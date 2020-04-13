/*
 *  *................... C PROJECT..........................
 *   TOPIC: REGULAR EXPRESSION EDITOR
 *      -ANKIT ANAND
 *      -SAI MAHATMA
 *          
*/
/*.........................................................*/
/* including header */
#include"header.h"
void main(int argc,char *argv[])
{
 int i,j,no_flag=0,line_no=0,no_matches=0;
 FILE *fp;
 bool check=false;                     //check if atleast one file is there in which match is true
 char line[100];
 start();
 flag_enabled=c_enabled=i_enabled=l_enabled=n_enabled=v_enabled=h_enabled= w_enabled=false;
anchor_enabled=dot_enabled=class_enabled=group_enabled=rep_enabled=false; 


/* Enabling the flags and counting them */
for( i=1 ; i<argc ; )
 {
  if(argv[i][0]!='-')
    break;
  else
   {
    flag_enabled=true;
    enableFlag(argv[i]);
    if(h_enabled)
      exit(0);
    i++;
   }
 } /* end of for loop */

 
 no_flag=i-1; /* numbrer of flags */
 
 
 /* Error if only flags are  passed and file(s) is(are) missing */ 
  if(((i>=argc-2)&&(!(argc >=3)))||(!(argc >=i+2 )))
   {
     printf("\nWrong syntax\nHelp: ./main -h \n");
	 help();
     exit(1);
   }


 /* Error if file names start with '-' (only flags begin with '-')  */    
  while(i<argc)
  {
   if(argv[i][0]=='-')
   {
     printf("\nWrong syntax \nHelp: ./main -h \n");
     help();
	 exit(2);
   }
   i++;
  } /* end of while */



 j = no_flag + 2 ;  /* index of the first file  */


 /* Editing file by file */
 if(l_enabled)
	printf("\nList of files in which atleat one matching is true:\n");
 while( j < argc ) 
 {
   fp = fopen(argv[j] , "r") ;
   if(!fp)
   {
     printf("\n not able to open %s file.\n" , argv[j]) ;
     j++ ;
	 continue ;
   }
   /* Processing line by line */
  line_no=0; 
  no_matches=0;
  core(argv[no_flag+1]);
  fscanf(fp ,"%[^\n]s",line);
  while( (fscanf(fp ,"%[^\n]s",line))!=EOF) 
	{       
			line_no++;
           	   mainCore(line,line_no,&no_matches);
               fseek(fp,1,1);

       } /* end of inner while loop */
   if(c_enabled)
   printf("\nNo of lines matched in the file '%s'is %d \n",argv[j],no_matches);
   if((l_enabled)&&(no_matches))
		   printf("\n\t\t-'%s'\n",argv[j]);
   if(no_matches)
		   check=true;

   j++;
 } /* end of outer while loop */
 if(l_enabled && !check)
		 printf("\n\tNo files has atleast one line in which matching is true..\n");
printf("\n\n\n\t\t...............................SAIRAM..............................\n");
} /* end of main() */



