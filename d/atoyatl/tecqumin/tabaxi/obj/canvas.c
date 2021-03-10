//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;

void create() {
    ::create();
    set_name("canvas sheet");
    set_id( ({"sheet","canvas", "canvas sheet" }) );
    set_short("%^RESET%^%^ORANGE%^a large sheet of canvas.%^RESET%^");
    set_weight(8);
    set_long( (:TO, "long_desc":) );
}

void init(){
  ::init();
  set_long( (:TO, "long_desc":) );
}

string long_desc(){
  string desc, filename;
  int pits;
  object room;
  desc = "%^ORANGE%^A large sheet of canvas, useful for many things. You could make tents out of it,"
        +" or ships sails, stretch it across a wooden frame and make oil paintings, make some sailors'"
        +" pants out of it, or - well, you get the idea.%^RESET%^";
  room = EETO;
  if (!objectp(room)){
    room= ETO;
  }
  if (objectp(room)){
    filename = file_name(room);
    if(TABAXROOM + "main_field" == filename[0..strlen(TABAXROOM + "main_field")-1]
     ||TABAXROOM + "high_field" == filename[0..strlen(TABAXROOM + "high_field")-1]
     ||TABAXROOM + "low_field" == filename[0..strlen(TABAXROOM + "low_field")-1]){
      switch (room->query_pitted()){
      case 1: // PITS IN THE ROOM // deliberately falling through to next case
      case 3: // STAKED PITS IN THE ROOM
        desc +=" You could probably use the canvas to %^BOLD%^%^YELLOW%^<cover pits>%^RESET%^ and"
              +" camouflage them";
        break;
      default:
      }
    }
  }
  return desc;
}
