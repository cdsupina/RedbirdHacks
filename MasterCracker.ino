#include <LiquidCrystal.h>
#include <Keypad.h>
//joystick variables

int bossHealth = 12;
int playerHealth = 3;

int score = 0;
unsigned long timeLimit = 120000;
char secretWord[] = {'*','A','B','*'};
boolean secretFound = false;

int radius = 100;

int joyLR1 = 7;
int joyUD1 = 6;

//LR,UD
int joy1Pos1[] = {535, 0};
int joy1Pos2[] = {945, 181};
int joy1Pos3[] = {1023, 576};
int joy1Pos4[] = {958, 946};
int joy1Pos5[] = {534,1023};
int joy1Pos6[] = {227, 989};
int joy1Pos7[] = {11, 576};
int joy1Pos8[] = {262, 120};

int* joy1Positions[] = {joy1Pos1,joy1Pos2,joy1Pos3,joy1Pos4,joy1Pos5,joy1Pos6,joy1Pos7,joy1Pos8};

int joy2Pos1[] = {536, 0};
int joy2Pos2[] = {1000, 139};
int joy2Pos3[] = {1023, 554};
int joy2Pos4[] = {970, 947};
int joy2Pos5[] = {537, 1023};
int joy2Pos6[] = {311, 950};
int joy2Pos7[] = {84, 552};
int joy2Pos8[] = {267, 91};

int* joy2Positions[] = {joy2Pos1,joy2Pos2,joy2Pos3,joy2Pos4,joy2Pos5,joy2Pos6,joy2Pos7,joy2Pos8};


int joyLR2 = 5;
int joyUD2 = 4;

int button1 = 30;
int button2 = 35;
int button3 = 34;
int button4 = 33;

//lcd variables
LiquidCrystal lcd(38,40,42,44,46,48);

//LED Variables
int led1 = 22;
int led2 = 23;
int led3 = 24;
int led4 = 25;

int LEDs[] = {led1, led2, led3, led4};

int led5 = 26;
int led6 = 27;
int led7 = 28;
int led8 = 29;

int led9 = 13;
int led10 = 12;
int led11 = 11;
int led12 = 10;

int allLEDs[] = {led1, led2, led3, led4, led5, led6, led7, led8, led9, led10, led11, led12};

//Buzzer Variables
int buzzR = 2;
int buzzL = 3;

//Keypad Variables
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {39, 41, 43, 45}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {47, 49, 51, 53}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


void setup(){
  
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  lcd.begin(16,2);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("In a land");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("once peaceful,");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("now scorched");
  lcd.setCursor(0,1);
  lcd.print("by the");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Predatory");
  delay(500);
  lcd.setCursor(0,1);
  lcd.print("Privateer...");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The");
  lcd.setCursor(0,1);
  lcd.print("swashbuckling");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("beast now hides");
  lcd.setCursor(0,1);
  lcd.print("in the depths");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("of his notorious");
  delay(500);
  lcd.setCursor(0,1);
  lcd.print("galleon.");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Riddled with");
  lcd.setCursor(0,1);
  lcd.print("terrible");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("traps, and");
  lcd.setCursor(0,1);
  lcd.print("inpenetrable");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("locks, only");
  lcd.setCursor(0,1);
  lcd.print("one hero");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("stands");
  lcd.setCursor(0,1);
  lcd.print("a chance...");
  delay(3000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("THE MASTER");
  lcd.setCursor(0,1);
  lcd.print("       CRACKER  ");
  delay(3500);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  
  pinMode(buzzR, OUTPUT);
  pinMode(buzzL, OUTPUT);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Go!!!");
  delay(2000);
  
  //counter = 0;
  timeLimit += millis();
}

void loop(){
  
  delay(1000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  
  Serial.println(millis());
  Serial.println();
  
  
  if(millis()>timeLimit){
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Time's Up!");
    delay(1750);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Score:");
    lcd.setCursor(7,0);
    lcd.print(score);
    delay(3000);
    if(secretFound){
    
      secretLevel();
    }else{
    
      while(1){
      
        delay(1);
      }
    }
  }else{
    
    pickGame(random(1,5));
  }


  
} 

//########################################################################################################################################3

//### GAME 1: HIGH-LOW GUESSING GAME ### 
void guessNumber(){
  
  //Serial.println("Guess the number game started!");
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A magical");
  lcd.setCursor(0,1);
  lcd.print("numeral");
  delay(1000);
        
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("opens");
  delay(500);
  lcd.setCursor(0,1);
  lcd.print("this door...");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter a number.");
  int randNum = random(0,10);
  boolean unsolved = true;
  
  while(unsolved){
  
    char customKey = customKeypad.getKey();
  
    if (customKey){
      //Serial.println(customKey);
      int result = customKey - 48;
      beepR(7000);
      if(result == randNum){
      
        unsolved = false;
        
        int secret = random(0,3);
        
        if(secret == 0){
        
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("The door");
          lcd.setCursor(0,1);
          lcd.print("collapses...  2A");
        }else{
        
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("The door");
          lcd.setCursor(0,1);
          lcd.print("collapses...");
        }
        
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        score += 10;
      }else if(result > randNum){
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Enter a number.");
        lcd.setCursor(0,1);
        lcd.print("Too high!");
        //Serial.println("Too high!");
        digitalWrite(led1, LOW);
        digitalWrite(led4, HIGH);
      }else if(result < randNum){
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Enter a number.");
        lcd.setCursor(0,1);
        lcd.print("Too low!");
        //Serial.println("Too low!");
        digitalWrite(led1, HIGH);
        digitalWrite(led4, LOW);
      }
    }
  }
  
  
  
}

//### GAME 2: WORD GUESSING GAME ###
void guessWord(){
  
  //Serial.println("Guess the word game started!");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A mighty");
  lcd.setCursor(0,1);
  lcd.print("barrier, but");
  delay(1000);
        
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("weak to");
  delay(500);
  lcd.setCursor(0,1);
  lcd.print("certain runes");
  delay(500);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("of power...");
  delay(500);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter 4 letters.");
  
  char randWord[] = {pickLetter(), pickLetter(), pickLetter(), pickLetter()};
  for(int i =0; i<4; i++){
    //Serial.print(randWord[i]);
  }
  //Serial.println();
  boolean unsolved = true;
  
  while(unsolved){
  
    //make an array of 4 characters
    char guessWord[] = {'E','E','E','E'};
    
    
    for(int i = 0; i<4; i++){
      //Serial.println("Enter a letter.");
      
      if(i == 0){
        
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        digitalWrite(led8, HIGH);
      }
      
      if(i == 1){
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        digitalWrite(led8, LOW);
      }
      
      if(i == 2){
        
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, LOW);
        digitalWrite(led8, LOW);
      }
      
      if(i == 3){
        
        digitalWrite(led5, HIGH);
        digitalWrite(led6, LOW);
        digitalWrite(led7, LOW);
        digitalWrite(led8, LOW);
      }
      
      
      while(1){
        char customKey = customKeypad.getKey();
      
        if (customKey){
          
          
          //Serial.println(customKey);
          guessWord[i] = customKey;
          
        }
        
        if(guessWord[i] != 'E'){
          
          lcd.setCursor(i,1);
          lcd.print(guessWord[i]);
          beepR(7000);
          break;
        }
      }
      
    
    
    
    }
    //Serial.println("Four letters were entered. Here is the word:");
    
    boolean secretChars[] = {false,false,false,false};
    
    for(int i = 0; i<4; i++){
      
      //test for secret
      if(guessWord[i] == secretWord[i]){
      
        secretChars[i] = true;
      }
      
      lcd.setCursor(i,1);
      lcd.print(guessWord[i]);
    }
    
    int secretCorrectCount = 0;
    for(int i = 0; i<4; i++){
    
      if(secretChars[i]){
        secretCorrectCount ++;
      }
    }
    
    if(secretCorrectCount == 4){
      
      secretFound = true;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("The path");
      lcd.setCursor(0,1);
      lcd.print("suddenly");
      delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("seems clear.");
      delay(500);
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter 4 letters.");
    }
    
    
    
    //Array of characters aquired. test them with randWord
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    int counter = 0;
    
    if(randWord[0] == guessWord[0]){
      
      counter ++;
      digitalWrite(led1, HIGH);
    }
    
    if(randWord[1] == guessWord[1]){
      
      counter ++;
      digitalWrite(led2, HIGH);
    }
    
    if(randWord[2] == guessWord[2]){
      
      counter ++;
      digitalWrite(led3, HIGH);
    }
    
    if(randWord[3] == guessWord[3]){
      
      counter ++;
      digitalWrite(led4, HIGH);
    }
    
    if(counter == 4){
      
      unsolved = false;
      
      int secret = random(0,3);
      
      if(secret == 0){
      
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("The barrier");
        lcd.setCursor(0,1);
        lcd.print("vanishes...   1*");     
      }else{
      
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("The barrier");
        lcd.setCursor(0,1);
        lcd.print("vanishes...");
      }
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      score += 22;
    }
  }
  
}

//### GAME 3: JOYSTICK GUESSING GAME ###
void guessJoy(){
  
  //Serial.println("Joystick position game started!");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A faithful");
  lcd.setCursor(0,1);
  lcd.print("tumbler lock.");
  delay(1000);
        
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Your sturdy");
  delay(500);
  lcd.setCursor(0,1);
  lcd.print("picks");
  delay(500);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("should do...");
  delay(500);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Position");
  lcd.setCursor(0,1);
  lcd.print("your picks.");
  //joyStickTest();
  int rand1 = random(0,8);
  int randPos1[] = {joy1Positions[rand1][0],joy1Positions[rand1][1]};
  int randPos1LR = randPos1[0];
  int randPos1UD = randPos1[1];
  
  
  int rand2 = random(0,8);
  int randPos2[] = {joy2Positions[rand2][0],joy2Positions[rand2][1]};
  int randPos2LR = randPos2[0];
  int randPos2UD = randPos2[1];
  
  boolean unsolved = true;
  boolean joy1Solved = false;
  boolean joy2Solved = false;
  
  while(unsolved){
        
    if(withinRadius(analogRead(joyLR1),randPos1LR, radius) && withinRadius(analogRead(joyUD1), randPos1UD, radius)){
      joy1Solved = true;
      beepL(7000);  
    }else{
      joy1Solved = false;
    }
    
    if(withinRadius(analogRead(joyLR2),randPos2LR, radius) && withinRadius(analogRead(joyUD2), randPos2UD, radius)){
      joy2Solved = true;
      beepR(7000);  
    }else{
      joy2Solved = false;
    }
    
    if(joy1Solved && joy2Solved && digitalRead(button1)){
      
      unsolved = false;
      
      int secret = (0,3);
      
      if(secret == 0){
      
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("You hear");
        lcd.setCursor(0,1);
        lcd.print("a click...    4*");
      }else{
      
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("You hear");
        lcd.setCursor(0,1);
        lcd.print("a click...");
      }
      
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      score += 17;
    }
  }
  
}

//###GAME 4: PATTERN GAME###
void patternGame(){
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A test of");
  lcd.setCursor(0,1);
  lcd.print("patience.");
  delay(1000);
        
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Watch");
  delay(500);
  lcd.setCursor(0,1);
  lcd.print("carefully.");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Watch.");
  
  int rand1 = random(0,4);
  int rand2 = random(0,4);
  int rand3 = random(0,4);
  int rand4 = random(0,4);
  int rand5 = random(0,4);
  int rand6 = random(0,4);
  
  int randPattern[] = {rand1,rand2,rand3,rand4,rand5,rand6};
  boolean unsolved = true;
  
  for(int i = 0; i<6; i++){
    
    //Serial.print(randPattern[i]);
  }
  
  while(unsolved){
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Watch.");
    
    for(int i = 0; i<6; i++){
      
     
      
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      delay(100);
      if(i == 0){
        
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        digitalWrite(led8, HIGH);
      }else{
      
        digitalWrite(led5, LOW);
        digitalWrite(led6, LOW);
        digitalWrite(led7, LOW);
        digitalWrite(led8, LOW);
      }
      digitalWrite(LEDs[randPattern[i]], HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Watch.");
      lcd.setCursor(0,1);
      lcd.print(i+1);
      
      //Serial.println(randPattern[i]);
      delay(random(700,1051));
      
      
    }
    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    
    int counter = 0;
    int input[] = {4,4,4,4,4,4};
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Repeat.");
    
    while(1){
      
      if(digitalRead(button4)){
        
        input[counter] = 0;
        lcd.setCursor(counter,1);
        lcd.print(input[counter]+1);
        counter ++;
        delay(200);
      }else if(digitalRead(button3)){
        
        input[counter] = 1;
        lcd.setCursor(counter,1);
        lcd.print(input[counter]+1);
        counter ++;
        delay(200);
      }else if(digitalRead(button2)){
        
        input[counter] = 2;
        lcd.setCursor(counter,1);
        lcd.print(input[counter]+1);
        counter ++;
        delay(200);
      }else if(digitalRead(button1)){
        
        input[counter] = 3;
        lcd.setCursor(counter,1);
        lcd.print(input[counter]+1);
        counter ++;
        delay(200);
      }
      
      if(counter > 5){
      
        break;
      }
    }
    
    if((input[0] == randPattern[0])&&
      (input[1] == randPattern[1])&&
      (input[2] == randPattern[2])&&
      (input[3] == randPattern[3])&&
      (input[4] == randPattern[4])&&
      (input[5] == randPattern[5])){
      
      unsolved = false;
      int secret = random(0,3);
      
      if(secret == 0){
      
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Your nerves");
        lcd.setCursor(0,1);
        lcd.print("are at ease...3B");
      }else{
      
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Your nerves");
        lcd.setCursor(0,1);
        lcd.print("are at ease...");
      }
      
      
      
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      score += 25;
    }else{
      unsolved = false;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You get a");
      lcd.setCursor(0,1);
      lcd.print("bad feeling...");
      score -= 25;
    }
  }
}

//###SECRET BOSS###
void secretLevel(){
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The Golden");
  lcd.setCursor(0,1);
  lcd.print("Pirate Dragon,");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("infamous,");
  delay(500);
  lcd.setCursor(0,1);
  lcd.print("villainous,");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("is awoken by");
  lcd.setCursor(0,1);
  lcd.print("its foe's soft");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("footsteps.");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("It prepares to");
  lcd.setCursor(0,1);
  lcd.print("strike!");
  delay(3000);
  
  unsigned long attackTime = 12000;
  
  boolean boss = true;
  
  while(boss){
    updateBossHealth(bossHealth);
    pickAttack(random(1,5));
    if(bossHealth == 0){
      
      boss = false;
    }
    if(playerHealth == 0){
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You Died.");
      
      while(1){
        delay(1000);
      }
    }
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("You defeated");
  lcd.setCursor(0,1);
  lcd.print("the...");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Golden Pirate");
  lcd.setCursor(0,1);
  lcd.print("Dragon!");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CONGLATURATION!");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("YOU HAVE");
  lcd.setCursor(0,1);
  lcd.print("COMPLETED");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A GREAT GAME.");
  lcd.setCursor(0,1);
  lcd.print("AND PROOVED THE");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("JUSTICE OF OUR");
  lcd.setCursor(0,1);
  lcd.print("CULTURE.");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NOW GO AND REST");
  lcd.setCursor(0,1);
  lcd.print("OUR HEROES!");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Score:");
  lcd.setCursor(7,0);
  lcd.print(score);
  
  while(1){
    delay(1000);
  }
  
}

//###Number Attack###

int numberAtk(){
  
  //Serial.println("Guess the number game started!");
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("An");
  lcd.setCursor(0,1);
  lcd.print("opening...");
  delay(1000);
        
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Multiple strikes");
  lcd.setCursor(0,1);
  lcd.print("should quicken");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("this fight.");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter a number.");
  
  
  int guesses = 0;
  int randNum = random(0,10);
  boolean unsolved = true;
  
  while(unsolved){
  
    char customKey = customKeypad.getKey();
  
    if (customKey){
      //Serial.println(customKey);
      int result = customKey - 48;
      beepR(7000);
      guesses ++;
      
      if(result == randNum){
      
        unsolved = false;        
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("I strike!");
        
        
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        score += 10/guesses;
        delay(750);
        
        if(guesses < 4){
          bossHealth --;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Perfectly");
          lcd.setCursor(0,1);
          lcd.print("executed!");
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("A flurry of");
          lcd.setCursor(0,1);
          lcd.print("deadly attacks!");
          delay(1000);
        }else if(guesses <  6){
        
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Damn. A miss.");
          delay(1000);
        }else{
          playerHealth --;
          if(playerHealth == 2){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("The dragon");
            lcd.setCursor(0,1);
            lcd.print("unexpectedly");
            delay(1000);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("lashes out.");
            lcd.setCursor(0,1);
            lcd.print("I'm hit!");
            delay(1000);
          }
          
          if(playerHealth == 1){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("The dragon");
            lcd.setCursor(0,1);
            lcd.print("unexpectedly");
            delay(1000);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("lashes out.");
            delay(1000);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("I'm hit!");
            delay(1000);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("I don't think");
            lcd.setCursor(0,1);
            lcd.print("that I can take");
            delay(1000);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("another hit");
            lcd.setCursor(0,1);
            lcd.print("like this!");
            delay(1000);
          }
        }
      }else if(result > randNum){
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Enter a number.");
        lcd.setCursor(0,1);
        lcd.print("Too high!");
        //Serial.println("Too high!");
        digitalWrite(led1, LOW);
        digitalWrite(led4, HIGH);
      }else if(result < randNum){
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Enter a number.");
        lcd.setCursor(0,1);
        lcd.print("Too low!");
        //Serial.println("Too low!");
        digitalWrite(led1, HIGH);
        digitalWrite(led4, LOW);
      }
    }
  }
  
  
  
}


//### Attack 2: WORD GUESSING GAME ###
void wordAtk(){
  
  //Serial.println("Guess the word game started!");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A well placed");
  lcd.setCursor(0,1);
  lcd.print("spell shall");
  delay(1000);
        
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("surely banish");
  lcd.setCursor(0,1);
  lcd.print("this beastly");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("buccaneer!");
  delay(500);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter a word.");
  
  char randWord[] = {pickLetter(), pickLetter(), pickLetter(), pickLetter()};
  for(int i =0; i<4; i++){
    //Serial.print(randWord[i]);
  }
  //Serial.println();
  
  int guesses = 0;
  boolean unsolved = true;
  
  while(unsolved){
  
    //make an array of 4 characters
    char guessWord[] = {'E','E','E','E'};
    
    
    for(int i = 0; i<4; i++){
      //Serial.println("Enter a letter.");
      
      if(i == 0){
        
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        digitalWrite(led8, HIGH);
      }
      
      if(i == 1){
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        digitalWrite(led8, LOW);
      }
      
      if(i == 2){
        
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, LOW);
        digitalWrite(led8, LOW);
      }
      
      if(i == 3){
        
        digitalWrite(led5, HIGH);
        digitalWrite(led6, LOW);
        digitalWrite(led7, LOW);
        digitalWrite(led8, LOW);
      }
      
      
      while(1){
        char customKey = customKeypad.getKey();
      
        if (customKey){
          
          
          //Serial.println(customKey);
          guessWord[i] = customKey;
          
        }
        
        if(guessWord[i] != 'E'){
          
          lcd.setCursor(i,1);
          lcd.print(guessWord[i]);
          beepR(7000);
          break;
        }
      }
      
    
    
    
    }
    
    
    
    //Array of characters aquired. test them with randWord
    guesses ++;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    int counter = 0;
    
    if(randWord[0] == guessWord[0]){
      
      counter ++;
      digitalWrite(led1, HIGH);
    }
    
    if(randWord[1] == guessWord[1]){
      
      counter ++;
      digitalWrite(led2, HIGH);
    }
    
    if(randWord[2] == guessWord[2]){
      
      counter ++;
      digitalWrite(led3, HIGH);
    }
    
    if(randWord[3] == guessWord[3]){
      
      counter ++;
      digitalWrite(led4, HIGH);
    }
    
    if(counter == 4){
      
      unsolved = false;
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("I strike!");
      
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      delay(750);
      score += 22/guesses;  
      if(guesses < 5){
        bossHealth --;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Perfectly");
        lcd.setCursor(0,1);
        lcd.print("executed!");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("A magic");
        lcd.setCursor(0,1);
        lcd.print("missle!");
        delay(1000);
      }else if(guesses <  6){
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Damn. A miss.");
        delay(1000);
      }else{
        playerHealth --;
        if(playerHealth == 2){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("The dragon");
          lcd.setCursor(0,1);
          lcd.print("unexpectedly");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("lashes out.");
          lcd.setCursor(0,1);
          lcd.print("I'm hit!");
          delay(1000);
        }
          
        if(playerHealth == 1){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("The dragon");
          lcd.setCursor(0,1);
          lcd.print("unexpectedly");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("lashes out.");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("I'm hit!");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("I don't think");
          lcd.setCursor(0,1);
          lcd.print("that I can take");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("another hit");
          lcd.setCursor(0,1);
          lcd.print("like this!");
          delay(1000);
        }
      
      }
    }
  }
  
}

///###ATTAKCK 3: JOY Attack###

void joyAtk(){
  
  //Serial.println("Joystick position game started!");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A masterful");
  lcd.setCursor(0,1);
  lcd.print("strike should");
  delay(1000);
        
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("maim this");
  lcd.setCursor(0,1);
  lcd.print("marauder.");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Prepare");
  lcd.setCursor(0,1);
  lcd.print("your strike.");
  
  //joyStickTest();
  int rand1 = random(0,8);
  int randPos1[] = {joy1Positions[rand1][0],joy1Positions[rand1][1]};
  int randPos1LR = randPos1[0];
  int randPos1UD = randPos1[1];
  
  
  int rand2 = random(0,8);
  int randPos2[] = {joy2Positions[rand2][0],joy2Positions[rand2][1]};
  int randPos2LR = randPos2[0];
  int randPos2UD = randPos2[1];
  
  boolean unsolved = true;
  boolean joy1Solved = false;
  boolean joy2Solved = false;
  
  unsigned long time1 = millis();
  while(unsolved){
        
    if(withinRadius(analogRead(joyLR1),randPos1LR, radius) && withinRadius(analogRead(joyUD1), randPos1UD, radius)){
      joy1Solved = true;
      beepL(7000);  
    }else{
      joy1Solved = false;
    }
    
    if(withinRadius(analogRead(joyLR2),randPos2LR, radius) && withinRadius(analogRead(joyUD2), randPos2UD, radius)){
      joy2Solved = true;
      beepR(7000);  
    }else{
      joy2Solved = false;
    }
    
    if(joy1Solved && joy2Solved && digitalRead(button1)){
      
      unsolved = false;
      
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("I strike!");
      
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      delay(750);
      score += 17/((millis()-time1)/1000);
      
      if((millis()-time1)/1000 < 12){
        bossHealth --;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Perfectly");
        lcd.setCursor(0,1);
        lcd.print("executed!");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Such refined");
        lcd.setCursor(0,1);
        lcd.print("technique!");
        delay(1000);
      }else if((millis()-time1)/1000 <  15){
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Damn. A miss.");
        delay(1000);
      }else{
        playerHealth --;
        if(playerHealth == 2){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("The dragon");
          lcd.setCursor(0,1);
          lcd.print("unexpectedly");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("lashes out.");
          lcd.setCursor(0,1);
          lcd.print("I'm hit!");
          delay(1000);
        }
          
        if(playerHealth == 1){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("The dragon");
          lcd.setCursor(0,1);
          lcd.print("unexpectedly");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("lashes out.");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("I'm hit!");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("I don't think");
          lcd.setCursor(0,1);
          lcd.print("that I can take");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("another hit");
          lcd.setCursor(0,1);
          lcd.print("like this!");
          delay(1000);
        }
      
      }
      
    }
  }
  
}

//###ATTACK 4: Pattern###
void patternAtk(){
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The dragon");
  lcd.setCursor(0,1);
  lcd.print("prepares a");
  delay(1000);
        
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("devasting");
  lcd.setCursor(0,1);
  lcd.print("fire attack.");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("It can be");
  lcd.setCursor(0,1);
  lcd.print("countered");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("if watched");
  lcd.setCursor(0,1);
  lcd.print("closely.");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Watch.");
  
  int rand1 = random(0,4);
  int rand2 = random(0,4);
  int rand3 = random(0,4);
  int rand4 = random(0,4);
  int rand5 = random(0,4);
  int rand6 = random(0,4);
  
  int randPattern[] = {rand1,rand2,rand3,rand4,rand5,rand6};
  boolean unsolved = true;
  
  for(int i = 0; i<6; i++){
    
    //Serial.print(randPattern[i]);
  }
  
  while(unsolved){
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Watch.");
    
    for(int i = 0; i<6; i++){
      
     
      
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      delay(100);
      if(i == 0){
        
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        digitalWrite(led8, HIGH);
      }else{
      
        digitalWrite(led5, LOW);
        digitalWrite(led6, LOW);
        digitalWrite(led7, LOW);
        digitalWrite(led8, LOW);
      }
      digitalWrite(LEDs[randPattern[i]], HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Watch.");
      lcd.setCursor(0,1);
      lcd.print(i+1);
      
      //Serial.println(randPattern[i]);
      delay(random(700,1051));
      
      
    }
    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    
    int counter = 0;
    int input[] = {4,4,4,4,4,4};
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Repeat.");
    
    while(1){
      
      if(digitalRead(button4)){
        
        input[counter] = 0;
        lcd.setCursor(counter,1);
        lcd.print(input[counter]+1);
        counter ++;
        delay(200);
      }else if(digitalRead(button3)){
        
        input[counter] = 1;
        lcd.setCursor(counter,1);
        lcd.print(input[counter]+1);
        counter ++;
        delay(200);
      }else if(digitalRead(button2)){
        
        input[counter] = 2;
        lcd.setCursor(counter,1);
        lcd.print(input[counter]+1);
        counter ++;
        delay(200);
      }else if(digitalRead(button1)){
        
        input[counter] = 3;
        lcd.setCursor(counter,1);
        lcd.print(input[counter]+1);
        counter ++;
        delay(200);
      }
      
      if(counter > 5){
      
        break;
      }
    }
    
    if((input[0] == randPattern[0])&&
      (input[1] == randPattern[1])&&
      (input[2] == randPattern[2])&&
      (input[3] == randPattern[3])&&
      (input[4] == randPattern[4])&&
      (input[5] == randPattern[5])){
      
      unsolved = false;
      
      bossHealth--;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Successfully");
      lcd.setCursor(0,1);
      lcd.print("countered!");
      
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      delay(750);
      score += 25/2;
    }else{
      unsolved = false;
      playerHealth --;
      
      if(playerHealth == 2){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("The dragon");
          lcd.setCursor(0,1);
          lcd.print("breathes its");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("spoiled flame.");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("It burns!");
          delay(1000);
        }
          
        if(playerHealth == 1){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("The dragon");
          lcd.setCursor(0,1);
          lcd.print("breathes its");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("spoiled flame.");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("It burns!");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("I don't think");
          lcd.setCursor(0,1);
          lcd.print("that I can take");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("another hit");
          lcd.setCursor(0,1);
          lcd.print("like this!");
          delay(1000);
        }
      
      score -= 25/2;
    }
  }
}
//#####################HELPER#####################

void pickGame(int gameID){

  if(gameID == 1){
  
    guessNumber();
  }
  
  if(gameID == 2){
  
    guessWord();
  }
  
  if(gameID == 3){
  
    guessJoy();
  }
  
  if(gameID == 4){
  
    patternGame();
  }
  
}

void pickAttack(int atkID){

  if(atkID == 1){
  
    numberAtk();
  }
  
  if(atkID == 2){
  
    wordAtk();
  }
  
  if(atkID == 3){
  
    joyAtk();
  }
  
  if(atkID == 4){
  
    patternAtk();
  }
  
}

char pickLetter(){

  int rand = random(1,5);
  
  if(rand == 1){
    
    return 'A';
  }
  
  if(rand == 2){
  
    return 'B';
  }
  
  if(rand == 3){
  
    return 'C';
  }
  
  if(rand == 4){
  
    return 'D';
  }
  
}

void beepR(unsigned char delayms) { //creating function

  analogWrite(buzzR, 1); //Setting pin to high
  delay(delayms); //Delaying
  analogWrite(buzzR, 0); //Setting pin to LOW
  delay(delayms); //Delaying 
}

void beepL(unsigned char delayms) { //creating function

  analogWrite(buzzL, 1); //Setting pin to high
  delay(delayms); //Delaying
  analogWrite(buzzL, 0); //Setting pin to LOW
  delay(delayms); //Delaying 
}

void joyStickTest(){

  Serial.println("***Analog Readings***");
  Serial.print("joyLR1: ");
  Serial.println(analogRead(joyLR1));
  Serial.print("joyUD1: ");
  Serial.println(analogRead(joyUD1));
  Serial.print("joyLR2: ");
  Serial.println(analogRead(joyLR2));
  Serial.print("joyUD2: ");
  Serial.println(analogRead(joyUD2));
}

boolean withinRadius(int input, int test, int radius){
  
  boolean result = false;
  
  if((input >= test-radius) && (input <= test+radius)){
    
    result = true;
  }
  
  return result;
}

void updateBossHealth(int health){
  
  for(int i = 0; i<12; i++){
  
    digitalWrite(allLEDs[i], LOW);
  }
  
  for(int i = 0; i< 12; i++){
    
    
    
    
    if(health > 0){
      
      digitalWrite(allLEDs[i], HIGH);
      health--;
    }  
  }
}


