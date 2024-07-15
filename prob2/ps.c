#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <time.h>
#include <sys/sysinfo.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <readline/readline.h>
#include <readline/history.h>
#include<sched.h>
#include<pwd.h>

       void myps1() {
    DIR* currstr;
    struct dirent* current;
    if ((currstr = opendir("/proc")) == NULL) {
        perror("opendir");
        return;
    }
    while ((current = readdir(currstr)) != NULL) {
        if (current->d_type == DT_DIR) {
            char path[1000000];
            snprintf(path, sizeof(path), "/proc/%s/status", current->d_name);
            FILE* file;
            if ((file = fopen(path, "r")) != NULL) {
                char line[1000000];
                char name[1000];
                char tty_name[1000];
                int pid;
                int utime, stime;
                int status;
                int tty_nr;
                struct stat statbuf;

                if (sscanf(current->d_name, "%d", &pid) == 1) {
                    snprintf(path, sizeof(path), "/proc/%s/fd/0", current->d_name);
                    if (stat(path, &statbuf) == 0) {
                        if (S_ISCHR(statbuf.st_mode)) {
                            sprintf(tty_name, "/dev/%s", ttyname(statbuf.st_rdev));
                        } else {
                            strcpy(tty_name, "?");
                        }
                    } else {
                        strcpy(tty_name, "?");
                    }
                }

                while (fgets(line, sizeof(line), file) != NULL) {
                    if (sscanf(line, "Name: %s", name) == 1) {
                        break;
                    }
                }
                fseek(file, 0, SEEK_SET);  // Reset the file pointer to read from the beginning

                while (fgets(line, sizeof(line), file) != NULL) {
                    if (sscanf(line, "State: %d", &status) == 1) {
                        break;
                    }
                }

                if (status != -1) {
                    time_t now = time(NULL);
                    struct tm* timenow = localtime(&now);
                    char time[10];
                    strftime(time, sizeof(time), "%H:%M", timenow);
                    printf("%-8d %c%-10s %2d:%-5ld - %-10s\n", pid, (status == 0) ? 'R' : 'S', tty_name, utime, now % 60, name);
                }
                fclose(file);
            }
        }
    }
    closedir(currstr);
}

int myps2(){
         DIR *currstr;
    struct dirent *current;
    if ((currstr = opendir("/proc")) == NULL) {
        perror("opendir");
        return 1;
    }
    printf("%-8s %-8s  %-8s %-8s  %-10s %-10s %-10s %-10s\n","UID","PID","PPID","C","STIME","TTY", "TIME","CMD");
   
    while ((current = readdir(currstr)) != NULL) {
        if (current->d_type == DT_DIR) {
            char path[1000000];
            snprintf(path, sizeof(path), "/proc/%s/status", current->d_name);
            FILE *file;
            if ((file = fopen(path, "r")) != NULL) {
                char paths[1000];
                snprintf(paths, sizeof(paths), "/proc/%s/fd/0", current->d_name);
                if (access(paths, F_OK) != 0) {
                    continue;
                }
                int proceed;
                if ((proceed = open(paths, O_RDWR)) < 0) {
                    continue;
                }
                if (ttyname(proceed) == NULL) {
                    continue;
                    close(proceed);
                }
                char line[10000];
                char name[1000];
                int status;
                int utime, stime;
                int tty_nr;
                int tty_fd = -1;
                struct user_info;
                int ppid;
                
                while (fgets(line, sizeof(line), file) != NULL) {
                    if (sscanf(line, "Name: %s", name) == 1) {
                        sscanf(current->d_name, "%d", &ppid);
                    }

                    if (sscanf(line, "State: %d", &status) == 1) {
                        break;
                    }
                    sscanf(line, "%*d %*s %*c %d", &tty_nr);
                    if (sscanf(line, "utime: %d", &utime) == 1) {
                        utime /= sysconf(_SC_CLK_TCK);
                    }
                    if (sscanf(line, "stime: %d", &stime) == 1) {
                        stime /= sysconf(_SC_CLK_TCK);
                    }
                }
                fclose(file);
                if ( status != -1) {
                 if ((tty_fd = open(paths, O_RDWR)) != -1) { 
                        char *tty_name = ttyname(tty_fd);
                    printf("%-8d %-10s %2d:%-5ld -%-10s\n", ppid, (tty_nr == 0) ? "?" : tty_name, utime, time(NULL) % 60, name);
                }
            }
        }
    }
    closedir(currstr);
}
    return 0;
}
int myps3(){
	 DIR *currstr;
    struct dirent *current;
    if ((currstr = opendir("/proc")) == NULL) {
        perror("opendir");
        return 1;
    }
    printf("%-8s %-8s  %-8s %-8s  %-10s %-10s %-10s %-10s\n","UID","PID","PPID","C","STIME","TTY", "TIME","CMD");
    while ((current = readdir(currstr)) != NULL) {
    if (current->d_type == DT_DIR) {
            char path[1000000];
            snprintf(path, sizeof(path), "/proc/%s/status", current->d_name);
            FILE *file;
            if ((file = fopen(path, "r")) != NULL) {
                char line[1000000];
                char name[1000];
		char name1[1000];
                char pwd[1000];
                char status1[1000];
		int status;
                int utime, stime;
		int uid;
		int core;
                int tty_nr;
		 int processor;
		 struct user_info;
		 int  ppid;
		 int  pid;
int tty_fd = open("/dev/tty", O_RDONLY);
if (tty_fd == -1) {
    perror("open");
}
    char *tty_name = (tty_nr == 0) ? NULL: ttyname(tty_fd);;

                while (fgets(line, sizeof(line), file) != NULL) {

			if(sscanf(line,"Uid : %d",&uid)==1){
					break;
		}
	 if (strncmp(line, "PPid:", 5) == 0) {
                           sscanf(line, "PPid:\t%d", &ppid);}
			
                    if (sscanf(line, "Name: %s", name) == 1) {
                        sscanf(current->d_name, "%d", &pid);
                    }
                    if (sscanf(line, "State: %d",&status) == 1) {
                        break;
                    }
                    if (sscanf(line, "State: %s", status1) == 1) {
                        break;
                    }
                    if (sscanf(line, "utime: %d", &utime) == 1) {
                        utime /= sysconf(_SC_CLK_TCK);
                    }
                    if (sscanf(line, "stime: %d", &stime) == 1) {
                        stime /= sysconf(_SC_CLK_TCK);
                    }}              
  struct passwd *pw = getpwuid(uid);
                if (pwd == NULL) {
                    fprintf(stderr, "Failed to get username for UID %d\n", uid);
                    continue; }
                char *username = pw->pw_name;
		fclose(file);
                if (status != -1) {
                    time_t now = time(NULL);
                    struct tm *timenow = localtime(&now);
                    char time[10];
                    strftime(time, sizeof(time), "%H:%M", timenow); 
                    printf("%-8s  %-8d  %-8d %-8s  %2d:%-5ld %c%-10s %2d:%-5ld %s\n",username,pid,ppid,status1,stime,now % 60,(tty_nr ==0)?'?':' ',(tty_name == NULL) ? " ": tty_name , utime, now % 60, name);

		}}}}}
