#ifndef RENDER_H
#define RENDER_H
#define SPI_SPEED 40000000 // SPI speed
#define PIN_MISO    12      // mandatory  (if the display has no MISO line, set this to 255 but then VSync will be disabled)
//LED to vin through resistor
#define PIN_SCK     13      // mandatory
#define PIN_MOSI    11      // mandatory
#define PIN_DC      10      // mandatory, can be any pin but using pin 10 (or 36 or 37 on T4.1) provides greater performance
#define PIN_RESET   6       // optional (but recommended), can be any pin. 
#define PIN_CS      9       // optional (but recommended), can be any pin.  
//GND
//VCC


#define PIN_BACKLIGHT 255   // optional, set this only if the screen LED pin is connected directly to the Teensy.
#define PIN_TOUCH_IRQ 255   // optional, set this only if the touchscreen is connected on the same SPI bus
#define PIN_TOUCH_CS  255   // optional, set this only if the touchscreen is connected on the same spi bus

#include "SPI.h"
#include <ILI9341_T4.h>
#include "tgx.h"
#include <font_tgx_OpenSans_Bold.h>
extern uint16_t ib[];
extern uint16_t fb[];
using namespace tgx;

class RENDER {
public:
    RENDER();  // Constructor
    void drawEnvelope(int EG, float times[4][4]);
    void drawReverb(float wetdry,float size, float lp, float dif, float time);
    void drawFilter(float f1, float f2, float q1, float q2);
    void drawMod(int slot, int source, float amount, int destination);
    void drawOsc(float wave, float detune, bool nwaves, bool step);
    void drawShaper(float gain);
    void initializeDisplay();

private:
    static constexpr int width = 320;
    static constexpr int height = 240;



    ILI9341_T4::ILI9341Driver tft;  // Screen driver object

    ILI9341_T4::DiffBuffStatic<6000> diff1;
    ILI9341_T4::DiffBuffStatic<6000> diff2;

    tgx::Image<tgx::RGB565> im;  // Image encapsulating the framebuffer
};

#endif // DISPLAY_MANAGER_H
