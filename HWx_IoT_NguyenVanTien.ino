int ledPin = 16;                
int control = LOW ;
int button_pin = 0 ;
String text;

void blink()
{
  
    if (control == LOW) 
  {
    control = HIGH ;
    Serial.println("trang thai cua led : off  ");
  }
  else
  {
    control = LOW;
    Serial.println("trang thai cua led : on ");
  }
  
  digitalWrite(ledPin, control);
  
}
void setup()
{
  
  pinMode(ledPin, OUTPUT);      
  pinMode(button_pin, INPUT);   
  //INPUT_PULLUP dung de kich hoat dien tro trong mach, giup chong qua tai mach, gay hong ( mot so truong hop khong can thiet).    
  pinMode(button_pin, INPUT_PULLUP); 
  attachInterrupt(button_pin, blink, FALLING);
  Serial.begin(115200);
  Serial.println(".......") ;
  Serial.println(" bam on de tat led - bam off de bat led ");

 
}

void loop()
{
 // kiem tra cong serial da san sang chua.
 if (Serial.available())
 {
  // ham serial.readstringuntil dung de lay chuoi string (doan text ) trong may tinh.
 text = Serial.readStringUntil('\n');
 // cat het cac ki tu trong o dau va cuoi , de loai bo cac gia tri nhieu lam sai - giong nhung fflush(stdin) trong c.
 text.trim();
 if(text == "led on") 
 {
  digitalWrite(16,LOW);
 Serial.println(" trang thai cua led ::: on" ) ;
 }
 if(text == "led off") 
 {
  digitalWrite(16,HIGH);
 Serial.println("trang thai cua led ::: off ") ;
 }
 
 }
}


