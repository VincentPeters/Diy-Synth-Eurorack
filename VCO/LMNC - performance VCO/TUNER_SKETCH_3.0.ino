//This code is made using the very good sine wave freq detection by Amanda Ghassaei july 2012
//https://www.instructables.com/member/amandaghassaei/
//it is then put into the loop and the lights just light up when its there turn.

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
*/

//this is just a suggestion of what to put on the arduino. you can put anything you want!
//remember this is made by sam the dumbest coder on the planet.
//but it works! you cant dispute that haha.
//this is just a suggestion of what to put on the arduino. you can put anything you want!
//maybe something that rotates to the frequency? no ones saying you need a tuner haha.
//if anyone makes a different sketch they think is superior and want to share also definitely share
//there are a lot of free pins on the nano. maybe you could add a suboctave generator or something!
//just some ideas
//it is made to be quite accomadating for analog oscillators, it's probably best to fine track the oscillator
//with another tuner with more accuracy, this gives a ball park figure for gigs. and it works just fine
//for that!

//LED OUTPUT PINS


int LED3 = 18;
int LED4 = 19;
int LED5 = 17;


//7 segment display output pins;

int LEDE = 2;
int LEDD = 3;
int LEDC = 4;
int LEDDP = 5;
int LEDB = 9;
int LEDA = 8;
int LEDF = 7;
int LEDG = 6;


//clipping indicator variables
boolean clipping = 0;

//data storage variables
byte newData = 0;
byte prevData = 0;

//freq variables
unsigned int timer = 0;//counts period of wave
unsigned int period;
int frequency;

void setup(){


  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);


  pinMode(LEDE, OUTPUT);
  pinMode(LEDD, OUTPUT);
  pinMode(LEDC, OUTPUT);
  pinMode(LEDDP, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDA, OUTPUT);
  pinMode(LEDF, OUTPUT);
  pinMode(LEDG, OUTPUT);
  
  
 //to see frequency coming up on the serial uncomment the line beloe and also the serial code right at the bottom of this code page 

Serial.begin(9600);

  
  cli();//diable interrupts
  
  //set up continuous sampling of analog pin 0
  
  //clear ADCSRA and ADCSRB registers
  ADCSRA = 0;
  ADCSRB = 0;
  
  ADMUX |= (1 << REFS0); //set reference voltage
  ADMUX |= (1 << ADLAR); //left align the ADC value- so we can read highest 8 bits from ADCH register only
  
  ADCSRA |= (1 << ADPS2) | (1 << ADPS0); //set ADC clock with 32 prescaler- 16mHz/32=500kHz
  ADCSRA |= (1 << ADATE); //enabble auto trigger
  ADCSRA |= (1 << ADIE); //enable interrupts when measurement complete
  ADCSRA |= (1 << ADEN); //enable ADC
  ADCSRA |= (1 << ADSC); //start ADC measurements
  
  sei();//enable interrupts
}

ISR(ADC_vect) {//when new ADC value ready

  prevData = newData;//store previous value
  newData = ADCH;//get value from A0
  if (prevData < 127 && newData >=127){//if increasing and crossing midpoint
    period = timer;//get period
    timer = 0;//reset timer
  }
  
  timer++;//increment timer at rate of 38.5kHz
}

void loop(){


  frequency = 384620/period;//timer rate with an extra zero/period


if (0<frequency && 158>frequency)    {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
                                      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,LOW ));}

//C
                     
if ((158<frequency && 161>frequency) || (318<frequency && 323>frequency)  || (636<frequency && 650>frequency)   || (1272<frequency && 1302>frequency)   || (2550<frequency && 25590>frequency)   || (5155<frequency && 5170>frequency)   || (10180<frequency && 10320>frequency)  )   

   {(digitalWrite(LED3,HIGH)),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
    (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,LOW ));}


if ((161<frequency && 165>frequency) || (323<frequency && 330>frequency)  || (650<frequency && 660>frequency)   || (1302<frequency && 1315>frequency)   || (2590<frequency && 2640>frequency)   || (5170<frequency && 5300>frequency)   || (10320<frequency && 10730>frequency)  )    

   {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,HIGH)), (digitalWrite(LED5,LOW )),
    (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,LOW ));}


if ((165<frequency && 168>frequency) || (330<frequency && 336>frequency)  || (660<frequency && 674>frequency)   || (1315<frequency && 1350>frequency)   || (2640<frequency && 2690>frequency)   || (5300<frequency && 5400>frequency)   || (10730<frequency && 11000>frequency)  )    
   {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,HIGH)),
    (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,LOW ));}


//C#
                     

if ((168<frequency && 171>frequency) || (336<frequency && 345>frequency)  || (674<frequency && 689>frequency)   || (1350<frequency && 1378>frequency)   || (2690<frequency && 2750>frequency)   || (5420<frequency && 5500>frequency)   )  


   {(digitalWrite(LED3,HIGH)),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
    (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,LOW ));}

if ((171<frequency && 175>frequency) || (345<frequency && 351>frequency)  || (689<frequency && 698>frequency)   || (1378<frequency && 1392>frequency)   || (2750<frequency && 2800>frequency)   || (5490<frequency && 5591>frequency)   )    


   {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,HIGH)), (digitalWrite(LED5,LOW )),
    (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,LOW ));}

if ((175<frequency && 178>frequency) || (351<frequency && 356>frequency)  || (698<frequency && 714>frequency)   || (1392<frequency && 1429>frequency)   || (2800<frequency && 2855>frequency)   || (5581<frequency && 5700>frequency)   )    
    


   {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,HIGH)),
    (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,LOW ));}
                 



//D
                     


if ((178<frequency && 181>frequency)   || (356<frequency && 364>frequency)  || (714<frequency && 731>frequency)   || (1429<frequency && 1461>frequency)   || (2855<frequency && 2923>frequency)   || (5700<frequency && 5830>frequency)     )     


    {(digitalWrite(LED3,HIGH)),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
     (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,LOW )),(digitalWrite(LEDF,LOW )),(digitalWrite(LEDG,HIGH));}

if ((181<frequency && 185>frequency)   || (364<frequency && 370>frequency)  || (731<frequency && 741>frequency)    || (1461<frequency && 1475>frequency)   || (2923<frequency && 2955>frequency)   || (5820<frequency && 5930>frequency)    )    


    {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,HIGH)), (digitalWrite(LED5,LOW )),
     (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,LOW )),(digitalWrite(LEDF,LOW )),(digitalWrite(LEDG,HIGH));}

if ((185<frequency && 188>frequency)   || (370<frequency && 377>frequency)  || (741<frequency && 756>frequency)   || (1475<frequency && 1512>frequency)   || (2955<frequency && 3020>frequency)   || (5920<frequency && 6080>frequency)     )   


    {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,HIGH)),
     (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,LOW )),(digitalWrite(LEDF,LOW )),(digitalWrite(LEDG,HIGH));}





//D#
                     

if ((188<frequency && 192>frequency)  || (377<frequency && 386>frequency)  || (756<frequency && 776>frequency)    || (1512<frequency && 1548>frequency)   || (3020<frequency && 3090>frequency)   || (6080<frequency && 6190>frequency)      )    


    {(digitalWrite(LED3,HIGH)),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
     (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,LOW )),(digitalWrite(LEDF,LOW )),(digitalWrite(LEDG,HIGH));}

if ((192<frequency && 196>frequency)  || (386<frequency && 392>frequency)  || (776<frequency && 785>frequency)    || (1548<frequency && 1563>frequency)   || (3090<frequency && 3125>frequency)   || (6180<frequency && 300>frequency)      )     


    {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,HIGH)), (digitalWrite(LED5,LOW )),
     (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,LOW )),(digitalWrite(LEDF,LOW )),(digitalWrite(LEDG,HIGH));}

if ((196<frequency && 201>frequency)  || (392<frequency && 400>frequency)  || (785<frequency && 799>frequency)    || (1563<frequency && 1602>frequency)   || (3125<frequency && 3200>frequency)   || (6290<frequency && 6440>frequency)      )     


    {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,HIGH)),
     (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,LOW )),(digitalWrite(LEDF,LOW )),(digitalWrite(LEDG,HIGH));}



//E
                     

if ((201<frequency && 203>frequency)  || (400<frequency && 408>frequency)  || (799<frequency && 816>frequency)    || (1602<frequency && 1640>frequency)   || (3200<frequency && 3270>frequency)   || (6440<frequency && 6550>frequency)        )     


     {(digitalWrite(LED3,HIGH)),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}


if ((203<frequency && 208>frequency)   || (408<frequency && 415>frequency)  || (816<frequency && 829>frequency)    || (1640<frequency && 1656>frequency)   || (3270<frequency && 3330>frequency)   || (6540<frequency && 6660>frequency)        )    


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,HIGH)), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((208<frequency && 212>frequency)  || (415<frequency && 423>frequency)  || (829<frequency && 844>frequency)    || (1656<frequency && 1700>frequency)   || (3330<frequency && 3400>frequency)   || (6650<frequency && 6850>frequency)        )     


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,HIGH)),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}





//F0
                     


if ((212<frequency && 215>frequency)  || (423<frequency && 432>frequency)  || (844<frequency && 866>frequency)    || (1700<frequency && 1738>frequency)   || (3400<frequency && 3475>frequency)   || (6850<frequency && 6930>frequency)        )     


     {(digitalWrite(LED3,HIGH)),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,LOW )),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((215<frequency && 220>frequency)  || (432<frequency && 442>frequency)  || (866<frequency && 880>frequency)    || (1738<frequency && 1753>frequency)   || (3475<frequency && 3490>frequency)   || (6920<frequency && 7040>frequency)        )     


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,HIGH)), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,LOW )),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((220<frequency && 224>frequency)  || (442<frequency && 448>frequency)  || (880<frequency && 900>frequency)    || (1753<frequency && 1800>frequency)   || (3490<frequency && 3600>frequency)   || (7030<frequency && 7180>frequency)        )     


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,HIGH)),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,LOW )),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}




//F#0
                     


if ((224<frequency && 229>frequency)  || (448<frequency && 460>frequency)  || (900<frequency && 918>frequency)    || (1800<frequency && 1842>frequency)   || (3600<frequency && 3680>frequency)   || (7180<frequency && 7340>frequency)    )     


     {(digitalWrite(LED3,HIGH)),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,LOW )),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((229<frequency && 234>frequency)  || (460<frequency && 468>frequency)  || (918<frequency && 932>frequency)    || (1742<frequency && 1858>frequency)   || (3680<frequency && 3730>frequency)   || (7330<frequency && 7460>frequency)    )     



     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,HIGH)), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,LOW )),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((234<frequency && 239>frequency)  || (468<frequency && 476>frequency)  || (932<frequency && 955>frequency)    || (1858<frequency && 1915>frequency)   || (3730<frequency && 3820>frequency)   || (7450<frequency && 7630>frequency)    )     


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,HIGH)),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,LOW )),(digitalWrite(LEDC,LOW )),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,LOW )),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}







//G0
                     


if ((239<frequency && 242>frequency)  || (476<frequency && 487>frequency)  || (955<frequency && 973>frequency)    || (1915<frequency && 1953>frequency)   || (3820<frequency && 3900>frequency)   || (7763<frequency && 7800>frequency)  )     


     {(digitalWrite(LED3,HIGH)),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,LOW )),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((242<frequency && 247>frequency)  || (487<frequency && 494>frequency)  || (973<frequency && 988>frequency)    || (1953<frequency && 1968>frequency)   || (3900<frequency && 3950>frequency)   || (7790<frequency && 7910>frequency)  )     


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,HIGH)), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,LOW )),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((247<frequency && 252>frequency)  || (494<frequency && 505>frequency)  || (988<frequency && 1005>frequency)    || (1968<frequency && 2020>frequency)   || (3950<frequency && 4030>frequency)   || (7900<frequency && 8100>frequency)  )     


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,HIGH)),
      (digitalWrite(LEDE,LOW )),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}





//G#0
                     


if ((252<frequency && 257>frequency)  || (505<frequency && 516>frequency)  || (1005<frequency && 1031>frequency)   || (2020<frequency && 2068>frequency)   || (4030<frequency && 4110>frequency)   || (8100<frequency && 8270>frequency)      )     


     {(digitalWrite(LED3,HIGH)),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,LOW )),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((257<frequency && 261>frequency)  || (516<frequency && 525>frequency)  || (1031<frequency && 1045>frequency)   || (2068<frequency && 2085>frequency)   || (4110<frequency && 4180>frequency)    || (8260<frequency && 8390>frequency)     )     


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,HIGH)), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,LOW )),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((261<frequency && 266>frequency)  || (525<frequency && 538>frequency)  || (1045<frequency && 1075>frequency)   || (2085<frequency && 2155>frequency)   || (4180<frequency && 4265>frequency)   || (8380<frequency && 8570>frequency)      )     


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,HIGH)),
      (digitalWrite(LEDE,LOW )),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}



//A0


if ((266<frequency && 273>frequency)  || (538<frequency && 546>frequency)  || (1075<frequency && 1093>frequency)   || (2155<frequency && 2190>frequency)   || (4265<frequency && 4385>frequency)   || (8570<frequency && 8730>frequency)       )    


     {(digitalWrite(LED3,HIGH)),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,LOW )),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((273<frequency && 277>frequency)  || (546<frequency && 555>frequency)  || (1093<frequency && 1117>frequency)   || (2190<frequency && 2210>frequency)   || (4385<frequency && 4480>frequency)   || (8720<frequency && 8880>frequency)       )    


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,HIGH)), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,LOW )),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((277<frequency && 283>frequency)  || (555<frequency && 567>frequency)  || (1117<frequency && 1137>frequency)   || (2210<frequency && 2285>frequency)   || (4480<frequency && 4560>frequency)   || (8870<frequency && 9050>frequency)       )    


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,HIGH)),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,LOW )),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}



//A#0
                     


if ((283<frequency && 288>frequency)  || (567<frequency && 578>frequency)  || (1137<frequency && 1158>frequency)   || (2285<frequency && 2320>frequency)   || (4560<frequency && 4630>frequency)   || (9050<frequency && 9250>frequency)      )     


     {(digitalWrite(LED3,HIGH)),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,LOW )),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((288<frequency && 293>frequency)  || (578<frequency && 587>frequency)  || (1158<frequency && 1172>frequency)   || (2320<frequency && 2342>frequency)   || (4630<frequency && 4705>frequency)   || (9240<frequency && 9410>frequency)      )     


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,HIGH)), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,LOW )),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((293<frequency && 300>frequency)  || (585<frequency && 600>frequency)  || (1172<frequency && 1190>frequency)   || (2342<frequency && 2410>frequency)   || (4705<frequency && 4800>frequency)   || (9400<frequency && 9580>frequency)      )    


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,HIGH)),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,LOW )),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,HIGH)),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}




//B0


if ((300<frequency && 306>frequency)   || (600<frequency && 612>frequency)  || (1190<frequency && 1222>frequency)   || (2410<frequency && 2460>frequency)   || (4800<frequency && 4895>frequency)   || (9580<frequency && 9800>frequency)    )    


     {(digitalWrite(LED3,HIGH)),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((306<frequency && 312>frequency)   || (612<frequency && 623>frequency)  || (1222<frequency && 1237>frequency)   || (2460<frequency && 2482>frequency)   || (4895<frequency && 4950>frequency)    || (9790<frequency && 9990>frequency)   )   


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,HIGH)), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}

if ((312<frequency && 318>frequency)   || (623<frequency && 636>frequency)  || (1237<frequency && 1272>frequency)   || (2482<frequency && 2550>frequency)   || (4950<frequency && 5055>frequency)   || (9980<frequency && 10180>frequency)    )    


     {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,HIGH)),
      (digitalWrite(LEDE,HIGH)),(digitalWrite(LEDD,HIGH)),(digitalWrite(LEDC,HIGH)),(digitalWrite(LEDDP,LOW )),(digitalWrite(LEDB,HIGH)),(digitalWrite(LEDA,HIGH)),(digitalWrite(LEDF,HIGH)),(digitalWrite(LEDG,HIGH));}


//TOO HIGH FOR NOW
                     
if (  (10180<frequency && 100000>frequency) )    


      {(digitalWrite(LED3,LOW )),(digitalWrite(LED4,LOW )), (digitalWrite(LED5,LOW )),
      (digitalWrite(LEDE,LOW)),(digitalWrite(LEDD,LOW)),(digitalWrite(LEDC,LOW)),(digitalWrite(LEDDP,HIGH )),(digitalWrite(LEDB,LOW)),(digitalWrite(LEDA,LOW)),(digitalWrite(LEDF,LOW)),(digitalWrite(LEDG,LOW));}





delay(70);




 //uncomment this and the stuff at the top to see hz in the serial

Serial.print(frequency);

Serial.println("hz 1 decimal place");
  

}
