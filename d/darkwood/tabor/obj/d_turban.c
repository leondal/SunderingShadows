#include <std.h>

#define COLORS ({"%^BOLD%^%^GREEN%^vibrant green","%^BOLD%^%^RED%^crimson","%^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en ora%^YELLOW%^ng%^RESET%^%^ORANGE%^e","%^YELLOW%^saffron","%^BOLD%^%^MAGENTA%^fuchsia","%^BOLD%^%^BLUE%^navy blue","%^GREEN%^jade green","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^violet","gray"})

inherit DAEMON;

int j;
string str, COLOR;

void create_turban(object obj)
{
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	obj->set_value(10+random(16));
	obj->set_name(""+COLOR+" turban%^RESET%^");
	obj->set_short(""+COLOR+" turban%^RESET%^");
	obj->set_id(({"turban",""+COLOR+" turban","hat"}));
	obj->set_long("Folded and tucked swatches of "+COLOR+" "+
         "cotton %^RESET%^are used to create this odd hat.  The "+
         "turban is commonly worn by older men in the Tsvaren "+
         "Empire, though it seems others have began to wear them "+
         "more and more.  Many times men use %^BOLD%^be%^RED%^j"+
         "%^WHITE%^ew%^BLUE%^e%^WHITE%^le%^GREEN%^d %^WHITE%^brooches "+
         "%^RESET%^to pin the turban in place.");
	obj->set_weight(6);
	obj->set_type("clothing");
	obj->set_limbs(({"head"}));
	obj->set_ac(0);
}
