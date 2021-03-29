#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2);
DigitalIn up_button(D4);
DigitalIn down_button(D5);
DigitalIn confirm_button(D6);
DigitalIn mypin(USER_BUTTON);

AnalogOut Aout(D7);
AnalogIn Ain(A0);

static int choose_freq = 0;//0--4
static int set_freq = 0;
static int frequency = 20;
static int freq_change = 1;
static int freq_set = 0;

float ADCdata[405];
int sample_i;
int sample_rate = 400;

void check_button(){
    if(up_button){
        if(choose_freq>0){
            choose_freq--;
        }
        freq_change = 1;
    }else if(down_button){
        if(choose_freq<2){
            choose_freq++;
        }
        freq_change = 1;
    }else if(confirm_button){
        set_freq = choose_freq;
        if(choose_freq==0) frequency = 20;
        else if(choose_freq==1) frequency = 40;
        else if(choose_freq==2) frequency = 100;
        freq_set = 1;
    }
}

void display_freq(){
    if(freq_change || freq_set){
        uLCD.cls();
        uLCD.text_width(2);
        uLCD.text_height(2);
        uLCD.textbackground_color(BLACK);
        uLCD.color(WHITE);
        uLCD.locate(2,1);
        uLCD.printf("Menu");
        for(int i=0; i<3; i++){
            if(freq_change && choose_freq==i) uLCD.textbackground_color(0x00CC66);
            else if(freq_set && set_freq==i) uLCD.textbackground_color(0x3333FF);
            else uLCD.textbackground_color(BLACK);
            uLCD.locate(2,2+i);
            if(i==0) uLCD.printf("%d",20);
            else if(i==1) uLCD.printf("%d",40);
            else if(i==2) uLCD.printf("%d",100);
            uLCD.printf("Hz");
        }
        freq_change = 0;
        freq_set = 0;
    }
}

int main()
{
    while(1){
        if(!mypin) break;
        check_button();
        display_freq();
        int period = 1000000/frequency;//set freq
        int T = period/20;
        if(frequency==20){
            sample_i = 0;
            for (int p=0; p<20; p++){
                for (float i = 0.0f; i < 1.0f; i += 0.1f) {
                    Aout = i*0.92;
                    ADCdata[sample_i++] = Ain;
                    wait_us(T);
                }
                for (float i = 1.0f; i > 0.0f; i -= 0.1f) {
                    Aout = i*0.92;
                    ADCdata[sample_i++] = Ain;
                    wait_us(T);
                }
            }
        }
        else if(frequency==40){
            sample_i = 0;
            for (int p=0; p<40; p++){
                for (float i = 0.0f; i < 1.0f; i += 0.1f) {
                    Aout = i*0.92;
                    ADCdata[sample_i+(((int)(i*10))/2)] = Ain;
                    wait_us(T);
                }
                sample_i += 5;
                for (float i = 1.0f; i > 0.0f; i -= 0.1f) {
                    Aout = i*0.92;  
                    ADCdata[sample_i+(((int)((1-i)*10))/2)] = Ain;
                    wait_us(T);
                }
                sample_i += 5;
            }
        }
        else if(frequency==100){
            sample_i = 0;
            for (int p=0; p<100; p++){
                for (float i = 0.0f; i < 1.0f; i += 0.1f) {
                    Aout = i*0.92;
                    ADCdata[sample_i+(((int)(i*10))/5)] = Ain;
                    wait_us(T);
                }
                sample_i += 2;
                for (float i = 1.0f; i > 0.0f; i -= 0.1f) {
                    Aout = i*0.92;
                    ADCdata[sample_i+(((int)((1-i)*10))/5)] = Ain;
                    wait_us(T);
                }
                sample_i += 2;
            }
        }
    }
    for(int i=0; i<400; i++){
        printf("%f\r\n", ADCdata[i]);
        ThisThread::sleep_for(10ms);
    }
}