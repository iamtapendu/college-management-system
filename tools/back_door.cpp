#include"admin_portal.h"
#include"staff_portal.h"
#include"student_portal.h"



int main()
{
	int choice=99;
	while(choice)
	{
		system("clear");
		lgp();
		pline('=',30);
		cout<<gp<<"*****Wellcome to backdoor*****"<<endl;
		pline('=',30);
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
				store(2);
				break;
			case 2:
				store(1);
				break;
			case 3:
				store(0);
				break;
			default :
				choice=0;
		}
		
		
		
	}
	
}
