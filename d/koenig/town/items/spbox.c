#include <std.h>
inherit "/std/bag_logic";

void create()
{
  ::create();
  set_name("box");
  set_id( ({"small box"}) );
  set("short","%^BOLD%^%^BLACK%^A small j%^RESET%^%^MAGENTA%^e%^RED%^w%^BOLD%^%^BLACK%^el%^RESET%^%^RED%^e%^MAGENTA%^r%^BOLD%^%^BLACK%^y box%^RESET%^");
  set("long","The lid of this small box has a %^BOLD%^%^BLACK%^black widow %^RESET%^made of %^BOLD%^%^BLACK%^black onyx %^RESET%^and a single %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^by %^RESET%^on it. The box is carefully carved from %^BOLD%^%^BLACK%^blackened wood%^RESET%^.");
  set_open_long("The lid of this small box has a %^BOLD%^%^BLACK%^black widow %^RESET%^made of %^BOLD%^%^BLACK%^black onyx %^RESET%^and a single %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^by %^RESET%^on it. The box is carefully carved from %^BOLD%^%^BLACK%^blackened wood%^RESET%^.\%^BOLD%^%^WHITE%^It is open.%^RESET%^");
  set_closed_long("The lid of this small box has a %^BOLD%^%^BLACK%^black widow %^RESET%^made of %^BOLD%^%^BLACK%^black onyx %^RESET%^and a single %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^by %^RESET%^on it. The box is carefully carved from %^BOLD%^%^BLACK%^blackened wood%^RESET%^.\%^BOLD%^%^WHITE%^It is closed.%^RESET%^");
  set_no_clean(1);
  set_weight(1);
  set_value(1);
  set_max_internal_encumbrance(20);
  set_possible_to_close(1);
  set_lock("unlocked");
  set_key("small golden key");
}
void init(){
  ::init();
  if(receive_objects()) toggle_closed();
}
