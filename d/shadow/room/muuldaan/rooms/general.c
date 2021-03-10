#include <std.h>
#include "../defs.h"
inherit INH+"town";

void create(){ 
   ::create();
   set_long("%^BOLD%^A rough half-enclosed shanty%^RESET%^\n"
"The roof of this dark cavern arcs far above you, lost from view in the cave's %^BLACK%^%^BOLD%^shadows"
"%^RESET%^.  The walls are made of dull stone, still rough and jagged as though naturally formed.  Around "
"you is a half-enclosed shanty, with two rough walls of %^ORANGE%^wooden planks%^RESET%^ and a few%^RED%^ "
"skins%^RESET%^.  It doesn't seem well made enough to even support a roof, and little piles of%^ORANGE%^ "
"trash%^RESET%^ and %^BLUE%^debris%^RESET%^ are scattered around all corners of the room.  Here though, it "
"seems a few useful items have been rummaged forth from the trash, stacked in clearer sight on the top of "
"each pile.\n");

   set_exits(([
     "northwest":ROOMS"cavern8",
     "west":ROOMS"thief",
   ]));
}

void reset(){
   if(!present("zekkijn"))
     find_object_or_load(MON"zekkijn")->move(TO);
   switch(random(10)) {
     case 0:
     tell_room(TO,"%^ORANGE%^A small, grubby goblin passes you at a run, taking a swipe at your purse as he "
"goes.  He disappears into the crowd before you can even react.%^RESET%^");
     break;
     case 1..2:
     tell_room(TO,"%^RED%^Zekkijn smacks a goblin and sends it tumbling down the path, forcing it to drop "
"the item it was trying to steal.%^RESET%^");
     break;
     case 3..4:
     tell_room(TO,"%^BLACK%^%^BOLD%^Zekkijn searches through a nearby pile of trash, setting a few items "
"aside that might be semi-useful.%^RESET%^");
     break;
     case 5..6:
     tell_room(TO,"%^BLUE%^Something wet and slimy drips down on you from the roof above.%^RESET%^");
     break;
     case 7:
     tell_room(TO,"%^YELLOW%^A dying screech of some small creature echoes through the cavern from "
"outside.%^RESET%^");
     break;
     case 8..9:
     tell_room(TO,"%^GREEN%^A small gathering of goblins break out in a screaming fight over something one "
"of them managed to buy for a few silver pieces.%^RESET%^");
     break;
   }
}
