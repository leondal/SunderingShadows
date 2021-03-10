#include <std.h>
#include "../ruins.h"
inherit OBJECT;

void create()
{
	::create();
	set_name("demon heart");
	set_short("The stone heart of a demon");
	set_id(({"heart","demon heart","stone heart","demon_heart","stone heart of a demon"}));
	set_long(
	"This is the stone heart of some terrible demon. It is gnarled and black"+
	" and quite gruesome, but at least the demon is dead now."
	);
	set_weight(20);
	set_value(0);
}
