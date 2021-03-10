//cave40.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_long(
      ""+TO->query_long()+"Looking around, you "+
      "see that deep shadows climb far up the eastern wall."
      "\n"
    );
    add_item("wall","The eastern wall is covered with deep shadows.");
    add_item("shadows","The shadows seem to be formed by a ledge that looks "+
      "to lead to an alcove.");
    add_item("ledge","Perhaps if you are skilled enough or have the proper "+
      "tools, you could climb up to it.");
    add_item("alcove","Perhaps if you are skilled enough or have the proper "+
      "tools, you could climb up to it.");
 
    set_exits(([
        "west" : ROOMS"cave39"
   	]));
    set_climb_exits((["climb":({ ROOMS"cave41",10,6,100})]));
    set_fall_desc(
@FALL
You fall back down about 20 feet and land on some rocks and other
debris.  Ouch, that hurts!
FALL
);
   	
   set_search("default","You notice a ledge and alcove about 20 ft. up the wall.");
   set_search("wall","You notice a ledge and alcove about 20 ft. up the wall.");
}

/*
void reset() {
   object ob,scroll;
  ::reset();
  if(!present("dragon")) {
   ob= new("/d/deku/monster/dragon");
   scroll = new("/d/magic/scroll");
   scroll->set_spell(4);
   scroll->move(ob);
   ob->move(TO);
  }
}
*/
