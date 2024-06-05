#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;  
#define I2C_SDA 26
#define I2C_SCL 27

TwoWire i2c_new = TwoWire(0);


void setup(void)
{
  Serial.begin(115200);
  i2c_new.begin(I2C_SDA, I2C_SCL, 100000);
  

  if (!ads.begin(0x48, &i2c_new)) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
}

void loop(void)
{
  int16_t adc0;
  float volts0;

  adc0 = ads.readADC_SingleEnded(0);
  volts0 = ads.computeVolts(adc0);  
  float v_reactivity=6.4452*volts0 - 13.182; //konversi ke +/- 12 V
  Serial.print("ADC0: "); Serial.print(adc0); Serial.print(" Vin "); Serial.print(volts0); Serial.println("V");Serial.print(" V Reac "); Serial.print(v_reactivity); Serial.println("V");
  
  delay(1000);
}
