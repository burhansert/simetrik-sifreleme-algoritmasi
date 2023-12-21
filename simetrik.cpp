#include <iostream>
#include <string>

using namespace std;


string encrypt(string message, string key)
{
    string encrypted_message;

    // Her karakter sifreleniyor
    for (int i = 0; i < message.length(); i++)
    {
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

string decrypt(string encrypted_message, string key)
{
    string decrypted_message;

    //Her karakter desifre ediliyor
    for (int i = 0; i < encrypted_message.length(); i++)
    {
        // Her karakter, anahtarin ayni indeksindeki karakterle degistiriliyor
        char decrypted_character = (encrypted_message[i] - key[i % key.length()]);

        decrypted_message += decrypted_character;
    }

    return decrypted_message;
}

int main()
{
    while(true)
    {
        int islem=0;

        cout <<"-----------------------"<<endl ;
        cout <<"Hos geldiniz" << endl<< endl;

        cout <<"1 mesaj sifrele"<< endl;
        cout <<"2 mesaj sifresi coz"<< endl<< endl;

        cout <<"Ne yapmak istersiniz: " ;
        cin>>islem;
        cout<<endl;
        if (islem==1)
        {


            //Mesaj
            string message = "";
            cout <<"Sifrelenecek mesaji yaziniz:"<< endl;
            cin>>message;

            string key = "";   //Anahtar
            cout <<endl<<"Sifreyi yaziniz (en az 6 basamakli bir sayi):"<< endl;
            cin>>key;

            //Mesaj sifreleniyor
            string encrypted_message = encrypt(message, key);
            cout <<endl<<"Sifreli mesaj:"<< endl;
            cout << encrypted_message << endl;    //Sifrelenmis mesaj yazdiriliyor

        }
        else if (islem==2)
        {
            string message = "";
            cout <<"Sifresi cozulecek mesaji yaziniz:"<< endl;
            cin>>message;

            string key = "";   //Anahtar
            cout <<endl<<"Sifreyi yaziniz"<< endl;
            cin>>key;

            //Sifreli mesaj desifre ediliyor
            string decrypted_message = decrypt(message, key);
            cout <<endl<<"Sifresi cozulmus mesaj:"<< endl;
            //Desifre edilmis mesaj yazdiriliyor
            cout << decrypted_message << endl;

        }
        else
        {
            cout <<"Yanlis yazdiniz! Ekrana 1 veya 2 yaziniz"<< endl;
        }

    }

    return 0;
}
