inherit "/std/Object.c";
#include "std.h"

void create()
{
  ::create();
  set_name( "Black Death Key");
  set_id( ({"key", "black death key"}) );
  set_short("%^BOLD%^%^BLACK%^A Black Death Key%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This is a rather heavy and unusual looking key. It looks to be in the shape of a %^RESET%^skeleton%^BOLD%^%^BLACK%^ coming out of a coffin. How strange.");
  set_weight(10);
  set_value(20);
}
