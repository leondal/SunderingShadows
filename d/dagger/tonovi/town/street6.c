//updated by Circe 9/10/04
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_property("light", 2);
    set_short("Main Street");
    set_long(
      "%^BOLD%^%^GREEN%^Main Street%^RESET%^\n"+
      "You are on the %^BOLD%^%^BLACK%^main street %^RESET%^through "+
      "%^BOLD%^%^GREEN%^Tonovi%^RESET%^.  It runs east and west "+
      "through the heart of the city.  In the middle of the city "+
      "it crosses %^BOLD%^%^BLACK%^Ekan Street%^RESET%^, which "+
      "travels north and south.\n\n"+
      "Here along the street you can see %^BOLD%^shops %^RESET%^"+
      "to the north and south, and the street continues to the "+
      "west and east.  A %^ORANGE%^sign %^RESET%^hangs over each "+
      "of the doors to the north and south.\n"
    );
    set_items( ([
      ({"sign","signs"}) : "Two buildings have a door opening into "+
         "the street here, and each features a sign you could "+
         "read.",
      ({"north sign","healer sign"}) : ({"The sign on the shop to "+
         "the north is made of polished %^BOLD%^%^BLACK%^shadow"+
         "wood %^RESET%^and painted in %^YELLOW%^gold letters "+
         "%^RESET%^with a message you could read.",
         "%^YELLOW%^Tonovi Apothecary%^RESET%^","common"}),
      ({"south sign","armorer sign"}) : ({"The sign over the door "+
         "to the south has been pounded out of steel rather than "+
         "carved of wood.  A message has been etched in the middle "+
         "and darkened for ease of reading.",
         "%^BOLD%^Tonovi Armor Shop%^RESET%^","common"}),
	({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
         "Walls made of black stone mined from veins in the northern "+
         "mountains encircle the city.",
	({"street","ground"}) : "The streets here are made of "+
         "%^BOLD%^%^BLACK%^gray cobblestone%^RESET%^ kept mostly "+
         "clean of refuse, though here and there some recent trash "+
         "has been left by travellers.",
      ({"building","buildings"}) : "The buildings of the city rise "+
         "around you.  There is a mixture of buildings made of "+
         "black, white, and gray stone, as well as the occasional "+
         "wooden building.",
      ({"shops","shop"}) : "There are two shops here.  From the white "+
         "stone shop to the north, you smell many pungent aromas, "+
         "while the building to the south is made of expensive "+
         "mortared stone."
      ]) );
    set_exits( ([
	"east" : RPATH "street5",
	"west" : RPATH "street7",
	"north" : RPATH "healer",
	"south" : RPATH "armor",
      ]) );
}