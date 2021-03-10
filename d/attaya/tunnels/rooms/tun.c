#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit VAULT;

string long_desc();

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set("short", "A narrow tunnel");
  set_long((:TO, "long_desc":));
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_smell("default","The air smells of damp stone");
  set_listen("default","You can hear the sound of music coming from deep"
                      +" within the tunnels.");

  set_items( ([ 
     ({ "wall", "walls"}):" %^BOLD%^%^BLACK%^The walls are of black"
                         +" s%^RESET%^l%^BOLD%^%^BLACK%^ate. They are"
                         +" smooth in places, but cracked and uneven in"
                         +" others, making it hard to know whether they"
                         +" have been worked or not..",

  ({ "cracks", "fissures"}):"the larger cracks look big enough for"
                           +" something to go into of come out of, but"
                           +" they are way up out of"
                           +" reach.", 

  "ceiling" : "the ceiling is so high up as to be out of sight.",

  "floor" : "The floor is smooth, and relatively free of dirt. There are"
           +" scuff marks on it suggesting this place is frequently"
           +" travelled." 
  ]) );

  set_search("walls","you find many small cracks and fissures in the"
                    +" slate. There appear to be larger cracks higher up"
                    +" on the walls, out of reach." );

}


string long_desc(){
    return "%^BOLD%^%^BLACK%^This is a narrow tunnel cut through the"
          +" black rock. It is unclear whether this is a crudely"
          +" constructed tunnel or simply a natural fissure, but the"
          +" walls are steep and tall, and the ceiling is way out of"
          +" sight overhead.%^RESET%^";
}