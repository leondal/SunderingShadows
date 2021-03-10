#include <std.h>

#define COLORS ({"%^BOLD%^%^GREEN%^vibrant green","%^BOLD%^%^RED%^crimson","%^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en ora%^YELLOW%^ng%^RESET%^%^ORANGE%^e","%^YELLOW%^saffron","%^BOLD%^%^MAGENTA%^fuchsia","%^BOLD%^%^BLUE%^navy blue","%^GREEN%^jade green","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^violet","gray"})

inherit DAEMON;

int j;
string str, COLOR;

void create_robe(object obj)
{
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	obj->set_value(80+random(21));
	obj->set_name(""+COLOR+" robe%^RESET%^");
	obj->set_short(""+COLOR+" robe%^RESET%^");
	obj->set_id(({"robe",""+COLOR+" robe","embroidered robe","robes"}));
	obj->set_long("These richly lavishly embroidered robes are a "+
         "common sight in the Tsvaren Empire.  The blend of linen "+
         "and silk is used to create the main body of the robe, most "+
         "likely due to the comfort these two fabrics bring in the "+
         "heat.  Almost every square inch of this "+COLOR+" robe "+
         "%^RESET%^is heavily %^YELLOW%^embroidered %^RESET%^with "+
         "a striking pattern.  Though such a use of color might seem "+
         "garish or an eyesore, this %^BOLD%^needlework %^RESET%^is "+
         "simply captivating and breathtaking.");
	obj->set_weight(8);
	obj->set_type("clothing");
	obj->set_limbs(({"torso"}));
	obj->set_ac(0);
}
