#include <std.h>

inherit OBJECT;

void create(){
	::create();
	
	set_name("shapelesss mass");
	set_id(({"mass", "shapeless mass"}));

	set_short("%^BOLD%^%^BLACK%^A shapeless mass%^RESET%^");

	set_long("%^BOLD%^%^BLACK%^This mass of substance is almost fluid, though "+
	"it mostly resembles a ball.  It is impossible to determine "+
	"from what it was made or what its original shape or purpose was.%^RESET%^");

	set_value(0);
	set_weight(1);
}

