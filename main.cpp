#include <iostream>
#include <fstream>
#include<iomanip>
#include <cstdlib>
#include <string>
using namespace std;
class Photo
{
      int s_number;
      string s_topic;
      string s_description;
      string s_date;

public:
    Photo(){}///конструктор
    ~Photo(){}///деструктор
Photo(int number, string topic, string description, string date);

int GetNumber(){return s_number;}
string GetTopic(){return s_topic;}
string GetDescription(){return s_description;}
string GetDate(){return s_date;}

};

Photo::Photo (int number,string topic, string description, string date):
s_number(number),s_topic(topic),s_description(description),s_date(date){}
///дефиниция на деструктор
int main()
{
cout<<"how many photos would you like to insert?"<<endl;
int choice;
cin>>choice;

 Photo album[choice];///масив
 int number;
 string topic, description, date;

 cout << "Enter number, topic, description, and date.\n";

 Photo *aphoto;

 for (int i=0;i<choice;i++)
 {
    cout <<"Number:  ";
    cin >>number;
    cout <<"topic:  ";
    cin >>topic ;
    cout <<"description:  ";
    cin >>description;
    cout <<"date:  ";
    cin >>date;
    cout<<"_______________________________"<<endl;
    aphoto = new Photo (number, topic, description, date);
    album[i]=*aphoto;
    delete aphoto;
    }

 ofstream fout;

 fout.open( "records.txt" );

  if ( !fout )
   {
      cerr << "error finding the file" << endl;
      system( "PAUSE" );
      exit( 1 );
   }

   for (int i=0;i<choice;i++)

   {
      fout<< album[i].GetNumber() << ' ' << album[i].GetTopic()<< ' '<<album[i].GetDescription()<< ' ' << album[i].GetDate() << '\n';
   }
   fout.close();
   system( "PAUSE" );

   return 0;

}
