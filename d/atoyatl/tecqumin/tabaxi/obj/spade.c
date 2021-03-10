//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;

void create() {
    ::create();
    set_name("spade");
    set_id( ({"spade","shovel" }) );
    set_short("%^ORANGE%^spade%^RESET%^");
    set_weight(4);
    set_long( (:TO, "long_desc":) );
}

void init(){
  ::init();
  set_long( (:TO, "long_desc":) );
}

string long_desc(){
  string desc, filename;
  object room;
  desc = "%^ORANGE%^A %^RESET%^sharp bladed %^ORANGE%^spade, with a sturdy handle.%^RESET%^";
  room = EETO;
  if (!objectp(room)){
    room= ETO;
  }
  if (objectp(room)){
    filename = file_name(room);
    if(TABAXROOM + "main_field" == filename[0..strlen(TABAXROOM + "main_field")-1]
     ||TABAXROOM + "high_field" == filename[0..strlen(TABAXROOM + "high_field")-1]
     ||TABAXROOM + "low_field" == filename[0..strlen(TABAXROOM + "low_field")-1]){
      if (room->query_pitted()==0){
        desc += " You could probably %^BOLD%^%^YELLOW%^<dig>%^RESET%^ some pits here.";
      }
    }
  }
  return desc;
}