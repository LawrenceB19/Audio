#include "RENDER.h"

// Constructor Implementation
RENDER::RENDER()
    : tft(PIN_CS, PIN_DC, PIN_SCK, PIN_MOSI, PIN_MISO, PIN_RESET, PIN_TOUCH_CS, PIN_TOUCH_IRQ),
      im(fb, width, height) {

}

void RENDER::initializeDisplay() {
    while (!tft.begin(SPI_SPEED));
    tft.begin();
    tft.setScroll(0);
    tft.setRotation(3); // Set the rotation to your preferred orientation
    tft.setFramebuffer(ib); // Set internal framebuffer
    tft.setDiffBuffers(&diff1, &diff2); // Set differential buffers
    tft.setDiffGap(4); // Set gap for differential buffers
    tft.setRefreshRate(60); // Set display refresh rate
    tft.setVSyncSpacing(1); // Set VSync and framerate settings
    // make sure backlight is on
    if (PIN_BACKLIGHT != 255) {
        pinMode(PIN_BACKLIGHT, OUTPUT);
        digitalWrite(PIN_BACKLIGHT, HIGH);
    }
}

// Draw method Implementation
void RENDER::drawEnvelope(int EG, float times[4][4]) {
    float val;
    float val2;
    // Clear the screen
    im.fillScreen(RGB565_Black);
    switch(EG){
        case 0:
            im.drawText("MOD EG 1", { 20, 20 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
            break;
        case 1:
            im.drawText("MOD EG 2", { 20, 20 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
            break;
        case 2:
            im.drawText("MOD EG 3", { 20, 20 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
            break;
        case 3:
            im.drawText("AMP EG", { 20, 20 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
            break;
    }
    im.drawText("A", { 20, 200 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText("D", { 100, 200 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText("S", { 180, 200 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText("R", { 260, 200 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText(String(int(times[EG][0])).c_str(), { 20, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText(String(int(times[EG][1])).c_str(), { 100, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText(String(times[EG][2]).c_str(), { 180, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText(String(int(times[EG][3])).c_str(), { 260, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);

    val = 0.7 * pow(times[EG][0],0.5);
    //70 px maximum
    im.drawLine(20,150,20+val,50,RGB565_White);
    val2 = 20 + val;
    val = 0.7 * pow(times[EG][1],0.5);
    im.drawLine(val2,50,val2+val,(150-(times[EG][2]*100)),RGB565_White);
    val2 = val + val2;
    im.drawLine(val2,(150-(times[EG][2]*100)),val2+70,(150-(times[EG][2]*100)),RGB565_White);
    val2 += 70;
    val = val2 + 0.7 * pow(times[EG][3],0.5);
    im.drawLine(val2,(150-(times[EG][2]*100)),val,150,RGB565_White);

    // Push framebuffer to display
    tft.update(fb, false);
}

void RENDER::drawFilter(float f1, float f2, float q1, float q2){
    im.fillScreen(RGB565_Black);
    im.drawText("Filters", { 20, 20 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText("Cut 1", { 20, 200 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText("Res 1", { 100, 200 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText("Cut 2", { 180, 200 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText("Res 2", { 260, 200 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText((String(f1).c_str()), { 20, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText((String(q1).c_str()), { 100, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText((String(f2).c_str()), { 180, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText((String(q2).c_str()), { 260, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    tft.update(fb, false);
}

void RENDER::drawOsc(float wave, float det, bool nwaves, bool step){
    im.fillScreen(RGB565_Black);
    im.drawRect(20,30,290,140,RGB565_White);
    //im.drawRoundRect({10, 10, 100, 50}, 1, RGB565_White);
    
    im.drawText("Oscillator 1", { 20, 20 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText("Wave", { 5, 200 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText((String(wave).c_str()), { 5, 230 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText("Detune", { 100, 200 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText((String(det).c_str()), { 100, 230 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText("No.", { 180, 200 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    if(nwaves == true){
        im.drawText("2", { 180, 230 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    }
    if(nwaves == false){
        im.drawText("1", { 180, 230 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    }
    im.drawText("Step ", { 270, 200 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    if(step == true){
        im.drawText("On", { 270, 230 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    }
    if(step == false){
        im.drawText("Off", { 270, 230 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    }
    tft.update(fb, false);
}

void RENDER::drawMod(int slot, int source, float amount, int destination){
    im.fillScreen(RGB565_Black);
    im.drawText("Mod matrix", { 20, 20 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText("Slot", { 5, 200 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText((String(slot).c_str()), { 20, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText("Source", { 80, 200 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText((String(source).c_str()), { 80, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText("amount", { 160, 200 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText((String(amount).c_str()), { 160, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText("destination", { 200, 200 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText((String(destination).c_str()), { 200, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    tft.update(fb, false);
}

void RENDER::drawShaper(float pre_gain){
    im.fillScreen(RGB565_Black);
    im.drawText("Waveshaper", { 20, 20 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText("input gain", { 20, 200 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    //im.drawText("Res 1", { 100, 200 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    //im.drawText("Cut 2", { 180, 200 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    //im.drawText("Res 2", { 260, 200 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText((String(pre_gain).c_str()), { 20, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    //im.drawText((String(q1).c_str()), { 100, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    //im.drawText((String(f2).c_str()), { 180, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    //im.drawText((String(q2).c_str()), { 260, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    tft.update(fb, false);
}

void RENDER::drawReverb(float wetdry, float size, float lp, float dif, float time){

    int centre_x = 160;
    int centre_y = 100;
    float size_x;
    float size_y;
    float size2_x;
    float size2_y;

    int particle_count = 10 + int(lp * 30);
    int particle_origin[2] = {160, 100};
    int particle_dest[2] = {160,0};
    int displacement_vector[2];
    float dist_travelled;
    float trail_length;
    float randomNumbers[40] = {
    0.415707, 0.682235, 0.946568, 0.526728, 0.127245, 0.678219, 0.901123, 0.473982, 
    0.257921, 0.364927, 0.754981, 0.825742, 0.192834, 0.385621, 0.623456, 0.273981,
    0.534678, 0.124679, 0.237891, 0.398217, 0.849672, 0.512345, 0.689042, 0.781234, 
    0.624573, 0.271346, 0.493721, 0.751298, 0.825673, 0.938271, 0.652198, 0.371890, 
    0.429317, 0.589213, 0.723891, 0.284672, 0.643981, 0.793217, 0.521789, 0.392718
    };
    im.fillScreen(RGB565_Black);


    //render test particle
    for(int i=0; i<particle_count;i++)
    {
        particle_dest[0] = i * (320/particle_count);
        dist_travelled = randomNumbers[i];
        dist_travelled = dist_travelled + time;
        dist_travelled = dist_travelled - int(dist_travelled);
        dist_travelled = pow(dist_travelled,2);
        trail_length = dif * 0.4 * dist_travelled;
        displacement_vector[0] = particle_dest[0] - particle_origin[0];
        displacement_vector[1] = particle_dest[1] - particle_origin[1];
        im.drawLine(particle_origin[0] + int(displacement_vector[0] * dist_travelled), particle_origin[1] + int(displacement_vector[1] * dist_travelled),particle_origin[0]+ int(displacement_vector[0] * (trail_length + dist_travelled)),particle_origin[1]+ int(displacement_vector[1] * (trail_length + dist_travelled)),RGB565_White,dist_travelled);
    }
    particle_dest[1] = 240;
    for(int i=0; i<particle_count;i++)
    {
        particle_dest[0] = i * (320/particle_count);
        dist_travelled = randomNumbers[i];
        dist_travelled = dist_travelled + time;
        dist_travelled = dist_travelled - int(dist_travelled);
        dist_travelled = pow(dist_travelled,2);
        trail_length = dif * 0.4 * dist_travelled;
        displacement_vector[0] = particle_dest[0] - particle_origin[0];
        displacement_vector[1] = particle_dest[1] - particle_origin[1];
        im.drawLine(particle_origin[0] + int(displacement_vector[0] * dist_travelled), particle_origin[1] + int(displacement_vector[1] * dist_travelled),particle_origin[0]+ int(displacement_vector[0] * (trail_length + dist_travelled)),particle_origin[1]+ int(displacement_vector[1] * (trail_length + dist_travelled)),RGB565_White,dist_travelled);
    }

    particle_dest[0] = 0;
    for(int i=0; i<particle_count;i++)
    {
        particle_dest[1] = i * (240/particle_count);
        dist_travelled = randomNumbers[i];
        dist_travelled = dist_travelled + time;
        dist_travelled = dist_travelled - int(dist_travelled);
        dist_travelled = pow(dist_travelled,2);
        trail_length = dif * 0.4 * dist_travelled;
        displacement_vector[0] = particle_dest[0] - particle_origin[0];
        displacement_vector[1] = particle_dest[1] - particle_origin[1];
        im.drawLine(particle_origin[0] + int(displacement_vector[0] * dist_travelled), particle_origin[1] + int(displacement_vector[1] * dist_travelled),particle_origin[0]+ int(displacement_vector[0] * (trail_length + dist_travelled)),particle_origin[1]+ int(displacement_vector[1] * (trail_length + dist_travelled)),RGB565_White,dist_travelled);
    }
    particle_dest[0] = 320;
    for(int i=0; i<particle_count;i++)
    {
        particle_dest[1] = i * (240/particle_count);
        dist_travelled = randomNumbers[i];
        dist_travelled = dist_travelled + time;
        dist_travelled = dist_travelled - int(dist_travelled);
        dist_travelled = pow(dist_travelled,2);
        trail_length = dif * 0.4 * dist_travelled;
        displacement_vector[0] = particle_dest[0] - particle_origin[0];
        displacement_vector[1] = particle_dest[1] - particle_origin[1];
        im.drawLine(particle_origin[0] + int(displacement_vector[0] * dist_travelled), particle_origin[1] + int(displacement_vector[1] * dist_travelled),particle_origin[0]+ int(displacement_vector[0] * (trail_length + dist_travelled)),particle_origin[1]+ int(displacement_vector[1] * (trail_length + dist_travelled)),RGB565_White,dist_travelled);
    }

    im.drawText("Reverb", { 20, 20 }, RGB565_White, font_tgx_OpenSans_Bold_24, false);
    im.drawText("Wet/dry", { 10, 200 }, RGB565_White, font_tgx_OpenSans_Bold_16, false);
    im.drawText("Length", { 80, 200 }, RGB565_White, font_tgx_OpenSans_Bold_16, false);
    im.drawText("Lowpass", { 150, 200 }, RGB565_White, font_tgx_OpenSans_Bold_16, false);
    im.drawText("Diffusion", { 235, 200 }, RGB565_White, font_tgx_OpenSans_Bold_16, false);
    im.drawText(String(wetdry).c_str(), { 10, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText(String(size).c_str(), { 80, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText(String(lp).c_str(), { 150, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);
    im.drawText(String(dif).c_str(), { 235, 220 }, RGB565_White, font_tgx_OpenSans_Bold_18, false);

    //room rendering
    //draw outer rectangle
    size_x = 210 * wetdry;
    size_x = constrain(size_x,21,210);
    size_y = 140 * wetdry;
    size_y = constrain(size_y,14,210);
    size2_x = size_x * 0.7 * (1-size);
    size2_x = constrain(size2_x,15,210);
    size2_y = size_y * 0.7 * (1-size);
    size2_y = constrain(size2_y,10,140);

    im.drawRect({int(centre_x - 0.5 * size_x), int(centre_y - 0.5 * size_y)},{int(size_x),int(size_y)},RGB565_White);
    im.drawRect({int(centre_x - 0.5 * size2_x), int(centre_y - 0.5 * size2_y)},{int(size2_x),int(size2_y)},RGB565_White);
    im.drawLine({int(centre_x - 0.5 * size_x), int(centre_y - 0.5 * size_y)},{int(centre_x - 0.5 * size2_x), int(centre_y - 0.5 * size2_y)},RGB565_White);
    im.drawLine({int(centre_x - 0.5 * size_x), int(centre_y + 0.5 * size_y)},{int(centre_x - 0.5 * size2_x), int(centre_y + 0.5 * size2_y)},RGB565_White);
    im.drawLine({int(centre_x + 0.5 * size_x), int(centre_y - 0.5 * size_y)},{int(centre_x + 0.5 * size2_x), int(centre_y - 0.5 * size2_y)},RGB565_White);
    im.drawLine({int(centre_x + 0.5 * size_x), int(centre_y + 0.5 * size_y)},{int(centre_x + 0.5 * size2_x), int(centre_y + 0.5 * size2_y)},RGB565_White);
    tft.update(fb, false);
}