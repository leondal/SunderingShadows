#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit ROOM;
int open;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_name("Up in a tree");
  set_short("%^GREEN%^Up in a tree%^RESET%^");
  set_long( (:TO, "long_desc":) );
  set_items(([ ({"clearing", "jungle clearing"}): "You can see a clearing"
          +" in the jungle nearby, with a massive higureon tree in the"
          +" centre of it.",
               ({"tree", "higureon tree"}) : "The tree is absolutely huge,"
          +" and you can see a wooden platform encircling the trunk at a"
          +" height of about thirty feet",
                ({"platform", "wooden platform"}):  "The platform"
          +" encircling the trunk of the higureon tree is approximately at"
          +" the same height as you are at the moment",
               ({"vine", "vines"}):"There are a number of loose vines"
          +" hanging from the branches above you, in addition to the"
          +" general tangle of vines around the trunk and limbs of the"
          +" tree",
               ({"loose vine", "loose vines"}):"Several of the vines are"
          +" within reach. You could probably swing on them if you wanted"
          +" to");
  set_search("","");
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.");
}
void init() {
   ::init();
   add_action("swing", "swing");
}

string long_desc(){
  string desc;
  desc =  "%^GREEN%^You are high in the branches of a vine-tangled tree,"
         +" overlooking a clearing in the %^BOLD%^%^GREEN%^j%^RESET%^"
         +"%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^"
         +"%^GREEN%^e%^RESET%^%^GREEN%^.";
  }
  return desc;
}

int swing(string str){
  
}