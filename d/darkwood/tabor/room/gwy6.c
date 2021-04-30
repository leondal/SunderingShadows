//updated by Circe 6/2/04 with color, etc
// Gwydion Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// gwy6.c

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
You are on %^BOLD%^%^BLUE%^Gwydion Street %^RESET%^in Tabor before the %^GREEN%^Fields of Tempus%^RESET%^. The
%^GREEN%^Fields %^RESET%^appear to be a small fenced building with a large field that has
%^ORANGE%^sparring yards %^RESET%^and an %^BOLD%^archery range %^RESET%^for training of the Royal Army and
any who seek better skills with their weapons. To the northwest, you see
that what appears to be an %^ORANGE%^ancient road %^RESET%^that has recently been repaired 
and leads out of town.

%^BOLD%^%^MAGENTA%^There is a sign you can look at here.

%^WHITE%^There is a stone slab bearing a written message you should read.

%^BOLD%^%^BLUE%^Gwydion Street %^RESET%^continues to the east.
To the northwest is a quiet but well kept road that travels out of the city.
TABOR
    );
  set_exits(([
    "northwest" : "/d/shadow/room/forest/road58",
    "east" : ROOMDIR+"gwy5",
    "trainer" : ROOMDIR+"trainer"
  ]));
  set_listen("default","You hear the muffled sounds of a busy town all around you.");
  set_smell("default","The slightly rank scent of a busy city "+
    "lingers in the air.");
  set_items(([
    "sign" : "%^GREEN%^Fields of Tempus%^RESET%^: Royal Army training "+
             "center.\n"+
             "%^BOLD%^Grand Trunk Highway%^RESET%^: North to Echoes "+
             "Mountains and Shadow's Gate\n"+
	       "%^BOLD%^%^BLUE%^Gwydion Street%^RESET%^: East to %^GREEN%^"+
             "Greene Street %^RESET%^and %^MAGENTA%^Mathowvy Road%^RESET%^",
    ({"stone","slab","stone slab","laws"}) : "This stone slab bears "+
       "the laws of Tabor.  You should definitely read it and heed its "+
       "message."
  ]));
  set_pre_exit_functions(({"trainer","east"}),({"go_past","go_past"}));
  set_post_exit_functions(({"northwest"}),({"GoThroughDoor"}));
 }

void reset()
{
   ::reset();
   if(!present("guard 2")) {
      new(MONDIR+"guard")->move(TO);
      new(MONDIR+"guard_guide")->move(TO);
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
   race = TP->query_race();
   if(objectp(shape = TP->query_property("shapeshifted"))) race = (string)shape->query_shape_race();
   if(objectp(shape = TP->query_property("altered"))) race = (string)shape->query_shape_race();
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
   tell_object(TP,"%^B_RED%^%^YELLOW%^As you step out through the gates, "+
      "you recall that you are heading towards the meadowlands.  These "+
      "can be dangerous to those who are inexperienced, but the paths are "+
      "supposed to be safe.  A known orc lair is said to lie out past "+
      "the meadowlands.");
   return 1;
}
