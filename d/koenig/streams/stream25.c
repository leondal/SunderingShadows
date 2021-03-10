//stream25.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_long(
         "%^BOLD%^%^BLUE%^The river grows shallower here along the banks.  "+
         "This is the source of the stream flowing down from the %^RESET%^%^RED%^mountains, "+
         "%^BOLD%^%^BLUE%^and the water is quite cold and the current brisk.  "+
         "Just to the east is a narrow, rocky bank at the foot of the mountains.  A "+
         "small %^CYAN%^waterfall %^BLUE%^is formed here, with the icy water cascading down the rock.  "+
         "It seems you can go not further east."+
         "\n"
      );
      add_item("cave","The opening of the cave across the stream looks ominous, but nothing "+
         "from it could reach you here.");
      add_item("mountains","The mountains rise sharply here, blocking out the view "+
         "of the sky and cooling the air below.");
      add_item("waterfall","Water tumbles down over the rocks, forming a small pool "+
         "here at the foot of the mountains that is quickly drained by the stream.");
    	set_exits(([
       	"west" : VILSTREAM"stream24",
            "enter" : VILSTREAM"grotto1"
    	] ));
      set_invis_exits(({"enter"}));
      set_search("default","Looking around, you see a dark shadow behind the waterfall.");
      set_search("waterfall","As you get closer to the waterfall, you can see it "+
         "hides a cave of some sort.  You might be able to enter it.");
}