/*
    user.h
    author: cmlin
    email: 13307130255@fudan.edu.cn
*/
#ifndef _USER_H
#define _USER_H

#include "config.h"
#include <map>
#include <vector>
using namespace std;

struct user {
    int socket_handle;
    string name;
};

class user_list {
    map<int,user> u;
public:
    user_list()
    {
        u.clear();
    }

    void add(int socket_handle,char* name)
    {
        user new_user;
        new_user.socket_handle = socket_handle;
        new_user.name = name;
        u[socket_handle] = new_user;
    }

    void remove(int socket_handle)
    {
        u.erase(socket_handle);
    }


    string getUsername(int socket_handle)
    {
        return u[socket_handle].name;
    }

    vector<int> getAllsocket()
    {
        vector<int> l;
        map<int,user>::iterator it;
        for(it=u.begin();it!=u.end();it++) {
            l.push_back(it->first);
        }
        return l;
    }
};

#endif // _USER_H
