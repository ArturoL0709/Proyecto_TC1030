# Proyecto_TC1030
Proyecto de programación orientado a objetos
El programa es un sistema de pedidos para un restaurante. Permite a los clientes seleccionar y ordenar diferentes platos, como bebidas, postres y platos principales, y calcular el total del pedido.

El programa utiliza una estructura de clases para representar los diferentes tipos de platos. La clase base es "plato", que tiene atributos comunes como el nombre, el tipo y el precio. Esta clase es abstracta y define dos métodos virtuales puros: "calcular_cuenta()" y "to_string()". Las clases derivadas "bebida", "postre" y "plato_principal" heredan de la clase "plato" y proporcionan implementaciones concretas para estos métodos.

El programa utiliza una clase adicional llamada "pedido" para manejar la lógica del pedido. La clase "pedido" contiene un arreglo de punteros a objetos de la clase "plato" y realiza operaciones como agregar platos al pedido, mostrar el menú, calcular el total del pedido y realizar el pedido final.

El programa comienza en la función principal main(). Crea un objeto de la clase "pedido" y llama al método "creaejemplos()" para inicializar el menú con algunos ejemplos predefinidos. Luego, muestra un menú principal que permite al usuario seleccionar diferentes opciones, como agregar una bebida, un postre o un plato principal, mostrar el menú, realizar un pedido o salir del programa.

Cuando el usuario selecciona una opción para agregar un plato, se recopilan los detalles necesarios, como el nombre, el precio y la proteína en el caso de un plato principal. Luego, se llaman a los métodos correspondientes de la clase "pedido" para agregar el plato al pedido.

El programa utiliza bucles y estructuras de control para permitir al usuario realizar múltiples selecciones y construir su pedido. Se muestra el menú de pedido después de cada selección para que el cliente pueda ver qué platos ha seleccionado hasta el momento. El total del pedido se calcula continuamente y se muestra al finalizar el pedido.

En resumen, el programa del sistema de pedidos del restaurante proporciona una interfaz interactiva para que los clientes seleccionen y ordenen diferentes platos. Ofrece opciones para agregar bebidas, postres y platos principales, muestra el menú, calcula el total del pedido y permite realizar el pedido final. Es una herramienta útil para agilizar el proceso de pedidos en un restaurante y mejorar la experiencia del cliente.


# Consideraciones
Limitaciones en los tipos de platos: El programa solo permite agregar platos de tres tipos: bebidas, postres y platos principales. No se proporciona la opción para agregar otros tipos de platos. Si se desea ampliar la variedad de platos, se requeriría modificar el código y agregar las clases correspondientes.

Entrada de datos: Es importante ingresar correctamente los tipos de datos para cada atributo solicitado al agregar un plato. El programa espera que se ingresen cadenas de caracteres (string) para el nombre y la proteína del plato principal, y números de punto flotante (float) para el precio de los platos y el tamaño de la bebida. Es necesario asegurarse de ingresar los datos en el formato correcto para evitar errores.

Ambiente de ejecución: g++ bebida.h pedido.h Plato.h plato_principal.h postre.h main.cpp -o programa
Windows: programa.exe

Dependencias y compilación: Se mencionan los archivos necesarios para compilar el programa, incluyendo los archivos de encabezado (.h) y el archivo principal (main.cpp). Se proporciona el comando de compilación para usar con el compilador g++ en Linux y se menciona el nombre del archivo de salida. Para Windows, se menciona el nombre del archivo ejecutable resultante.



# CORRECIONES
Para esta entrega finalhe modificado correciones que me hicieron llegar por medio de mi archivo de de calificaciones de Excel. Las correciones son mi UML,  la sobrecarga y sobreescriturade metodos, así como también la implementación de clases virtuales. 

 
 ##Consideraciones
. 
  
