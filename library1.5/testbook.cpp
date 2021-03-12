#include <iostream>
#include <fstream>
#include <cstring>
#include "library_system.h"
#include "book.h"
#include "user_admini.h"
#include "user_student.h"
#include "library_system_user.h"
#include <windows.h>
#include <cstdlib>

using namespace std;

int main(){
    int ttt;
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

    system("cls");
	
	while(true){
		cout << "��ӭ����H��ѧͼ��ݣ����ȵ�¼;" << endl;
    	cout << "�Թ���Ա��¼������1����ѧУ�û���¼������2���˳�������0" << endl;
    	cout << "�����룺";
    	int choose_status;
		cin >> choose_status;
		cout << "���Ժ�" << endl;
		Sleep(1000);
		system("cls");
		if(choose_status==0){
			break;
		}
		if(choose_status==1){
			cout << "����ѡ�����Աģʽ" << endl;
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
                    cout<<"--7--�޸�ָ���û��Ľ������-----"<<endl;
                    cout<<"--8--����ͼ��-------------------"<<endl;
                    cout<<"--9--ɾ��ͼ��-------------------"<<endl;
                    cout<<"--10-����ͼ��-------------------"<<endl;
                    cout<<"--11-�˳���¼-------------------"<<endl;
                    cout<<"--12-�鿴ͼ��ݲ���-------------" << endl;
                    cout << "--13-�鿴����Ա����-----------" << endl;
                    cout << "--14-�鿴�û�����-------------"<< endl;
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
                    if(a==7){ cout<<"����ʹ�����������û�����1������ʹ���˻��������û�����2"<<endl;int c;cin>>c;string aa;
                              if(c==1){cout<<"�������û���"<<endl;
                                       while(true){
                                       cin>>aa;
                                       if(lsu.findStudent_Name(aa)==-1){cout<<"�����ڸ��û�����������"<<endl;}
                                       else{
                                            user_student st1=lsu.getUserStatus(lsu.findStudent_Name(aa));
                                            cout<<"������ָ���û��޸ĺ�Ľ��������1Ϊ�Ѿ����ģ���������Ϊδ���ģ�"<<endl;
                                            int ii;cin>>ii;st1.setBorrow(ii);cout<<"�޸Ľ�������ɹ�"<<endl;break;
                                       }    }
                              }
                              if(c==2){cout<<"�������˻���"<<endl;
                                       while(true){
                                       cin>>aa;
                                       if(lsu.findStudent_Account(aa)==-1){cout<<"�����ڸ��û�����������"<<endl;}
                                       else{
                                            user_student st1=lsu.getUserStatus(lsu.findStudent_Account(aa));
                                            cout<<"������ָ���û��޸ĺ�Ľ��������1Ϊ�Ѿ����ģ���������Ϊδ���ģ�"<<endl;
                                            int ii;cin>>ii;st1.setBorrow(ii);cout<<"�޸Ľ�������ɹ�"<<endl;break;
                                       }    }
                               }
                    }
                    if(a==8){ cout<<"�ѽ�������ͼ�����"<<endl;string bkn;string Isb;string anm;char cla1;string cla2;char cla3;
                              cout<<"����������ͼ�������"<<endl;cin>>bkn;cout<<"�������ӦISBN���"<<endl;cin>>Isb;
                              cout<<"������ͼ�����ߵ�����"<<endl;cin>>anm;cout<<"������ͼ������һ��"<<endl;cin>>cla1;
                              cout<<"������ͼ�����ڶ���"<<endl;cin>>cla2;cout<<"������ͼ����������"<<endl;cin>>cla3;
                              book bk1(bkn, Isb, anm, cla1, cla2, cla3);cout<<"����ͼ��ɹ�"<<endl;ls1.addBook(bk1);
                    }
                    if(a==9){ cout<<"�ѽ���ɾ��ͼ����棬������Ҫɾ��ͼ��������Ϣ"<<endl;
                              cout<<"����1�����������ң�����2����ISBN���в���"<<endl;
                              int uu;cin>>uu;
                              if(uu==1){ cout<<"����������:";string nnmm;cin>>nnmm;
                                         while(true){
                              if(ls1.findBook_name(nnmm)==-1){cout<<"�����ҵ��鼮�����ڣ�����������"<<endl;}
                              else{cout<<"�Ѳ��ҵ��˶�Ӧ�鼮��ȷ��ɾ��������1�������������˳�"<<endl;int nntt;cin>>nntt;if(nntt==1){ls1.deleteBook(ls1.showBook(ls1.findBook_name(nnmm)));cout<<"ɾ���ɹ�"<<endl;break;}else{cout<<"���˳�"<<endl;break;}}
                              }
                              }
                              if(uu==2){cout<<"������ISBN:";string iiss;cin>>iiss;
                                        while(true){
                              if(ls1.findBook_ISBN(iiss)==-1){cout<<"�����ҵ��鼮�����ڣ�����������"<<endl;}
                              else{cout<<"�Ѳ��ҵ��˶�Ӧ�鼮��ȷ��ɾ��������1�������������˳�"<<endl;int nntt;cin>>nntt;if(nntt==1){ls1.deleteBook(ls1.showBook(ls1.findBook_ISBN(iiss)));cout<<"ɾ���ɹ�"<<endl;break;}else{cout<<"���˳�"<<endl;break;}}
                              }
                              }
                            }
                    if(a==10){ cout<<"������ȷ����������1��ISBN�뾫ȷ����������2"<<endl;
                               cout<<"����ģ������������3,������ģ������������4"<<endl;
                               cout<<"�˳�������5"<<endl;int yyy;cin>>yyy;string srr;
                                  while(true){
                                        if(yyy==1){cout<<"��������Ҫ���ҵ�����"<<endl;cin>>srr;
                                             if(ls1.findBook_name(srr)==-1){cout<<"�����ҵ��鼮�����ڣ�����������"<<endl;break;}
                                             else{cout<<"�����鼮�ɹ�����ѡ�����蹦��"<<endl;book bkk=ls1.showBook(ls1.findBook_name(srr));
                                                  cout<<"--1--��ȡ�鼮�������Ϣ-----"<<endl;
                                                  cout<<"--2--��ѯ����Ľ������-----"<<endl;
                                                  cout<<"--3--�˳�-------------------"<<endl;int ttt;
                                                  cin>>ttt;if(ttt==3){break;}
                                                  while(true){
                                                    if(ttt==1){cout<<bkk<<endl;break;}
                                                    if(ttt==2){cout<<bkk.getisBorrow()<<"��0Ϊδ�����ߣ�1Ϊ�ѱ����ߣ�"<<endl;break;}
                                                    if(ttt==3){break;}
                                                  }
                                             }}
                                        if(yyy==2){cout<<"��������Ҫ�����鼮��ISBN��"<<endl;cin>>srr;
                                             if(ls1.findBook_ISBN(srr)==-1){cout<<"�����ҵ��鼮�����ڣ�����������"<<endl;}
                                             else{cout<<"�����鼮�ɹ�����ѡ�����蹦��"<<endl;book bkk=ls1.showBook(ls1.findBook_ISBN(srr));
                                                  cout<<"--1--��ȡ�鼮�������Ϣ-----"<<endl;
                                                  cout<<"--2--��ѯ����Ľ������-----"<<endl;
                                                  cout<<"--3--�˳�-------------------"<<endl;int ttt;
                                                  cin>>ttt;if(ttt==3){break;}
                                                  while(true){
                                                    if(ttt==1){cout<<bkk<<endl;}
                                                    if(ttt==2){cout<<bkk.getisBorrow()<<"��0Ϊδ�����ߣ�1Ϊ�ѱ����ߣ�"<<endl;}
                                                    if(ttt==3){break;}
                                                  }
                                             }}
                                        if(yyy==3){cout<<"����������Ҫ���ҵ��鼮���"<<endl;cin>>srr;ls1.findBook_classF(srr);break;}
                                        if(yyy==4){cout<<"����������Ҫ���ҵ�����"<<endl;cin>>srr;ls1.findBook_authorName(srr);break;}
                                        if(yyy==5){break;}
                                  }
                             }
                    if(a==11){ cout<<"���˳���¼"<<endl; cout << "��л����ʹ��" << endl; break;}
                    if(a==12){
                        ls1.showAllBook();
                    }
                    if(a==13){
                        lsu.showAdminis();
                    }
                    if(a==14){
                        lsu.showUsers();
                    }
                    /**//**/ 
                    }
				}
			}
		}
		if(choose_status==2){
			cout << "����ѡ��ѧУ�û�ģʽ" << endl;
            cout << "���践��������back�������˳�������logout������������������forget,�����¼��ֱ�������˺ź�����" << endl;
            cout << "������:";
			Sleep(1000);
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
                    cout<<"��¼�ɹ�����������ѧ���û�����"<<endl;
                    user_student st=lsu.getUserStatus(lsu.isLogin_user(str1,str2));
                    cout<<"��ѡ����Ҫʵ�ֵĹ���"<<endl;
                    cout<<"--1--�޸�����-------------------"<<endl;
                    cout<<"--2--�鿴��ǰ�Ľ��ļ�¼---------"<<endl;
                    cout<<"--3--���ü������ܲ���ͼ��-------"<<endl;

                    while(true){
                        int a;cin>>a;
                        if(a==1){ cout<<"�������޸ĺ������"<<endl;string b;cin>>b;st.setPassword(b);cout<<"�޸�����ɹ�"<<endl;}
                        if(a==2){ cout<<"��ǰ�˻��ĸ��˽������Ϊ(0Ϊδ����1Ϊ�ѽ��飩��"<<st.getIsBorrow()<<endl;}
                        if(a==3){ cout<<"������ȷ����������1��ISBN�뾫ȷ����������2"<<endl;
                                  cout<<"����ģ������������3��������ģ������������4"<<endl;
                                  cout<<"�˳�������5"<<endl;
                                  int tt;cin>>tt;string stt;
                                  while(true){if(tt==1){
                                            if(ttt==5){cout<<"���˳�"<<endl;break;}
                                             cout<<"��������Ҫ���ҵ�����"<<endl;cin>>stt;
                                             if(ls1.findBook_name(stt)==-1){cout<<"�����ҵ��鼮�����ڣ�����������"<<endl;}
                                             else{cout<<"�����鼮�ɹ�����ѡ�����蹦��"<<endl;book bkk=ls1.showBook(ls1.findBook_name(stt));
                                                  cout<<"--1--��ȡ�鼮�������Ϣ-----"<<endl;
                                                  cout<<"--2--��ѯ����Ľ������-----"<<endl;
                                                  cout<<"--3--���ı���---------------"<<endl;
                                                  cout<<"--4--�黹����---------------"<<endl;
                                                  cout<<"--5--�˳�-------------------"<<endl;
                                                  while(true){
                                                    cin>>ttt;
                                                    if(ttt==1){cout<<bkk<<endl;}
                                                    if(ttt==2){cout<<bkk.getisBorrow()<<"��0Ϊδ�����ߣ�1Ϊ�ѱ����ߣ�"<<endl;}
                                                    if(ttt==3){bkk.setBorrow(1);cout<<"�鼮���ĳɹ�"<<endl;}
                                                    if(ttt==4){bkk.setBorrow(0);cout<<"�鼮�黹�ɹ�"<<endl;}
                                                    if(ttt==5){break;}
                                                  }
                                             }
                                             }
                                  if(tt==2){ if(ttt==5){cout<<"���˳�"<<endl;break;}
                                             cout<<"��������Ҫ�����鼮��ISBN��"<<endl;cin>>stt;
                                             if(ls1.findBook_ISBN(stt)==-1){cout<<"�����ҵ��鼮�����ڣ�����������"<<endl;}
                                             else{cout<<"�����鼮�ɹ�����ѡ�����蹦��"<<endl;book bkk=ls1.showBook(ls1.findBook_ISBN(stt));
                                                  cout<<"--1--��ȡ�鼮�������Ϣ-----"<<endl;
                                                  cout<<"--2--��ѯ����Ľ������-----"<<endl;
                                                  cout<<"--3--���ı���---------------"<<endl;
                                                  cout<<"--4--�黹����---------------"<<endl;
                                                  cout<<"--5--�˳�-------------------"<<endl;
                                                  while(true){
                                                    cin>>ttt;
                                                    if(ttt==1){cout<<bkk<<endl;}
                                                    if(ttt==2){cout<<bkk.getisBorrow()<<"��0Ϊδ�����ߣ�1Ϊ�ѱ����ߣ�"<<endl;}
                                                    if(ttt==3){bkk.setBorrow(1);cout<<"�鼮���ĳɹ�"<<endl;}
                                                    if(ttt==4){bkk.setBorrow(0);cout<<"�鼮�黹�ɹ�"<<endl;}
                                                    if(ttt==5){break;}
                                                  }
                                             }
                                          }
                                  if(tt==3){cout<<"����������Ҫ���ҵ��鼮���"<<endl;cin>>stt;ls1.findBook_classF(stt);break;}
                                  if(tt==4){cout<<"����������Ҫ���ҵ�����"<<endl;cin>>stt;ls1.findBook_authorName(stt);break;}
                                  if(tt==5){break;}
                            }
                        }
                        /***//***/ 
                    }
                }
            }
		}
	}
	cout << "��л����ʹ��!!" << endl;
    return 0;
}
