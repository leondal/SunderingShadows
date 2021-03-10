//updated by Circe 12/19/04 with new desc
#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit BAZAAR;

void create(){
    ::create();
    set_property("light",2);
    set_short("Bazaar of Tonovi");
    set_long("%^CYAN%^Bazaar of Tonovi%^RESET%^\n"+
       "This is the southwestern corner of the bazaar of Tonovi, "+
       "bounded on the west and south by the %^BOLD%^%^BLACK%^city walls%^RESET%^."+
       "  To the southwest stands a %^BOLD%^%^BLACK%^reinforced "+
       "gate%^RESET%^ that leads into the walls of the city.  "+
       "The %^CYAN%^bazaar %^RESET%^opens to the north and east, "+
       "with %^ORANGE%^stands %^RESET%^and %^MAGENTA%^merchants "+
       "%^RESET%^advertising their wares.  All manner of unusual "+
       "%^ORANGE%^goods %^RESET%^seem to be sold here, and there is "+
       "a large crowd gathered around what looks to be a %^ORANGE%^"+
       "platform %^RESET%^of sorts to the northeast in the center "+
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
         "the center of the bazaar to the northeast, there is "+
         "what looks to be a large platform.  It is hard to tell "+
         "from here exactly what is going on there, but it has "+
         "drawn the attention and presence of most of the people "+
         "in the bazaar.",
      ({"gate","reinforced gate","city gate"}) : "The city gate "+
         "is made of %^BOLD%^%^BLACK%^shadowood %^RESET%^"+
         "reinforced with %^BOLD%^%^BLACK%^iron bands%^RESET%^.  "+
         "It leads into the walls of the city, where none but the "+
         "guard should travel."
    ]));
    set_exits(([
	"north" : RPATH "bazaar4",
	"east" : RPATH "bazaar8",
	"southwest" : RPATH "wall10"
    ]));
}
