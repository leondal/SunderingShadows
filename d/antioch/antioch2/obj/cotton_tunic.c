#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("cotton tunic");
	set_short("%^RESET%^A plain cotton tunic");
	set_id(({"tunic","cotton tunic","mina_clothing","plain tunic","clothing","plain cotton tunic","white tunic"}));
	set_long(
	"%^WHITE%^%^BOLD%^This is a cotton tunic made from soft cotton. It is"+
	" a solid white color. It looks simple yet comfortable."
	);
	set_weight(4);
	set_value(9);
	set_ac(0);
	set_type("clothing");
	set_limbs(({"torso"}));
	set_size(2);
}
