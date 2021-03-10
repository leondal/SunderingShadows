#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("workman's pants");
	set_short("A pair of workman's pants");
	set_id(({"pants","workman's pants","mina_clothing","clothing","pair of pants","brown pants"}));
	set_long(
	"This is a pair of workman's pants. They are made of rather rough, heavy"+
	" material that is resistant to wear and excellent for field work."
	);
	set_weight(6);
	set_value(12);
	set_ac(0);
	set_type("clothing");
	set_limbs(({"right leg","left leg"}));
	set_size(2);
	set_wear((:TO,"wearme":));
}

int wearme(string str)
{
	if((string)ETO->query_gender() != "male") {
      tell_object(ETO,"These are men's pants!\n");
		return 0;
	}
	return 1;
}
