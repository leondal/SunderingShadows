// /d/magic/symbols/eldath_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","eldath_holy_symbol","medallion","wooden medallion"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("wooden medallion");
   set_short("wooden medallion");
   set_long("This medallion is a piece of wood carved into a circle and painted sky blue. Painted fern leaves surround the inner edge of the circle, with some living plants affixed as well. In the center of the circle is a picture of a peaceful waterfall falling into a still pool.");
}
