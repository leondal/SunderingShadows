//petals.c - flower petals you can gather and then toss
//for new Seneca by ~Circe~ 1/12/08
#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("bougainvillea petals");
   set_id(({"petals","bougainvillea petals","flower petals","sprinkling of petals"}));
   set_short("%^RESET%^%^GREEN%^a sprinkling of %^ORANGE%^c%^BOLD%^o"+
      "%^RED%^l%^MAGENTA%^o%^YELLOW%^r%^RESET%^%^MAGENTA%^f"+
      "%^BOLD%^u%^RESET%^%^ORANGE%^l %^GREEN%^petals%^RESET%^");
   set_long("%^GREEN%^Spread all along the ground are tiny petals "+
      "of %^BOLD%^%^MAGENTA%^pi%^WHITE%^n%^MAGENTA%^k"+
      "%^RESET%^%^ORANGE%^, %^BOLD%^%^RED%^scarlet%^RESET%^"+
      "%^GREEN%^, and %^ORANGE%^ora%^YELLOW%^n%^RESET%^%^ORANGE%^ge "+
      "%^GREEN%^bougainvillea blossoms.  They have been spread "+
      "out quite a bit and some have become crushed, but they "+
      "create a pretty decoration.%^RESET%^");
   set_weight(1);
   set_value(0);
}