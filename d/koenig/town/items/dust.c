#include <std.h>
inherit OBJECT;

void create() {
  ::create();
  set_name("dust");
  set_id( ({"dust"}) );
  set_short("%^RESET%^%^ORANGE%^A pile of dust%^RESET%^");
  set_long("%^RESET%^%^ORANGE%^Here sits a pile of %^RESET%^dust%^RESET%^%^ORANGE%^. It is exceptionally dusty.%^RESET%^");
  set_value(0);
  set_weight(1);
}
