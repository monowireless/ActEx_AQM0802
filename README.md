# ActEx_AQM0802

## About

Sitronix社のI2C接続LCDコントローラST7032を実装したLCDモジュールAQM0802を使用してカウント値を表示するサンプルです。

Act sample using AQM0802 LCD modules built with the Sitronix ST7032 I2C controller.

## Connection

AQM0802の電源およびリセットピンを接続したうえで、I2C SCLとI2C SDAをTWELITEに接続します。

Connect powerlines and the reset pin on the AQM0802, then connect I2C SCL and I2C SDA to the TWELITE.

## Usage

### Initialization

```C++:ActEx_AQM0802.cpp
    // Setup the display
    display.begin();
```

AQM0802クラスのインスタンスをグローバル空間に宣言し、setup()内でAQM0802::begin()を呼びます。

Create a global instance of the AQM0802 class, then call AQM0802::begin() in the setup().

### Clear the display

```C++
    // Clear the display
    display.clear();
```

ディスプレイの内容を消去するには、AQM0802::clear()を呼びます。

Use AQM0802::clear() to clear contents on the display.

### Print strings

```C++:ActEx_AQM0802.cpp
        // Increment the count number and print it
        display.printf("%05d[s]\n", ++count);
```

書式文字列を表示するには、AQM0802::printf()を呼びます。
C言語標準ライブラリのprintf()と同様に使えますが、一度に表示できる最大の文字数が`AQM0802_PRINTF_MAX`に定義されており、デフォルトは64文字です。

Use AQM0802::printf() to print formatted strings.
You can use this method like the printf() in the C standard library, but maximum count of the string is limited to the `AQM0802_PRINTF_MAX`. Default value is 64.

```C++:AQM0802/AQM0802.hpp
/// Maximum length of printf() strings
#define AQM0802_PRINTF_MAX 64
```

### Put a character

```C++
    // Print 'a'
    display.putc('a');
```

文字を表示するには、AQM0802::putc()を呼びます。
C言語標準ライブラリのputc()あるいはputchar()と同様に使えます。

Use AQM0802::putc() to put a character.
You can use this method like the putc() or putchar() in the C standard library.

### Move the cursor

```C++
    // Move the cursor to the y:1,x:3
    display.move(1, 3);
```

AQM0802::printf() および AQM0802::putc()の表示開始位置を変更するには、AQM0802::move()を呼びます。
ncursesライブラリのmove()と同様に使えます。

Use AQM0802::move() to move the initial position of the AQM0802::printf() and AQM0802::putc().
You can use this method like the move() in the ncurses library.

## License
MW-SLA-1 (MONO WIRELESS SOFTWARE LICENSE AGREEMENT)
