#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int start=0;
    bool postive=true, postive_exp=true;
    if(str[0]=='+'){
        ++start;
    }
    else if(str[0]=='-'){
        postive=false;
        ++start;
    }
    int exp=0;//幂数
    bool isexp=false;
    string xiaoshu;
    int point_pos;
    while(start<str.size())
    {
        //+1.23400E-03
        if(str[start]=='E'){
            isexp=true;
            ++start;
            continue;
        }
        if(str[start]=='.'){
            point_pos=xiaoshu.size();
            ++start;
            continue;
        }
        if(isexp){
                if(str[start]=='-'){
                        //exp=-1;
                        postive_exp=false;
                        ++start;
                }
                else if(str[start]=='+'){
                        ++start;
                }
                exp=exp*10+str[start]-'0';
        }
        else{
                xiaoshu+=str[start];
        }
        ++start;
    }
    if(!postive) cout<<"-";
    if(!postive_exp) exp=-1*exp;
    if(exp<0){
        cout<<"0.";
        while(++exp<0){
            cout<<"0";
        }
        cout<<xiaoshu<<endl;
    }
    else{
        point_pos+=exp;
        if(point_pos>=xiaoshu.size()){
            cout<<xiaoshu;
            for(int i=xiaoshu.size(); i<point_pos; i++){
                cout<<"0";
            }
            cout<<endl;
        }
        else{
                //xiaoshu.insert(xiaoshu.begin()+point_pos+exp, '.');
                string w=xiaoshu.substr(point_pos, xiaoshu.size());
                xiaoshu=xiaoshu.substr(0,point_pos)+"."+w;
                cout<<xiaoshu<<endl;

        }

    }
    return 0;
}
