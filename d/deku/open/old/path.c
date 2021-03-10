#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Shadowlord forest");
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_long(
@KAYLA
Opening up before you is a trail of some kind.  The trees and brambles
to either side of the path intertwine and curve upward to form an arch
which blocks out direct sunlight.  The path is a dark tunnel through a  
wall of leaves, roots, and briars.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/open/skull",
       "south" : "/d/deku/open/forest63"
    ] ));
    set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
    set_items(([
    ] ));
}

int GoThroughDoor() {
   object ob, obj;
   if(avatarp(TP) && TP->query_invis()) return 1;
   if(present("ogre guard")) {
      write("HAHA, you weak "+TP->query_race()+"!!!");
      return 0;
    }
  ob = present("deku note",TP);
  if(!ob){
    write("Some sort of powerful magic prevents you from going north!");
    return 0;
  }
  ob->remove();
  write("The note disappears as you move north.");
  write("You may enter into the realm of darkness.");
  return 1;
}

void reset() {
  ::reset();
  if(!present("ogre")) {
    new("/d/deku/monster/ogre")->move(TO);
    new("/d/deku/monster/ogre")->move(TO);
  }
}
