//viento_lane.c ~Circe~ 11/9/07
//Main thoroughfare through Seneca - runs E-W
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_climate("tropical");
   set_property("light", 2);
   set_name("Viento Lane");
   set_short("Viento Lane");
   set_long("%^BOLD%^%^CYAN%^Viento Lane, Seneca%^RESET%^\n"+
      "This broad thoroughfare runs east and west through the city "+
      "and is divided into two lanes "+
      "with a %^GREEN%^grassy median %^RESET%^in between.  "+
      "Each lane is wide enough for two carts and meticulously "+
      "paved with %^ORANGE%^co%^RED%^b%^ORANGE%^"+
      "ble%^RESET%^s%^ORANGE%^to%^RED%^n%^ORANGE%^e%^RESET%^s "+
      "in a zig-zagging pattern.  Standing in the %^GREEN%^"+
      "median %^RESET%^at intervals are ornate %^BOLD%^%^BLACK%^"+
      "street lamps%^RESET%^ to light the way at night.  Beautiful "+
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
         "side-by-side on each side of the grassy median.",
      ({"median","grassy median"}) : "%^GREEN%^The median is "+
         "wide enough for the street lamps to fit easily.  They "+
         "are mostly filled with coarse grass sprouting through "+
         "the %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
         "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand%^GREEN%^, but "+
         "occasionally, a low-growing %^BOLD%^juniper bush "+
         "%^RESET%^%^GREEN%^peeks up from the ground.%^RESET%^",
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
         "the sand are blades of coarse grass."
   ]));
}

void reset(){
   ::reset();
   if(!present("street lamp")) new(OBJ"street_lamp")->move(TO);
}
