#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("small golden key");
  set_id( ({"key", "golden key", "small golden key"}) );
  set_short("%^YELLOW%^A small golden key%^RESET%^");
  set_long("%^YELLOW%^This is a small and shiny %^RESET%^%^ORANGE%^golden%^YELLOW%^ key. You imagine what wonder of wonders it might unlock in this place.%^RESET%^");
  set_weight(1);
  set_value(5);
}
