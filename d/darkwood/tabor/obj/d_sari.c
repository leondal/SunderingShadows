//updated by Circe 7/21/19 to ring type so it can be layered as intended
#include <std.h>

#define COLORS ({"%^BOLD%^%^GREEN%^vibrant green","%^BOLD%^%^RED%^crimson","%^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en ora%^YELLOW%^ng%^RESET%^%^ORANGE%^e","%^YELLOW%^saffron","%^BOLD%^%^MAGENTA%^fuchsia","%^BOLD%^%^BLUE%^navy blue","%^GREEN%^jade green","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^violet","gray"})

inherit DAEMON;

int j;
string str, COLOR;

void create_sari(object obj)
{
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	obj->set_value(30+random(11));
	obj->set_name(""+COLOR+" sari%^RESET%^");
	obj->set_short(""+COLOR+" sari%^RESET%^");
	obj->set_id(({"sari",""+COLOR+" sari","dress"}));
	obj->set_long("A common type of 'dress' for Tsvarian women "+
         "is the sari.  Though it is not exactly a dress, the sari "+
         "is often seen that way.  Colorful silk dyed a "+COLOR+" "+
         "shade %^RESET%^with %^YELLOW%^"+
         "golden threads %^RESET%^is pleated and wrapped around a "+
         "womans waist to create the flowing long skirt.  The ends "+
         "of the fabric are then draped horizontally across ones "+
         "shoulder.  Along the outer edge of the draped cloth a "+
         "%^YELLOW%^detailed golden border %^RESET%^shimmers.  It "+
         "is said that in the Tsvaren Empire one can determine a "+
         "womans rank, social class, and religion by this border.");
	obj->set_weight(8);
	obj->set_type("ring");
	obj->set_limbs(({"torso"}));
	obj->set_ac(0);
}
