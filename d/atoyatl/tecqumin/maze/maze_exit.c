#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit VAULT;

string long_desc();

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set_short("A small, circular room");
  set_long((:TO, "long_desc":));
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_smell("default","The air is stale and musty");
  set_listen("default","It is almost silent, other than your own echoing footsteps and occasional strange scrabbling sounds in the distance");

  set_items( ([     
       ({ "vine", "vines", "creeper","creepers"}):
                         "The %^GREEN%^vines%^RESET%^ and"
                        +" %^GREEN%^creepers%^RESET%^ run along, over, up"
                        +" and down the ziggurat in a crazy, matted"
                        +" tangle that makes the going somewhat hard as"
                        +" you walk along, and provides plentiful refuge"
                        +" for hidden biting %^MAGENTA%^insects%^RESET%^"
                        +" or other things",
  ]) );
  set_exits( ([ "down" : ROOMS + "exit" ,]) );

  
}


string long_desc(){
    return "A small, circular room, with a set of steps leading up to the level above";
}