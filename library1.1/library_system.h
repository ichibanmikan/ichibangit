#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

bool cmp(book b1, book b2){
	string s1=b1.getBookName();
	string s2=b2.getBookName();
	if(s1[0]!=s2[0]){
		return s1[0]<s2[0];
	}
	if(s1[1]!=s2[1]){
		return s1[1]<s2[1];
	}
	if(s1[2]!=s2[2]){
		return s1[2]<s2[2];
	}
}

class library_system {
    private:
        vector<book> vecBook; //书籍信息库
    public:
        library_system(){}
		~library_system(){}
        void setBook(ifstream &infile){
            string s;
            while(!infile.eof()){
            	getline(infile, s);
            	stringstream ss;
				string sa[5];
				ss << s;
				string temps;
				char ch;
				int temp=0;
				while(ss >> temps){
					if(temp==3){
						ch=temps[0];
						sa[temp]=temps.substr(1, temps.size()-1);
						temp++;
						continue;
					}
					sa[temp]=temps;
					temp++;
				}
				char ch_2=sa[4][0];
				book b1(sa[0], sa[1], sa[2], ch, sa[3], ch_2);
				vecBook.push_back(b1);
            }
            infile.close();
        } //将书籍信息放入书籍数据库中
		int findBook(book b1){
			for (int i=0; i<vecBook.size(); i++){
				if(vecBook[i]==b1){
					return i;
				}
				return -1;
			}
		}//精确查找图书，用于删除图书。
		int findBook_name(string s1){
			for (int i=0; i<vecBook.size(); i++){
				if(vecBook[i].getBookName()==s1){
					return i;
				}
			}
			return -1;
		} //根据名字精确查找图书，查到了就返回位置信息，查不到就返回-1.
		int findBook_ISBN(string s1){
			for (int i=0; i<vecBook.size(); i++){
				if(vecBook[i].getISBN()==s1){
					return i;
				}
			}
			return -1;
		} //根据ISBN精确查找图书
		void findBook_authorName(string s2){
			vector<book> vecTemp;
			for (int i=0; i<vecBook.size(); i++){
				if(vecBook[i].getAuthorName()==s2){
					vecTemp.push_back(vecBook[i]);
				}
			}
			sort(vecTemp.begin(), vecTemp.end(), cmp);
			for (int i=0; i<vecTemp.size(); i++){
				cout << vecTemp[i].getBookName() << ' ' << vecTemp[i].getISBN() << ' ' << vecTemp[i].getAuthorName() << ' ' << vecTemp[i].getClassF() << endl;
			}
		} //模糊查找图书并按照字典序输出
		void addBook(book b1){
			vecBook.push_back(b1);
		} //增加图书
		void deletBook(book b1){
			vector<book>::iterator iter;
			iter=vecBook.erase(vecBook.begin()+findBook(b1));
		} //删除图书
		void findBook_classF(string s){
			vector<book> vecTemp;
			if(s.size()==1){
				for (int i=0; i<vecBook.size(); i++){
					string sc=vecBook[i].getClassF();
					if(sc.substr(0, 1)==s){
						vecTemp.push_back(vecBook[i]);
					}
				}
			}
			else{
				for (int i=0; i<vecBook.size(); i++){
					string sc=vecBook[i].getClassF();
					s+=" 1";
					if(sc==s){
						vecTemp.push_back(vecBook[i]);
					}
				}
			}
			sort(vecTemp.begin(), vecTemp.end(), cmp);
			for (int i=0; i<vecTemp.size(); i++){
				cout << vecTemp[i].getBookName() << ' ' << vecTemp[i].getISBN() << ' ' << vecTemp[i].getAuthorName() << ' ' << vecTemp[i].getClassF() << endl;
			}
		}//根据分类模糊查找并按照字典序输出
		void showAllBook(){
			for (int i=0; i<vecBook.size(); i++){
				cout << vecBook[i];
			}
		}
};

#endif
