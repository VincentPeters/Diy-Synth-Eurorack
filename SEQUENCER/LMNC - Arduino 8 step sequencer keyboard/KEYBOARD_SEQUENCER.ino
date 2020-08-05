//LOOK MUM NO COMPUTER KEYBOARD SEQUENCER. A SIMPLE DESIGN TO MAKE A 4017 STYLE SEQUENCER WITH MORE ADDED FUNCTIONS.
//MORE INFO CHECK LOOKMUMNOCOMPUTER.COM
//PLEASE EMAIL ME COMPUTER@LOOKMUMNOCOMPUTER.COM OR LOOKMUMNOCOMPUTER@GMAIL.COM IF ANY QUESTIONS
//ANY MODIFICATIONS PLEASE LET ME KNOW AND I CAN FEATURE ON THE WEBSITE
//OPEN SOURCE. DONT USE IN A PRODUCT OR WHATEVER WITHOUT TALKING TO ME
//SAM BATTLE 2017
//BOOM



//ALSO TO ADD! I HAVE MADE THIS CODE IN A WAY ITS EASY TO UNDERSTAND FOR A NONE CODER (LIKE MYSELF)
//I REMEMBER WHEN I STARTED ON ARDUINO BEING LIKE WHAT THE HELL IS GOING ON.
//SO IVE LAYED IT OUT LOGICALLY, SEINSE IT ISNT A COMPLICATED PROGRAM I FIGURED WHY THE HECK NOT!

//SO YES THIS ISNT THE BEST WAY OF GOING ABOUT THIS HOWEVER IT IS THE EASIEST TO UNDERSTAND
//FOR A NONE CODER MIND.


#define STEP1 2
#define STEP2 3
#define STEP3 4
#define STEP4 5
#define STEP5 6
#define STEP6 7
#define STEP7 8
#define STEP8 9
#define STEPBUTTON1   14
#define STEPBUTTON2   15
#define STEPBUTTON3   16
#define STEPBUTTON4   17
#define STEPBUTTON5   18
#define STEPBUTTON6   19
#define STEPBUTTON7   21
#define STEPBUTTON8   20

#define FORWARDS 12
#define VARIATION 19
#define RESET 10
#define BACK 13
#define ZERO 11

//ABOVE BASICALLY DEFINES THE NAMES OF THE PINS, PLEASE REMEMBER THE ANALOG PINS A0,A1,A2, BLAH BLAH CAN BE USED AS DIGITAL PINS. THE ARE
//DIGITAL 14 and UP!


int val = 0;
int old_val = 0;
int val1 = 0;
int old_val1 = 0;
int val2 = 0;
int old_val2 = 0;
int val3 = 0;
int old_val3 = 0;
int val4 = 0;
int old_val4 = 0;


int vals1 = 0;
int old_vals1 = 0;
int vals2 = 0;
int old_vals2 = 0;
int vals3 = 0;
int old_vals3 = 0;
int vals4 = 0;
int old_vals4 = 0;
int vals5 = 0;
int old_vals5 = 0;
int vals6 = 0;
int old_vals6 = 0;
int vals7 = 0;
int old_vals7 = 0;
int vals8 = 0;
int old_vals8 = 0;


int state = 0;
int led = 17;
int newled = 1;


void setup ()
{
  pinMode (STEP1, OUTPUT);
  pinMode (STEP2, OUTPUT);
  pinMode (STEP3, OUTPUT);
  pinMode (STEP4, OUTPUT);
  pinMode (STEP5, OUTPUT);
  pinMode (STEP6, OUTPUT);
  pinMode (STEP7, OUTPUT);
  pinMode (STEP8, OUTPUT);
  pinMode (FORWARDS, INPUT);
  pinMode (BACK, INPUT);
  pinMode (RESET, INPUT);
  pinMode (ZERO, INPUT);
  pinMode (STEPBUTTON1, INPUT);
  pinMode (STEPBUTTON2, INPUT);
  pinMode (STEPBUTTON3, INPUT);
  pinMode (STEPBUTTON4, INPUT);
  pinMode (STEPBUTTON5, INPUT);
  pinMode (STEPBUTTON6, INPUT);

  //SET THE PINS TO IN OR OUT
  

}


void loop ()
{  
  val1 = digitalRead (FORWARDS);
   if((val1 == HIGH) && (old_val1 == LOW))
   
   {
    newled = led - 1; 
     if (newled <=8) { newled = 16; } 
    led = newled;
   
   }

//THIS IS THE THING THAT MAKES IT GO FORWARDS, IT SAYS -1 YOULL SEE ALL OF THE NUMBERS AND WHAT THEY DO BELOW
   
       val2 = digitalRead (ZERO);
   if((val2 == HIGH) && (old_val2 == LOW))
   
   {
    newled = led = 17;
    led = newled;
   }
  
//THIS MAKES THE ZERO COMMAND WORK. 17 IS WHEN NO LIGHTS ARE ON 
   
    val3 = digitalRead (RESET);
   if((val3 == HIGH) && (old_val3 == LOW))
   
   {
    newled = led = 16;
    led = newled;
   }

//RESET BACK TO STEP 1

     val4 = digitalRead (BACK);
   if((val4 == HIGH) && (old_val4 == LOW))
   
   {
    newled = led + 1; 
     if (newled >=17 ) { newled = 9; } 
    led = newled;
   
   }

//GO BACKWARDS

//BELOW ARE ALL OF THE STEP BUTTONS AND WHAT THEY DO. BASICALLY WHEN THEY ARE HIT THE LED NUMBER GOES TO THE RIGHT NUMBER

     vals1 = digitalRead (STEPBUTTON1);
   if((vals1 == HIGH) && (old_vals1 == LOW))
   
   {
    newled = led = 16;
   
   }
    
     vals2 = digitalRead (STEPBUTTON2);
   if((vals2 == HIGH) && (old_vals2 == LOW))
   
   {
    newled = led = 15;
   
   }

     vals3 = digitalRead (STEPBUTTON3);
   if((vals3 == HIGH) && (old_vals3 == LOW))
   
   {
    newled = led = 14;
   
   }

     vals4 = digitalRead (STEPBUTTON4);
   if((vals4 == HIGH) && (old_vals4 == LOW))
   
   {
    newled = led = 13;
   
   }
   

     vals5 = digitalRead (STEPBUTTON5);
   if((vals5 == HIGH) && (old_vals5 == LOW))
   
   {
    newled = led = 12;
   
   }
   
     vals6 = digitalRead (STEPBUTTON6);
   if((vals6 == HIGH) && (old_vals6 == LOW))
   
   {
    newled = led = 11;
   
   }

     vals7 = analogRead (STEPBUTTON7);
   if((vals7 >= 1000) && (old_vals7 <= 1000))
   
   {
    newled = led = 10;
   
   }
  
      vals8 = analogRead (STEPBUTTON8);
   if((vals8 >= 1000) && (old_vals8 <= 1000))
   
   {
    newled = led = 9;
   
   }
  
  old_val = val;
  old_val1 = val1;
  old_val2 = val2;
  old_val3 = val3;
  old_val4 = val4;


  if (newled >=17 ) { newled = 9; } 
  if (newled <=8 ) { newled = 16; } 
  
      

  
 //BELOW ARE ALL OF THE NU<BERS AND WHAT THEY DO!
 
  if (led == 17)
  {
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, LOW);
    digitalWrite(STEP3, LOW);
    digitalWrite(STEP4, LOW);
    digitalWrite(STEP5, LOW);
    digitalWrite(STEP6, LOW);
    digitalWrite(STEP7, LOW);
    digitalWrite(STEP8, LOW);
  }
 
  if (led == 16)
  {
    digitalWrite(STEP1, HIGH);
    digitalWrite(STEP2, LOW);
    digitalWrite(STEP3, LOW);
    digitalWrite(STEP4, LOW);
    digitalWrite(STEP5, LOW);
    digitalWrite(STEP6, LOW);
    digitalWrite(STEP7, LOW);
    digitalWrite(STEP8, LOW);      
  }
 if (led == 15)
  {
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, HIGH);
    digitalWrite(STEP3, LOW);
     digitalWrite(STEP4, LOW);
     digitalWrite(STEP5, LOW);
     digitalWrite(STEP6, LOW);
     digitalWrite(STEP7, LOW);
     digitalWrite(STEP8, LOW);
         }
 if (led == 14)
  {
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, LOW);
    digitalWrite(STEP3, HIGH);
     digitalWrite(STEP4, LOW);
     digitalWrite(STEP5, LOW);
     digitalWrite(STEP6, LOW);
     digitalWrite(STEP7, LOW);
     digitalWrite(STEP8, LOW);

  
  } 
 if (led == 13)
  {
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, LOW);
    digitalWrite(STEP3, LOW);
     digitalWrite(STEP4, HIGH);
     digitalWrite(STEP5, LOW);
     digitalWrite(STEP6, LOW);
     digitalWrite(STEP7, LOW);
     digitalWrite(STEP8, LOW);

  } 
   if (led == 12)
  {
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, LOW);
    digitalWrite(STEP3, LOW);
     digitalWrite(STEP4, LOW);
     digitalWrite(STEP5, HIGH);
     digitalWrite(STEP6, LOW);
     digitalWrite(STEP7, LOW);
     digitalWrite(STEP8, LOW);

  } 
   if (led == 11)
  {
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, LOW);
    digitalWrite(STEP3, LOW);
     digitalWrite(STEP4, LOW);
     digitalWrite(STEP5, LOW);
     digitalWrite(STEP6, HIGH);
     digitalWrite(STEP7, LOW);
     digitalWrite(STEP8, LOW);

  } 
     if (led == 10)
  {
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, LOW);
    digitalWrite(STEP3, LOW);
     digitalWrite(STEP4, LOW);
     digitalWrite(STEP5, LOW);
     digitalWrite(STEP6, LOW);
     digitalWrite(STEP7, HIGH);
     digitalWrite(STEP8, LOW);

  } 
       if (led == 9)
  {
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, LOW);
    digitalWrite(STEP3, LOW);
     digitalWrite(STEP4, LOW);
     digitalWrite(STEP5, LOW);
     digitalWrite(STEP6, LOW);
     digitalWrite(STEP7, LOW);
     digitalWrite(STEP8, HIGH);

  } 
   if (led == 8)
  {
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, LOW);
    digitalWrite(STEP3, LOW);
     digitalWrite(STEP4, LOW);
     digitalWrite(STEP5, LOW);
     digitalWrite(STEP6, LOW);
     digitalWrite(STEP7, LOW);
     digitalWrite(STEP8, LOW);

  } 

}
