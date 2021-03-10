#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/armour/hide.c";

void create()
{
	::create();
	set_name("green hide");
	set_short("A suit of green hide");
	set_id(({"hide","armor","hide armor","green hide","suit of hide","suit of green hide"}));
	set_long(
	"This suit of hide armor was made from some the skin of some large reptile."+
	" It is a mottled green color that is still rough on the outside. It has"+
	" been hardened, and the inside scraped smooth and slightly padded for"+
	" comfort."
	);
	set_size(2);
	set_value(15);
	set_property("enchantment",1);
}
