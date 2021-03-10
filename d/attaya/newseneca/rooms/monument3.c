//monument3.c ~Circe~ 12/10/07
#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("A Grand Monument, Seneca");
   set_short("A Grand Monument, Seneca");
   set_property("light",3);
   set_long("%^BOLD%^%^WHITE%^A Grand Monument, Seneca%^RESET%^\n"+
      "%^GREEN%^This square garden is carpeted with lush, soft "+
      "%^BOLD%^grass%^RESET%^%^GREEN%^ that surrounds the magnificent "+
      "centerpiece, a %^BOLD%^%^WHITE%^marble statue%^RESET%^%^GREEN%^ "+
      "of a kilted warrior.  A foot-high border of %^BOLD%^%^BLACK%^"+
      "slate %^RESET%^%^GREEN%^rings the statue, containing the "+
      "pristine %^CYAN%^reflecting pool %^GREEN%^therein.  The serenity "+
      "of the pool stands at odds with the %^BOLD%^%^WHITE%^power "+
      "%^RESET%^%^GREEN%^and %^BOLD%^%^CYAN%^motion %^RESET%^%^GREEN%^"+
      "suggested by the statue, a juxtaposition explored in the "+
      "rest of the garden.  Carved %^BOLD%^%^BLACK%^stone benches "+
      "%^RESET%^%^GREEN%^have been placed around the garden, giving visitors "+
      "places to sit, while monstrous %^BOLD%^Attaya flytraps %^RESET%^"+
      "%^GREEN%^stand nearby with %^RED%^gaping maws%^GREEN%^.  "+
      "They possess an alien beauty countered by the vibrant "+
      "six-inch blossoms of the %^RED%^h%^BOLD%^i"+
      "%^YELLOW%^b%^RESET%^%^ORANGE%^i%^BOLD%^%^MAGENTA%^s%^RESET%^"+
      "%^MAGENTA%^c%^BOLD%^%^RED%^u%^YELLOW%^s %^RESET%^%^GREEN%^"+
      "springing up all around.  Bounding the eastern and "+
      "southern sides of this small park is a tall %^BOLD%^%^WHITE%^"+
      "fence %^RESET%^%^GREEN%^lined with %^BOLD%^hedges%^RESET%^"+
      "%^GREEN%^.  In the other directions, you see the bustling city "+
      "of %^BOLD%^%^WHITE%^Seneca%^RESET%^%^GREEN%^.\n");
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
         "ble%^RESET%^s%^ORANGE%^to%^RED%^n%^ORANGE%^e streets%^RESET%^ "+
         "to the north and west and the town square to the northwest "+
         "are created from stones in shades of "+
         "%^ORANGE%^brown%^RESET%^, %^RED%^red%^RESET%^, and "+
         "white arranged in zig-zagging patterns.",
      "grass" : "%^BOLD%^%^GREEN%^The grass here is soft and well-"+
         "groomed, quite unlike most of the beach grass growing "+
         "thoughout Seneca.  It is kept relatively short, and it "+
         "would likely be a great place for a picnic.%^RESET%^",
      ({"fence","hedge","hedges"}) : "Blending into the background "+
         "is the tall fence to the south and east.  The fence is "+
         "%^BOLD%^white%^RESET%^ and made of planks placed side-by-"+
         "side for privacy.  Growing in front of the fence are tall "+
         "%^GREEN%^hedges %^RESET%^that further add to the tranquil "+
         "atmosphere here, despite being so close to the bustling "+
         "center of Seneca.",
      ({"border","slate","slate border"}) : "%^BOLD%^%^BLACK%^Crafted "+
         "from pieces of dark ebony slate, the border is left somewhat "+
         "rough.  It houses the reflecting pool and adds a certain "+
         "natural aspect to the garden.%^RESET%^",
      ({"pool","reflecting pool"}) : "%^RESET%^%^CYAN%^The %^BOLD%^"+
         "reflecting pool %^RESET%^%^CYAN%^is square in shape and "+
         "bordered neatly with %^BOLD%^%^BLACK%^slate%^RESET%^%^CYAN%^.  "+
         "It has a perfect calmness that seems unruffled by the wind, "+
         "and it reflects the statue clearly, creating the illusion "+
         "that more than one warrior stands ready to fight.%^RESET%^",
      ({"bench","stone bench","benches","stone benches"}) : "%^BOLD%^"+
         "%^BLACK%^Several stone benches have been placed around the "+
         "garden, the tall flowers between them creating the illusion "+
         "of separate alcoves.  Each bench is made from a slate "+
         "top supported by columns of slate pieces arranged like bricks.%^RESET%^",
      ({"flytraps","Attaya flytraps","flytrap"}) : "%^RESET%^%^GREEN%^"+
         "Most unusual flowers, each of the Attaya flytraps looks much "+
         "like a tall stalk supporting several clam-shaped 'blossoms'.  "+
         "Each blossom is lined with long, thin filaments that have "+
         "the appearance of needle-like teeth.  The inner portion of "+
         "each blossom is colored %^BOLD%^%^RED%^red%^RESET%^%^GREEN%^, "+
         "making the flowers look like nothing so much as gaping maws.%^RESET%^",
      ({"hibiscus","blossom","blossoms"}) : "%^RESET%^%^GREEN%^"+
         "The leafy hibiscus plants each sprout six-inch blossoms "+
         "of five rounded petals.  Huge and beautiful, the "+
         "blossoms range in a variety of colors from the lightest "+
         "%^BOLD%^%^MAGENTA%^pinks %^RESET%^%^GREEN%^to the darkest "+
         "%^RED%^maroons%^GREEN%^.%^RESET%^"
   ]));
   set_exits(([
      "west" : ROOMS"skyline44",
      "north" : ROOMS"viento54",
      "northwest" : ROOMS"square"
   ]));
}

void reset(){
   ::reset();
   if(!present("street lamp")) new(OBJ"street_lamp")->move(TO);
   if(!present("kalimex statue")) new(OBJ"kalimex_statue")->move(TO);
}