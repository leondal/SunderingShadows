#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall2";

void create(){ 
   ::create();
   set_long("%^CYAN%^Hallway of a ruined keep%^RESET%^\n"
"You are standing just inside the entrance of a ruined keep.  The %^BLUE%^walls "
"%^RESET%^show signs of damage here, with holes and cracks that let the weather "
"in.  The %^ORANGE%^floor %^RESET%^is covered in dust and dirt, and streaks of "
"mud have been tracked across it.  Patches of %^GREEN%^moss %^RESET%^have crept "
"over the walls and floor, making travel treacherous in some places.  The "
"corridor heads northwards deeper into the keep.  Crumbling walls to the south "
"offer a way out of the building.\n");
   set_exits(([
     "north" : ROOMS"keep7",
     "south" : ROOMS"keep2",
   ]));
}
