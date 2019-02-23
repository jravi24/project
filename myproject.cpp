 #include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<cstring>
using namespace std;
class user
{
	char d_name[50];
	char name[50];
	char section[10];
	char id[50];
	char mobile_num[30];
	char mail_adress[50];
	char c_num[30];
	char password[30];
	int t_sub;
	char subject[10][10];
public:
	int i;
	void get_data()//student data entry from user portal
	{
		cout<<"enter the name of the college"<<endl;
		cin>>c_name;
		cout<<"enter the name of the student"<<endl;
		cin>>name;
		cout<<"enter the section of the student"<<endl;
		cin>>section;
		cout<<"enter the id of the student"<<endl;
		cin>>id;
		cout<<"enter the mobile number of the student"<<endl;
		cin>>mobile_num;
		cout<<"enter the citizenship number"<<endl;
		cin>>c_num;
		cout<<"enter the mail adress of the student"<<endl;
		cin>>mail_adress;
		cout<<"enter the total subject"<<endl;
		cin>>t_sub;
		for(i=0;i<t_sub;i++)
		{
			cout<<"enter the subjects name"<<endl;
			cin>>subject[i];
		}
	}

int studprofile()//this function displays the student details at the student portal
{
	cout<<"college name"<<c_name<<endl;
	cout<<"student name"<<name<<endl;
	cout<<"student section"<<section<<endl;
	cout<<"id of the student"<<id<<endl;
	cout<<"mobile number of student"<<mobile_num<<endl;
	cout<<"citizenship number"<<c_num;
	cout<<"mail adress is"<<mail_adress;
	return 0;
}
int get_sub()
{
	cout<<"\n student total subject :-"<<t_sub<<endl;
	for(i=0;i<t_sub;i++)
	{
		cout<<"\n\tsubject"<<":-"<<subject[i];
		i=i+1;
	}
	return 0;
}
void addsub()
{
	cout<<"enter a new subject\n"<<endl;
	cin>>subject[t_sub];
	t_sub++;
	cout<<"You added a new subject to your subject list"<<endl;
}
void modiyprofile()
{
	cout<<"the profile details are :-"<<endl;

	cout<<"college name"<<c_name<<endl;
	cout<<"student name"<<name<<endl;
	cout<<"student section"<<section<<endl;
	cout<<"id of the student"<<id<<endl;
	cout<<"mobile number of student"<<mobile_num<<endl;
	cout<<"citizenship number"<<c_num<<endl;
	cout<<"mail adress is"<<mail_adress<<endl;
	int k=-1;
	if(k=1)
	{
		char ename[20];
		cout<<"enter the college name to be modified"<<endl;
		cin>>ename;
		strcpy(c_name,ename);
		cout<<"the college name updated successfully\n"<<endl;
	}
	else if(k=2)
	{
		char mname[30];
		cout<<"enter the name of the student to be modified"<<endl;
		cin>>mname;
		strcpy(name,mname);
		cout<<"the name of the student updated successfully"<<endl;
	}
	else if(k=3)
	{
		char sec[5];
		cout<<"enter the section to be modified"<<endl;
		cin>>sec;
		strcpy(section,sec);
		cout<<"the section of the student is updated successfully"<<endl;
	}
	else if(k=4)
	{
		char id_no[20];
		cout<<"enter the id number to be replaced"<<endl;
		cin>>id_no;
		strcpy(id,id_no);
		cout<<"the id updated successfully"<<endl;
	}
	else if(k=5)
	{
		char m_num[30];
		cout<<"enter the mobile number to be replaced"<<endl;
		cin>>m_num;
		strcpy(mobile_num,m_num);
		cout<<"the mobile number  updated successfully"<<endl;
	}
	else if(k=6)
	{
		char m_adress[30];
		cout<<"enter the mail adress to be replaced"<<endl;
		cin>>m_adress;
		strcpy(mail_adress,m_adress);
		cout<<"the mail adress updated successfully"<<endl;
	}
	else if(k=7)
	{
		char citizenship[40];

		cout<<"enter the citizenship number"<<endl;
		cin>>citizenship;
		strcpy(c_num,citizenship);
		cout<<"the citizenship number is updated successful"<<endl;
	}

	else
		cout<<"invalid operation..."<<endl;
}
void stdisplay()//this function displays all the relavant information to the user portal.
{
	cout<<"college name"<<c_name<<endl;
	cout<<"student name"<<name<<endl;
	cout<<"student section"<<section<<endl;
	cout<<"id of the student"<<id<<endl;
	cout<<"mobile number of student"<<mobile_num<<endl;
	cout<<"citizenship number"<<c_num<<endl;
	cout<<"mail adress is"<<mail_adress<<endl;
	for(i=0;i<t_sub;i++)
	{
		cout<<"\n\tsubject"<<":-"<<subject[i];
		i=i+1;
	}
	if(t_sub==0)
		cout<<"no subject specified"<<endl;
}
};
int main()
{
	user a;
	user f;
	user s;
	char con;
	int ch;
	char choice;
	MAIN_MENU :
do{
	cout<<"\n\n\n\t\tWelcome to student database portal"<<endl;
	cout<<"\n\n\n\t\tEnter to continue"<<endl;
	getchar();
	cout<<"\n\n\n\t\t press 1 for the user portal"<<endl;
	cout<<"\n\n\n\t\t press 2 for the student portal"<<endl;
	cout<<"\n\n\n\t\t enter your choice"<<endl;
	cin>>ch;
	switch(ch)
	{
	    case 1:
            int temp;
						MENU1 :
			cout<<"\n press 1 to add a student record"<<endl;
			cout<<"\n press 2 to add multiple student record"<<endl;
			cout<<"\n press 3 to view all records of student"<<endl;
			cout<<"\n press 4 to exit"<<endl;
			cout<<"\n enter your choice"<<endl;
			cin>>temp;
			if(temp==1)//for single student record entry
			{
				cout<<"enter the details of a student"<<endl;
				fstream fs;
				fs.open("stinfo.txt",ios::out);
				a.get_data();
				fs.write((char *)&a,sizeof(user));
				fs.close();
				cout<<"the data entered successfully"<<endl;
				goto MENU1;
			}
			if(temp==2)//for multiple student record
			{
				char m='0';
				fstream fs;
				fs.open("stinfo.txt",ios::ate);
				do
				{
					cout<<"enter the details"<<endl;
					a.get_data();
					fs.write((char *)&a,sizeof(user));
					cout<<"press 0 if u want to continue"<<endl;
					cin>>m;
				}while(m=='0');
				fs.close();
				cout<<"record updated successfully"<<endl;
				goto MENU1;
			}
			if(temp==3)
			{
				fstream fs;
				fs.open("stinfo.txt",ios::in);
				fs.seekg(0);
				while(fs.eof()!=0)
				{
					fs.read((char *)&a,sizeof(user));
					a.stdisplay();
				}
				fs.close();
			}
			if(temp==4)
			{
				goto MAIN_MENU;
			}
			if(temp<1||temp>4)
			{
				cout<<"invalid input"<<endl;
			}
			goto MENU1;//closing of user portal

	case 2:

		char moreop;

		MENU2 :
	do{
		system("clear");
		cout<<"\n\n\t\t Welcome to the student panel";
		cout<<"\n\n press 1 to view your profile";
		cout<<"\n press 2 to view your subjects";
		cout<<"\n press 3 to add a subject";
		cout<<"\n press 4 to modify your profile";
		cout<<"\n press 5 to exit";
		int inchoice;
		cout<<"enter your choice";
		cin>>inchoice;
		if(inchoice==1)
		{
			fstream fs;
			fs.open("stinfo.txt",ios::in);
			fs.seekg(0);
			int x;
			while(!fs.eof())
			{
				x=0;
				fs.read((char *)&f,sizeof(user));
				x=f.studprofile();
				if(x==1)
				{
					break;
				}

			}
			fs.close();
			goto MENU2;

		}//end of first int choice
		if(inchoice==2)
		{
			fstream fs;
			fs.open("stinfo.txt",ios::in);
			fs.seekg(0);
			int y;
			while(!fs.eof())
			{
				y=0;
				fs.read((char *)&f,sizeof(user));
				int y=f.get_sub();
				if(y==1)
				{
					break;
				}
			}
			fs.close();
			goto MENU2;
		}
		if(inchoice==3)
		{
			fstream fs;
			fstream fs1;
			fs.open("stinfo.txt",ios::in|ios::binary);
			fs1.open("tempstinfo.txt",ios::out|ios::ate);
			fs.seekg(0);
			while(!fs.eof())
			{
				fs.read((char *)&f,sizeof(user));
				f.addsub();
				fs1.write((char *)&f,sizeof(user));
			}
			fs.close();
			fs1.close();
			remove("stinfo.txt");
			rename("tempstinfo.txt","stinfo.txt");
			goto MENU2;
		}
		if(inchoice==4)
		{
			fstream fs;
			fstream fs1;
			fs.open("stinfo.txt",ios::in|ios::binary);
			fs1.open("tempstinfo.txt",ios::out|ios::ate);
			fs.seekg(0);
			while(fs.eof()!=0)
			{
				fs.read((char *)&f,sizeof(user));
				f.modiyprofile();
				fs1.write((char *)&f,sizeof(user));
			}
			fs.close();
			fs1.close();
			remove("stinfo.txt");
			rename("tempstinfo.txt","stinfo.txt");
			goto MENU2;
		}
		if(inchoice==5)
		{
			goto MAIN_MENU;
		}
		if(inchoice<1||inchoice>5)
			cout<<"invlid input provided"<<endl;
			cout<<"enter to continue"<<endl;
			getchar();
			cout<<"press y otherwise perform more operations"<<endl;
			cin>>moreop;
			if(moreop!='Y'&&moreop!='y')
			{
				system("clear");
				cout<<"thanku!"<<endl;
				getchar();
				goto MAIN_MENU;
			}
        cout<<"Do you want to continue in student portal[Y/N]"<<endl;
		cin>>moreop;

	}while(moreop=='Y'||moreop=='y');
	break;
	default:
        if(ch<1||ch>2)
        {
            cout<<"invalid input"<<endl;
            getchar();
            system("clear");
            cout<<"\n\n\n thank u!"<<endl;
        }
        goto MAIN_MENU;
	}//switch end

	cout<<"Do you want to enter one of the portal[Y/N]\n ";
	cin>>con;
}while(con=='Y' || con=='y');

}//main end
