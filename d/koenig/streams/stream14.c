//stream14.c
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
            "To the northwest, the river's bottom rises, creating a narrow ford.  The sandy bank "+
            "to the southeast looks to lead onto a dry path."+
            "\n"
      );
      add_item("ford","The sandy shore of the ford rises to the northwest.  Barely six "+
         "inches of water covers the ground there.");
      add_item("path","The sandy bank leads right up to the foot of a path.  It was "+
         "most likely used by villagers at one time, although you are not sure where "+
         "it may lead.");
    	set_exits(([
       	"northwest" : VILSTREAM"ford",
       	"southeast" : VILSTREAM"path1",
            "east" : VILSTREAM"stream18"
    	] ));
}
