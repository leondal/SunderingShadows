#include <std.h>
inherit "/std/armour";
void create(){
::create();
set_name("Dark Ring");
set_id(({"ring","black ring","dark ring"}));
set_short("Dark Ring");
set_long("This is a platinum ring with a black stone "+
"set in its top. "+
"The stone has sparkles of light dancing through it. "+
"It gives off a cold%^BOLD%^%^BLUE%^ aura of evil.%^RESET%^");
set_type("clothing");
set_ac(0);
set_weight(1);
set_type("ring");
set("value",50);
  set_limbs(({"left hand","right hand"}));
}
