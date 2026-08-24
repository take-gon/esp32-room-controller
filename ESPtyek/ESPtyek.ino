#include <Wire.h>              // I2C通信を使うためのライブラリ
#include <Adafruit_GFX.h>      // 文字や図形を描画するための基本ライブラリ
#include <Adafruit_SSD1306.h>  // SSD1306 OLEDを制御するためのライブラリ

// OLEDの横幅
#define SCREEN_WIDTH 128

// OLEDの縦幅
#define SCREEN_HEIGHT 64

// OLEDを操作するためのオブジェクトを作成
// &Wire はI2C通信を使うという意味
// -1 はリセット用ピンを使わないという意味
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {

  // I2C通信を開始する
  // GPIO21 = SDA
  // GPIO22 = SCL
  Wire.begin(21, 22);

  // OLEDを初期化する
  // 0x3C は先ほどI2Cスキャンで確認したOLEDのアドレス
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {

    // OLEDの初期化に失敗したら、
    // ここで永久停止する
    while (true);
  }

  // OLEDの画面内容を一度すべて消す
  display.clearDisplay();

  // 文字サイズを2倍にする
  display.setTextSize(2);

  // 文字色を白にする
  display.setTextColor(SSD1306_WHITE);

  // 文字を書き始める位置を指定
  // 左から10ピクセル、上から20ピクセル
  display.setCursor(10, 20);

  // OLED内部の描画用メモリに文字を書く
  display.println("ESP32 OK!");

  // 描画用メモリの内容を実際のOLED画面に表示する
  display.display();
}

void loop() {

  // 今回は繰り返し処理をしないので空
}