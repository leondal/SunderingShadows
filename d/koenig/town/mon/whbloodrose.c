#include <std.h>
inherit "/d/koenig/town/mon/bloodrose.c";

void create() {
  ::create();
  set_id( ({"bloodrose","rosebush","white bloodrose","bush"}) );
  set_short("%^BOLD%^%^WHITE%^White Bl%^RESET%^o%^BOLD%^odr%^RESET%^o%^BOLD%^se Bush%^RESET%^");
  set_long("%^RESET%^This beautiful %^BOLD%^white rose bush%^RESET%^ has some of its blossoms in full bloom "+
"while others are still in bud. Odd how it has little veins of %^BOLD%^%^RED%^pale red%^RESET%^ in it.");
  set_funcs( ({"embrace"}) );
  set_func_chance(75);
}
