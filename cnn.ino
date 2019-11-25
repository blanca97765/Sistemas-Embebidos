#include "matriz_entrenamiento.h"
float datos_prueba[5]={5.8 , 2.7 ,4.1, 1,2};
int respuesta;
void setup() {
Serial.begin(9600);


}

void loop() {
// respuesta=knn(3,3,5,120);
// Serial.println(respuesta);
 cnn(3,5,120);
 delay (5000);
 

}

void cnn(int etiquetas, int tam_col, int tam_fil){
  int i;
  int j;
  int l;
  int f;
  int c;
  float centroid=0;
  float promedio=0;
  float distancia_menor=3000;
  float distancia=0;
  int s=0; //contar los datos que se envian al source 
  int label;
  
  /*
   * centroides-> promedio
   *              promedio por columna y por etiqueta
   *              almaceno los vectores
   *              knn entre vectores y matriz de entrenamiento
   */
   float centroides[etiquetas][tam_col]; 
   for(i=0;i<etiquetas;i++){
    for(j=0;j<tam_col;j++){ //iniciar matrices en ceros 
      if(j==tam_col-1){
      centroides[i][j]=i+1; //llenar etiquetas a cada centroide para hcer knn y comparar 
      }
      else{
      centroides[i][j]=0;   //lleno de ceros al resto de la matriz       
    }
    
   }
   //realizar promediopor columna y por etiqueta 
   for(l=0;l<etiquetas;l++){
    for(i=0;i<tam_col-1;i++){
      for(j=(40*l);j<40*(l+1);j++){ 
       centroid=centroid+matriz[j][i]; 
      }
      centroides[l][i]=centroid/40;
     Serial.println(centroides[l][i],4);
     Serial.print(',');
      centroid=0;
    }
    Serial.println(centroides[l][tam_col-1]);
   }
}

//encontrar la distancia entre los centroides y la matriz de entrenamiento
//para comparar si clasifica adecuadamente 
     //for-> matriz entrenamiento 
       //for-> filas de matriz de entrenamiento 
         //for-> filas de matriz centroides
           //for->columnas
  for(i=0;i<tam_fil;i++){
    for(j=0;j<etiquetas;j++){
      for(l=0;l<tam_col-1;l++){
        promedio=promedio+pow(centroides[j][l]-matriz[i][l],2);   
      }
      distancia=sqrt(promedio);
      if(distancia<distancia_menor){
        distancia_menor=distancia; //asigna el valor que adquirio dentro de la raiz 
        label=centroides[j][tam_col-1];
      }
      promedio=0;
    }
    //comparar si lo que tiene la matriz en la posicion i y tamcol-1 es igual a label
    distancia_menor=3000;
   
    if(matriz[i][tam_col-1]==label){
      Serial.print(String(i)+":");
      Serial.println("D");
      delay(100);
    }
    else{
      Serial.print(String(i)+":");
      Serial.println("S");
      delay(100);
      s++; //contador de Datos de Source
      Serial.print(s);
      } 
      s;
      float matriz_s[s][tam_col];
      for(f=0;f<s;f++){
        for(c=0;c<tam_col;c++){
        matriz_s[f][c]=matriz[i][c];      
      }    
    }
     for(f=0;f<s;f++){
        for(c=0;c<tam_col;c++){
    Serial.print(matriz_s[f][c]);
       Serial.print(',');
       delay(500) ;       
  }
    Serial.println(' ');
    }
  }
  }
