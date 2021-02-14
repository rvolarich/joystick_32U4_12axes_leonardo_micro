/*
 *    The program creates three USB joysticks on one ATmega32U4 chip each having 4 axes, 12 in total. 
 *    It is compatible with Arduino Leonardo and Micro boards.
 *    
 *    Author: Robert Volaric 
 */

#include <Joystick12ch32u4.h>

#define _1_A_X  A0  // _1_ X A0
#define _1_A_Y  A1  // _1_ Y A1
#define _1_A_Z  A2  // _1_ Z A2
#define _1_A_XR  A3  // _1_ XRotation A3


#define _2_A_X  A4  // _2_ X A4
#define _2_A_Y  A5  // _2_ Y A5
#define _2_A_Z  A6  // _2_ Z D4
#define _2_A_XR  A7  // _2_ XRotation D6


#define _3_A_X  A8  // _3_ X D8
#define _3_A_Y  A9  // _3_ Y D9
#define _3_A_Z  A10  // _3_ Z D10
#define _3_A_XR  A11  // _3_ XRotation D12


#define MARGIN_POS 8 // threshold for loop exit, eliminates small changes on adc
#define MARGIN_NEG -8

#define WIRE_LOOP_DELAY 0

int _1_X_value, _1_Y_value, _1_Z_value, _1_XR_value;
int _2_X_value, _2_Y_value, _2_Z_value, _2_XR_value;
int _3_X_value, _3_Y_value, _3_Z_value, _3_XR_value;

int _1_XLastPotState = 0;
int _1_XCurrentPotState;
int _1_YLastPotState = 0;
int _1_YCurrentPotState;
int _1_ZLastPotState = 0;
int _1_ZCurrentPotState;
int _1_XRLastPotState = 0;
int _1_XRCurrentPotState;


int _2_XLastPotState = 0;
int _2_XCurrentPotState;
int _2_YLastPotState = 0;
int _2_YCurrentPotState;
int _2_ZLastPotState = 0;
int _2_ZCurrentPotState;
int _2_XRLastPotState = 0;
int _2_XRCurrentPotState;


int _3_XLastPotState = 0;
int _3_XCurrentPotState;
int _3_YLastPotState = 0;
int _3_YCurrentPotState;
int _3_ZLastPotState = 0;
int _3_ZCurrentPotState;
int _3_XRLastPotState = 0;
int _3_XRCurrentPotState;

bool lastValueAll = true; // controls initial state of all lastState variables
bool initState = true;

void setup() {

Joystick_ begin();
 
 pinMode(_1_A_X, INPUT); // for any unused input change to pinMode(pin, INPUT_PULLUP)
 pinMode(_1_A_Y, INPUT);
 pinMode(_1_A_Z, INPUT);
 pinMode(_1_A_XR, INPUT);
 pinMode(_2_A_X, INPUT);
 pinMode(_2_A_Y, INPUT);
 pinMode(_2_A_Z, INPUT);
 pinMode(_2_A_XR, INPUT);
 pinMode(_3_A_X, INPUT);
 pinMode(_3_A_Y, INPUT);
 pinMode(_3_A_Z, INPUT);
 pinMode(_3_A_XR, INPUT);
}


void loop() {

Joystick_ _1_(0);
Joystick_ _2_(1);
Joystick_ _3_(2);


    if(initState){
        
    if(lastValueAll){

      // Joystick 1
      
      _1_XCurrentPotState = analogRead(_1_A_X);
      _1_XLastPotState = _1_XCurrentPotState / 4;
      _1_YCurrentPotState = analogRead(_1_A_Y);
      _1_YLastPotState = _1_YCurrentPotState / 4;
      _1_ZCurrentPotState = analogRead(_1_A_Z);
      _1_ZLastPotState = _1_ZCurrentPotState / 4;
      _1_XRCurrentPotState = analogRead(_1_A_XR);
      _1_XRLastPotState = _1_XRCurrentPotState / 4;
     
      
       // Joystick 2
      
      _2_XCurrentPotState = analogRead(_2_A_X);
      _2_XLastPotState = _2_XCurrentPotState / 4;
      _2_YCurrentPotState = analogRead(_2_A_Y);
      _2_YLastPotState = _2_YCurrentPotState / 4;
      _2_ZCurrentPotState = analogRead(_2_A_Z);
      _2_ZLastPotState = _2_ZCurrentPotState / 4;
      _2_XRCurrentPotState = analogRead(_2_A_XR);
      _2_XRLastPotState = _2_XRCurrentPotState / 4;
      
      
       // Joystick 3
      
      _3_XCurrentPotState = analogRead(_3_A_X);
      _3_XLastPotState = _3_XCurrentPotState / 4;
      _3_YCurrentPotState = analogRead(_3_A_Y);
      _3_YLastPotState = _3_YCurrentPotState / 4;
      _3_ZCurrentPotState = analogRead(_3_A_Z);
      _3_ZLastPotState = _3_ZCurrentPotState / 4;
      _3_XRCurrentPotState = analogRead(_3_A_XR);
      _3_XRLastPotState = _3_XRCurrentPotState / 4;
      
      lastValueAll = false;
       
    }

    _1_.setXAxis(_1_XLastPotState);
    _1_.setYAxis(_1_YLastPotState);
    _1_.setZAxis(_1_ZLastPotState);
    _1_.setXAxisRotation(_1_XRLastPotState);
    _1_.sendState();

    _2_.setXAxis(_2_XLastPotState);
    _2_.setYAxis(_2_YLastPotState);
    _2_.setZAxis(_2_ZLastPotState);
    _2_.setXAxisRotation(_2_XRLastPotState);
    _2_.sendState();

    _3_.setXAxis(_3_XLastPotState);
    _3_.setYAxis(_3_YLastPotState);
    _3_.setZAxis(_3_ZLastPotState);
    _3_.setXAxisRotation(_3_XRLastPotState);
    _3_.sendState();
    
    delay(200);
    
   }

  //Joystick 1***************************************************************************************************

  // Joystick _1_ X Axis

  _1_XCurrentPotState = analogRead(_1_A_X) / 4;

  while(_1_XCurrentPotState != _1_XLastPotState){

    if(_1_XCurrentPotState - _1_XLastPotState < MARGIN_POS && _1_XCurrentPotState - _1_XLastPotState > MARGIN_NEG){

        break;
    }
    
   initState = false;
   _1_X_value = analogRead(_1_A_X);
   _1_.setXAxis(_1_X_value / 4);
  
   _1_XLastPotState = _1_XCurrentPotState;
   _1_.sendState();
  }

  // Joystick _1_ Y Axis

  _1_YCurrentPotState = analogRead(_1_A_Y) / 4;

  while(_1_YCurrentPotState != _1_YLastPotState){

    if(_1_YCurrentPotState - _1_YLastPotState < MARGIN_POS && _1_YCurrentPotState - _1_YLastPotState > MARGIN_NEG){

        break;
    }
    
   initState = false;
   _1_Y_value = analogRead(_1_A_Y);
   _1_.setYAxis(_1_Y_value / 4);
   _1_YLastPotState = _1_YCurrentPotState;
   _1_.sendState();
  }

  // Joystick _1_ Z Axis

  _1_ZCurrentPotState = analogRead(_1_A_Z) / 4;

  while(_1_ZCurrentPotState != _1_ZLastPotState){

    if(_1_ZCurrentPotState - _1_ZLastPotState < MARGIN_POS && _1_ZCurrentPotState - _1_ZLastPotState > MARGIN_NEG){

        break;
    }
    
   initState = false;
   _1_Z_value = analogRead(_1_A_Z);
   _1_.setZAxis(_1_Z_value / 4);
   _1_ZLastPotState = _1_ZCurrentPotState;
   _1_.sendState();
  }

  // Joystick _1_ X Axis Rotation

  _1_XRCurrentPotState = analogRead(_1_A_XR) / 4;

  while(_1_XRCurrentPotState != _1_XRLastPotState){

    if(_1_XRCurrentPotState - _1_XRLastPotState < MARGIN_POS && _1_XRCurrentPotState - _1_XRLastPotState > MARGIN_NEG){

        break;
    }
    
   initState = false;
   _1_XR_value = analogRead(_1_A_XR);
   _1_.setXAxisRotation(_1_XR_value / 4);
   _1_XRLastPotState = _1_XRCurrentPotState;
   _1_.sendState();
  }


  // Joystick 2 ******************************************************************************************************

  // Joystick _2_ X Axis

  _2_XCurrentPotState = analogRead(_2_A_X) / 4;

  while(_2_XCurrentPotState != _2_XLastPotState){

    if(_2_XCurrentPotState - _2_XLastPotState < MARGIN_POS && _2_XCurrentPotState - _2_XLastPotState > MARGIN_NEG){

        break;
    }
    
    initState = false;
   _2_X_value = analogRead(_2_A_X);
   _2_.setXAxis(_2_X_value / 4);
   _2_XLastPotState = _2_XCurrentPotState;
   _2_.sendState();
   
  }

  // Joystick _2_ Y Axis

  _2_YCurrentPotState = analogRead(_2_A_Y) / 4;

  while(_2_YCurrentPotState != _2_YLastPotState){

    if(_2_YCurrentPotState - _2_YLastPotState < MARGIN_POS && _2_YCurrentPotState - _2_YLastPotState > MARGIN_NEG){

        break;
    }
    
    initState = false;
   _2_Y_value = analogRead(_2_A_Y);
   _2_.setYAxis(_2_Y_value / 4);
   _2_YLastPotState = _2_YCurrentPotState;
   _2_.sendState();
   
  }

  // Joystick _2_ Z Axis

  _2_ZCurrentPotState = analogRead(_2_A_Z) / 4;

  while(_2_ZCurrentPotState != _2_ZLastPotState){

    if(_2_ZCurrentPotState - _2_ZLastPotState < MARGIN_POS && _2_ZCurrentPotState - _2_ZLastPotState > MARGIN_NEG){

        break;
    }
    
    initState = false;
   _2_Z_value = analogRead(_2_A_Z);
   _2_.setZAxis(_2_Z_value / 4);
   _2_ZLastPotState = _2_ZCurrentPotState;
   _2_.sendState();
   
  }
  
  
  // Joystick _2_ X Axis Rotation

  _2_XRCurrentPotState = analogRead(_2_A_XR) / 4;

  while(_2_XRCurrentPotState != _2_XRLastPotState){

    if(_2_XRCurrentPotState - _2_XRLastPotState < MARGIN_POS && _2_XRCurrentPotState - _2_XRLastPotState > MARGIN_NEG){

        break;
    }
    
    initState = false;
   _2_XR_value = analogRead(_2_A_XR);
   _2_.setXAxisRotation(_2_XR_value / 4);
   _2_XRLastPotState = _2_XRCurrentPotState;
   _2_.sendState();
   
  }


  // Joystick 3******************************************************************************************************

  

  // Joystick _3_ X Axis
  
  _3_XCurrentPotState = analogRead(_3_A_X) / 4;

  while(_3_XCurrentPotState != _3_XLastPotState){

    if(_3_XCurrentPotState - _3_XLastPotState < MARGIN_POS && _3_XCurrentPotState - _3_XLastPotState > MARGIN_NEG){

        break;
    }
     
    initState = false;
   _3_X_value = analogRead(_3_A_X);
   
   _3_.setXAxis(_3_X_value / 4);
   _3_XLastPotState = _3_XCurrentPotState;
   _3_.sendState();
  }

  // Joystick _3_ Y Axis
  
  _3_YCurrentPotState = analogRead(_3_A_Y) / 4;

  while(_3_YCurrentPotState != _3_YLastPotState){

    if(_3_YCurrentPotState - _3_YLastPotState < MARGIN_POS && _3_YCurrentPotState - _3_YLastPotState > MARGIN_NEG){

        break;
    }
     
    initState = false;
   _3_Y_value = analogRead(_3_A_Y);
   _3_.setYAxis(_3_Y_value / 4);
   _3_YLastPotState = _3_YCurrentPotState;
   _3_.sendState();
  }

   // Joystick _3_ Z Axis

  _3_ZCurrentPotState = analogRead(_3_A_Z) / 4;

  while(_3_ZCurrentPotState != _3_ZLastPotState){

    if(_3_ZCurrentPotState - _3_ZLastPotState < MARGIN_POS && _3_ZCurrentPotState - _3_ZLastPotState > MARGIN_NEG){

        break;
    }
     
    initState = false;
   _3_Z_value = analogRead(_3_A_Z);
   _3_.setZAxis(_3_Z_value / 4);
   _3_ZLastPotState = _3_ZCurrentPotState;
   _3_.sendState();
  }

  // Joystick _3_ XR Axis

  _3_XRCurrentPotState = analogRead(_3_A_XR) / 4;

  while(_3_XRCurrentPotState != _3_XRLastPotState){

    if(_3_XRCurrentPotState - _3_XRLastPotState < MARGIN_POS && _3_XRCurrentPotState - _3_XRLastPotState > MARGIN_NEG){

        break;
    }
     
    initState = false;
   _3_XR_value = analogRead(_3_A_XR);
   _3_.setXAxisRotation(_3_XR_value / 4);
   _3_XRLastPotState = _3_XRCurrentPotState;
   _3_.sendState();
  }

  }

 
  



 

 
