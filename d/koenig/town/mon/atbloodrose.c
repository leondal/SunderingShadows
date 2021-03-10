#include <std.h>
inherit "/d/koenig/town/mon/bloodrose.c";

void create() {
  ::create();
  set_name("bloodrose");
  set_id( ({"bloodrose", "rosebush", "amethyst bloodrose", "bush"}) );
  set_short("%^BOLD%^%^MAGENTA%^An A%^RESET%^%^MAGENTA%^m%^RED%^e%^BOLD%^%^MAGENTA%^thy%^RESET%^%^MAGENTA%^s%^RED%^t %^BOLD%^%^MAGENTA%^Bl%^RESET%^%^MAGENTA%^o%^RED%^o%^BOLD%^%^MAGENTA%^dr%^RESET%^%^RED%^o%^MAGENTA%^s%^BOLD%^e B%^RESET%^%^MAGENTA%^u%^BOLD%^sh%^RESET%^");
  set_long("%^RESET%^%^MAGENTA%^This %^BOLD%^amethyst rose bush%^RESET%^%^MAGENTA%^ has some of its blossoms in full bloom "+
"while others are still in bud. Odd how it has little veins of %^BOLD%^%^RED%^pale red%^RESET%^%^MAGENTA%^ in it.%^RESET%^");
}
