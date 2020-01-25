//program to use millis clock to trigger multiple timers 

//Array 0 for loop delay protection
//1,000 microseconds = 1 millisecond; 1,000,000 micro in 1 sec
//using millis for timer it will reset after 50 days not important
//for short duration actions

unsigned long int tic[10];
unsigned long int toc[10] = {100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000};

//once
void setup() {
  String ioOUT;
  Serial.begin(115200);
  while(!Serial); //wait for serial to start
  
  ioOUT = F("\nSERIAL START\n");
  ioOUT += F("LOOP DELAY TEST set at ");
  ioOUT += (String)toc[0];
  Serial.println(ioOUT);
  
  //initialize all timers machine time
  for(int x=0; x <= 9; x++){
    tic[x] = millis();
  }
}
//inturrupt here

//repeat
void loop() {
  String ioOUT;
  tic[0]= millis(); //master loop timer set every loop to check processing delays

//Test for timer trigger and execute timer actions
  for( int x = 1; x <= 9; x++){
    
    //Test for timer duration
    if(millis() - tic[x] >= toc[x]){ //do something for all triggered timers
      tic[x] = millis();//reset timer
      ioOUT = F("\nTimer#");
      ioOUT += (String)x;
      ioOUT += "=";
      ioOUT += toc[x];
      ioOUT += F(" ; triggered at (");
      ioOUT += tic[x];
      ioOUT += ")";
      Serial.print(ioOUT);

      //do stuff if specific timer triggered
      switch(x){
         case 1:
          ioOUT = F("ONE");
          break;
        case 2:
          ioOUT = F("TWO");
          break;
          case 3:
          ioOUT = F("THREE");
        break;
        case 4:
          ioOUT = F("FOUR");
          break;
        case 5:
          ioOUT = F("FIVE");
          break;
        case 6:
          delay(100);//delay to test overall single loop lag
          ioOUT = F("SIX");
          break;
        case 7:
          ioOUT = F("SEVEN");
          break;
        case 8:
          ioOUT = F("EIGHT");
          break;
        case 9:
          ioOUT = F("NINE");
          break;
        default:
          ioOUT = F("DEFAULT");//should not trigger DEFAULT
          break; 
      }
      Serial.println(ioOUT);
    }
  }
  //overall loop delay excessive
  if(millis() - tic[0] >= toc[0]){
    ioOUT = F("Loop timer delay excessive =");
    ioOUT += (String)(millis() - toc[0]);
    ioOUT += F(" Loop delay greater than ");
    ioOUT += (String)toc[0];
    ioOUT += F(" milliseconds\n");
    Serial.println(ioOUT);
  }
}