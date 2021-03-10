#include <std.h>
#include "../ruins.h"
inherit OBJECT;

void create()
{
	::create();
	set_name("serpent's tooth");
	set_short("A serpent's tooth");
	set_id(({"tooth","serpent tooth","serpent's tooth","serpents tooth","serpent_tooth"}));
	set_long(
	"%^BOLD%^%^WHITE%^This tooth must have come from a very large serpent! It"+
	" is about a foot in length, and quite sharp. With a little work, it might"+
	" make a nice weapon."
	);
	set_weight(5);
	set_value(500);
}
