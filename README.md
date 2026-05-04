# Aparato reproductor

**Desarrollado por:**
* Ninibeth Pérez Cortés - papaFritaUwU
* Rodrigo Reyes Alfaro - rodrigoreyes-bit
* Josefa Vargas Cortés - josefa-v

## Descripción del Proyecto
Aparato reproductor es un reproductor de música basado en consola desarrollado en C++ para el curso de Estructuras de Datos. El sistema permite gestionar un catálogo de música desde un archivo fuente y controlar una lista de reproducción dinámica. Utiliza estructuras de datos personalizadas, como listas doblemente enlazadas, para ofrecer una navegación fluida entre canciones, permitiendo reproducir, pausar y gestionar colas de reproducción de forma eficiente.

## Diagrama de Clases
* **Cancion:** Almacena los metadatos (ID, nombre, artista, duración, etc.).
* **Nodo:** Clase base para la estructura de lista enlazada.
* **Almacenamiento:** Gestiona el catálogo completo de canciones disponibles en el sistema.
* **ListaReproduccion:** Controla la cola actual, el puntero a la canción en reproducción y los estados.

## Compilación y Ejecución
Para compilar este proyecto, se requiere un compilador de C++ (GCC/G++) instalado en su sistema. 

### 1. Compilación
Desde la raíz del proyecto (donde se encuentra el archivo `main.cpp`)
