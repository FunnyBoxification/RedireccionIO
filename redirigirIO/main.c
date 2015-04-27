/*
 * main.c
 *
 *  Created on: 27/4/2015
 *      Author: utnso
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>


int main(int argc, char** argv) {
	pid_t pid;
	int status = 0;

	pid = fork();
	if(pid == 0) { //hijo
		FILE* entrada = fopen("entrada.txt","r");
		FILE* salida = fopen("salida.txt","w");

		dup2(fileno(entrada),0);
		dup2(fileno(salida),1);

		system("/home/utnso/workspace/redirigirIO/script.sh");
	}
	else {
		wait(&status);
		exit(0);
	}

	return 0;
}
