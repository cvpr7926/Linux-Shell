#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <ctype.h>
#include<sched.h>
#include<pwd.h>
int myls1();
int myps1();
int myps2();
int myps3();
int myps4();
int myps5(int pid);
 
    int myls3();
    int myls4();
    int myls5();
      int mygrep1(char *sorfile,char *desfile);
       int mygrep2(char *sorfile,char *desfile);
        int mygrep3(char *sorfile,char *desfile);
         int mygrep4(char *sorfile,char *desfile);
          int mygrep5(char *sorfile,char *desfile);
     int copyfile(char *sorfile,char *desfile);
     void connect(char *sorfile,char *desfile);
     void re(char *sorfile,char *desfile,int overwrite);
     void cp_u(char *sorfile, char *desfile,int update);
     void connect1(char *sorfile, char *desfile);
     void re1(char *sorfile, char *desfile);
      void movefile1(char *sorfile, char *desfile);
        void movefile(char *sorfile, char *desfile);
     void cp_u1(char *sorfile, char *desfile,int update);
int main(){

	while(1){
    char cwd[1000];
    char *input;
    char *username=getlogin();
    char hostname[1000];
    gethostname(hostname,sizeof(hostname));
    getcwd(cwd,sizeof(cwd));
     strcat(username,"@");
     strcat(username,hostname);
     strcat(username,":~");
     strcat(username,cwd);
     strcat(username,"$ ");
	input=readline(username);
	char *argv[6];
	argv[0]=strtok(input," ");
	argv[1]=strtok(NULL," ");
	argv[2]=strtok(NULL," ");
	argv[3]=strtok(NULL," ");
	argv[4]=strtok(NULL," ");
	if(strlen(input)!=0){
	add_history(input);}
 if(strcmp(input,"exit")==0){
	 break;}
	  if(strcmp(argv[0],"ls")==0 && argv[1]==NULL){
   DIR *currstr25;
    struct dirent *current25;
    char *path25 ="./";
currstr25=opendir(path25);

    if (currstr25 == NULL) {
        perror("opendir");
    }

    while ((current25 = readdir(currstr25)) != NULL) {
	     if (current25->d_name[0] == '.') {
		     continue;}
            printf("%s\n", current25->d_name);}
    closedir(currstr25);}

 if(strcmp(argv[0],"man") ==0)
 {
 	if(strcmp(argv[1],"ls") == 0)
 	{
 		char star[100];
 		FILE *moon;
 		moon = fopen("ls.txt","r");
 		while(fgets(star,100,moon) != NULL)
 		{
 			printf("%s",star);
 		}
 		fclose(moon);
 		printf("\n");
 	}
 	if(strcmp(argv[1],"ps") == 0)
 	{
 		char star[100];
 		FILE *moon;
 		moon = fopen("ps.txt","r");
 		while(fgets(star,100,moon) != NULL)
 		{
 			printf("%s",star);
 		}
 		fclose(moon);
 		printf("\n");
 	}
 	if(strcmp(argv[1],"cp") == 0)
 	{
 		char star[100];
 		FILE *moon;
 		moon = fopen("cp.txt","r");
 		while(fgets(star,100,moon) != NULL)
 		{
 			printf("%s",star);
 		}
 		fclose(moon);
 		printf("\n");
 	}
 	if(strcmp(argv[1],"mv") == 0)
 	{
 		char star[100];
 		FILE *moon;
 		moon = fopen("mv.txt","r");
 		while(fgets(star,100,moon) != NULL)
 		{
 			printf("%s",star);
 		}
 		fclose(moon);
 		printf("\n");
 	}
 	if(strcmp(argv[1],"grep") == 0)
 	{
 		char star[100];
 		FILE *moon;
 		moon = fopen("grep.txt","r");
 		while(fgets(star,100,moon) != NULL)
 		{
 			printf("%s",star);
 		}
 		fclose(moon);
 		printf("\n");
 	}
 	
 }
 
 
 if(strcmp(argv[0],"ps")==0 && strcmp(argv[1],"-A")==0){
 myps1();}
 if(strcmp(argv[0],"ps")==0 && argv[1]==NULL){
 myps2();}
 if(strcmp(argv[0],"ps")==0 && strcmp(argv[1],"-af")==0){
 myps3();}
 
 

   

	 if(strcmp(argv[0],"ls")==0 && strcmp(argv[1],"-a")==0){
  myls1();}
	  if(strcmp(argv[0],"ls")==0 && strcmp(argv[1],"-l")==0){
	  myls4();}
	   if(strcmp(argv[0],"ls")==0 && strcmp(argv[1],"-o")==0){
	   myls3();}
	  if(strcmp(argv[0],"ls")==0 && strcmp(argv[1],"-g")==0) {
  myls5();}
 

          if(strcmp(input,"ps")==0  && strcmp(argv[1],"-f")==0){
          myps4();}
          if  ( strcmp(argv[0],"ps")==0 && strcmp(argv[1],"-p")==0 ) {
            int pid = atoi(argv[2]);
          myps5(pid);}
          
  	 
   int overwrite=1;
   int update=0;
   if  ( strcmp(argv[0],"cp")==0 && strcmp(argv[1], "-n") == 0) {

          char *sorfile = argv[2];
    char *desfile = argv[3];
overwrite=0;
re(sorfile,desfile, overwrite);	}	
		  if (strcmp(argv[0],"cp")==0 && strcmp(argv[1],"-u")==0) {

          char *sorfile = argv[2];
    char *desfile = argv[3];
update=1;
cp_u(sorfile,desfile,update); }
    if(strcmp(argv[0],"cp")==0 && strcmp(argv[1],"-v")==0){
    char *sorfile =argv[2];
    char * desfile= argv[3];
    copyfile(sorfile, desfile);
    printf("%s -> %s", sorfile,desfile);}
    	  if (strcmp(argv[0],"cp")==0 && strcmp(argv[1],"-i")==0) {

          char *sorfile = argv[2];
    char *desfile = argv[3];
  
        connect(sorfile,desfile);}

    if (strcmp(argv[0],"cp")==0 && argv[3] == NULL ) {
    char *sorfile =argv[1];
    char *desfile = argv[2];

    copyfile(sorfile, desfile);}

    if(strcmp(argv[0],"mv")==0 && argv[3]==NULL){

    char *sorfile = argv[1];
    char *desfile = argv[2];

    movefile(sorfile, desfile);}              
      if ( strcmp(argv[0],"mv")==0 && strcmp(argv[1],"-n")==0) {

        char *sorfile = argv[2];
    char *desfile = argv[3];
re1(sorfile,desfile); }
int update1=0;
                  if (strcmp(argv[0],"mv")==0 && strcmp(argv[1],"-u")==0) {
          char *sorfile = argv[2];
    char *desfile = argv[3];
update1=1;
cp_u1(sorfile,desfile,update1); }

 if (strcmp(argv[0],"mv")==0 &&strcmp(argv[1],"-v")==0) {

          char *sorfile = argv[2];
    char *desfile = argv[3];

    movefile1(sorfile, desfile);
    
    }
                   if (strcmp(argv[0],"mv")==0 && strcmp(argv[1],"-i")==0) {

          char *sorfile = argv[2];
    char *desfile = argv[3];
connect1(sorfile,desfile);
}
 if (strcmp(argv[0],"grep")==0 && argv[3] == NULL) {
   char *sorfile = argv[1];
    char *desfile = argv[2];
 mygrep1(sorfile,desfile);
 
 }
 if (strcmp(argv[0],"grep")==0 && strcmp(argv[1],"-n")==0) {
   char *sorfile = argv[2];
    char *desfile = argv[3];
 mygrep2(sorfile,desfile);
 
 } 
  if (strcmp(argv[0],"grep")==0 && strcmp(argv[1],"-v")==0) {
   char *sorfile = argv[2];
    char *desfile = argv[3];
 mygrep3(sorfile,desfile);
 
 }
  if (strcmp(argv[0],"grep")==0 && strcmp(argv[1],"-c")==0) {
   char *sorfile = argv[2];
    char *desfile = argv[3];
 mygrep4(sorfile,desfile);
 }
 if (strcmp(argv[0],"grep")==0 && strcmp(argv[1],"-l")==0) {
   char *sorfile = argv[2];
    char *desfile = argv[3];
 mygrep5(sorfile,desfile);
 
 }    
 
 }
	return 0;
}
