#include <std.h>
inherit "/d/koenig/town/mon/bloodrose.c";

void create() {
  ::create();
  set_name("bloodrose");
  set_id( ({"bloodrose", "rosebush", "pink bloodrose", "bush"}) );
  set_short("%^BOLD%^%^MAGENTA%^Pink Bl%^RED%^o%^MAGENTA%^odro%^RED%^s%^MAGENTA%^e Bush%^RESET%^");
  set_long("%^BOLD%^%^MAGENTA%^This beautiful pink rose bush has some of its blossoms in full bloom while others are still in bud. It is odd how it has little veins of %^RED%^pale red%^MAGENTA%^ in it%^RESET%^.");
}
