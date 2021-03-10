#include <std.h>
#include "../aketon_outpost.h"

inherit ROOM;

void create(){
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set_name("%^GREEN%^Aketon Camp");
   set_short("%^GREEN%^Aketon Camp");
   set_long("%^GREEN%^This elven camp is nestled deep in the "+
      "forest.  Mighty %^ORANGE%^trees%^GREEN%^ tower high, "+
      "their leafy canopies creating a comforting shade.  "+
      "Ribbons of %^YELLOW%^sunlight%^RESET%^ %^GREEN%^stream "+
      "through the canopy, giving a %^MAGENTA%^m%^CYAN%^y"+
      "%^WHITE%^s%^CYAN%^t%^MAGENTA%^i%^WHITE%^c%^CYAN%^a%^MAGENTA%^l%^GREEN%^ "+
      "feeling to the camp.  A mighty %^RED%^redwood%^GREEN%^ tree rests in "+
      "the middle of the camp, supporting an elegant construction.  "+
      "The structure has been built in such a way as to work "+
      "with the natural form of the tree, rather than against it.\n");
   set("night long","%^BLUE%^This elven camp is nestled deep "+
      "in the forest.  Mighty %^ORANGE%^trees%^BLUE%^ tower "+
      "high, their leafy canopies creating a comforting shade.  "+
      "Ribbons of %^BOLD%^%^WHITE%^moonlight%^RESET%^ %^BLUE%^"+
      "stream through the canopy, giving a %^MAGENTA%^m%^CYAN%^y"+
      "%^WHITE%^s%^CYAN%^t%^MAGENTA%^i%^WHITE%^c%^CYAN%^a"+
      "%^MAGENTA%^l%^BLUE%^ feeling to the camp.  "+
      "A mighty %^RED%^redwood%^BLUE%^ tree rests in "+
      "the middle of the camp, supporting an elegant construction.  "+
      "The structure has been built in such a way as to work "+
      "with the natural form of the tree, rather than against it.\n");
   set_smell("default","Fresh woodland scents linger in the air.");
   set_listen("default","Songbirds sing among the rustle of leaves.");
   set_items(([
      ({"trees","canopy","forest"}) : "%^GREEN%^The forest "+
         "around you feels ancient.  Some of the trees are "+
         "bigger than any you have ever seen before!",
      ({"buildings","structure"}) : "%^BOLD%^Crafted out of "+
         "opaque crystal, the structures that are nestled in "+
         "the branches of the mighty redwood are of obvious "+
         "elven design.  Thin arches support the walls of the "+
         "structures, looking extremely fragile. Elegant "+
         "spires weave around, echoing a natural theme in their form."
   ]));
   set_exits(([
     "south" : ROOMS"aketon_path6",
     "enter" : ROOMS"aketon_foyer",
   ]));
} 
