#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit VAULT;

string long_desc();

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set_short("A narrow tunnel");
  set_long((:TO, "long_desc":));
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_smell("default","The air smells fresh and clear here");
  set_listen("default","Birdsong and insect noises surround you");

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

  
}

string query_path(){
  return ROOMS;
}

string query_name(){
  return base_name(TO)[strlen(ROOMS)..strlen(base_name(TO))-1];
}

string long_desc(){
    return "You stand upon the steps of a large ziggurat, which rises"
          +" from the floor of the %^GREEN%^jungle%^RESET%^ like a"
          +" staggered %^ORANGE%^pyramid%^RESET%^. The stone beneath your"
          +" feet is aged and worn. %^GREEN%^Creepers%^RESET%^ and"
          +" %^GREEN%^vines%^RESET%^ of all sorts have grown across the"
          +" stone slabs, almost hiding the structure completely.";
}
