//A crystal ball to be used as the target for remote
//viewing.  Place in enclaves and such.
//~Circe~ 7/31/05

#include <std.h>

inherit OBJECT;

void create() {
	::create();
	set_name("crystal ball");
	set_id(({
                "crystal ball","ball"
	}));
	set_short("%^CYAN%^a crystal ball%^RESET%^");
	set_property("no animate", 1);
	set_long(
         "%^CYAN%^This sphere is made from a polished piece of "+
         "crystal about ten inches in diameter.  The surface "+
         "is flawless, free from scratches or cracks.  The "+
         "center of the ball seems almost opaque, as though it "+
         "is hiding some manner of secret.  The ball is set "+
         "upon a short mahogany stand.%^RESET%^"
	);
	set_value(1001);
	set_weight(100000);
	set_no_clean(1);
}

int get() { return 0; }

int drop() { return 1; }

int is_crystal_ball()
{
	return 1;
}
