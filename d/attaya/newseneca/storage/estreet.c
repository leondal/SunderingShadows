//estreet ~Circe~ 11/23/07
//Eastern thoroughfare around Seneca, runs N-S
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_climate("tropical");
   set_property("light", 2);
   set_name("Lila Way");
   set_short("Lila Way");
   set_long("%^RESET%^%^MAGENTA%^Lila Way, Seneca%^RESET%^\n"+
      "This broad thoroughfare runs north and south along the eastern "+
      "edge of the city.  It is a single line wide enough for two "+
      "carts and is meticulously paved with %^ORANGE%^co%^RED%^b%^ORANGE%^"+
      "ble%^RESET%^s%^ORANGE%^to%^RED%^n%^ORANGE%^e%^RESET%^s "+
      "in a zig-zagging pattern.  Lining the western side of the "+
      "street at intervals are ornate %^BOLD%^%^BLACK%^"+
      "street lamps%^RESET%^ to light the way at night, while the "+
      "eastern edge of the street is bounded by the rough %^BOLD%^co"+
      "%^MAGENTA%^q%^WHITE%^ui%^BLACK%^n%^WHITE%^a walls %^RESET%^"+
      "that encircle the town.  Beautiful "+
      "%^BOLD%^%^RED%^ivy geraniums %^RESET%^hang in %^BOLD%^"+
      "%^BLACK%^wrought-iron baskets %^RESET%^from the lamps, adding "+
      "a brilliant flash of color to the air.  %^ORANGE%^"+
      "Shop fronts %^RESET%^and %^CYAN%^houses %^RESET%^crowd the "+
      "lanes, each with a modest strip of %^GREEN%^grass %^RESET%^"+
      "poking up through the pale %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
      "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand that covers much of "+
      "the land here in Seneca.  The streets seem to bustle with "+
      "activity at all times, though people are much more careful "+
      "at night and often peer towards the town %^BOLD%^walls%^RESET%^.\n\n" );
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"street","boulevard","cobblestone","cobblestones","thoroughfare"}) : 
         "The %^ORANGE%^co%^RED%^b%^ORANGE%^"+
         "ble%^RESET%^s%^ORANGE%^to%^RED%^n%^ORANGE%^e street%^RESET%^ "+
         "is created from stones in shades of "+
         "%^ORANGE%^brown%^RESET%^, %^RED%^red%^RESET%^, and "+
         "white, which are arranged to form a pattern of "+
         "zig-zagging lines.  The boulevard is well-crafted and was "+
         "carefully planned, allowing plenty of space for two wagons "+
         "side-by-side for the entire length of the street.",
      ({"geraniums","ivy geraniums","geranium","flowers","baskets"}) : "Hanging "+
         "from the street lamps are clever %^BOLD%^%^BLACK%^wrought "+
         "iron baskets %^RESET%^filled with %^BOLD%^coir fibers%^RESET%^.  "+
         "Within each basket grows a beautiful %^BOLD%^%^RED%^ivy "+
         "geranium %^RESET%^with bright %^BOLD%^%^RED%^red petals "+
         "%^RESET%^and lush %^GREEN%^green foliage%^RESET%^.",
      ({"shops","shop fronts","houses"}) : "Much of the street "+
         "is lined with shops, with small single-family houses "+
         "spread throughout.  Each shop features a small yard with "+
         "a narrow strip of grass.  Signs hang above most shops, "+
         "identifying the trade of the owner.",
      ({"sand","golden sand","grass"}) : "Spread everywhere is "+
         "the soft golden sand that seems to threaten to bury "+
         "Seneca.  In most places, it is a light coating, but "+
         "in others, it seems to have piled up.  Poking up through "+
         "the sand are blades of coarse grass.",
      ({"coquina","coquina walls"}) : "%^BOLD%^An odd sedimentary rock, co%^MAGENTA%^q"+
         "%^WHITE%^ui%^BLACK%^n%^WHITE%^a is formed from layer upon "+
         "layer of %^RESET%^seashells %^BOLD%^and %^MAGENTA%^coral"+
         "%^WHITE%^.  A relative of limestone, it was chosen for the "+
         "town walls for its abundance, thanks to the %^MAGENTA%^coral "+
         "reef %^WHITE%^nearby, as well as for its unique physical "+
         "properties.  It is actually soft compared to other stones, so "+
         "it will give and not break when struck - allowing damaged "+
         "sections to simply be cut away and replaced with a new block of "+
         "co%^MAGENTA%^q%^WHITE%^ui%^BLACK%^n%^WHITE%^a.%^RESET%^",
      ({"wall","walls"}) : "The %^BOLD%^co%^MAGENTA%^q%^WHITE%^ui"+
         "%^BLACK%^n%^WHITE%^a walls %^RESET%^of Seneca rise well over "+
         "twenty feet high and are eight feet wide.  Bastions are spread "+
         "along the wall at every one hundred or so feet.  These towers "+
         "are about ten feet taller than the rest of the wall and are "+
         "manned as look out points.  The top of the wall is crenellated, "+
         "allowing space for both archers to attack and defenders to deliver "+
         "nasty surprised to invaders.  The walls serve as a chilling reminder "+
         "that though the town of Seneca is prosperous, it is constantly "+
         "under threat from Intruder."
   ]));
}

void reset(){
   ::reset();
   if(!present("street lamp")) new(OBJ"street_lamp")->move(TO);
}
