#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
 set_name("pedestal");
  set_id( ({"pedestal"}) );
 set_short("%^YELLOW%^A golden pedestal%^RESET%^");
  set_long("%^YELLOW%^This is an ornately carved, golden pedestal. Carved into its surface are images of demons battling angels. Sitting atop it is a very lovely %^WHITE%^figurine%^YELLOW%^ made of crystal.%^RESET%^");
  set_weight(1000);
  set_value(0);
}
