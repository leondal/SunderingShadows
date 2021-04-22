#include <std.h>

inherit OBJECT;

create() {
	::create();
	set_name("portable scrying mirror");
	set_id(({
		"mirror", "fine mirror", "scrying mirror", "portable mirror", "portable scrying mirror"
	}));
	set_short("%^RESET%^%^CYAN%^a portable scrying mirror%^RESET%^");
	set_property("no animate", 1);
	set_long("This is a rather plain, but finely made mirror.  The reflective surface appears to be silver polished to an incredible lustre.  The surface is large and with the stout frame, this mirror looks to weigh quite a bit, and is even bulkier than it is heavy.");
	set_value(75000);
	set_weight(20);
	set_no_clean(1);
}

int is_scrying_mirror()
{
	return 1;
}
