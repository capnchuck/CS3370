# CS3370
Coursework for CS3370 Advanced C++ Development

                    **Set portsetter Alias**
                        
To enable the portsetter program to be called with the command "setport" follow these steps:

1. Edit the .bashrc file (~/.bashrc)
2. Scroll down to the bottom of the file.
3. Add the line: alias setport='{complete path to portsetter.cpp.o file}'
4. Save and exit the file.
5. Enter the command "source ~/.bashrc" to enable the changes.




                    **How Testing Program Works**
                    
The testing progarm is run simply by running its executable i.e. ./Tester.cpp.o. 
It will then run a series of tests automatically and will return whether or not the test
passed or failed in the console window. If a test checks against invalid input, it will say that 
that test passed as long as the correct non-zero number is returned. A log of all data 
returned by the program will be kept in test.txt. If a test does not pass, look for what 
the program returns in test.txt and report any errors you find.

It is important to keep the Tester executable in the same directory as the portsetter
program. The program calls the portsetter executable directly, not by its alias.






                    **Conjunto portsetter Alias**
                    
Para activar el programa portsetter ser llamado con el comando "SETPORT" siga estos pasos:

1. Edit el archivo .bashrc (~ / .bashrc)
2. Desplácese hasta la parte inferior del archivo.
3. Añadir la línea: alias SETPORT = '{ruta completa a portsetter.cpp.o archivo}'
4. Save y salga del archivo.
5. Ingrese el comando "source ~ / .bashrc" para activar los cambios.



                **Cómo Programa de Verificación de Obras**

El progarm prueba se ejecuta simplemente mediante la ejecución de su ejecutable es decir ./Tester.cpp.o.
A continuación, ejecutar una serie de pruebas automáticamente y volverá si la prueba o no
aprueba o no, en la ventana de la consola. Si una prueba de cheques contra entrada no válida, es decir que se
que prueba pasó el tiempo que se devuelve el número correcto distinto de cero. Un registro de todos los datos
devuelto por el programa se mantendrá en test.txt. Si una prueba no pasa, buscar lo
el programa vuelve en test.txt e informe de cualquier error que encuentre.

Es importante mantener el ejecutable Tester en el mismo directorio que el portsetter
programa. El programa llama al ejecutable portsetter directamente, no por su alias.
