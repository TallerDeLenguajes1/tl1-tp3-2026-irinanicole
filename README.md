
    ***NOTAS***

## fgets():
>>
    fgets(buffer, tamaño, stdin);
    // requiere especificar longitud ('tamaño') y el flujo de entrada ('stdin')
>>
- es segura porque permite especificar el tamaño máximo del búfer para evitar desbordamientos (evita sobreescribir)
- detiene la lectura al llegar al límite especificado.
- incluye el '\n' al final de la cadena si hay espacio, y añade un carácter nulo ('\0') al final para terminarla correctamente.
- Necesita de una 'Limpieza de Buffer' si existe un scanf() antes del input:
>>
    void limpiarBuffer(){
        int c;
        while ((c = getchar()) != "\n" && c != EOF) {}
    }
>>
- Necesita una correción de los '\n' por '\0', en el caso que se quisiera comparar la igualdad de dos cadenas diferentes (que fueron ingresadas por el usuario).
>>
    //Dado un 'arregloCaracteres[]' : string ('cadena de caracteres')
    //Forma de correción//
     arregloCaracteres[strcspn(arregloCaracteres,"\n")] = '\0';
     // se reemplaza por el caracter de 'fin de cadena'
     //donde la función 'strcspn()' devuelve la posición donde se encuentre el elemento '\n' en el arreglo.
>>
==> de esta manera borramos los saltos de línea que quedan al final de nuestras cadenas leídas y los reemplazamos por un '\0'
y luego, la cadena está lista para ser comparada con cualquier otra.

## gets() 
>>
    gets(buffer);
>>
- es insegura y obsoleta, ya que no controla la cantidad de caracteres leídos.
- puede sobrescribir memoria adyacente si la entrada del usuario supera el tamaño del array, causando fallos graves de seguridad.
- lee hasta el salto de línea ('\n') pero no lo guarda en la cadena.