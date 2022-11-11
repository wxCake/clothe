#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

#define FILENAME "clothes.txt"
using namespace std;

class Clothes{
  private:
      string type;
      string sizes;
      string ccd;
      int price;
      int wws;
  public:
    Clothes(){}
    Clothes(string types,string sizes,string ccd,int wws,int price){
    this->type=type;
    this->sizes=sizes;
    this->ccd=ccd;
    this->price=price;
    this->wws=wws;
    }
    void settype(string type){
    this->type=type;
    }
    void setsizes(string sizes){
    this->sizes=sizes;
    }
    void setccd(string ccd){
    this->ccd=ccd;
    }
    void setprice(int price){
    this->price=price;
    }
    void setwws(int wws){
    this->wws=wws;
    }
    string gettype(){
    return type;
    }
    string getsizes(){
    return sizes;
    }
    string getccd(){
    return ccd;
    }
    int getprice(){
    return price;
    }
    int getwws(){
    return wws;
    }

    void show(){
   cout<<"\n\t"<<type<<"\t"<<sizes<<"\t"<<ccd<<"\t"<<price<<"\t"<<wws;
}
   void save(){

   ofstream op(FILENAME,ios::out|ios::app|ios::binary);
   if(op.is_open() ){
    op<<type<<"\t"<<sizes<<"\t"<<ccd<<"\t"<<price<<"\t"<<wws<<"\r\n";
    op.close();
   }


}

};

class Controller{
public:
    bool login();
    void menu();
    void add();
    void view();
    void initdate();
};

vector<Clothes> clos;
void Controller::initdate(){
fstream file(FILENAME,ios::in|ios::binary);
if(file.is_open()){
    string line;
    string arr[5];
    int index=-1,count=0,num=0;
    while(getline(file,line)){

        num=0;
        count=0;
        index=line.find("\t",count);
        while(index>0){
            arr[num++]=line.substr(count,index-count);
           count=index+1;
           index=line.find("\t",count);
        }
    }
    arr[num]=line.substr(count);
    clos.push_back( Clothes(arr[0],arr[1],arr[2],atoi(arr[3].c_str()),atoi(arr[4].c_str())));

}
file.close();
}
void Controller::view(){
system("cls");
cout<<"\n\t*************浏览服装信息************";
if(clos.size()<=0){
cout<<"\n\t暂无服装信息";
}else{
cout<<"\n\t种类\t型号\t颜色\t价格\t等级";
int i,len=clos.size();
for(i=0;i<len;i++){

    clos[i].show();
   }
 }
}

void Controller::add(){
system("cls");
Clothes clo;
int result;
string type;string sizes; int price;int wws;string ccd;
cout<<"\n\t*************添加服装信息************";
cout<<"\n\t请输入服装类型:";
cin>>type;
cout<<"\n\t请输入服装尺码:";
cin>>sizes;
cout<<"\n\t请输入服装颜色:";
cin>>ccd;
cout<<"\n\t请输入服装价格:";
cin>>price;
cout<<"\n\t请输入服装等级:";
cin>>wws;

clo.settype(type);
clo.setsizes(sizes);
clo.setccd(ccd);
clo.setprice(price);
clo.setwws(wws);
cout<<"\n\t类型\t尺码\t颜色\t价格\t等级";
clo.show();
result=MessageBox(NULL,"您确定要添加此数据？","确认提示",MB_YESNO|MB_ICONQUESTION);
if(result==6){
    clo.save();
    clos.push_back(clo);
    cout<<"\n\t添加成功";

}else{
   cout<<"\n\t取消添加";
}


}


void Controller::menu(){
int choise;
int num=0;

while(true){
    system("cls");
    cout<<"\n\t********欢迎使用服装管理系统*********";
    cout<<"\n\t********1·浏览服装信息*********";
    cout<<"\n\t********2·添加服装信息*********";
    cout<<"\n\t********3·修改服装信息*********";
    cout<<"\n\t********4·删除服装信息*********";
    cout<<"\n\t********5·查询服装信息*********";
    cout<<"\n\t********6·退出*********";
    do{
        if(num==0){
            cout<<"\n\t请输入您的选择(1-6)：";

        }else{
            cout<<"\n\t请重新输入：";

        }
         cin>>choise;
        num++;
    }while(choise<=0||choise>6);

switch(choise){
case 1:
   view();
    break;
case 2:
    add();
    break;

case 3:
    cout<<"\n\t修改服装信息";
    break;

case 4:
    cout<<"\n\t删除服装信息";
    break;
case 5:
    cout<<"\n\t查询服装信息";
    break;
case 6:
   exit(0);
}
cout<<"\n\n\t";
getch();
}


}

bool Controller::login(){
string name;
string mm;

for(int num=1;num>=0;num++)
 {

    cout << "\n\t请输入您的工号：";
    cin >>name;
    cout << "\n\t请输入您的密码：";
    cin >>mm;
    system ("cls");
    if(name=="wx"&&mm=="wx123")
    {
        return true;
    }
    else
    {
        if(num>=3){
            cout <<"\n\t账号异常，即将退出。。。。";
            exit(0);
        }
        else{
            cout <<"\n\t账号或密码错误，您还有"<<(3-num)<<"次机会";
        }
    }
 }
};
int main(){
cout<<"\n\n\t\t\t\t**********************服装管理系统*************************\n\n";

cout<<"\n\n";
getch();system ("cls");
Controller controller;
if(controller.login())
{
    controller.initdate();
    controller.menu();
}
}

