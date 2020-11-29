#ifndef _FILE_MNG
#define _FILE_MNG 1

#include"class_file.h"


void store(int key)
{
	system("clear");lgp();
	fstream file;
	file.open(fname[key],ios::out|ios::app);
	if(file.fail())
	{
		lgp();pline('=',26);
		cout<<gp<<"can't create/open the file"<<endl;
		pline('=',26);
		return;
	}
	if(key==0)
	{
		student stdnt;
		stdnt.get_data();
		file.write((char*)&stdnt,sizeof(student));
	}
	if(key==1)
	{
		staff stff;
		stff.get_data();
		file.write((char*)&stff,sizeof(staff));
	}
	if(key==2)
	{
		admin admn;
		admn.get_data();
		file.write((char*)&admn,sizeof(admin));
	}

	file.close();
	system("clear");lgp();
	pline();
	cout<<gp<<"data had been saved"<<endl;
	pline();
	cin.get();
}



void show(int key)
{
	fstream file;
	file.open(fname[key],ios::in);
	if(file.fail())
	{
		pline();
		cout<<"can't open the file"<<endl;
		pline();
		return;
	}
	if(key==0)
	{
		student stdnt;
		pline('-',92);
		cout<<gp<<"STUDENTS' DATA"<<endl;
		pline('=',92);
		cout<<gp<<setw(6)<<"ID"<<setw(20)<<"NAME"<<setw(5)<<"AGE"<<setw(15)<<"DEPARTMENT"<<setw(8)<<"YEAR"<<setw(8)<<"ROLL"<<setw(30)<<"ADDRESS"<<endl;
		pline('-',92);
		while(file.read((char*)&stdnt,sizeof(student)))
			stdnt.put_data();
		pline('=',92);	
	}
	if(key==1)
	{
		staff stff;
		pline('-',97);
		cout<<gp<<"STUFFS' DATA"<<endl;
		pline('=',97);
		cout<<gp<<setw(6)<<"ID"<<setw(20)<<"NAME"<<setw(5)<<"AGE"<<setw(15)<<"DEPARTMENT"<<setw(7)<<"DEGREE"<<setw(8)<<"SALARY"<<setw(30)<<"ADDRESS"<<endl;
		pline('-',97);
		while(file.read((char*)&stff,sizeof(staff)))
			stff.put_data();
		pline('=',97);
	}
	if(key==2)
	{
		admin admn;
		pline('-',61);
		cout<<gp<<"ADMINATRATIONS' DATA"<<endl;
		pline('=',61);
		cout<<gp<<setw(6)<<"ID"<<setw(20)<<"NAME"<<setw(5)<<"AGE"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"QUALIFICATION"<<endl;
		pline('-',61);
		while(file.read((char*)&admn,sizeof(admin)))
			admn.put_data();
		pline('=',61);
	}

	file.close();
}


void update(int key)
{
	system("clear");lgp();
	fstream file;
	file.open(fname[key],ios::ate|ios::in|ios::out);
	if(file.fail())
	{
		pline();
		cout<<"can't open the file"<<endl;
		pline();
		sleep(2);
		return;
	}
	int location=0,temp_id;
	cout<<gp<<"Enter id of the record :";
	cin>>temp_id;
	cin.ignore();
	file.seekg(0,ios::beg);
	
	if(key==0)
	{
		student stdnt;
		while(file.read((char*)&stdnt,sizeof(student)))
		{
			if(stdnt.get_id()==temp_id)
			{
				location=file.tellg()/sizeof(student);
				break;
			}
		}
		if(location==0)
		{
			pline('-');
			cout<<gp<<"INVALID ID"<<endl;
			pline('-');
			file.close();
			cin.get();
			return;
		}
		stdnt.get_data();
		file.seekp((location-1)*sizeof(student),ios::beg);
		file.write((char*)&stdnt,sizeof(student));
		file.close();
		pline('=');
		cout<<gp<<"UPDATE DONE"<<endl;
		pline('=');
		cin.get();
	}
	if(key==1)
	{
		staff stff;
		while(file.read((char*)&stff,sizeof(staff)))
		{
			if(stff.get_id()==temp_id)
			{
				location=file.tellg()/sizeof(staff);
				break;
			}
		}
		if(location==0)
		{
			pline('-');
			cout<<gp<<"INVALID ID"<<endl;
			pline('-');
			file.close();
			cin.get();
			return;
		}
		stff.get_data();
		file.seekp((location-1)*sizeof(staff),ios::beg);
		file.write((char*)&stff,sizeof(staff));
		file.close();
		pline('=');
		cout<<gp<<"UPDATE DONE"<<endl;
		pline('=');
		cin.get();
	}
}

void save(student stdnt,int location)
{	
	fstream file;
	file.open(fname[0],ios::in|ios::ate|ios::out);
	if(file.fail())
	{
		lgp();pline('=',26);
		cout<<gp<<"can't access database file"<<endl;
		pline('=',26);
		return;
	}	
	file.seekg(0,ios::beg);
	file.seekp(location*sizeof(student),ios::beg);
	file.write((char*)&stdnt,sizeof(student));
	file.close();
	system("clear");lgp();
	pline('=',27);
	cout<<gp<<"Successfully Updated Record"<<endl;
	pline('=',27);
	cin.get();
}

void save(staff stff,int location)
{	
	fstream file;
	file.open(fname[1],ios::in|ios::ate|ios::out);
	if(file.fail())
	{
		lgp();pline('=',26);
		cout<<gp<<"can't access database file"<<endl;
		pline('=',26);
		return;
	}	
	file.seekg(0,ios::beg);
	file.seekp(location*sizeof(stff),ios::beg);
	file.write((char*)&stff,sizeof(stff));
	file.close();
	system("clear");lgp();
	pline('=',27);
	cout<<gp<<"Successfully updated record"<<endl;
	pline('=',27);
	cin.get();
}
void save(admin admn,int location)
{	
	fstream file;
	file.open(fname[0],ios::in|ios::ate|ios::out);
	if(file.fail())
	{
		lgp();pline('=',26);
		cout<<gp<<"can't access database file"<<endl;
		pline('=',26);
		return;
	}	
	
		file.seekp(location*sizeof(admin),ios::beg);
		file.write((char*)&admn,sizeof(admin));
		file.close();
		system("clear");lgp();
		pline('=',27);
		cout<<gp<<"Successfully Updated Record"<<endl;
		pline('=',27);
		cin.get();
}


void dlt(int key)
{
	system("clear");lgp();
	fstream o_file,t_file;
	int temp_id,flag=0;
	o_file.open(fname[key],ios::in|ios::ate);
	t_file.open("temp_database.dat",ios::out);
	if(o_file.fail()||t_file.fail())
	{	
		lgp();pline('=',26);
		cout<<gp<<"can't access database file"<<endl;
		pline('=',26);
		cin.get();
		return;
	}
	cout<<gp<<"Enter the id to be deleted :";
	cin>>temp_id;
	cin.ignore();
	o_file.seekg(0,ios::beg);
	if(key==0)
	{
		student stdnt;
		while(o_file.read((char*)&stdnt,sizeof(student)))
		{
			if(stdnt.get_id()!=temp_id)
				t_file.write((char*)&stdnt,sizeof(student));
			else
				flag=1;
		}
		o_file.close();
		t_file.close();
		system("clear");lgp();
		if(flag==0)
		{
			pline();
			cout<<gp<<"invalid id"<<endl;
			pline();
			remove("temp_database.dat");
			cin.get();
			return;
		}
		else
		{
			lgp();pline('=',23);
			cout<<gp<<"record has been deleted"<<endl;
			pline('=',23);
			remove(fname[key]);
			rename("temp_database.dat",fname[key]);
			cin.get();
			return;
		}

	}

	if(key==1)
	{
		staff stff;
		while(o_file.read((char*)&stff,sizeof(staff)))
		{
			if(stff.get_id()!=temp_id)
				t_file.write((char*)&stff,sizeof(staff));
			else
				flag=1;
		}
		o_file.close();
		t_file.close();
		system("clear");lgp();
		if(flag==0)
		{
			pline();
			cout<<gp<<"INVALID ID"<<endl;
			pline();
			remove("temp_database.dat");
			cin.get();
			return;
		}
		else
		{
			pline('=',23);
			cout<<gp<<"Record has been deleted"<<endl;
			pline('=',23);
			remove(fname[key]);
			rename("temp_database.dat",fname[key]);
			cin.get();
			return;
		}

	}
	if(key==2)
	{
		admin admn;
		while(o_file.read((char*)&admn,sizeof(admin)))
		{
			if(admn.get_id()!=temp_id)
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
			cin.get();
			return;
		}
		else
		{
			lgp();pline('=',23);
			cout<<gp<<"record has been deleted"<<endl;
			pline('=',23);
			remove(fname[key]);
			rename("temp_database.dat",fname[key]);
			cin.get();
			return;
		}

	}
}

void view_log()
{
	system("clear");lgp();
	fstream lg;
	char action[64];
	lg.open(logfile,ios::in);
	if(lg.fail())
	{
		pline();
		cout<<gp<<"logfile can't open/create"<<endl;
		pline();
	}
	pline();
	cout<<gp<<"****Activity log****"<<endl;
	pline('=',50);
	while(lg.read((char*)&action,sizeof(action)))
	{
		cout<<gp<<action<<endl;
	}
	lg.close();
	cin.get();
}

#endif
