#include <stdio.h>
#include "unit.h"

void Init_unit(UNIT * U,char type,int owner,int x, int y){

	Owner(*U)		= owner;
    Type(*U)		= type;
    if(type=='S'){
        M_Hp(*U)		= 100;
        Hp(*U)			= 100;
        Atk(*U)			= 20;
        Def(*U)         = 15;
        Heal(*U)        = 0;
        M_Mov(*U)		= 3;
        Mov(*U)		    = 3;
        Cost(*U)		= 2;
        GHP(*U)          = 50;
        Atk_Type(*U)    = 'M';
    }else if(type=='A'){
        M_Hp(*U)		= 100;
        Hp(*U)			= 100;
        Atk(*U)			= 15;
        Def(*U)         = 15;
        Heal(*U)        = 0;
        M_Mov(*U)		= 2;
        Mov(*U)		    = 2;
        Cost(*U)		= 1;
        GHP(*U)          = 90;
        Atk_Type(*U)    = 'R';
    }else if(type=='K'){
        M_Hp(*U)		= 300;
        Hp(*U)			= 50;
        Atk(*U)			= 50;
        Def(*U)         = 30;
        Heal(*U)        = 0;
        M_Mov(*U)		= 1;
        Mov(*U)		    = 1;
        Cost(*U)		= 0;
        GHP(*U)          = 90;
        Atk_Type(*U)    = 'M';
    }else if(type=='W'){
        M_Hp(*U)		= 100;
        Hp(*U)			= 100;
        Atk(*U)			= 5;
        Def(*U)         = 5;
        Heal(*U)        = 25;
        M_Mov(*U)		= 3;
        Mov(*U)		    = 3;
        Cost(*U)		= 5;
        GHP(*U)          = 90;
        Atk_Type(*U)    = 'M';
    }

    /* Dummy for unitlist purpose*/
    else{
        M_Hp(*U)		= 0;
        Hp(*U)			= 0;
        Atk(*U)			= 0;
        Def(*U)         = 0;
        Heal(*U)        = 0;
        M_Mov(*U)		= 0;
        Mov(*U)		    = 0;
        Cost(*U)		= 0;
        GHP(*U)          = 0;
        Atk_Type(*U)    = 'Z';
    }
    Pos(*U)			= MakePOINT(x, y);
    Can_Atk(*U)		= true;

}

UNIT Create_new_unit(char type,int owner,int x, int y){

    UNIT new_unit;
    Init_unit(&new_unit,type,owner,x,y);
    return new_unit;
    }

void Show_unit_info (UNIT U){

    printf("Unit Type            : ");print_unit_type(U);printf(" \n");
    printf("Max HP               : %d\n", M_Hp(U));
    printf("HP                   : %d\n", Hp(U));
    printf("Atk                  : %d\n", Atk(U));
    printf("Def                  : %d\n", Def(U));
    if (Type(U)=='W'){
        printf("Healing (White Mage) : %d\n", Heal(U));
    }
    printf("Max Movement         : %d\n", M_Mov(U));
    printf("Movement             : %d\n", Mov(U));
    printf("Cost                 : %d\n", Cost(U));
    printf("Position             : <%d, %d>\n", Absis(Pos(U)), Ordinat((Pos(U))));
    printf("Attack Type          : %c\n", Atk_Type(U));
    printf("Can attack           : ");

    if (Can_Atk(U)){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
}
void show_unit_available(UNIT U,boolean Retaliates)
/*I.S. U terdefinisi*/
/*F.S. menuliskan atribut dari unit yang available*/
{
    print_unit_type(U);
    TulisPOINT(Pos(U));
    printf(" | ");
    printf("Health %d/%d  ",Hp(U),M_Hp(U));
    if(Retaliates){
        printf("(Retaliates)");
    }
    printf("\n");
}

void print_unit_type(UNIT U)
/*I.S. U terdefinisi*/
/*F.S. menuliskan jenis dari U*/
{
    if(Type(U)=='K'){
        printf("King ");
    }else if(Type(U)=='A'){
        printf("Archer ");
    }else if(Type(U)=='S'){
        printf("Swordman ");
    }else if(Type(U)=='W'){
        printf("White Mage ");
    }
}
