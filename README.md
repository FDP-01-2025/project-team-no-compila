[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Horror game – The Mansion of Blackthorn

## Descripción del Proyecto

Temática y ambientación:
El juego se desarrolla en una mansión embrujada conocida como “Blackthorn”, un lugar lleno de misterio, oscuridad y elementos sobrenaturales. La historia se construye en torno a un ritual maldito y la presencia de entidades espirituales. El ambiente es tétrico y está inspirado en el género de horror gótico, con elementos como retratos que sangran, libros malditos, susurros en pasillos oscuros y rituales ocultistas.

Mecánica principal:
El juego es de tipo narrativo y por turnos, diseñado para dos jugadores. Cada jugador toma decisiones que afectan el rumbo de la historia. La mecánica se basa en:

- Elegir entre opciones (1 a 3) en cada fase.

- Recolectar objetos clave para avanzar o desbloquear eventos.

- Superar obstáculos sobrenaturales usando los objetos encontrados.

- Llegar al ritual final y lograr uno de varios desenlaces posibles.


Idea general de la jugabilidad:
Los jugadores avanzan a través de cinco fases principales, cada una con varios eventos aleatorios. En cada evento:

- Ambos jugadores enfrentan decisiones independientes.

- Las decisiones afectan la historia, los objetos obtenidos y el final del juego.

- Se utiliza un sistema de guardado automático para retomar el progreso.

- Existen múltiples finales dependiendo de los objetos recolectados y las acciones tomadas, lo que fomenta la rejugabilidad.


Aplicación de los temas vistos:

- Funciones:

El código está dividido en funciones como progress(), loadprogress(), showObjects(), menu(), fase1(), fase2(), fase3(), fase4(), fase5(), finals().
Ejemplo: progress() guarda el progreso actual en un archivo .txt.

- Estructuras de control:

if: Se usa para verificar si un jugador tiene un objeto antes de usarlo.
Ejemplo: if (player.inventario[daga] == 1)

switch: Utilizado para manejar múltiples decisiones de los jugadores o eventos aleatorios.
Ejemplo: switch (evento) { case 1: ... }

while / do...while: Garantiza que se ejecute la fase correcta hasta que el jugador complete esa fase y avance a la siguiente. Además, garantiza que el jugador ingrese opciones válidas.
Ejemplo: while (phase == 1) phase1(player);
         do { ... } while (option < 1 || option > 3);

for: Se emplea para recorrer el inventario del jugador y mostrar los objetos disponibles.
Ejemplo: for (int i = 0; i < 12; i++) { ... }

- Manejo de archivos (fstream):

Se utiliza ifstream y ofstream para leer y escribir archivos como “perfil.txt” o “parte1.txt”.
Esto permite guardar el progreso del jugador o cargarlo si ya había jugado antes.

- Aleatoriedad (rand):

Cada fase selecciona aleatoriamente un evento mediante rand() % 3 + 1. Esto aporta variedad y hace que cada partida sea diferente.

- Estructuras (struct):

Se utiliza una estructura llamada gameData para guardar información del juego como: 
- Nombre del juego.
- Jugadores.
- Inventario (arreglo).
- Fase actual.
- Evento activo.
- Progreso de la historia.

Consideraciones técnicas del desarrollo

- El programa está escrito completamente en C++.
- Se usó validación de entrada con cin.fail() para evitar errores si el usuario ingresa letras en lugar de números.
- Se aplicaron principios de programación estructurada para mantener claridad y orden en el código.
- El sistema de inventario se basa en un arreglo de enteros (int inventario[12]), donde cada índice representa un objeto.
- El sistema de guardado/carga se implementó con lectura/escritura de archivos, usando rutas estándar.
- Se aplico el uso de puntero (&) para poder guardar con exactitud el progreso de la partida y no se pierda por el uso del rand.


## Equipo

- **Nombre del equipo:** Team no Compila

### Integrantes del equipo

1. **Nombre completo:** José Ariel Álvarez Morales.  
   **Carnet:** 00034725

2. **Nombre completo:** Ángel Leonel Choto García.
   **Carnet:** 00185725

3. **Nombre completo:** Diego Gabriel Bonilla Comandari. 
   **Carnet:** 00147325
   
4. **Nombre completo:** Erick Jose Claros López.
   **Carnet:** 00071125

## Mockups
![Menu](https://github.com/user-attachments/assets/18a6b3eb-cc0c-4503-bff5-c907c2c43e7c)
![Patida normal jugador 1 y jugador 2](https://github.com/user-attachments/assets/72ddc669-e353-4479-a6ef-97ad18eae67f)
![case 1](https://github.com/user-attachments/assets/3e5910ef-756a-4ad4-b3c9-b9664ef07f55)
![case 2](https://github.com/user-attachments/assets/8fca0448-0247-4364-86fa-593c080bcd54)
![case 3](https://github.com/user-attachments/assets/4a31df5d-8040-4362-9cfa-7aaf5d959a37)
![case 5](https://github.com/user-attachments/assets/5c925c98-42cd-48a1-989d-62df7498cc5a)

## Flujograma
![header h](https://github.com/user-attachments/assets/8275efaf-84fd-40ae-8ca8-35125d0bf443)
![def cpp](https://github.com/user-attachments/assets/156f61c8-9369-4fa5-bf34-0722b2efd994)
![main cpp](https://github.com/user-attachments/assets/bde82976-76f4-4a2e-a60f-aa7de4b4bc21)




## Instrucciones de Ejecución

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone [URL del repositorio]
