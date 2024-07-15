#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
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
 if(strcmp(input,"help")==0){
	 system("bash -c help");
	 continue;
 }
 else{
	 system(input);}}
	return 0;}
