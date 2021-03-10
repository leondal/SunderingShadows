#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("dungeon key");
  set_id( ({"key", "dungeon key"}) );
  set_short("%^YELLOW%^A small key%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This is a small, %^RESET%^%^ORANGE%^dirty key%^BOLD%^%^BLACK%^. Hmmmmm. Now to find a small, %^RESET%^%^ORANGE%^dirty lock%^BOLD%^%^BLACK%^.%^RESET%^");
  set_weight(1);
  set_value(5);
}

