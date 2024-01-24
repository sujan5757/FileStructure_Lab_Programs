#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int n=0,indx=0;
class student
{
public: char name[20],usn[20],branch[5];
int sem;
void insert(fstream &f1,fstream &f2)
{
cout<<"Enter Name: ";
cin>>name;
cout<<"Enter USN: ";
cin>>usn;
cout<<"Enter Sem: ";
cin>>sem;
cout<<"Enter Branch: ";
cin>>branch;
write(f1,f2);
}
void write(fstream &f1,fstream &f2)
{
f1<<++indx<<"\t"<<name<<"\n";
f2<<name<<"\t"<<usn<<"\t"<<sem<<"\t"<<branch<<"\n";
}
void display(fstream &f2)
{
f2>>name>>usn>>sem>>branch;
cout<<name<<"\t"<<usn<<"\t"<<sem<<"\t"<<branch<<"\n";

}
int search(fstream &f1,char key[20])
{
int i,x;
for(i=1;i<=n;i++)
{
f1>>x>>name;if(strcmp(name,key)==0)
return i;
}
cout<<"Record not found\n";
return 0;
}
int remove(fstream &f1,char key[20])
{
int i;
i=search(f1,key);
return i;
}

};
int main()
{
fstream f1,f2;
student s[20],p;
int ch,k=0,i,j;
for(;;)
{
cout<<"1.Insert 2.Display 3.Search 4.Delete 5.Exit\n";
cout<<"Enter choice: ";
cin>>ch;
switch(ch)
{
case 1: f1.open("m.txt",ios::app);

f2.open("mn.txt",ios::app);
cout<<"Enter no. of students: ";
cin>>k;
n=n+k;
for(int i=1;i<=k;i++)
s[i].insert(f1,f2);
f1.close();
f2.close();
break;
case 2: f2.open("mn.txt",ios::in);
for(i=1;i<=n;i++)
s[i].display(f2);
f2.close();
break;
case 3: char name[20];
cout<<"Enter name to search: ";
cin>>name;
f1.open("m.txt",ios::in);
f2.open("mn.txt",ios::in);
 j=p.search(f1,name);
if(j!=0)
{
cout<<"Record found & Details are\n";
cout<<"Name="<<s[j].name<<"\n"<<"USN="<<s[j].usn<<"\n"
<<"Sem="<<s[j].sem<<"\n"<<"Branch="<<s[j].branch<<"\n";
}
f1.close();
f2.close();
break;

case 4: f1.open("m.txt",ios::in);
f2.open("mn.txt",ios::in);
cout<<"Enter name to delete: ";

cin>>name;
j=p.remove(f1,name);
if(j!=0)
{
for(i=j;i<n;i++)
s[i]=s[i+1];
cout<<"Deletion successfull\n";
}
n--;
indx--;
f1.close();
f2.close();
f1.open("m.txt",ios::trunc|ios::app);
f2.open("mn.txt",ios::trunc|ios::app);
indx=0;
for(i=1;i<=n;i++)
s[i].write(f1,f2);
f1.close();
f2.close();
break;
default:return 0;
}
}
}
