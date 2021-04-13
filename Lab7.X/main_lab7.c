/*------------------------------------------------------------------------------
Archivo: mainsproject.s
Microcontrolador: PIC16F887
Autor: Andy Bonilla
Compilador: pic-as (v2.30), MPLABX v5.45
    
Programa: Laboratorio 7
Hardware: PIC16F887
    
Creado: 12 de abril de 2021    
Descripcion: 
------------------------------------------------------------------------------*/
//#include <xc.h>
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)


/*-----------------------------------------------------------------------------
------------------------librerias a implementar ------------------------------
-----------------------------------------------------------------------------*/
#include <xc.h>
#include <stdint.h>

/*-----------------------------------------------------------------------------
------------------------directivas del compilador------------------------------
-----------------------------------------------------------------------------*/
#define _tmr0_value 200

/*-----------------------------------------------------------------------------
-------------------------------- variables -----------------------------------
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-------------------------prototipos de funciones-------------------------------
-----------------------------------------------------------------------------*/
void setup(void);  //funcion para configuracion de registros

void __interrupt() isr(void) //si la bandera de INT TMR0
{
    if (T0IF==1)
    { 
        
    }
}

/*-----------------------------------------------------------------------------
-----------------------------ciclo principal----------------------------------
-----------------------------------------------------------------------------*/

void main(void)  //funcion principal sin retorno
{  
    setup(); //en el main se manda a llamar a las configuraciones
    
    
    //---------------------loop principal del programa ------------------------
  
}

/*-----------------------------------------------------------------------------
--------------------------- configuraciones ----------------------------------
-----------------------------------------------------------------------------*/
void setup(void) //FUNCION PARA CONFIGURACION DE ENTRADAS Y SALIDAS
{
    //CONFIGURACION DE ENTRADAS/SALIDAS DIGITALES
    ANSEL = 0X00;  
    ANSELH = 0X00;
    
    //CONFIGURACION DE ENTRADAS Y SALIDAS EN PUERTOS
    TRISA = 0X00;       // Todo el puerto A es salida
    TRISB = 0b11000000; // PortB0 y PortB1 son entradas
    TRISC = 0X00;       // Todo el puerto C es salida
            
    PORTA = 0X00;       // Todo el puerto A es salida
    PORTB = 0b11000000; // PortB0 y PortB1 son entradas
    PORTC = 0X00;       // Todo el puerto C es salida
           
    //CONFIGURACION DEL OSCILADOR
    OSCCONbits.IRCF2=1; //4MHz 110
    OSCCONbits.IRCF1=1; //4MHz 110
    OSCCONbits.IRCF0=0; //4MHz 110
    OSCCONbits.SCS=1;   //configuracion de oscilador interno
    
    //CONFIGURACION DEL TIMER0
    OPTION_REGbits.T0CS=0;
    OPTION_REGbits.PSA=0; //SE HABILITA EL PREESCALER
    OPTION_REGbits.PS2=1; //PREESCALER 1:256 111
    OPTION_REGbits.PS1=1; //PREESCALER 1:256 111
    OPTION_REGbits.PS0=1; //PREESCALER 1:256 111
    //idealmente el reset_timer0
    
    //CONFIGURACION DE INTERRUPCIONES
    INTCONbits.GIE=1; //se habilitan las interrupciones globales
    INTCONbits.T0IE=1; //enable bit de int timer0
    INTCONbits.TMR0IF=0; //se apaga la bandera de int timer0
      
}

/*-----------------------------------------------------------------------------
------------------------------- funciones -------------------------------------
-----------------------------------------------------------------------------*/

