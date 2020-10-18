#include <LiquidCrystal.h>// menyisipkan library lcd
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);// inisialisasi pin yang digunakan pada komponen lcd
int GAS_SENSOR_LOW=3;// inisialisasi pin 3 pada arduino yang digunakan sebagai sensor gas (low)
int GREEN_LED=5;// inisialisasi pin 5 pada arduino yang digunakan sebagai led berwarna hijau
int RED_LED=4;// inisialisasi pin 4 pada arduino yang digunakan sebagai led berwarna merah

void setup() { // fungsi yang berjalan ketika program dimulai dan hanya akan berjalan sekali setelah setiap powerUp atau ketika board Arduino reset
  pinMode (GAS_SENSOR_LOW, INPUT_PULLUP);// Mengkonfigurasi pin yang nanti nya akan digunakan sebagai pin resistor pull up
  pinMode (GREEN_LED, OUTPUT) ;// Mengkonfigurasi pin 5 sebagai output pada led hijau
  pinMode (RED_LED, OUTPUT) ;// Mengkonfigurasi pin 4 sebagai output pada led merah
  lcd. begin(20,4);// mengatur jumlah baris dan kolom yang digunakan pada lcd
  lcd.setCursor(0,0);// mengatur posisi kursor pada kolom 0 baris 0
  lcd.print ("SISTEM PENDETEKSI");// mencetak teks pada lcd sesuai baris dan kolom yang diatur sebelumnya
  lcd.setCursor(0,1);// mengatur posisi kursor pada kolom 0 baris 1
  lcd.print ("ALKOHOL");// mencetak teks pada lcd sesuai baris dan kolom yang diatur sebelumnya
  lcd.setCursor(0,2);// mengatur posisi kursor pada kolom 0 baris 2
  lcd.print ("TELEKOMUNIKASI PNJ");// mencetak teks pada lcd sesuai baris dan kolom yang diatur sebelumnya
  delay (1000);// memberikan jeda waktu selama 1000 ms
}
void loop() { // fungsi yang berjalan setelah void setup selesai dan akan berjalan berulang kali selama board Arduino menyala
  int GAS_SENSOR_LOW_READ = digitalRead(GAS_SENSOR_LOW);// membaca input yang diberikan dari logic toggle
  if (GAS_SENSOR_LOW_READ == LOW)// membaca pin 3 sebagai pin LOW
  {
    lcd.clear();// perintah membersihkan layar lcd dari teks
    lcd.setCursor(0, 3);// mengatur posisi kursor pada kolom 0 baris 3
    lcd.print ("ALCOHOL NOT DETECTED");// mencetak teks pada lcd sesuai baris dan kolom yang diatur sebelumnya
    digitalWrite (GREEN_LED, LOW);// lampu led pada output pin 3 sebagai output low
    digitalWrite (RED_LED, HIGH);// lampu led pada output pin 2 sebagai output high
    delay (20);// memberikan jeda waktu selama 20 ms
  }
  else // jika tidak, maka akan dijalankan program 
  {
    lcd.clear();// perintah membersihkan layar lcd dari teks
    lcd.setCursor(0, 3);// mengatur posisi kursor pada kolom 0 baris 3
    lcd.print ("ALCOHOL DETECTED");// mencetak teks pada lcd sesuai baris dan kolom yang diatur sebelumnya
    digitalWrite (RED_LED, LOW);// lampu led pada output pin 2 sebagai output low
    digitalWrite (GREEN_LED, HIGH) ;// lampu led pada output pin 3 sebagai output high
    delay (20);// memberikan jeda waktu selama 20 ms
  }
}
