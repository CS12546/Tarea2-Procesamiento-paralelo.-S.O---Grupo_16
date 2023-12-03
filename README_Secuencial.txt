Este es un programa hecho para linux(ubuntu)

Para ejecutar el metodo secuencial
-Tener una imagen de nombre "mi_imagen_color.jpg" (proporcionada por/en el repositorio) 
Abrir terminal y introducir:

./secuencial mi_imagen_color.jpg mi_imagen_gris.jpg 4

mi_imagen_color.jpg es el nombre de la imagen de entrada a color.

mi_imagen_gris.jpg es el nombre que se le dará a la nueva imagen en escala de grises.

4 es el número de hebras (aunque parece que no está afectando el tiempo de ejecución en este caso).

Resultado:

El programa generara un nuevo archivo de imagen en escala de grises llamado mi_imagen_gris.jpg.