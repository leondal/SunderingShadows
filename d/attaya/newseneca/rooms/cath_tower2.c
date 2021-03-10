//cath_tower2 - bell tower for new Seneca
//~Circe~ 1/14/08
#include <std.h>
#include "../seneca.h"

inherit STORAGE"cath_tower";

void create(){
   ::create();
   set_long(::query_long()+"\nThis is the second floor of the "+
      "bell tower.  Looking out the western window, you see "+
      "the %^ORANGE%^trunk %^RESET%^of the Attaya oak that "+
      "spreads its canopy over the cemetery rising above the "+
      "flat rooftop of the vestry.\n");
   set_exits(([
      "down" : ROOMS"cath_tower1",
      "up" : ROOMS"cath_tower3"
   ]));
   add_item("trunk","The gnarled trunk of the ancient Attaya "+
      "oak fills the view from the western window over the "+
      "rooftop of the vestry.");
   add_item("tree","The gnarled trunk of the ancient Attaya "+
      "oak fills the view from the western window over the "+
      "rooftop of the vestry.");
   add_item("oak","The gnarled trunk of the ancient Attaya "+
      "oak fills the view from the western window over the "+
      "rooftop of the vestry.");
   add_item("Attaya oak","The gnarled trunk of the ancient Attaya "+
      "oak fills the view from the western window over the "+
      "rooftop of the vestry.");
   add_item("rooftop","The rooftop of the vestry is flat and "+
      "fashioned from the same sandstone as the rest of the "+
      "cathedral.");
}