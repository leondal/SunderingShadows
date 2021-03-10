//vil7.c
#include <std.h>
#include "../../kildare.h"

inherit PATHEND;

void create()
{
   ::create();
   set_short("The Tanning Yard");
   set_long(
      "%^RESET%^%^ORANGE%^The Tanning Yard\n"+
      "%^RESET%^%^GREEN%^Scattered throughout this small rocky clearing behind a "+
      "stone building are many different tools of the tanning trade.  Wooden "+
      "racks are spread around with sheep skins stretched across them, drying "+
      "in the sun.  Several skins are piled on a long, thin table along with "+
      "various scrapers, knives, and other strange implements.  Copper buckets "+
      "filled with ash litter the ground beneath the table, and a few have been "+
      "placed by the drying stands as well.  Burlap sacks are placed within a "+
      "small recess dug into the rising mountainside.  One has been split open "+
      "and rock salt has poured onto the ground beside it.  This clearing is a "+
      "narrow semi-circle, with the mountain rising up all around and the southern "+
      "side bounded by a stone wall with a door."
   );
   set_items(([
      (({"clearing","rocky clearing","yard"})) : "The tanning yard is a rocky "+
         "stone clearing much like the footpaths through the town.  It seems "+
         "to have been running for quite some time, yet all the equipment is "+
         "well-kept and some of it seems new.",
      (({"racks","wooden racks","drying racks"})) : "Several wooden contraptions "+
         "stretch out pelts to dry in the sun.  The cold weather here seems to "+
         "lengthen the drying time, but the presence of salt and ash indicate that "+
         "the tanners have learned to augment the process.",
      (({"skins","sheepskins","sheep skins"})) : "Stretched on the wooden racks and "+
         "piled on the narrow table are sheep skins of varying sizes.  Most of them "+
         "have had all the wool removed first, but a few on the table are awaiting "+
         "this process.",
      (({"scrapers","knives","implements"})) : "Long, slender knives are laid neatly "+
         "out on the table alongside broad, flat metal scrapers, shears, and other "+
         "tools.  It seems everything one would need to tan skins of any kind is here.",
      (({"buckets","copper buckets","ash","ashes"})) : "Six copper buckets filled with "+
         "deep gray ash are placed around the tanning yard.  Some of the skins have clearly "+
         "had ash of this sort applied to them to help soften them up after they dried.",
      (({"burlap sacks","sacks","rock salt","salt","recess"})) : "The low recess dug "+
         "into the rising mountainside protects these burlap bags from inclement weather.  "+
         "Salt is often used to aid in drying out skins as well as a means of helping "+
         "keep them soft.",
      (({"wall","stone wall"})) : "The stone wall to the south has a door leading into "+
         "the building."
      ]));

   set_exits(([
      "south" : TROOMS"vil5",
      ]));
   set_door("back door",TROOMS"vil5","south",0);

}
void reset()
{
        ::reset();
        if(!present("joshua")) {
                new(MON"joshua")->move(TO);
        }
        if(!present("tessa")) {
                new(MON"tessa")->move(TO);
        }
}
