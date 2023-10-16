//********************************************************************************
// Librerias
//********************************************************************************
#include <SPI.h>
#include <SD.h>
//********************************************************************************
// Variables Globales
//********************************************************************************
#define CS_PIN PA_3
int opcion;
char c;
int lineCount;
//********************************************************************************
// Lectura SD
//********************************************************************************
File myFile;
//********************************************************************************
// Configuración
//********************************************************************************
void setup(){
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  SPI.setModule(0); //Indicar que el módulo SPI se utilizará
  Serial.print("Initializing SD card...");

  if (!SD.begin(CS_PIN)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // Mostrar el menú en el monitor serial
  Serial.println("Selecciona una imagen:");
  Serial.println("1. Corazon");
  Serial.println("2. Perro");
  Serial.println("3. Casa");
  Serial.println("Imagen Propia:");
  Serial.println("  4. Editar Imagen");
  Serial.println("  5. Visualizar Imagen");
}
//********************************************************************************
// Loop
//********************************************************************************
void loop() {
  // Esperar a que el usuario ingrese una opción
  while (!Serial.available()) {
  // Esperar a que haya datos disponibles en el monitor serial
  }
  // Leer la opción ingresada por el usuario
  opcion = Serial.parseInt();

  if(opcion == 1){
    // Leer Opcion 1
     File textFile = SD.open("/opcion1.txt");
      if (textFile) {
        Serial.println(" ");
        Serial.println("CORAZON: ");
        while (textFile.available()) {
          Serial.write(textFile.read());
        }
        textFile.close();
      } else {
        Serial.println("error opening opcion1.txt!");
      }
    Serial.println(" ");
    Serial.println("Selecciona una imagen:");
    Serial.println("1. Corazon");
    Serial.println("2. Perro");
    Serial.println("3. Casa");
    Serial.println("Imagen Propia:");
    Serial.println("  4. Editar Imagen");
    Serial.println("  5. Visualizar Imagen");
  }
  if(opcion == 2){
    // Leer Opcion 2
     File textFile = SD.open("/opcion2.txt");
      if (textFile) {
        Serial.println(" ");
        Serial.println("PERRO: ");
        while (textFile.available()) {
          Serial.write(textFile.read());
        }
        textFile.close();
      } else {
        Serial.println("error opening opcion2.txt!");
      }
    Serial.println(" ");
    Serial.println("Selecciona una imagen:");
    Serial.println("1. Corazon");
    Serial.println("2. Perro");
    Serial.println("3. Casa");
    Serial.println("Imagen Propia:");
    Serial.println("  4. Editar Imagen");
    Serial.println("  5. Visualizar Imagen");
  }
  if(opcion == 3){
    // Leer Opcion 3
     File textFile = SD.open("/opcion3.txt");
      if (textFile) {
        Serial.println(" ");
        Serial.println("CASA: ");
        while (textFile.available()) {
          Serial.write(textFile.read());
        }
        textFile.close();
      } else {
        Serial.println("error opening opcion3.txt!");
      }
    Serial.println(" ");
    Serial.println("Selecciona una imagen:");
    Serial.println("1. Corazon");
    Serial.println("2. Perro");
    Serial.println("3. Casa");
    Serial.println("Imagen Propia:");
    Serial.println("  4. Editar Imagen");
    Serial.println("  5. Visualizar Imagen");
  }
  if(opcion == 4){
    Serial.println("Escriba las 10 lineas de la nueva imagen: ");
    while (lineCount < 11) {
    while (!Serial.available()) {
      // Espera a que haya datos disponibles en el monitor serial
    }

    while (Serial.available() > 0) {
      c = Serial.read();
      // Abre el archivo en modo "append"
      myFile = SD.open("opcion4.txt", FILE_WRITE);
      if (myFile) {
        myFile.print(c);
        myFile.close();
      } else {
        Serial.print("error opening opcion4.txt!");
      }
    }
  // Incrementar el contador de líneas
    Serial.print("Linea ");
    Serial.print(lineCount);
    Serial.println(" Recibida");
    lineCount++;
    }  
    Serial.println(" ");
    Serial.println("IMAGEN COMPLETADA");
    Serial.println(" ");
    Serial.println("Selecciona una imagen:");
    Serial.println("1. Corazon");
    Serial.println("2. Perro");
    Serial.println("3. Casa");
    Serial.println("Imagen Propia:");
    Serial.println("  4. Editar Imagen");
    Serial.println("  5. Visualizar Imagen"); 
  }
  if(opcion == 5){
   // Leer Opcion 5
     File textFile = SD.open("/opcion4.txt");
      if (textFile) {
        Serial.println(" ");
        Serial.println("IMAGEN PROPIA: ");
        while (textFile.available()) {
          Serial.write(textFile.read());
        }
        textFile.close();
      } else {
        Serial.println("error opening opcion4.txt!");
      }
    Serial.println(" ");
    Serial.println("Selecciona una imagen:");
    Serial.println("1. Corazon");
    Serial.println("2. Perro");
    Serial.println("3. Casa");
    Serial.println("Imagen Propia:");
    Serial.println("  4. Editar Imagen");
    Serial.println("  5. Visualizar Imagen");
  }
}
