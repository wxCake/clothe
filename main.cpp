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
cout<<"\n\t*************�����װ��Ϣ************";
if(clos.size()<=0){
cout<<"\n\t���޷�װ��Ϣ";
}else{
cout<<"\n\t����\t�ͺ�\t��ɫ\t�۸�\t�ȼ�";
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
cout<<"\n\t*************��ӷ�װ��Ϣ************";
cout<<"\n\t�������װ����:";
cin>>type;
cout<<"\n\t�������װ����:";
cin>>sizes;
cout<<"\n\t�������װ��ɫ:";
cin>>ccd;
cout<<"\n\t�������װ�۸�:";
cin>>price;
cout<<"\n\t�������װ�ȼ�:";
cin>>wws;

clo.settype(type);
clo.setsizes(sizes);
clo.setccd(ccd);
clo.setprice(price);
clo.setwws(wws);
cout<<"\n\t����\t����\t��ɫ\t�۸�\t�ȼ�";
clo.show();
result=MessageBox(NULL,"��ȷ��Ҫ��Ӵ����ݣ�","ȷ����ʾ",MB_YESNO|MB_ICONQUESTION);
if(result==6){
    clo.save();
    clos.push_back(clo);
    cout<<"\n\t��ӳɹ�";

}else{
   cout<<"\n\tȡ�����";
}


}


void Controller::menu(){
int choise;
int num=0;

while(true){
    system("cls");
    cout<<"\n\t********��ӭʹ�÷�װ����ϵͳ*********";
    cout<<"\n\t********1�������װ��Ϣ*********";
    cout<<"\n\t********2����ӷ�װ��Ϣ*********";
    cout<<"\n\t********3���޸ķ�װ��Ϣ*********";
    cout<<"\n\t********4��ɾ����װ��Ϣ*********";
    cout<<"\n\t********5����ѯ��װ��Ϣ*********";
    cout<<"\n\t********6���˳�*********";
    do{
        if(num==0){
            cout<<"\n\t����������ѡ��(1-6)��";

        }else{
            cout<<"\n\t���������룺";

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
    cout<<"\n\t�޸ķ�װ��Ϣ";
    break;

case 4:
    cout<<"\n\tɾ����װ��Ϣ";
    break;
case 5:
    cout<<"\n\t��ѯ��װ��Ϣ";
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

    cout << "\n\t���������Ĺ��ţ�";
    cin >>name;
    cout << "\n\t�������������룺";
    cin >>mm;
    system ("cls");
    if(name=="wx"&&mm=="wx123")
    {
        return true;
    }
    else
    {
        if(num>=3){
            cout <<"\n\t�˺��쳣�������˳���������";
            exit(0);
        }
        else{
            cout <<"\n\t�˺Ż��������������"<<(3-num)<<"�λ���";
        }
    }
 }
};
int main(){
cout<<"\n\n\t\t\t\t**********************��װ����ϵͳ*************************\n\n";

cout<<"\n\n";
getch();system ("cls");
Controller controller;
if(controller.login())
{
    controller.initdate();
    controller.menu();
}
}

