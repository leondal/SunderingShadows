inherit "/std/Object.c";
#include "std.h"

void create()
{
  ::create();
  set_name( "Life Angel Key");
  set_id( ({"key", "life angel key"}) );
  set_short("%^BOLD%^%^WHITE%^A Life Angel Key%^RESET%^");
  set_long("%^BOLD%^%^WHITE%^This key, unlike its counterpart, is rather light, and is in the shape of an %^YELLOW%^angel%^BOLD%^%^WHITE%^ resurrecting a small child.");
  set_weight(5);
  set_value(20);
}
