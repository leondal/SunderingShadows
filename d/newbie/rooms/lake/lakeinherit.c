#include <std.h>
#include "../../newbie.h"
inherit WATER;

// Aquatic Quest - Offestry Valley - Created in March 2009 by Ari
// For inclusion into the Offestry Valley Upgrade by Nienne

void pick_mon();

void create(){
  ::create();
  set_property("light",1);
  set_terrain(SHALLOW_WATER);
  set_travel(FRESH_BLAZE);
  pick_mon();
  set_repop(10);

  set_name("Cor'Alu Lake");
  set_short("%^BOLD%^%^CYAN%^Cor'Alu Lake%^RESET%^");
  set_long("%^BOLD%^%^BLUE%^You find yourself swimming below the "+
"calm waters of %^RESET%^%^CYAN%^Cor'Alu Lake%^BOLD%^%^BLUE%^.  "+
"The cold liquid swirls all around you, reflecting the surface "+
"light and %^CYAN%^i%^RESET%^%^CYAN%^l%^BLUE%^l%^BOLD%^u%^RESET%^"+
"%^CYAN%^m%^BOLD%^i%^BLUE%^n%^RESET%^%^CYAN%^a%^BLUE%^t%^BOLD%^i"+
"%^RESET%^%^BLUE%^n%^CYAN%^g %^BOLD%^%^BLUE%^a bit of the area "+
"nearby.  A few little %^RESET%^fish %^BOLD%^%^BLUE%^dart away at "+
"your movements, and further below you can see %^RESET%^%^BLUE%^"+
"larger fish %^BOLD%^waiting for a baited line to be tossed their "+
"way.%^RESET%^");

  set_smell("default","\nThe water tastes crisp with a little "+
"earthy undertone.");
  set_listen("default","You hear water moving about you as you "+
"swim along.");

  set_items(([
    ({"fish","little fish"}):"%^RESET%^You see there are a number "+
"of small silver, gray and blue-tinged fish that dart about the "+
"rocky edges of the lake, seeking shelter in the nooks and crannies "+
"found there.  A few swim about in the open water, snatching up "+
"bugs that land on the surface, but these fish quickly swim away "+
"soon as you draw near.",
    ({"large fish"}):"%^BOLD%^%^BLUE%^Looking into the deep water "+
"you can see several larger fish swimming about.  Trout, bass, "+
"an occasional salmon, and a few others you're not sure about. "+
"Like their smaller cousins, as soon as you draw close they "+
"swim away quickly.%^RESET%^",
    ({"water","light"}):"%^CYAN%^This close to the surface, the "+
"light filters down through the cool waters of the Cor'Alu, "+
"illuminating a bit of the surroundings.  Deeper the water grows "+
"more murky and difficult to see.",
  ]));
}

void pick_mon(){
	int monsters;
	monsters = has_mobs();
	if(!monsters){
		if(mons){ mons = ([]); }
				set_monsters(({"/d/newbie/rooms/lake/frog"}),({random(2)+1}));
				monster_party(15);
	}
	return 1;
}
