#include <dht11.h>                                            
#include <ESP8266WiFi.h>


String agAdi = "***********************";                     //Ağ adı.    
String agSifresi = "**********";                              //Ağ şifresi.

int dht11Pin = D1;
//int butonPin=D2;//reset butonu yöntemi ile yapılacaksa


float nem, sicaklik;

dht11 DHT11;                        

void setup() {
  Serial.begin(115200);
  WiFi.begin(agAdi, agSifresi);
  Serial.println ("");
  //pinMode(D2,INPUT_PULLUP);//reset butonu yöntemi ile yapılacaksa

  
   while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  Serial.println("");
  Serial.println("Ağ bağlantısı sağlandı");

  //////////////Bu aralıkta yaptırmak istediğiniz işlerin kodunu ekleyebilirsiniz//////////////////////
  DHT11.read(dht11Pin);
  sicaklik = (float)DHT11.temperature;                        //sıcaklık ve nem bilgisini aldık
  nem = (float)DHT11.humidity; 
  Serial.println("Veriler Okundu");
  Serial.print("Sıcaklık / Nem :");
  Serial.print(sicaklik);
  Serial.print("C /");
  Serial.print(nem);
  Serial.println("%");
  delay(3000); //okuma kolaylığı için
 ///////////////////////////////////////////////////////////////////////////////////////////////////////

  //deep sleep komut kısmı//////////////////////////////////////////////////////////////////////////////
  // Deep Sleep modunda esp 20sn uyuyacak ve sonra kendini uyandıracak
   Serial.println("Şimdi 20sn uyuyacağım ve sonra tekrar uyanacağım");
   delay(1000); //okuma kolaylığı için

   ESP.deepSleep(20e6);  //20x10 üzeri 6 kadar micro saniye uyu demek
   delay(20);//sorun çıkmasını engellemek için
  
    //  // Butona basılana kadar uykuda kalma durumu için gerekli satır
    //  Serial.println("Reset butonuna basılana kadar uykuda kalacağım");
    //  delay (500);
    //  ESP.deepSleep(0);  //sürekli uykuda kalması için 0 yazarız

    
}

void loop() {
}
