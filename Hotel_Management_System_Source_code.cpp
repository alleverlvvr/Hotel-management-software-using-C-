#include<iostream>
#include<conio.h>
#include<string.h>
#include <time.h>
#include<dos.h>
#include<fstream>
using namespace std;
void coupd();
void coup();
void gen();
void dlx();
void spd();
class hotel
{
public:
int room_no;
char name[30];
char address[50];
char phone[10];
public:
void main_menu(); //to dispay the main menu
void add(); //to book a room
void display(); //to display the customer record
void rooms(); //to display alloted rooms
void edit(); //to edit the customer record
int check(int); //to check room status
void modify(int); //to modify the record
void delete_rec(int); //to delete the record
};
void hotel::main_menu()
{
int choice;
while(choice!=5)
{
cout<<"\n\t\t\t\t*************";
cout<<"\n\t\t\t\t* MAIN MENU *";
cout<<"\n\t\t\t\t*************";
cout<<"\n\n\n\t\t\t1.Book A Room";
cout<<"\n\t\t\t2.Customer Record";
cout<<"\n\t\t\t3.Rooms Allotted";
cout<<"\n\t\t\t4.Edit Record";
cout<<"\n\t\t\t5.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;
switch(choice)
{
case 1: add();
break;
case 2: display();
break;
case 3: rooms();
break;
case 4: edit();
break;
case 5: break;
default:
{
cout<<"\n\n\t\t\tWrong choice!!!";
cout<<"\n\t\t\tPress any key to continue!!";
getch();
}
}
}
}
void hotel::add()
{
int r,flag;
ofstream fout("Record.dat",ios::app);
cout<<"\n Enter Customer Details";
cout<<"\n **********************";
cout<<"\n\n Room no: ";
cin>>r;
flag=check(r);
if(flag)
cout<<"\n Sorry..!!!Room is already booked";
else
{
room_no=r;
cout<<" Name: ";
gets(name);
gets(name);
cout<<" Address: ";
gets(address);
cout<<" Phone No: ";
gets(phone);
fout.write((char*)this,sizeof(hotel));
cout<<"\n Room is booked!!!";
}
cout<<"\n Press any key to continue!!";
getch();
fout.close();
}
void hotel::display()
{
ifstream fin("Record.dat",ios::in);
int r,flag;
cout<<"\n Enter room no: ";
cin>>r;
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\n Customer Details";
cout<<"\n ****************";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry Room no. not found or vacant!!";
cout<<"\n\n Press any key to continue!!";
getch();
fin.close();
}
void hotel::rooms()
{
ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t List Of Rooms Allotted";
cout<<"\n\t\t\t*********************";
cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t"<<phone;
}
cout<<"\n\n\n\t\t\tPress any key to continue!!";
getch();
fin.close();
}
void hotel::edit()
{
int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n *********";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";
cout<<"\n Enter your choice: ";
cin>>choice;
cout<<"\n Enter room no: ";
cin>>r;
switch(choice)
{
case 1: modify(r);
break;
case 2: delete_rec(r);
break;
default: cout<<"\n Wrong Choice!!";
}
cout<<"\n Press any key to continue!!!";
getch();
}
int hotel::check(int r)
{
int flag=0;
ifstream fin("Record.dat",ios::in);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
flag=1;
break;
}
}
fin.close();
return(flag);
}
void hotel::modify(int r)
{
long pos,flag=0;
fstream file("Record.dat",ios::in|ios::out|ios::binary);
while(!file.eof())
{
pos=file.tellg();
file.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\n Enter New Details";
cout<<"\n *****************";
cout<<"\n Name: ";
gets(name);
cout<<" Address: ";
gets(address);
cout<<" Phone no: ";
gets(phone);
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n Record is modified!!";
flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry Room no. not found or vacant!!";
file.close();
}
void hotel::delete_rec(int r)
{
int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;
if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;
}
else
fout.write((char*)this,sizeof(hotel));
}
fin.close();
fout.close();
if(flag==0)
cout<<"\n Sorry room no. not found or vacant!!";
else
{
remove("Record.dat");
rename("temp.dat","Record.dat");
}
};
class room : public hotel
{
public:
int r_no;
int r_charge;
char r_cust[20];
char c_city[20];
int c_mem;
char c_nat[20];
char r_avail;
int r_per;
int no;
char type[20];
int charge;
char cust[20];
char avail;
int per;
int year;
int mon;
int day;
public:
char r_type[20];
char getavail()
{
return(r_avail);
}
void getr1()
{
r_no=1;
strcpy(r_type,"Sp Dlx\t");
r_charge=1500;
r_avail='Y';
strcpy(r_cust,"N.A\t");
r_per=0;
}
void getr2()
{
r_no=2;
strcpy(r_type,"Dlx\t");
r_charge=1000;
r_avail='Y';
strcpy(r_cust,"N.A\t");
r_per=0;
}
void getr3()
{
r_no=3;
strcpy(r_type,"Gen\t");
r_charge=750;
r_avail='Y';
strcpy(r_cust,"N.A\t");
r_per=0;
}
void getr4()
{
r_no=4;
strcpy(r_type,"Couple\t");
r_charge=1250;
r_avail='Y';
strcpy(r_cust,"N.A\t");
r_per=0;
}
void getr5()
{
r_no=5;
strcpy(r_type,"C Dlx\t");
r_charge=1500;
r_avail='Y';
strcpy(r_cust,"N.A\t");
r_per=0;
}
void putinfo()
{
int r,flag;
ofstream fout("Record.dat",ios::app);
cout<<"\n"<<r_no<<"\t "<<r_type<<"\t "<<r_charge<<"\t "<<r_avail<<"\t "<<r_cust<<"\t "<<r_per;
}
void modify()
{
cout<<"\n Enter modified data";
cout<<"\n____________________________________________________________________________";
cout<<"\n Enter Room no :";
cin>>no;
cout<<"\n Enter Room type :";
cin>>type;
cout<<"\n Enter Room charges :";
cin>>charge;
cout<<"\n Enter Room Availability :";
cin>>avail;
cout<<"\n Enter name of cust living :";
cin>>cust;
cout<<"\n For how many days cust want the room :";
cin>>per;
cout<<"\n...... Data is modified";
r_no=no;
strcpy(r_type,type);
r_charge=charge;
r_avail=avail;
strcpy(r_cust,cust);
r_per=per;
}
void allocate()
{
if(r_avail=='Y')
{
cout<<"\n Enter Name of cust living :";
cin >>cust;
cout<<"\n For how many days cust want the room :";
cin>>per;
cout<<"\n Enter city name :";
cin>>c_city;
cout<<"\n Enter nationality :";
cin>>c_nat;
cout<<"\n Enter no. of member in your group :";
cin>>c_mem;
cout<<"\n Enter the date of arrival ";
cout<<"\n------------------------------";
cout<<"\n Year : ";
cin >>year;
cout<<"\n Month :";
cin >>mon;
cout<<"\n Day :";
cin >>day;
cout<<"\n... Room is allocated to "<<cust<<" for "<<per<<" days.";
strcpy(r_cust,cust);
r_per=per;
r_avail='N';
}
else
{
cout<<"\n ERROR : Room cannot be allocated ...";
cout<<"\n Room is not available...";
cout<<"r-enter basic details to search again and confirm you";
}
}
void putcust()
{
int i,j;
i=day+r_per;
if(j==0)
{
ifstream fin("Record.dat",ios::in);
int r,flag;
cout<<"\n Enter room no:(once more to search in database) ";
cin>>r;
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\n Customer Details";
cout<<"\n ****************";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
flag=1;
}
}
int k=1;
if(k==0)// just remove it while being serious.
{
cout<<"\n Data not available ";
}
}
else
{
cout<<"\n Room No :"<<r_no;
cout<<"\n Customer Name :"<<r_cust;
cout<<"\n Days :"<<r_per;
cout<<"\n City :"<<c_city;
cout<<"\n Nationality :"<<c_nat;
cout<<"\n No of member :"<<c_mem;
cout<<"\n Arrival Date :"<<day<<"/"<<mon<<"/"<<year;
date(i,mon,year);
}
}
void date(int d,int m,int y)
{
int i;
i=m%12;
if(i==0)
{
if(d>31)
{
d=d-31;
m=m+1;
}
if(m>12)
{
m=m-12;
y=y+1;
}
cout<<"\n Departure Date :"<<d<<"/"<<m<<"/"<<y;
}
else
if(i==1)
{
if(d>31)
{
d=d-31;
m=m+1;
}
if(m>12)
{
m=m-12;
y=y+1;
}
cout<<"\n Departure Date :"<<d<<"/"<<m<<"/"<<y;
}
else
if(i==2)
{
if(d>30)
{
d=d-30;
m=m+1;
}
if(m>12)
{
m=m-12;
y=y+1;
}
cout<<"\n Departure Date :"<<d<<"/"<<m<<"/"<<y;
}
else
if(i==3)
{
if(d>31)
{
d=d-31;
m=m+1;
}
if(m>12)
{
m=m-12;
y=y+1;
}
cout<<"\n Departure Date :"<<d<<"/"<<m<<"/"<<y;
}
else
if(i==4)
{
if(d>30)
{
d=d-30;
m=m+1;
}
if(m>12)
{
m=m-12;
y=y+1;
}
cout<<"\n Departure Date :"<<d<<"/"<<m<<"/"<<y;
}
else
if(i==5)
{
if(d>31)
{
d=d-31;
m=m+1;
}
if(m>12)
{
m=m-12;
y=y+1;
}
cout<<"\n Departure Date :"<<d<<"/"<<m<<"/"<<y;
}
else
if(i==6)
{
if(d>30)
{
d=d-30;
m=m+1;
}
if(m>12)
{
m=m-12;
y=y+1;
}
cout<<"\n Departure Date :"<<d<<"/"<<m<<"/"<<y;
}
else
if(i==7)
{
if(d>31)
{
d=d-31;
m=m+1;
}
if(m>12)
{
m=m-12;
y=y+1;
}
cout<<"\n Departure Date :"<<d<<"/"<<m<<"/"<<y;
}
else
if(i==8)
{
if(d>31)
{
d=d-31;
m=m+1;
}
if(m>12)
{
m=m-12;
y=y+1;
}
cout<<"\n Departure Date :"<<d<<"/"<<m<<"/"<<y;
}
else
if(i==9)
{
if(d>30)
{
d=d-30;
m=m+1;
}
if(m>12)
{
m=m-12;
y=y+1;
}
cout<<"\n Departure Date :"<<d<<"/"<<m<<"/"<<y;
}
else
if(i==10)
{
if(d>31)
{
d=d-31;
m=m+1;
}
if(m>12)
{
m=m-12;
y=y+1;
}
cout<<"\n Departure Date :"<<d<<"/"<<m<<"/"<<y;
}
else
if(i==11)
{
if(d>30)
{
d=d-30;
m=m+1;
}
if(m>12)
{
m=m-12;
y=y+1;
}
cout<<"\n Departure Date :"<<d<<"/"<<m<<"/"<<y;
}
}
};
class bill: public room
{
public:
long total;
int food;
long room;
float ser;
int t;
int oc;
public:
void calculate()
{
room= r_charge * r_per;
cout<<"\n Enter the bill amount of restaurant:";
cin>>food;
cout<<"\n Enter other charges:";
cin>>oc;
t=(int) room + food + oc;
ser=(int)(0.05*t);
total=t+ser;
}
void dispbill()
{
cout<<"\n________________________________________________________________________________";
cout<<"\n************************* Allever Hotel ***********************";
cout<<"\n -------------------------------- ";
cout<<"\n 1 no. Salt lake, howrah-700156";
cout<<"\n Tel :- 1458792 ";
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n Customer name : "<<r_cust;
cout<<"\n ";
cout<<"\n Stayed for "<<r_per<<" days";
cout<<"\n Room charges : "<<r_charge<<"(Per day)";
cout<<"\n Room charges : "<<room<<"(total)";
cout<<"\n Restaurant bill : "<<food;
cout<<"\n Other charges : "<<oc;
cout<<"\n Ser.tax = 5%";
cout<<"\n Ser.tax ="<<ser;
cout<<"\n Bill Amount is Rs "<<total;
cout<<"\n ";
cout<<"\n THANK YOU !!!!!";
cout<<"\n Do Visit Us Again !";
strcpy(r_cust,"N.A");
r_per=0;
r_avail='Y';
day=0;
mon=0;
year=0;
}
void check();
};
void bill:: check()
{
if(r_avail=='Y'||r_avail=='y')
{
cout<<"\n"<<r_no<<"\t "<<r_type<<"\t"<<r_charge<<"\t "<<r_avail<<"\t "<<r_cust<<"\t "<<r_per;
}
}
int main()
{
hotel h;
int i,ch;
bill R[5];
char c;
getch();
R[0].getr1();
R[1].getr2();
R[2].getr3();
R[3].getr4();
R[4].getr5();
time_t t;
t = time(NULL);
cout<<"\n "<<ctime(&t);
t -= 24L*60L*60L;
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n*************************** WELCOME TO ALLEVER HOTEL ************************";
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n--------------------------------------------------------------------------------";
getch();
xyz:
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n********************** Allever Hotel **************************";
cout<<"\n ________________________________ ";
cout<<"\n 1 no. salt lake, kolkata,700156 ";
cout<<"\n Tel-45454545. designed by- Rahul Shaw";
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n ";
cout<<"\n 1.GET INFORMATION  \t   2.GET CUSTOMER INFO ";
cout<<"\n ";
cout<<"\n 3.MODIFY INFORMATION  \t   4.CHECK THE AVAILABILITY ";
cout<<"\n ";
cout<<"\n 5.ALLOCATE ROOM  \t   6.FEATURES OF ROOMS ";
cout<<"\n ";
cout<<"\n 7.CREATE BILL  \t   8.EXIT ";
cout<<"\n\n Enter your choice : ";
cin >>ch;
if(ch>8)
{
cout<<"\n Wrong choice ....";
getch();
goto xyz;
}
if(ch==1)
{
cout<<"\n ROOM INFO ";
cout<<"\n ----------- ";
cout<<"\nRoom No| Type | Charge | Availability | Cust_Name | Period |";
for(i=0;i<=4;i++)
{
R[i].putinfo();
}
getch();
cout<<"\n ";
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n Do you want to exit(Y/N) :";
cin>>c;
if (c=='N'||c=='n')
goto xyz;
else
goto mno;
}
else
if(ch==2)
{
abc:
int n;
cout<<"\n Enter room no. :";
cin>>n;
if(n>5)
{
cout<<"\n Wrong choice ....";
getch();
}
//n=n-1;
cout<<"\n CUSTOMER INFO ";
cout<<"\n -------------- ";
R[n].putcust();
cout<<"\n ";
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n Do you want to exit (Y/N):";
cin>>c;
if (c=='N'||c=='n')
goto xyz;
else
goto mno;
}
else
if(ch==3)
{
pqr:
int a;
cout<<"\n Enter Room no :";
cin>>a;
if(a>5)
{
cout<<"\n Wrong choice ...";
getch();
}
a=a-1;
R[a].modify();
cout<<"kindly re-enter to store a copy of it in the database server";
h.edit();
getch();
cout<<"\n ";
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n Do you want to exit :";
cin>>c;
if (c=='N'||c=='n')
goto xyz;
else
goto mno;
}
else
if(ch==4)
{
cout<<"\n AVAILABLE ROOMS ";
cout<<"\n ----------------- ";
cout<<"\nRoom No| Type | Charge | Availability | Cust_Name | Period|";
for(i=0;i<=4;i++)
{
R[i].check();
}
getch();
cout<<"\n ";
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n Do you want to exit :";
cin>>c;
if (c=='N'||c=='n')
goto xyz;
else
goto mno;
}
else
if(ch==5)
{
int b;
def:
cout<<"\n Enter room no to be allocated:";
cin >>b;
if(b>5)
{
cout<<"\n Wrong choice ...";
getch();
goto def;
}
b=b-1;
R[b].allocate();
cout<<endl;
cout<<"kindly re-enter the basic information for storing in server";
h.add();
cout<<"\n ";
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n Do you want to exit :";
cin>>c;
if (c=='N'||c=='n')
goto xyz;
else
goto mno;
}
else
if(ch==6)
{
int a,d,e,f,g,h;
char c;
char b[5];
cout<<"\n Enter Room No:";
cin>>a;
if(a>5)
{
cout<<"\n Wrong choice ...";
getch();
}
a=a-1;
strcpy(b,R[a].r_type);
d=strcmp(b,"Sp Dlx");
e=strcmp(b,"Dlx");
f=strcmp(b,"Gen");
g=strcmp(b,"Couple");
h=strcmp(b,"C Dlx");
if(d==1)
{
spd();
}
else
if(e==1)
{
dlx();
}
else
if(f==1)
{
gen();
}
else
if(g==1)
{
coupd();
}
else
if(h==1)
{
coup();
}
getch();
cout<<"\n ";
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n Do you want to exit :";
cin>>c;
if (c=='N'||c=='n')
goto xyz;
}
else
if(ch==7)
{
stu:
int b;
cout<<"\n Enter Room no :";
cin>>b;
if(b>5)
{
cout<<"\n Wrong choice ...";
getch();
goto stu;
}
{
char av;
av=R[b-1].getavail();
if(av=='Y')
{
cout<<"\n ERROR: Room is not alloted.";
cout<<"\n Bill cannot be created ";
getch();
goto stu;
}
else
{
R[b-1].calculate();
R[b-1].dispbill();
getch();
}
}
cout<<"\n ";
cout<<"\n--------------------------------------------------------------------------------";
cout<<"\n Do you want to exit :";
cin>>c;
if (c=='N'||c=='n')
goto xyz;
}
else
if(ch==8)
{
goto mno;
}
mno:
return 0;
}
void spd()
{
cout<<"\n FEATURES OF THIS ROOM ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n\n Room Type >>> Sp.delux ";
cout<<"\n\n Room charges >>> Rs.1500 per day";
cout<<"\n\n 1. Bed >>> 2";
cout<<"\n\n 2.Capacity >>> 5";
cout<<"\n\n 3.Balcony available ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n ADDITIONAL FEATURES ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n\n 1.A/C available ";
cout<<"\n\n 2.Geyser available";
cout<<"\n\n 3.TV available ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n NOTE :- Extra bed will cost Rs.500 per bed ";
}
void dlx()
{
cout<<"\n FEATURES OF THIS ROOM ";
cout<<"\n-------------------------------------------------------------------";
cout<<"\n\n Room Type >>> Deluxe ";
cout<<"\n\n Room charges >>>Rs.1000 per day";
cout<<"\n\n 1. Bed >>> 2";
cout<<"\n\n 2.Capacity >>> 5";
cout<<"\n-------------------------------------------------------------------";
cout<<"\n ADDITIONAL FEATURES ";
cout<<"\n-------------------------------------------------------------------";
cout<<"\n\n 1.A/C available ";
cout<<"\n\n 3.Geyser available";
cout<<"\n\n 4.TV available ";
cout<<"\n-------------------------------------------------------------------";
cout<<"\n NOTE :- Extra bed will cost Rs.500 per bed ";
}
void gen()
{
cout<<"\n FEATURES OF THIS ROOM ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n\n Room Type >>> General ";
cout<<"\n\n Room charges >>>Rs.750 per day";
cout<<"\n\n 1. Bed >>> 2";
cout<<"\n\n 2.Capacity >>> 5";
cout<<"\n------------------------------------------------------------------";
cout<<"\n ADDITIONAL FEATURES ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n\n 1.Geyser available";
cout<<"\n------------------------------------------------------------------";
cout<<"\n NOTE :- Extra bed will cost Rs.500 per bed ";
}
void coup()
{
cout<<"\n FEATURES OF THIS ROOM ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n\n Room Type >>> Couple ";
cout<<"\n\n Room charges >>>Rs.1250 per day";
cout<<"\n\n 1. Bed >>> 1";
cout<<"\n\n 2. Capacity >>> 2";
cout<<"\n\n 3.Balcony available ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n ADDITIONAL FEATURES ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n\n 2.Geyser available";
cout<<"\n\n 3.TV available ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n NOTE :- Extra bed will cost Rs.500 per bed ";
}
void coupd()
{
cout<<"\n FEATURES OF THIS ROOM ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n\n Room Type >>> Couple deluxe ";
cout<<"\n\n Room charges >>> Rs.1500 per day";
cout<<"\n\n 1. Bed >>> 1";
cout<<"\n\n 2.Capacity >>> 2";
cout<<"\n\n 3.Balcony available ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n ADDITIONAL FEATURES ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n\n 1.A/C available ";
cout<<"\n\n 2.Geyser available";
cout<<"\n\n 3.TV available ";
cout<<"\n------------------------------------------------------------------";
cout<<"\n NOTE :- Extra bed will cost Rs.500 per bed ";
}
