//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;

void create() {
    ::create();
    set_name("sand");
    set_id( ({"sand", "pile of sand" }) );
    set_short("%^RESET%^%^ORANGE%^pile of sand%^RESET%^");
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
  desc = "%^ORANGE%^A pile of sand. You could probably build a small castle. And stick a flag in it"
        +"%^RESET%^";
  room = EETO;
  if (!objectp(room)){
    room= ETO;
  }
  if (objectp(room)){
    if (present("cauldron", room) || present("cauldron", TP)){
      desc += "\nYou could probably use it to fill the cauldron";
    }
  }
  return desc;
}
