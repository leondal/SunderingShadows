//armor template

#include <std.h>

#define MAGIC_EFFECT_D "/daemon/magic_effect"


inherit ARMOUR;

int whichWear;
int whichRemove;
int whichStruck;

void create(){
     ::create();
     set_name(~NAME~);
     set_id(~ID~);
     set_short(~SHORT~);
     set_long(
@PLAYER
~LONG~
PLAYER
    );
    set_weight(~WEIGHT~);
    set_value(~VALUE~);
    set_ac(~AC~);
    set_size(~SIZE~);
    set_type(~TYPE~);
    set_limbs(~LIMBS~);
    set_property("creator",~CREATOR~);
    set_property("quality",~QUALITY~);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"struck_func":));
}



int wear_func(){
     return MAGIC_EFFECT_D->magic_wear(whichWear, TP);        
}

int remove_func(){
     return MAGIC_EFFECT_D->magic_remove(whichRemove, TP);        
}

int struck_func(int dam, object what, object who){
     return MAGIC_EFFECT_D->magic_struck(whichStruck, ETO, dam, what, who);        
}


set_whichWear(int i){
     whichWear=i;
}

set_whichRemove(int i){
     whichRemove=i;
}

set_whichStruck(int i){
    whichStruck=i;
}
