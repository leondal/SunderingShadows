#include <std.h>
#include "../defs.h"
inherit INH+"tower";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^Within the Black Spire%^RESET%^\n"
"%^BLUE%^It's difficult to call this small room a store, since there is very little here other than a few shelves with "
"blocks of raw, %^RESET%^pa%^ORANGE%^l%^RESET%^e %^BLUE%^zurkhwood upon them in varied sizes.  A single comfortable "
"%^RED%^c%^MAGENTA%^ha%^RED%^ir %^BLUE%^has been placed in one corner, worn as though someone spends a lot of time in it"
".  Other than this, the room is identical to the rest of the tower, enclosed in %^BOLD%^%^BLACK%^glo%^RESET%^ss%^BOLD%^"
"%^BLACK%^y %^RESET%^%^BLUE%^obsidian %^RESET%^%^BLUE%^that sheds %^ORANGE%^m%^YELLOW%^u%^RESET%^%^ORANGE%^t%^RESET%^e"
"%^ORANGE%^d %^BLUE%^light around the area.  Only one exit is apparent, through the small archway that leads back to the "
"centre of the spire.%^RESET%^\n");

   add_item(({"archway","obsidian archway"}),"%^BLUE%^A small archway of matching mirror-smooth %^BOLD%^%^BLACK%^obsi"
"%^RESET%^di%^BOLD%^%^BLACK%^an %^RESET%^%^BLUE%^leads back into the centre of the spire.%^RESET%^");
   add_item(({"shelves","blocks","wood","zurkhwood","tools","knives"}),"%^BLUE%^A few shelves lie against the rear wall, "
"all of them set about with varied pieces of raw %^RESET%^zu%^ORANGE%^rk%^RESET%^hwo%^ORANGE%^o%^RESET%^d%^BLUE%^.  On "
"the lowest shelf lies a few chunky tools and heavy %^CYAN%^knives%^BLUE%^, lacking the finesse of weaponry but instead "
"likely designed for carving.%^RESET%^");
   add_item("chair","%^BLUE%^A single chair is the only other item of interest in this room.  Its sturdy %^RED%^zurk"
"%^MAGENTA%^hw%^RED%^ood %^BLUE%^legs support a piece upholstered in %^ORANGE%^dark l%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^"
"ather%^BLUE%^.  It seems well worn and bears an indentation in the middle from regular use.%^RESET%^");
   set_exits(([
     "south":ROOMS"tower6",
   ]));
}

void reset(){
   ::reset();
   if(!present("ilmayne")) new(MON"ilmayne")->move(TO);
}