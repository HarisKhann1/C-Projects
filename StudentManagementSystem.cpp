#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct s{	
  int rollNO;
  char name[100];
  char Fname[100];
  float subject1;
  float subject2;
  float subject3;
  char department[50];
}s;

void departmentt(){
	
	int choice;
	
	printf("\n1.Aritifical Intelligence");
	printf("\n2.Computer Science");
	printf("\n3.Cyber Security");
	printf("\n4.Software Engineering");
	printf("\n5.Media Science");
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	switch (choice){
		case 1:
			 strcpy(s.department,"Aritifical Intelligence");
			 break;
		case 2:
			  strcpy(s.department,"Computer Science");
		      break;
		case 3:
			  strcpy(s.department,"Cyber Security");
	          break;
		case 4:
			  strcpy(s.department,"Software Engineering");
		      break;
		case 5:
		      strcpy(s.department,"Media Science");	
			 break;
		default:
		printf("wrong choice\n");
		system("pause");
		exit(1);
			 
	}
	
}
void add(){

   FILE* pf;
    pf = fopen("original.txt", "ab");
    if (pf == NULL) {
        fprintf(stderr,
                "\nError to open the file\n");
        exit(1);
    }
    fflush(stdin);
    printf("\n\nEnter Roll NO. :");
    scanf("%d",&s.rollNO);
    printf("\nEnter Name :");
    scanf("%s",&s.name);
    printf("\nEnter Father Name :");
    scanf("%s",&s.Fname);
    printf("\nMarks of subject 01 :");
    scanf("%f",&s.subject1);
    printf("\nMarks of subject 02 :");
    scanf("%f",&s.subject2);
    printf("\nMarks of subject 03 :");
    scanf("%f",&s.subject3);
    departmentt();
    
    fwrite(&s,sizeof(s),1,pf);
    if (fwrite != 0)
        printf("Contents to file written successfully !\n");
    else
        printf("Error writing file !\n");
    
	   
    int another;
    printf("\n(1).for adding an another record press 1\n(2).For NO press 2\n");
	scanf("%d",&another);
	system("cls"); 
	if(another == 1){
		add();
	}    
    fclose(pf);
}
void view(){
  
   system("cls");
   FILE* pf;
    pf = fopen("original.txt", "rb");
    if (pf == NULL) {
        fprintf(stderr,
                "\nError to open the file\n");
        exit(1);
    }
    //fflush(stdin);
  
    while(fread(&s,sizeof(s),1,pf))
	
    printf("\nRoll NO:%d\t Name:%s\t FaterName:%s\t Department :%s\n|English :%.2f\t| |Arabic :%.2f\t| |ICT :%.2f|\n",s.rollNO,s.name,s.Fname,s.department,s.subject1,s.subject2,s.subject3);
    printf("\n");
    system("pause");
    fclose(pf);

}

void delet(){
	FILE* pf;
	FILE* pf2;
	
  int roll;
  system("cls");
  printf("Enter roll no you wanna delet:");
  scanf("%d",&roll);
  
  pf = fopen("original.txt","rb");
  pf2 = fopen("copy.txt","ab");
  
  if(pf == NULL){
  	fprintf(stderr,"Cant opened");
  	exit(0);
  }
  
  while(fread(&s,sizeof(s),1,pf))
  {
  	if(s.rollNO != roll)
  	{
  	   fwrite(&s,sizeof(s),1,pf2);
  	   
	  }
  }
  printf("\n\ndata deleted succesfully\n");
  	   system("pause");
  fclose(pf);
  fclose(pf2);
  
  remove("original.txt");
  rename("copy.txt","original.txt");
  //system("cls");
  
  
}
void update(){
	
	FILE *pf,*pf2;
	int roll;
	int flag = 0;
	
	printf("\nenter roll");
	scanf("%d",&roll);
	 //struct s s2;
	pf=fopen("original.txt","r+");
	pf2=fopen("copy.txt","a+");
	
	if(pf == NULL)
	{
		fprintf(stderr,"Error opening file");
		exit(1);
	 }
	 
	 
	 while(fread(&s,sizeof(s),1,pf)>0 && flag==0)
	 {
	       if(s.rollNO != roll)
		   {
		     flag = 1;
		     printf("record found");
		   	printf("\nRoll NO:%d\t Name:%s\t FaterName:%s\t Department :%s\n|English :%.2f\t| |Arabic :%.2f\t| |ICT :%.2f|\n",s.rollNO,s.name,s.Fname,s.department,s.subject1,s.subject2,s.subject3);
		   	 fwrite(&s,sizeof(s),1,pf2);
			}	
	} 
	if(flag ==0){
				printf("\nrecord not found");
				exit(0);
			}
		   	
	fflush(stdin);
    printf("\n\nEnter Roll NO. :");
    scanf("%d",&s.rollNO);
    printf("\nEnter Name :");
    scanf("%s",&s.name);
    printf("\nEnter Father Name :");
    scanf("%s",&s.Fname);
    printf("\nMarks of subject 01 :");
    scanf("%f",&s.subject1);
    printf("\nMarks of subject 02 :");
    scanf("%f",&s.subject2);
    printf("\nMarks of subject 03 :");
    scanf("%f",&s.subject3);
    departmentt();

	fwrite(&s,sizeof(s),1,pf2);
	fclose(pf);
	fclose(pf2);
	
	remove("original.txt");
	rename("copy.txt","original.txt");
	system("pause");
	printf("\nsuccessfully");
	
}

void search(){
	
	FILE *pf;
	int roll;
	int flag = 0;
	fflush(stdin);
	printf("\nEnter Roll No:");
	scanf("%d",&roll);
	 //struct s s2;
	pf=fopen("original.txt","rb");

	
	if(pf == NULL)
	{
		fprintf(stderr,"Error opening file");
		exit(1);
	 }
	 
	 
	 while(fread(&s,sizeof(s),1,pf)>0 && flag==0)
	 {
	       if(s.rollNO == roll)
		   {
		     flag = 1;
		     printf("record found");
		   	printf("\nRoll NO:%d\t Name:%s\t FaterName:%s\t Department :%s\n|English :%.2f\t| |Arabic :%.2f\t| |ICT :%.2f|\n",s.rollNO,s.name,s.Fname,s.department,s.subject1,s.subject2,s.subject3);
		   	 
			}	
	} 
	if(flag ==0){
				printf("\nrecord not found");
				
			
			}
	fclose(pf);	
	system("pause");
	
}

void scholarship(){
         
       
	FILE *pf;
	int roll;
	int flag = 0;
	fflush(stdin);
	printf("\nEnter Roll No:");
	scanf("%d",&roll);
	 //struct s s2;
	pf=fopen("original.txt","rb");

	
	if(pf == NULL)
	{
		fprintf(stderr,"Error opening file");
		exit(1);
	 }
	 
	 
	 while(fread(&s,sizeof(s),1,pf)>0 && flag==0)
	 {
	       if(s.rollNO == roll)
		   {
		     flag = 1;
		     printf("record found");
		   	 printf("\nRoll NO:%d\t Name:%s\t FaterName:%s\t Department :%s\n|English :%.2f\t| |Arabic :%.2f\t| |ICT :%.2f|\n",s.rollNO,s.name,s.Fname,s.department,s.subject1,s.subject2,s.subject3);
		   	 float total = s.subject1 + s.subject2 +s.subject3;
             printf("\nTotal numbers are = %.2f\n",total);
			 
			 int scholarshipLeastMarks;
			 printf("\nSet a number least number for scholarship:");
			 scanf("%d",&scholarshipLeastMarks);
			 if(total >= scholarshipLeastMarks){
			 	printf("\nStudent is Eligible for Scholarship\n");
			 }
			 else{
			 	printf("\nStudent is not Eligible for Scholarship\n");
			 } 
			}	
	} 
	if(flag ==0){
				printf("\nrecord not found");
			}
	fclose(pf);	
	system("pause");  
}

int main(){
   int choice;
   
   do{
   	 printf("================================ DASHBOARD ============================\n");
   	 printf("\n\t1.Add student\n");
   	 printf("\t2.View All Students\n");
   	 printf("\t3.Delet Students\n");
   	 printf("\t4.Update Students\n");
   	 printf("\t5.Search Students\n");
   	 printf("\t6.Scholarship\n");
   	 printf("\t0.Exit\n");
   	 printf("\tEnter Your Choice:");
   	 scanf("%d",&choice);
   	 
    if(choice > 6){
    	printf("\n\n\tWrong Choice");
    	exit(1);
	}
   	 switch(choice) {
   	 	case 1:
   	 		add();
   	 	    break;	
   	 	case 2:
   	 		view();
			break;
		case 3:
		    delet();
			break;
		case 4:
		    update();
			break;
		case 5:
		    search();
			break;
		case 6:
		    scholarship();
			break;					
	default:
		printf("Wrong choice");
}

   	 system("cls");
   }while(choice !=0);


  return 0;
}

