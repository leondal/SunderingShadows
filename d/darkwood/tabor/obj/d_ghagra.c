#include <std.h>

#define COLORS ({"%^BOLD%^%^GREEN%^vibrant green","%^BOLD%^%^RED%^crimson","%^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en ora%^YELLOW%^ng%^RESET%^%^ORANGE%^e","%^YELLOW%^saffron","%^BOLD%^%^MAGENTA%^fuchsia","%^BOLD%^%^BLUE%^navy blue","%^GREEN%^jade green","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^violet","gray"})

inherit DAEMON;

int j;
string str, COLOR;

void create_ghagra(object obj)
{
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	obj->set_value(45);
	obj->set_name(""+COLOR+" ghagra%^RESET%^");
	obj->set_short(""+COLOR+" ghagra%^RESET%^");
	obj->set_id(({"ghagra","skirt",""+COLOR+" ghagra"}));
	obj->set_long("This gathered skirt is made from semi-sheer "+
         ""+COLOR+" silk %^RESET%^that reaches down to the mid-shin.  "+
         "The skirt is prized by many women for its lightweight "+
         "texture and its brilliant bold color.  As with most Tsvarian "+
         "silk, this one is woven with %^YELLOW%^golden threads "+
         "%^RESET%^to create tiny ornate circles along the cloth.  "+
         "A %^YELLOW%^golden border %^RESET%^encircles the bottom of "+
         "the skirt.  They say that in the Tsvarian Empire one can "+
         "tell a persons social class, religion, and where they are "+
         "from by the pattern of this border.");
	obj->set_weight(5);
	obj->set_type("clothing");
	obj->set_limbs(({"right leg","left leg"}));
	obj->set_ac(0);
}
