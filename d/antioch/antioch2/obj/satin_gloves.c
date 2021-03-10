#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("satin gloves");
	set_short("%^BOLD%^%^BLUE%^Long satin gloves%^RESET%^");
	set_id(({"gloves","mina_clothing","clothing","satin gloves","long satin gloves","long gloves","blue gloves","long blue gloves","blue satin gloves"}));
	set_long(
	"This is a pair of fine satin gloves. They are long, reaching up to the"+
	" wearer's elbows. They have been dyed a %^BOLD%^%^BLUE%^deep blue%^RESET%^"+
	" shade and are very lovely."
	);
	set_weight(2);
	set_value(25);
	set_ac(0);
	set_type("clothing");
	set_limbs(({"right arm","left arm"}));
	set_size(2);
	set_wear((:TO,"wearme":));
}

int wearme(string str)
{
	if((string)ETO->query_gender() != "female") {
		notify_fail("These are lady's gloves!\n");
		return 0;
	}
	return 1;
}
