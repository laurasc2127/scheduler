main.c
#include <pthread.h> //pincipalmente colocamos la libreria para poder ejecutar los hilos
#include <stdio.h>
#include <stdlib.h>


 void *threads(void *t) //declaramos el hilo
 {
    int i;
    long hilo; //longitud del hilo


    hiloID = (long)t;
    printf("\n leyendo un libro \n",hilo); //los prcesos que esta realizando el hilo

    printf("\n Escribiendo un mensaje \n",hilo); //los prcesos que esta realizando el hilo

     printf("\n Escuchando musica \n",hilo); //los prcesos que esta realizando el hilo
    pthread_exit((void*) t);
 }

 int hilos;

 void numeroH (){
    printf("\n Digite No Hilos \n"); //Numero de hilo a ejecutar
    scanf ("%d",&noHilos);
 }

 int main (int argc, char *argv[]) //se declara un arreglo
 {
    numeroH();
    pthread_t thread[noHilos];
    pthread_attr_t at;    int r;
    long t;
    void *st;


    pthread_attr_init(&at);
    pthread_attr_setdetachstate(&at, PTHREAD_CREATE_JOINABLE);

    for(t=0; t<noHilos  ; t++) {
       printf("\n\n Hilo creado  %N\n", t);
       r = pthread_create(&thread[t], &at, hilos, (void *)t);
       if (r) {
          }

    pthread_attr_destroy(&at);
    for(t=0; t<noHilos; t++) {
       r = pthread_join(thread[t], &st);
       if (r) {
          }
       printf("\n proceso de hilo  completo \n",t); //termina el proceso del hilo
       }

 }
