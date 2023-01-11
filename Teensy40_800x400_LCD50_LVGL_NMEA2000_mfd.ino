/*



Teensy 4.0 with LVGL NMEA2000 MFD
Using SSD1963 5.0" 800x480 LCD
www.skpang.co.uk Jan 2023

Requires the following library:
https://github.com/ttlappalainen/NMEA2000
https://github.com/lvgl/lvgl

*/

#include "SSD1963.h"
#include "skp_lvgl.h"
#include "lvgl.h"
#include "ui.h"
#include "ui_helpers.h"

#define NMEA2000_TEENSYX_CAN_BUS tNMEA2000_Teensyx::CAN3 // Use port can3
#include <NMEA2000_CAN.h>
#include <N2kMessages.h>
#include <N2kMessagesEnumToStr.h>

#define RS  26
#define WR  27
#define CS  25
#define RST 28
#define BL_CTL  21
int led = 13;       // Teensy yellow LED

char buff[20];

SSD1963 lcd(RS, WR, CS, RST);  // Remember to change the model parameter to suit your display module!

typedef struct {
  unsigned long PGN;
  void (*Handler)(const tN2kMsg &N2kMsg); 
} tNMEA2000Handler;

void SystemTime(const tN2kMsg &N2kMsg);
void Wind(const tN2kMsg &N2kMsg);
void OutsideEnvironmental(const tN2kMsg &N2kMsg);
void EngineRapid(const tN2kMsg &N2kMsg);
void COGSOG(const tN2kMsg &N2kMsg);
void BatteryConfigurationStatus(const tN2kMsg &N2kMsg);
void EngineDynamicParameters(const tN2kMsg &N2kMsg);

tNMEA2000Handler NMEA2000Handlers[]={
//  {126992L,&SystemTime},
  {130310L,&OutsideEnvironmental},
  {130306L,&Wind},
  {127488L,&EngineRapid},
  {129026L,&COGSOG},
  {127489L,&EngineDynamicParameters},
 // {127513L,&BatteryConfigurationStatus},
  {0,0}
};

Stream *OutputStream;
void HandleNMEA2000Msg(const tN2kMsg &N2kMsg);

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(BL_CTL, OUTPUT);
  digitalWrite(led, HIGH);   
  digitalWrite(BL_CTL, HIGH);   
  delay(500);              
  digitalWriteFast(led, LOW);    

  lcd.InitLCD();
  // r g b
  lcd.setColor(0, 20,80);
  lcd.fillRect(0, 0, 800, 480);
  
  lcd.setColor(0, 0,255);
  lcd.drawLine(0,0,800,480);

  lcd.setColor(0, 255,0);
  lcd.drawLine(800,0,0,480);

  lcd.setColor(255, 0,0);
  lcd.drawLine(800,240,0,240);
 
  OutputStream=&Serial;
  // NMEA2000.SetN2kCANReceiveFrameBufSize(50);
  // Do not forward bus messages at all
  NMEA2000.SetForwardType(tNMEA2000::fwdt_Text);
  NMEA2000.SetForwardStream(OutputStream);
  // Set false below, if you do not want to see messages parsed to HEX withing library
  NMEA2000.EnableForward(false);
  NMEA2000.SetMsgHandler(HandleNMEA2000Msg);
  //  NMEA2000.SetN2kCANMsgBufSize(2);
  NMEA2000.Open();
  OutputStream->print("NMEA2000 Running...");

  skp_lvgl_init();    // Start LVGL
  Serial.println("800x480 SSD1963 skpang.co.uk 2023");
}

//*****************************************************************************
template<typename T> void PrintLabelValWithConversionCheckUnDef(const char* label, T val, double (*ConvFunc)(double val)=0, bool AddLf=false, int8_t Desim=-1 ) {
  OutputStream->print(label);
  if (!N2kIsNA(val)) {
    if ( Desim<0 ) {
      if (ConvFunc) { OutputStream->print(ConvFunc(val)); } else { OutputStream->print(val); }
    } else {
      if (ConvFunc) { OutputStream->print(ConvFunc(val),Desim); } else { OutputStream->print(val,Desim); }
    }
  } else OutputStream->print("not available");
  if (AddLf) OutputStream->println();
}

//*****************************************************************************
//NMEA 2000 message handler
void HandleNMEA2000Msg(const tN2kMsg &N2kMsg) {
  int iHandler;
  
  // Find handler
  //OutputStream->print("In Main Handler: "); OutputStream->println(N2kMsg.PGN);
  for (iHandler=0; NMEA2000Handlers[iHandler].PGN!=0 && !(N2kMsg.PGN==NMEA2000Handlers[iHandler].PGN); iHandler++);
  
  if (NMEA2000Handlers[iHandler].PGN!=0) {
    NMEA2000Handlers[iHandler].Handler(N2kMsg); 
  }
}
//*****************************************************************************
void COGSOG(const tN2kMsg &N2kMsg) {
    unsigned char SID;
    tN2kHeadingReference HeadingReference;
    double COG;
    double SOG;
    
    if (ParseN2kCOGSOGRapid(N2kMsg,SID,HeadingReference,COG,SOG) ) {
                      OutputStream->println("COG/SOG:");
      PrintLabelValWithConversionCheckUnDef("  SID: ",SID,0,true);
                        OutputStream->print("  reference: "); PrintN2kEnumType(HeadingReference,OutputStream);
      PrintLabelValWithConversionCheckUnDef("  COG (deg): ",COG,&RadToDeg,true);
      PrintLabelValWithConversionCheckUnDef("  SOG (m/s): ",SOG,0,true);
      
      sprintf(buff,"%2.0f",RadToDeg(COG));
      lv_label_set_text(ui_lbCOG,buff);    // Update LCD
      
      sprintf(buff,"%2.1f",msToKnots(SOG));
      lv_label_set_text(ui_lbSOG,buff);    // Update LCD
    
    } else {
      OutputStream->print("Failed to parse PGN: "); OutputStream->println(N2kMsg.PGN);
    }
}

//*****************************************************************************
void Wind(const tN2kMsg &N2kMsg) {
   unsigned char SID;
   double WindSpeed;
   double WindAngle; 
   double knots;
   double WindAngle_degree;
   
   tN2kWindReference WindReference;
    
   if(ParseN2kWindSpeed(N2kMsg,SID,  WindSpeed, WindAngle, WindReference)) 
   {
      Serial.print("Wind speed ");
      Serial.print(WindSpeed);
      Serial.print(" ");
      knots = msToKnots(WindSpeed);
      sprintf(buff,"%2.1f",knots);
      lv_label_set_text(ui_lbWindSpeed,buff);    // Update  LCD
   
      WindAngle_degree = RadToDeg(WindAngle);
      Serial.print("Wind direction ");
      Serial.println(WindAngle_degree);
   
      sprintf(buff,"%2.0f",WindAngle_degree);
      lv_label_set_text(ui_lbWindDirection,buff); 
      lv_img_set_angle(ui_Screen1_Image2,WindAngle_degree*10);
   
  
    } else {
      OutputStream->print("Failed to parse PGN: "); OutputStream->println(N2kMsg.PGN);
    }
}
//*****************************************************************************
void OutsideEnvironmental(const tN2kMsg &N2kMsg) {
    unsigned char SID;
    double WaterTemperature,temperature;
    double OutsideAmbientAirTemperature;
    double AtmosphericPressure;
    
    if (ParseN2kOutsideEnvironmentalParameters(N2kMsg,SID,WaterTemperature,OutsideAmbientAirTemperature,AtmosphericPressure) ) {
      PrintLabelValWithConversionCheckUnDef("Water temp: ",WaterTemperature,&KelvinToC);
      PrintLabelValWithConversionCheckUnDef(", outside ambient temp: ",OutsideAmbientAirTemperature,&KelvinToC);
      PrintLabelValWithConversionCheckUnDef(", pressure: ",AtmosphericPressure,0,true);
      
      temperature = KelvinToC(WaterTemperature);
      sprintf(buff,"%2.1f",temperature);
      
      lv_label_set_text(ui_lbWaterTemp, buff);   // Update temperature on LCD

    } else {
      OutputStream->print("Failed to parse PGN: ");  OutputStream->println(N2kMsg.PGN);
    }
}

//*****************************************************************************
void EngineRapid(const tN2kMsg &N2kMsg) {
    unsigned char EngineInstance;
    double EngineSpeed;
    double EngineBoostPressure;
    int8_t EngineTiltTrim;
    
    if (ParseN2kEngineParamRapid(N2kMsg,EngineInstance,EngineSpeed,EngineBoostPressure,EngineTiltTrim) ) {
      PrintLabelValWithConversionCheckUnDef("Engine rapid params: ",EngineInstance,0,true);
      PrintLabelValWithConversionCheckUnDef("  RPM: ",EngineSpeed,0,true);
      PrintLabelValWithConversionCheckUnDef("  boost pressure (Pa): ",EngineBoostPressure,0,true);
      PrintLabelValWithConversionCheckUnDef("  tilt trim: ",EngineTiltTrim,0,true);

      sprintf(buff,"%2.0f",EngineSpeed);
      lv_label_set_text(ui_lbEngineRPM, buff);   // Update LCD

    } else {
      OutputStream->print("Failed to parse PGN: "); OutputStream->println(N2kMsg.PGN);
    }
}

//*****************************************************************************
void EngineDynamicParameters(const tN2kMsg &N2kMsg) {
    unsigned char EngineInstance;
    double EngineOilPress;
    double EngineOilTemp;
    double EngineCoolantTemp;
    double AltenatorVoltage;
    double FuelRate;
    double EngineHours;
    double EngineCoolantPress;
    double EngineFuelPress; 
    int8_t EngineLoad;
    int8_t EngineTorque;
    tN2kEngineDiscreteStatus1 Status1;
    tN2kEngineDiscreteStatus2 Status2;
    
    if (ParseN2kEngineDynamicParam(N2kMsg,EngineInstance,EngineOilPress,EngineOilTemp,EngineCoolantTemp,
                                 AltenatorVoltage,FuelRate,EngineHours,
                                 EngineCoolantPress,EngineFuelPress,
                                 EngineLoad,EngineTorque,Status1,Status2) ) {
      PrintLabelValWithConversionCheckUnDef("Engine dynamic params: ",EngineInstance,0,true);
      PrintLabelValWithConversionCheckUnDef("  oil pressure (Pa): ",EngineOilPress,0,true);
      PrintLabelValWithConversionCheckUnDef("  oil temp (C): ",EngineOilTemp,&KelvinToC,true);
      PrintLabelValWithConversionCheckUnDef("  coolant temp (C): ",EngineCoolantTemp,&KelvinToC,true);
      PrintLabelValWithConversionCheckUnDef("  altenator voltage (V): ",AltenatorVoltage,0,true);
      PrintLabelValWithConversionCheckUnDef("  fuel rate (l/h): ",FuelRate,0,true);
      PrintLabelValWithConversionCheckUnDef("  engine hours (h): ",EngineHours,&SecondsToh,true);
      PrintLabelValWithConversionCheckUnDef("  coolant pressure (Pa): ",EngineCoolantPress,0,true);
      PrintLabelValWithConversionCheckUnDef("  fuel pressure (Pa): ",EngineFuelPress,0,true);
      PrintLabelValWithConversionCheckUnDef("  engine load (%): ",EngineLoad,0,true);
      PrintLabelValWithConversionCheckUnDef("  engine torque (%): ",EngineTorque,0,true);
      
      sprintf(buff,"%2.1f",AltenatorVoltage);
      lv_label_set_text(ui_lbAltVolt, buff);   // LCD

    } else {
      OutputStream->print("Failed to parse PGN: "); OutputStream->println(N2kMsg.PGN);
    }
}

void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    NMEA2000.ParseMessages();
}
