/**
 * @file voting.h
 * @author Naga Varma Uppalapati (nagavu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __VOTING_H__
#define __VOTING_H__
//VARIABLE DECLARATION
static FILE *fp2,*fp1,*fp3;
static int num=0,yob,ch,n=0,res,a[50],i,go,m=1,no,len,j;
static char voterid1[80],name[80],cand[20],voterid2[80],voter[80],che[20],c;
	//Heading
    char heading();
    int display();
    int forvoting();
    int addcandidates();
    int listofvoters();
    int listofcandidates();
    int livecount();
    
#endif