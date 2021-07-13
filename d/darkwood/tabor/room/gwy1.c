//updated by Circe 6/2/04 with color, etc
// Gwydion Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// gwy1.c
//exit for path to Koenig added by Circe 11/29/03

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

#define BADDIES ({"ogre","half-ogre","hobgoblin","bugbear","goblin","orc","ogre-mage","gnoll","kobold","drow","half-drow"})

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Gwydion Street, Tabor");
  set_short("Gwydion Street, Tabor");
  set_long(
@TABOR
%^BOLD%^Gwydion Street, Tabor%^RESET%^
You are on %^BOLD%^%^BLUE%^Gwydion Street %^RESET%^in Tabor at the east end of town.  From here
you can make out the %^CYAN%^Wizard's Tower %^RESET%^on top of %^RED%^Mount Dragon %^RESET%^that was the
model for the Wizard's Tower that was built in Shadow.  You see a seldom
trod road which leads up the steep slope of the hill start to the
northeast.  Another road leads through a narrow gate to the southeast.

%^BOLD%^%^MAGENTA%^There is a sign you can look at here.

%^WHITE%^There is a stone slab bearing a written message you should read.

%^BOLD%^%^BLUE%^Gwydion Street %^RESET%^continues to the west.
TABOR
    );
  set_exits(([
    "northeast" : ROOMDIR+"way1",
    "west" : ROOMDIR+"gwy2",
    "southeast" : "/d/koenig/streams/path18"
//      "southeast" : ROOMDIR+"shadow1"
  ]));
  set_listen("default","You hear the muffled sounds of a busy town all around you.");
  set_smell("default","The slightly rank scent of a busy city "+
    "lingers in the air.");
  set_items(([
    "sign" : "%^CYAN%^Wizard's Way%^RESET%^: Northeast to %^CYAN%^"
             "Wizard's Tower\n"+
             "%^BOLD%^%^WHITE%^Koenig Pathway%^RESET%^ : East to %^GREEN%^"+
             "Koenig Village %^RESET%^and %^YELLOW%^Echoes Mountains\n"+
	       "%^BOLD%^%^BLUE%^Gwydion Street%^RESET%^: West to %^GREEN%^"+
             "Greene Street %^RESET%^and %^MAGENTA%^Mathowvy Road",
    ({"stone","slab","stone slab","laws"}) : "This stone slab bears "+
       "the laws of Tabor.  You should definitely read it and heed its "+
       "message."
  ]));
  set_pre_exit_functions(({"northeast","west"}),({"go_past","go_past"}));
  set_post_exit_functions(({"southeast"}),({"GoThroughDoor"}));
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
   tell_object(TP,"%^B_RED%^%^YELLOW%^Stepping through the gates, you "+
      "realize you are heading towards the abandoned town of Koenig.  "+
      "You remember hearing that orcs are thought to have invaded that "+
      "place.  A strange farm lies near the streams there.  This pathway "+
      "will also lead you to the Quiet Forest Road, and from there, you "+
      "may explore the Echoes Mountains, Goblin Stronghold, and various "+
      "other places and cities.");
   return 1;
}
