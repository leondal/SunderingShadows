#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("paper");
  set_id( ({"paper"}) );
  set_short("a small piece of paper");
  set_long("%^YELLOW%^The golden key will unlock your greatest ally from its prison. Be warned! If you free it too soon, it can be your greatest enemy.%^RESET%^");
  set_value(0);
  set_weight(1);
}
