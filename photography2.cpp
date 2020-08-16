#include <iostream>
#include <fstream>
#include<iomanip>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
class Photo
{
      int s_number;
      string s_topic;
      string s_description;///������ ����������-����������
      string s_date;

public:
    Photo(){}///�����������
    ~Photo(){}///����������
Photo(int number, string topic, string description, string date);

int GetNumber(){return s_number;}
string GetTopic(){return s_topic;} ///��� ���������
string GetDescription(){return s_description;}
string GetDate(){return s_date;}

};

Photo::Photo (int number,string topic, string description, string date):
s_number(number),s_topic(topic),s_description(description),s_date(date){}  ///��������� �� ������������

void output(Photo);///���������� �� ������� void

int main()
{
cout<<"how many photos would you like to display?"<<endl;
int choice;
cin>>choice;

 Photo albumm[choice];///���������� �� ����� albumm �� ��� Photo � ������ choice
 int number;
 string topic, description, date;

 ifstream inRecordFile("records.txt");///���� �� ��������� �� ����
 if (!inRecordFile)///��������
 {
     cerr<<"file not found in directory\n";
     system("PAUSE");
     exit(1);
 }


 Photo *pPhoto;///����������� �� ������� ����� ��� �����

 for (int i=0;i<choice;i++)
 {
    inRecordFile>>number>>topic>>description>>date;
    pPhoto=new Photo(number,topic,description, date);
    albumm[i]=*pPhoto;
    delete pPhoto;
    }

    sort(albumm, albumm + choice, [](Photo A, Photo B) -> bool { return (A.GetTopic() < B.GetTopic()); });

    for(int i = 0; i < choice; i++)
    {
        output(albumm[i]);
    }

system( "PAUSE" );
while(cin>>topic)
for (int i=0; i<0;i++)
{
    if (=topic){

 output(albumm[i]);
}
else
    cout<<"type other topic"<<endl;

}
return 0;
}
void output( Photo photo ) /// ������� �� ������������� �� ��������� �� �����
{
   cout<<photo.GetNumber()<<' '<<photo.GetTopic()<<' '<<photo.GetDescription()<<' '<<photo.GetDate()<< '\n';
}
