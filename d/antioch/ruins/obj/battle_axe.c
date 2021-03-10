#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/weapon/battle_axe.c";

void create()
{
	::create();
	set_name("battle axe");
	set_short("A mighty battle axe");
	set_id(({"axe","battle axe","large axe","mighty axe","mighty battle axe"}));
	set_long(
	"This is a large battle axe. The hilt is wooden and wrapped with tanned"+
	" hide and the blade is made of wickedly sharp steel. This could be a"+
	" powerful weapon in the right hands."
	);
}
