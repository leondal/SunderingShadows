#include <std.h>

#define COLORS ({"%^BOLD%^%^GREEN%^vibrant green","%^BOLD%^%^RED%^crimson","%^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en ora%^YELLOW%^ng%^RESET%^%^ORANGE%^e","%^YELLOW%^saffron","%^BOLD%^%^MAGENTA%^fuchsia","%^BOLD%^%^BLUE%^navy blue","%^GREEN%^jade green","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^violet","gray"})

inherit DAEMON;

int j;
string str, COLOR;

void create_vest(object obj)
{
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	obj->set_value(random(20)+30);
	obj->set_name(""+COLOR+" vest%^RESET%^");
	obj->set_short(""+COLOR+" vest%^RESET%^");
	obj->set_id(({"vest","short vest",""+COLOR+" vest"}));
	obj->set_long("This short waisted vest featured rounded edges.  "+
         "Woven into the "+COLOR+" silk %^RESET%^are molten "+
         "%^YELLOW%^golden ovals%^RESET%^, a common theme in "+
         "Tsvarian clothing.  The vest is cut in a way that it "+
         "exposes ones chest.  %^YELLOW%^Gold braid %^RESET%^"+
         "trims the edges of the vest.");
	obj->set_weight(2);
	obj->set_type("ring");
	obj->set_limbs(({"torso"}));
	obj->set_ac(0);
        set_property("repairtype",({ "tailor" }));
}
