#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;
int i=0;
bool login1=false;

struct car{
    string car_name[100]={};
    string model_name[100]={};
    int registr[100]={ };
    bool booke[100]={};
    int day[100];

} ;

struct car obj1;

void details(int x)
{
    cout<<"\n"<<obj1.car_name[x];
    cout<<"\n"<<obj1.model_name[x];
    cout<<"\n"<<obj1.registr[x];
     
}
void booking()
{  int ch;

cout<<"Booking -> 1\n Cancle booking -> 2\n";
  switch(ch)
  {
    case 1:
    {
        string mod;
    cout<<"\n Enter the model you want :";
    while(mod!= obj1.car_name[i])
    {
        i++;
        if(i>100)
        {
            break;
        }
    }
    if(obj1.booke[i] == false){
        cout<<"\n ";
    details(i);
    cout<<"For how many days you want to book :";
    cin>>obj1.day[i];
obj1.booke[i]=true;

    }
    else
    {
        cout<<"\n The car is not available at the moment \n";
    }
    }


    case 2 :{
        string chh;
        cout<<"Do you really want to cancle your booking(yes/no) : ";
        cin>>chh;
        string model;
        int j=0;
        if(chh=="yes")
        {
            while(obj1.model_name[j]!=model&&j<100)
            if(obj1.model_name[j]==model){
            obj1.booke[j]=false;
            }
            else 
            cout<<"incorrect model";
            exit(0);
        }
        else{
            exit(0);
        }
    }
  
    
      
}
}
void login()
{
    string pss;
    int phoneno;
    string mytext;
    cout<<"Enter Your registered mobile no : ";
    cin>>phoneno;

    cout<<"\nEnter the Password : ";
    cin>>pss;

ifstream MyReadFile("car_rental_details.txt");
    while (getline(MyReadFile, mytext)) {
          if(mytext==pss)
          {
            login1=true;
            cout<<"The password is correct ...\n";
          }
    }


MyReadFile.close();

 }


void signup()
{   string Name;
    string Email_id;
    string pass;
    string phone_no;
    cout<<"Enter your Name : ";
    cin>>Name;
     cout<<"\nEnter your Email id : ";
    cin>>Email_id;
      cout<<"\nEnter the phone no  you want to use  : ";
    cin>>phone_no;
     cout<<"\nEnter the Password you want to use  : ";
    cin>>pass;
    

    ofstream file("car_rental_details.txt");
    file<<Name ;
    file<<"\n";
    file<<Email_id;
    file<<"\n";
    file<<pass;
    file<<"\n";
    file<<phone_no;

    file.close();
    

}


int main()
{
     

int ch;
cout<<"LOGIN ----------------------------> 1 \n Signup ------------------------------> 2\n";
cin>>ch;
switch(ch)
{
    case 1 : 
    {
        login();
        if (login1==true)
        {
            booking();
        }

    }
    case 2:
    {
        signup();
        

    }
    case 3 :
    {
        exit(0);
    }
}


login1=false;
    return 0;
}