//Coded by Lujke


#include <std.h>
#include "../tecqumin.h"
inherit OBJECT;

void create() {
    ::create();
    set_name("Healing stone");
    set_id( ({"healing stone","stone","jet", "jetstone", "jet stone", "xxjetstonexx" }) );
    set_short("%^BOLD%^%^BLACK%^A piece of jetstone%^RESET%^");
    set_weight(1);
    set_long( (: TO, "long_desc" :) );
}

void init(){
  ::init();
  add_action("cure_quali", "heal");
    set_long( (: TO, "long_desc" :) );
}

string long_desc(){
  string desc;
  desc =     "%^BOLD%^%^BLACK%^A simple stone of jet, shaped into a flat"
            +" oval, with a jaguar's face carved into the front. Intricate"
            +" runeshapes surround the jaguar face and adorn a circled"
            +" pentagram inscribed on the back of the stone.";
  if ( (objectp(ETO) && present("quali", ETO)) || (objectp(EETO) && present("quali", EETO)) ){
    desc += "%^RESET%^%^CYAN%^ This stone has been blessed by a priest of the Tecqumin. You could use"
           +" it to %^RESET%^heal%^CYAN%^ the mind of the jungle spirit";
  }
  return desc;
}

int cure_quali(string str){
  object room, quali, healer;
  healer = ETO;
  if (!objectp(healer)){return 0;}
  room = environment(healer);
  if (!objectp(room)){return 0;}
  quali = present("quali", room);
  if (!objectp(quali)|| quali != present("spirit", room)){return 0;}
  if (!quali->id(str)){return 0;}
  tell_object(healer, "%^BLUE%^Raising the %^BOLD%^%^BLACK%^Jetstone"
                     +" %^RESET%^%^BLUE%^in your hands, you point the"
                     +" jaguar face toward %^GREEN%^Quali%^BLUE%^ and"
                     +" whisper the mystic phrase taught to you by the old"
                     +" priest.");
  tell_room(room, "%^BLUE%^" + healer->QCN + "%^RESET%^%^BLUE%^ raises a"
                 +" piece of intricately carved %^BOLD%^%^BLACK%^Jetstone"
                 +" %^RESET%^%^BLUE%^in " + healer->QP + " hands, angling"
                 +" it to point towards %^GREEN%^Quali.  At the same time,"
                 + healer->QP + " whispers strange sounding syllables under"
                 +" " + healer->QP + " breath%^RESET%^", healer);
  quali->heal_mind(healer);
  return 1;
}
