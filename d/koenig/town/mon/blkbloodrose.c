#include <std.h>
inherit "/d/koenig/town/mon/bloodrose.c";

void create() {
  ::create();
  set_name("bloodrose");
  set_id( ({"bloodrose","rosebush","black bloodrose","bush"}) );
  set_short("%^BOLD%^%^BLACK%^Bl%^RESET%^%^RED%^a%^BOLD%^c%^BLACK%^k Bl%^RED%^o%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^dr%^RESET%^%^RED%^o%^BOLD%^s%^BLACK%^e B%^RESET%^%^RED%^u%^BOLD%^s%^BLACK%^h%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This beautiful black rose bush has some of its blossoms in full bloom while others are still in bud. Odd how it has little veins of %^BOLD%^%^RED%^pale red%^BOLD%^%^BLACK%^ in it.%^RESET%^");
}
