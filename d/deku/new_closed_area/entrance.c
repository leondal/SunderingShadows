#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",0);
//    set_property("no attack",1);
   set_short("Kobold Forest");
    set_long(
@KAYLA
You just entered the Kobold Forest.  Black ironwood gates, 20' tall
stand firmly against the darkness of the forest.  Banded with steel
plates, locked by bolt and magic, these gates once sealed the forest 
from the more powerful intruders but now they stand wide open.  
%^RED%^ There is a large sign here.
KAYLA
    );
   set_smell("default","You smell the rich scents of the forest.");
   set_listen("default","You hear birds singing within the trees.");
    set_exits(([
       "enter" : "/d/deku/new/new1",
       "north" : "/d/shadow/room/forest/road9"
    ] ));
//    set_pre_exit_functions(({"enter"}),({"GoThroughDoor"}) );
    set_items(([
       "sign" : "This is the entrance to Kobold Caverns.  Once a newbie area, it is likely to be undergoing many changes now."
    ] ));
}

void init() {
   ::init();
//   add_action("sneak","sneak");
}

/*  Commenting out by Styx due to Newbietown opening to open it up to everyone per T.
void sneak(string str) {
   if(!str) return 0;
   if(str != "enter") return 0;
   if(TP->query_lowest_level() > 5) {
      write("This is a level restricted area!!");
      return 1;
   }
   return 1;
}

int GoThroughDoor() {
  if (this_player()->query_lowest_level() > 5) {
    if(present("gerack")) {
    write("%^MAGENTA%^Gerack says:%^RESET%^ Your skill is too great to remain in this area. Begone from here or I'll be forced to thrash you.");
    }
    else write("You are too powerful to enter this area.");
    this_player()->move_player("/d/shadow/room/forest/road9");
    return 0;
  }
  if(present("gerack"))
  write("%^MAGENTA%^Gerack says:%^RESET%^ You may enter young Squire.");
  return 1;
}
*/

void reset() {
  ::reset();
//  if(!present("gnome")){
//    new("/d/deku/monster/gerack")->move(this_object());
//    return 1;
//  }
}
