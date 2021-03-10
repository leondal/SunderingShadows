#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall2";

void create(){ 
   set_monsters(({MONS+"xvart"}),({1}));
   ::create();
   set_repop(40);
   set_name("Dead end of a ruined keep");
   set_short("%^CYAN%^Dead end of a ruined keep%^RESET%^");
   set_long("%^CYAN%^Dead end of a ruined keep%^RESET%^\n"
"You are traveling down the hallway of a ruined keep.  The %^BLUE%^walls "
"%^RESET%^are in poor shape here, with holes and cracks that let the weather "
"in.  The %^ORANGE%^floor %^RESET%^is covered in dust and dirt, and streaks of "
"mud have been tracked across it.  Patches of %^GREEN%^moss %^RESET%^have crept "
"over the walls and floor, making travel treacherous in some places.  Crumbling "
"walls to the west offer a way out of the building.\n");
   set_exits(([
     "west" : ROOMS"keep4",
   ]));
}
