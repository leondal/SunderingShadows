//cath_study.c 
//for new Seneca ~Circe~ 06/01/08
#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Study of the Cathedral, Seneca");
   set_short("Study of the Cathedral, Seneca");
   set_long("%^BOLD%^Study of the Cathedral, Seneca%^RESET%^\n"+
      "A hush reigns over this room, which has clearly been "+
      "reserved for study.  The room is lit by three large %^BOLD%^"+
      "%^BLACK%^iron chandeliers %^RESET%^simple in design that "+
      "hold rings of %^BOLD%^beeswax candles %^RESET%^to provide "+
      "soft %^YELLOW%^illumination %^RESET%^to those at work here.  "+
      "Narrow %^ORANGE%^desks %^RESET%^with matching %^ORANGE%^"+
      "chairs %^RESET%^are arranged in such a way as to promote "+
      "independent study.  Several %^BOLD%^%^BLACK%^iron reading "+
      "stands %^RESET%^are spread around, offering a place for the "+
      "studious monk to keep books open while he writes or reads.  "+
      "A quiet, enchanting %^CYAN%^music %^RESET%^emanates from "+
      "somewhere, invigorating the mind and enhancing "+
      "concentration, though its source is impossible to locate.\n");
   set_exits(([
      "east" : ROOMS"cath_basement"
   ]));
   set_smell("default","The light fragrance of beeswax fills the air.");
   set_listen("default","A soft, enchanting music spreads "+
      "throughout the room.");
   set_items(([
      ({"wall","walls"}) : "%^BOLD%^%^WHITE%^The stone walls are "+
         "smooth and whitewashed for a pristine appearance.%^RESET%^",
      "floor" : "The smooth stone floor was hewn at one point but "+
         "has also been worn by countless feet over the years, "+
         "making it seem almost soft.",
      ({"chandelier","chandeliers","iron chandeliers","candles","beeswax candles"}) :
         "Each of the %^BOLD%^%^BLACK%^chandeliers %^RESET%^is made "+
         "of a ring of iron that supports a circle of a few dozen "+
         "%^BOLD%^beeswax candles %^RESET%^that seem to have been "+
         "enchanted to last longer.  They provide perfect "+
         "illumination - just bright enough to allow study while "+
         "being soft enough to avoid becoming a distraction.  The "+
         "chandeliers hang from the ceiling by means of thick iron "+
         "chains.",
      ({"desks","desk","chair","chairs"}) : "Each desk is a very "+
         "simple structure, providing just enough room for one "+
         "person to spread a book or two with parchment, quill, "+
         "and ink for taking notes.  None of the chairs are "+
         "padded, likely to help the monks keep awake while at "+
         "their important studies.",
      ({"stands","reading stands","iron reading stands","stand"}) :
         "Each of the reading stands is made from %^BOLD%^%^BLACK%^"+
         "wrought iron %^RESET%^and features a scrollwork back "+
         "with an adjustable bar that can be placed at different "+
         "heights to keep the chosen book open."
   ]));
}
