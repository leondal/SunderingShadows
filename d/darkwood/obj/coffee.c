#include <std.h>
inherit "/std/drink.c";

void create()
{
	::create();
	set_name("coffee");
	set_id(({"coffee","mug of coffee","coffee mug","black coffee"}));
	set_short("A mug of coffee");
	set_weight(1);
	set_poison(0);
	set_strength(15);
	set_value(0);
	set_destroy();
	set_type("caffeine");
	set_long(
	"This is a mug of cold, black coffee. It looks very gritty, and almost"+
	" has the consistancy of mud."
	);
	set_my_mess("You drink the black sludge, er, coffee, and almost choke it's"+
	" so bad.");
	set_your_mess("practically chokes on the cold black coffee.");
}
