#include"header_files/admin_portal.h"
#include"header_files/staff_portal.h"
#include"header_files/student_portal.h"


int main()
{
	int choice=99;
	
	lg.open(logfile,ios::out|ios::app);
	if(lg.fail())
	{
		pline();
		cout<<gp<<"logfile can't open/create"<<endl;
		pline();
	}
	greet();
	while(choice)
	{
		system("clear");
		lgp();
		pline();
		cout<<gp<<"*****LOGIN PAGE*****"<<endl;
		pline();
		cout<<gp<<"1. Admin"<<endl;
		cout<<gp<<"2. Staff"<<endl;
		cout<<gp<<"3. Student"<<endl;
		cout<<gp<<"Any other key to exit..."<<endl;
		pline('-');
		cout<<gp<<"Enter your choice :";
		cin>>choice;
		cin.ignore();
		switch(choice)
		{
			case 1:
				if(login(2))
				{
					sprintf(action,"[ id:%d ]-> Opens admin portal",id);
					lg.write((char*)&action,sizeof(action));
					admin_portal();
				}
				else
					cin.get();
				break;
			case 2:
				if(login(1))
				{
					sprintf(action,"[ id:%d ]-> Opens staff portal",id);
					lg.write((char*)&action,sizeof(action));
					staff_portal();
				}
				else
					cin.get();
				break;
			case 3:
				if(login(0))
				{
					sprintf(action,"[ id:%d ]-> Opens student portal",id);
					lg.write((char*)&action,sizeof(action));
					student_portal();
				}
				else
					cin.get();
				break;
			default :
				lg.close();
				choice=0;
		}
		
		
		
	}
	
}
