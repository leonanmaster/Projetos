#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(){
	char input_buffer[1024];
	char *args[20];
	int status;
	while(1){
		int i = 0;

		printf(">");
		fgets(input_buffer, sizeof(input_buffer), stdin);
		
		char *token = strtok(input_buffer, " \n");
		while(token != NULL){	
			args[i++] = token;
			token = strtok(NULL, " \n");
		
		}
		args[i] = NULL; //O ARRAY PRECISA TERMINAR COM NULL
		
		if (args[0] == NULL){
			continue;
		}
		
		// TRATAMENTO DE COMANDOS INTERNOS:
		if(strcmp(args[0], "exit") == 0){
			exit(0);
		}else if(strcmp(args[0], "cd") == 0){
			if(chdir(args[1]) != 0){
				perror("Há algo de errado com esse diretorio, oh mestre.\n");
			}
		}				
		// TRATAMENTO DE COMANDOS EXTERNOS:
		else{ 
			pid_t pid = fork();

			if (pid == 0){
				execvp(args[0], args);
				perror("Impossível realizar tal tarefa, oh mestre - ");
				exit(1);	
				
			} else if (pid > 0){
				wait(&status);	
				
			}else {
				printf("ERROOOO");

			}
		}
	}
	return 0;
}
