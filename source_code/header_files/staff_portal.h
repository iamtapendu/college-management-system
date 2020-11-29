#ifndef _STFF
#define _STFF 1

#include"file_mng.h"

void staff_portal()
{
	int choice=99,location;
	staff stff;
	fstream file;
	file.open(fname[1],ios::in|ios::ate);
	if(file.fail())
	{
		lgp();pline('=',26);
		cout<<gp<<"can't access database file"<<endl;
		pline('=',26);
		return;
	}
	file.seekg(0,ios::beg);
	while(file.read((char*)&stff,sizeof(staff)))
	{
		if(stff.get_id()==id)
		{
			location=file.tellg()/sizeof(staff)-1;
			break;
		}
	}
	file.close();
	while(choice)
	{
		system("clear");lgp();
		pline('=',24);
		cout<<gp<<"******STAFF PORTAL******"<<endl;
		pline('=',24);
		cout<<"\t\t\t\t\t\tID :"<<id<<endl<<endl;
		pline();
		cout<<gp<<"1. VIEW PROFILE"<<endl;
		cout<<gp<<"2. UPDATE PROFILE"<<endl;
		cout<<gp<<"3. CHANGE PASSWORD"<<endl;
		cout<<gp<<"4. VIEW ALL STUDENT"<<endl;
		cout<<gp<<"5. LOG OUT"<<endl;
		pline();
		cout<<gp<<"Enter your choice :";
		cin>>choice;
		cin.ignore();
		switch(choice)
		{
			case 1:
				stff.view_profile();
				sprintf(action,"[ id:%d ]-> view own profile",id);
				lg.write((char*)&action,sizeof(action));
				break;
			case 2:
				stff.update();
				save(stff,location);
				sprintf(action,"[ id:%d ]-> update own profile",id);
				lg.write((char*)&action,sizeof(action));
				break;
			case 3:
				if(stff.chg_pass())
				{
					save(stff,location);
					sprintf(action,"[ id:%d ]-> change profile password",id);
				}
				else
					sprintf(action,"[ id:%d ]-> fail to change profile password",id);
				lg.write((char*)&action,sizeof(action));
				break;
			case 4:
				system("clear");lgp();
				show(0);
				cin.get();
				sprintf(action,"[ id:%d ]-> view all student profile",id);
				lg.write((char*)&action,sizeof(action));
				break;
			case 5:
				sprintf(action,"[ id:%d ]-> logout",id);
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
