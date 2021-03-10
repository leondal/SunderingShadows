//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;

void create() {
    ::create();
    set_name("hot sand");
    set_id( ({"sand", "pile of sand", "hot sand" }) );
    set_short("%^RESET%^%^ORANGE%^pile of %^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t"
             +" %^RESET%^%^ORANGE%^s%^RED%^a%^ORANGE%^nd%^RESET%^");
    set_weight(8);
    set_long( (:TO, "long_desc":) );
}

void init(){
  ::init();
  set_long( (:TO, "long_desc":) );
}

string long_desc(){
  string desc;
  object room, cauldron;
  desc = "%^ORANGE%^A pile of %^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t"
             +" %^RESET%^%^ORANGE%^s%^RED%^a%^ORANGE%^nd%^RESET%^. You could probably build a small"
            +" castle. But you'd burn your fingers."
        +"%^RESET%^";
  room = EETO;
  if (!objectp(room)){
    room= ETO;
  }
  if (objectp(room)){
    if (present("cauldron", room) || present("cauldron", TP)){
      desc += "\n%^RESET%^You could probably use it to fill the cauldron";
    }
  }
  return desc;
}
