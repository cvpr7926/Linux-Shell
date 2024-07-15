#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
int copyfile(char *sorfile, char *desfile) {
    
 struct stat s;
    if (stat(sorfile, &s) == -1) {
        printf("Error: Cannot stat file '%s' : No such file or directory", sorfile);
    }
    mode_t mode = s.st_mode;


    int sor1 = open(sorfile, O_RDONLY);
    if (sor1 == -1) {
        printf("Error: Permission denied for reading %s\n", sorfile);
    }


    int des1 = open(desfile, O_WRONLY | O_CREAT, mode);
    if (des1 == -1) {
        printf("Error: Cannot create file %s\n", desfile);
    }


    char tank[1000];
    ssize_t Read;
    while ((Read = read(sor1, tank, sizeof(tank))) > 0) {
        if (write(des1, tank, Read) != Read) {
            printf("Error: Writing error on %s\n", desfile);
        }
    }
    close(sor1);
    close(des1);


}
void connect(char *sorfile, char *desfile) {

    struct stat s;
    if (stat(sorfile, &s) == -1) {
        printf("Error: Cannot stat file '%s' : No such file or directory", sorfile);
    }
    mode_t mode = s.st_mode;


    int sor1 = open(sorfile, O_RDONLY);
    if (sor1 == -1) {
        printf("Error: Permission denied for reading %s\n", sorfile);
    }

 if (access(desfile, F_OK) == 0) {
        char response;
        printf("Destination file '%s' already exists. Do you want to overwrite it? (y/n): ", desfile);
        scanf(" %c", &response);

        if (response != 'y') {
            printf("Operation canceled by user.\n");
            close(sor1);
           
        }
    }
    int des1 = open(desfile, O_WRONLY | O_CREAT, mode);
    if (des1 == -1) {
        printf("Error: Cannot create file %s\n", desfile);
    }

	 char tank[1000];
    ssize_t Read;
    while ((Read = read(sor1, tank, sizeof(tank))) > 0) {
        if (write(des1, tank, Read) != Read) {
            printf("Error: Writing error on %s\n", desfile);
        }
    }


    close(sor1);
    close(des1);

}
void re(char *sorfile, char *desfile,int overwrite) {
    struct stat s;
    if (stat(sorfile, &s) == -1) {
        printf("Error: Cannot stat file '%s' : No such file or directory", sorfile);
    }
    mode_t mode = s.st_mode;


    int sor1 = open(sorfile, O_RDONLY);
    if (sor1 == -1) {
        printf("Error: Permission denied for reading %s\n", sorfile);
    }
if (!overwrite && stat(desfile, &s) == 0) {
        return;
    }

    int des1 = open(desfile, O_WRONLY | O_CREAT, mode);
    if (des1 == -1) {
        printf("Error: Cannot create file %s\n", desfile);
    }

	 char tank[1000];
    ssize_t Read;
    while ((Read = read(sor1, tank, sizeof(tank))) > 0) {
        if (write(des1, tank, Read) != Read) {
            printf("Error: Writing error on %s\n", desfile);
        }
    }


    close(sor1);
    close(des1);

}

void cp_u(char *sorfile, char *desfile,int update) {

    struct stat s;
    if (stat(sorfile, &s) == -1) {
        printf("Error: Cannot stat file '%s' : No such file or directory", sorfile);
    }
    mode_t mode = s.st_mode;
     struct stat dest;
    int destexist = stat(desfile, &dest) == 0;
    int copy = 1;

    if (update && destexist) {
        time_t sourcemod = s.st_mtime;
        time_t destmod = dest.st_mtime;
        if (difftime(destmod, sourcemod) >= 0) {
            copy = 0;
        }
    }

    if (!copy) {
        printf("'%s' is up to date\n", desfile);
        return;
    }


    int sor1 = open(sorfile, O_RDONLY);
    if (sor1 == -1) {
        printf("Error: Permission denied for reading %s\n", sorfile);
    }


    int des1 = open(desfile, O_WRONLY | O_CREAT, mode);
    if (des1 == -1) {
        printf("Error: Cannot create file %s\n", desfile);
    }


    char tank[1000];
    ssize_t Read;
    while ((Read = read(sor1, tank, sizeof(tank))) > 0) {
        if (write(des1, tank, Read) != Read) {
            printf("Error: Writing error on %s\n", desfile);
        }
    }
    close(sor1);
    close(des1);

}




