#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class node {
	
	public:
	int acc_num;
	long long id_num;
	string first_name;
	string last_name;
	string fname;
	long long pass;
	string account_type;
	int curr_bal;
	int req_money;
	string requester;
	node *next;
};

node *head=NULL,*tail=NULL,*current=NULL;

class comp{
	public:
	string line;
	string name;
	comp *nextc; 
};

comp *headc=NULL,*tailc=NULL;

class money {
	
	public:
	string sender_name;
	string receiver_name;
	int amount;
	money *nexts;
};

money *heads=NULL,*tails=NULL;

class edit
{
	public:
	string epname;
	string ename;
	string elastn;
	string eacc_typ;
	long long eid;
	edit *nexte;
 }; 

edit *heade=NULL,*taile=NULL;

class notify {
	string sender;
	int amount;
	notify *nextn;
};

notify *headn=NULL,*tailn=NULL;
char logout;

int acc;
void reg()
{
	
   node* newnode = new node();
   
     cout<<"\nWRITE YOUR FIRST NAME: "<<endl;
     cin>>newnode->first_name;
   
     cout<<"\nWRITE YOUR LAST NAME: "<<endl;
     cin>>newnode->last_name;
      
     cout<<"\nWRITE YOUR CNIC NUMBER: "<<endl;
     cin>>newnode->id_num; 

     cout<<"\nWRITE YOUR FATHER NAME: "<<endl;
     cin>>newnode->fname;
   
     cout<<"\nSAVING ACCOUNT OR CURRENT ACCOUNT "<<endl;
     cin>>newnode->account_type;
  
     cout<<"\nWRITE YOUR PASSWORD: "<<endl;
     cin>>newnode->pass;
     
     acc = acc + 0003426;
     newnode->acc_num = acc;
     newnode->curr_bal= 1000;
     cout<<"\nYOUR ACCOUNT NUMBER IS "<<newnode->acc_num<<endl;
         
   if(head == NULL)
   {
   	head = newnode;
   	tail = newnode;
   	
   }
   else 
   {
   		tail->next = newnode;
		tail = newnode;
		tail->next = NULL;
   
}
}

void edit_acc_details()
{
	bool loop = true;
	long long new_password;
	cout<<"\nYOUR CURRENT PASSWORD: "<<current->pass<<endl;
	while(loop == true)
	{
		cout<<" WRITE YOUR NEW PASSWORD "<<endl;
		cin>>new_password;
		if(current->pass != new_password)
		{
			current->pass = new_password;
			cout<<" YOUR PASSWORD HAS BEEN CHANGED "<<endl;
			break;
		}
		else {
			cout<<"YOUR NEW PASSWORD CANNOT BE EQUAL TO YOUR RECENT PASSWORD"<<endl;
		}
	}
}

void send_money()
   {
  	int moneya;
	string names;
	money* newnode = new money();
	cout<<"WRITE NAME OF A PERSON TO WHOM YOU WANT TO SEND MONEY "<<endl;
    cin>>names;
    node* temp = head;
    while(temp != NULL)
    {
    	if(names == temp->first_name)
    	{
    		cout<<" ACCOUNT FOUND "<<endl;
    		cout<<" \n\nPERSON NAME: "<<temp->first_name<<" "<<temp->last_name<<endl;
    		cout<<"\nWRITE THE AMOUNT YOU WANT TO SEND  "<<endl;
    		cin>>moneya;
    		if(moneya > current->curr_bal)
    		{
    			cout<<"INSUFFICIENT MONEY"<<endl;
    			break;
			}
			else
			{
			
    		current->curr_bal = current->curr_bal - moneya;
    		temp->curr_bal = temp->curr_bal + moneya;
    		cout<<"YOUR CURRENT BALANCE IS "<<current->curr_bal<<endl;
    		newnode->amount = moneya;
    		newnode->receiver_name = temp->first_name;
			newnode->sender_name = current->first_name;
			
			if(heads == NULL)
			{
				heads = newnode;
				tails = newnode;
			}
			else {
				tails->nexts = newnode;
				tails = newnode;
				tails->nexts = NULL;
			}
			 
    		break;
    	}
		}
		     
    	temp = temp->next;
	}
}

void requested()
{
	char c;
	node* newnode = current;
	cout<<current->requester<<" REQUESTED YOU " << current->req_money<<" PKR "<<endl;
	cout<<"\nPRESS Y TO SEND MONEY AND PRESS N TO REJECT THE REQUEST "<<endl;
	cin>>c;
	node* temp = head;
	
	if(c == 'y')
	{
		
	 while(temp != NULL)
    {
    	if(current->requester == temp->first_name)
    	{
    		cout<<" ACCOUNT FOUND "<<endl;
    		cout<<" \n\nPERSON NAME: "<<temp->first_name<<" "<<temp->last_name<<endl;
    		
    		if(current->req_money > current->curr_bal)
    		{
    			cout<<"INSUFFICIENT MONEY"<<endl;
    			break;
			}
			else
			{
			
    		current->curr_bal = current->curr_bal - current->req_money;
    		temp->curr_bal = temp->curr_bal + current->req_money;
    		cout<<"YOUR CURRENT BALANCE IS "<<current->curr_bal<<endl;
    		cout<<"\nTRANSFERED MONEY SUCCESFULLY "<<endl;
    		break;
    	}
		}
		     
    	temp = temp->next;
	}
	
				}
	else {
		cout<<"\nREJECTED REQUEST SUCCESFULLY "<<endl;
	}
}

void req_money()
{
    		int money;
	string names;
	cout<<"WRITE NAME OF A PERSON TO WHOM YOU WANT REQUEST TO SEND MONEY "<<endl;
    cin>>names;
    node* temp = head;
    while(temp != NULL)
    {
    	if(names == temp->first_name)
    	{
    		cout<<" ACCOUNT FOUND "<<endl;
    		cout<<" \n\nPERSON NAME: "<<temp->first_name<<" "<<temp->last_name<<endl;
    		cout<<"\nWRITE THE AMOUNT YOU WANT REQUEST  "<<endl;
    		cin>>money;
    		temp->req_money = money;
    	    temp->requester = current->first_name;
		}
		     
    	temp = temp->next;
}
}

void display()
{
	node* newnode = current;
    cout<<"\nFIRST NAME: "<<newnode->first_name<<" "<<newnode->last_name<<endl;
    cout<<"\nCNIC NUMBER: "<<newnode->id_num<<endl;
    cout<<"\nFATHER NAME: "<<newnode->fname<<endl;
    cout<<"\nACCOUNT TYPE "<<newnode->account_type<<endl;
    cout<<"\nACCOUNT NUMBER "<<newnode->acc_num<<endl;
}

void complaints()
{
	comp* newnode =new comp();
	cout<<"WRITE YOUR COMPLAINTS HERE:"<<endl;
	cin.ignore();
    getline(cin,newnode->line);
	newnode -> name = current -> first_name;
	
	if(headc == NULL)
   {
   	headc = newnode;
   	tailc = newnode;
   }
   else 
   {
   		tailc->nextc = newnode;
		tailc = newnode;
		tailc->nextc = NULL;
   
}
	
}

void scomplaints() {
	
	comp* temp = headc;
	char option;
	while(temp != NULL)
	{
		cout<<"NAME: "<<temp->name<<endl;
		cout<<"COMPLAINT: "<<temp->line<<endl;
		cout<<"\nS = PROBLEM WILL BE SOLVED SOON "<<endl;
		cout<<"\nN = PROBLEM INVALID "<<endl;
		cin>>option;
		if(option == 's')
		{
			cout<<"done"<<endl;
		}
		else if(option == 'n')
		{
			cout<<"done"<<endl;
		}
		
		
		temp = temp->nextc;
	}
}

void money_flow_stats() {

 money* temp = heads;
 
 while(temp != NULL)
 {
 	cout<<"SENDER NAME: "<<temp->sender_name<<endl;
 	cout<<"RECEIVER NAME: "<<temp->receiver_name<<endl;
 	cout<<"AMOUNT: "<<temp->amount<<endl;
 	cout<<"\n"<<endl;
 	
 	temp = temp->nexts;
 }

}

void admin_edit_acc_details()
{
    edit* editptr = new edit();
	string s;
	node* newnode = head;
	
	cout<<"WRITE NAME OF PERSON TO EDIT HIS/HER ACCOUNT DETAILS"<<endl;
	cin>>s;
	cout<<"\n";

    
    
    	 while(newnode != NULL)
    {
    	if(s == newnode->first_name)
    	{
    cout<<"FIRST NAME: "<<newnode->first_name<<" "<<newnode->last_name<<endl;
    cout<<"CNIC NUMBER: "<<newnode->id_num<<endl;
    cout<<"FATHER NAME: "<<newnode->fname<<endl;
    cout<<"ACCOUNT TYPE "<<newnode->account_type<<endl;
    cout<<"ACCOUNT NUMBER "<<newnode->acc_num<<endl;
	cout<<"TOTAL BALANCE "<<newnode->curr_bal<<endl;
	
	cout<<"\nTHE CHANGINGS CAN NOT BE IMPLEMENTED WITHOUT USERS PERMISSION!"<<endl;
	cout<<"\nCHANGE NAME: "<<endl;
    cin>>editptr->ename;
	cout<<"LAST NAME"<<endl;
	cin>>editptr->elastn;
	cout<<"ACCOUNT TYPE"<<endl;
	cin>>editptr->eacc_typ;
	cout<<"CNIC"<<endl;
	cin>>editptr->eid;
	editptr->epname = newnode->first_name;
	
		if(heade == NULL)
   {
   	heade = editptr;
   	taile = editptr;
   	
   }
   else 
   {
   		taile->nexte = editptr;
		taile = editptr;
		taile->nexte = NULL;
   
    }
    cout<<"REQUEST FOR THESE CHANGINGS HAS BEEN SENT TO USER"<<endl;
    break;
			}
		
			     
    	newnode = newnode->next;
	}
}

void withdraw_money()
{
		string s;
		int mon;
	node* newnode = head;
	char c;
	int pass_admin;
	cout<<"SEARCH ACCOUNT WITH NAME TO ADD OR WITHDRAW MONEY "<<endl;
	cin>>s;
		 while(newnode != NULL)
    {
    	if(s == newnode->first_name)
    	{
          cout<<"ACCOUNT FOUND"<<endl;
		  cout<<"FIRST NAME: "<<newnode->first_name<<" "<<newnode->last_name<<endl;   
          cout<<"CURRENT BALANCE "<<newnode->curr_bal<<endl;
          cout<<"\n";
          cout<<"WRITE PASSWORD OF ADMIN AGAIN TO ADD OR WITHRAW MONEY"<<endl;
          cin>>pass_admin;
          if(pass_admin == 35861)    
            {
            	cout<<"WRITE W TO WITHRAW \nWRITE A TO ADD MONEY"<<endl;
            	cin>>c;
                if(c == 'w')
				{
					cout<<"WRITE AMOUNT "<<endl;
					cin>>mon;
					if(mon < newnode->curr_bal)
					{
						newnode->curr_bal = newnode->curr_bal - mon;
						cout<<"MONEY WITHDRAWN SUCCESFULLY"<<endl;
					 } 
					 else{
					 	cout<<"INSUFFICIENT MONEY"<<endl;
					 					 	
					 }
					
					break;
					  }
				else if(c == 'a')
				{
					cout<<"WRITE AMOUNT "<<endl;
					cin>>mon;
					newnode->curr_bal = newnode->curr_bal + mon;
						cout<<"MONEY ADDED"<<endl;
					break;
							}
				else {
					
					
					break;
				}				    	
			  }
			  else {
			  	cout<<"WRONG PASSWORD YOU CAN NOT ADD OR WITHDRAW MONEY "<<endl;
			  	break;
				}  
			}
		
			     
    	newnode = newnode->next;
	}
	
}

void deleteacc() {
	system("CLS");
	char s;
	node* temp = head;
    node* del = new node();
    string delname;
    
    cout<<"ACCOUNT CAN NOT BE DELETED IF ITS ACCOUNT BALANCE > 0"<<endl;
    cout<<"WRITE NAME OF PERSON TO DELETE ACCOUNT"<<endl;
    cin>>delname;
    		
	 while(temp != NULL)
    {
    
    	
    	if(delname == temp->first_name && temp == head)
    	 {
    	 	cout<<"NAME: "<<temp->last_name<<", "<<temp->first_name<<endl;
    	 	cout<<"ACCOUNT NUMBER: "<<temp->acc_num<<endl;
    	 	cout<<"CURRENT BALANCE: "<<temp->curr_bal<<endl;
    	 	cout<<"ACCOUNT TYPE "<<temp->account_type<<endl;
    	 	cout<<"ARE YOU SURE YOU WANT TO DELETE THIS ACCOUNT PRESS Y (YES): "<<endl;
    	 	cin>>s;
    	 	if(temp->curr_bal <= 0 && s == 'y'  )
			 {
			 	 head = temp->next;
    	 	     delete temp;
    	 	     cout<<"ACCOUNT DELETED "<<endl;
    	 	     break;
			 }
			 else {
			 	cout<<"ACCOUNT CAN NOT BE DELETED: "<<endl;
			 	break;
			 }	
		 	 	}
		else if(delname == temp->next->first_name)
		{
				cout<<"NAME: "<<temp->next->last_name<<", "<<temp->next->first_name<<endl;
    	 	cout<<"ACCOUNT NUMBER: "<<temp->next->acc_num<<endl;
    	 	cout<<"CURRENT BALANCE: "<<temp->next->curr_bal<<endl;
    	 	cout<<"ACCOUNT TYPE "<<temp->next->account_type<<endl;
    	 	cout<<"ARE YOU SURE YOU WANT TO DELETE THIS ACCOUNT PRESS Y (YES): "<<endl;
    	 	cin>>s;
    	 	if(temp->next->curr_bal == 0 && s == 'y'  )
			 {
			 	 	del = temp->next;
			        temp->next = temp->next->next;
			       delete del;
			       cout<<"ACCOUNT DELETED "<<endl;
			       break;
			 }
			 else {
			 	cout<<"ACCOUNT CAN NOT BE DELETED: "<<endl;
			 	break;
			 }	
			
		}
			     
    	temp = temp->next;
	}				}
	
	
	void notification()
	{
		
	money* tempm = heads;
    
    while(tempm != NULL)
    {
    	if(tempm->receiver_name == current->first_name)
    	{
    		cout<<tempm->sender_name<<" SENT YOU "<<tempm->amount<<" pkr"<<endl;
		}
	tempm = tempm->nexts;
	}
		cout<<"\n"<<endl;
	}
	
	
	/*	
	    if()
	    {
		cout<<"ADMIN CHANGED YOUR ACCOUNT DETAILS"<<endl;
    	cout<<"FROM "<<newnode->first_name<<" TO "<<tempe->ename<<endl;
		cout<<"FROM "<<newnode->last_name<<" TO "<<tempe->elastn<<endl;
		cout<<"FROM "<<newnode->account_type<<" TO "<<tempe->eacc_typ<<endl;
		cout<<"FROM "<<newnode->id_num<<" TO "<<tempe->eid<<endl;
		
		cout<<"IF YOU AGREE PREE Y"<<endl;
		cout<<"TO UNDO CHANGES PRESS U"<<endl;
		cin>>c;
		if(c == 'y' || c == 'Y')
		{
			
		newnode->first_name = tempe->ename;
	    newnode->last_name  = tempe->elastn;
		newnode->account_type = tempe->eacc_typ;
		newnode->id_num  = tempe->eid;
		
		cout<<"DONE"<<endl;
		break;
		}
		else {
			cout<<"REQUEST DECLINED"<<endl;
			break;
		}*/
//..............................................................................................
void notifications() 
{
 
  
  edit* tempe = heade;
  edit* newnode = new edit();
  char c;
  while(tempe != NULL)
  {
  if(current->first_name == tempe->epname)
  {
  	cout<<"ADMIN CHANGED YOUR ACCOUNT DETAILS"<<endl;
    	cout<<"FROM "<<current->first_name<<" TO "<<tempe->ename<<endl;
		cout<<"FROM "<<current->last_name<<" TO "<<tempe->elastn<<endl;
		cout<<"FROM "<<current->account_type<<" TO "<<tempe->eacc_typ<<endl;
		cout<<"FROM "<<current->id_num<<" TO "<<tempe->eid<<endl;
		
		cout<<"IF YOU AGREE PREE Y"<<endl;
		cout<<"TO UNDO CHANGES PRESS U"<<endl;
		cin>>c;
		if(c == 'y' || c == 'Y')
		{
			
		current->first_name = tempe->ename;
	    current->last_name  = tempe->elastn;
		current->account_type = tempe->eacc_typ;
		current->id_num  = tempe->eid;
		
		cout<<"DONE"<<endl;
		break;
		}
		else {
			cout<<"REQUEST DECLINED"<<endl;
			break;
  }
} 
tempe=tempe->nexte;
}}
//................................................................................................
void displayacc()
{
	string s;
	node* newnode = head;
	
	cout<<"WRITE NAME OF PERSON TO SEE HIS ACCOUNT\nOR WRITE A TO SEE ALL ACCOUNTS"<<endl;
	cin>>s;
	cout<<"\n";
	if(s == "a")
	{
	
	while(newnode != NULL)
	{
		
	cout<<"FIRST NAME: "<<newnode->first_name<<" "<<newnode->last_name<<endl;
    cout<<"CNIC NUMBER: "<<newnode->id_num<<endl;
    cout<<"FATHER NAME: "<<newnode->fname<<endl;
    cout<<"ACCOUNT TYPE "<<newnode->account_type<<endl;
    cout<<"ACCOUNT NUMBER "<<newnode->acc_num<<endl;
	cout<<"TOTAL BALANCE "<<newnode->curr_bal<<endl;
	cout<<"\n"<<endl;  
	  newnode = newnode->next;
	}}
    else 
    {
    	 while(newnode != NULL)
    {
    	if(s == newnode->first_name)
    	{
    cout<<"FIRST NAME: "<<newnode->first_name<<" "<<newnode->last_name<<endl;
    cout<<"CNIC NUMBER: "<<newnode->id_num<<endl;
    cout<<"FATHER NAME: "<<newnode->fname<<endl;
    cout<<"ACCOUNT TYPE "<<newnode->account_type<<endl;
    cout<<"ACCOUNT NUMBER "<<newnode->acc_num<<endl;
	cout<<"TOTAL BALANCE "<<newnode->curr_bal<<endl;
			}
		
			     
    	newnode = newnode->next;
	}}
	
}

void adminhome()
{
	int choose = 0;
	cout<<"you are logged in:"<<endl;
    
    int count = 0;

    char c;
	do{ 
    system("CLS");
     cout<<"HEY! "<<endl;
      cout<<"                              ADMIN HOME PAGE"<<endl;
     
    cout<<"\n1 SHOW COMPLAINTS \n2 SHOW STATS\n3 DELETE ACCOUNT\n4 WITHDRAW OR ADD MONEY\n5 SHOW ACCOUNTS \n6 EDIT ACCOUNT DETAILS\n9 LOGOUT"<<endl;
     cin>>choose;
     cout<<"\n";
     switch (choose)
    {
     
	    case 1:
          scomplaints();
            
            break;
        case 2:
            
            money_flow_stats();
            
            break;
        case 3:
           deleteacc();
            
            break;
        case 4:
            
			withdraw_money();
            break;
		case 5:
            displayacc();
            
            break;	    
        case 6:
		   admin_edit_acc_details();
		break;    
		case 9:
			count =1;
			logout ='l';
		break;
        default:
            cout << "CHOOSE 1, 2, 3, 4, 5 or 6 " << endl;
            
    }
     if(count == 1)
   {
   	break;
   }
   else
    {
			cout << "WRITE B TO GO BACK"<<endl;
             cin >> c; 
}
   
   }while(c == 'b');
}

void adminlogin()
{
	int password;
	string name;
	cout<<"WRITE YOUR NAME: "<<endl;
    cin>>name;
    cout<<"WRITE YOUR PASSWORD: "<<endl;
    cin>>password;
   if(name == "admin" && password == 35861)
   {
   	system("CLS");
   	adminhome();
   }
   else {
   	cout<<"WRONG PASSWORD "<<endl;
   }
   
}

void account()
{
	int choose = 0;
	cout<<"you are logged in:"<<endl;
    int count=0;
    

    char c;
	do{ 
    system("CLS");
     cout<<"HEY! "<<current->last_name<<", "<<current->first_name<<endl;
    cout<<current->acc_num<<endl;
    cout<<current->account_type<<" account"<<endl;
	cout<<"\n\n\n\nYOUR CURRENT BALANCE:"<<endl;   
	cout<<"..........................."<<endl;
	cout<<"       "<<current->curr_bal<<"       "<<endl;    
    
    cout<<"..........................."<<endl;
    
    cout<<"\n1 CHANGE PASSWORD \n2 SEND MONEY\n3 COMPLAINTS\n4 REQUEST MONEY\n5 SHOW ACCOUNT DETAILS\n6 SHOW REQUESTS\n7 ADMIN EDIT REQUEST \n8 NOTIFICATIONS \n9 LOGOUT"<<endl;
     cin>>choose;
     cout<<"\n";
     switch (choose)
    {
     
	    case 1:
           system("CLS");
		    edit_acc_details();
            
            break;
        case 2:
            
            send_money();
            
            break;
        case 3:
            complaints();
            
            break;
        case 4:
            
            req_money();
            break;
		case 5:
            display();
            
            break;	    
        case 6:
		    requested();
		break;    
		case 7:
			
			notifications();
			
			break;
		case 8:
			notification();
			break;
		case 9:
		count = 1;
		logout='l';
			break;
        default:
            cout << "CHOOSE 1, 2, 3, 4, 5 or 6 " << endl;
            
    }
     if(count == 1)
   {
   	break;
   }
   else
    {
			cout << "WRITE B TO GO BACK"<<endl;
    cin >> c; 
}
   }while(c == 'b');
}

login()
{
	int password;
	string name;
	cout<<"WRITE YOUR NAME: "<<endl;
    cin>>name;
    cout<<"WRITE YOUR PASSWORD: "<<endl;
    cin>>password;
    
    node* temp = head;
    while(temp != NULL)
    {
    	if(name == temp->first_name && password == temp->pass)
    	{
    		current = temp;
    		account();
    		
		}
		     
    	temp = temp->next;
	}
}


/*

*/

void choice()
{
    int chose = 0;

    cout << "\n1 LOGIN\n2 REGISTER \n3 ADMIN"<<endl;
    cin >> chose; 

    switch (chose)
    {
        case 1:
            login();
            
            break;
        case 2:
            reg();
            
            break;
        case 3:
            adminlogin();
            
            break;
        default:
            cout << "CHOOSE 1, 2, OR 3" << endl;
            choice();
    }
}



int main()
{	
   char back;
	do{
	
	choice();
	if(logout == 'l')
	{
	back = 'b';	
	}
	else
	{
 	cout << "WRITE B TO GO BACK"<<endl;
    cin >> back;
     }
    system("CLS");
   }while(back == 'b');

   

	return 0;
}
