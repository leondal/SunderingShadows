//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;

int lit;

void create() {
    ::create();
    lit = 0;
    set_name("brazier");
    set_id( ({"brazier","iron brazier", "basket brazier" }) );
    set_short("%^BOLD%^%^BLACK%^iron brazier");
    set_weight(15);
    set_long( (:TO, "long_desc":) );
}

void init(){
  ::init();
  set_long( (:TO, "long_desc":) );
  add_action("light_me", "light");
  add_action("douse_me", "douse");
}

int query_lit(){
  return lit;
}

int douse_me(string str){
  if (!objectp(ETO) || !interact ("brazier", str) || present(str, ETO)!= TO){
    return notify_fail("There doesn't seem to be a " + str + " here\n");
  }
  if (lit ==0){
    tell_object(TP, "The brazier is not lit");
    return 1;
  }
  if (interactive(ETO)){
    tell_object(TP, ("It's probably safer to put it down first"));
    return 1;
  }
  tell_object(TP, "You carefully extinguish the  %^RED%^f%^BOLD%^%^RED%^i%^RESET%^%^RED%^re%^RESET%^"
                 +"  in the bottom of the brazier");
  tell_room(ETO, TPQCN + "%^RESET%^ carefully extinguishes the %^RED%^f%^BOLD%^%^RED%^i%^RESET%^"
                 +"%^RED%^re%^RESET%^ in the bottom of the brazier", TP);
  lit = 0;
  return 1;
}

int light_me(string str){
  if (!objectp(ETO) || !interact ("brazier", str) || present(str, ETO)!= TO){
    return notify_fail("There doesn't seem to be a " + str + " here\n");
  }
  if (lit ==1){
    tell_object(TP, "The brazier is already lit");
    return 1;
  }
  if (interactive(ETO)){
    tell_object(TP, "Lighting that while carrying it would probably not be a good idea"); 
    return 1;
  }
  tell_object(TP, "You carefully set %^RED%^f%^BOLD%^%^RED%^i%^RESET%^%^RED%^re%^RESET%^ to the fuel"
                 +" in the bottom of the brazier");
  tell_room(ETO, TPQCN + "%^RESET%^ carefully sets %^RED%^f%^BOLD%^%^RED%^i%^RESET%^%^RED%^re%^RESET%^"
                 +" to the fuel in the bottom of the brazier", TP);
  lit = 1;
  return 1;
}

string long_desc(){
  string desc;
  desc = "%^BOLD%^%^BLACK%^A large, basket design iron brazier, with a carrying handle on either side"
        +" and a tripod base for standing on. The bottom of the basket is filled with %^RESET%^"
        +"%^ORANGE%^fuel%^BOLD%^%^BLACK%^. There is a sturdy iron hoop at the top, on which you could"
        +" place pots or cauldrons for heating.";
  switch(lit){
  case 0:
    break;
  case 1:
    desc += " A %^RESET%^%^RED%^f%^BOLD%^%^RED%^i%^RESET%^%^RED%^re%^BOLD%^%^BLACK%^ at the bottom of"
           +" the basket emits a constant heat and a dull gl%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^w of"
           +" light";
  }
  return desc;
}
