#include<iostream>
#include<fstream>
#include "My Contacts.cpp"
#include<string.h>
using namespace std;

contact obj;

void ReadData()
{
    fstream rd;
    rd.open("DataFile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);

    cout<<endl;
    cout<<left;
    cout<<setw(20);
    cout<<"Full Name";
    cout<<setw(15);
    cout<<"Mobile NO.";
    cout<<setw(30);
    cout<<"E-mail";
    cout<<setw(20);
    cout<<"Instagram";
    cout<<setw(20);
    cout<<"Twitter";
    cout<<endl<<"---------------------------------------------------------------------------------------------------";
    for(int i=0;i<s;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        obj.display();
    }
    cout<<endl<<"---------------------------------------------------------------------------------------------------";
}
void AddContact()
{
    char name[50];
    cout<<endl<<"Enter the name to check if it already exists";
    cin>>name;
    fstream rd;
    rd.open("DataFile.txt");
    obj.accept();
    fstream wr;
    wr.open("DataFile.txt",ios::app);
    wr.write((char*)&obj,sizeof(obj));
    wr.close();
    cout<<endl<<"File Written.";
}
void DeleteContact()
{
    char name[50];
    int a=0,b=0;
    cout<<endl<<"Enter the name to be removed:";
    cin>>name;
    fstream rd;
    rd.open("DataFile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    for(int i=1;i<=size;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            cout<<endl<<"Contact deleted";
        }
        else
        {
           wr.write((char *)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("DataFile.txt");
    rename("tempfile.txt","DataFile.txt");

}
void caller()
{
    int i;
    cout<<endl<<"Press 1 to read contacts";
    cout<<endl<<"Press 2 to add contact";
    cout<<endl<<"Press 3 to delete contacts";
    cout<<endl<<"Press 4 to update contacts";
    cout<<endl<<"Press 5 to search by Name";
    cout<<endl<<"Press 6 to search by Mobile";
    cout<<endl<<"Press 7 to search by E-Mail";
    cin>>i;
    if(i==1)
    {
        ReadData();
    }
    if(i==2)
    {
        AddContact();
    }
    if(i==3)
    {
        DeleteContact();
    }
}
int main()
{
    caller();
}
