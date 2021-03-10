//updated by Circe 12/19/04 with new desc
#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit BAZAAR;

void create(){
    ::create();
    set_property("light",2);
    set_short("Bazaar of Tonovi");
    set_long("%^CYAN%^Bazaar of Tonovi%^RESET%^\n"+
       "This is the northeastern corner of the bazaar of Tonovi, "+
       "opening onto %^BOLD%^%^GREEN%^Main Street %^RESET%^to the east.  "+
       "To the north a narrow %^ORANGE%^pathway %^RESET%^leads "+
       "to a small %^BOLD%^stone building%^RESET%^.  "+
       "The %^CYAN%^bazaar %^RESET%^opens to the south and west, "+
       "with %^ORANGE%^stands %^RESET%^and %^MAGENTA%^merchants "+
       "%^RESET%^advertising their wares.  All manner of unusual "+
       "%^ORANGE%^goods %^RESET%^seem to be sold here, and there is "+
       "a large crowd gathered around what looks to be a %^ORANGE%^"+
       "platform %^RESET%^of sorts to the southwest in the center "+
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
         "the center of the bazaar to the southwest, there is "+
         "what looks to be a large platform.  It is hard to tell "+
         "from here exactly what is going on there, but it has "+
         "drawn the attention and presence of most of the people "+
         "in the bazaar.",
      ({"path","building","shop"}) : "To the north, a narrow "+
         "pathway leads from the general bustle of the bazaar "+
         "towards a small shop."
    ]));
    set_exits(([
	"east" : RPATH "street8",
	"west" : RPATH "bazaar2",
	"south" : RPATH "bazaar6",
 	"north" : "/d/player_houses/lusell/rooms/shop_entrance"
    ]));
}
