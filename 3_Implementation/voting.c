/**
 * @file voting.c
 * @author Naga Varma Uppalapati (nagavu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "voting.h"
    
int display()
{
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
		fprintf(fp2,"%s %s %d\n",voterid1,name,yob);
		fclose(fp2);
		
		printf("**************\n");

		system("cls");

		printf("Successfully Logged In:\n\n");
		printf("\n\n\nEnter 1 to continue:");
		scanf("%d",&no);
		if(no==1)
			{
				system("cls");
				goto go;
			}


		go :
			system("cls");
			fflush(stdin);
			printf("\n\nWELCOME :  %s\n\n",name);
			printf("1.For voting\n2.Add candidate\n3.List of voters\n4.List of candidates\n5.Live count\n6.Exit\n");
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
			forvoting();
		}
        else if(ch==2)
        {
            addcandidates();
            goto go;
        }
        else if(ch==3)
        {
            listofvoters();
            printf("\n\nEnter 1 to return back to menu:");
            scanf("%d",&no);
            if(no==1)
			goto go;
		}
        else if(ch==4)
        {
            listofcandidates();
            printf("\n\nEnter 1 to return back to menu:");
            scanf("%d",&no);
            if(no==1)
			goto go;
		}
        else if(ch==5)
        {
            livecount();
            printf("\n\nEnter 1 to return back to menu:");
            scanf("%d",&no);
            if(no==1)
			goto go;
		}
        else
		printf("\n\n\t\t\t   *******THANK YOU*******\n");
		exit(0);
}
int forvoting()
{
    system("cls");
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
			printf("\n\n\t\t\t   *******THANK YOU*******\n");
            fclose(fp1);
            fclose(fp3);
			
    }
    int addcandidates()
    {
       system("cls");
        fflush(stdin);
		printf("Enter the name of new Candidate:\n");
        scanf("%s",cand);
		fp1 = fopen("candidates.txt","a");
		fprintf(fp1,"%s\n",cand);
		fclose(fp1);
		printf("Name is registered succesfully\n");
		

    }
    int listofvoters()
    {
        system("cls");

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
		

    }
	int listofcandidates()
    {
        system("cls");

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
		
    }
	int livecount()
    {
        system("cls");
		fflush(stdin);
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
	