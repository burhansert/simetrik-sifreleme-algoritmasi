#include <iostream>
#include <string>

using namespace std;


string encrypt(string message, string key) {
  string encrypted_message;

  // Her karakter sifreleniyor
  for (int i = 0; i < message.length(); i++) {
    //z karakteri ascii tablosunda onluk sistemde 122 yi ifade ediyor
    //9 sayisi ascii tablosunda onluk sistemde 57 yi ifade ediyor
    //122+57=179 oluyor
    char encrypted_character = (message[i] + key[i % key.length()]);

    //cout << message[i] + key[i % key.length()] << endl;

    //sifrelenmis mesaja ekleniyor
    encrypted_message += encrypted_character;
  }

  return encrypted_message;
}

string decrypt(string encrypted_message, string key) {
  string decrypted_message;

  //Her karakter desifre ediliyor
  for (int i = 0; i < encrypted_message.length(); i++) {
    // Her karakter, anahtarin ayni indeksindeki karakterle degistiriliyor
    char decrypted_character = (encrypted_message[i] - key[i % key.length()]);

    decrypted_message += decrypted_character;
  }

  return decrypted_message;
}

int main() {
  //Anahtar
  string key = "1234567890";

  //Mesaj
  string message = "burhan";

  //Sifreli mesaj
  string encrypted_message = encrypt(message, key);

  //Sifrelenmis mesaj
  cout << encrypted_message << endl;

  // Þifrelenmiþ mesajý deþifre edin.
  string decrypted_message = decrypt(encrypted_message, key);

  // Deþifre edilmiþ mesajý yazdýrýn.
  cout << decrypted_message << endl;

  return 0;
}
