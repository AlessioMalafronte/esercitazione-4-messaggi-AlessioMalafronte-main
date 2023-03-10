#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "header.h"


void Client(int msg_id_balancer) {

	int i;
	int ret;

	for(i=0; i<TOTALE_MESSAGGI; i++) {

		/* TBD: Inviare il messaggio del client */
		struct messaggi msg;

		msg.pid_mittente = getpid();

		printf("Client %d: invio messaggio numero %d\n", getpid(), i);

		ret = msgsnd(msg_id_balancer, &msg, sizeof(struct messaggi) - sizeof(long), 0);

		if(ret < 0) {

			perror("Errore msgsnd() client");
			exit(1);
		}
	}
}


void Balancer(int msg_id_balancer, int msg_id_server[]) {

	int i;
	int ret;


	/*
	  La variabile "server" indica il prossimo server a cui
	  verrà inviato un messaggio. Il primo messaggio viene 
	  inviato al server n.0, il secondo messaggio al server n.1,
	  il terzo messaggio al server n.2, e poi si ripete a partire
	  da 0.
	*/

	int server = 0;


	for(i=0; i<TOTALE_MESSAGGI*TOTALE_CLIENT; i++) {

		/* TBD: Ricevere un messaggio dai client */

		struct messaggi msg;

		/* TBD */

		ret = msgrcv(msg_id_balancer, &msg, sizeof(struct messaggi) - sizeof(long), 0, 0);

		if(ret < 0) {

			perror("Errore msgrcv() balancer");
			exit(1);
		}

		printf("Balancer: ricezione messaggio dal processo %d, invio al server %d\n", msg.pid_mittente ,server+1);



		/* TBD: Inviare il messaggio all'i-esimo server */

 		/* TBD */

		ret = msgsnd(msg_id_server[server], &msg, sizeof(struct messaggi)- sizeof(long), 0);

		if(ret < 0) {

			perror("Errore msgsnd() balancer");
			exit(1);
		}



		/*
		  Aggiorna la variabile server con la divisione in modulo
		*/

		server = (server + 1) % TOTALE_SERVER;
	}

}


void Server(int msg_id_server) {

	int i;
	int ret;


	/*
	  Ciascun server effettua un numero di ricezioni prefissato
	  e poi termina.

	  Nota bene: il programma è scritto in modo che il numero totale di
	  messaggi sia esattamente un multiplo del numero di server
	*/

	for(i=0; i<TOTALE_MESSAGGI*TOTALE_CLIENT/TOTALE_SERVER; i++) {


		/* TBD: Ricevere un messaggio dal load balancer */

		struct messaggi msg;

		/* TBD */

		ret = msgrcv(msg_id_server, &msg, sizeof(struct messaggi) - sizeof(long), 0, 0);
	
		printf("Server %d: ricezione messaggio numero %d dal processo %d\n", getpid(), i, msg.pid_mittente);

		if(ret < 0) {

			perror("Errore msgrcv() server");
			exit(1);
		}
	}
}

  
