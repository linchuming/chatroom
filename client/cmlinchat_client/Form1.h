#pragma once
#include <string>
#include <string.h>
#include <memory.h>
#include <vector>
using namespace std;

struct package {
	char comd[32];
	char name[32];
	char text[2048];
};
vector<package> msg;
namespace cmlinchat_client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;
	using namespace System::Threading;

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


	private:
		/* 程序定义的全局变量 */
	    int port;
		long long host;
		IPAddress^ iPaddress;
		IPEndPoint^ iPendpoint; 
		Thread^ oThread;


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textName;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textContain;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textMsg;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button3;

			 Socket^ socket;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textContain = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textMsg = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(270, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 26);
			this->button1->TabIndex = 0;
			this->button1->Text = L"登陆";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textName
			// 
			this->textName->Location = System::Drawing::Point(71, 17);
			this->textName->Name = L"textName";
			this->textName->Size = System::Drawing::Size(158, 21);
			this->textName->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"昵称：";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textContain);
			this->groupBox1->Location = System::Drawing::Point(24, 54);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(379, 321);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"聊天窗";
			// 
			// textContain
			// 
			this->textContain->Location = System::Drawing::Point(19, 23);
			this->textContain->Multiline = true;
			this->textContain->Name = L"textContain";
			this->textContain->Size = System::Drawing::Size(339, 280);
			this->textContain->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(331, 449);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(51, 31);
			this->button2->TabIndex = 4;
			this->button2->Text = L"发送";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textMsg
			// 
			this->textMsg->Location = System::Drawing::Point(44, 386);
			this->textMsg->Multiline = true;
			this->textMsg->Name = L"textMsg";
			this->textMsg->Size = System::Drawing::Size(261, 94);
			this->textMsg->TabIndex = 5;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(331, 387);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 35);
			this->button3->TabIndex = 6;
			this->button3->Text = L"清屏";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(431, 505);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textMsg);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textName);
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Cmlin‘s Chatting Room";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 host = 0xb0061c73; // 115.28.6.176
				 port = 2333;
				 iPaddress = gcnew IPAddress(host);
				 iPendpoint = gcnew IPEndPoint(host,port);
				// socket = gcnew Socket(AddressFamily::InterNetwork,
				//	 SocketType::Stream, ProtocolType::Tcp);
				// try {
				//	socket->Connect(iPendpoint);
				// } catch(SocketException^ e) {
				//	 MessageBox::Show("unable to connect the server!","error");
				//	 Application::Exit();
				// }
				//socket->Close();

			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ str = textName->Text;
				 package sdata;
				 memset(&sdata,'\0',sizeof(sdata));
				 strcpy(sdata.comd,"login");
				 char* name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
				 strcpy(sdata.name,name);
				 //String^ mystr= System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)((char*)&sdata));
	
				 socket = gcnew Socket(AddressFamily::InterNetwork,
					 SocketType::Stream, ProtocolType::Tcp);
				 try {
					socket->Connect(iPendpoint);
				 } catch(SocketException^ e) {
					 MessageBox::Show("unable to connect the server!","error");
					 return;
				 }
				 array<unsigned char>^ buffer = gcnew array<unsigned char>(5120);
				 try {
					 char* dd = (char*)(&sdata);
					 for(int i=0;i<sizeof(package);i++) {
						buffer[i] = dd[i];
					 }
					 socket->Send(buffer);
				 } catch(SocketException^ e) {
					 MessageBox::Show("login failed!","error");
					 return;
				 }
				 button1->Enabled = false;
	
				//array<unsigned char>^ buffer = gcnew array<unsigned char>(4096);
				try {
					socket->Receive(buffer);
				} catch(SocketException^ e) {
				}
				//
				////package* pg = (package*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sb->ToString());
				package pg;
				char* ptr = (char*)&pg;
				for(int i=0;i < sizeof(package);i++) {
					ptr[i] = buffer[i];
				}
				if(strcmp(pg.comd,"login_succ") == 0) {
					textContain->Text = "登陆成功！\n" ;
				}
				oThread = gcnew Thread(gcnew ParameterizedThreadStart(ThreadProc));
				
				oThread->Start(this);
				timer1->Enabled = true; 
			 }
		static void ThreadProc(Object^ data)
		{
			Form1^ f = (Form1^)data;
			while(1) {
				array<unsigned char>^ buffer = gcnew array<unsigned char>(5120);
				f->socket->Receive(buffer);
				package pg;
				char* ptr = (char*)&pg;
				for(int i=0;i < sizeof(package);i++) {
					ptr[i] = buffer[i];
				}
				if(strcmp(pg.comd,"send_msg") == 0) {
					msg.push_back(pg);
				}
			}

		}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ str = textMsg->Text;
				 package sdata;
				 memset(&sdata,'\0',sizeof(sdata));
				 strcpy(sdata.comd,"msg");
				 char* text = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
				 strcpy(sdata.text,text);
				 array<unsigned char>^ buffer = gcnew array<unsigned char>(5120);
				 try {
					 char* dd = (char*)(&sdata);
					 for(int i=0;i<sizeof(package);i++) {
						buffer[i] = dd[i];
					 }
					socket->Send(buffer);
				 } catch(SocketException^ e) {
					 MessageBox::Show("send message failed!","error");
					 return;
				 }
				 textMsg->Text = "";
			 }
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 //if(oThread) {
				// oThread->Suspend();
			 //}
			 if(socket) {
				 socket->Close();
			 }
			 Application::Exit();
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(!msg.empty()) {
				 vector<package>::iterator it;
				 it=msg.begin();
				 while(it!=msg.end()) {
					 String^ name = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)(it->name));
					 String^ text = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)(it->text));
					 textContain->AppendText(name+":"+text+"\n");
					 it = msg.erase(it);
				 }
			 }
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 textContain->Text = "";
		 }
};
}

