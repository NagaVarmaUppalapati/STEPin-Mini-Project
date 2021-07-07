/**
 * @file voting.c
 * @author Naga Varma Uppalapati (https://github.com/NagaVarmaUppalapati/STEPin-Mini-Project.git)
 * @brief 
 * @version 0.1
 * @date 2021-07-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "voting.h"
    
	//Heading
	char heading()
	{
		system("cls");

	printf("\n\t\t\t\t\t\t     ANDHRA PRADESH\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n\n");
	printf("\t\t\t\t\t  WELCOME TO THE ELECTION MANAGEMENT APP\n\n");
	printf("\t\t\t\t\t\t  ************************\n");
	printf("\n\n\n");
	}

int main()
{
	//VARIABLE DECLARATION
	FILE *fp2,*fp1,*fp3;
	int num=0,yob,ch,n=0,res,a[50],i,go,m=1,no,len, j;
	char voterid1[80],name[80],district[20],mandal[20],village[20],cand[20],voterid2[80],voter[80],che[20],c;

	system("cls");
	heading();
	fflush(stdin);
	//USER ENTRY
	printf("\n\n\t\t\t  ENTER VOTER ID:");
    scanf("%s",voterid1);
    //Removing spaces in name
	len=strlen(voterid1);
	for(i=0; i<len; i++)
	{
		if(voterid1[i]==' ')
		{
			for(j=i; j<len; j++)
			{
				voterid1[j]=voterid1[j+1];
			}
		len--;
		}
	}
    printf("\t\t\t  ENTER NAME:");
	scanf("%s",name);
    printf("\t\t\t  ENTER YOB:");
	scanf("%d",&yob);
	printf("\t\t\t  ENTER DISTRICT:");
	scanf("%s",district);
	printf("\t\t\t  ENTER MANDAL:");
	scanf("%s",mandal);
	printf("\t\t\t  ENTER VILLAGE:");
	scanf("%s",village);

	fp2 = fopen("voters.txt","r");
	while(fscanf(fp2,"%s",voterid2)!= EOF)
    {
       if(strcmp(voterid1,voterid2)==0)
        {
            printf("You have already voted.\n");
            exit(0);
        }

    }

		fclose(fp2);
		fp2 = fopen("voters.txt","a");
		fprintf(fp2,"%s %s %d %s %s %s\n",voterid1,name,yob,district,mandal,village);
		fclose(fp2);
		
		printf("**************\n");

		system("cls");

		heading();
		printf("Rule Book:\n\n");
		printf("1.You can vote only once.\n2.Enter names as per registered in Aadhar.\n3.You can add new candidates but those must be from AP state.");
		printf("\n4.People from any district can participate.\n5.Please be fair and impartial in voting.\n");
		printf("\n\n\n\n\n\n\n\nEnter 1 to continue:");
		scanf("%d",&no);
		if(no==1)
			{
				system("cls");
				goto go;
			}


		go :
			system("cls");
			fflush(stdin);
			heading();
			printf("\n\nWELCOME :  %s\n\n",voterid1);
			printf("1.For voting\n2.Add candidate\n3.List of voters\n4.Live count\n5.List of Candidates\n6.Exit\n");
			printf("\n\n\nEnter Response: ");
			scanf("%d",&ch);
			system("cls");
			fp1=fopen("candidates.txt","r");
			for(c=getc(fp1);c!=EOF;c=getc(fp1))//for finding no of candidates
				if(c == '\n')
					n = n + 1;
            fclose(fp1);

		if(ch==1)
		{
			system("cls");
			heading();
			printf("\n LIST OF CONTESTING CANDIDATES:\n\n");
			fp1 = fopen("candidates.txt","r");
			for(i=0;i<n;i++)
			{
				if(fgets(cand,20,fp1)>0)
                {   printf("%d.%s",m,cand);
					m=m+1;
                }
			}
			fclose(fp1);
			m=1;
			fp3 = fopen("number.txt","r");
            
			for(i=0;i<n;i++)
			{
				fscanf(fp3,"%d",&a[i]);
			}
			printf("\n\nEnter Your Response:");
			scanf("%d",&res);
			i = res-1;
			a[i] = a[i] + 1;
			fclose(fp3);

			fp3 = fopen("number.txt","w");
			for(i=0;i<n;i++)
				{
				fprintf(fp3,"%d\n",a[i]);
				}
			fclose(fp3);
			printf("\nYour response has been submitted succesfully\n");

            heading();
            m=1;
            fp3 = fopen("number.txt","r");
            fp1 = fopen("candidates.txt","r");
           printf("\n\nS.no\t\tNo of votes\t\tCandidate\n");
		printf("__________________________________________________\n");
		for(;;)
		{
			if(fgets(cand,20,fp1)>0)
			{
				if(fscanf(fp3,"%d",&num)>0)
				{
					printf("%d.\t\t %d \t\t\t%s",m,num,cand );
					m=m+1;
				}
				else break;
			}
			else break;
		}
            m=1;
            fclose(fp1);
            fclose(fp3);

		}

	else if(ch==2)
	{
		system("cls");
		heading();
        fflush(stdin);
		printf("Enter the name of new Candidate:\n");
        scanf("%s",cand);
		fp1 = fopen("candidates.txt","a");
		fprintf(fp1,"%s\n",cand);
		fclose(fp1);
		printf("Name is registered succesfully\n");
		goto go;

	}

	else if(ch==3)
	{
		system("cls");
		heading();

		fp2=fopen("voters.txt","r");
		m=1;
		for(i=0;i<1000;i++)
		{

			if(fgets(voter,1001,fp2)>0)
			{
				printf("%d.%s",m,voter);
				m=m+1;
			}
		}
		m=1;
		fclose(fp2);
		printf("\n\nEnter 1 to return back to menu:");
		scanf("%d",&no);
		if(no==1)
			goto go;
	}

	else if(ch==4)
	{
		system("cls");
		fflush(stdin);
		heading();
		fp3 = fopen("number.txt","r");
		fp1 = fopen("candidates.txt","r");
		m=1;
		printf("\n\nS.no\t\tNo of votes\t\tCandidate\n");
		printf("__________________________________________________\n");
		for(;;)
		{
			if(fgets(cand,20,fp1)>0)
			{
				if(fscanf(fp3,"%d",&num)>0)
				{
					totalvotes(m,num,cand);
					
					m=m+1;
				}
				else break;
			}
			else break;
		}
		m=1;
		fclose(fp1);
		fclose(fp3);
		printf("\n\nEnter 1 to return back to menu:");
		scanf("%d",&no);
		if(no==1)
			goto go;
	}
	else if(ch==5)
	{
		system("cls");
			heading();

			printf("\n LIST OF CONTESTING CANDIDATES:\n\n");
			fp1 = fopen("candidates.txt","r");
			for(i=0;i<n;i++)
			{
				if(fgets(cand,20,fp1)>0)
                {   printf("%d.%s",m,cand);
					m=m+1;
                }
			}
		m=1;
		printf("\n\nEnter 1 to return back to menu:");
		scanf("%d",&no);
		if(no==1)
			goto go;
	}
	else
        heading();
		printf("\n\n\t\t\t   *******THANK YOU*******\n");
		exit(0);
}
