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
"%^RESET%^are in poor shape here, with holes and cracks that let the weather "
"in.  The %^ORANGE%^floor %^RESET%^is covered in dust and dirt, and streaks of "
"mud have been tracked across it.  Patches of %^GREEN%^moss %^RESET%^have crept "
"over the walls and floor, making travel treacherous in some places.%^RESET%^");
   set_smell("default","The air is filled with dust.");
   set_listen("default","The wind whistles through the cracks in the walls.");
   set_items(([
     ({"walls","holes","cracks"}) : "%^BLUE%^The stone walls that make up the "
"keep are in poor shape here.  They don't look as if they're about to fall down"
", but there are sizeable holes and cracks running through some blocks, letting "
"in the wind and allowing moisture to creep inside.  %^GREEN%^Moss %^BLUE%^has "
"grown over some sections, making footing dangerous.%^RESET%^",
     ({"floor","dust","dirt","mud"}) : "%^ORANGE%^The floor is made of stone "
"bricks and is covered in dirt and dust.  Streaks of mud have been tracked "
"through the hallway by something.%^RESET%^",
     "moss" : "%^GREEN%^Patches of moss have grown over the walls and floor.  "
"They are wet and slimy, making footing treacherous in some places.%^RESET%^",
   ]));
}

void reset()
{
    ::reset();
    return;
}