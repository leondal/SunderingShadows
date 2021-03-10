#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_terrain(BUILT_CAVE);
   set_travel(DIRT_ROAD);
   set_name("Underground tunnel");
   set_short("Underground tunnel");
   set_long("%^BOLD%^Underground tunnel%^RESET%^\n"
"Further into the tunnel here, it curves to the side, though both northern and eastern directions leading "
"into the %^BLUE%^cavern's shadows%^RESET%^.  The walls are made of %^BLACK%^%^BOLD%^stone and mortar"
"%^RESET%^, and look quite sturdy.  They're a little damp, however, as though %^CYAN%^water%^RESET%^ is "
"leaking from somewhere above, running down the walls.  While difficult to make out the details, you can "
"see what looks to be faint traces of a storage room to the east.  Before you, against the southern wall, is "
"an old countertop, and a %^WHITE%^%^BOLD%^notice%^RESET%^ is tacked to the wall behind it.\n");
   set_smell("default","A faint smell of dampness permeates the air around you.");
   set_listen("default","It's particularly quiet here, except for an occasional drip of water.");

   set_items(([
     ({"cavern","walls","roof","stone"}):"The %^BLACK%^%^BOLD%^stone-and-mortar%^RESET%^ walls look quite "
"sturdy, though they're a little damp, as though %^CYAN%^water%^RESET%^ is leaking from somewhere above.",
	"notice":({"A piece of ragged parchment is tacked here, scrawled with a message you could probably "
"read.","\n\n%^WHITE%^%^BOLD%^To all rogues!\n\nDue to the transient population and the clerical demands on "
"myself, as Guildmaster of the thieves guild, I have decided to just say to hell with the guild fee, and "
"just charge higher prices at the store.  If ya don't like it don't shop here.  By the way if you see that "
"dead beat Alden, kick him in the teeth and kill him.\n\nSigned, Cedwin Hobblefoot.\n%^RESET%^"}),
	"counter":"The counter is made of %^ORANGE%^rough wood%^RESET%^ that looks untended and worn with age."
    ]));

   set_exits(([
     "north":COVE"thief3",
     "east":COVE"thief5"
   ]));
}
