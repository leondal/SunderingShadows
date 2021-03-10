#include <std.h>
inherit "/d/koenig/town/mon/bloodrose.c";

void create() {
  ::create();
  set_id( ({"bloodrose", "rosebush", "yellow bloodrose", "bush"}) );
  set_short("%^YELLOW%^Yellow Bl%^RESET%^o%^YELLOW%^odro%^RESET%^s%^YELLOW%^e Bush%^RESET%^");
  set_long("%^RESET%^This beautiful %^YELLOW%^yellow rose bush%^RESET%^ has some of its blossoms in full bloom "+
"while others are still in bud. Odd how it has little veins of %^BOLD%^%^RED%^pale red%^RESET%^ in it.");
}
