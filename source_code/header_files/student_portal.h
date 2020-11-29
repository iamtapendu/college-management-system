#ifndef _STDNT
#define _STDNT 1

#include"file_mng.h"

void student_portal()
{
	int choice=99,location;
	student stdnt;
	fstream file;
	file.open(fname[0],ios::in|ios::ate);
	if(file.fail())
	{
		lgp();pline('=',26);
		cout<<gp<<"can't access database file"<<endl;
		pline('=',26);
		return;
	}
	file.seekg(0,ios::beg);
	while(file.read((char*)&stdnt,sizeof(student)))
	{
		if(stdnt.get_id()==id)
		{
			location=file.tellg()/sizeof(student)-1;
			break;
		}
	}
	file.close();
	while(choice)
	{
		system("clear");lgp();
		pline('=',26);
		cout<<gp<<"******STUDENT PORTAL******"<<endl;
		pline('=',26);
		cout<<"\t\t\t\t\t\tID :"<<id<<endl<<endl;
		pline();
		cout<<gp<<"1. VIEW PROFILE"<<endl;
		cout<<gp<<"2. UPDATE PROFILE"<<endl;
		cout<<gp<<"3. CHANGE PASSWORD"<<endl;
		cout<<gp<<"4. LOG OUT"<<endl;
		pline();
		cout<<gp<<"Enter your choice :";
		cin>>choice;
		cin.ignore();
		switch(choice)
		{
			case 1:
				stdnt.view_profile();
				sprintf(action,"[ id:%d ]-> view own profile",id);
				lg.write((char*)&action,sizeof(action));
				break;
			case 2:
				stdnt.update();
				save(stdnt,location);
				sprintf(action,"[ id:%d ]-> updated own profile",id);
				lg.write((char*)&action,sizeof(action));
				break;
			case 3:
				if(stdnt.chg_pass())
				{
					save(stdnt,location);
					sprintf(action,"[ id:%d ]-> change profile password",id);
				}
				else
					sprintf(action,"[ id:%d ]-> fail to change profile password",id);
				lg.write((char*)&action,sizeof(action));
				break;
			case 4:
				sprintf(action,"[ id:%d ]-> fail to change profile password",id);
				lg.write((char*)&action,sizeof(action));
				lg.close();
				return;
			default:
				pline();
				cout<<gp<<"WRONG CHOICE"<<endl;
				pline();
		}
		
	}
}

#endif 
