#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../../tecqumin.h"

inherit J_MAZE;
int open;

string long_desc();

void create() {
  string room_num, filename;
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
          +" to" ]));
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
  filename = file_name(TO);
  room_num = filename[strlen(filename)-2..strlen(filename)-1];
  set_climb_exits(([
    "descend":({TREEHOUSE + "/rooms/" + "treetop_base" + room_num,2,0, 30}),
  ]));

}
void init(){
  ::init();
  set_had_players(3);
}

string long_desc(){
  int i;
  string desc, * exits, direction;
  direction = "";
  exits = TO->query_exits();
  desc =  ::long_desc();
  if (sizeof(exits)>0){
    for (i=0;i<sizeof(exits);i++){
      if((string)TO->query_exit(exits[i]) == TREEHOUSE + "/rooms/" + "t_house_base"){
        direction = exits[i];
      }
    }
    if (direction !=""){
      desc += "%^RESET%^ A clearing to the " + direction + " is dominated"
             +" by a huge higureon tree.\n";
    }
  }
  return desc;
}
