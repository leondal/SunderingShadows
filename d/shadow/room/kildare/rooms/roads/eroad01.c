//eroad01.c
#include "../../kildare.h"

inherit EHIGH;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^WHITE%^A Rocky Path
%^RESET%^%^CYAN%^A narrow footpath runs between the two stone buildings to the 
northwest before continuing southeast.  It meanders alongside boulders and 
tall evergreens, choosing the path of least resistance as it makes 
its way.  It does not seem to be wide enough for carts or buggies, 
and is barely flat enough to allow proper footing for a horse.  Very 
little grass softens the ground here, but the trees provide some 
protection from the elements.
CIRCE
   );
   add_item("buildings","The stone buildings to the northwest are "+
      "made of the same gray stone as the mountainside.  There are "+
      "no windows that you can see, but each has a tall chimney "+
      "from which a light puff of smoke flows.");
   set_exits(([
      "northwest" : TROOMS"path8",
      "southeast" : ROADS"eroad02"
      ]));
}
