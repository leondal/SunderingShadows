//made teleport proof by Circe 11/8/03 to avoid people mis-teleporting to the hm island.  //Temporary fix
//adapted for Juran by Circe 1/17/05
inherit"/std/room";
#include "/d/antioch/areadefs.h"

void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_property("no teleport",1);
  set_short("A small office");
  set_short("A small office");
set_long(
@HMQUEST
You have entered a small office.  There are piles of paper and dust 
everywhere, covered in creeping mold.  The desk itself is somewhat 
clean, and a stury looking chair stands behind it.  Little other
furnishings are in this room - even the floor has been left 
bare stone.
HMQUEST
  );
  set_smell("default","You smell damp mold in the air.");
  set_listen("default","You hear the sounds of the city outside.");
  set_exits(([
    "south":"/d/shadow/juran/city/r40"
  ]));
}

void reset(){
  ::reset();
  if(!present("wizened goblin"))
    new("/d/hm_quest/mon/quest_goblin")->move(this_object());
}
