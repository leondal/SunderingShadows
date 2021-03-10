#include <std.h>
#include "../defs.h"
inherit INH+"town";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^WHITE%^A small alcove\n"
"%^RESET%^This little alcove is blocked, for the most part, by the pile of "
"%^RED%^debris %^RESET%^at its entry, making it difficult to get back here.  "
"Once here though, you realise you must be standing in one of the %^CYAN%^"
"cleanest %^RESET%^spots in this entire cavern system.  The floor is lacking in "
"the usual scattering of rubbish, with only a few traces of %^ORANGE%^dirt "
"%^RESET%^and %^BLUE%^rocks %^RESET%^here and there.  Several flat-topped "
"%^BOLD%^%^BLACK%^stones %^RESET%^have been put to use around the room, most of "
"them holding tattered tomes and a few rolled-up parchments.\n");

   set_exits(([
     "northeast":ROOMS"components",
   ]));
}

void reset(){
   if(!present("greshk"))
     find_object_or_load(MON"greshk")->move(TO);
   switch(random(14)) {
     case 0:
     tell_room(TO,"%^ORANGE%^A small, grubby goblin passes you at a run, taking a swipe at your purse as he "
"goes.  He disappears into the cavern beyond before you can even react.%^RESET%^");
     break;
     case 1..2:
     tell_room(TO,"%^RED%^Greshk narrows his eyes and hisses at a nearby goblin, whose grimy hands "
"were getting too close to a set of parchments.%^RESET%^");
     break;
     case 3..4:
     tell_room(TO,"%^BOLD%^%^BLACK%^Greshk carefully sifts through several parchments, putting "
"them in order before he sets them back down.%^RESET%^");
     break;
     case 5..6:
     tell_room(TO,"%^BLUE%^Something wet and slimy drips down on you from the roof above.%^RESET%^");
     break;
     case 7:
     tell_room(TO,"%^YELLOW%^A dying screech of some small creature echoes through the cavern from "
"outside.%^RESET%^");
     break;
     case 8..9:
     tell_room(TO,"%^BOLD%^%^WHITE%^Greshk leafs through an old tome, merticulously copying out "
"arcane symbols onto a fresh sheet of parchment.%^RESET%^");
     break;
   }
}
