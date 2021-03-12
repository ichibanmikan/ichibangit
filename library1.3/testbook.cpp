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
                    Sleep(1000);
                    cout<<"��½�ɹ��������������Ա�û�����"<<endl;
                    user_admini am=lsu.getAdnimiStatus(lsu.isLogin_admini(str1, str2));
                    cout<<"��ѡ����Ҫʵ�ֵĹ���"<<endl;
                    cout<<"--1--�޸�����-------------------"<<endl;
                    cout<<"--2--�޸�ָ���鼮����-----------"<<endl;
                    cout<<"--3--�޸�ָ���鼮ISBN-----------"<<endl;
                    cout<<"--4--�޸�ָ���鼮��������-------"<<endl;
                    cout<<"--5--�޸�ָ���鼮�������-------"<<endl;
                    cout<<"--6--��ȡ��ǰ�û������û�����---"<<endl;
                    cout<<"--7--�˳���¼-------------------"<<endl;
                    while(true){
                    int a;cin>>a;
                    if(a==1){ cout<<"�������޸ĺ������"<<endl;string mima;cin>>mima;am.setPassword(mima);cout<<"�޸�����ɹ�"<<endl;}
                    if(a==2){ cout<<"������Ҫ�޸��鼮����"<<endl;string nm;cin>>nm;ls1.findBook_name(nm);
                              if(ls1.findBook_name(nm)==-1){cout<<"�����ڸ���"<<endl;}
                              else{cout<<"�������޸ĺ�����"<<endl;string a1;cin>>a1;am.changeBookName(ls1.showBook(ls1.findBook_name(nm)),a1);
                                   cout<<"�鼮�����޸ĳɹ�"<<endl;
                              }
                    }
                    if(a==3){ cout<<"������Ҫ�޸��鼮����"<<endl;string nm1;cin>>nm1;ls1.findBook_name(nm1);
                              if(ls1.findBook_name(nm1)==-1){cout<<"�����ڸ���"<<endl;}
                              else{cout<<"�������޸ĺ�ISBN"<<endl;string a2;cin>>a2;am.changeBookISBN(ls1.showBook(ls1.findBook_name(nm1)),a2);
                                   cout<<"�鼮ISBN�޸ĳɹ�"<<endl;
                              }
                    }
                    string nm4;//������1��6������4.30�޸Ĺ��ˣ�����if(a==5)��ʱ���и�nm2,�Ҳ�֪���������nm2һ��һ�������һ�������nm2������������a=4�Ĵ�������ģ����elseif�������˾Ͳ����������ˣ�nm2�ͱ�ɾ���ˣ�����a==5��ʾ��nm2�ᱨ��δ���壬�����������һ��
                    if(a==4){ cout<<"������Ҫ�޸��鼮����"<<endl;string nm2;cin>>nm2;ls1.findBook_name(nm2);
                              nm4=nm2;
                              if(ls1.findBook_name(nm2)==-1){cout<<"�����ڸ���"<<endl;}
                              else{cout<<"�������޸ĺ���������"<<endl;string a3;cin>>a3;am.changeBookAuthorName(ls1.showBook(ls1.findBook_name(nm2)),a3);
                                   cout<<"�鼮���������޸ĳɹ�"<<endl;
                              }
                    }
                    if(a==5){ cout<<"������Ҫ�޸��鼮����"<<endl;string nm3;cin>>nm3;ls1.findBook_name(nm3);
                              if(ls1.findBook_name(nm3)==-1){cout<<"�����ڸ���"<<endl;}
                              else{cout<<"�������޸ĺ�Ľ����飨0��ʾ��δ�����1��ʾ�ѽ����"<<endl;int it;cin>>it;
                                   am.changeBookIsBorrow(ls1.showBook(ls1.findBook_name(nm4)),it);cout<<"�鼮��������ѳɹ��޸�"<<endl;
                              }
                    }
                    if(a==6){ cout<<"��ǰ���û���Ϊ��"<<am.getAccount()<<" ��ǰ�û�������Ϊ:"<<am.getName()<<endl;} //1.6.16:34;����������û��������Ҳ���ż����ˣ���
                    if(a==7){ cout<<"�����˳���¼"<<endl;break;}
                    }
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
                    Sleep(1000);
                    cout<<"��½�ɹ�����������ѧ���û�����"<<endl;
                    user_student st=lsu.getUserStatus(lsu.isLogin_user(str1,str2));
                    cout<<"��ѡ����Ҫʵ�ֵĹ���"<<endl;
                    cout<<"--1--�޸�����-------------------"<<endl;
                    cout<<"--2--�鿴��ǰ�Ľ��ļ�¼---------"<<endl;
                    cout<<"--3-----------"<<endl;

                    while(true){
                        int a;cin>>a;
                        if(a==1){ cout<<"�������޸ĺ������"<<endl;string b;cin>>b;st.setPassword(b);cout<<"�޸�����ɹ�"<<endl;}
                        if(a==2){ }
                    }
                }
            }
		}
	}
	cout << "��л����ʹ��!!" << endl;
	//�����Ҿٵ�һ�����ӣ��Ͱ����������д���У����������Ǹ���library_system_user�������п⺯��ֱ���þ��У������򵥵���̫���ˣ�������!!!!��ʲô����һ����������!!!
    return 0;
}
