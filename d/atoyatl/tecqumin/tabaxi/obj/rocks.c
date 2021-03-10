//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;

void create() {
    ::create();
    set_name("rocks");
    set_id( ({"rocks","rock", "bunch of rocks" }) );
    set_short("%^RESET%^%^ORANGE%^bunch of rocks%^RESET%^");
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
  desc = "%^ORANGE%^A bunch of rocks. They're, you know, rocky.%^RESET%^";
  room = EETO;
  if (!objectp(room)){
    room= ETO;
  }
  if (objectp(room)){
    if (present("cauldron", room) || present("cauldron", TP)){
      desc += "\nYou could probably use them to fill the cauldron";
    }
  }
  return desc;
}
