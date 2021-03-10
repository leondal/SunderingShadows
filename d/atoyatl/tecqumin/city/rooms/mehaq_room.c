#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../../tecqumin.h"

inherit VAULT;


string long_desc();

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_name("In a side room in a palace");
  set_short("In a side room in a palace");
  set_long( "This is a small, minimally furnished room inside the Tecqumin"
           +" palace. It has a window that looks ut onto the gardens, with"
           +" a stone window seat before it." );
  set_items(([  ]));
  set_smell("default","There is a damp, musty smell in here.");
  set_listen("default","The only sounds drift in from the jungle outside.");
  set_exits( ([ "west" : CITY_ROOM + "trophy_room" ]) );
  set_door("stone door", CITY_ROOM + "trophy_room", "west", 0);
  set_door_description("stone door", "A heavy stone door, with a square lintel.");

}

void reset(){
  object meh, * mehs, room;
  int i, count;
  ::reset();
  if (!present("mehaq", TO)){
    mehs = children(MOB + "empress");
    count = sizeof(mehs);
    if (count>0){
//      tell_room(TO, "I found " + count + " empresses");
      for (i=count-1;i>=0;i--){
        if (!objectp(mehs[i])){
          mehs -= ({mehs[i]});
          continue;
        }
//        tell_room(TO, "Empress " + i + " is a valid object.");
        room = environment(mehs[i]);
        if (!objectp(room)){
          mehs -= ({mehs[i]});
          continue;
        }
//        tell_room(TO, "Empress " + i + " is in a valid room.");
      }
    }
//    tell_room(TO, "After checking them all, " + sizeof(mehs) + " empresses remains");
    if (sizeof(mehs)<1){
      meh = new (MOB + "empress");
      meh->move(TO);
      tell_room(ETO, "The air %^BOLD%^%^CYAN%^fl%^WHITE%^i%^CYAN%^ck"
        +"%^WHITE%^e%^CYAN%^r%^WHITE%^s%^RESET%^ and a %^CYAN%^spirit"
        +"%^RESET%^ appears");
    }
  } 
}
