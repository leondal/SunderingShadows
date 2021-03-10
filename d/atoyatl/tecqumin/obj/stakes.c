//Coded by Lujke


#include <std.h>
#include "../tecqumin.h"
inherit OBJECT;

void create() {
    ::create();
    set_name("bundle of wooden stakes");
    set_id( ({"stakes","bundle", "wooden stakes" }) );
    set_short("%^RESET%^%^ORANGE%^bundle of wooden stakes%^RESET%^");
    set_weight(8);
    set_long( (:TO, "long_desc":) );
}

void init(){
  ::init();
  set_long( (:TO, "long_desc":) );
}

string long_desc(){
  string desc, filename;
  object room;
  desc = "%^ORANGE%^A bundle of sturdy, sharpened wooden stakes.%^RESET%^";
  room = EETO;
  if (objectp(room)){
    filename = file_name(room);
    if(ROOMS + "platform" == filename[0..strlen(ROOMS + "platform")-1]){
      if ((int)room->query_screened()==1){
        desc += "\nYou could probably fix the stakes to the screens here";
      } else {
        desc += "\nYou might be able to use the stakes as a defensive"
               +" barrier if there was something to fix them to.";
      }   
    }
  }
  return desc;
}
