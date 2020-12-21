
#define CLK_CKDIVR  (*(unsigned char *)0x50C6) // CLK SPEED DIVIDER
#define PB_ODR      (*(unsigned char *)0x5005) // PORT B LATCH
#define PB_DDR      (*(unsigned char *)0x5007) // PORT B DATA DIRECTION
#define PB_CR1      (*(unsigned char *)0x5008) // PORT B CONTROL REGISTER 1

void setup() {
  
  PB_DDR |= 1 << 5; // assuming led pin is 5 1<<5 = B00100000 5th pin as output
  PB_CR1 |= 1 << 5; // Sets output to push pull mode
  CLK_CKDIVR = 0x00; // 2MHZ default clock to 16MHZ
  PB_ODR = 0x00; // Turn all pins off
}

void loop() {
  PB_ODR |= 1 << 5; // turn pin high
  delay(1000);                       
  PB_ODR ^= 1 << 5; // turn pin low  
  delay(1000);                       
}