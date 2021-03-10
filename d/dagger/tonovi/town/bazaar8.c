//updated by Circe 12/19/04 with new desc
#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit BAZAAR;

void create(){
    ::create();
    set_property("light",2);
    set_short("Bazaar of Tonovi");
    set_long("%^CYAN%^Bazaar of Tonovi%^RESET%^\n"+
       "This is the southern end of the bazaar of Tonovi, "+
       "bounded on the south by the %^BOLD%^%^BLACK%^city walls%^RESET%^."+
       "  The %^CYAN%^bazaar %^RESET%^opens to the north, "+
       "with %^ORANGE%^stands %^RESET%^and %^MAGENTA%^merchants "+
       "%^RESET%^advertising their wares.  All manner of unusual "+
       "%^ORANGE%^goods %^RESET%^seem to be sold here, and there is "+
       "a large crowd gathered around what looks to be a %^ORANGE%^"+
       "platform %^RESET%^of sorts to the north in the center "+
       "of the %^CYAN%^bazaar%^RESET%^.\n");
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
      ({"platform","large platform","center"}) : "Directly in "+
         "the center of the bazaar to the north, there is "+
         "what looks to be a large platform.  It is hard to tell "+
         "from here exactly what is going on there, but it has "+
         "drawn the attention and presence of most of the people "+
         "in the bazaar."
    ]));
    set_exits(([
	"west" : RPATH "bazaar7",
	"north" : RPATH "bazaar5",
	"east" : RPATH "bazaar9"
    ]));
}