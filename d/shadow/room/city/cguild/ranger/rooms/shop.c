#include <std.h>
#include "../ranger.h"
inherit ROOM;

void create(){
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_property("no teleport",1);
   set_name("A side alcove");
   set_short("%^RESET%^%^GREEN%^A side alcove%^RESET%^");
   set_long("%^RESET%^%^GREEN%^A side alcove%^RESET%^\n"
"%^RESET%^%^ORANGE%^Off to the side of the main hollow in the trunk resides this little alcove, enclosed on "
"all sides by the %^RED%^rough wood %^ORANGE%^of the tree.  The walls retain a %^BOLD%^%^BLACK%^ro%^RESET%^ug"
"%^BOLD%^%^BLACK%^h %^RESET%^%^ORANGE%^texture, though the floor has been worn smooth by the passage of many "
"feet over time.  Low-roofed, long and narrow, this alcove likely extends into one of the tree's massive "
"limbs judging by its overall shape.  Softly glowing orbs of %^GREEN%^vi%^CYAN%^rid%^GREEN%^ian li%^CYAN%^gh"
"%^GREEN%^t %^ORANGE%^shed a gentle, natural radiance about the partially enclosed and darkened room.  The "
"furthest recesses contain neatly-arranged stock for the little store that resides here, with bows and arrows "
"that are neatly kept in oilskins and quivers, lying upon raised bumps in the wood or propped against the "
"walls.  Treated leathers have been neatly laid out for perusal by visitors, alongside various tools and "
"snares.  Beyond all this, an opening in the wooden walls leads out towards the more spacious centre of the "
"tree itself.\n%^RESET%^");
   set_smell("default","The sweet smell of fresh air and greenery surrounds you.");
   set_listen("default","The quiet surroundings are occasionally interrupted by the soft creak of wood.");

   set_items(([
     ({"walls","wood","bark","tree","trunk","roof","floor"}):"%^RESET%^%^ORANGE%^It seems as though a thick "
"limb of a %^GREEN%^massive oak tree %^ORANGE%^forms this room, enclosed on all sides by %^RED%^rough-barked "
"wood%^ORANGE%^ in a long, low-roofed shape.  While the walls are %^BOLD%^%^BLACK%^ro%^RESET%^ug%^BOLD%^"
"%^BLACK%^h %^RESET%^%^ORANGE%^to the touch, the floor has been worn smooth by the passage of countless feet."
"%^RESET%^",
     ({"orbs","light","radiance"}):"%^RESET%^%^ORANGE%^Around the walls, softly glowing orbs of %^GREEN%^vi"
"%^CYAN%^rid%^GREEN%^ian li%^CYAN%^gh%^GREEN%^t %^ORANGE%^shed a gentle radiance upon the room itself."
"%^RESET%^",
     ({"store","bows","arrows","oilskins","quivers","tools","snares","recesses","stock"}):"%^RESET%^%^ORANGE%^"
"Kept within the low-roofed recesses of this alcove are all kinds of woodsman's tools, ranging from leathers "
"and snares through to bows and fletched arrows.  All are carefully stored and placed in clear view for "
"perusal.%^RESET%^",
   ]));

   set_exits(([
     "out":RROOM"hall2"
   ]));
}

void reset(){
   ::reset();
   if(!present("wolf"))
     find_object_or_load(RNPC+"wolflord")->move(TO);
}