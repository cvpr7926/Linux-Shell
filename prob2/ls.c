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
#include <pwd.h>
#include <grp.h>


	int  myls1(){

  DIR *currstr;
    struct dirent *current;
    char *path ="./";
currstr=opendir(path);

    if (currstr == NULL) {
        perror("opendir");
        return 1;
    }

    while ((current = readdir(currstr)) != NULL) {
            printf("%s\n", current->d_name);}
    closedir(currstr);}
    int myls3(){
  DIR *currstr;
    struct dirent *current;
    char *path ="./";
    struct stat s;
currstr=opendir(path);

    if (currstr == NULL) {
        perror("opendir");
        return 1;
    }

    while ((current = readdir(currstr)) != NULL) {
	    if(stat(current->d_name,&s)==-1){
		    perror("stat");
		    exit(EXIT_FAILURE);}
             printf((S_ISDIR(s.st_mode)) ? "d" : "-");
    printf((s.st_mode & S_IRUSR) ? "r" : "-");
    printf((s.st_mode & S_IWUSR) ? "w" : "-");
    printf((s.st_mode & S_IXUSR) ? "x" : "-");
    printf((s.st_mode & S_IRGRP) ? "r" : "-");
    printf((s.st_mode & S_IWGRP) ? "w" : "-");
    printf((s.st_mode & S_IXGRP) ? "x" : "-");
    printf((s.st_mode & S_IROTH) ? "r" : "-");
    printf((s.st_mode & S_IWOTH) ? "w" : "-");
    printf((s.st_mode & S_IXOTH) ? "x" : "-");

    printf(" %2ld", s.st_nlink);

    printf(" %s", getpwuid(s.st_uid)->pw_name);

    printf(" %8ld", s.st_size);
    char time[80];
    strftime(time, 80, "%b %d %H:%M", localtime(&s.st_mtime));
    printf(" %s", time);


            printf(" %s\n", current->d_name);}
    closedir(currstr);}
     int myls4(){
  DIR *currstr;
    struct dirent *current;
    char *path ="./";
    struct stat s;
currstr=opendir(path);

    if (currstr == NULL) {
        perror("opendir");
        return 1;
    }

    while ((current = readdir(currstr)) != NULL) {
	    if(stat(current->d_name,&s)==-1){
		    perror("stat");
		    exit(EXIT_FAILURE);}
             printf((S_ISDIR(s.st_mode)) ? "d" : "-");
    printf((s.st_mode & S_IRUSR) ? "r" : "-");
    printf((s.st_mode & S_IWUSR) ? "w" : "-");
    printf((s.st_mode & S_IXUSR) ? "x" : "-");
    printf((s.st_mode & S_IRGRP) ? "r" : "-");
    printf((s.st_mode & S_IWGRP) ? "w" : "-");
    printf((s.st_mode & S_IXGRP) ? "x" : "-");
    printf((s.st_mode & S_IROTH) ? "r" : "-");
    printf((s.st_mode & S_IWOTH) ? "w" : "-");
    printf((s.st_mode & S_IXOTH) ? "x" : "-");

    printf(" %2ld", s.st_nlink);

    printf(" %s", getpwuid(s.st_uid)->pw_name);
    printf(" %s",getgrgid(s.st_gid)->gr_name);

    printf(" %8ld", s.st_size);
    char time[80];
    strftime(time, 80, "%b %d %H:%M", localtime(&s.st_mtime));
    printf(" %s", time);


            printf(" %s\n", current->d_name);}
    closedir(currstr);}
     int myls5(){
  DIR *currstr;
    struct dirent *current;
    char *path ="./";
    struct stat s;
currstr=opendir(path);

    if (currstr == NULL) {
        perror("opendir");
        return 1;
    }

    while ((current = readdir(currstr)) != NULL) {
	    if(stat(current->d_name,&s)==-1){
		    perror("stat");
		    exit(EXIT_FAILURE);}
             printf((S_ISDIR(s.st_mode)) ? "d" : "-");
    printf((s.st_mode & S_IRUSR) ? "r" : "-");
    printf((s.st_mode & S_IWUSR) ? "w" : "-");
    printf((s.st_mode & S_IXUSR) ? "x" : "-");
    printf((s.st_mode & S_IRGRP) ? "r" : "-");
    printf((s.st_mode & S_IWGRP) ? "w" : "-");
    printf((s.st_mode & S_IXGRP) ? "x" : "-");
    printf((s.st_mode & S_IROTH) ? "r" : "-");
    printf((s.st_mode & S_IWOTH) ? "w" : "-");
    printf((s.st_mode & S_IXOTH) ? "x" : "-");

    printf(" %2ld", s.st_nlink);

    printf(" %s",getgrgid(s.st_gid)->gr_name);

    printf(" %8ld", s.st_size);
    char time[80];
    strftime(time, 80, "%b %d %H:%M", localtime(&s.st_mtime));
    printf(" %s", time);


            printf(" %s\n", current->d_name);}
    closedir(currstr);}
