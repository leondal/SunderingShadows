#include <std.h>

#define COLORS ({"%^BOLD%^%^GREEN%^vibrant green","%^BOLD%^%^RED%^crimson","%^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en ora%^YELLOW%^ng%^RESET%^%^ORANGE%^e","%^YELLOW%^saffron","%^BOLD%^%^MAGENTA%^fuchsia","%^BOLD%^%^BLUE%^navy blue","%^GREEN%^jade green","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^violet","gray"})

inherit DAEMON;

int j;
string str, COLOR;

void create_leggings(object obj)
{
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	obj->set_value(8+random(6));
	obj->set_name(""+COLOR+" leggings%^RESET%^");
	obj->set_short(""+COLOR+" leggings%^RESET%^");
	obj->set_id(({"leggings",""+COLOR+" leggings","silk leggings"}));
	obj->set_long("These cropped silken leggings are commonly "+
         "worn by both sexes in the Tsvaren Empire.  The leggings "+
         "fall just below the knee and are notched on each side.  "+
         "The heavyweight "+COLOR+" silk %^RESET%^has a slight "+
         "sheen on it, common for any high quality silk.  A richly "+
         "detailed %^BOLD%^metallic border %^RESET%^runs across the "+
         "hem of each leg.");
	obj->set_weight(2);
	obj->set_type("clothing");
	obj->set_limbs(({"right leg","left leg"}));
	obj->set_ac(0);
}
