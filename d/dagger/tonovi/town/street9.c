//updated by Circe 9/10/04
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_property("light", 3);
    set_property("night light", 3);
    set_short("Ekan Street");
    set_long(
      "%^BOLD%^%^BLACK%^Ekan Street%^RESET%^\n"+
      "You are on the southern end of %^BOLD%^%^BLACK%^Ekan Street"+
      "%^RESET%^.  This end of the street is %^YELLOW%^highly lit "+
      "%^RESET%^and crawling with %^BLUE%^guards%^RESET%^.  To the "+
      "south you can see the small %^BOLD%^%^BLACK%^gate %^RESET%^that "+
      "guards the entrance to the inside of the %^BOLD%^%^BLACK%^walls "+
      "%^RESET%^of the city.  There is a %^BOLD%^shop %^RESET%^on "+
      "each side of the street here, each with an opulent %^ORANGE%^"+
      "sign %^RESET%^displayed over its door.\n"
    );
    set_items( ([
	"lights" : "The lights here are very bright, keeping the whole "+
         "area brightly lit even at night.",
	({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
         "Walls made of black stone mined from veins in the northern "+
         "mountains encircle the city.",
	({"street","ground"}) : "The streets here are made of "+
         "%^BOLD%^%^BLACK%^gray cobblestone%^RESET%^ kept mostly "+
         "clean of refuse, though here and there some recent trash "+
         "has been left by travellers.",
      ({"building","buildings","shops","shop"}) : "The buildings of the city rise "+
         "around you.  There is a mixture of buildings made of "+
         "black, white, and gray stone, as well as the occasional "+
         "wooden building.",
      ({"guard","guards"}) : "Guards in the uniform of the %^BOLD%^"+
         "%^GREEN%^Tonovi Guard %^RESET%^walk up and down this "+
         "section of road, while private guards are stationed at "+
         "the doorways of the buildings.",
      ({"shop","shops","bank","treasury"}) : "Upon closer inspection, "+
         "you can see neither of these is a shop in the normal "+
         "sense of the word.  Both do a brisk business though.",
      ({"sign","signs"}) : "Did you want to look at the east "+
         "sign or the west sign?",
      ({"east sign","treasury sign"}) : ({"The sign over the door on "+
         "the east is made of high-quality %^BOLD%^%^BLACK%^"+
         "shadowood %^RESET%^and bears a message you could read.",
         "%^YELLOW%^Merchant's Portal%^RESET%^","common"}),
      ({"west sign","bank sign"}) : ({"The sign over the door on "+
         "the west is made of high-quality %^BOLD%^%^BLACK%^"+
         "shadowood %^RESET%^and bears a message you could read.",
         "%^YELLOW%^Bank of Tonovi%^RESET%^","common"})
      ]) );
    set_exits( ([
	"north" : RPATH "street10",
        "east" : RPATH "portal",
	"west" : RPATH "bank",
	"south" : RPATH "wall5"
      ]) );
}
