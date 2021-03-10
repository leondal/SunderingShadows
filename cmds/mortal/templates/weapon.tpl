
//armor template

#include <std.h>
#define MAGIC_EFFECT_D "/daemon/magic_effect"

inherit WEAPON;

int whichWield;
int whichUnwield;
int whichHit;

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
    set_size(~SIZE~);
    set_type(~TYPE~);
    set_prof_type(~PROF~);
    set_property("creator",~CREATOR~);
    set_property("quality",~QUALITY~);
    set_wc(~WC#~,~WC~);
    set_large_wc(~LWC#~,~LWC~);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    
}

int wield_func(){
     return MAGIC_EFFECT_D->magic_wield(whichWield, TP);        
}

int unwield_func(){
     return MAGIC_EFFECT_D->magic_unwield(whichUnwield, TP);        
}

int hit_func(object target){
     return MAGIC_EFFECT_D->magic_hit(whichHit, ETO, target);        
}



set_whichWield(int i){
     whichWield = i;
}

set_whichUnwield(int i){
     whichUnwield = i;
}

set_whichHit(int i){
     whichHit =i;
}

