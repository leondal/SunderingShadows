#include <std.h>

#define COLORS ({"%^BOLD%^%^GREEN%^vibrant green","%^BOLD%^%^RED%^crimson","%^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en ora%^YELLOW%^ng%^RESET%^%^ORANGE%^e","%^YELLOW%^saffron","%^BOLD%^%^MAGENTA%^fuchsia","%^BOLD%^%^BLUE%^navy blue","%^GREEN%^jade green","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^violet","gray"})

inherit DAEMON;

int j;
string str, COLOR;

void create_sash(object obj)
{
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	obj->set_value(5+random(11));
	obj->set_name(""+COLOR+" sash%^RESET%^");
	obj->set_short(""+COLOR+" sash%^RESET%^");
	obj->set_id(({"sash",""+COLOR+" sash"}));
	obj->set_long("Long rectangular cut "+COLOR+" silk %^RESET%^"+
         "is used to create this sash.  The sash is worn about the "+
         "waist, as a display of ones pride and to conceal money "+
         "pouches within its many folds.  In the Tsvaren Empire these "+
         "sashes ends are tucked within each other, and only a thug "+
         "would leave them exposed!");
	obj->set_weight(1);
	obj->set_type("ring");
        obj->set_property("repairtype",({ "tailor" }));
	obj->set_limbs(({"waist"}));
	obj->set_ac(0);
}
