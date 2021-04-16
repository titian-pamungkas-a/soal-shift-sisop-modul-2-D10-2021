#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

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
        //move();
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

int main() {
  pid_t child_id;
  int status;

  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE);
  }
  if (child_id == 0) {
    // this is child
    char *argv[] = {"mkdir", "-p", "Musyik", "Pyoto", "Fylm", NULL};
    execv("/bin/mkdir", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
    download();
  }
}
