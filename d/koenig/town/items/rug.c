#include <std.h>
inherit OBJECT;

void create(){
  ::create();
  set_name("rug");
  set_id( ({"rug"}) );
  set_short("%^RESET%^%^MAGENTA%^A simple area rug%^RESET%^");
  set_long("%^BOLD%^%^RED%^This %^RESET%^%^RED%^woven rug%^BOLD%^ is rather simple in design, but it stands out due to its "
     "%^RESET%^cleanliness%^BOLD%^%^RED%^ in the relatively %^RESET%^%^ORANGE%^disgusting%^BOLD%^%^RED%^ surroundings. It seems a bit shifted about, as if someone had been tampering with it.%^RESET%^");
  set_weight(10000);
  set_value(1);
}
