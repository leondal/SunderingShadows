#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("paper");
  set_id( ({"paper"}) );
  set_short("a small piece of paper");
  set_long("%^BOLD%^%^WHITE%^You must find the house of the three sisters, but be careful here, for nothing is as it appears to be and there are secrets where you least expect them.%^RESET%^");
  set_value(0);
  set_weight(1);
}
