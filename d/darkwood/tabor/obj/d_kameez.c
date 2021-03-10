#include <std.h>

#define COLORS ({"%^BOLD%^%^GREEN%^vibrant green","%^BOLD%^%^RED%^crimson","%^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en ora%^YELLOW%^ng%^RESET%^%^ORANGE%^e","%^YELLOW%^saffron","%^BOLD%^%^MAGENTA%^fuchsia","%^BOLD%^%^BLUE%^navy blue","%^GREEN%^jade green","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^violet","gray"})

inherit DAEMON;

int j;
string str, COLOR;

void create_kameez(object obj)
{
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	obj->set_value(70+random(15));
	obj->set_name(""+COLOR+" kameez%^RESET%^");
	obj->set_short(""+COLOR+" kameez%^RESET%^");
	obj->set_id(({"kameez","jacket",""+COLOR+" kameez"}));
	obj->set_long("This long tunic jacket is made from a blend of "+
         "silk and linen dyed a "+COLOR+" shade %^RESET%^and made "+
         "into this comfortable top.  Thanks to the linen, the silk "+
         "jacket has some structure.  The long, tapered sleeves "+
         "further add to the exquisite tailoring of this garment.  "+
         "The jacket is collarless, and it seems to fasten closed up "+
         "the front with the use of hidden metal hooks and eyes.");
	obj->set_weight(6);
	obj->set_type("clothing");
	obj->set_limbs(({"torso"}));
	obj->set_ac(0);
}
