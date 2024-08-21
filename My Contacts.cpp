#include<iostream>
#include<iomanip>
using namespace std;

class contact
{
private:
    char name[50],mob[50],mail[50],insta[50],twit[50];

public:
    void accept()
    {
        cout<<endl<<"Enter the name:";
        cin>>name;
        cout<<endl<<"Enter the Mobile No:";
        cin>>mob;
        cout<<endl<<"Enter the E-Mail:";
        cin>>mail;
        cout<<endl<<"Enter the Instagram Handle:";
        cin>>insta;
        cout<<endl<<"Enter the Twitter Handle:";
        cin>>twit;


    }
    void display()
    {

       cout<<endl;
       cout<<left;
       cout<<setw(20);
       cout<<name;
       cout<<setw(15);
       cout<<mob;
       cout<<setw(30);
       cout<<mail;
       cout<<setw(20);
       cout<<insta;
       cout<<setw(20);
       cout<<twit;


    }
    friend void AddContact();
    friend void DeleteContact();
};
void AddContact();
void DeleteContact();
