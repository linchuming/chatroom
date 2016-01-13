/*
    socket.h
    author: cmlin
    email: 13307130255@fudan.edu.cn
*/
#ifndef _SOCKET_H
#define _SOCKET_H

#include "config.h"
#include "user.h"
#include <memory.h>
using namespace std;
#define PORT 2333
#define LENGTH_OF_LISTEN_QUEUE 50
#define BUFFER_SIZE 4096
struct sockaddr_in server_addr;
int server_socket;

user_list usr;

void* thread_work(void *ptr);


struct package {
    char comd[32];
    char name[32];
    char text[2048];
};

int server_start()
{
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    server_socket = socket(PF_INET,SOCK_STREAM,0);
    if(server_socket < 0) {
        cout<<"Create Socket Failed!"<<endl;
        return -1;
    }

    int opt = 1;
    setsockopt(server_socket,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    if(bind(server_socket,(struct sockaddr*)&server_addr,sizeof(server_addr))) {
        cout<<"Bind Failed!"<<endl;
        return -2;
    }

    if(listen(server_socket,LENGTH_OF_LISTEN_QUEUE)) {
        cout<<"Listen Failed!"<<endl;
        return -3;
    }

    cout<<"Server Start Success!"<<endl;
    return 0;

}

void server_work()
{
    while(1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);

        int new_client = accept(server_socket,(struct sockaddr*)&client_addr,&len);
        if(new_client<0) {
            cout<<"Create Client Socket Failed!"<<endl;
            continue;
        }
        //cout<<"new client"<<endl;

        pthread_t tid;
        pthread_create(&tid,NULL,thread_work,&new_client);

    }
}

void* thread_work(void *ptr)
{
    int client_socket = *(int*)ptr;
    char buffer[BUFFER_SIZE];
    while(1) {
        ssize_t len = recv(client_socket,buffer,BUFFER_SIZE,0);
        if(len<0) {
            cout<<"Client Close!"<<endl;
            usr.remove(client_socket);
            return NULL;
        }
        //cout<<buffer<<endl;
        package* pg = (package*)buffer;
        if(strcmp(pg->comd,"login")==0) {
            usr.add(client_socket,pg->name);
            package sdata;
            memset(&sdata,'\0',sizeof(package));
            strcpy(sdata.comd,"login_succ");
            send(client_socket,&sdata,sizeof(sdata),0);
            cout<<"Client Login!"<<endl;
            cout<<"User Name: "<<sdata.name<<endl;
        } else if (strcmp(pg->comd,"msg") == 0) {
            package sdata;
            memset(&sdata,'\0',sizeof(package));
            strcpy(sdata.comd,"send_msg");
            strcpy(sdata.name,usr.getUsername(client_socket).c_str());
            strcpy(sdata.text,pg->text);
            vector<int> us = usr.getAllsocket();
            vector<int>::iterator it;
            for(it=us.begin();it!=us.end();it++) {
                send(*it,&sdata,sizeof(sdata),0);
            }
            cout<<"Send Message!"<<endl;
        }
    }


}

void server_close()
{
    close(server_socket);
}
#endif // _SOCKET_H
