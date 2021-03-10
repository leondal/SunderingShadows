#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(NAT_CAVE);
   set_travel(DIRT_ROAD);
    set_property("light",0);
    set_property("indoors",1);
    set_short("Kobold Caverns");
    set_long(
@KAYLA
  You are moving deeper into the mountain's side.  All around you
the stone is magically carved.  There is a flicker of light toward
the north.
KAYLA
    );
      set_listen("default","Peculiar, the cavern is deadly quiet.");
    set_exits(([
       "south" : "/d/deku/new/cave10",
       "north" : "/d/deku/new/cave12"
    ] ));
    set_items(([
          "walls" : "The cavern walls are magically formed."
    ] ));
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}


void reset() {
  ::reset();
  if(!present("hobgoblin")) {
    new("/d/deku/monster/hobgob")->move(this_object());
  }
}

int GoThroughDoor() {
   object obj;
     obj = present("smelly hobgoblin");
   if(TP->query_invis()) return 1;
     if(objectp(obj) && !obj->id("undead")){
      write("%^MAGENTA%^The hobgoblin says%^RESET%^: No one disturbs the King!");
    return 0;
  }
  return 1;
}
