//caves1.c - updated 11/28/03 by Circe.
#include <std.h>
#include "../koenig.h"

inherit CAVES;


void create() {
    	::create();
    	set_name("The entrance to a cave");
    	set_short("The entrance to a cave");
    	set_long(
         "A narrow %^BOLD%^%^BLACK%^crack %^RESET%^in the solid rock wall of the mountain gives "+
         "admittance to this small cave.  A bit of %^YELLOW%^light %^RESET%^shines in from the "+
         "cave entrance to the west, while the %^BOLD%^%^BLACK%^shadows %^RESET%^deepen as the cave "+
         "extends eastward.  Mingled in the %^ORANGE%^dust %^RESET%^of the cave floor are tiny "+
         "scraps of rotting %^GREEN%^food %^RESET%^and slivers of %^BOLD%^bone%^RESET%^, evidence that you are "+
         "perhaps not alone."+
         "\n"
    	);
    	set_items(([
         ({"crack","entrance"}) : "The tall, narrow sliver in the western wall "+
            "of the cave allows some light to penetrate the darkness here and seems "+
            "to be the only escape to the outside world.",
         ({"wall","walls","cave"}) : "The solid rock walls of the cavern are deep "+
            "gray and worn smooth.  Faint watermarks reveal that the stream was probably "+
            "the origin of this cave system.  The walls curve smoothly overhead, and "+
            "no stalagmites or stalagtites have formed here.",
         ({"shadow","shadows"}) : "Deep shadows line the cavern walls and cast "+
            "much of the floor into darkness.",
         ({"ground","floor","scraps","food","bone"}) : "A hefty layer of dust and debris "+
            "covers the smooth stone floor of the cavern.  Interspersed with the dust are "+
            "bone slivers and decaying food scraps."
    	] ));
      set_search("default","You find nothing but bones and moldy food.");
    	set_exits(([
       	"west" : VILSTREAM"stream13",
       	"east" : KCAVES"caves2"
    	] ));
}