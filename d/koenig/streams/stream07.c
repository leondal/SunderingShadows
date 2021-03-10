//stream07.c
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
            "the cold water coming down from the mountains chilling you to the bone."+
            "Just to the west, the river begins to tumble wildly over a long series "+
            "of rocky rapids, blocking your passage that way.  A bridge has been "+
            "built over the rapids, but there doesn't seem to be a good way "+
            "to reach it from here."+
            "\n"
      );
      add_item("rapids","The rapids cause the river to churn and burble below.  Going that "+
            "way would surely be foolish.");
    	set_exits(([
       	"east" : VILSTREAM"stream08"
    	] ));
}
