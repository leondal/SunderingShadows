#include <std.h>
inherit "/d/koenig/town/mon/bloodrose.c";

void create() {
  ::create();
  set_id( ({"bloodrose", "rosebush", "red bloodrose", "bush"}) );
  set_short("%^BOLD%^%^RED%^Red %^RESET%^%^RED%^Bl%^BOLD%^%^RED%^o%^RESET%^%^RED%^odro%^BOLD%^%^RED%^s%^RESET%^%^RED%^e %^BOLD%^%^RED%^Bush%^RESET%^");
  set_long("%^RESET%^%^RED%^This beautiful red rose bush has some of its blossoms in full bloom while others are still in bud.  Odd how it has little veins of %^BOLD%^pale red%^RESET%^%^RED%^ in it.%^RESET%^");
  set_funcs( ({"embrace"}) );
  set_func_chance(75);
}
