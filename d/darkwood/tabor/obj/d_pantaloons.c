#include <std.h>

#define COLORS ({"%^BOLD%^%^GREEN%^vibrant green","%^BOLD%^%^RED%^crimson","%^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en ora%^YELLOW%^ng%^RESET%^%^ORANGE%^e","%^YELLOW%^saffron","%^BOLD%^%^MAGENTA%^fuchsia","%^BOLD%^%^BLUE%^navy blue","%^GREEN%^jade green","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^violet","gray"})

inherit DAEMON;

int j;
string str, COLOR;

void create_pantaloons(object obj)
{
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	obj->set_value(10+random(16));
	obj->set_name(""+COLOR+" pantaloons%^RESET%^");
	obj->set_short(""+COLOR+" pantaloons%^RESET%^");
        obj->set_id(({"pantaloons",""+COLOR+" pantaloons","pants","tabor pantaloons"}));
	obj->set_long("Long flowing soft "+COLOR+" cotton pantaloons "+
         "%^RESET%^fall to ones ankles.  The pantaloons are typically "+
         "worn tight around the waist and loose around the legs.  The "+
         "excess fabric is then gathered by the use of %^BOLD%^"+
         "embroidered bands %^RESET%^around the ankles, thus creating "+
         "a rounded puff of fabric.  These pantaloons have a "+
         "drawstring waist to get the right fit.");
	obj->set_weight(6);
	obj->set_type("clothing");
	obj->set_limbs(({"right leg","left leg"}));
	obj->set_ac(0);
}
