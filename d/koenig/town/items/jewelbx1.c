#include <std.h>
inherit "/std/bag_logic";

void create()
{
  ::create();
  set_name("jewelry box");
    set_id( ({"jewelry box","box"}));
  set_short("%^BOLD%^%^BLACK%^A small %^BOLD%^%^MAGENTA%^j%^RESET%^%^MAGENTA%^e%^RESET%^%^RED%^wel%^MAGENTA%^r%^BOLD%^y%^BOLD%^%^BLACK%^ box%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This is a very lovely jewelry box. It looks quite expensive. Its black wooden surface is adorned with %^BOLD%^%^MAGENTA%^colorful%^BOLD%^%^BLACK%^ gems.%^RESET%^");
  set_open_long("It is open.");
  set_closed_long("It is closed.");
  set_no_clean(1);
  set_weight(10000);
  set_value(0);
  set_max_internal_encumbrance(10);
  set_possible_to_close(1);
  new("/d/common/obj/potion/hurt.c")->move(this_object());
  new("/d/common/obj/potion/weaken.c")->move(this_object());
  new("/d/koenig/town/items/paper3.c")->move(this_object());
}
