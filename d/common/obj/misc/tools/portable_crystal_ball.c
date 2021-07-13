//A crystal ball to be used as the target for remote
//viewing.  Place in enclaves and such.
//~Circe~ 7/31/05

#include <std.h>

inherit OBJECT;

void create() {
	::create();
	set_name("portable crystal ball");
	set_id(({
                "crystal ball","ball","portable crystal ball","portable ball"
	}));
	set_short("%^CYAN%^a portable crystal ball%^RESET%^");
	set_long("%^CYAN%^This sphere is made from a polished piece of crystal about ten inches in diameter.  The surface is flawless, free from scratches or cracks.  The center of the ball seems almost opaque, as though it is hiding some manner of secret.  The ball is set upon a short mahogany stand.%^RESET%^");
	set_property("no animate", 1);
	set_value(75000);
	set_weight(20);
	set_no_clean(1);
}

int is_crystal_ball()
{
	return 1;
}
