#include <stdio.h>
#include <stdlib.h>
#include <sound.h>
#include <math.h>
#include <graphics.h>
#include <zxlowgfx.h>


void bloop(unsigned char p,unsigned char d); 
void colr(int col); //This our ASM function prototype 
//void beepsy(int freq,int dur);
void pauza(int len);
void xpatt(int st,int ph);

void main(){
     unsigned char pitch,duration;
     int note=0x01FF,length=0x000F;
     int p=60,d=20,color=12,i; // We want to fill with attr=12
     int pat=0,ph=1,x;

     pitch=(unsigned char) p;
     duration=(unsigned char) d;
     
     
     //for(i=0;i<64;i++){
     //bloop(pitch,duration);     
     //printf("Hello ASM z80 group ");
     //} */
     colr(color);
     for(x=0;x<36;x++){
     xpatt(pat,x);
     }
       // call our function 
     

}

void bloop(unsigned char p,unsigned char d){
     int i=0,j=0;
     for(i=0;i<p;i++){
         bit_click();
      for (j=0;j<d;j++){
       }   
                     }
}

void colr(int col){
    #asm
    ld hl,2  // First adress on stack is return adress
    add hl,sp  // hence move two bytes below HL now points to where  
    ld a,(hl) // our passed variable col sits now put the value into A
    ld hl,22528 // this just fills the attribute area with the value of A
    ld de,22529
    ld bc,767
    ld (hl),a
    ldir
    #endasm


}
/*void beepsy(int freq, int dur){
     #asm
     di
     ld hl,2
     add hl,sp // we want DE=freq and BC=duration 
     ld d,(hl)
     inc hl  //move hl up stack by 2 now it points to dur
     ld e,(hl)
     inc hl
     ld b,(hl)
     inc hl
     ld c,(hl)
     
     ld hl,0  //initialise counter
     loop:
     add hl,de
     ld a,h
     cp 128        //pulse width
     sbc a,a
     and 16
     out (254),a    
     dec bc
     ld a,b
     or c
     jr nz,loop
     ei
     #endasm

} */
void pauza(int len){
     #asm
     ld hl,2
     add hl,sp
     ld b,h
     ld c,l
     
     loop2:
     dec bc
     ld a,b
     or c
     jr nz,loop2
     #endasm

}
void xpatt(int str, int ph){
     #asm
      
     ld hl,2
     add hl,sp
     ld b,(hl)
     inc hl
     inc hl
     ld a,(hl)

     ld hl,16384
     ld d,a
loop3:
     ld a,d
     ld (hl),a
     add a,b
     cp 255
     jr z,res
     ld d,a
     inc hl
     ld a,h
     cp 80
     jp nz,loop3     
     jp ext
res:
     xor a
     ld d,a
     jp loop3
ext:
     #endasm
 
}  




