#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit VAULT;


void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set_short("A small alcove");
  set_long(("A small alcove, off to one side from a tunnel beneath the ziggurat." ));
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_smell("default","The air is stale and musty");
  set_listen("default","It's very quiet");
  call_out("set_floor", 1);
  set_items( ([     
       ({ "root", "roots", }): "The ancient roots that have crept up"
                       +" through the floor here are gnarled and twisted,"
                       +" thick as an ogre's wrist and tough as old"
                       +" leather. They make moving at more than a"
                       +" walking pace difficult, and would take some"
                       +" effort to clear."
        ]) );
  set_exits( ([ "west" : ROOMS + "tun23"]) );
  
}
void init(){
  ::init();

}

