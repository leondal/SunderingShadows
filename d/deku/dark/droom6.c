#include <std.h>

inherit ROOM;

int num;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
     set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
   set_short("Passageway to the Abyss");
    set_long(
@KAYLA
%^YELLOW%^Passageway to the Abyss%^RESET%^
This passageway provides access to a network of caverns that connects
the Underdark to the surface world.
KAYLA
    );
    set_exits(([
       "east" : "/d/deku/dark/droom7",
       "west" : "/d/deku/dark/droom5"
    ] ));
    set_items(([
    ] ));
  num = 0;
}

void reset() {
  ::reset();
  num = 0;
}

void init() {
  ::init();
  if(num == 1) return 1;
  if( !random(3) && !present("darkelf") ) {
   tell_room(ETP,"%^YELLOW%^Darkelves surprise you from all sides of the cavern.");
   new("/d/deku/monster/elf")->move(TO);
   new("/d/deku/monster/elf")->move(TO);
   switch(random(3)) {
     case 0:  new("/d/deku/monster/elf")->move(TO);
     case 1:  new("/d/deku/monster/elf")->move(TO);
     case 2:  new("/d/deku/monster/elf")->move(TO);
     break;
   }
  num = 1;
  }
}
