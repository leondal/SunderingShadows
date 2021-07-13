//updated by Circe 6/2/04 with color, etc.
// Mathowvy Road, just outside Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// math1.c

#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

#define BADDIES ({"ogre","half-ogre","hobgoblin","bugbear","goblin","orc","ogre-mage","gnoll","kobold","drow","half-drow"})

void create() {
  ::create();
  set_light(2);
  set_terrain(CITY);
  set_travel(DIRT_ROAD);
  set_name("Mathowvy Road, just outside Tabor");
  set_short("Mathowvy Road, just outside Tabor");
  set_long(
@DAI
%^BOLD%^Mathowvy Road, just outside Tabor%^RESET%^
You find yourself in front of a guard post on the edge of the %^GREEN%^forest%^RESET%^.
This appears to simply be a security precaution and traffic seems to
move freely past.  A short distance to the north, you see a town with
two %^ORANGE%^rocky hills %^RESET%^rising above it.  On the larger hill is a large %^YELLOW%^castle%^RESET%^,
and on the taller hill is a slender %^BOLD%^white tower%^RESET%^.

%^BOLD%^%^MAGENTA%^There is a sign here.

%^WHITE%^There is a stone slab bearing a written message you should read.

%^RESET%^%^MAGENTA%^Mathowvy Road %^RESET%^continues to the north and south.
DAI
    );
  set_exits(([
    "south" : "/d/darkwood/tabor/road/road1",
    "north" : ROOMDIR+"math2"
  ]));
  set_listen("default","You hear the sound of trees in the breeze.");
  set_smell("default","You catch a faintly rank scent of the city on the breeze.");
  set_items(([
    "hills" : "There is a larger hill and a taller hill you can see.",
    "larger hill" : "This is Mount Tabor, which is topped by the fortess of Caer Tabor",
    "taller hill" : "This is Mount Dragon, which is topped by the Wizard's Tower of Tabor",
    "sign" : "%^MAGENTA%^Mathowvy Road%^RESET%^: North to Tabor, south to Azha in Tsarven",
    "guard post" : "A small, but sturdy booth where the Tabor guards watch traffic.",
    ({"stone","slab","stone slab","laws"}) : "This stone slab bears "+
       "the laws of Tabor.  You should definitely read it and heed its "+
       "message."
  ]));
  set_pre_exit_functions(({"north"}),({"go_past"}));
  set_post_exit_functions(({"south"}),({"GoThroughDoor"}));
 }

void reset(){
	::reset();
   if(!present("tabor guard")) {
      new("/d/darkwood/tabor/mon/guard")->move(TO);
      new("/d/darkwood/tabor/mon/guard_guide")->move(TO);
   }
   if(!present("PsyKnight Reinforcement")) {
      new("/d/darkwood/tabor/mon/psyknight")->move(TO);
   }
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

void init(){
   ::init();
   add_action("read","read");
}

int read(string str){
   if(!str) return 0;
   if(str == "laws" || str == "slab" || str == "stone slab"){
      tell_object(TP,"You read over the laws carved into the slab.");
      tell_room(ETP,""+TPQCN+" reads the laws on the stone slab.",TP);
      TP->more("/d/darkwood/tabor/obj/tabor_laws");
      return 1;
   }
   return 0;
}

int go_past(){
   string race;
   object obj, shape;
   race = TP->query_race();
   if(objectp(shape = TP->query_property("shapeshifted"))) race = (string)shape->query_shape_race();
   if(objectp(shape = TP->query_property("altered"))) race = (string)shape->query_shape_race();
   if(avatarp(TP)) return 1;
   if(TP->query_invis() || TP->query_hidden()) return 1;
   if(member_array(race, BADDIES) != -1) {
     if(obj = present("tabor guard")) {
       obj->force_me("emote places one hand on his sword and "+
          "holds the other forward.");
       obj->force_me("say Your kind is not welcome here after "+
          "all the disruptions they have caused.");
       return 0;
     }
   }
   return 1;
}

//GoThroughDoor added by Circe to inform those of lower levels where they 
//are heading.  6/14/05
int GoThroughDoor(){
   int lvl = TP->query_lowest_level();
   if(lvl > 15) return 1;
   tell_object(TP,"%^B_RED%^%^YELLOW%^As you make your way south of the "+
      "city of Tabor, you realize you are heading towards the dark "+
      "Yntala Forest, which can prove quite a challenge to young adventurers.  "+
      "If you stay on the road, you will come to Azha and the southern "+
      "territories.");
   return 1;
}
