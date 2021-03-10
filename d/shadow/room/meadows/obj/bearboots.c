#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("bearskin boots");
   set_short("%^BOLD%^%^BLACK%^B%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^"+
		"ars%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^in boots%^RESET%^");
   set_id(({"bearskin boots","boots","bear skin boots","bear boots"}));
   set_long("%^BOLD%^%^BLACK%^This is a pair of bearskin boots. They have been reinforced"+
   " with leather to make them more durable, and they reach all the way"+
   " up to the knee. The tops of the boots turn down, exposing"+
   " brown bear fur. The inside of the boots is warm and soft, while "+
	"the outside is fairly durable.%^RESET%^");
    set_type("clothing");
    set_weight(2);
    set_limbs(({"left foot","right foot"}));
   set_value(15);
   set_size(random(3)+1);
}
