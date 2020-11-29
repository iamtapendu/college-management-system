#ifndef _CLG_CLS
#define _CLG_CLS 1

#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<unistd.h>
#include<string.h>

using namespace std;

const char *fname[]={"database/student_database.dat","database/staff_database.dat","database/admin_database.dat"};
const char logfile[]={"database/activity_details.log"};
const int base=10000;
int id;

int set_id(int);
int check_authentication(int,char*,int);

const char gp[]="\t\t"; //for horizontal space

void pline(char style='=', int num=20) //for decorative line
{	cout<<gp;
	for(int i=0;i<num;i++)
		cout<<style;
	cout<<endl;
}

void lgp(int line=10) //for vaertical space
{
	for(int i=0;i<line;i++)
		cout<<endl;
}

void greet() // for greet msg
{
	system("clear");
	lgp();
	pline('=',25);
	cout<<gp<<"WELCOME TO COLLEGE PORTAL"<<endl;
	pline('=',25);
	cin.get();
	system("clear");
}

class info
{
	protected:
		int id;
		int code;
		char name[30];
		int age;
		char address[100];
		char password[100];
	public:
		info(int key){id=0;code=key;}
		int get_id(){return id;}
		char* get_name(){return name;}
		char* get_password(){return password;}
		virtual void put_data()=0;
		virtual void get_data()=0;
		virtual void view_profile()=0;
		virtual void update()=0;
		virtual int chg_pass()=0;
};
class student:public info
{
	char dept[10];
	int year;
	int roll;
	char subject[4][30];
	public:
		student():info(0){}
		void put_data();
		void get_data();
		void view_profile();
		void update();
		int chg_pass();
};

void student::get_data()
{
	char passbuff1[100],passbuff2[100];
	pline();
	cout<<gp<<"Enter your Details"<<endl;
	pline();
	cout<<gp<<"NAME :";
	cin.getline(name,30);
	cout<<gp<<"AGE :";
	cin>>age;
	cout<<gp<<"ADDRESS :";
	cin.ignore();
	cin.getline(address,100);
	cout<<gp<<"DEPARTMENT :";
	cin.getline(dept,10);
	cout<<gp<<"YEAR :";
	cin>>year;
	cout<<gp<<"ROLL NO. :";
	cin>>roll;
	cin.ignore();
	for(int i=0;i<4;i++)
	{
		cout<<gp<<"SUBJECT "<<i+1<<" :";
		cin.getline(subject[i],30);
	}
	while(1)
	{
		cout<<gp<<"PASSWORD :";
		cin>>passbuff1;
		cout<<gp<<"CONFIRM PASSWORD :";
		cin>>passbuff2;
		if(strcmp(passbuff1,passbuff2))
		{	
			pline();
			cout<<gp<<"PASSWORD MISMATCH!!!"<<endl;
			pline();
		}
		else
		{
			strcpy(password,passbuff1);			
			break;
		}
	}
	cin.ignore();
	if(id==0)
		id=set_id(code);
}
void student::put_data()
{
	cout<<gp<<setw(6)<<id<<setw(20)<<name<<setw(5)<<age<<setw(15)<<dept<<setw(8)<<year<<setw(8)<<roll<<setw(30)<<address<<endl;
}

void student::view_profile()
{
	system("clear");lgp();
	pline('=',26);
	cout<<gp<<"*******YOUR PROFILE*******"<<endl;
	pline('=',26);
	cout<<"\n\n\n";
	cout<<gp<<"1. ID NUMBER :"<<id<<endl;
	cout<<gp<<"2. NAME :"<<name<<endl;
	cout<<gp<<"3. AGE :"<<age<<endl;
	cout<<gp<<"4. ADDRESS :"<<address<<endl;
	cout<<gp<<"5. DEPARTMENT :"<<dept<<endl;
	cout<<gp<<"6. YEAR :"<<year<<"\t7. ROLL :"<<roll<<endl;
	cout<<gp<<"8. SUBJECTS :"<<subject[0]<<", "<<subject[1]<<", "<<subject[2]<<", "<<subject[3]<<endl;
	pline('-');
	cin.get();	 
}

void student::update()
{
	int ch;
	while(1)
	{
		system("clear");lgp();
		pline('=',33);
		cout<<gp<<"*******UPDATE YOUR PROFILE*******"<<endl;
		pline('=',33);
		cout<<"\n\n\n";
		cout<<gp<<"1. NAME :"<<name<<endl;
		cout<<gp<<"2. AGE :"<<age<<endl;
		cout<<gp<<"3. ADDRESS :"<<address<<endl;
		cout<<gp<<"4 to SAVE CHANGES"<<endl;
		pline('-');
		cout<<gp<<"Enter Your Choice For Update :";
		cin>>ch;
		cin.ignore();
		switch(ch)
		{
			case 1:
				cout<<gp<<"NAME :";
				cin.getline(name,30);
				break;
			case 2:
				cout<<gp<<"AGE :";
				cin>>age;
				cin.ignore();
				break;
			case 3:
				cout<<gp<<"ADDRESS :";
				cin.getline(address,100);
				break;
			case 4:
				cout<<gp<<"SAVING..."<<endl;
				return;
			default:
				pline();
				cout<<gp<<"WRONG OPTION"<<endl;
				pline();
				cin.get();
				break;
		}
	}
}

int student::chg_pass()
{
	system("clear");lgp();
	char passbuff1[100],passbuff2[100];
	cout<<gp<<"Enter old Pass :";
	cin>>passbuff1;
	cin.ignore();
	if(!check_authentication(id,passbuff1,0))
	{
		cin.get();
		return 0;
	}
	cout<<gp<<"PASSWORD :";
	cin>>passbuff1;
	cout<<gp<<"CONFIRM PASSWORD :";
	cin>>passbuff2;
	cin.ignore();
	if(strcmp(passbuff1,passbuff2))
	{	
		pline();
		cout<<gp<<"PASSWORD MISMATCH!!!"<<endl;
		pline();
		cin.get();
		return 0;
	}
	else
		strcpy(password,passbuff1);			
	return 1;
}

class staff:public info
{	
	char qualfctn[10];
	char dept[10];
	int salary;
	public:
		staff():info(1){}
		void get_data();
		void put_data();
		void view_profile();
		void update();
		int chg_pass();
};

void staff::get_data()
{
	char passbuff1[100],passbuff2[100];
	pline();	
	cout<<gp<<"Enter your Details"<<endl;
	pline();
	cout<<gp<<"NAME :";
	cin.getline(name,30);
	cout<<gp<<"AGE :";
	cin>>age;
	cout<<gp<<"ADDRESS :";
	cin.ignore();
	cin.getline(address,100);
	cout<<gp<<"DEPARTMENT :";
	cin.getline(dept,10);
	cout<<gp<<"QUALIFIACTION :";
	cin.getline(qualfctn,10);
	cout<<gp<<"SALARY :";
	cin>>salary;
	while(1)
	{
		cout<<gp<<"PASSWORD :";
		cin>>passbuff1;
		cout<<gp<<"CONFIRM PASSWORD :";
		cin>>passbuff2;
		if(strcmp(passbuff1,passbuff2))
		{	
			pline();
			cout<<gp<<"PASSWORD MISMATCH!!!"<<endl;
			pline();
		}
		else
		{
			strcpy(password,passbuff1);			
			break;
		}
	}
	cin.ignore();
	if(id==0)
		id=set_id(code);
}
void staff::put_data()
{
	cout<<gp<<setw(6)<<id<<setw(20)<<name<<setw(5)<<age<<setw(15)<<dept<<setw(7)<<qualfctn<<setw(8)<<salary<<setw(30)<<address<<endl;
}

void staff::view_profile()
{
	system("clear");lgp();
	pline('=',26);
	cout<<gp<<gp<<"*******YOUR PROFILE*******"<<endl;
	pline('=',26);
	cout<<"\n\n\n";
	cout<<gp<<"1. ID NUMBER :"<<id<<endl;
	cout<<gp<<"2. NAME :"<<name<<endl;
	cout<<gp<<"3. AGE :"<<age<<endl;
	cout<<gp<<"4. ADDRESS :"<<address<<endl;
	cout<<gp<<"5. DEPARTMENT :"<<dept<<endl;
	cout<<gp<<"6. QUALIFICATION :"<<qualfctn<<"\t7. SALARY :"<<salary<<endl;
	pline('-');
	cin.get();	 
}

void staff::update()
{
	int ch;
	while(1)
	{
		system("clear");lgp();
		pline('=',33);
		cout<<gp<<"*******UPDATE YOUR PROFILE*******"<<endl;
		pline('=',33);
		cout<<"\n\n\n";
		cout<<gp<<"1. NAME :"<<name<<endl;
		cout<<gp<<"2. AGE :"<<age<<endl;
		cout<<gp<<"3. ADDRESS :"<<address<<endl;
		cout<<gp<<"4. QUALIFICATION :"<<qualfctn<<endl;
		cout<<gp<<"5 to SAVE CHANGES"<<endl;
		pline('-');
		cout<<gp<<"Enter Your Choice For Update :";
		cin>>ch;
		cin.ignore();
		switch(ch)
		{
			case 1:
				cout<<gp<<"NAME :";
				cin.getline(name,30);
				break;
			case 2:
				cout<<gp<<"AGE :";
				cin>>age;
				cin.ignore();
				break;
			case 3:
				cout<<gp<<"ADDRESS :";
				cin.getline(address,100);
				break;
			case 4:
				cout<<gp<<"QALIFICATIONS :";
				cin>>qualfctn;
				break;
			case 5:
				pline();
				cout<<gp<<"SAVING..."<<endl;
				pline();
				sleep(2);
				return;
			default:
				pline();
				cout<<gp<<"WRONG OPTION"<<endl;
				pline();
				cin.get();
				break;
		}
	}
}

int staff::chg_pass()
{
	system("clear");lgp();
	char passbuff1[100],passbuff2[100];
	cout<<gp<<"Enter old Pass :";
	cin>>passbuff1;
	cin.ignore();
	if(!check_authentication(id,passbuff1,1))
	{
		cin.get();
		return 0;
	}
	cout<<gp<<"PASSWORD :";
	cin>>passbuff1;
	cout<<gp<<"CONFIRM PASSWORD :";
	cin>>passbuff2;
	cin.ignore();
	if(strcmp(passbuff1,passbuff2))
	{	
		pline();
		cout<<gp<<"PASSWORD MISMATCH!!!"<<endl;
		pline();
		cin.get();
		return 0;
	}
	else
		strcpy(password,passbuff1);			
	return 1;
}


class admin:public info
{	
	char qualfctn[10];
	char dept[10];
	int salary;
	public:
		admin():info(2){}
		void get_data();
		void put_data();
		void view_profile();
		void update();
		int chg_pass();
};

void admin::get_data()
{
	char passbuff1[100],passbuff2[100];
	pline();	
	cout<<gp<<"Enter your Details"<<endl;
	pline();
	cout<<gp<<"NAME :";
	cin.getline(name,30);
	cout<<gp<<"AGE :";
	cin>>age;
	cout<<gp<<"ADDRESS :";
	cin.ignore();
	cin.getline(address,100);
	cout<<gp<<"DEPARTMENT :";
	cin.getline(dept,10);
	cout<<gp<<"QUALIFIACTION :";
	cin.getline(qualfctn,10);
	cout<<gp<<"SALARY :";
	cin>>salary;
	while(1)
	{
		cout<<gp<<"PASSWORD :";
		cin>>passbuff1;
		cout<<gp<<"CONFIRM PASSWORD :";
		cin>>passbuff2;
		if(strcmp(passbuff1,passbuff2))
		{	
			pline();
			cout<<gp<<"PASSWORD MISMATCH!!!"<<endl;
			pline();
		}
		else
		{
			strcpy(password,passbuff1);			
			break;
		}
	}
	cin.ignore();
	if(id==0)
		id=set_id(code);
}
void admin::put_data()
{
	cout<<gp<<setw(6)<<id<<setw(20)<<name<<setw(5)<<age<<setw(15)<<dept<<setw(15)<<qualfctn<<endl;
}

void admin::view_profile()
{
	system("clear");lgp();
	pline('=',26);
	cout<<gp<<"*******YOUR PROFILE*******"<<endl;
	pline('=',26);
	cout<<"\n\n\n";
	cout<<gp<<"1. ID NUMBER :"<<id<<endl;
	cout<<gp<<"2. NAME :"<<name<<endl;
	cout<<gp<<"3. AGE :"<<age<<endl;
	cout<<gp<<"4. ADDRESS :"<<address<<endl;
	cout<<gp<<"5. DEPARTMENT :"<<dept<<endl;
	cout<<gp<<"6. QUALIFICATION :"<<qualfctn<<"\t7. SALARY :"<<salary<<endl;
	pline('-');
	cin.get();	 
}

void admin::update()
{
	int ch;
	while(1)
	{
		system("clear");lgp();
		pline('=',33);
		cout<<gp<<"*******UPDATE YOUR PROFILE*******"<<endl;
		pline('=',33);
		cout<<"\n\n\n";
		cout<<gp<<"1. NAME :"<<name<<endl;
		cout<<gp<<"2. AGE :"<<age<<endl;
		cout<<gp<<"3. ADDRESS :"<<address<<endl;
		cout<<gp<<"4. DEPARTMENT :"<<dept<<endl;
		cout<<gp<<"5. QUALIFICATION :"<<qualfctn<<endl;
		cout<<gp<<"6 to SAVE CHANGES"<<endl;
		pline('-');
		cout<<gp<<"Enter Your Choice For Update :";
		cin>>ch;
		cin.ignore();
		switch(ch)
		{
			case 1:
				cout<<gp<<"NAME :";
				cin.getline(name,30);
				break;
			case 2:
				cout<<gp<<"AGE :";
				cin>>age;
				cin.ignore();
				break;
			case 3:
				cout<<gp<<"ADDRESS :";
				cin.getline(address,100);
				break;
			case 4:
				cout<<gp<<"DEPARTMENT :";
				cin.getline(dept,10);
				break;
			case 5:
				cout<<gp<<"QALIFICATIONS :";
				cin>>qualfctn;
				cin.ignore();
				break;
			case 6:
				pline();
				cout<<gp<<"SAVING..."<<endl;
				sleep(2);
				pline();
				return;
			default:
				pline();
				cout<<gp<<"WRONG OPTION"<<endl;
				pline();
				cin.get();
				break;
		}
	}
}

int admin::chg_pass()
{
	system("clear");lgp();
	char passbuff1[100],passbuff2[100];
	cout<<gp<<"Enter old Pass :";
	cin>>passbuff1;
	cin.ignore();
	if(!check_authentication(id,passbuff1,2))
	{
		cin.get();
		return 0;
	}
	cout<<gp<<"PASSWORD :";
	cin>>passbuff1;
	cout<<gp<<"CONFIRM PASSWORD :";
	cin>>passbuff2;
	cin.ignore();
	if(strcmp(passbuff1,passbuff2))
	{	
		pline();
		cout<<gp<<"PASSWORD MISMATCH!!!"<<endl;
		pline();
		cin.get();
		return 0;
	}
	else
		strcpy(password,passbuff1);			
	return 1;
}



int set_id(int key)
{	
	fstream file;
	int tmp_id;
	file.open(fname[key],ios::in|ios::ate);
	if(file.fail())
	{	pline();
		cout<<gp<<"can't open file"<<endl;
		pline();
		sleep(3);
		system("clear");
		exit(1);
	}
	if(key==0)
	{	
		student stdnt;
		file.seekg(-sizeof(student),ios::end);
		file.read((char*)&stdnt,sizeof(student));
		tmp_id=stdnt.get_id();

	}
	if(key==1)
	{	
		staff stff;
		file.seekg(-sizeof(staff),ios::end);
		file.read((char*)&stff,sizeof(staff));
		tmp_id=stff.get_id();
	}
	if(key==2)
	{	
		admin admn;
		file.seekg(-sizeof(admin),ios::end);
		file.read((char*)&admn,sizeof(admin));
		tmp_id=admn.get_id();
	}
	
	file.close();
	if(tmp_id==0)
		return base;
	else
		return tmp_id+1;
}

int check_authentication(int id,char pass[100],int key)
{
	fstream file;
	
	file.open(fname[key],ios::in);
	if(file.bad())
	{
		pline();
		cout<<gp<<"can't open the file"<<endl;
		pline();
		return 0;
	}
	if(key==0)
	{
		student stdnt;
		while(file.read((char*)&stdnt,sizeof(student)))
			if(id==stdnt.get_id())
				if(!strcmp(pass,stdnt.get_password()))
				{
					file.close();
					return 1;
				}
	}
	if(key==1)
	{
		staff stff;
		while(file.read((char*)&stff,sizeof(staff)))
			if(id==stff.get_id())
				if(!strcmp(pass,stff.get_password()))
				{
					file.close();
					return 1;
				}
	}
	if(key==2)
	{
		admin admn;
		while(file.read((char*)&admn,sizeof(admin)))
			if(id==admn.get_id())
				if(!strcmp(pass,admn.get_password()))
				{
					file.close();
					return 1;
				}
	}
	pline();
	cout<<gp<<"INVALID ID/PASSWORD"<<endl;
	pline();
	file.close();
	return 0;
}


int login(int key)
{	
	system("clear");lgp();
	int attempt=3;
	char pass[100];
	pline();
	while(attempt)
	{		
		cout<<gp<<"Enter ID :";
		cin>>id;
		cout<<gp<<"Enter Password :";
		cin>>pass;
		cin.ignore();
		if(check_authentication(id,pass,key))
		{		
			return 1;
		}
		else
		{	attempt--;
			pline();
			if(attempt!=0)
				cout<<gp<<"You only "<<attempt<<" attempt(s) left"<<endl;
			else
				cout<<gp<<"Try again letter :( :("<<endl;
			pline();
		}
	}
	return 0;
}




#endif
