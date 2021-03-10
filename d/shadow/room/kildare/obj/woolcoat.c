#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("wool coat");
   set_id(({"coat","wool coat","suede coat"}));
   set_short("Wool-lined Coat");
   set_long(
@CIRCE
This soft coat is made from the brushed suede of sheep.  It 
is a light tan color, and the seams have been left showing, 
giving it a somewhat rough look.  It seems very sturdy and warm, 
lined with fluffy white wool.  The overcoat is designed to be 
worn hip-length and can be buttoned up, protecting the wearer 
from the cold.
CIRCE
   );
   set_lore("This is a finely-tailored coat made by Mariel "+
      "of Kildare Glen.  A small tag bearing her mark has been "+
      "sewn into it.");
   set_property("lore difficulty",3);
   set_weight(8);
   set_value(50);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
}

int wearme() {
   tell_object(ETO,"%^RESET%^%^ORANGE%^You slip the coat on and button "+
      "it up, feeling much warmer.%^RESET%^");
   return 1;
}

int unwearme() {
   tell_object(ETO,"%^BOLD%^%^CYAN%^You get a slight chill as you slip out of the coat.");
   tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" shivers "+
      "and removes the coat.%^RESET%^",ETO);
   return 1;
}
