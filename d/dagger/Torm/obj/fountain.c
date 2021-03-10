#include <std.h>
inherit OBJECT;
void create(){
  ::create();
  set_id(({
    "fountain","city water fountain","torms city water fountain","water fountain","torm's city fountain","torms city fountain","torm's city water fountain",
  }));
    set_name("Torm's city fountain");
    set_short("Torm's city fountain");
  set_weight(100000);
  set_long(
  "%^YELLOW%^"
   "  Torm's central water fountain is a great work of art."
   "  A massive bronze whale leaps from an open pool of water with a continuous stream of pure water spouting from its blow-hole."
   "  The base of the fountain is almost 20 feet across and the water from the top of the whale reaches almost 30 feet in the air before it arcs back down around the statue into the basin."
  "%^BLUE%^"
  "\nThe water looks very good and you're sure you could <drink from fountain> to ease your thirst." 
  );
  set_value(0);
  set_property("no animate",1);
}
