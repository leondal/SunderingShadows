#include <std.h>
#include "../tormdefs.h"
inherit VAULT;
void create(){
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light",2);
      set_short("Entry way to Torm's public baths");
    set_long(
    "Entry way to Torm's public baths.\n"
        "  You stand at the top of a flight of wide stairs that overlooks Torm's busy marketplace to the east."
      "  Steam rises out from between two large doors that lead into the baths and you catch the scent of bath oils and perfumes."
   "  You can overlook part of the busy marketplace to the east of here."
    );
    set("night long",
        "  You stand at the top of a flight of wide stairs with a view that fades quickly into the fog covering Torm's marketplace to the east."
      "  Two large doors that lead into the public baths stand closed and no hint of life is noticed from behind them.  The baths should be open"+
    " again in the morning, however."
    );
   set_items(([
   "stairs" : "You are standing at the top of a set of wide marble stairs that lead into the elaborate bathhouse of Torm.",
   ({"doors","large doors"}) : "There are two large bronze doors here that are embossed with various patterns of sea shells and such. Steam rises out from between them",
   ]));
    set_smell("default","You can smell the residue of bath oils and perfumes.");
    set_listen("default","The sound of running water is faintly heard.");
    set_items(([
      ]));
  set_exits(([
  "stairs":TCITY+"c54",
  "doors":TCITY+"c113",
  ]));
  set_door("doors",TCITY+"c113","west","Torm masterkey");
   if(query_night()) {
      set_open("doors",0);
      set_locked("doors",1);
   }
   else {
      set_open("doors",1);
      set_locked("doors",0);
   }
}
