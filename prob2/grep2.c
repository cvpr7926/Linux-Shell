#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<readline/readline.h>
#include<readline/history.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
int mygrep1( char* sorfile,char* desfile){
	FILE *file = fopen(desfile, "r");
char Tank[100000];
    if (file == NULL) {
        printf("Error: cannot open file\n");
        return 1;
    }

    while (fgets(Tank,100000, file) != NULL) {
        if (strstr(Tank, sorfile) != NULL) {
            printf("%s:%s",desfile,Tank);
        }
    }

    fclose(file);
}
int mygrep2( char* sorfile,char* desfile){
	int match=0;
        FILE *file = fopen(desfile, "r");
char Tank[100000];
    if (file == NULL) {
        printf("Error: cannot open file\n");
        return 1;
    }
int linenumber=0;
    while (fgets(Tank,100000, file) != NULL) {
        if (strstr(Tank, sorfile) != NULL){
            linenumber++;
            printf("%d:%s",linenumber,Tank);
        }
    }

    fclose(file);
}
int mygrep3( char* sorfile,char* desfile){
        FILE *file = fopen(desfile, "r");
char Tank[100000];
    if (file == NULL) {
        printf("Error: cannot open file\n");
        return 1;
    }

    while (fgets(Tank,100000, file) != NULL) {
        if (strstr(Tank, sorfile) == NULL) {
            printf("%s:%s",desfile,Tank);
        }
    }

    fclose(file);
}
int mygrep4( char* sorfile,char* desfile){
	int count=0;
        FILE *file = fopen(desfile, "r");
char Tank[100000];
    if (file == NULL) {
        printf("Error: cannot open file\n");
        return 1;
    }

    while (fgets(Tank,100000, file) != NULL) {
        if (strstr(Tank, sorfile) != NULL) {
            count++;
        }
    }
printf("%d\n",count);
    fclose(file);
}
int mygrep5( char* sorfile,char* desfile){
	FILE *file = fopen(desfile, "r");
char Tank[100000];
int found =0;
    if (file == NULL) {
        printf("Error: cannot open file\n");
        return 1;
    }
    while (fgets(Tank,100000, file) != NULL) {
        
          if (strstr(Tank, sorfile) != NULL) {
            printf("%s\n", desfile);
            found = 1;
            break;
        }
    }
  
    

    fclose(file);
    if (!found) {
        printf("%s: No match found.\n", desfile);
    }

}

