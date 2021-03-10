//updated by Circe 12/19/04 with new desc
#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit BAZAAR;

void create(){
    ::create();
    set_property("light",2);
    set_short("Bazaar of Tonovi");
    set_long("%^CYAN%^Bazaar of Tonovi%^RESET%^\n"+
       "This is the center of the bazaar of Tonovi, "+
       "dominated by a large %^ORANGE%^wooden platform%^RESET%^.  "+
       "The %^CYAN%^bazaar %^RESET%^opens all around, "+
       "with %^ORANGE%^stands %^RESET%^and %^MAGENTA%^merchants "+
       "%^RESET%^advertising their wares.  All manner of unusual "+
       "%^ORANGE%^goods %^RESET%^seem to be sold here.  Right here "+
       "in the center there is a large crowd gathered, making it "+
       "difficult to see and hear.  Standing atop the %^ORANGE%^"+
       "platform %^RESET%^is an assortment of elves accompanied "+
       "by other races.  A small man with a tall %^BOLD%^%^BLACK%^"+
       "black hat %^RESET%^is calling out prices to the shouting "+
       "crowd, making you realize...those elves are "+
       "being sold as slaves!\n");
    set_smell("default", "You smell several strange smells, "+
       "especially strong is the sweet smell of fruits.");
    set_listen("default","You can hear the merchants peddling "+
       "their wares from all around.");
    set_items( ([
	({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
         "Walls made of black stone mined from veins in the northern "+
         "mountains encircle the city.",
      ({"wares","goods","stands","merchants"}) : "Merchants in "+
         "clothing from all parts of the realms stand before their "+
         "stalls, proffering their wares.  The goods range from "+
         "exotic fruits and vegetables to perfumes, silks, and "+
         "unusual pets.",
      ({"platform","large platform","center"}) : "A massive wooden "+
         "platform dominates the center of the bazaar, topped by "+
         "elves chained with a few members of other races.  The "+
         "slaves look frightened and confused, being taken from their "+
         "families and sold to the eager buyers surrounding them."
    ]));
    set_exits(([
	"north" : RPATH "bazaar2",
	"east" : RPATH "bazaar6",
	"south" : RPATH "bazaar8",
	"west" : RPATH "bazaar4"
    ]));
}
