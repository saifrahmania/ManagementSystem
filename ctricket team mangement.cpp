#include<bits/stdc++.h>
using namespace std;

class player
{
protected:
    char name[50],role[20];
    int age, jno;
    float height;
public:

     virtual void getdata()
    {
        cout<<"Enter player's Name:"<<endl;
        cin.ignore();
        cin.getline(name,50);
        cout<<"Enter player's Age :"<<endl;
        cin>>age;
        cout<<"Enter player's Height: "<<endl;
        cin>>height;
        cout<<"Enter player's Jersey No :"<<endl;
        cin>>jno;
        cout<<"Role of the player:  "<<endl;
        cin.ignore();
        cin.getline(role,20);

    }
    virtual void putdata()
    {
        cout<<"Player's Info:  "<<endl;
        cout<<"Name:  "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Height:  "<<height<<endl;
        cout<<"Jersey No: "<<jno<<endl;
        cout<<"Role of the player:  "<<role<<endl;

    }
   virtual void player_report()
    {
        cout<<jno<<setw(10)<<name<<setw(10)<<age<<setw(10)<<height<<setw(10)<<role<<setw(10);
    }

};

class batsman: public player
{
protected:
    int previous_match,previous_score, highest_score;
    float average_run;
public:
    void bat_getdata()
    {
         player::getdata();
        cout<<"Enter the number of matches player played:  "<<endl;
        cin>>previous_match;
        cout<<"Enter player's previous total score"<<endl;
        cin>>previous_score;
        cout<<"Enter player's average score "<<endl;
        cin>>average_run;
        cout<<"Enter player's highest score:  "<<endl;
        cin>>highest_score;
    }

    void bat_putdata()
    {
         player:: putdata();
        cout<<"previously played : "<<previous_match<<"matches"<<endl;
        cout<<"previous score:  "<<previous_score<<endl;
        cout<<"Highest Score: "<<highest_score<<endl;
        cout<<"Average run is:  "<<average_run<<endl;
    }
    void bat_report()
    {
        player::player_report();
        cout<<previous_match<<setw(10)<<previous_score<<setw(10)<<highest_score<<setw(10)<<
        average_run;
    }



};
class bowler: public player
{
protected:
    int previous_match,previous_wicket,highest_wicket;
    float average_wicket;
public:
     void bowl_getdata()
    {
         void player::getdata();
        cout<<"Enter the number of matches player played:  "<<endl;
        cin>>previous_match;
        cout<<"Enter player's previous total wicket"<<endl;
        cin>>previous_wicket;
        cout<<"Enter player's average wicket"<<endl;
        cin>>average_wicket;
        cout<<"Enter player's highest wicket:  "<<endl;
        cin>>highest_wicket;
    }
    void bowl_putdata()
    {
        void player:: putdata();
        cout<<"previously played : "<<previous_match<<"matches"<<endl;
        cout<<"previous score:  "<<previous_wicket<<endl;
        cout<<"Highest Score: "<<highest_wicket<<endl;
        cout<<"Average run is:  "<<average_wicket<<endl;
    }
    void bowl_report()

    {
       void  player_report();
        cout<<previous_match<<setw(10)<<previous_wicket<<setw(10)<<highest_wicket<<setw(10)<<average_wicket;
    }


};

class allrounder: public bowler, public batsman
{
public:
    void all_getdata()
    {
         void bowler::bowl_getdata();
        void  batsman::bat_getdata();
    }
    void all_putdata()
    {
        void  bowler::bowl_putdata();
        void  batsman:: bat_putdata();
    }
    void all_report()
    {
       void  batsman::bat_report();
       void  bowler::bowl_report();
    }
} ;
class cricketer: public player,public batsman,public bowler, public allrounder
{
protected:

    int jno;
    char tp;
     bowler bo1;
    batsman ba1;
    allrounder all1;
    char t,type;
public:
    cricketer_getdata()
    {

     cout <<"Enter player type: \n"<<"For batsman press 'B'\n"
     <<"for Bowler press 'O'\n"<<"For All rounder press 'A'"<<endl;
     cin>>t;
     type=toupper(t);
     do
     {
         switch (type)
     {
     case 'B':
        {
            ba1.bat_getdata();
            cout<<"Player type:  "<<type<<endl;
        }
    case 'O':
        {
            bo1.bowl_getdata();
            cout<<"Player type:  "<<type<<endl;
        }
    case 'A':
        {
            all1.all_getdata();
            cout<<"Player type:  "<<type<<endl;
        }
    default:
        {
            cout<<"Invalid Input"<<endl;
        }


     }
     } while (type=='B'||type=='O'==type=='A');
    }
    cricketer_putdata()
    {


           ba1.bat_putdata();



            bo1.bowl_putdata();



            all1.all_putdata();


    }
     int jourseyno()
    {
        return jno;
    }
    char typ()
    {
        tp = type;
        return tp;
    }
    void cricketer_report ()
    {
        ba1.bat_report();
        bo1.bowl_report();
        all1.all_report();
    }



};

void creatProfile();
void displayProfile( )  ;
void modifyProfile(int );
void deleteProfile(int );
void playerEnque( )  ;
void allPlayerList()  ;
void intro();

int main()
{
cout<<"hello";
}
void creatProfile()
{
    cricketer c1;
    c1.cricketer_getdata();
}


void displayProfile(int x)
{
    cricketer c1;
    bool flag = false;
    ifstream inFile;
    inFile.open("profile.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\nBALANCE DETAILS\n";

        while(inFile.read(reinterpret_cast<char *> (&c1), sizeof(cricketer)))
    {
        if(c1.jourseyno()==x)
        {
            c1.cricketer_putdata();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nprofile number does not exist";
}
void modifyProfile(int x)
{
    bool found=false;
    cricketer c1;
    fstream File;
    File.open("profile.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&c1), sizeof(cricketer));
        if(c1.jourseyno()==x)
        {
            c1.cricketer_putdata();
            cout<<"\n\nEnter The New Details of profile"<<endl;
            c1.cricketer_getdata();
            int pos=(-1)*static_cast<int>(sizeof(cricketer));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&c1), sizeof(cricketer));
            cout<<"\n\n\t Record Updated";
            found=true;
}
    }
}
void deleteProfile(int x)
{
     cricketer c1;
    ifstream inFile;
    ofstream outFile;
    inFile.open("profile.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&c1), sizeof(cricketer)))
    {
        if(c1.jourseyno()!=x)
        {
            outFile.write(reinterpret_cast<char *> (&c1), sizeof(cricketer));
        }
    }
    inFile.close();
    outFile.close();
    remove("profile.dat");
    rename("Temp.dat","profile.dat");
    cout<<"\n\n\tRecord Deleted ..";
}
void playerEnque(int x)
{

}
void allPlayerList()
{
    cricketer c1;
    ifstream inFile;
    inFile.open("profile.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\n\n\t\tAll Player List \n\n";
    cout<<"====================================================\n";
    cout<<"Jersey.      NAME           Age  Height  Role    Previous Match Previous Score Highest Score  Average run  Previous wicket Highest Wicket  Average Wicket\n";
    cout<<"====================================================\n";
    while(inFile.read(reinterpret_cast<char *> (&c1), sizeof(cricketer)))
    {
        c1.cricketer_report();
    }
    inFile.close();
}
void intro()
{

}


