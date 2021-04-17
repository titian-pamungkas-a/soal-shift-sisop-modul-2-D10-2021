#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>
#include <stdio.h>

void zip(){
  char texta[100];
  time_t nowa = time(NULL);
  struct tm *ta = localtime(&nowa);
  strftime(texta, sizeof(texta)-1, "%d-%m_%H:%M", ta);
  while (strcmp(texta, "09-04_22:22") != 0){
    nowa = time(NULL);
    ta = localtime(&nowa);
    strftime(texta, sizeof(texta)-1, "%d-%m_%H:%M", ta);
    sleep(1);
  }
  pid_t zipp;
  int zipstat;
  zipp = fork();
  if (zipp < 0) {
    exit(EXIT_FAILURE);
  }
  if (zipp == 0){
    execl("usr/bin/zip", "zip", "Lopyu_Stevany","Fylm", "Musyik", "Pyoto", NULL);
  }else {
    while ((wait(&zipstat)) > 0);
    pid_t rm1;
    int removestat1;
    rm1 = fork();
    if (rm1 < 0) {
      exit(EXIT_FAILURE);
    }
    if (rm1 == 0){
      execl("/bin/rm", "rm", "Pyoto", NULL);
    }else{
      while ((wait(&removestat1)) > 0);
      pid_t rm2;
      int removestat2;
      rm2 = fork();
      if (rm2 < 0) {
        exit(EXIT_FAILURE);
      }
      if (rm2 == 0){
        execl("/bin/rm", "rm", "Fylm", NULL);
      }else{
        while ((wait(&movestat3)) > 0);
        execl("/bin/rm", "rm", "Musyik", NULL);
      }
    }
  }
}

void move(){
  pid_t move1;
  int movestat1;
  move1 = fork();
  
  
  if (move1 < 0) {
    exit(EXIT_FAILURE);
  }
  if (move1 == 0){
    execl("/bin/mv", "mv", "-T","MUSIK/", "Musyik", NULL);
  }else {
    while ((wait(&movestat1)) > 0);
    pid_t move2;
    int movestat2;
    move2 = fork();
    if (move2 < 0) {
      exit(EXIT_FAILURE);
    }
    if (move2 == 0){
      execl("/bin/mv", "mv", "-T","FOTO/", "Pyoto", NULL);
    }else{
      while ((wait(&movestat2)) > 0);
      pid_t move3;
      int movestat3;
      move3 = fork();
      if (move3 < 0) {
        exit(EXIT_FAILURE);
      }
      if (move3 == 0){
        execl("/bin/mv", "mv", "-T", "FILM/", "Fylm", NULL);
      }else{
        while ((wait(&movestat3)) > 0);
        zip();
      }
    }
  }
}

void unzip(){
  pid_t zip1;
  int zipstat1;
  zip1 = fork();
  
  
  if (zip1 < 0) {
    exit(EXIT_FAILURE);
  }
  if (zip1 == 0){
    execl("/usr/bin/unzip", "unzip", "Musik_for_Stevany.zip", NULL);
  }else {
    while ((wait(&zipstat1)) > 0);
    pid_t zip2;
    int zipstat2;
    zip2 = fork();
    if (zip2 < 0) {
      exit(EXIT_FAILURE);
    }
    if (zip2 == 0){
      execl("/usr/bin/unzip", "unzip", "Foto_for_Stevany.zip", NULL);
    }else{
      while ((wait(&zipstat2)) > 0);
      pid_t zip3;
      int zipstat3;
      zip3 = fork();
      if (zip3 < 0) {
        exit(EXIT_FAILURE);
      }
      if (zip3 == 0){
        execl("/usr/bin/unzip", "unzip", "Film_for_Stevany.zip", NULL);
      }else{
        while ((wait(&zipstat3)) > 0);
        move();
      }
    }
  }
}
/*
void change(){
  pid_t changemodd;
  int stats;
  changemodd = fork();
  if (changemodd < 0){
    exit(EXIT_FAILURE);
  }
  if (changemodd == 0){
    char *argv[] = {"chmod". "-R", "777", "/home/tito/soal2"};
}*/

void download(){
  pid_t down1;
  int downstat1;
  down1 = fork();
  
  
  if (down1 < 0) {
    exit(EXIT_FAILURE);
  }
  if (down1 == 0){
    execl("/usr/bin/wget", "wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", NULL);
  }else {
    while ((wait(&downstat1)) > 0);
    pid_t down2;
    int downstat2;
    down2 = fork();
    if (down2 < 0) {
      exit(EXIT_FAILURE);
    }
    if (down2 == 0){
      execl("/usr/bin/wget", "wget", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", NULL);
    }else{
      while ((wait(&downstat2)) > 0);
      pid_t down3;
      int downstat3;
      down3 = fork();
      if (down3 < 0) {
        exit(EXIT_FAILURE);
      }
      if (down3 == 0){
        execl("/usr/bin/wget", "wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", NULL);
      }else{
        while ((wait(&downstat3)) > 0);
        unzip();
      }
    }
  }
}

void folder(){
  pid_t fold;
  int foldstat;
  fold = fork();
  if (fold < 0) {
    exit(EXIT_FAILURE);
  }
  if (fold == 0) {
    char *argv[] = {"mkdir", "-p", "Musyik", "Pyoto", "Fylm", NULL};
    execv("/bin/mkdir", argv);
  } else {
    while ((wait(&foldstat)) > 0);
    download();
  }
}

int main() {
  pid_t pid, sid;        // Variabel untuk menyimpan PID

  pid = fork();     // Menyimpan PID dari Child Process

  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while (1) {
    char text[100];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(text, sizeof(text)-1, "%d-%m_%H:%M", t);
    while (strcmp(text, "09-04_16:22") != 0){
      now = time(NULL);
      t = localtime(&now);
      strftime(text, sizeof(text)-1, "%d-%m_%H:%M", t);
      sleep(1);
    }
    
    pid_t child_id;
    int status;

    child_id = fork();

    if (child_id < 0) {
      exit(EXIT_FAILURE);
    }
    if (child_id == 0) {
      folder();
    } else {
      while ((wait(&status)) > 0);
      //
      
    }
    

    sleep(30);
  }
}
