#include <std.h>
#include "../aketon_outpost.h"

inherit ROOM;

void create(){
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set_name("%^GREEN%^Around A Sequoia Tree");
   set_short("%^GREEN%^Around A Sequoia Tree");
   set_long("%^GREEN%^Around A Sequoia Tree%^RESET%^\n"+
      "%^GREEN%^Stairs woven from %^BOLD%^vines%^RESET%^%^GREEN%^"+
" spiral around this large %^ORANGE%^Sequoia%^GREEN%^ tree,"+
" offering easy passage up and down.  The Sequoia tree thrives"+
" with vitality, perhaps due to the care that is lavished upon it."+
"  The wide branches of the tree spiral and twist higher into the "
"air, providing an abundance of %^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^h"
"%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^e%^RESET%^%^GREEN%^.  "+
"The chatter of forest animals and songbirds can be heard up in the "
"branches.\n");
  set_smell("default","Fresh woodland scents linger in the air.");
   set_listen("default","Songbirds sing among the rustle of leaves.");
   set_items(([
      ({"trees","canopy","forest","boughs"}) : "%^GREEN%^The forest "+
         "around you feels ancient.  Some of the trees are "+
         "bigger than any you have ever seen before!",
      ({"stairs","vines"}) : "%^BOLD%^%^GREEN%^Seeming to be woven from"+
" nature itself, the staircase winds around the massive trunk "+
"of the Sequoia.  The vines are lush and healthy, displaying "+
"vibrant leaves.  The staircase has been created without a railing,"+
" so extreme care would be needed climbing and descending.",
      ({"tree","sequoia"}) : "%^ORANGE%^The mighty Sequoia is one of the "+
"largest trees in this ancient forest.  This Sequoia is so large, "+
"it looks as if it might take more than thirty people to encircle "+
"the trunk.  The bark of the tree has a rough texture to it, showing"+
" that it has endured centuries of changes.  The dark green leaves "+
"create a massive canopy that provide a cooling shade to this part of "+
"the forest.",
         ]));
   } 
