//********************************************************************************
// Librerias
//********************************************************************************
#include <SPI.h>
#include <SD.h>
//********************************************************************************
// Variables Globales
//********************************************************************************
#define CS_PIN 5
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
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(10, OUTPUT);

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
    while (lineCount < 10) {
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
    Serial.print(lineCount + 1);
    Serial.println(" Recibida");
    lineCount++;
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
