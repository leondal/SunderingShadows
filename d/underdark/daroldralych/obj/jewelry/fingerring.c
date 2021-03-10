#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("silver rings");
   set_id(({"rings","silver rings","chain-linked rings","chain linked rings","chain linked silver rings","chain-linked silver rings"}));
   set_short("%^BOLD%^%^WHITE%^chain-linked s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r rings%^RESET%^");
   set_long("This piece of jewelry is formed of three solid %^BOLD%^"
"%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r "
"%^RESET%^rings, each polished to a %^ORANGE%^br%^YELLOW%^il%^WHITE%^"
"l%^YELLOW%^ia%^RESET%^%^ORANGE%^nt %^RESET%^sheen.  Its unique "
"appearance is given by the thin chains of %^BOLD%^%^WHITE%^s%^RESET%^i"
"%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^, linking the "
"three rings together, but with a fair length of movement between each.  "
"It seems the entire piece is designed to be worn across several fingers, "
"with the chains left to dangle over the back of the hand.  A strange, "
"but pleasantly %^GREEN%^e%^CYAN%^x%^MAGENTA%^o%^CYAN%^t%^GREEN%^i"
"%^ORANGE%^c %^RESET%^item of jewelry.\n");
   set_limbs(({"right hand","left hand"}));
   set_weight(0);
   set_value(530);
   set_ac(0);
   set_type("ring");
}
