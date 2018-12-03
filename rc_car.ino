#include <SoftwareSerial.h> // software bluetooth serial

// 모터드라이버 핀 설정 
#define LeftA 5 
#define LeftB 6 
#define RightA 9 
#define RightB 10 
 
//bt settings
#define BlueTx 12 
#define BlueRx 11 

#define Debug
 
SoftwareSerial mySerial(BlueTx, BlueRx);  //시리얼 통신을 위한 객체선언

char command; // input command 
 
void setup() {
 // 시리얼 통신속도 설정
  Serial.begin(9600);   
  mySerial.begin(9600); 

 // 모터드라이버 출력 설정
  pinMode(LeftA, OUTPUT);
  pinMode(RightA, OUTPUT);
  pinMode(LeftB, OUTPUT);
  pinMode(RightB, OUTPUT);  
  
  Serial.println("BT ready");
}
 
void loop() {
  while(mySerial.available())  //블루투스로 입력이 있으면
  {
     command = mySerial.read(); // 컨트롤러 리턴값을 저장
     #ifdef Debug
     Serial.print(command);
     #endif
     
     if(command == 'l'){            //좌회전      
       left();
     }else if(command == 'r'){      //우회전
       right();
     }else if(command == 'f'){      //전진
       forward();
     }else if(command == 'b'){      //후진
       backward();
     }else if(command == 's'){      //정지
       stop(); 
     }
  }
  
}
 
// functions
void forward(){
  #ifdef Debug
    Serial.println("forward");
    
  #endif  
  //정회전
  analogWrite(LeftA, 0);              // 5번핀에 0
  analogWrite(LeftB, 150);            // 6번핀에 150
  analogWrite(RightA, 0);              // 9번핀에 0
  analogWrite(RightB, 150);           // 10번핀에 150
  delay(300);
  analogWrite(LeftA, 0);              // 5번핀에 0
  analogWrite(LeftB, 0);            // 6번핀에 150
  analogWrite(RightA, 0);              // 9번핀에 0
  analogWrite(RightB, 0);           // 10번핀에 150

}

void backward(){
  #ifdef Debug
    Serial.println("back");
  #endif  
  //역회전
  analogWrite(LeftA, 150);              // 5번핀에 0
  analogWrite(LeftB, 0);            // 6번핀에 150
  analogWrite(RightA, 150);              // 9번핀에 0
  analogWrite(RightB, 0);           // 10번핀에 150
  delay(300);
  analogWrite(LeftA, 0);              // 5번핀에 0
  analogWrite(LeftB, 0);            // 6번핀에 150
  analogWrite(RightA, 0);              // 9번핀에 0
  analogWrite(RightB, 0);           // 10번핀에 150

}

void left(){
  #ifdef Debug
    Serial.println("left");
  #endif  


}

void right(){
  #ifdef Debug
    Serial.println("right");
  #endif  


}

void stop(){
  #ifdef Debug
    Serial.println("stop");
  #endif  
  
}

