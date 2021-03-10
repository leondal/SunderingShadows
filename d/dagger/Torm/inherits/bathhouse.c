#include <std.h>
#include "../tormdefs.h"
inherit VAULT;

void create()
{
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light",2);
  set_property("indoors",1);
    set_short("Bathhouse in the city of Torm");
  set_long(
    "  You stand in a four foot deep pool that measures almost 30 feet by 30 feet across."
    "  Marble steps go down from the edges into the water at even intervals between which a stone ledge serves as a seat for those who wish to stay longer to relax."
  "  A fountain of a fish coming out of a seashell dominates the center of the pool, with more of the stone ledge around it as well."
  "  Steam fills the air and you feel relaxed with the warm water bubbling at your toes."
  );
  set_items(([
   (({"ledge","stone ledge"})) : "A narrow stone ledge encircles the pool except for for marble stairs that break its continous flow around the pool.  Looks like a comfortable place to sit.",
   (({"statue","fountain","fish fountain"})) : "%^BOLD%^This tall marble fountain is"+
   " of a fish rising out of a stone clam set in the center of the pool."+
   " %^CYAN%^Water%^WHITE%^ spouts out of its mouth, cascading down into the"+
   " center of the pool.",
   (({"pool","bath"})) : "%^BOLD%^%^CYAN%^The pool measures 30 by 30 feet"+
   " with stairs in its northeast corner leading back up to the steps.",
   (({"water","bubbles"})) : "%^BOLD%^%^CYAN%^The warm water effervesces"+
   " from somewhere below the surface of the pool, and its little bubbles"+
   " tingle as it touches your skin.",
   "stairs" : "Marble stairs lead out of the bath to the main level.",
   "marble" : "%^BOLD%^Gorgeous and very expensive looking white marble is"+
   " shot through with %^BLACK%^black%^WHITE%^ and %^YELLOW%^gold%^WHITE%^ flecks.",
   (({"walls","floor","ceiling","roof"})): "Marble facing encases all the"+
   " walls, columns, floor and ceiling of this stone building.",
  ]));
  set_smell("default","You can smell the sweet scents of bath oils and perfumes.");
  set_listen("default","The water bubbles in the pools.");
}

void reset(){
   ::reset();
   if(query_night()) return;
   if(!random(2)) {
     if(!present("bather")){
        new(MON+"bather.c")->move(TO);
     }
   }
}
