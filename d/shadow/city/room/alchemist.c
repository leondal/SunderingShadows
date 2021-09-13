//Octothorpe (6/5/16)
//Shadow, Alchemist Shop

#include <std.h>
#include "../defs.h"

inherit ROOM;

void create()
{
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("no kill",1);
   set_short("The Shadow Scroll Shop");
   set_long("%^RESET%^%^ORANGE%^This is a %^RESET%^tidy%^ORANGE%^ little "+
   "shop where everything is neatly kept in its place. The shelves are lined "+
   "with canisters of various sizes, shapes and colors, "+ 
   "all holding the highest quality of components available "+
   "to the local mage population. A section of shelves feature various writing "+
   "materials such as parchment and quills, while another features a grand "+
   "assortment of scrolls and wands. A small shrine to %^MAGENTA%^Kismet%^ORANGE%^ "+
   "set into a wall is the only ornamentation to be found, and the counter which "+
   "Meguile stands behind is impeccably clean.\n\n"+
   "%^CYAN%^Type %^BOLD%^<help shop>%^RESET%^%^CYAN%^ for information on how to use the shop.\n");
   set_smell("default","You smell the odor of harsh chemicals");
   set_listen("default","You hear the sounds of bubbling liquids.");
   set_items(([ "tube": "A tube of colorless bubbling liquid",
      "canisters,shelves,components": "Many exotic scents and fascinating shapes "+ 
	  "are precisely measured and stored away. The shelves are neat, "+ 
	  "with nary a speck of dust to be found.",
      "shrine": "%^RESET%^The details on this small statue are stunning. The Lady of Mysteries "+ 
	  "stands with her arms out to the side, a %^MAGENTA%^purple mist%^RESET%^ rising from between her fingers."
	  ]));
   set_exits(([
      "southwest" : ROOMS"crossways4"
   ]));
}

void reset()
{
   ::reset();
   if(!present("meguile"))
      find_object_or_load("/d/shadow/mon/alchemist")->move(TO);
}