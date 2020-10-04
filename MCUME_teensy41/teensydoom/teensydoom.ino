


#include "iopins.h"  
#include "emuapi.h"  
#include "keyboard_osd.h"
extern "C" {
#include "doom.h"
}

#ifdef HAS_T4_VGA
#include "vga_t_dma.h"
TFT_T_DMA tft;
#else
#include "tft_t_dma.h"
TFT_T_DMA tft = TFT_T_DMA(TFT_CS, TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK, TFT_MISO, TFT_TOUCH_CS, TFT_TOUCH_INT);
#endif

static IntervalTimer myTimer;
static unsigned char  palette8[PALETTE_SIZE];
static unsigned short  palette16[PALETTE_SIZE];
static int skip=0;

static unsigned long long mscount=0;
volatile unsigned int systime;

static void vblCount() { 
  mscount += 20;
  systime += 20;
}

void emu_SetPaletteEntry(unsigned char r, unsigned char g, unsigned char b, int index)
{
  if (index<PALETTE_SIZE) {
    //Serial.println("%d: %d %d %d\n", index, r,g,b);
    palette8[index]  = RGBVAL8(r,g,b);  
  }
}

void * emu_LineBuffer(int line)
{
#ifdef HAS_T4_VGA
    return(NULL);
#else
    return (void*)tft.getLineBuffer(line);    
#endif  
}

void emu_DrawLine(unsigned char * VBuf, int width, int height, int line) 
{
#ifdef HAS_T4_VGA
    tft.writeLine(width,1,line, VBuf, palette8);
#else
    tft.writeLine(width,1,line, VBuf, palette16);
#endif
}  

void emu_DrawLine8(unsigned char * VBuf, int width, int height, int line) 
{
    if (skip==0) {
#ifdef HAS_T4_VGA
      tft.writeLine(width,height,line, VBuf);
#endif      
    }   
} 

void emu_DrawLine16(unsigned short * VBuf, int width, int height, int line) 
{
    if (skip==0) {
#ifdef HAS_T4_VGA
      tft.writeLine16(width,height,line, VBuf);
#else
      tft.writeLine(width,height,line, VBuf);
#endif      
    }   
} 

void emu_DrawScreen(unsigned char * VBuf, int width, int height, int stride) 
{
    if (skip==0) {
#ifdef HAS_T4_VGA
      tft.writeScreen(width,height-TFT_VBUFFER_YCROP,stride, VBuf+(TFT_VBUFFER_YCROP/2)*stride, palette8);
#else
      tft.writeScreen(width,height-TFT_VBUFFER_YCROP,stride, VBuf+(TFT_VBUFFER_YCROP/2)*stride, palette16);
#endif
    }
}

int emu_FrameSkip(void)
{
  return skip;
}


// ****************************************************
// the setup() method runs once, when the sketch starts
// ****************************************************
void setup() {

#ifdef HAS_T4_VGA
  tft.begin(VGA_MODE_320x240);
  //NVIC_SET_PRIORITY(IRQ_QTIMER3, 255);
#else
  tft.begin();
#endif  
  
  emu_init(); 

  myTimer.begin(vblCount, 20000);  //to run every 20ms  
}


// ****************************************************
// the loop() method runs continuously
// ****************************************************
void loop(void) 
{
  if (menuActive()) {
    uint16_t bClick = emu_DebounceLocalKeys();
    int action = handleMenu(bClick);
    char * wad = menuSelection();
    if (action == ACTION_RUNTFT) {
      toggleMenu(false);
      tft.fillScreenNoDma( RGBVAL16(0x00,0x00,0x00) );
      tft.startDMA(); 
      char filepath[80];
      strcpy(filepath, ROMSDIR);
      strcat(filepath, "/");
      strcat(filepath, wad);
      D_DoomMain(filepath);  
      Serial.println("init end");      
    }           
    delay(20);
  } 
  else { 
    D_DoomLoop();  
  } 
}






EXTMEM  unsigned char MemPool[8*1024*1024];


extern "C" void emu_GetTimeOfDay(int * usec, int * sec) {
  unsigned long long count=mscount;
  int lsec = count / 1000;
  int lusec = (count % 1000)*1000;
  * usec = lusec;
  * sec = lsec;
}
