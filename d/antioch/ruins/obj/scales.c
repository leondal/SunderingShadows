#include <std.h>
#include "../ruins.h"
inherit OBJECT;

void create()
{
	::create();
	set_name("serpent scales");
	set_short("Some serpent scales");
	set_id(({"scales","serpent scales","some serpent scales","serpent_scales"}));
	set_long(
	"%^BLUE%^These serpent scales are dark with the muck of the sewers. They"+
	" are quite large, and look rather durable. Someone with skill might be"+
	" able to do something with them."
	);
	set_value(2000);
	set_weight(40);
}
