#include <std.h>

#define COLORS ({"%^BOLD%^%^GREEN%^vibrant green","%^BOLD%^%^RED%^crimson","%^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en ora%^YELLOW%^ng%^RESET%^%^ORANGE%^e","%^YELLOW%^saffron","%^BOLD%^%^MAGENTA%^fuchsia","%^BOLD%^%^BLUE%^navy blue","%^GREEN%^jade green","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^violet","gray"})

inherit DAEMON;

int j;
string str, COLOR;

void create_salwar(object obj)
{
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	obj->set_value(35+random(15));
	obj->set_name(""+COLOR+" salwar%^RESET%^");
	obj->set_short(""+COLOR+" salwar%^RESET%^");
	obj->set_id(({"salwar","pants",""+COLOR+" salwar"}));
	obj->set_long("These long loosely fitted trousers are made "+
         "from "+COLOR+" sueded silk%^RESET%^, giving them a nubby, "+
         "pebbly texture.  The silk is thick enough that it does "+
         "not become transparent under any lighting conditions.  "+
         "The fullness of the pants falls in folds that help to "+
         "conceal the shape of the leg.");
	obj->set_weight(6);
	obj->set_type("clothing");
	obj->set_limbs(({"right leg","left leg"}));
	obj->set_ac(0);
}
