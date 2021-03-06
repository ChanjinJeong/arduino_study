# 1 "j:\\vscode\\arduino\\arduino_study\\sketch.ino"
# 2 "j:\\vscode\\arduino\\arduino_study\\sketch.ino" 2
int pin=8;
DHT11 dht11(pin);
void setup()
{
   Serial.begin(9600);
  while (!Serial) {
      ; // wait for serial port to connect. Needed for Leonardo only
    }
}

void loop()
{
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();
  }
  delay(1000 /* 1000ms*/); //delay for reread
}
