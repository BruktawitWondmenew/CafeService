#include<iostream>
using namespace std;

//void add_node_at_start ( );
void enqueue ( ) ;
void display_forward() ;
void dequeue();
//void delete_from_end();
void is_empty();
void get_size ();
void peek();
void clear();
void display_backward() ;
void search();
void menu();
int meal_number=1;
struct queue
{
	int name;
	int meal_no;
	int priority=0;
	queue *next;
	queue *prev;
};
queue *start=NULL;
queue *end=NULL;
int main()
{char cont;
	do{
int choice;
int press;
cout<<"TO get customer service press 1"<<endl;
cout<<"TO get manager\\waiter service press 2"<<endl;
cin>>press;
if(press==1)
        {
     	int a;
          cout<<"        WELCOME TO OUR CAFE"<<  endl;
          cout<<"thanks for you are being our customer"<<endl;	
           cout<<"PLEASE press 1 to see the menu and to order the meal "<<endl;
         cin>>a;
             if (a==1)
             { 
                menu();
	               	enqueue ( );
	         }
			 else 
	         cout<<"pls enter the correct no"<<endl;
	         
        }
else if(press==2)
    {
	cout<<"            HELLO OUR MANAGER"<<endl;
	cout<<"here is all the customers information SO you can do any operation that you want"<<endl;
	cout<<"press 1 if the meal is READY SO DELETE from the list"<<endl;
	cout<<"press 2 if you want to SEE all the orders"<<endl;
	cout<<"press 3 if you want to SEE THE LAST customer order"<<endl;
	cout<<"press 4 to DELETE all the customers order if something wrong is happen"<<endl;
	cout<<"press 5 if you want to check the order list IS EMPTY"<<endl;
	cout<<"press 6 if you want to know ALL customer NO"<<endl;
	cout<<"SOOO please press you choice"<<endl;
cin>>choice;

switch(choice)
  { 
	break;
	case 1:
	dequeue ( ) ;
	break;
	case 2:
    display_forward() ;
    	break;
    case 3:
   peek();
    	break;
    case 4:
   clear();
    	break;
    case 5:
   is_empty();
   break;
   case 6:
   	get_size();
   break;
    default:
    cout<<"enter the correct choice"<<endl;
  } 
   }
else
   {
   	cout<<"sorry there is no any operation for you"<<endl;
   }
cout<<"enter y/Y TO CONTINUE"<<endl;
cin>>cont;
}
while(cont=='y'|| cont=='Y');

	return 0;
}
void menu()
{
cout<<"       MENU              "<<endl;
cout<<"1,BEYAYNET          "<<endl;    
cout<<"2,SHIRO          "<<endl; 
cout<<"3,PASTA          "<<endl; 
cout<<"4,FIRFIR          "<<endl;
}
/*
void add_node_at_start ( ) 
{
	  node  *temp1, *temp2;
temp1=new node;
cout<<"enter a number to add at start"<<endl;
cin>>temp1->data;
if(start==NULL)
        {
	        start=temp1;
            temp1->next=NULL;
            temp1->prev=NULL;
        }
        else
        {
        	temp2=start;
        	temp1->next=temp2;
        	temp2->prev=temp1;
        
        	temp1->prev=NULL;
        		start=temp1;
        }
}*/
void enqueue ( ) 
{int n;
cout<<"enter your food choice pls"<<endl;
cin>>n;
	 queue *temp1, *temp2;
temp1=new queue;
cout<<"PLS write your first name"<<endl;
cin>>temp1->name;
if(n==1)
temp1->priority=1;
temp1->meal_no=meal_number;

if(start==NULL)
  {
	       start=temp1;
            temp1->next=NULL;
            temp1->prev=NULL;
  }
else
   {
            temp2=start;
	       while(temp2->next!=NULL)
                temp2=temp2->next;
            temp2->next=temp1;
            temp1->prev=temp2;
            temp1->next=NULL;
        }
meal_number++;
}
void display_forward()
{int c=1;
    queue *temp3=start;
    if(start==NULL)
		cout<<"there is no any order till now"<<endl;
	else
   	 {
		 while(temp3!=NULL)
     	{
			cout<<"our custemors are "<<endl;
			cout<<"    "<<c<<temp3->name<<"  "<<"with meal number  "<<temp3->meal_no<<endl;
         	temp3=temp3->next;
         	c++;
    		  }
}

}
void dequeue()  
{
queue *temp1;
if(start==NULL)
  {
		cout<<"there is no any order"<<endl;
  }
else
 {
            	 temp1=start;
		start=start->next;
		start->prev=NULL;
		delete temp1;
  }
}
void peek()
{ 
    if(start==NULL)
		cout<<"there is no any order"<<endl;
	else
			cout<<"the last order is :"<<start<<endl;
}
void clear()
{
	queue *temp1,*temp2;
if(start==NULL)
  {
		cout<<"there is no any order for now"<<endl;
  }
else
 {
            	 temp2=start;
            	 temp1=start;
            	 while (temp1!=NULL)
            {
			 
             temp1=temp1->next;
             delete temp2;
             start=temp1;
             temp2=temp1;
            }
  }	
	
	
}
void is_empty()
{
	bool is_empty;
 if(start==NULL)
 	is_empty=true;
else
is_empty=false;
cout<<is_empty;	
}/*
void full()
{
	bool full;
	if(end!=NULL)
	  full=true;
 else
     full=false;
     cout<<full;
}
*/
void get_size()
{int count;
    queue *temp3=start;
    if(start==NULL)
		count=0;
	else
   	 {
		 while(temp3!=NULL)
     	{count++;
         	temp3=temp3->next;
    		  }
}
cout<<"there is"<<count<<"orders for now"<<endl;
}


//void priority_queue
/*

void delete_from_end()        
{
	node *temp1;
if(start==NULL)
  {
		cout<<"no node to be delete"<<endl;
  }
else
 {
            	 temp1=start;
		start=start->next;
		start->prev=NULL;
		delete temp1;
  }
}
void display_backward()        
{
    node *temp=start;
    if(start==NULL)
		cout<<"no node to display"<<endl;
	else
   	 {
		 while(temp->next!=NULL)
     	{
		 temp=temp->next;}
		 while(temp!=NULL)
		 {
	    	cout<<"Data stored is "<<temp->data<<" at "<<endl;
         	temp=temp->prev;
    		  }
}

}*/
void search()
{
queue *temp,*temp2;
int meal_num;
cout<<"enter a ticket no to be  searched";
cin>>meal_num;
if(start==NULL)
{
cout<<"there is no any order"<<endl;
}
else
{
	int count=1;
	temp2=start;
while(meal_num!=temp2->meal_no||temp2->next!=NULL)
{
	temp2=temp2->next;
	count++;
}
if (temp2->meal_no==meal_num)
	cout<<"we get it:  at node::"<<count;
else
cout<<"can't get it"<<endl;
}
}

/*
void search()
{
node *temp,*temp2;
int found=0;
	int count=1;
cout<<"enter a data to search";
cin>>temp->data;
if(start==NULL)
{
cout<<"it is empty"<<endl;
}
else
{

	temp2=start;
do
{
	if(temp->data==temp2->data)
	 found =1;
	 else
	temp2=temp2->next;
	count++;
}
while(temp->data!=temp2->data||temp2==NULL);
}
if(found==0)
{
cout<<"can not get it"<<endl;
}
else
{
	cout<<"get it:  at node::"<<count;
}

}
*/

