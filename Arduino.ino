bool pushButton1;   // 创建布尔型变量用来存储按键开关1的电平状态
bool pushButton2;   // 创建布尔型变量用来存储按键开关2的电平状态

void setup() {
  pinMode(pushButton1, INPUT);  // 设置引脚2为输入模式
  pinMode(pushButton2, INPUT);  // 设置引脚10为输入模式
  Serial.begin(9600); // 设置串口波特率为9600
}
void loop() {
  int ButtonValue1 = 0; //定义变量并赋初值为0
  ButtonValue1 = digitalRead(pushButton1);  

  int ButtonValue2 = 0; //定义变量并赋初值为0
  ButtonValue2 = digitalRead(pushButton2);  
   
  int pushButton1 = digitalRead(2); 
  int pushButton2 = digitalRead(10);
  
  if (Serial.available()) { // If there is data available from the serial communication
    char inByte = Serial.read(); // Read and store the incoming data
    char inByte1 = Serial.read();
  }
  if (pushButton1 != HIGH) {// Check if the button is pressed
  Serial.println(1);
  }

  if (pushButton2 != HIGH) {// Check if the button is pressed
  Serial.println(2);
  //Serial.print(" Value of switch = ");  //通过串行通信发送，输出到串口监视器
  // Serial.println(switchValue); //将读取的按键值输出到串口监视器
}
delay(5);
}
