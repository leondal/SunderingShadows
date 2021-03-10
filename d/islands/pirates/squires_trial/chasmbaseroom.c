#include <std.h>
#include "squires_trial.h"

inherit ROOM;

void create(){
  ::create();
  set_terrain(BUILT_TUNNEL);
  set_travel(BACK_ALLEY);
  set_property("indoors",1);
  set_property("no sticks",1);
  set_property("no teleport",1);
  set_property("light",-2);
  
  set_short("A rocky chasm");
  set_smell("default","The air is stale.");
  set_listen("default","No sound disturbs the air.");
  set_search("default","The rocks are sharp, and you almost cut your hand.");
  
  add_item("stream","%^BOLD%^%^BLUE%^The water is clear and moves " +
            "quickly, babbling over the rough rocks.%^RESET%^%^WHITE%^");
            
  add_item("path","%^RESET%^%^BLUE%^It looks as if a path has formed by " +
            "shifting stones as feet have trod the same path.%^RESET%^%^WHITE%^");
}




void reset(){
  ::reset();
}
