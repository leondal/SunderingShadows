#include <std.h>
#include "../defs.h"
inherit INH+"town";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^WHITE%^A debris-filled niche\n"
"%^RESET%^The roof of this dark cavern arcs far above you, lost from view in the cave's %^BOLD%^%^BLACK%^shadows%^RESET%^"
".  The walls are made of dull stone, still rough and jagged as though naturally formed.  Just beside "
"you is a half-enclosed shanty, its rough wall of %^ORANGE%^wooden planks %^RESET%^and a few "
"%^RED%^skins%^RESET%^ serving to hide whatever lies beyond.  Between the shanty and the cavern wall, "
"this niche seems to have been put to use by yet another scavenger of the cavern, filled with bits and "
"pieces.  Some look like nothing more than %^BLUE%^rubbish%^RESET%^, but a few seem like they might "
"be valuable.\n");

   set_exits(([
     "north":ROOMS"cavern8",
     "east":ROOMS"general",
   ]));
}

void reset(){
   ::reset();
   if(!present("snarfblat"))
     find_object_or_load(MON"snarfblat")->move(TO);
   switch(random(14)) {
     case 0:
     tell_room(TO,"%^ORANGE%^A small, grubby goblin passes you at a run, taking a swipe at your purse as he "
"goes.  He disappears into the crowd before you can even react.%^RESET%^");
     break;
     case 1..2:
     tell_room(TO,"%^RED%^Snarfblat snarls and takes a swipe at a nearby kobold, putting an abrupt "
"end to its attempt to steal something.%^RESET%^");
     break;
     case 3..4:
     tell_room(TO,"%^BOLD%^%^BLACK%^Snarfblat searches through a nearby pile of debris, looking for "
"something requested by a nearby bugbear.%^RESET%^");
     break;
     case 5..6:
     tell_room(TO,"%^BLUE%^Something wet and slimy drips down on you from the roof above.%^RESET%^");
     break;
     case 7:
     tell_room(TO,"%^YELLOW%^A dying screech of some small creature echoes through the cavern from "
"outside.%^RESET%^");
     break;
     case 8..9:
     tell_room(TO,"%^CYAN%^A small gathering of goblins break out in a screaming fight over something one "
"of them managed to buy for a few silver pieces.%^RESET%^");
     break;
     case 10..11:
     tell_room(TO,"%^BOLD%^%^WHITE%^Snarfblat offers a toothy grin and moves a few items around for better "
"viewing.%^RESET%^");
     break;
     case 12..13:
     tell_room(TO,"%^GREEN%^The precarious wall of the shanty beside you gives a creak of protest.%^RESET%^");
     break;
   }
}
