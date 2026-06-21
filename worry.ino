#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 or 0x3F for a 16x2 display
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  lcd.init();          // Initialize the LCD
  lcd.backlight();     // Turn on the backlight
}

void loop() {
  // --- Track Intro Banner ---
  lcd.setCursor(0, 0);
  lcd.print(">> NOW PLAYING: ");
  lcd.setCursor(0, 1);
  lcd.print("worry (slowed)  "); 
  delay(3500); // Intro screen holds for 3.5 seconds
  lcd.clear();

  // --- Static Header for the Loop ---
  lcd.setCursor(0, 0);
  lcd.print("LONOWN - worry  ");

  // --- Line 1 ---
  String lyric1 = "   One summer night   ";
  scrollText(1, lyric1, 400); // Balanced speed (600ms per character shift)
  delay(1000); // 1.5-second pause after line finishes scrolling

  // --- Line 2 ---
  String lyric2 = "   The fade of night   ";
  scrollText(1, lyric2, 500);
  delay(1000);

  // --- Line 3 ---
  String lyric3 = "   The fade of night   ";
  scrollText(1, lyric3, 500);
  delay(1000);
  
  // --- Line 4 ---
  String lyric4 = "   The fade of-   ";
  scrollText(1, lyric4, 500);
  delay(1000); // 2-second pause on the final trailing line
  
  // Clear everything before starting the loop over again
  lcd.clear();
}

// Scrolling function for the second row
void scrollText(int row, String text, int delayTime) {
  for (int i = 0; i < text.length() - 16; i++) {
    lcd.setCursor(0, row);
    lcd.print(text.substring(i, i + 16));
    delay(delayTime); // Controls the shifting tempo
  }
}