#ifndef LIBRARY_SYSTEM_USER
#define LIBRARY_SYSTEM_USER

#include "user_student.h"
#include "library_system.h"
#include "user_admini.h"
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class library_system_user : public user_admini{
    private:
        vector<user_student> vecUS; //学校用户信息库
        vector<user_admini> vecADM; //管理员信息库
    public:
        void setVecUS(ifstream &infile){
			string info;
			while(!infile.eof()){
				getline(infile, info);
				string ia[5];
				stringstream ss;
				ss << info;
				int temp=0;
				string temps;
				while(ss >> temps){
					ia[temp]=temps;
					temp++;
				}
				user_student us1(ia[0], ia[1]);
				vecUS.push_back(us1);
			}
			infile.close();
		} //将用户信息放入用户数据库中，包含名字和账号
        void setVecAdmini(ifstream &infile){
            string info;
			while(!infile.eof()){
				getline(infile, info);
				string ia[5];
				stringstream ss;
				ss << info;
				int temp=0;
				string temps;
				while(ss >> temps){
					ia[temp]=temps;
					temp++;
				}
				user_admini us1(ia[0], ia[1]);
				vecADM.push_back(us1);
			}
			infile.close();
        }//将管理员信息放入管理员数据库中，包含名字和账号
		void showUsers(){
			for (int i=0; i<vecUS.size(); i++){
				cout << vecUS[i].getName() << ' ' << vecUS[i].account << endl;
			}
		}//展示用户信息
        void showAdminis(){
			for (int i=0; i<vecADM.size(); i++){
				cout << vecADM[i].getName() << ' ' << vecADM[i].getAccount() << endl;
			}
        }//展示管理员信息
		int isLogin_user(string account_str, string password_str){
			for (int i=0; i<vecUS.size(); i++){
				if(vecUS[i].account==account_str&&vecUS[i].getPassword()==password_str){
					return i;
				}
			}
			return -1;
		}//如果使用学校用户登录，是否登录成功，成功返回对应的位置，不成功返回-1
		int isLogin_admini(string account_str, string password_str){
			for (int i=0; i<vecADM.size(); i++){
				if(vecADM[i].getAccount()==account_str&&vecADM[i].getPassword()==password_str){
					return i;
				}
			}
			return -1;
		}//如果使用管理员身份登录，是否登录成功，成功返回对应的位置，不成功返回-1
		void forgetPassword(string account_str, string name, int temp){
			//temp是类型，1对应管理员，2对应学校用户
			if(temp==2){
				for (int i=0; i<vecUS.size(); i++){
					if(vecUS[i].account==account_str&&vecUS[i].getName()==name){
						cout << "匹配成功，请输入修改后的密码" << endl;
						string newPassword;
						cin >> newPassword;
						vecUS[i].setPassword(newPassword);
						return ;
					}
				}
			}
			if(temp==1){
				for (int i=0; i<vecADM.size(); i++){
					if(vecADM[i].getAccount()==account_str&&vecADM[i].getName()==name){
						cout << "匹配成功，请输入修改后的密码" << endl;
						string newPassword;
						cin >> newPassword;
						vecADM[i].setPassword(newPassword);
						return ;
					}
				}
			}
			cout << "抱歉，未查找到相关信息" << endl;
		}
		user_student getUserStatus(int i){
			return vecUS[i];
		}//返回用户对应的情况，便于后端处理
		user_admini getAdnimiStatus(int i){
			return vecADM[i];
		}//返回管理员对应的情况，便于后端处理
}; //用户信息库 

#endif
