//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;

void create() {
    ::create();
    set_name("bundle of wooden stakes");
    set_id( ({"stakes","bundle", "wooden stakes", "wood" }) );
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
  int stakes;
  object room;
  desc = "%^ORANGE%^A bundle of sturdy, sharpened wooden stakes.%^RESET%^";
  room = EETO;
  if (!objectp(room)){
    room= ETO;
  }
  if (objectp(room)){
    stakes = room->staked();
    filename = file_name(room);
    if(TABAXROOM + "main_field" == filename[0..strlen(TABAXROOM + "main_field")-1]
     ||TABAXROOM + "high_field" == filename[0..strlen(TABAXROOM + "high_field")-1]
     ||TABAXROOM + "low_field" == filename[0..strlen(TABAXROOM + "low_field")-1]){
      switch (room->query_pitted()){
      case 0: //CLEAR OF PITS
        switch (stakes){
        case 0:
          desc +=" You could probably %^BOLD%^%^YELLOW%^<plant>%^RESET%^ the stakes in defensive lines"
                +" here";
          break;
        }
        break;
      case 1: // PITS IN THE ROOM
        switch (stakes){
        case 0:
          desc +=" You could probably %^BOLD%^%^YELLOW%^<plant>%^RESET%^ the stakes in defensive lines"
               +" here, or %^BOLD%^%^YELLOW%^<bury>%^RESET%^ them in the pits";
          break;
        case 1:
          desc +=" You could probably %^BOLD%^%^YELLOW%^<bury>%^RESET%^ the stakes in the pits here";
          break;
        }
        break;
      case 2..4: // COVERED PITS, STAKED PITS, COVERED & STAKED PITS
        switch (stakes){
        case 0:
          desc +=" You could probably %^BOLD%^%^YELLOW%^<plant>%^RESET%^ the stakes in defensive lines"
               +" here";
          break;
        }
      }
    }
  }
  return desc;
}
