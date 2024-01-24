         #include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


class student
{
	private: char buf[45],name[10],sem[10],branch[10];
		int pos;
	public:
		void read()
		{
			cout<<"Name:"<<endl;
			cin>>name;
			cout<<"Semester:"<<endl;
			cin>>sem;
			cout<<"Branch:"<<endl;
			cin>>branch;
		}
		void pack(fstream &ofile)
		{
			read();
			strcpy(buf,"");
			strcat(buf,name);
			strcat(buf,"|");
			strcat(buf,sem);
			strcat(buf,"|");
			strcat(buf,branch);
			strcat(buf,"|");
			strcat(buf,"\n");
			ofile.write(buf,strlen(buf));
		}
		void unpack(fstream &ifile)
		{
			char extra[45];
			while(!ifile.eof())
			{
				ifile.getline(name,10,'|');
				ifile.getline(sem,10,'|');
				ifile.getline(branch,10,'|');
				ifile.getline(extra,45,'\n');
				cout<<name<<"\t";
				cout<<sem<<"\t";
				cout<<branch<<"\n";
			}
		}
		int search(fstream &ifile,char key[])
		{
			char extra[45];
			while(!ifile.eof())
			{
				ifile.getline(name,10,'|');
				ifile.getline(sem,10,'|');
				ifile.getline(branch,10,'|');
				ifile.getline(extra,45,'\n');
				if(strcmp(name,key)==0)
				{
					cout<<" "<<"record found and details are:"<<endl;
					cout<<" "<<"name\n"<<name<<endl;
					cout<<" "<<"semester\n"<<sem<<endl;
					cout<<" "<<"branch\n" <<branch<<endl;
					return 1;
				}
			}
			return 0;
		}
		void modify(fstream &ifile,char key[])
		{
			fstream gfile;
			student s[10];
			char extra[50];
			int i=0;
			while(!ifile.eof())
			{
				
				ifile.getline(s[i].name,10,'|');
				
				ifile.getline(s[i].sem,10,'|');
				
				ifile.getline(s[i].branch,10,'|');
				
				ifile.getline(extra,45,'\n');
				i++;
			}
			ifile.close();
			int flag=0;
			for(int j=0;j<i;j++)
			{
				if(strcmp(key,s[j].name)==0)
				{
					flag=1;
					cout<<"record found details are:"<<endl;
					cout<<s[j].name<<endl;
					cout<<s[j].sem<<endl;
					cout<<s[j].branch<<endl;
					
					cout<<"enter the modification details\n"<<endl; 
					cout<<"enter the name\n"<<endl;
					cin>>s[j].name;
					cout<<"enter the sem\n"<<endl;
					cin>>s[j].sem;
					cout<<"enter the branch\n"<<endl;
					cin>>s[j].branch;
				}
			}
			if(flag==0)
			{
				cout<<"Record not found\n";
				return;
			}
			gfile.open("student.txt",ios::out);
			for(int k=0;k<i-1;k++)
			{
				strcpy(buf,"");
				strcat(buf,s[k].name);
				strcat(buf,"|");
				strcat(buf,s[k].sem);
				strcat(buf,"|");
				strcat(buf,s[k].branch);
				strcat(buf,"|");
				strcat(buf,"\n");
				
				gfile.write(buf,strlen(buf));
			}
			gfile.close();
		}
};

int main()
{
	int n,i,ch;
	char key[10];
	student stu;
	fstream ifile,ofile;
	fstream iofile;
	
	fstream infile;
	
	ofile.open("student.txt",ios::trunc|ios::app);
	ofile.close();
	for(;;)
	{
	
	cout<<"1.insert\n 2.display\n 3.search\n 4.modify\n 5.exit\n";
	 cout<<"enter your choice"<<endl; 
	 cin>>ch;
	switch(ch)
	{
		case 1: 
			ofile.open("student.txt",ios::out|ios::app);
			cout<<"enter the no of students\n";
			cin>>n;
			for(i=0;i<n;i++)
			{
				stu.pack(ofile);
			}
			ofile.close();
			break;
		case 2: 
			infile.open("student.txt",ios::in);
			stu.unpack(infile);
			infile.close();
			break;
		case 3:cout<<"enter the record name to be searched\n"<<endl; 
			cin>>key;
			
			ifile.open("student.txt",ios::in);
			if(stu.search(ifile,key)==0)
			cout<<"record not found\n";
			ifile.close();
			break;
		case 4: 
			iofile.open("student.txt",ios::in|ios::out);
			cout<<"enter the record name to be modified\n"<<endl;
			cin>>key;
			stu.modify(iofile,key);
			
			iofile.close();
			break;
		default:return 0;
		}
	}
	
}
		
