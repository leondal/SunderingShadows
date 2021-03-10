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
    drinker->set_eye_color(str);
    tell_object(drinker,"%^BOLD%^%^WHITE%^Your eyes grow momentarily blurred, and then they take on a distinctly "+str+" color!%^RESET%^");
    tell_room(environment(drinker),"%^BOLD%^%^WHITE%^"+drinker->QCN+"'s eyes suddenly turn "+str+"!%^RESET%^");
    return 1;
}

int potion_backfire(object drinker,int mystrength,string str) {
    string *myopt;
    int whichone;
    ::potion_backfire(drinker,mystrength,str);
    myopt = query_valid_args();
    whichone = random(sizeof(myopt));
    str = myopt[whichone];
    drinker->set_eye_color(str);
    tell_object(drinker,"%^BOLD%^%^WHITE%^Your eyes grow momentarily blurred, and then they take on a distinctly "+str+" color!%^RESET%^");
    tell_room(environment(drinker),"%^BOLD%^%^WHITE%^"+drinker->QCN+"'s eyes suddenly turn "+str+"!%^RESET%^");
    return 1;
}

string * query_valid_args() { return ({ "gray", "blue", "brown", "hazel", "green", "coffee", "chocolate", "sable", "cyan", "azure", "sapphire", "emerald", "silver", "amber", "yellow", "purple", "violet" }); }