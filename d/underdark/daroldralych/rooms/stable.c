#include <std.h>
#include "../defs.h"
inherit STABLE;

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("House Archuul's stables");
   set_short("%^BLUE%^House Archuul's stables%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^House Archuul's stables%^RESET%^\n"
"%^BLUE%^Surrounding this small side-cavern are numerous pens, all separated by %^BOLD%^%^BLACK%^heavy st%^RESET%^"
"%^ORANGE%^on%^BOLD%^%^BLACK%^e walls %^RESET%^%^BLUE%^that are supported by the walls of the cavern itself.  Some of the "
"enclosure walls are far too high to see what is kept inside, but you can see enough within other pens to make out a few "
"creatures milling around, %^GREEN%^l%^ORANGE%^iz%^GREEN%^ar%^ORANGE%^d%^GREEN%^s %^BLUE%^and shaggy %^ORANGE%^rothe "
"%^BLUE%^and the occasional more exotic beasts.  The occasional bellow or screech comes from some of the enclosures.  An "
"opening in the eastern wall of the cavern leads out onto the streets of the city itself, and there is a wooden sign "
"secured to the wall there, listing the creatures for sale.%^RESET%^\n");
   set_smell("default","%^ORANGE%^The air here carries the mingled %^GREEN%^re%^BOLD%^e%^RESET%^%^GREEN%^k %^ORANGE%^of "
"animal bodies and waste.");
   set_listen("default","%^RED%^Gro%^ORANGE%^an%^RED%^s%^GREEN%^, bellows and %^ORANGE%^sc%^YELLOW%^r%^RESET%^%^ORANGE%^"
"eec%^RESET%^he%^ORANGE%^s %^GREEN%^come from the enclosures around you.");

   set_items(([
     ({"wall","walls","roof"}):"%^BLUE%^The walls and roof of this small cavern are all made of %^BOLD%^%^BLACK%^dark st"
"%^RESET%^%^ORANGE%^on%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^, obviously carved by a mortal hand, but showing no real signs "
"of elegance in their carving.%^RESET%^",
     ({"pens","enclosures"}):"%^BLUE%^Numerous enclosures with %^BOLD%^%^BLACK%^heavy st%^RESET%^%^ORANGE%^on%^BOLD%^"
"%^BLACK%^e walls %^RESET%^%^BLUE%^keep the animals here separated from one another.%^RESET%^",
   ]));
   set_exits(([
     "east":ROOMS"outer6",
   ]));

   set_animal(({"rothe","packlizard","ravener","steeder","cavvekan"}),({HOR"rothe",HOR"packlizard",HOR"ravener",HOR"spider",HOR"cavvekan"}));
   set_animal_price(({"rothe","packlizard","ravener","steeder","cavvekan"}),({400,1000,7000,9000,2000}));
   set_stalls(12);
   ::fill_stalls();
}

void reset(){
   if(!present("xyros")) new(MON"xyros")->move(TO);
}
