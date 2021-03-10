#include "../brew.h"
inherit BREWPOTION;

string * query_valid_args();

void create() {
    ::create();
    set_property("instant potion",1);
}

int potion_effect(object drinker,int mystrength,string str) {
    ::potion_effect(drinker,mystrength,str);
    if(!str) {
      tell_object(drinker,"This potion has its variable broken! Sorry!");
      return 1;
    }
    drinker->set_hair_color(str);
    tell_object(drinker,"%^BOLD%^%^WHITE%^Your skin tingles briefly as every hair on your body becomes "+str+"!%^RESET%^");
    tell_room(environment(drinker),"%^BOLD%^%^WHITE%^All of "+drinker->QCN+"'s hair suddenly becomes "+str+"!%^RESET%^");
    return 1;
}

int potion_backfire(object drinker,int mystrength,string str) {
    string *myopt;
    int whichone;
    ::potion_backfire(drinker,mystrength,str);
    myopt = query_valid_args();
    whichone = random(sizeof(myopt));
    str = myopt[whichone];
    drinker->set_hair_color(str);
    tell_object(drinker,"%^BOLD%^%^WHITE%^Your skin tingles briefly as every hair on your body becomes "+str+"!%^RESET%^");
    tell_room(environment(drinker),"%^BOLD%^%^WHITE%^All of "+drinker->QCN+"'s hair suddenly becomes "+str+"!%^RESET%^");
    return 1;
}

string * query_valid_args() { return ({ "bald", "gray", "white", "red", "blonde", "brown", "black", "crimson", "scarlet", "auburn", "sable", "silver", "golden", "ebony", "blue", "bright pink" }); }