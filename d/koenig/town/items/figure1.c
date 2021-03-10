#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("Crystal Figurine");
  set_id( ({"Crystal Figurine", "crystal figurine", "figurine"}) );
  set_short("%^BOLD%^%^GREEN%^A crystal figurine%^RESET%^");
  set_long("%^RESET%^%^GREEN%^This is a %^BOLD%^crystal figurine%^RESET%^%^GREEN%^ made of a deep rich %^CYAN%^g%^RESET%^%^GREEN%^r%^CYAN%^ee%^RESET%^%^GREEN%^n c%^CYAN%^ryst%^RESET%^%^GREEN%^a%^CYAN%^l%^RESET%^%^GREEN%^ in the form of a scorpion. It is very detailed and looks very life like. It is about the size of a large man's hand.");
  set_weight(1000);
  set_value(0);
}
