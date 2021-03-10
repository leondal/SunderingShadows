#include <std.h>

#define COLORS ({"%^BOLD%^%^GREEN%^vibrant green","%^BOLD%^%^RED%^crimson","%^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en ora%^YELLOW%^ng%^RESET%^%^ORANGE%^e","%^YELLOW%^saffron","%^BOLD%^%^MAGENTA%^fuchsia","%^BOLD%^%^BLUE%^navy blue","%^GREEN%^jade green","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^violet","gray"})

inherit DAEMON;

int j;
string str, COLOR;

void create_choli(object obj)
{
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	obj->set_value(35);
	obj->set_name(""+COLOR+" choli%^RESET%^");
	obj->set_short(""+COLOR+" choli%^RESET%^");
	obj->set_id(({"choli","shirt",""+COLOR+" choli"}));
	obj->set_long("The choli is a tight-fitting top that exposes "+
         "ones midriff.  This one has a rounded neckline and short "+
         "slender sleeves.  Made from "+COLOR+" silk %^RESET%^that "+
         "has been woven with %^YELLOW%^golden threads%^RESET%^, "+
         "this shirt has an exotic appearance.  A pair of ties is "+
         "traditionally wrapped around one's torso.  Silken %^YELLOW%^"+
         "tassels %^RESET%^hang from the end of each tie.");
	obj->set_weight(3);
	obj->set_type("clothing");
	obj->set_limbs(({"torso"}));
	obj->set_ac(0);
}
