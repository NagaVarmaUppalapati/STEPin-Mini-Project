#include "stdio.h"
#include "stdlib.h"
#include "string.h"                                                      
#include "time.h"
#include "header.h"
#include "conio.h"

char catagories[][15]={"Movies","Series","Musics","Animated","Adults"};

FILE *fp,*ft,*fs;
int s;
char finddvd;
char password[10]={"pass"};

struct meroDate
{

int mm,dd,yy;

};

struct dvd
{

int id;

char stname[20];

char name[20];

char available[20];

int qty;

int price;

int count;

char *cat;

struct meroDate issued;

struct meroDate duedate;

};
struct dvd a;


int main()

{
system("COLOR 06");
Password();

getch();

}

void mainmenu()

{

system("cls");

int i;


printf("\t\t\t\tWELCOME\n\t\t\t\t  To \n\t\t   \xB2\xB2\xB2\xB2\xB2\xB2 DVD Store Management System \xB2\xB2\xB2\xB2\xB2\xB2\n");


printf("[1] Add DVD Record\n");


printf("[2] Delete DVD Record\n");


printf("[3] Search DVD Record\n");


printf("[4] View DVD list\n");


printf("[5] Edit DVD Record\n");


printf("[6] Close The Application\n");


t();


printf("Enter your choice:");



switch(getch())

{

case '1':

adddvd();

break;

case '2':

deletedvd();

break;

case '3':

searchdvd();

break;

case '4':

viewdvd();

break;

case '5':

editdvd();

break;

case '6':

{

system("cls");


printf("\tDVD Store Management System\n");

printf("\tProject in C\n");

printf("\tis brought to you by\n");

printf("\tBUG BUSTERS\n");

printf("\tTHANK YOU");


exit(0);

}

default:

{


printf("\aWrong Entry!!Please re-entered correct option");

if(getch())

mainmenu();

}



}

}

void adddvd(void)    

{

system("cls");

int i;


printf("CHOOSE YOUR CATEGORIES\n");


printf("[1] Movies\n");


printf("[2] Series\n");


printf("[3] Musics\n");


printf("[4] Animated\n");


printf("[5] Adults\n");


printf("[7] Back to main menu\n");





printf("Enter your choice:");

scanf("%d",&s);

if(s==7)

mainmenu() ;

system("cls");

fp=fopen("data.txt","ab+");

if(getdata()==1)

{

a.cat=catagories[s-1];

fseek(fp,0,SEEK_END);

fwrite(&a,sizeof(a),1,fp);

fclose(fp);


printf("The record is sucessfully saved\n");


printf("Save any more?(Y / N):");

if(getch()=='n')

mainmenu();

else

system("cls");

adddvd();

}

}

void deletedvd()    

{

system("cls");

int d;

char another='y';

while(another=='y')  

{

system("cls");


printf("Enter the DVD ID to  delete:");

scanf("%d",&d);

fp=fopen("data.txt","rb+");

rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id==d)

{

printf("\nThe DVD record is available");

printf("\nDVD name is %s",a.name);


finddvd='t';

}

}

if(finddvd!='t')

{

printf("\nNo record is found modify the search");

if(getch())

mainmenu();

}

if(finddvd=='t' )

{


printf("\nDo you want to delete it?(Y/N):");

if(getch()=='y')

{

ft=fopen("test.txt","wb+");  

rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id!=d)

{

fseek(ft,0,SEEK_CUR);

fwrite(&a,sizeof(a),1,ft); 

}                              

}

fclose(ft);

fclose(fp);

remove("data.txt");

rename("test.txt","data.txt"); 

fp=fopen("data.txt","rb+");    

if(finddvd=='t')

{


printf("\nThe record is sucessfully deleted");

printf("\n\tDelete another record?(Y/N)");

}

}

else

mainmenu();

fflush(stdin);

another=getch();

}

}


mainmenu();

}

void searchdvd()

{

system("cls");

int d;

printf("\t\t\t\t*********************Search DVD*********************\n");



printf("1. Search By ID\n");


printf("2. Search By Name\n");


printf("Enter Your Choice:");

fp=fopen("data.txt","rb+"); 

rewind(fp);   

switch(getch())

{

case '1':

{

system("cls");



printf("\t\t\t\t******************Search DVD By Id*******************\n");


printf("Enter the DVD id:");

scanf("%d",&d);


while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id==d)

{


printf("\nThe DVD is available\n");


printf("ID:%d\n",a.id);


printf("Name:%s\n",a.name);


printf("Availability:%s\n",a.available);


printf("Quantity:%i\n",a.qty);


printf("Price:%i\n",a.price);


finddvd='t';

}



}

if(finddvd!='t')  

{

printf("\aNo Record Found\n");

}


printf("Try another search?(Y/N)");

if(getch()=='y')

searchdvd();

else

mainmenu();

break;

}

case '2':

{

char s[15];

system("cls");


printf("\t\t\t\t*****************Search DVD By Name*****************\n");


printf("Enter DVD Name:");

scanf("%s",s);

int d=0;

while(fread(&a,sizeof(a),1,fp)==1)

{

if(strcmp(a.name,(s))==0) 

{

    printf("\nThe DVD is available\n");


	printf("ID:%d\n",a.id);


	printf("Name:%s\n",a.name);


	printf("Availability:%s\n",a.available);


    printf("Quantity:%i\n",a.qty);

	
	printf("Price:%i\n",a.price);


	d+=6;

}



}

if(d==0)

{

printf("\aNo Record Found\n");

}

printf("Try another search?(Y/N)");

if(getch()=='y')

	searchdvd();

else

	mainmenu();

break;

}

default :

getch();

searchdvd();

}

fclose(fp);

}



void viewdvd(void)  

{

int i=0,j;

system("cls");


printf("******************************** DVD STORE **********************************\n");



printf("\tID      DVD NAME    AVAILABILITY    QUANTITY   PRICE\n");


j=4;

fp=fopen("data.txt","rb");

while(fread(&a,sizeof(a),1,fp)==1)

{


printf("\t%d",a.id);


printf("\t%s",a.name);


printf("\t\t%s",a.available);


printf("\t\t%i",a.qty);



printf("\t%i",a.price);



printf("\n\n");

j++;

}

fclose(fp);


returnfunc();

}

void editdvd(void)  

{

system("cls");

int c=0;

int d,e;


printf("Edit DVD Section\n");

char another='y';

while(another=='y')

{

system("cls");


printf("Enter DVD Id to be edited:");

scanf("%d",&d);

fp=fopen("data.txt","rb+");

while(fread(&a,sizeof(a),1,fp)==1)

{

if(checkid(d)==0)

{



printf("\nThe DVD is availble\n");



printf("The DVD ID:%d\n",a.id);


printf("Enter new Name:");

scanf("%s",a.name);



printf("\nEnter new Availability Status:");

scanf("%s",a.available);



printf("\nEnter new Quantity:");

scanf("%i",&a.qty);



printf("\nEnter new Price:");

scanf("%i",&a.price);



printf("\nThe record is modified\n");

fseek(fp,ftell(fp)-sizeof(a),0);

fwrite(&a,sizeof(a),1,fp);

fclose(fp);

c=1;

}

if(c==0)

{


printf("No record found\n");

}

}


printf("Modify another Record?(Y/N)");

fflush(stdin);

another=getch() ;

}

returnfunc();

}

void returnfunc(void)

{

{

printf("\nPress ENTER to return to main menu");

}

a:

if(getch()==13) 

mainmenu();

else

goto a;

}

int getdata()

{

int t;



printf("Enter the Information Below\n");

printf("Category:");

printf("%s",catagories[s-1]);

printf("\nDVD ID:\t");

scanf("%d",&t);

if(checkid(t) == 0)

{

printf("\aThe id already exists\a");

getch();

mainmenu();

return 0;

}

a.id=t;

printf("\nDVD Name:\n");


scanf("%s",a.name);


printf("\nAvailability:\n");


scanf("%s",a.available);


printf("\nQuantity:\n");


scanf("%i",&a.qty);


printf("\nPrice:\n");

scanf("%i",&a.price);

return 1;

}

int checkid(int t)  

{

rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

if(a.id==t)

return 0;  

return 1; 

}

int t(void) 

{

time_t t;

time(&t);

printf("Date and time:%s\n",ctime(&t));

return 0 ;

}


void Password(void) 

{



system("cls");

char d[25]="Password Protected";

char ch,pass[10];

int i=0,j;





	printf("\t\t\t\tWELCOME\n\t\t\t\t  To \n\t\t   \xB2\xB2\xB2\xB2\xB2\xB2 DVD Store Management System \xB2\xB2\xB2\xB2\xB2\xB2\n");

	printf("\t \n\n\n Enter Password:");

	

while(ch!=13)

{

ch=getch();



if(ch!=13 && ch!=8){

putch('*');

pass[i] = ch;

i++;

}

}

pass[i] = '\0';

if(strcmp(pass,password)==0)

{

printf("\n\n\n\t\tPassword matched!!");

printf("\n\n\tPress any key to proceed.....");

getch();

mainmenu();

}

else

{

printf("\n\n\n\t\t\aWarning!! \n\t   Incorrect Password");

getch();

Password();

}

}




