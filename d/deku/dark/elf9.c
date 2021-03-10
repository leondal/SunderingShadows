#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
    set_short("Gateway to the Abyss");
     set_long("A dim red glow emanates from the ceiling of the cavern. In "+
        "the center of the room stands a large stone statue of a dwarf.  "+
        "Its feet are planted on the floor, and its hands press against "+
        "the ceiling. A set of doors is behind the statue on the west wall.\n");
    set_listen("default","These rooms are deathly silent.");
    set_smell("default", "The vile smell of rot penetrates your mortal soul.");
    set_exits(([
       "west" : "/d/deku/dark/doom",
       "north" : "/d/deku/dark/room9"
    ] ));
    set_items(([
    "statue":"A large stone statue of a dwarf, with its feet planted upon the floor and his hands press against the ceiling.",
   "doors" : "A large set of golden doors, they stand 10 feet wide and\n"+
"are about 9 feet tall.\n"
      
    ] ));
    set_pre_exit_functions(({"west"}),({"go_west"}));
}

void reset() {
  ::reset();
  if(!random(3) && !present("elf")) {
    new("/d/deku/monster/elf")->move(TO);
    new("/d/deku/monster/elite")->move(TO);
    switch(random(5)) {
      case 0:  new("/d/deku/monster/captain")->move(TO);
      case 1..3:  new("/d/deku/monster/elf")->move(TO);
      case 4:  new("/d/deku/monster/elite")->move(TO);
    }
  }
}

int go_west() {
   if(present("darkelf")) {
    write("%^RED%^The Drow block anyone from entering through those doors.");
    return 0;
  }
  tell_room(ETP, "%^GREEN%^The doors open as "+TPQCN+" walks toward them.");
  tell_object(TP, "The doors open as you walk toward them.");
  return 1;
}
