#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("Organ");
  set_id( ({"organ", "Organ"}) );
  set_short("%^RESET%^%^ORANGE%^A huge wooden organ%^RESET%^");
  set_long("%^RESET%^%^ORANGE%^This organ is quite large. If you have ever stepped within a temple, it may remind you of one of those. Its notes are pure and soothing, almost hypnotic. It shines and vibrates as it is being played, however, the %^BOLD%^%^BLACK%^monster%^RESET%^%^ORANGE%^ playing has a tendancy to play a few %^GREEN%^sour%^RESET%^%^ORANGE%^ notes.");
  set_weight(10000);
  set_value(0);
}
