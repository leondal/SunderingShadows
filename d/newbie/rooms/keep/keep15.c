#include <std.h>
#include "../inherit/keep.h"
inherit CROOM;

void create(){ 
   ::create();
   set_repop(60);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("An abandoned mess hall");
   set_short("%^RESET%^%^CYAN%^An abandoned mess hall%^RESET%^");
   set_long("%^RESET%^%^CYAN%^An abandoned mess hall%^RESET%^\n"
"You are standing at the southern end of a vast mess hall.  A long "
"%^ORANGE%^table %^RESET%^extends nearly the full length of the room, but a "
"great crack has sundered it and caused it to fall inwards in the middle.  The "
"remains of broken %^BOLD%^%^WHITE%^crockery %^RESET%^and %^GREEN%^furniture "
"%^RESET%^are strewn all around the room, leaving very few clear sections of "
"%^BLUE%^floor %^RESET%^to walk upon, and even those are caked in grime and "
"dirt.  %^MAGENTA%^Bundles %^RESET%^of ruined cloth and furniture stuffing are "
"piled up in some corners, serving perhaps as a nest for some kind of creature"
".   A small doorway lies open here, the door long broken and gone, that leads "
"into what appears to be a kitchen.  At the far northern end of this mess hall "
"lies another, much larger doorway.\n");
   set_smell("default","The air is thick with the smell of mildew and decay.");
   set_listen("default","You can hear the scratching of claws on stone.	");
   set_exits(([
     "north" : ROOMS"keep14",
     "east" : ROOMS"keep16",
   ]));
   set_items(([
     "table" : "%^ORANGE%^A massive table stands in the middle of the room, "
"running nearly the full length of the hall.  A great crack has sundered it "
"through the middle, leaving each end tipped upwards as it dips down to meet "
"the floor in the centre.%^RESET%^",
     ({"crockery","furniture","floor"}) : "%^BLUE%^The floor is grimy and "
"covered in the dirt of ages, with little clawed prints tracked all across it.  "
"Broken crockery and furniture are strewn all about, making it hard to find "
"clear places to walk.%^RESET%^",
     ({"bundles","cloth","stuffing","nest"}) : "%^MAGENTA%^Around the edges of "
"the hall, piles of furniture stuffing and torn cloth have been bundled up into "
"what seem to be little nests for some sort of creature.%^RESET%^",
   ]));
}

void reset() {
   int active;
   active = has_mobs();
   if(!active) {
      if(mons) mons = ([]);
      set_monsters(({MONS"xvart"}),({random(3)+1}));
   }
   ::reset();
}
