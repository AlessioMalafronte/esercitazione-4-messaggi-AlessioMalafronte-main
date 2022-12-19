#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

#include "p.h"


int main() {

	pid_t pid;
	int i;



    key_t queue_operandi_1  = /* TBD: Definire una chiave */
	key_t queue_risultati_1 = /* TBD: Definire una chiave */
	key_t queue_operandi_2  = /* TBD: Definire una chiave */
	key_t queue_risultati_2 = /* TBD: Definire una chiave */



    int id_operandi_1 = /* TBD: Creare una nuova coda */

	if(id_operandi_1 < 0) {
		perror("Msgget fallita");
		exit(1);
	}



    int id_risultati_1 = /* TBD: Creare una nuova coda */

	if(id_risultati_1 < 0) {
		perror("Msgget fallita");
		exit(1);
	}



	int id_operandi_2 = /* TBD: Creare una nuova coda */

	if(id_operandi_2 < 0) {
		perror("Msgget fallita");
		exit(1);
	}



	int id_risultati_2 = /* TBD: Creare una nuova coda */

	if(id_risultati_2 < 0) {
		perror("Msgget fallita");
		exit(1);
	}




	/* TBD: Creare 6 processi figli, e fare in modo che ognuno di loro
	   esegua un degli eseguibili "p1", "p2", etc.

	   NOTA: È consentito anche non usare un ciclo.
	   (poiché il numero dei processi è fisso, si può replicare il
		codice per 6 volte, cambiando solo il percorso dell'eseguibile)
	 */



	/* TBD: Attendere la terminazione dei 6 processi figli */



    /* TBD: Rimuovere le code */


	return 0;
}

