Este es un programa hecho para linux(ubuntu)
-Asegurarse de haber ejecutado previamente el comando 
make(para compilar los ejecutables)

Para ejecutar el metodo paralelo threads
-Tener una imagen de nombre "mi_imagen_color.jpg" (proporcionada por/en el repositorio) 
Abrir terminal y introducir:

./paralelo_openmp mi_imagen_color.jpg mi_imagen_gris_openmp.jpg 4

mi_imagen_gris_openmp.jpg es el nombre que se le dará a la nueva imagen en escala de grises generada por el programa paralelo usando OpenMP.

4 es el número de threads que se utilizarán.

Estos comandos son similares al comando del programa secuencial, pero están destinados a ejecutarse con las implementaciones paralelas. 
Puede ejecutar estos comandos para comparar los tiempos de ejecución y verificar cómo la paralelización afecta el rendimiento en el sistema