*                                              AUM SRI SAI RAM
*
PROJECT ON REGULAR EXPRESSIONS
          Authors:
              R. SAI MAHATMA     Regd No:133211
              ANKIT ANAND       Regd No:133214


* This lets you experiment with " Regular Expressions" as
  implemented by the grep command.  In this :
.       Matches any single character (including newline)
[list]  Matches a single character contained in the brackets.
        Ranges using "-" are supported; "-" is a literal if first or last.
        Negate by beginning with ^ inside [ ].
^       Matches the starting position.  MUST USE if want to match whole string.
$       Matches the ending position.  MUST USE if want to match whole string.
\       Escape character; a following metacharacter loses its meaning.
        Use \\ for backslash itself.
\(...\)   Subexpression; treat the entire expression as one expression.
|       Alternative.  "cat|dog" matches either "cat" or "dog".
*       Matches the preceding element zero or more times.
+       Matches the preceding element one or more times.
?       Matches the preceding element zero or one times ("optional")
\{m,n\}   Matches the preceding element at least m and not more than n times.
									
*   User can give multiple files for this.									
	
*   Some sample regular expressions are :
*   Variable name for many programming languages:
*  [_A-Za-z][_A-Za-z0-9]
*  Decimal Numbers
*  ^[0-9]+(\.[0-9]*)?([Ee][0-9]+)?$
*  Lastname, Firstname[additional names]
* ^[A-Za-z'!]+,( [A-Za-z'!]+)+$
*
*
*                                                    
.............................................................................................
.............................................................................................

Files' Description:

readMe.txt  : file containing description of project 
header.h    : file for including all headers and declarations of functions
main.c      : file with main() functions
functions.c : file containing functions' definitions
makefile    : makefile
Summary.txt : file containing the summary of our project, limitations, future work and acknowledgements.

..............................................................................................
..............................................................................................
Usage:
         ./main [OPTIONS] 'REG_EXP' [FILES]


        .........................Useful flags............................
               -c :Prints the count of no of lines matching the pattern.
               -i :Ignores the case(Upper||Lower).
               -l :Prints the list of files in which atleast one line matches the pattern.
               -n :Shows line no. of line matching the pattern in the file.
               -v :(Inverse output)Prints the lines do not match the pattern.
               -w :Exact word match


..............................................................................................
..............................................................................................

Coding done  by Matahma :

  void start(void)                                                                  
  void help(void)
  void display(node*)
  void display2(Node*)
  void displayMachine(void)                                                         
  void validityCheck(void)
  Node* insert(Node* ,int,int,char *,int)                                           
  void combination(void)
  Node* del(Node*,int,int)                                                          
  bool findNull(void)
  void stateMachine(void)
  void insertInMachine(void)
  bool isRep(char*,int,int*)
  bool match(char *)
  

Codings done by Ankit : 

  void stateMachine(void)                                   
  void enableFlag(char [])                                   
  void core(char*)
  void mainCore(char*,int,int*) 
  bool match(char *)                                     
  char isAnchor(char*)
  char isClass(char*,int,int*)
  bool isGroup(char*,int ,int*)                                                     
  bool isDot(char*)
  bool isRep(char*,int,int*)
..........................................................................................