#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Elorenna");
	set_short("Elorenna, a citizen of Antioch");
	set_id(({"citizen","female","woman","half-elf","elorenna","Elorenna"}));
	set_long(
	"Elorenna must be getting older, she is actually showing signs of her age which"+
	" is rare for half-elves. Her long brown hair is streaked with gray, and there"+
	" are even a few wrinkles on her delicate face. Her eyes are a warm brown color"+
	" and even though she can best be described as homely, she seems like she has"+
	" a soft heart."
	);
	set_gender("female");
	set_race("half-elf");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
}
