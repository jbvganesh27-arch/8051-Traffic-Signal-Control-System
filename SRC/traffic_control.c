#include <REGX51.H>

//-------------------- LEDs --------------------

// North
sbit NR = P1^0;
sbit NY = P1^1;
sbit NG = P1^2;

// South
sbit SR = P1^3;
sbit SY = P1^4;
sbit SG = P1^5;

// East
sbit ER = P2^0;
sbit EY = P2^1;
sbit EG = P2^2;

// West
sbit WRED = P2^3;
sbit WYEL = P2^4;
sbit WGRN = P2^5;

//---------------- Buttons ----------------

sbit B1 = P3^0;
sbit B2 = P3^1;
sbit B3 = P3^2;
sbit B4 = P3^3;
sbit B5 = P3^4;

// Active LOW LEDs
#define ON  1
#define OFF 0

void delay()
{
    unsigned int i,j;
    for(i=0;i<250;i++)
        for(j=0;j<1275;j++);
}

void AllRed()
{
    NR=ON; NY=OFF; NG=OFF;
    SR=ON; SY=OFF; SG=OFF;
    ER=ON; EY=OFF; EG=OFF;
    WRED=ON; WYEL=OFF; WGRN=OFF;
}

void North()
{
    NR=OFF;
    NY=OFF;
    NG=ON;

    SR=ON;
    SY=OFF;
    SG=OFF;

    ER=ON;
    EY=OFF;
    EG=OFF;

    WRED=ON;
    WYEL=OFF;
    WGRN=OFF;
}

void South()
{
    NR=ON;
    NY=OFF;
    NG=OFF;

    SR=OFF;
    SY=OFF;
    SG=ON;

    ER=ON;
    EY=OFF;
    EG=OFF;

    WRED=ON;
    WYEL=OFF;
    WGRN=OFF;
}

void East()
{
    NR=ON;
    NY=OFF;
    NG=OFF;

    SR=ON;
    SY=OFF;
    SG=OFF;

    ER=OFF;
    EY=OFF;
    EG=ON;

    WRED=ON;
    WYEL=OFF;
    WGRN=OFF;
}

void West()
{
    NR=ON;
    NY=OFF;
    NG=OFF;

    SR=ON;
    SY=OFF;
    SG=OFF;

    ER=ON;
    EY=OFF;
    EG=OFF;

    WRED=OFF;
    WYEL=OFF;
    WGRN=ON;
}

void main()
{
    P1 = 0xFF;
    P2 = 0xFF;
    P3 = 0xFF;

    AllRed();

    while(1)
    {
        if(B1==0)
        {
            North();
        }

        else if(B2==0)
        {
            South();
        }

        else if(B3==0)
        {
            East();
        }

        else if(B4==0)
        {
            West();
        }

        else if(B5==0)
        {
            AllRed();
        }
    }
}
