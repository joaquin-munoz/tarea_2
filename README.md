tarea 2 : Joaquin muñoz 
### Sistema de administracion sobre tickets de soporte técnico en una empresa,

# Descripción

El programa permite al usuario realizar diversas operaciones con canciones almacenadas en un archivo CSV, como cargar las canciones desde un archivo, buscar canciones por género, por artista o por tempo. Para ello, utiliza estructuras como mapas y listas para organizar y buscar los datos eficientemente.
# Cómo compilar y ejecutar

Este sistema ha sido desarrollado en lenguaje C y puede ejecutarse fácilmente utilizando "Visual Studio Code" junto con una extensión para C/C++, como "C/C++ Extension Pack" de Microsoft. Para comenzar a trabajar con el sistema en tu equipo local, sigue estos pasos:

# Requisitos previos:

- Tener instalado [Visual Studio Code],puede intalarlo en el siguiente link : https://code.visualstudio.com.
- Instalar la extensión "C/C++" de Microsoft.
- Tener instalado un compilador de C (como gcc). Si estás en Windows, se recomienda instalar [MinGW](https://www.mingw-w64.org/) o utilizar el entorno [WSL](https://learn.microsoft.com/en-us/windows/wsl/).

# Pasos para compilar y ejecutar:

1. Descarga y descomprime el archivo (.zip) en una carpeta de tu elección donde mas te acomode.
2. Abre el proyecto en Visual Studio Code**
    - Inicia Visual Studio Code.
    - Selecciona (Archivo > Abrir carpeta...) y elige la carpeta donde descomprimiste el proyecto.
3. Compila el código
    - Abre el archivo principal por ejemplo en tarea2.c
    - Abre la terminal integrada Terminal > Nueva terminal, puedes usar la terminal que desees , recomendada git bash.
    - En la terminal, compila el programa con el siguiente comando: 
        (gcc tdas/*.c tarea2.c -Wno-unused-result -o tarea2)
        
4. Ejecuta el programa
    - Una vez compilado, puedes ejecutar la aplicación con:
        (./tarea2)        

## Funcionalidades 
    ### **Funcionalidades para la aplicación:**

1. *cargar canciones*:
    - el programa lee el archico CSV y almacena en un struck cada cancion con sus datos correspondientes id, artists, album_name, track_name, tempo y track_genre, crea listas dependientes para el genero, artista y tempo y cada una de las listas creadas almacenada en sus mapas correspondiendtes song_artista, song_tempo, song_genres.

2. *buscar por genero*:
    - el usuario ingresa el genero a buscar y el programa muestra los datos asociados a dicho genero mosrando los datos para cada cancion(id, artists, album_name, track_name, tempo y track_genre)


3. *buscar por artista*:
    - el usuario ingresa el nombre del artista y el programa muestra los datos asociados a dicho artista mosrando los datos anteriormente dichos para cada cancion(id, artists, album_name, track_name, tempo y track_genre)

4. *buscar por tempos* :
    - el usuario ingresa para buscar por tempo y el programa pregunta que tipo de tempo quiere el usuario (Lentas,Moderadas,Rápidas), a continuacion el programa muestra la canciones que encajan en el rango del tipo de tempo seleccionado

5. *salir* :
    - al seleccionar esta opcion el programa se cierra.

# Funcionando correctamente:
1. cargar canciones
    
2. buscar por genero

3. buscar por artista

4. buscar por tempos


# Problemas conocidos:

- al buscar por genero y no ingresar un genero sino ingresar como opcion '4' o '5' el prograna muestra ciertas canciones.

# A mejorar:

- crear atajos en caso de que el usuario se equivoque y salte error para poder intentarlo nuevamente sin tener que volver al inicio o en que caso que quiera devolverse hacia atras.
-hacer una funcion que lea tildes para tener una imagen mas limpia de los datos en caso de alguno de estos tener tildes o simbolos que se vean algo "corruptos".

# Ejemplo de uso
**Paso 1: cargar canciones**

    el usuario iniciaria cargando las canciones del archivo csv,este demoraria 1 a 2 minutos dependiendo del dispositivo donde se ejecute este programa

    luego de que terminara podria seguir con las demas funciones

**Paso 2: buscar por genero**

    - si el usuario selecciona la opcion 3, debe pone el nombre del artista "Zarcort", y este mostraria las canciones con el genero anime (se aceptan mayusculas,tildes, etc).

    **********

    Opción seleccionada: 2) buscar por genero

    Ingrese el género de la musica: anime

    ID: 5049, artista: SEKAI NO OWARI, album_name: Alternative Christmas 2022, track_name: silent , tempo: 87.794
    ID: 5050, artista: Mrs. GREEN APPLE, album_name: ÒéñÒâ│ÒâòÒéºÒâ½ÒâÄ, track_name: ÒéñÒâ│ÒâòÒéºÒâ½ÒâÄ , tempo: 92.466
    ID: 5051, artista: Yuko Ando, album_name: Shogeki, track_name: Shogeki , tempo: 137.032
    .....
    .....

    **********

    - si el usuario selecciona la opcion 3, debe pone el nombre del artista "Zarcort", y este mostraria las canciones con el genero anime (se aceptan mayusculas,tildes,etc).

    **********

    Opción seleccionada: 3) buscar por artista 

    Ingrese el artista de la musica: Zarcort

    ID: 5396, artista: Zarcort, album_name: Resident Evil Rap, track_name: Resident Evil Rap , tempo: 92.011 
    ID: 5488, artista: Zarcort, album_name: Halo 4 Rap, track_name: Halo 4 Rap , tempo: 128.453
    .....
    .....

    **********
    - si el usuario selecciona la opcion 4, debe seleccionar el tempo del que desee obtener las canciones, y este mostraria las canciones con el con el tempo elejido.

    **********

    Opción seleccionada: 4) buscar por tempo 

    Ingrese el tempo de la musica: 1

    1) Lentas(menos de 80 BPM):
    2) Moderadas(entre 80 y 120 BPM):
    3) Rápidas(Tempo mayor a 120 BPM):

    ID: 103620, artista: Amber Mark, album_name: Halloween & Chill, track_name: Foreign Things , tempo: 75.075
    ID: 103627, artista: Amber Mark, album_name: Best R&B Tunes, track_name: Competition - Single Edit , tempo: 74.993 
    .....
    .....

    **********

**Paso 3: salir**

    -si joaquin no quisiera realizar ninguna otra operacion seleccionaria salir(opcion 5) y el programa mostraria el siguiente mensaje:

    **********

    hasta luego, ten un buen dia.
    
    **********