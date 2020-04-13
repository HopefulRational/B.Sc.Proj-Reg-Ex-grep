/*including headers*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>

#define MAX 50            /* #define constant(const global)*/

#define MAX_OPTNS 7 
int compo;
/*.........................................*/  
typedef struct tree
{       char ch;
		int low1,low2;        
		int up1,up2;
		struct tree* next_sibling;
		struct tree* next_vertex;
		bool state;


}tree;	
tree  **st_machine;
/*..........................................*/

/*..........................................*/
typedef struct optns
{
  bool anchors[4],clas[2],group[2],repition[4],dot,star,alteration ;
  } Flags ;
typedef struct Options
{
		bool clas , rep , dot , star , altrn , grp ;
}oprtrs ;
/*.........................................*/
typedef struct R_node
{
		char data[2] ;
		int pos ;
		struct R_node* nxt ;
}NoDe ;
/*..........................................*/

typedef struct node
{
  char sub_reg[MAX] ;
  bool status ;
  struct node* next;
} node ;  
 node *head;
/*........................................*/
typedef struct Node
{
 int start,end,type;
 char reg[MAX];
 struct Node* next; 
}Node;
/*........................................*/
typedef struct Node* list;
 list  grps, cls,  rep,  combo, dot,   star;/*linked lists for groups,clsses,and repitions*/
 
/*.........................................*/
node* createNode(void);
/*.........................................*/
bool flag_enabled, c_enabled, i_enabled, l_enabled, n_enabled, v_enabled, h_enabled, w_enabled;


bool anchor_enabled,dot_enabled,class_enabled,group_enabled,rep_enabled;
bool wd_beg,wd_end,line_beg,line_end;
void start(void);
void help(void);
void display(node*);
void display2(Node*);
void displayMachine(void);
void validityCheck(void);
Node* insert(Node* ,int,int,char *,int);
void combination(void);
Node* del(Node*,int,int);
bool findNull(void);
void stateMachine(void);
void insertInMachine(void);
/*..........................................*/
void enableFlag(char []);
/*..........................................*/
void core(char*);
/*..........................................*/
void mainCore(char*,int,int*) ;
/*..........................................*/
bool match(char *);
/*..........................................*/
char isAnchor(char*);
char isClass(char*,int,int*);
bool isGroup(char*,int ,int*);
bool isDot(char*);
bool isRep(char*,int,int*);
/*..........................................*/
