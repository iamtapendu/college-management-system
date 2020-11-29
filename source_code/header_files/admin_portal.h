#ifndef _ADMN
#define _ADMN 1

#include"file_mng.h"

void dlt_account(admin admn)
{
	fstream o_file,t_file;
	int flag=0;
	o_file.open(fname[2],ios::in|ios::ate);
	t_file.open("temp_database.dat",ios::out);
	if(o_file.fail()||t_file.fail())
	{	
		lgp();pline('=',26);
		cout<<gp<<"can't access database file"<<endl;
		pline('=',26);
		return;
	}
	o_file.seekg(0,ios::beg);
	while(o_file.read((char*)&admn,sizeof(admin)))
	{
		if(admn.get_id()!=id)
			t_file.write((char*)&admn,sizeof(admin));
		else
			flag=1;
	}
	o_file.close();
	t_file.close();
	system("clear");
	if(flag==0)
	{
		lgp();pline();
		cout<<gp<<"invalid id"<<endl;
		pline();
		remove("temp_database.dat");
		return;
	}
	else
	{
		lgp();pline('=',23);
		cout<<gp<<"Account has been deleted"<<endl;
		pline('=',23);
		remove(fname[2]);
		rename("temp_database.dat",fname[2]);
		return;
	}
}

void student_details()
{
	int ch;
	while(1)
	{
		system("clear");lgp();
		pline();
		cout<<gp<<"***STUDENT DETAILS***"<<endl;
		pline();
		cout<<gp<<"1. ADD RECORD"<<endl;
		cout<<gp<<"2. UPDATE RECORD"<<endl;
		cout<<gp<<"3. DELETE RECORD"<<endl;
		cout<<gp<<"4. SHOW ALL RECORD"<<endl;
		cout<<gp<<"5. back to main menu"<<endl;
		pline();
		cout<<gp<<"Enter your choice :";
		cin>>ch;
		cin.ignore();
		switch(ch)
		{
			case 1:
				store(0);
				break;
			case 2:
				update(0);
				break;
			case 3:
				dlt(0);
				break;
			case 4:
				system("clear");lgp();
				show(0);
				cin.get();
				break;
			case 5:
				return;
			default:
				pline();
				cout<<"WRONG CHOICE"<<endl;
				pline();
		}
	}
}

void staff_details()
{
	int ch;
	while(1)
	{
		system("clear");lgp();
		pline();
		cout<<gp<<"***STAFF DETAILS***"<<endl;
		pline();
		cout<<gp<<"1. ADD RECORD"<<endl;
		cout<<gp<<"2. UPDATE RECORD"<<endl;
		cout<<gp<<"3. DELETE RECORD"<<endl;
		cout<<gp<<"4. SHOW ALL RECORD"<<endl;
		cout<<gp<<"5. back to main menu"<<endl;
		pline();
		cout<<gp<<"Enter your choice :";
		cin>>ch;
		cin.ignore();
		switch(ch)
		{
			case 1:
				store(1);
				break;
			case 2:
				update(1);
				break;
			case 3:
				dlt(1);
				break;
			case 4:
				system("clear");lgp();
				show(1);
				cin.get();
				break;
			case 5:
				return;
			default:
				pline();
				cout<<"WRONG CHOICE"<<endl;
				pline();
		}
	}
}


void admin_portal()
{
	int choice=99,location;
	admin admn;
	fstream file;
	file.open(fname[2],ios::in|ios::ate);
	if(file.fail())
	{
		lgp();pline('=',26);
		cout<<gp<<"can't access database file"<<endl;
		pline('=',26);
		return;
	}
	file.seekg(0,ios::beg);
	while(file.read((char*)&admn,sizeof(admin)))
	{
		if(admn.get_id()==id)
		{
			location=file.tellg()/sizeof(admin)-1;
			break;
		}
	}
	file.close();
	while(choice)
	{
		system("clear");lgp();
		pline('=',24);
		cout<<gp<<"******ADMIN PORTAL******"<<endl;
		pline('=',24);
		cout<<"\t\t\t\t\t\tID :"<<id<<endl<<endl;
		pline();
		cout<<gp<<"1. VIEW PROFILE"<<endl;
		cout<<gp<<"2. UPDATE PROFILE"<<endl;
		cout<<gp<<"3. CHANGE PASSWORD"<<endl;
		cout<<gp<<"4. VIEW STAFFS' DETAILS"<<endl;
		cout<<gp<<"5. VIEW STUDENTS' DETAILS"<<endl;
		cout<<gp<<"6. VIEW ALL ADMINS' DETAILS"<<endl;
		cout<<gp<<"7. VIEW LOG FILE"<<endl;
		cout<<gp<<"8. DELETE YOUR ACCOUNT"<<endl;
		cout<<gp<<"9. LOG OUT"<<endl;
		pline();
		cout<<gp<<"Enter your choice :";
		cin>>choice;
		cin.ignore();
		switch(choice)
		{
			case 1:
				admn.view_profile();
				break;
			case 2:
				admn.update();
				save(admn,location);
				break;
			case 3:
				if(admn.chg_pass())
					save(admn,location);
				break;
			case 4:
				staff_details();
				break;
			case 5:
				student_details();
				break;
			case 6:
				system("clear");lgp();
				cout<<gp<<gp<<"****ALL ADMIN DETAILS****"<<endl<<endl;
				show(2);
				cin.get();
				break;
			case 7:
				//log();
				break;
			case 8:
				dlt_account(admn);
			case 9:
				//log_close
				return;
			default:
				pline();
				cout<<gp<<"WRONG CHOICE"<<endl;
				pline();
		}
		
	}
}

#endif

