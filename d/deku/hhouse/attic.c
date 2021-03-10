#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_short("Haunted House");
    set_long(
@KAYLA
Several holes in the roof allow dim light to enter this large,
dirty room which extends to the length of the house.  There are
pieces of broken furniture here and there and rubbish is heaped
about the floor.  There are two large sacks in the northwest
corner.  There are grimy cobwebs on the walls and ceiling and 
the floor is liberally strewn with dust and rubbish.
KAYLA
    );
     set_smell("default","The smell of rot and decay is all around");
    set_exits(([ "down" : HH_ROOMS+"landing" ] ));
    set_items(([
       "sacks" : "The two sacks contain useless old clothing and rags."
    ] ));
    set_pre_exit_functions(({"down"}),({"go_down"}));
}

void reset() {
  int r;
  ::reset();
  //taken out for now to reflect sandros' beheading of him and 
  //ruther's desire for the head to maybe get rid of him
  //permenantly
  //if(!present("knight")) {
  //  new("/d/deku/monster/dknight")->move(TO);
  //}
  if(!present("chest")){
    r = random(2);
   if(r==0) new("/d/hm_quest/chests/chest11")->move(TO);
    else new("/d/hm_quest/chests/chest27")->move(TO);
  }
}

int go_down() {
  if(present("knight")) {
    write("%^RED%^The Knight says:%^RESET%^ Fight until death!!");
    return 0;
  }
  return 1;
}
