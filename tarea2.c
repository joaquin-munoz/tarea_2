#include "tdas/extra.h"
#include "tdas/list.h"
#include "tdas/map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char track_name[100];
  char tempo[100];
  char track_genre[1000];
  char artista[100];
  char id[100];
  char album_name[100];
} song;
// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("     Base de Datos de canciones");
  puts("========================================");

  puts("1) Cargar canciones");
  puts("2) Buscar por genero");
  puts("3) Buscar por artista");
  puts("4) Buscar por tempo");
  puts("5) Salir");
}

/*1 igual, 0 no*/
int is_equal_str(void *key1, void *key2) {
  return strcmp((char *)key1, (char *)key2) == 0;
}

/*1 igual, 0 no*/
int is_equal_int(void *key1, void *key2) {
  return *(int *)key1 == *(int *)key2; 
}

void cargar_canciones(Map *song_genres,Map *song_artista,Map *song_tempo) {
  FILE *archivo = fopen("data/song_dataset_.csv", "r");
  if (archivo == NULL) {
    perror(
        "Error al abrir el archivo");
    return;
  }

  char **campos;
  campos = leer_linea_csv(archivo, ',');
  List *tempo_80 = list_create();
  List *tempo_120 = list_create();
  List *tempo_121 = list_create();
  // Lee cada línea del archivo CSV hasta el final
  while ((campos = leer_linea_csv(archivo, ',')) != NULL) {
    // Crea una nueva estructura Film y almacena los datos de cada película
    song *cancion = (song *)malloc(sizeof(song));
    strcpy(cancion->track_genre, campos[20]);
    strcpy(cancion->artista, campos[2]);
    strcpy(cancion->tempo, campos[18]); 
    strcpy(cancion->album_name, campos[3]); 
    strcpy(cancion->id, campos[0]); 
    strcpy(cancion->track_name, campos[4]);
    //mapa de canciones
    if(map_search(song_genres,cancion->track_genre) == NULL){ //SI el genero NO SE ENCUENTRA CREA NUEVA LISTA
      List *canciones = list_create();
      list_pushBack(canciones,cancion);
      map_insert(song_genres,cancion->track_genre,canciones);
    }
    else{
      MapPair* par = map_search(song_genres,cancion->track_genre); //par->value = lista de canciones
      list_pushBack(par->value,cancion);
    }
    //mapa de artista
    if(map_search(song_artista,cancion->artista) == NULL){ //SI el genero NO SE ENCUENTRA CREA NUEVA LISTA
      List *artistas = list_create();
      list_pushBack(artistas,cancion);
      map_insert(song_artista,cancion->artista,artistas);
    }
    else{
      MapPair* par = map_search(song_artista,cancion->artista); //par->value = lista de canciones
      list_pushBack(par->value,cancion);
    }
    //mapa de tempos, usamos funcion atof(float)
    if(atof(cancion->tempo) < 80){
      list_pushBack(tempo_80,cancion);
    }
    else if(80 <= atof(cancion->tempo) && atof(cancion->tempo) <= 120){
        list_pushBack(tempo_120,cancion);
    }
    else {
      list_pushBack(tempo_121,cancion);
    }
  }
  map_insert(song_tempo,"Lentas",tempo_80);
  map_insert(song_tempo,"Moderadas",tempo_120);
  map_insert(song_tempo,"Rápidas",tempo_121);
  fclose(archivo);
}

void buscar_por_genero(Map *song_genres) {
  char genero[100];

  // Solicita al usuario el genero de la musica
  printf("Ingrese el genero de la musica: ");
  scanf(" %[^\n]s", genero) ;; // Lee el genero del teclado

  MapPair *pair = map_search(song_genres, genero); // buscamos la cancion
  
  if (pair != NULL) { // si existe mostramos la info 
      List* canciones = pair->value;
      song *cancion = list_first(canciones);
      
      while (cancion != NULL) { //mostramos id, artists, album_name, track_name, tempo y track_genre. 
        printf("ID: %s, artista: %s, album_name: %s, track_name: %s , tempo: %s \n", cancion->id, cancion->artista
          ,cancion->album_name,cancion->track_name, cancion->tempo);
          cancion = list_next(canciones);
      }
  }
  else printf("el genero ingresado no existe o es invalido\n"); //en caso contrario mostramos el siguiente mensaje
}
/*Buscar por Artista: La usuaria ingresa el nombre de un artista
 y la aplicación lista sus canciones disponibles con la información de cada una.*/
void buscar_por_artista(Map *song_artista){
  char artista[100];

  // Solicita al usuario el artista de la musica
  printf("Ingrese el artista de la musica: ");
  scanf(" %[^\n]s", artista) ; // Lee el artista del teclado

  MapPair *pair = map_search(song_artista, artista); // buscamos la cancion
  
  if (pair != NULL) { // si existe mostramos la info 
      List* canciones = pair->value;
      song *cancion = list_first(canciones);
      
      while (cancion != NULL) { //mostramos id, artists, album_name, track_name, tempo y track_genre. 
        printf("ID: %s, artista: %s, album_name: %s, track_name: %s , tempo: %s \n", cancion->id, cancion->artista
          ,cancion->album_name,cancion->track_name, cancion->tempo);
          cancion = list_next(canciones);
      }
  }
  else printf("el artista ingresado no existe o es invalido\n"); //en caso contrario mostramos el siguiente mensaje
}

void mostrar_tempo(Map *song_tempo,char *a){
  MapPair *pair = map_search(song_tempo, a);
  List* tempo_canciones = pair->value;
  song *cancion = list_first(tempo_canciones);
    
  while (cancion != NULL) { //mostramos id, artists, album_name, track_name, tempo y track_genre. 
    printf("ID: %s, artista: %s, album_name: %s, track_name: %s , tempo: %s \n", cancion->id, cancion->artista
        ,cancion->album_name,cancion->track_name, cancion->tempo);
        cancion = list_next(tempo_canciones);
  }
}
void Buscar_por_tempo(Map *song_tempo){
  char tempo;
  puts("Ingrese el tempo de la musica:");

  puts("1) Lentas(menos de 80 BPM)");
  puts("2) Moderadas(entre 80 y 120 BPM");
  puts("3) Rapidas(Tempo mayor a 120 BPM)");
  scanf(" %c", &tempo); // Lee el tempo del teclado

  switch (tempo) {
    case '1':
      mostrar_tempo(song_tempo,"Lentas");
      break;
    case '2':
      mostrar_tempo(song_tempo,"Moderadas");
      break;
    case '3':
      mostrar_tempo(song_tempo,"Rápidas");
      break;
    }
}
int main() {
  char opcion; // Variable para almacenar una opción ingresada por el usuario
               

  // Crea un mapa para almacenar artista, tempo , generos para almacenar las canciones.
  // comparación que trabaja con claves de tipo string.
  Map *song_artista = map_create(is_equal_str);
  Map *song_tempo = map_create(is_equal_str);
  Map *song_genres = map_create(is_equal_str);


  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opcion: ");
    scanf(" %c", &opcion);

    switch (opcion) {
    case '1':
      cargar_canciones(song_genres,song_artista,song_tempo);
      break;
    case '2':
      buscar_por_genero(song_genres);
      break;
    case '3':
      buscar_por_artista(song_artista);
      break;
    case '4':
      Buscar_por_tempo(song_tempo);
      break;
    case '5':
      printf("hasta luego, ten un buen dia.\n");
      break;
    }
    presioneTeclaParaContinuar();

  } while (opcion != '5');

  return 0;
}
