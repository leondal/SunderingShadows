#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_property("smithy",1); 
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
   set_name("A dark cavern");
   set_short("A dark cavern");
   set_smell("default","The thick, heavy stench of dampness and decay fills the cavern.");
   set_listen("default","A constant stream of chatter, screeching, grumbling and general rabble surrounds you.");
   set_long("%^BOLD%^A small cavern%^RESET%^\n"
"This little cavern is a small offshoot of the main cave, with the same rough and jagged stone to shape it.  "
"The stone floor is cold underfoot, and covered with the same %^ORANGE%^grime %^RESET%^as the rest of the "
"area.  Here, however, only a few small scraps of trash are visible, as if an attempt was actually made to "
"clear it up.  Instead, quite an assortment of %^BLACK%^%^BOLD%^rough weaponry%^RESET%^, %^ORANGE%^leathers "
"%^RESET%^and %^RED%^hide %^RESET%^are stacked unceremoniously around the walls, most in rather poor shape.  "
"It is actually rather %^RED%^hot%^RESET%^ in here, probably from the rough encasement of %^BLACK%^%^BOLD%^"
"burning coals %^RESET%^at the far side of the room, where a few anvils are unceremoniously resting around on "
"the floor.  A steady stream of creatures scurry in and out of the cavern opening.\n");

   set_items(([
     ({"cave","cavern","walls","ground","roof","ceiling"}):"The cavern is formed of dull stone, still jagged "
"in many places and probably not shaped by mortal hands.  A pathway works its way around the cavern, nothing "
"more than a trail that has been cleared through the piles of trash and miscellaneous crap filling the rest "
"of the cavern.",
     ({"goblins","kobolds","hobgoblins","bugbears","creatures","beasts"}):"All around you is a crowd of "
"creatures, constantly coming and going, pushing and shoving past one another.  With them comes a terrible "
"odor, and a constant racket of noise filling the cavern."
   ]));
   set_exits(([
     "west":ROOMS"cavern7",
   ]));
}

void reset(){
   ::reset();
   if(!present("burzkam"))
     find_object_or_load(MON"burzkam")->move(TO);
   switch(random(10)) {
     case 0:
     tell_room(TO,"%^ORANGE%^A small, grubby goblin passes you at a run, taking a swipe at your purse as he "
"goes.  He disappears into the crowd before you can even react.%^RESET%^");
     break;
     case 1:
     tell_room(TO,"%^RED%^Burzkam turns and snarls at a little kobold, whose spindly fingers quickly drop "
"the dagger it had attempted to steal.  It screeches and flees the cavern.%^RESET%^");
     break;
     case 2..3:
     tell_room(TO,"%^BLACK%^%^BOLD%^Burzkam grunts and bashes at a crudely made dagger.  Whether he's trying "
"to improve or break it is difficult to judge.%^RESET%^");
     break;
     case 4..5:
     tell_room(TO,"%^CYAN%^Burzkam tears off the lower half of a robe, effectively turning it into a smaller "
"garment for a goblin or kobold.%^RESET%^");
     break;
     case 6..7:
     tell_room(TO,"%^BLUE%^Something wet and slimy drips down on you from the roof above.%^RESET%^");
     break;
     case 8:
     tell_room(TO,"%^YELLOW%^A dying screech of some small creature echoes through the cavern from "
"outside.%^RESET%^");
     break;
     case 9:
     tell_room(TO,"%^GREEN%^A small gathering of goblins break out in a screaming fight over something one "
"of them managed to buy for a few silver pieces.%^RESET%^");
     break;
   }

}
