#include <std.h>
#include "keep.h"
inherit CVAULT;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("Hallway of a ruined keep");
   set_short("%^CYAN%^Hallway of a ruined keep%^RESET%^");
   set_long("%^CYAN%^Hallway of a ruined keep%^RESET%^\n"
"You are traveling down the hallway of a ruined keep.  The %^BLUE%^walls "
"%^RESET%^are in fairly good shape here, although a few holes and cracks let "
"the weather in.  The %^ORANGE%^floor %^RESET%^is covered in dust and dirt, and "
"streaks of mud have been tracked across it.");
   set_smell("default","The air is filled with dust.");
   set_listen("default","The wind whistles through the cracks in the walls.");
   set_items(([
     ({"walls","holes","cracks"}) : "%^BLUE%^The stone walls that make up the "
"keep are in moderate shape.  They don't look as if they'll fall down any time "
"soon, but there are enough holes and cracks running through some blocks, "
"letting in the wind and allowing moisture to creep inside.%^RESET%^",
     ({"floor","dust","dirt","mud"}) : "%^ORANGE%^The floor is made of stone "
"bricks and is covered in dirt and dust.  Streaks of mud have been tracked "
"through the hallway by something.%^RESET%^",
   ]));
}
