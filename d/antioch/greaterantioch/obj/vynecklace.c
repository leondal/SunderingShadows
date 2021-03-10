#include <std.h>
#include "../gantioch.h"
inherit OBJECT;

create(){
   ::create();
   set_id(({"necklace","vythao's necklace"}));
   set_name("vythao's necklace");
   set_obvious_short("%^RESET%^%^ORANGE%^A leather-bound %^BOLD%^%^BLACK%^opal %^RESET%^%^ORANGE%^necklace.%^RESET%^");
   set_short("%^BOLD%^%^RED%^Vythao's %^BOLD%^%^BLACK%^Keepsake%^RESET%^");
   set_long(
      "%^RESET%^%^ORANGE%^This well-crafted tribal necklace is quite beautiful."+
      "Hung on a long leather step is a %^BOLD%^%^BLACK%^black opal %^RESET%^%^ORANGE%^which is held"+
      "securely by a %^BOLD%^%^YELLOW%^brass%^RESET%^%^ORANGE%^ loop. The item looks well worn, as if"+
      "it has been used for many, many years. It is obviously a valuable item.%^RESET%^"
   );
   set_weight(1);
   set_value(1300);
}
