//picnic cup for new Seneca
//~Circe~ 12/13/07
#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("picnic cup");
   set_id(({"cup","leather cup","picnic cup","leather picnic cup"}));
   set_short("%^RESET%^%^ORANGE%^a leather picnic cup%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This collapsible cup is made of soft, "+
      "water-proofed leather.  It is only a few inches high but holds "+
      "a surprising amount of liquid at once.  Its clever design allows "+
      "it to be stored away neatly.%^RESET%^");
   set_weight(1);
   set_value(0);
}