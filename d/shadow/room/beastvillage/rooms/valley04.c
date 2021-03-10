#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);  
   set_property("light",2); 
   set_terrain(NEW_MOUNTS); 
   set_travel(FOOT_PATH); 
   set_name("A rough path through the forest");    
   set_short("%^GREEN%^A rough path through the forest%^RESET%^");

   set_long("%^GREEN%^A rough path through the forest%^RESET%^\n"
"%^ORANGE%^This rugged pathway is formed mainly of downtrodden dirt, with a few rocks "
"and boulders tumbled haphazardly into place from higher in the %^YELLOW%^Charu Mountains"
"%^RESET%^%^ORANGE%^.  To either side rise the eaves of the %^GREEN%^forest%^ORANGE%^, "
"mainly pine and ash that spread thick branches and foliage over the lesser shrubs beneath.  "
"Above their canopy, you catch glimpses of the still-taller mountain ridges, that effectively "
"serve to border the small valley in on all sides.  Somewhere nearby, you can hear the roar "
"of tumbling %^CYAN%^water%^ORANGE%^, towards which the rockier limits of the path seem to lead.  "
"Further north appears to be a clearing of sorts.%^RESET%^\n");

   set_smell("default","The mountain air is crisp and carries the fresh aroma of pine.");
   set_listen("default","You can hear the roar of a nearby waterfall.");

   set_items(([
           ({"path","pathway","dirt","rocks","boulders"}) : "%^ORANGE%^Beneath "
"your feet leads a pathway made up of dirt and a few tumbled stones, growing rockier "
"as it leads towards the sound of tumbling and rushing water to the southwest.  It "
"becomes little more than downtrodden earth the further north you travel, into the "
"depths of the forest.%^RESET%^",

           ({"mountains","ridges" }) : "%^BOLD%^%^WHITE%^High above the forest rise "
"the ridges of the Charu Mountains, effectively hemming in this tiny valley on all "
"sides.%^RESET%^",

           ({"forest","trees","pine","ash","shrubs"}) : "%^GREEN%^Within this isolated "
"valley stands an ancient forest, which rises above you on all sides.  Pine and ash branches "
"claw toward the sky above, casting dappled shadows across the lesser shrubs at their feet, "
"and the dirt path upon which you stand.%^RESET%^",

        ]));

   set_exits(([ 
     "south":ROOMS"valley03",
     "northeast":ROOMS"valley05",
   ])); 
}
