#include "matriz.h" 
float W[4] = {0.01, 0.01, 0.01, 0.01}; //pesos de inicio
int salidadeseada;//valor deseado
int fila = 0; 
int columna = 0;
float sumatoria; // valor de suma
float suma;//aux
float b = -0.1; //valor del bias 
float salidaobtenida; //valor obtenido 
float e = 0; // error para calcular
boolean fin = true; //para finalizar el aprendizaje
int cont = 1; //verificador
int i = 0;
int iteraciones = 0; //conteo de iteraciones
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  verificacion();
}

void salida() {
  salidadeseada = matrizP[fila][4] - 1; // obtencion de 1s y 0s
  sumatoria = b;  
  Serial.print("La salida deseada es : ");
  Serial.println(salidadeseada);
  sumatoriaT();   
}

void sumatoriaT() {
  for (columna = 0; columna < 4; columna++) {
    suma = sumatoria + (matrizP[fila][columna] * W[columna]); //sumatoria de datos multiplicados por pesos
    sumatoria=suma;
    }
  salidaobtenida = 0;
  if (suma > 0) {
    salidaobtenida = 1;     
  }
  Serial.print("La salida obtenida es : ");
  Serial.println(salidaobtenida);  
  Serial.println(" ");
  delay(5);
  error(); 
  }


void error() {

  if (salidaobtenida =! salidadeseada) { //comparacion de salidas
    iteraciones++; 
    cont++; 
    e = salidadeseada - salidaobtenida; //calculo del error
    b = b + e ; //calculo de nuevo bias
    for (columna = 0; columna < 4; columna++) {
      W[columna] = W[columna] + matrizP[fila][columna] * e ; //calculo de nuevo peso con respecto al error 
    }

  }
}

void verificacion(){
  if (fin == true) {
    if (cont > 0) {
      cont = 0;
      for (; fila < 106; fila++) {
        salida();
      }
    } else {
      fin = false;
      Serial.println("Los valores finales para la neurona es: ");
      for (; i < 4; i++) {
        Serial.print("Peso ");
        Serial.print(i + 1);
        Serial.print("= ");
        Serial.println(W[i]);
      }
      Serial.print("El valor de bias es: ");
      Serial.println(b);
      Serial.print("El numero de iteraciones es: ");
      Serial.println(iteraciones);

    }

  }
}
