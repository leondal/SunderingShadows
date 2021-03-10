//stream13.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_long(
         "%^BOLD%^%^BLUE%^The river grows shallower here along the banks.  "+
         "This is the source of the stream flowing down from the %^RESET%^%^RED%^mountains, "+
         "%^BOLD%^%^BLUE%^and the water is quite cold and the current brisk.  "+
         "The %^BOLD%^%^BLACK%^deep, dark opening of a cave %^BLUE%^can be seen to the "+
         "east on the riverbank."+
         "\n"
      );
      add_item("cave","The opening of the cave looks ominous, and a foul smell "+
         "emanates from it.");
      add_item("mountains","The mountains rise sharply here, blocking out the view "+
         "of the sky and cooling the air below.");
    	set_exits(([
       	"west" : VILSTREAM"stream12",
       	"east" : KCAVES"caves1"
    	] ));
}
