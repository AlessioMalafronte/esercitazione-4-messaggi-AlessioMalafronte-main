#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "header.h"

int main() {

	int msg_id_balancer;
	int msg_id_server[TOTALE_SERVER];
	int i;
	pid_t p;
	int status;
	int ret;



	/*
	  TBD: Creare una coda per i messaggi dai client
	  verso il balancer
	*/

	key_t chiave_client = IPC_PRIVATE;

	msg_id_balancer = msgget(chiave_client, IPC_CREAT | 0644);

	if(msg_id_balancer < 0) {

		perror("Errore msgget() coda balancer");
		exit(1);
	}



	/*
	  TBD: Creare 3 code per i messaggi dal balancer verso
	  i server, una coda per ogni server
	*/

	for(i=0; i<TOTALE_SERVER; i++) {

		msg_id_server[i] = msgget(IPC_PRIVATE, IPC_CREAT | 0644);

		if(msg_id_server[i] < 0) {

			perror("Errore msgget() coda server");
			exit(1);
		}
	}



	/*
	  TBD: Creare i processi client, passando alla funzione Client()
	  in ingresso lo ID della coda del balancer
	*/

	for(i=0; i<TOTALE_CLIENT; i++) {

		p = fork();

		if(p == 0){

			Client(msg_id_balancer);

			exit(0);

		}
		if(p<0){
			perror("Errore fork client");
			exit(1);
		}
	}



	/*
	  TBD: Creare i processi server, passando alla funzione Server()
	  in ingresso lo ID della coda di quel server
	*/

	for(i=0; i<TOTALE_SERVER; i++) {

		p = fork();

		if(p == 0){

			Server(msg_id_server[i]);

			exit(0);

		}if(p < 0){
			perror("Errore fork server");
			exit(1);
		}

	}



	/*
	  TBD: Creare il processo balancer, passando alla funzione Balancer()
	in ingresso gli ID di tutte le code
	*/
	p = fork();

	if(p == 0){
		Balancer(msg_id_balancer, msg_id_server);

		exit(0);
	}
	if(p < 0){

		perror("Errore fork balancer");

		exit(1);
	}


	/*
	  TBD: Il processo padre si pone in attesa della terminazione
	  di tutti i processi (client, server e balancer)
	*/

	for(i=0; i<TOTALE_CLIENT+TOTALE_SERVER+1; i++) {

		/* TBD */
		wait(NULL);

	}



	/*
	  TBD: Rimozione delle code dal sistema
	*/

	ret = msgctl(msg_id_balancer, IPC_RMID, NULL);

	if(ret < 0){
		perror("Errore msgctl server");
		exit(1);
	}

	for(int i = 0; i < TOTALE_SERVER; i++){
		
		ret = msgctl(msg_id_server[i], IPC_RMID, NULL);

		if(ret < 0){
			perror("Errore msgctl server");
			exit(1);
		}

	}

	return 0;

}

  
