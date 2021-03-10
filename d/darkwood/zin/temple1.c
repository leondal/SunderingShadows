//      Darkwood Forest
//      Zincarla@ShadowGate
//      04/11/95

#include <std.h>
#include "./zin.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set_smell("default", "It smells of decay and horrid death.");
    set_listen("default", "Deep grunts echo about.");
    set_property("indoors", 1);
    set_property("light", 1);
    set("short", "The Ogre Temple");
    set("long", "The air in here is very damp and beads of water "+
        "slowly make their way down the sides of the temple walls.  "+
        "The floor has been smoothed through much wear of heavy "+
        "feet.  Standing along three of the corners are statues "+
        "carved from a dark stone.  There is a huge arch set into "+
        "the east wall.  You can feel evilness radiate about you.");
    set_items( ([
        "shadows": "They dance about...almost watching you...",
        "water": "It has left multicoloured streaks along the walls.",
        "arch": "It is actually very beautiful and lead east.",
        "statues": "They all represent a dark cloaked figure of "+
                   "great powers.",
    ]) );
    set_exits( ([
        "out": ROOM_DIR+"forest5",
        "east": ROOM_DIR+"temple2",
    ]) );
}

void reset() {
    ::reset();
    if(!present("guard")) {
        new(MON_DIR+"kobold_guard")->move(this_object());
        new(MON_DIR+"kobold_guard")->move(this_object());
    }
}

void init(){
  ::init();
  add_action("go_east","east");
}

int go_east(string str){
  if(present("guard",TO)){
    tell_object(TP,"%^BOLD%^The guard will not let you enter the temple!\n");
    tell_room(TO,"You see the guard step in front of "+TPQCN+" to block "+TP->query_possessive()+" entrance to the temple.",TP);
  return 1;
  }
  else{
    TP->move_player(ROOM_DIR+"temple2");
    return 1;
  }
}
