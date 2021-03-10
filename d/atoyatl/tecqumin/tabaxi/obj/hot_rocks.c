//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;

void create() {
    ::create();
    set_name("hot rocks");
    set_id( ({"rocks","rock", "bunch of rocks", "hot rocks", "bunch of hot rocks" }) );
    set_short("%^RESET%^%^ORANGE%^bunch of %^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^t"
             +" %^RESET%^%^ORANGE%^r%^RED%^o%^ORANGE%^cks%^RESET%^");
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
  desc = "%^ORANGE%^A bunch of %^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^t"
        +" %^RESET%^%^ORANGE%^r%^RED%^o%^ORANGE%^cks. They're"
        +" gl%^BOLD%^%^RED%^o%^RESET%^%^ORANGE%^w%^RED%^i%^ORANGE%^ng with the heat.%^RESET%^";
  room = EETO;
  if (!objectp(room)){
    room= ETO;
  }
  if (objectp(room)){
    if (present("cauldron", room) || present("cauldron", TP)){
      desc += "\n%^RESET%^You could probably use them to fill the cauldron";
    }
  }
  return desc;
}
