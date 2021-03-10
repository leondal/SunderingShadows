#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("chair");
  set_id( ({"chair"}) );
  set_short("%^RESET%^%^ORANGE%^A comfortable chair%^RESET%^");
  set_long("%^RESET%^%^ORANGE%^This chair looks comfy, very sturdy, and it is presently empty. It sure would make a pleasant place to sit and rest for awhile.%^RESET%^");
  set_weight(10000);
  set_value(0);
}
