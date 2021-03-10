#include <std.h>
#include "../piratedefs.h"

inherit ROOM;
// object ob;

void create(){ 
   ::create();
   set_property("light",2);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
  
   set_short( "Crossroads" );

   set_long(
            "%^BOLD%^Dock Crossroads%^RESET%^\n"+
            "You have reached the market and town square. "+
            "All around you smugglers and pirates offer up "+
             "thier ill-gotten gains. You clutch your purse. "+
            "North you can see some greenery, south leads to "+
            "the inlet which holds the docks and ships.  "+
            "A house blocks your way west."
"\n"
   );

   set_smell("default","You smell fresh ocean air.");
set_listen("default","You can hear waves crashing on shore.");

/*  removing ooc boards & others that have outlived their usefulness  *Styx*  4/6/03
ob = new("std/bboard");
ob->set_name("board");
ob->set_id( ({ "board", "bulletin board", "pirate's cove board" }) );
ob->set_board_id("pirate_board");
ob->set_short("The Pirate's Cove Board");
ob->set_long("This is a sign mounted on tall wooden poles standing in the "
    "square of the village of Pirate's Cove."
"\n"
);
ob->set_max_posts(20);
ob->set_location(CAVES"cove8");
*/
   set_items(([
     "ocean":"The ocean spreads out before you to the horizon.",
    "village":"You can now have a clear view of the village buildings. 
They seem to have been built out of pieces of old ships.",
    "streets":"The streets are more like paths but they get the job
done.",
    ]));

   set_exits(([
   "north":CAVES"cove9",
   "south":CAVES"cove10",
   "east":CAVES"cove7"
]));

}
