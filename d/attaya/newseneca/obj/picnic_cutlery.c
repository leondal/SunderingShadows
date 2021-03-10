//picnic cutlery for new Seneca
//~Circe~ 12/13/07
#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("picnic cutlery");
   set_id(({"cutlery","picnic cutlery","pewter cutlery","pewter picnic cutlery"}));
   set_short("%^RESET%^pewter cutlery set%^RESET%^");
   set_long("Arranged on a thin %^ORANGE%^leather thong %^RESET%^"+
      "is a set of pewter cutlery.  A two-tined fork, small spoon, "+
      "and rather dull knife make up the set, all with short, "+
      "rounded handles.  The %^RESET%^%^ORANGE%^thong %^RESET%^may "+
      "be untied to remove each piece, but it has also been left "+
      "long enough to allow one piece to be used at a time without "+
      "untying them.");
   set_weight(1);
   set_value(0);
}