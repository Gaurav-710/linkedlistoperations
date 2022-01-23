#include<stdio.h>
#include<stdlib.h>
struct node        // node these is user defined data type
{
  int data;              //  data part of node
  struct node* next;     //address part of node 

};

struct node* last=NULL;    // global pointer variable which point the last node linked list 

struct node* createnode()                                            //------->function for creating node
{
  int a;
  struct node *newnode=NULL;
  newnode=(struct node*)malloc(sizeof(struct node));                      //---->memory on heap
 if(newnode==NULL)
   {
     printf("Memory Not Allocated");
     return NULL;

   }
 else
  {
    printf("enter data");  //taking data from user
    scanf("%d",&a);
    newnode->data=a;
    newnode->next=NULL;
  }

 return newnode;
}

void createlinkedlist(struct node** head)     //function for linking node  //**head -->these pointer store the address of first becuase we to cage the value in first 
{
  struct node* tempnode=NULL;
  struct node* travnode=*head; 
  
  tempnode=createnode();
  if(*head==NULL)
   {
     *head=tempnode;                           //here we store the address of first node in first pointer variable
     
   }
  else
   {
     while(travnode->next!=NULL)  		//loop for travsing the limnked list till the lasr node 
          {
               travnode=travnode->next;   
		
	  }
      travnode->next=tempnode; 
      last=tempnode;
   }
}





void displaylinkedlist(struct node* head) 		  //   function for displaying the linked list
{
    
 struct node* travnode=head;
  if(head==NULL)
  {

    printf("your linked list is empty");

  } 
  else
    {                                   		                 // here we copy the value of first poiter variable
     while(travnode!=NULL)                			 // loop for  traversing the linked list for printing the data part of each node 
        {
          printf("%d ",travnode->data);
          travnode=travnode->next;

        }

printf("\n");

    }
}

void Insertatfirst(struct node** temp)     		 //function for insrting node at first 
{
  struct node * tempnode=NULL;
  tempnode=createnode();
  tempnode->next=*temp;
  *temp=tempnode;
  
}



void Insertatlast(struct node** temp)    		 //function for insrting node at last 
{
  struct node * tempnode=NULL;
  tempnode=createnode();
  last->next=tempnode;
}

void Deletelastnode(struct node * temp)  		// These function will delete last node in linked list 
{
  struct node* lastd=NULL;
  if(temp==NULL && last==NULL)
    {

        printf("your linked list is empty");
 
    }
 else
{
   while(temp->next!=last)
    {
      temp=temp->next;

    }
  lastd=temp->next;
  last=temp;
  last->next=NULL;
  free(lastd);
   }    
}
void Deletefirstnode(struct node** head)    		 // These function will delete first node 
{  
    struct node * temp=*head;
    struct node * tempe=NULL;
     if(temp==NULL)
     {
        printf("your  linked list is empty");
    
     }
   else
    {  tempe=*head;
  
       temp=temp->next;
       *head=temp;
       free(tempe);
    }
}


void Deleteparticularnode(struct node* temp,struct node** firstt)
{  struct node* pkk=temp;
   struct node* pk=NULL;
   struct node* pj=NULL;
   int data1;
   printf("enter data part of node to delete that node");
   scanf("%d",&data1);
   if(data1==temp->data)
    {
       Deletefirstnode(firstt);
    }
else if(data1==last->data)
  {
     Deletelastnode(temp);
  }
else if((temp==NULL)
{
   printf("your  linked list is empty");  

}
else
  {
   while(temp!=NULL)
    {
      if(temp->data==data1)
        {
          
          pk=temp;               	   //here we stored the address of node which has to delete  in pk pointer variable 
          pj=temp->next;  		  //here we stored the address of next node in pj pointer variable
           break;
       
         
       }

       temp=temp->next;
    }
    while(pkk->next!=pk) 
      {
        pkk=pkk->next;
      }
   pkk->next=pj;   
   free(pk);    // here we free the memory of pk
  }

}
void main()                                            //main function  handle all the function
{  struct node * first=NULL;
   int choice;


 do{
  printf("1.create linkedlist \n 2.display linkedlist \n 3.Insert node at first position \n 4.Insert node at last position \n 5.Delete first  node \n 6.Delete last node \n   7.Deleteparticularnode \n 8.exit \n  ");  
        
  printf("please enter choice \n");

  scanf("%d",&choice);


  switch(choice)
    {
        case 1:createlinkedlist(&first);
               break;

       
	case 2:displaylinkedlist(first);                               //here parameter first pointer because it store the address of first node
	       break;


        case 3:Insertatfirst(&first);
    	       break;   


        case 4:Insertatlast(&last);
  	       break; 

        
        case 5:Deletefirstnode(&first);
	       break;


        case 6:Deletelastnode(first);
	       break;


	case 7:Deleteparticularnode(first,&first);
               break;


        case 8:exit(0);
	       break;


     	default: printf("kindly enter valid choice");

    }

  }while(choice!=0);


}
