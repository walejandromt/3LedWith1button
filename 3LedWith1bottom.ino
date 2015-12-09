//3 Leds with 1 push bottom. Williams - WaSoM, walejandromt@gmail.com

int botomStatus = 0;
int botomAnterrior = 0;
int status = 0;
int x=0;
int concurrencia = 0;
boolean compareTo = false;
void setup(){
 pinMode(1, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(6, OUTPUT);
 
 pinMode(2, INPUT);

}
void loop(){


           
               while(true){
                   botomStatus = digitalRead(2);
                      
                      
                      if (botomStatus == HIGH && botomAnterrior == LOW) {
                             status = status + 1;                            //Condición que verifica si el usuario ha presionado el botón
                             delay(10);
                             Serial.print("hola");
                       }
                       
                   x=concurrencia%2;
                         
                         
                      if(status != 0 && x==0 && concurrencia==80){  
                           
                           compareTo=true;                                 //Condición que da luz verde a la condición de las variables
                           Serial.println(status);
                           break;
                  
                         }
                 
                      if(status != 0){
                        delay(20);
                         concurrencia++;                                   //Concurrencia o concatenación de las veces que paso, sirve para dar unos 10 seg después de presionar
                       }                                                   //Una vez el botón para verificar si se volverá a presionar o no. 
                    
                       
                   botomAnterrior = botomStatus;

             
               
             }
               

              




               
               if(compareTo == true){                                   //Aquí valora la condición si se cumplió una anterior que el "status" sea diferente de 0

                   switch (status)
                   {
                       case 1:
                           digitalWrite(6, HIGH);
                           digitalWrite(4, LOW);
                           digitalWrite(1, LOW);
                           status = 0;
                           compareTo=false; 
                           concurrencia = 0;
                           break;
                       case 2:
                           digitalWrite(6, LOW);
                           digitalWrite(4, HIGH);
                           digitalWrite(1, LOW);
                            status = 0;
                            compareTo=false; 
                            concurrencia = 0;
                           break;
                       case 3:
                           digitalWrite(6, LOW);
                           digitalWrite(4, LOW);
                           digitalWrite(1, HIGH);
                           status = 0;
                           compareTo=false;
                           concurrencia = 0;
                           break;
                       default:
                           status = 0;
                           digitalWrite(6, LOW);
                           digitalWrite(4, LOW);
                           digitalWrite(1, LOW);
                           compareTo=false;
                           concurrencia = 0;
                           break;
                   }
               
               }


               
           
    
}
