#include <std.h>
#include "../defs.h"
inherit HEALER;

void create() {
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
   set_name("A dark cavern");
   set_short("A dark cavern");
   set_long("%^BOLD%^A dark cavern%^RESET%^\n"
"A little trail comes off from the main path to lead here, amidst numerous piles of %^ORANGE%^trash%^RESET%^ "
"and %^BLUE%^rubble%^RESET%^ beside the stone wall of the cavern.  The area is entirely permeated by a "
"strong odor that burns unpleasantly at your nostrils.  Amidst the mess are countless grubby bottles and "
"jars, none actually labeled, so there could be almost anything inside them.  On the side of a large wooden "
"crate has been tacked a dirty sign, listing many potions and salves for sale in %^BLACK%^%^BOLD%^scrawled "
"runes%^RESET%^.");
   set_smell("default","The strong odor of vinegar and other herbs burns at your nostrils.");
   set_listen("default","The dulled noise of the street outside still reach your ears.");

   set_items(([
     ({"cave","cavern","walls","ground","roof","ceiling"}):"The cavern is formed of dull stone, still jagged "
"in many places and probably not shaped by mortal hands.  A pathway works its way around the cavern, nothing "
"more than a trail that has been cleared through the piles of trash and miscellaneous crap filling the rest "
"of the cavern.",
     ({"goblins","kobolds","hobgoblins","bugbears","creatures","beasts"}):"All around you is a crowd of "
"creatures, constantly coming and going, pushing and shoving past one another.  With them comes a terrible "
"odor, and a constant racket of noise filling the cavern.",
     ({"bottles","jars"}):"Amidst the trash surrounding the path are countless bottles and jars, coated in "
"grime.  They carry no labels, so there could be almost anything inside them."
   ]));
   set_exits(([
     "east":ROOMS"cavern3"
   ]));
   set_name("taalaar");
}

void reset(){
   ::reset();
   if(!present("taalaar"))
     find_object_or_load(MON"taalaar")->move(TO);
   switch(random(10)) {
     case 0:
     tell_room(TO,"%^ORANGE%^A small, grubby goblin passes you at a run, taking a swipe at your purse as he "
"goes.  He disappears into the crowd before you can even react.%^RESET%^");
     break;
     case 1:
     tell_room(TO,"%^RED%^Taalaar grabs a jar in each hand, shaking them experimentally as if even he has no "
"idea what's in them.%^RESET%^");
     break;
     case 2..3:
     tell_room(TO,"%^BLACK%^%^BOLD%^A horrid smell emanates from a pile of trash beside the path.  It almost "
"smells like something died in there.  Ugh.%^RESET%^");
     break;
     case 4..5:
     tell_room(TO,"%^CYAN%^A fight breaks out between several goblins, over something they found in a pile of trash nearby.%^RESET%^");
     break;
     case 6..7:
     tell_room(TO,"%^BLUE%^Something wet and slimy drips down on you from the roof above.%^RESET%^");
     break;
     case 8:
     tell_room(TO,"%^YELLOW%^A dying screech of some small creature echoes through the cavern from the other "
"end.%^RESET%^");
     break;
     case 9:
     tell_room(TO,"%^GREEN%^Taalaar jams some sort of herb into a grimy bottle, crushing it into mush and "
"stuffing a lid on it.%^RESET%^");
     break;
   }
}
