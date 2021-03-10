//stream12.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_long(
		"%^BOLD%^%^BLUE%^The stream is flowing rapidly northwestward, coming down from the foothills "+
            "of the %^RESET%^%^RED%^mountains %^BOLD%^%^BLUE%^to the southeast.  "+
            "It swirls past %^RESET%^%^ORANGE%^small rocks %^BOLD%^%^BLUE%^and %^GREEN%^trees "+
		"%^BLUE%^jutting out into the river's path.  The water is fairly shallow, rising "+
            "to about the knees of a typical human.  However, the current is moving swiftly, "+
            "and the %^RESET%^%^ORANGE%^sandy bottom %^BOLD%^%^BLUE%^seems to draw your "+
            "feet under, making it a struggle to "+
            "stand up straight.  The river would be a very pleasant place, were it not for "+
            "the cold water coming down from the mountains chilling you to the bone.  "+
            "To the east you can see the riverbank rising out of the water."+
            "\n"
      );
    	set_exits(([
       	"west" : VILSTREAM"stream11",
       	"east" : VILSTREAM"stream13"
    	] ));
}
