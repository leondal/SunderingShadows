#include <std.h>
#include "../defs.h"
inherit ISLAND;

void create()
{
  	::create();
	set_short("%^BOLD%^Under the Palm Trees - Ovadexel");
   	set_long("%^CYAN%^You stand upon a sandy beach of a small island.  "+
		"The island doesn't appear to be larger than a few hundred "+
		"yards across, and looks relatively bare.  Between the %^GREEN%^palms "+
		"trees%^CYAN%^ stands what once may have been a hut, but now is nothing  "+
		"more than ruins.  A few palm fronds still rest upon its roof "+
		"and tied to the wall supports, but the winds have ripped most "+
		"of them down.  A large doorway stands open, not that it is needed, "+
		"there are several sections of the wall you could simply walk "+
		"right through.  "
		"To the west, there looks to be a small, "+
		"sandy section of the beach.\n");
  	set("night long","%^BLUE%^The moonlight seems to cause the entire island "+
		"and the waters around it to glow in a %^BOLD%^%^WHITE%^"+
                "pale light%^RESET%^%^BLUE%^.  Between the palm "+
		"trees stands what once may have been a hut, but now is nothing  "+
		"more than ruins.  A few %^GREEN%^palm fronds%^BLUE%^ still rest "+
		"upon its roof "+
		"and tied to the wall supports, but the winds have ripped most "+
		"of them down.  A large doorway stands open, not that it is needed, "+
		"there are several sections of the wall you could simply walk "+
		"right through.  A small, "+
		"sandy section of the beach glows in the %^BOLD%^%^WHITE%^"+
		"moonlight%^RESET%^%^BLUE%^, just west of where you stand now.  "+
		"Rocks and clumps of oyster shells line the rest of the shore as "+
		"far as you can see.\n");      
 	set_items(([
    	"hut" : "%^ORANGE%^A small hut seems to stand in the center of this island.",
    	({"tree","trees","palm tree","palm trees"}) : "%^GREEN%^Tall palm trees are "+
		"scattered about this small island.  Coconuts are bunched up "+
		"at the top of a few of the taller ones.",
       ]) );

 	set_exits(([
    		"south" : ROOMS+"island4",
    		"west" : ROOMS+"island1",
    		"east" : ROOMS+"island3",
    		"north" : ROOMS+"island2",
    		"enter" : ROOMS+"hut"
    	]) );
}
