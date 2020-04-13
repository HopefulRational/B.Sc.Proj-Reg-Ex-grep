#include"header.h"
/*...................................*/
/*function to crete node for saving components in a given re_exp*/
node* createNode(void)
{
 node *p;
 p=(node*)calloc(sizeof(node),1);
 return p;
}
/*...................................*/
/*function to crete node for saving indices of groups,classes repitions*/
Node* createNode2(void)
{
  Node *p;
  p=(Node*)calloc(sizeof(Node),1);
  return p;
}
/*...................................*/
tree* createNode3(void)
{
		tree *p;
		p=(tree*)calloc(sizeof(tree),1);
		return p;
}

/*...........................................*/
/*This functions takes care of correctness(validity) of braces []()*/
void validityCheck(void)
{
		node *sub;
		Node *temp,*temp2;
		char check[]="/bin";
		int i,len=0;
		if(head!=NULL)
				sub=head->next;
			for(;sub!=NULL;sub=sub->next)
				{
						if(!strcmp(sub->sub_reg,check))
						{
								printf("\nError\n");
								exit(6);
						}
						len=strlen(sub->sub_reg);
						if(((len==1)&&(sub->sub_reg[0]=='['))||((len==2)&&((sub->sub_reg[0]=='[')||(sub->sub_reg[1]=='['))))
								printf("\n%s is Invalid regular expression \n",sub->sub_reg);
						if((len==2)&&(sub->sub_reg[0]=='[')&&(sub->sub_reg[1]==']'))
								printf("\n%s is Invalid regular expression \n",sub->sub_reg);

                }
			for(temp=grps;temp!=NULL;temp=temp->next)
			  {
					  for(temp2=cls;temp2!=NULL;temp2=temp2->next)
						{
                         if(!strcmp(temp->reg,temp2->reg))
						  {
							if((temp->start > temp2->start)&&(temp->end >temp2->end))
								 {	printf("INVALID");
								    exit(4);
								 }
							if((temp->start < temp2->start)&&(temp->end <temp2->end))
						     {  printf("INVALID");
						       exit(5);
				 																						                                                 }
						  }		  
						}		
			  }
	       for(temp=cls;temp!=NULL;temp=temp->next)
				   {
					 if((temp->end -temp->start)==1)
					  {printf("\nsynatax error in '[]' \n");
					     exit(8);
							 }
				   }


}
/*....................................*/
/*for Inserting(at the end) in linked list*/
Node* insert(Node *header,int start,int end,char reg[],int no)
{
 Node *p,*q;
 p=createNode2();
 
 if(p==NULL)
  {
	printf("\nSORRY!! No space\n");
	return header;
  }
	p->start=start;
	p->end=end;
	strcpy(p->reg,reg);
	p->type=no;
        if(header==NULL)
	{
	 header= p;
	 header->next=NULL;
	 return header;
	 
    }
 
 q=header;
 
while((q->next)!=NULL)
	q=q->next;
								   
  q->next=p;
  p->next=NULL; 
return header;

}
/*................................................................*/

Node* insertAscend(Node* header,int start,int end,int type,char reg[])
{
  Node *p=createNode2(),*temp=header;
  if(!p)
   {
   printf("\nNo space\n");
    }
  p->start=start;
  p->end=end;
  p->type=type;
  strcpy(p->reg,reg);
  if(header==NULL)
  {
		  header=p;
		  header->next=NULL;
          return header;
  }
  if((header->start) > (start))
   {
		   p->next=header;
		   header=p;
		   return header;
   }
   while(temp)
   {
		   if(((temp->start ) <(p->start))&&((temp->next==NULL)|| (((temp->next)->start)>(p->start))))
           {
				   p->next=temp->next;
				   temp->next=p;
				   return header;
		   }
   }
  return header;
   
}
/*...................................................................*/
/*For deleting node from linked list*/
Node* del(Node *header,int s,int e)
{
		Node *prev=NULL,*curr=header;
		if(curr==NULL)
				return header;
          if((curr->start ==s)&&(curr->end==e))
				 {
						 header=header->next;
						 free(curr);
						 return header;
				 }
			 while(curr)
				{
						if((curr->start ==s)&&(curr->end==e))
						 {
								 prev->next=curr->next;
								 free(curr);
								 return header;
						 }
						  else
						    {
									prev=curr;
									curr=curr->next;
							}
				}
 return header;				
}				

/*..............................................................*/
/*Function to intialise the linked lists and other global variables*/
void start(void)
{
 head=createNode();
 grps=NULL;   cls=NULL;    combo=NULL;
 rep=NULL;    dot=NULL;    star=NULL; 
   /*.................................*/
 anchor_enabled=false;
 dot_enabled=false;     class_enabled=false;
 group_enabled=false;   rep_enabled=false;
   /*.................................*/
 flag_enabled=false;  c_enabled=false;
 i_enabled=false;     l_enabled=false;
 n_enabled=false;     v_enabled=false;
 h_enabled=false;     w_enabled=false;
}
/*..................................*/
/*Function to display the linked list in which components are saved*/
void display(node* head)
{
 node *temp=head;
 while(temp!=NULL)
 {
  printf("\n%s\n",(temp->sub_reg));
  temp=temp->next;
 }
}
/*..................................*/
/*Function to display the linked list in which either groups or classes are saved*/
void display2(Node* header)
 {
	Node *temp=header;
	while(temp!=NULL)
	{
		printf("\n[%d , %d]\t type=%d\n",temp->start,temp->end,temp->type);
		temp=temp->next;
	}
 }
/*..................................*/
/*Function for help*/
void help(void)
{
  			   printf("\nUSAGE: ./main [OPTIONS] REG_EXP [FILES]\n");
               printf("\n.........................Useful flags............................\n");
               printf("\n -c :Prints the count of no of lines matching the pattern.\n"
   	                  " -i :Ignores the case(Upper||Lower)\n"
	                  " -l :Prints the list of files in which atleast one line matches the pattern\n"
	                  " -n :Shows line no. of line matching the pattern in the file\n"
	                  " -v :(Inverse output)Prints the lines do not match the pattern\n"
		              " -w :Exact word match\n.................................................................\n\n");

}
/*..................................*/
void combination(void)
{ int cnt=0;
  Node *temp=createNode2(),*temp2=createNode2();  
  if(grps==NULL && cls==NULL && rep==NULL)
   {combo=NULL;
     return ;

    }
  //combo=createNode2();
  temp2=combo;
  temp=cls;
  while(temp)
  {  cnt++;
     if(cnt!=1)
     temp2->next=temp;
     else
      {temp2=temp;
	   combo=temp2;
      }
	  temp=temp->next;
   }
   temp=grps;
  while(temp)
  {
    combo=insertAscend(combo,temp->start,temp->end,2,temp->reg);
	temp=temp->next;
   }  
   temp=rep;
  while(temp)
  {
   combo=insertAscend(combo,temp->start,temp->end,3,temp->reg);
   temp=temp->next;
  }
 return;
}
/*....................................*/
/*Function to enable flags entered by the user in a given regular exp
 * This function will take input the string which is given as argument in command line and
 * which started with '-' character 
 */
void enableFlag(char a[])
{
 int j,len=strlen(a);
 char ch;
 for(j=1;j<len;j++)
 {
  ch=a[j];
  switch(ch)
  {
   case 'c':
           c_enabled=true;
        break;
   case 'i':
           i_enabled=true;
        break;
   case 'l':
           l_enabled=true;
        break;
   case 'n':
           n_enabled=true;
        break;
   case 'v':
           v_enabled=true;
        break;
   case 'h':
           h_enabled=true;
           printf("\nUSAGE: ./main [OPTIONS] REG_EXP [FILES]\n");
           printf("\n.........................Useful flags............................\n");
           printf("\n -c :Prints the count of no of lines matching the pattern.\n"
               " -i :Ignores the case(Upper||Lower)\n"
               " -l :Prints the list of files in which atleast one line matches the pattern\n"
               " -n :Shows line no. of line matching the pattern in the file\n"
               " -v :(Inverse output)Prints the lines do not match the pattern\n"
               " -w :Exact word match\n.................................................................\n\n");
               
        break;
   case 'w':
           w_enabled=true;
        break;
   default:
        printf("\n -%c is not a flag!! Please correct your syntax.\n",ch);
     
  }
 }
}
/*........................................................*/
char* ignoreCase(char a[])
{
		int len=strlen(a),i;
		for(i=0;i<len;i++)
		{
				if(a[i]>=65 && a[i]<= 90)
						a[i]=a[i]+32;
		}
	return a;	
}
/*...........................................................*/
/*...................................*/
/*This function is for dividing into components if they are there..
 * Basically input for this is regular expression...
 * This function will find if any components are there in the given expression
 * and save each component in linked list..
 */
int components(char reg[])
{ 
  int i=0 , j=0 , k=0 ;
  int reg_size = strlen(reg) ;
  int no_comps=1 ;
  bool cond=false; 
  node *part=createNode(),*part2,*sub;
  head->next=part;
  for( ; k<reg_size ; k++)
  { 
		  if((i_enabled)&&(reg[k]>=65 && reg[k]<= 90))
		  {
				  reg[k]=reg[k]+32;
		  }
	if(reg[k]=='(')
       cond=true;
      else if(reg[k]==')')
	    cond=false;
     /*if(reg[k] != '|')
      {
         part->sub_reg[j] = reg[k] ;
        j++ ;
       }
	   */
    if((cond == false)&&(reg[k]=='|')&&(reg[k-1]==92))
     {
       part->sub_reg[j] = '\0' ;
       part->status = false ;
       
       part2=createNode();
       part->next=part2;
       part=part2;
       no_comps++;
      // i++ ;
       
       
       j = 0 ; 	
     }
	 else if(reg[k]!=92)
		{
          part->sub_reg[j] = reg[k] ;
		         j++ ;
		 }		
	   else if(reg[k]==92)
	     	{
              if(k!=reg_size-1)
				  {	if((reg[k+1]!='|'))
							{part->sub_reg[j] = reg[k] ;
							                 j++ ;
			                 }
					else if((reg[k+1]=='|')&&(cond))
					{
							part->sub_reg[j] = reg[k] ;
							            j++ ;

				    }			
				  }
			   else
			   {
					   part->sub_reg[j] = reg[k] ;
					                   j++ ;
			   }		   
			}



	     	}		

  
     part->sub_reg[j] = '\0' ;
     part->status = false ;
			
  validityCheck(); 
  //printf("\nno of components is %d\nThey are..\n..................................\n",no_comps) ;
    
  //display(head);
  printf("\n...........................\n");
  compo=no_comps;
  return no_comps;
}
/*...................................*/
/*This function is for anchors
 * There are 4 kinds of Anchors
 * this function will take each component one by one from the linked list
 * and check if anchors is there
 */
char isAnchor(char exp[])
{
	int len=strlen(exp);
	if(exp[0]=='^')
	{
         return '1';

	}
	if((exp[0]==92)&&(exp[1]=='<'))
	{
         return '2';
	}
	if((exp[len-2]==92)&&(exp[len-1]=='>'))
	{
         return '3';
	} 
	if(exp[len-1]=='$')
	{
         return '4';
	}
  return '0';
}
/*...................................*/
bool findNull(void)
{
		node *temp=head->next;
		while(temp)
		{if(!strlen(temp->sub_reg))
		   return true;

		  temp=temp->next; 
	    }   
		return false;
}		

/*.......................................................*/
/*This function is for CLASSES
 * this functions takes each component one by one from linked list
 * and check if any classes are there..
 * and if classes are there, it will give the starting and ending position of class
 */
char isClass(char exp[],int open,int *close)
{       char ch;
	int i=open;
	int len=strlen(exp);
        bool cls=false;
	
	if((exp[i]=='[')&&(i!=len-1))
	{   
                
		while((i<len)&&(exp[++i]!=']'))
		 { 
			if((i==len-1)&&(exp[i]!=']'))
					 {
							 printf("\nInvalid Expression\n");
							 exit(11);
					 }
         }
			if((i==len-1)&&(exp[i]!=']'))
			  return false;
            else
			  cls=true;
                 
		*close = i;
     }
           if(cls)
		   {		   
              if(exp[open+1]=='^')
               {
				if(i>=3)   
                 if((exp[i-2]=='-')&&(exp[i-3]!=92))
                    return '4';
                 else
                   return '3'; 
                }
		     if(i>=3)
               if((exp[i-2]=='-')&&(exp[i-3]!=92))
                   return '2';

                return '1';
	       }

	//printf("in is_class at the end\n");
	return '0'; 
}
/*...................................*/
/*This function is for GROUPS
 * this functions takes each component one by one from linked list
 * and check if any groups are there..
 * and if groups are there, it will give the starting and ending position of groups
 */

bool isGroup(char exp[],int open,int *close)
{
	int i=open;
	int len=strlen(exp);
	if(exp[i]=='(')
	{
		while(exp[++i]!=')')
		{
			if((i==len-1)&&(exp[i]!=')'))
				return false;

		}
            *close=i;
        return true;
	}
	
	return false;

}
/*...................................*/
/*This function is for Repitions
* this functions takes each component one by one from linked list
* and check if any Repitions are there..
* and if reptions are there, then it will give the starting and ending position of repitions
*/

bool isRep(char exp[],int open,int *close)
{
	int len=strlen(exp),i=open;
	if(exp[i]==92)
	{
		if(exp[++i]=='{')
		{
		   if(exp[i+1]==',')
				 return false;
			  	
			while(exp[++i]!=92)
			{
				if(i==len-1)
					return false;
			}
			if(exp[++i]=='}')
                {
                      *close=i;
           	       	   return true;
	                         
          	    }
                 }
      	}
	return false;
}
/*........................................................................*/
/*For refining groups,classes and repitions*/
void refine(void)
{
		node *sub;
		Node *temp,*temp2; 
		int i,j,len;
		if(head!=NULL)
			sub=head->next;

		  for(;sub!=NULL;sub=sub->next)
			{
              len=strlen(sub->sub_reg);
			  grps=del(grps,0,len-1); 
		    }
		  for(temp=grps;temp!=NULL;temp=temp->next)
		    {
		      if((temp->end -temp->start)==1)
				 grps=del(grps,temp->start,temp->end);
               else
			    {
						i=temp->start;
						j=temp->end;
					if((temp->reg[i-1]!=92)||(temp->reg[j-1]!=92))
							grps=del(grps,i,j);
                
				for(temp2=cls;temp2!=NULL;temp2=temp2->next)
				 {
					if(!strcmp(temp->reg,temp2->reg))
						{
						 if(((temp2->start)<i)&&((temp2->end)>j ))
								 grps=del(grps,i,j);
						}
				 }	
				} 
		    }
			for(temp=rep;temp!=NULL;temp=temp->next)
            {
			    if((temp->end -temp->start)==1)
		         rep=del(rep,temp->start,temp->end);
				 else
				 {
						 i=temp->start;
				         j=temp->end;
					for(temp2=cls;temp2!=NULL;temp2=temp2->next)
					{
							if(!strcmp(temp->reg,temp2->reg))
							{
									if(((temp2->start)<i)&&((temp2->end)>j ))
											rep=del(rep,i,j);
							}
					}
				 }
			}	 
		  for(temp=cls;temp!=NULL;temp=temp->next)
			{
					 if((temp->end -temp->start)==1)
					     {       printf("\nsynatax error in '[]' \n");
						                          exit(8);
								 cls=del(cls,temp->start,temp->end);
						 }
	        }
			

}		
/*.........................................................................*/

/*This functions is basically interface between main program and other functions
 * this will take regular expression as input
 * and calls the every other required function
 */
void core(char reg[])
{   char anchor,class;
	int i=0,cl_close,gr_close,no_comp,gr_index=0,cl_index=0,rep_close,rep_index=0;
    
	node *sub;
	printf("\nGiven regular expression is:%s\n",reg);
      
        
	no_comp=components(reg);
        //sub=head->next;
 validityCheck();
 /*
 if(!strlen(reg))
  {
   printf("%s\n",line);
  }
 */ 
  
  if(!findNull())
    if(strlen(reg))
	for(sub=head->next; sub!=NULL ; sub=sub->next)
       { //while(sub!=NULL)
     	  puts(sub->sub_reg);
           cl_index=0;
           gr_index=0;
           rep_index=0;
	       anchor=isAnchor(sub->sub_reg);
           if(anchor!='0')      
            printf("\nAnchor %c is in %s\n",anchor,sub->sub_reg);

          while(1)
	       {
				   class='0';
	          class=isClass(sub->sub_reg,cl_index,&(cl_close));
              if(class!='0')
	           {
				  //printf("\nclass %c[%d,%d] is there in %s",class,cl_index,cl_close,sub->sub_reg);
				  cls=insert(cls,cl_index,cl_close,sub->sub_reg,1);
		          cl_index=(cl_close)+1;
         		}
	          else
	         	cl_index++;
	    	if(cl_index >= (strlen(sub->sub_reg)-1))
		      break;
            }
          while(1)
            {
             if(isGroup(sub->sub_reg,gr_index,&(gr_close)))
              {
			   //printf("\ngroup[%d,%d] is there in %s",gr_index,gr_close,sub->sub_reg);
                grps=insert(grps,gr_index,gr_close,sub->sub_reg,2);
				 gr_index=(gr_close)+1;
                }
             else
                gr_index++;
                if(gr_index >= (strlen(sub->sub_reg)-1))
                 break;
            }
           while(1)
            {
             if(isRep(sub->sub_reg,rep_index,&(rep_close)))
              {
			    //printf("\nrepitition[%d,%d] is there in %s\n",rep_index,rep_close,sub->sub_reg);
                rep=insert(rep,rep_index,rep_close,sub->sub_reg,3);
				rep_index=(rep_close)+1;
                }
             else
                rep_index++;
                if(rep_index >= (strlen(sub->sub_reg)-1))
                 break;
            }


         //sub=sub->next;
         printf("\n.......................................\n");
          
	 }
	 refine();
         combination();
	 //display2(cls);
	 //display2(grps);
	//printf("\nrep\n");
	//display2(rep);
         display2(combo);
	 stateMachine();
       
	/*.....................................*/
}
/*..............................................................*/
/*Inteface between functions and main
 * INPUT:line and line_no
 * OUTPUT:prints the line if matching is true
 * */
void mainCore(char line[],int line_no,int* no_matches)
{
 FILE *fp;
 bool matched=false;
 fp=fopen("temp_file","a");
  fprintf(fp,"%s\n",line);
 
 matched=match(line);
 if(matched)
	{       
			(*(no_matches))++;
	}
 if(v_enabled)
   {
		   if(matched)
				   matched=false;
		   else
				   matched=true;
   }
 if(matched)
  {
		printf("\n");  
		  if(n_enabled)
				  printf("%d:",line_no);
		printf("%s",line);
  }
  fclose(fp);
}
/*..............................................................*/
bool match(char line_orig[])
{
		//puts(line);
 if(findNull())
		return true;
 char ch,line[100];
  
 bool negation=false;
 int len=strlen(line_orig),i=0,j=0,k=0,l;
 tree *temp,*temp2,*temp3;
 i=0;
 strcpy(line,line_orig);
 if(i_enabled)
 {
		 for(i=0;i<len;i++)
		   {
                 if(line[i]>=65 && line[i]<= 90)
                        line[i]=line[i]+32;
		    }

 }
 for(k=0;k<compo;k++)
 {

		 i=0;

 start:
  temp=st_machine[k]->next_vertex;
  if(w_enabled)
  {
		 if(i!=0)
		 {
				 while(((i-1)<len)&&line[i-1]!=' ')
				 {
						 i++;
				 }
				 if(i>=len)
						 return false;
		 }
  }
 while(i<len)
  {  
	while(temp)
        { 
		  j=i;
	    	while(j<len)
				{  
						
				   if(temp==NULL)
				    {     
							if(w_enabled)
							 {     if((j>(len-1))||(line[j]==' '))
							         return true;
								   else 
										   return false;
							  }
							return true;
				     }
					 
						ch=line[j];
			   if((temp->ch=='^')&&(temp->low1==0))
					  negation=true;
         		  else
		            negation=false;
		               	if(negation)
                           {//printf("\nthere is negation\n");
                                temp=temp->next_sibling;
                            }			  
           if(!negation && temp)
             {  
			  		 
			   if((temp->next_vertex)&&(((temp->next_vertex)->ch)=='*')&&(temp->next_vertex->next_vertex)&&((temp->next_vertex->next_vertex)->ch==ch))
			    { 
						
						temp=temp->next_vertex->next_vertex;
				        continue;
				}

				 
                 if((temp->next_vertex)&&(temp->next_vertex->ch=='*'))
				  {
						  temp3=temp;
						  if((((ch >= temp->low1)&&(ch <= temp->up1))||((ch >= temp->low2)&&(ch <= temp->up2))))
						  {
								  j++;
								  if(temp->ch!=line[j])
								  {
								    temp=temp->next_vertex->next_vertex;
						           }

								  continue;

						  }
				  
				         else if(temp3->next_sibling)
				         {
								 temp3=temp3->next_sibling;
								 while(temp3)
								 {
								   if((((ch >= temp3->low1)&&(ch <= temp3->up1))||((ch >= temp3->low2)&&(ch <= temp3->up2))))
								     {
										 break;
										 
								     }
									else
											temp3=temp3->next_sibling;
								 }
                                 if(temp3)
								 {
										 j++;
										 if(temp->ch!=line[j])
										{
								           temp=temp->next_vertex->next_vertex;
										 }

										 continue;
								 }
								 else
								 {
										 i++;
										 goto start;
								 }
				         }

				  }
	   
	   if((temp->next_vertex)&&(temp->next_vertex->ch=='+'))
	    {
				temp3=temp;
			     if((((ch >= temp->low1)&&(ch <= temp->up1))||((ch >= temp->low2)&&(ch <= temp->up2))))
					{
								  j++;
							 if(temp->ch!=line[j])
								   {
																																																															                                     temp=temp->next_vertex->next_vertex;
																																																																						    }

							 continue;

																																																																		    }

																																																																		  else if(temp3->next_sibling)
					 {
																																																																			  temp3=temp3->next_sibling;
																																																																				 while(temp3)
							 {
																																																																																																																																	            if((((ch >= temp3->low1)&&(ch <= temp3->up1))||((ch >= temp3->low2)&&(ch <= temp3->up2))))
								 {
											break;

							     }
																																																																				       else
								 temp3=temp3->next_sibling;
						     }
						 if(temp3)
		                 {
						        j++;
								if(temp->ch!=line[j])
								{
										temp=temp->next_vertex->next_vertex;
										}

						     continue;
						}	 
                      else
						{
							    i++;
								goto start;
						}
					 }
		}
			       { 
			        if(((ch >= temp->low1)&&(ch <= temp->up1))||((ch >= temp->low2)&&(ch <= temp->up2)))
		             {
										 
		                if(temp->state)
						{ if(w_enabled)
						   {
							 if(j!=len-1)
                               {
									   if(line[j+1]==' ')
											   return true;
									   return false;
							   }
						   }
		            	  return true;
						}
			               j++;
						   if(j>len-1)
								   return false;
		                 temp=temp->next_vertex;
	               	}
                 	else
	                 {
	                  if(temp->next_sibling)
	                   {   
							   temp=temp->next_sibling;
		                       continue;
	                   }
	                  else
	                   { 
							   i++;

		                       goto start;
	                   }
	                 }
		        	}	 
              }   
           else 
              {
					temp2=temp;
               while((temp))
				{  if(temp->low1==0 && temp->up1==0)
				    {
							temp=temp->next_sibling;
							continue;
					}
					if((((ch>=temp->low1)&&(ch<=temp->up1))||((ch>=temp->low2)&&(ch<=temp->up2))))
                     temp=temp->next_sibling;

					else
					  break;
                 
               }
               if(temp==NULL)
                 {if(temp2)
                   temp=temp2->next_vertex;
                     if(temp2->state)
                        return true;
                          negation=false;  
                   j++;
                  
                  }
                  else
                   { 
						   negation=false;
                           i++;
                           goto start;
                   }                
              }								 
								
						//j++;
		}
				

				 
	 }
   }
 }


 return false;
}
/*................................................................*/
/*................................................................*/
/*Constucting STATE MACHINE....................................*/
void stateMachine(void)
{
 int i,len=0,j=0,no=0;
 int open=0,close=0,cnt=0,counter=0;
 Node *temp;
 bool check=false;
 node *sub=head->next;
 tree *find=createNode3(),*dup=createNode3(),*tmp;
 tree *prev=createNode3(),*curr=createNode3(),*next;
 insertInMachine();
 
 for(i=0;(i<compo)&&(sub!=NULL);i++,sub=sub->next)
 {    //  printf("\ni=%d\n",i);  
		 len=strlen(sub->sub_reg);
		 prev=st_machine[i];
		 curr=st_machine[i]->next_vertex;
		 if(curr->next_vertex!=NULL)
		 next=curr->next_vertex;
		 cnt=0;no=0;
       for(temp=combo;temp!=NULL;temp=temp->next)
	   {
			   prev=st_machine[i];
			   curr=st_machine[i]->next_vertex;
			   next=curr->next_vertex;
	    if(temp->type==1)
           {
            if(!(strcmp(temp->reg,sub->sub_reg)))
		{     // cnt=0;
		       counter=0;
			   find=curr;
		     while(find)
			 {
              if((find->ch == ']')&&(cnt==temp->end))
					  break;

					  else
					  {
							  cnt++;
							  find=find->next_vertex;
					  }
			 }
			 cnt=no;
			   
			   if((temp->end-temp->start)==2)
			   {
					   while(curr)
					   {
							   if(curr->ch=='[')
									   break;

							   prev=curr;
							   curr=next;

							   if(curr)
							   next=curr->next_vertex;
					   }
					   next->next_vertex=find->next_vertex;
					   prev->next_vertex=next;
					   free(curr);
          

			   }
              else
				while(curr)
			    {
						
				if((curr->ch=='[')&&(cnt==temp->start))
				{       cnt+=2;
						check=true;
						prev->next_vertex=next;;
                        
						free(curr);
						
						curr=next;
					   if(next!=NULL)	
						next=next->next_vertex;


						continue;

				}
				else if((curr->ch==']')&&(cnt==temp->end))
                {
						cnt+=2;
						check=false;
						free(curr);
                        prev->next_vertex=find->next_vertex;

                        break;
				}
				else
				{      if(check)
				       {
						counter++;	   
					    if(counter==1)		   
					       prev=curr;
						while(prev->next_sibling)
                              {       prev->next_vertex=find->next_vertex;
									  prev=prev->next_sibling;
							  }
							  if(counter==1)
							  { prev->next_sibling=next;
								
							  }

							  else
								{
										curr->next_vertex=find->next_vertex;
										prev->next_sibling=curr;
								}

							  prev->next_vertex=find->next_vertex;
                              
						if(counter==1)
 						{
								curr=next->next_vertex;
								
								if(curr)
								next=curr->next_vertex;
								prev->next_sibling->next_vertex=find->next_vertex;
 
						}
						else
						{
								curr=next;
								if(next)
								next=next->next_vertex;
						}
					   }
						
						else
						{
						prev=curr;
						curr=next;
						if(next!=NULL)
						next=next->next_vertex;
						}
						cnt++;
				  }
			     }
		       
		 
             
			 no+=(temp->end-temp->start);
			 cnt=no;
	   	    }
     	   }
	counter=0;
         }
       }
	   sub=head->next;
	   for(i=0;(i<compo)&&(sub!=NULL);i++,sub=sub->next)
     	{  
			     len=strlen(sub->sub_reg);
		          prev=st_machine[i];
				  curr=st_machine[i]->next_vertex;
				  if(curr->next_vertex!=NULL)
                   next=curr->next_vertex;
				   
				   while((curr)&&(curr->ch!='*'))
				   {
						   prev=curr;
						   curr=next;
						   if(next)
								   next=next->next_vertex;

				   }
				   while(1)
				   {
						 if((curr==NULL)||(curr->ch!='*'))
								   break;
						  if(next)		
						  {
						   if((((next->ch)>=(prev->low1))&&((next->ch)<=(prev->up1)))||(((next->ch)>=(prev->low2))&&((next->ch)<=(prev->up2))))
						   {
							if(!(prev->next_sibling))
							{		
							dup->ch=prev->ch;
							dup->low1=prev->low1;
							dup->up1=prev->up1;
							dup->low2=prev->low2;
							dup->up2=prev->up2;
							dup->next_vertex=curr;
							prev->next_vertex=dup;
							
							prev->next_vertex=dup;
							}
						   
                            curr->next_vertex=next->next_vertex;
							free(next);
							next=curr->next_vertex;
						    }
						   else if(prev->next_sibling)
						   {
								   prev=prev->next_sibling;
								   while(prev)
								   {
										  if((((next->ch)>=(prev->low1))&&((next->ch)<=(prev->up1)))||(((next->ch)>=(prev->low2))&&((next->ch)<=(prev->up2))))
								           {
												   break;
										   }
										   else
												   prev=prev->next_sibling;
								   }
								   if(prev)
								   {
										   curr->next_vertex=next->next_vertex;
							               free(next);
										   next=curr->next_vertex;

								   }
								   else
								   {
										   break;
								   }

						   }
						   else
								   break;
						  }
						  else
								  break;
				   }
        }
		
		sub=head->next;
		 for(i=0;(i<compo)&&(sub!=NULL);i++,sub=sub->next)
	     {
		           len=strlen(sub->sub_reg);
				                 prev=st_machine[i];
					 
                   curr=st_machine[i]->next_vertex;
				         if(curr->next_vertex!=NULL)
							next=curr->next_vertex;
		while((curr)&&(curr->ch!='+'))
		   {
		         prev=curr;
                  curr=next;
					if(next)
	                 next=next->next_vertex;

			}
	   
         while(1)
		   {
				      if((curr==NULL)||(curr->ch!='+'))
		                                  break;
							if(next)
	                         {
						       if((((next->ch)>=(prev->low1))&&((next->ch)<=(prev->up1)))||(((next->ch)>=(prev->low2))&&((next->ch)<=(prev->up2))))
							   {
								if(!(prev->next_sibling))
							     {
									 dup->ch=prev->ch;
						             dup->low1=prev->low1;
				                     dup->up1=prev->up1;
									 dup->low2=prev->low2;
									 dup->up2=prev->up2;
							         dup->next_vertex=curr;
									 prev->next_vertex=dup;
								  
								  prev->next_vertex=dup;
                                  }
							    
								curr->next_vertex=next->next_vertex;
								                            free(next);
							    next=curr->next_vertex;
                               }
							  else if(prev->next_sibling)
					                {
									 prev=prev->next_sibling;
									 while(prev)
									 {
									  if((((next->ch)>=(prev->low1))&&((next->ch)<=(prev->up1)))||(((next->ch)>=(prev->low2))&&((next->ch)<=(prev->up2))))
									{
					                                              break;
					   																																																							                                           }
					   			     else
								      prev=prev->next_sibling;
									 }
									 if(prev)
								       {
											      curr->next_vertex=next->next_vertex;
												    free(next);
													next=curr->next_vertex;

                                        }
									 else
											 break;
									}
								else
										break;
				}
							else
									break;
		}					
                       

    }
          		
                               
	   displayMachine();	 
  
}
/*..................................................................*/
/*Insert into tree*/
void insertInMachine(void)
{
		node *sub;
		tree *temp1,*temp2;
		bool class=false,check1=false,check2=false,negation=false;
		int i=0,len,j=0,k=0,find=0;
		 st_machine=(tree**)calloc(sizeof(tree*),compo);
		  if(st_machine==NULL)
		  {
		         printf("\nSorry!No space");
				 exit(5);

		  }
	for(i=0;i<compo;i++)
	{
			st_machine[i]=createNode3();
	}
  for(i=0,sub=head->next;i<compo;i++,sub=sub->next)
	{  
			    temp1=createNode3();
				temp2=createNode3();
				temp2=st_machine[i];
				len=strlen(sub->sub_reg);
				check1=false;
				check2=false;
				negation=false;                           /*negation in class*/
				

	  for(j=0;j<len;j++)
     	{ 
	     if(sub->sub_reg[len-1]==']')		
		    check1=true;
		 
	     	temp1=createNode3();
			     
	     	temp1->ch=(sub->sub_reg[j]);
	    	if(temp1->ch=='[')
		     {
					 class=true;
						  
		          if(sub->sub_reg[j+1]=='^')
	               {
		             negation=true;
								  //j++;
		            }
		           else
		            negation=false;
						  
                  for(k=j;k<len;k++)
                   {
                     if(sub->sub_reg[k]==']')
                        {
								if(k==len-1)
  			                       check2=true;
		                        else  
                                   check2=false;

		                      break;
                        }
	         	      else
         		       check2=false;	 
 
	                }
              }

	    	else if(temp1->ch==']')
		       class=false;
           if((temp1->ch=='-')&&class&&(sub->sub_reg[j-1]!=92))
      	     {   if(sub->sub_reg[j-1] > sub->sub_reg[j+1])
			      {
						  printf("\nInvalid range\n");
						  exit(10);
				  }
					 if(!negation)
                      {
	        	        temp1->low1=(int)(sub->sub_reg[j-1]);
		                temp1->up1=(int)(sub->sub_reg[j+1]);
						 
						 
		                temp1->low2=(int)(sub->sub_reg[j-1]);
	                 	temp1->up2=(int)(sub->sub_reg[j+1]);
                       }
                     else
                      {
                         temp1->low1=1;
		                 temp1->up1=(int)(sub->sub_reg[j-1])-1;

		                 temp1->low2=(int)(sub->sub_reg[j+1])+1;
                         temp1->up2=127;
                           printf("\nentered 127\n");
		               }

	        }
    	else
        	{ 
					if((temp1->ch=='^')&&(sub->sub_reg[j-1]=='['))
	                 {
                       temp1->low1=0;
		               temp1->up1=0;
                       temp1->low2=0;					
                       temp1->up2=0;

	                 }
                    else
	                 {
	                  if((sub->sub_reg[j+1]=='-')||(sub->sub_reg[j-1]=='-'))
                       { 
		                temp1->low1=0;
		                temp1->up1=0;
		                temp1->low2=0;
		                temp1->up2=0;

	                 	}
	                  else
	                	{
		                 if(!negation)
		                 {
		            	   temp1->low1=(int)(sub->sub_reg[j]);
		                   temp1->up1=(int)(sub->sub_reg[j]);

            		       temp1->low2=(int)(sub->sub_reg[j]);
		                	temp1->up2=temp1->low2;
	                     }
                        if(negation)
		                 {
		     	            temp1->low1=1;
				            temp1->up1=(int)(sub->sub_reg[j])-1;
  
             			    temp1->low2=(int)(sub->sub_reg[j])+1;
					        temp1->up2=127;
		                  }
                        }
                     }
	    	}
	temp1->next_sibling=NULL;
	if(j==(len-1))
	  temp1->state=true;
	  else if(check1&&check2)
		temp1->state=true;
		else 
                   temp1->state=false;
	temp2->next_vertex=temp1;
				 
                 
	temp2=temp1;
        
         }
	 }
	 //displayMachine();

}
/*...................................................*/
/*...Display state machine....*/
void displayMachine(void)
{
		int i,j;
        tree *temp=createNode3();
		for(i=0;i<compo;i++)
		{
				j=0;
				temp=st_machine[i]->next_vertex;
				while(temp)
				{
                 printf("\n Level %d",++j);
				 printf(" \nNode==\t %c \tlow1=%d\tup1=%d \n\t\tlow2=%d\tup2=%d\n",temp->ch,temp->low1,temp->up1,temp->low2,temp->up2);
				 if(temp->state)
						 printf("\n\t\ttrue\n");
						 else
								 printf("\n\t\tfalse\n");
				 while((temp->next_sibling))
				    {   
							temp=temp->next_sibling;
							printf(" \n \t \tSibling== %c \tlow1=%d\tup1=%d\n\t\tlow2=%d\tup2=%d\n ",temp->ch,temp->low1,temp->up1,temp->low2,temp->up2);
							if(temp->state)
	                              printf("\n\t\ttrue\n");
									     else
								            printf("\n\t\tfalse\n");

					}
					temp=temp->next_vertex;
				}
			printf("\n");
		}
}
/*....................................................*/
























