#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct library{
	int book_id;
	int book_quantity;
	char book_name [100];
	char author_name[100];
}l1;

struct student{
	int s_id;
	char student_name[100];
	char book_name[100];
	char department[100];
	char issue_date[100];
	char return_date[100];	
}s1;

void bookAdd()
{
	  system("cls");
	  
      FILE* ptr;
      ptr = fopen("libraryDB.txt","ab+");
      
      if(ptr == NULL)
      {
      	fprintf(stderr,"Cant open File");
      	exit(1);
	  }
	  
	  printf("\n\n================= Add Book ====================\n");
	  printf("\nEnter Book ID:");
	  scanf("%d",&l1.book_id);
	  fflush(stdin);
	  printf("\nBook Name:");
	  gets(l1.book_name);
	  printf("\nAuthor Name:");
	  gets(l1.author_name);
	  printf("\nBook Quantity:");
	  scanf("%d",&l1.book_quantity);
	  
	  fwrite(&l1,sizeof(library),1,ptr);
	  
	  if(ptr != NULL)
	  {
	  	printf("\n\nBook add successfully\n");
	  }else{
	  	printf("\nBook did not add successfully\n");
	  }
	  system("pause");
	  
	  fclose(ptr);
}

void viewBook(){
    
    system("cls");
    
    FILE* ptr;
    ptr = fopen("libraryDB.txt","rb");
    
    if(ptr == NULL)
    {
    	fprintf(stderr,"Database cant open");
    	exit(1);
	}
	printf("\n\n================== VIEW BOOKS ===============\n");
	while(fread(&l1,sizeof(library),1,ptr))
	{
		printf("---------------------------------------------------------");
		printf("\nBook ID:%d\nBook Name:%s\nAuthor Name:%s\nQuantity:%d\n",l1.book_id,l1.book_name,l1.author_name,l1.book_quantity);
		printf("---------------------------------------------------------\n\n");
	}
	
	fclose(ptr);
	system("pause");
}
void issueBook()
{
     system("cls");
	  
      FILE* ptr;
      ptr = fopen("IssueBookDB.txt","ab+");
      
      if(ptr == NULL)
      {
      	fprintf(stderr,"Cant open File");
      	exit(1);
	  }
	  
	  printf("\n\n================= Issue Book ====================\n");
	  printf("\nEnter student ID:");
	  scanf("%d",&s1.s_id);
	  fflush(stdin);
	  printf("\nStudent Name:");
	  gets(s1.student_name);
	  printf("\nBook Name:");
	  gets(s1.book_name);
	  printf("\nDepartment Name:");
	  gets(s1.department);
	  printf("\nBook Issue Date (i.e. 12-March-2022):");
	  gets(s1.issue_date);
	  printf("\nBook Return Date (i.e. 7-March-2022):");
	  gets(s1.return_date);
	  
	  fwrite(&s1,sizeof(student),1,ptr);
	  
	  if(ptr != NULL)
	  {
	  	printf("\n\nBook issue successfully\n");
	  }else{
	  	printf("\nBook issue not successfully\n");
	  }
	  
	  system("pause");
	  
	  fclose(ptr);
}
void ViewissueBook()
{
     system("cls");
    
    FILE* ptr;
    ptr = fopen("IssueBookDB.txt","rb");
    
    if(ptr == NULL)
    {
    	fprintf(stderr,"Database cant open");
    	exit(1);
	}
	printf("\n\n================== VIEW Issue BOOKS ===============\n");
	while(fread(&s1,sizeof(student),1,ptr))
	{
		printf("---------------------------------------------------------");
		printf("\nStudent ID:%d\nStudent Name:%s\nBook Name:%s\nDepartment Name:%s\nIssue Date:%s\nReturn Date:%s\n",s1.s_id,s1.student_name,s1.book_name,s1.department,s1.issue_date,s1.return_date);
		printf("---------------------------------------------------------\n\n");
	}
	
	fclose(ptr);
	system("pause");
}
void modifyBook()
{
       system("cls");
   
   FILE* ptr,*ptr2;
   int id;
   int flag = 0;
   printf("\n\n=============== Modify Book Portion ===============\n\n");
   printf("Enter Book ID:");
   scanf("%d",&id);
   
   ptr = fopen("libraryDB.txt","rb");
   ptr2 = fopen("copy1.txt","ab");
   
   if(ptr == NULL)
   {
   	fprintf(stderr,"Cant open file");
   	exit(1);
   }
     //below portion will search wether the id exits in our database or not
       while(fread(&l1,sizeof(library),1,ptr)>0 && flag == 0)
   {	
   	if(l1.book_id == id)
   	{
   	  flag == 1;
   	  printf("\nBook Record Found\n");
   	  printf("---------------------------------------------------------");
	  printf("\nBook ID:%d\nBook Name:%s\nAuthor Name:%s\nQuantity:%d\n",l1.book_id,l1.book_name,l1.author_name,l1.book_quantity);
	  printf("---------------------------------------------------------\n\n");
   }
   }
   //if the id doesnot not match in our database it will print the message and exit the whole project
   if(l1.book_id != id)
   {
   	printf("\nBook record not found\n");
   	exit(0);
   }
   
   //here agian the loop will start and put all the data in ptr2 except the id we have given 
   while(fread(&l1,sizeof(library),1,ptr))
   {	
   	if(l1.book_id != id)
   	{
	  fwrite(&l1,sizeof(library),1,ptr2);
   }
   }
    
    // here the record we want to modify, will be given
      printf("\n\nEnter Book ID:");
	  scanf("%d",&l1.book_id);
	  fflush(stdin);
	  printf("\nBook Name:");
	  gets(l1.book_name);
	  printf("\nAuthor Name:");
	  gets(l1.author_name);
	  printf("\nBook Quantity:");
	  scanf("%d",&l1.book_quantity);
	  fwrite(&l1,sizeof(library),1,ptr2);  // and the above data and the loop data fill enter in the same file and thats how the file will be modify
      printf("\ndata modify successfully");
      	system("pasue");
   fclose(ptr);
   fclose(ptr2);
   remove("libraryDB.txt"); // here original file will be deleted
    rename("copy1.txt","libraryDB.txt"); // here the copy file, which contains the modify data will be replace will the name of original file
           
}

void DeleteBook()
{
	FILE* ptr,*ptr2;
	int book_id;
	
	printf("\n========================= Deleting Portion of Book ====================");
	printf("\n\nEnter Book ID");
	scanf("%d",&book_id);
	
	ptr = fopen("libraryDB.txt","rb");
	ptr2 = fopen("copy.txt","ab");
	
	if(ptr == NULL)
	{
		fprintf(stderr,"File cant be opened");
		exit(1);
	}
	
	while(fread(&l1,sizeof(library),1,ptr))
	{
		if(l1.book_id != book_id)
		{
			fwrite(&l1,sizeof(library),1,ptr2);
		}
	}
	if(l1.book_id == book_id)
	{
	printf("\n\ndata deleted succesfully\n");
    }else{
    	printf("\n\ndata not deleted succesfully\n");
	}
  	system("pause");
  	
    fclose(ptr);
    fclose(ptr2);
  
    remove("libraryDB.txt");
    rename("copy.txt","libraryDB.txt");
}

void SearchBook()
{
   system("cls");
   
   FILE* ptr;
   int id;
   int flag = 0;
   printf("\n\n=============== Search Book Portion ===============\n\n");
   printf("Enter Book ID:");
   scanf("%d",&id);
   
   ptr = fopen("libraryDB.txt","rb");
   
   if(ptr == NULL)
   {
   	fprintf(stderr,"Cant open file");
   	exit(1);
   }
   
   while(fread(&l1,sizeof(library),1,ptr)>0 && flag == 0)
   {	
   	if(l1.book_id == id)
   	{
   	  flag == 1;
   	  printf("\nBook Record Found\n");
   	  printf("---------------------------------------------------------");
	  printf("\nBook ID:%d\nBook Name:%s\nAuthor Name:%s\nQuantity:%d\n",l1.book_id,l1.book_name,l1.author_name,l1.book_quantity);
	  printf("---------------------------------------------------------\n\n");
   }
   }
   if(flag == 1)
   {
   	printf("\nBook record not found\n");
   }
   fclose(ptr);
   system("pause");
}

int main(){
   int choice;
   
   do{
   	 printf("================================ DASHBOARD ============================\n");
   	 printf("\n\t1.Add Book\n");
   	 printf("\t2.Issue Book\n");
   	 printf("\t3.View Issue Book\n");
   	 printf("\t4.View Books\n");
   	 printf("\t5.Modify Book\n");
   	 printf("\t6.Delete Book\n");
   	 printf("\t7.Search Book\n");
   	 printf("\t0.Exit\n");
   	 printf("\tEnter Your Choice:");
   	 scanf("%d",&choice);
   	 
    if(choice > 6){
    	printf("\n\n\tWrong Choice");
    	exit(1);
	}
   	 switch(choice) {
   	 	case 1:
   	 		bookAdd();
   	 	    break;	
   	 	case 2:
   	 		issueBook();
			break;
		case 3:
   	 		ViewissueBook();
			break;	
		case 4:
		    viewBook();
			break;
		case 5:
		    modifyBook();
			break;
		case 6:
		    DeleteBook();
			break;
		case 7:
		    SearchBook();
			break;					
	default:
		printf("Wrong choice");
}

   	 system("cls");
   }while(choice !=0);


  return 0;
}

