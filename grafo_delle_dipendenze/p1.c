#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

#include "p.h"


int main() {

	printf("Processo P1 avviato\n");



	key_t queue_operandi_1  = /* TBD: Definire la chiave per la coda 1 per gli operandi */
	key_t queue_risultati_1 = /* TBD: Definire la chiave per la coda 1 per le risposte */



	int id_operandi_1 = /* TBD: Ottenere la coda 1 per gli operandi */

	if(id_operandi_1 < 0) {
		perror("Msgget fallita");
		exit(1);
	}



	int id_risultati_1 = /* TBD: Ottenere la coda 1 per le risposte */

	if(id_risultati_1 < 0) {
		perror("Msgget fallita");
		exit(1);
	}



	srand(time(NULL));


	int i;

	for(i=0; i<3; i++) {


		int ret;

		int a = rand() % 10;
		int b = rand() % 10;
		int c = rand() % 10;
		int d = rand() % 10;
		int e = rand() % 10;
		int f = rand() % 10;
		int g = rand() % 10;
		int h = rand() % 10;

		int r1, r2, r3, risultato;



		printf("[P1] OPERANDI: a=%d, b=%d, c=%d, d=%d, e=%d, f=%d, g=%d, h=%d\n", a, b, c, d, e, f, g, h);


		/* TBD: Inviare gli operandi "a" e "b" al processo P2 sulla coda 1 degli operandi */

		printf("[P1] SEND P2\n");

		ret = /* TBD */

		if(ret<0) {
			perror("Msgsnd fallita");
			exit(1);
		}



		/* TBD: Inviare gli operandi "c", "d", "e", "f" al processo P3 sulla coda 1 degli operandi */

		printf("[P1] SEND P3\n");

		ret = /* TBD */

		if(ret<0) {
			perror("Msgsnd fallita");
			exit(1);
		}




		/* TBD: Inviare gli operandi "g" e "h" al processo P4 sulla coda 1 degli operandi */


		printf("[P1] SEND P4\n");

		ret = /* TBD */

		if(ret<0) {
			perror("Msgsnd fallita");
			exit(1);
		}



		/* TBD: Ricevere la risposta "r1" dal processo P2 sulla coda 1 delle risposte */

		printf("[P1] RECEIVE P2\n");

		ret = /* TBD */

		if(ret<0) {
			perror("Msgrcv fallita");
			exit(1);
		}

		r1 = /* TBD */




		/* TBD: Ricevere la risposta "r2" dal processo P3 sulla coda 1 delle risposte */

		printf("[P1] RECEIVE P3\n");

		ret = /* TBD */

		if(ret<0) {
			perror("Msgrcv fallita");
			exit(1);
		}

		r2 = /* TBD */




		/* TBD: Ricevere la risposta "r3" dal processo P4 sulla coda 1 delle risposte */

		printf("[P1] RECEIVE P4\n");

		ret = /* TBD */

		if(ret<0) {
			perror("Msgrcv fallita");
			exit(1);
		}

		r3 = /* TBD */





		printf("[P1] RISULTATI INTERMEDI: r1=%d, r2=%d, r3=%d\n", r1, r2, r3);




		risultato = r1 + r2 + r3;


		printf("[P1] RISULTATO: %d\n", risultato);

	}


	return 0;
}
