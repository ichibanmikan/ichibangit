#include <iostream>
#include <fstream>
#include <cstring>
#include "library_system.h"
#include "book.h"
#include "user_admini.h"
#include "user_student.h"
#include "library_system_user.h"
#include <windows.h>

using namespace std;

int main(){
	cout << "�����У����Ժ󡭡�����"  << endl;
    ifstream infile_book("books.txt", ios::in);
    library_system ls1;
    ls1.setBook(infile_book);
	// ls1.showAllBook();
    infile_book.close();

    ifstream infile_users("user.txt", ios::in);
    library_system_user lsu;
    lsu.setVecUS(infile_users);
    // lsu.showUsers();
    infile_users.close();

    ifstream infile_admini("admini.txt", ios::in);
   	lsu.setVecAdmini(infile_admini);
    // lsu.showAdminis();
    infile_admini.close();

	cout << "�������" << endl;
	
	Sleep(1000);//�ó���ͣ��һ��ʱ�䣬Sleep(ע��S��д)�����������������֮ǰ��������������ʾ��Ϣ�����
	 
	while(true){
		cout << "��ӭ����H��ѧͼ��ݣ����ȵ�¼;" << endl;
    	cout << "�Թ���Ա��¼������1����ѧУ�û���¼������2���˳�������0" << endl;
    	cout << "�����룺";
    	int choose_status;
		cin >> choose_status;
		if(choose_status==0){
			break;
		}
		if(choose_status==1){
			cout << "���践��������back�������˳�������logout������������������forget,�����¼��ֱ�������˺ź�����" << endl;
			cout << "������:";
			while(true){
				string str1, str2;
				cin >> str1;
				if(str1=="back"){
					break;
				}
				if(str1=="logout"){
					break;
				}
				if(str1=="forget"){
					cout << "�ѽ����һ�������棬����������Ӧ���˺ź�����" << endl;
					cin >> str1 >> str2;
					lsu.forgetPassword(str1,str2,1);//���øú������ﵽƥ����Ϣ�޸Ĺ���Ա�û�����Ĳ���
				}
				cin >> str2;
				if(lsu.isLogin_admini(str1, str2)==-1){
					cout << "�˺Ż���������������µ�¼" << endl;
				}
				else{
                    user_admini am=lsu.getAdnimiStatus(lsu.isLogin_admini(str1, str2));

				}
			}
		}
		if(choose_status==2){
            cout << "���践��������back�������˳�������logout������������������forget,�����¼��ֱ�������˺ź�����" << endl;
            cout << "������:";
            while(true){
                string str1,str2;
                cin>>str1;
                if(str1=="back"){
                    break;
                }
                if(str1=="logout"){
                    break;
                }
                if(str1=="forget"){
                    cout << "�ѽ����һ�������棬����������Ӧ���˺ź�����" << endl;
                    cin>>str1>>str2;
                    lsu.forgetPassword(str1,str2,2);//���øú������ﵽƥ����Ϣ�޸�ѧ���û�����Ĳ���
                }
                cin>>str2;
                if(lsu.isLogin_user(str1,str2)==-1){
                    cout << "�˺Ż���������������µ�¼" << endl;
                }
                else{
                    user_student st=lsu.getUserStatus(lsu.isLogin_user(str1,str2));
                }
            }
		}
	}
	cout << "��л����ʹ��!!" << endl;
	//�����Ҿٵ�һ�����ӣ��Ͱ����������д���У����������Ǹ���library_system_user�������п⺯��ֱ���þ��У������򵥵���̫���ˣ�������!!!!��ʲô����һ����������!!!
    return 0;
}
