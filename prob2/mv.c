#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
void connect1(char *sorfile, char *desfile) {
 struct stat s;
    if (stat(sorfile, &s) == -1) {
        printf("Error: Cannot stat file '%s': No such file or directory\n", sorfile);
        return;
    }

    struct stat dest1;
    int destexist1 = stat(desfile, &dest1) == 0;
    int copy1 = 1;

    if (destexist1) {
        char response;
        printf("File '%s' already exists. Do you want to overwrite? (y/n): ",desfile);
        fflush(stdout);
        scanf(" %c", &response);
        response = tolower(response);
        if (response != 'y') {
            copy1 = 0;
        }
    }

    if (!copy1) {
        printf("'%s' is up to date\n", desfile);
     
    }

    if (rename(sorfile, desfile) == -1) {
        printf("Error: Cannot rename file '%s' to '%s'\n", sorfile, desfile);
        return;
      
    }
   }
   void movefile(char *sorfile, char *desfile) {

    struct stat s;
    if (stat(sorfile, &s) == -1) {
        printf("Error: Cannot stat file '%s' : No such file or directory", sorfile);
    }

    if (access(desfile, F_OK) == 0) {
        }


    if (rename(sorfile, desfile) == -1) {
        printf("Error: Cannot move file '%s' to '%s'\n", sorfile, desfile);
    }}
 void movefile1(char *sorfile, char *desfile) {

    struct stat s;
    if (stat(sorfile, &s) == -1) {
        printf("Error: Cannot stat file '%s' : No such file or directory", sorfile);
    }

    if (access(desfile, F_OK) == 0) {
        }


    if (rename(sorfile, desfile) == -1) {
        printf("Error: Cannot move file '%s' to '%s'\n", sorfile, desfile);
    }
     printf("'%s' -> '%s'\n", sorfile, desfile);}

 void cp_u1(char *sorfile, char *desfile,int update1) {

    struct stat s;
    if (stat(sorfile, &s) == -1) {
        printf("Error: Cannot stat file '%s' : No such file or directory", sorfile);
    }

        
        struct stat dest1;
    int destexist1 = stat(desfile, &dest1) == 0;
    int copy1 = 1;

    if (update1 && destexist1) {
        time_t sourcemod1 = s.st_mtime;
        time_t destmod1 = dest1.st_mtime;
        if (difftime(destmod1, sourcemod1) >= 0) {
            copy1 = 0;
        }
    }

    if (!copy1) {
        printf("'%s' is up to date\n", desfile);
        return;
    }
  

    if (rename(sorfile, desfile) == -1) {
        printf("Error: Cannot rename file '%s' to '%s'\n", sorfile, desfile);
   
    }}
void re1(char *sorfile, char *desfile) {

    struct stat s;
    if (stat(sorfile, &s) == -1) {
        printf("Error: Cannot stat file '%s' : No such file or directory\n", sorfile);
    return;
    }

        if (access(desfile, F_OK) == 0) {
        printf("Destination file already exists, file not moved.\n");
        return;
    
    }

    if (rename(sorfile, desfile) == -1) {
        printf("Error: Cannot move file '%s' to '%s'\n", sorfile, desfile);
     
    }}


