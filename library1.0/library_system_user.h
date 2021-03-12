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
        vector<user_student> vecUS; //ѧУ�û���Ϣ��
        vector<user_admini> vecADM; //����Ա��Ϣ��
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
		} //���û���Ϣ�����û����ݿ��У��������ֺ��˺�
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
        }//������Ա��Ϣ�������Ա���ݿ��У��������ֺ��˺�
		void showUsers(){
			for (int i=0; i<vecUS.size(); i++){
				cout << vecUS[i].getName() << ' ' << vecUS[i].account << endl;
			}
		}//չʾ�û���Ϣ
        void showAdminis(){
			for (int i=0; i<vecADM.size(); i++){
				cout << vecADM[i].getName() << ' ' << vecADM[i].getAccount() << endl;
			}
        }//չʾ����Ա��Ϣ
		int isLogin_user(string account_str, string password_str){
			for (int i=0; i<vecUS.size(); i++){
				if(vecUS[i].account==account_str&&vecUS[i].getPassword()==password_str){
					return i;
				}
			}
			return -1;
		}//���ʹ��ѧУ�û���¼���Ƿ��¼�ɹ����ɹ����ض�Ӧ��λ�ã����ɹ�����-1
		int isLogin_admini(string account_str, string password_str){
			for (int i=0; i<vecADM.size(); i++){
				if(vecADM[i].getAccount()==account_str&&vecADM[i].getPassword()==password_str){
					return i;
				}
			}
			return -1;
		}//���ʹ�ù���Ա��ݵ�¼���Ƿ��¼�ɹ����ɹ����ض�Ӧ��λ�ã����ɹ�����-1
		void forgetPassword(string account_str, string name, int temp){
			//temp�����ͣ�1��Ӧ����Ա��2��ӦѧУ�û�
			if(temp==2){
				for (int i=0; i<vecUS.size(); i++){
					if(vecUS[i].account==account_str&&vecUS[i].getName()==name){
						cout << "ƥ��ɹ����������޸ĺ������" << endl;
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
						cout << "ƥ��ɹ����������޸ĺ������" << endl;
						string newPassword;
						cin >> newPassword;
						vecADM[i].setPassword(newPassword);
						return ;
					}
				}
			}
			cout << "��Ǹ��δ���ҵ������Ϣ" << endl;
		}
		user_student getUserStatus(int i){
			return vecUS[i];
		}//�����û���Ӧ����������ں�˴���
		user_admini getAdnimiStatus(int i){
			return vecADM[i];
		}//���ع���Ա��Ӧ����������ں�˴���
}; //�û���Ϣ�� 

#endif
