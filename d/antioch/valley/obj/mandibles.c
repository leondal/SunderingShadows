#include <std.h>
#include "../valley.h"
inherit OBJECT;

void create()
{
	::create();
	set_name("mandibles");
	set_id(({"mandibles","tenebrous worm mandibles","worm mandibles","set of mandibles","pair of mandibles"}));
	set_short("A pair of mandibles");
	switch(random(3500)) {
		case 0..999:
			set_long("This set of mandibles is from a creature"+
			" known as the tenebrous worm. The worm is a rather"+
			" large creature and its mandibles are highly valued"+
			" in some places. Unfortunately, this pair has been"+
			" broken and is therefore much less valuable.");
			set_value(500);
			break;
		case 1000..1999:
			set_long("This set of mandibles is from a creature"+
			" known as the tenebrous worm. The worm is a rather"+
			" large creature and its mandibles are highly valued"+
			" in some places. This pair is a small set but should"+
			" still fetch a nice price.");
			set_value(1000);
			break;
		case 2000..2999:
			set_long("This set of mandibles is from a creature"+
			" known as the tenebrous worm. The worm is a rather"+
			" large creature and its mandibles are highly valued"+
			" in some places. This pair is about average size and"+
			" will be worth a fair bit.");
			set_value(2000);
			break;
		case 3000..3500:
			set_long("This set of mandibles is from a creature"+
			" known as the tenebrous worm. The worm is a rather"+
			" large creature and its mandibles are highly valued"+
			" in some places. This pair is fairly large and should"+
			" be worth quite a lot.");
			set_value(3000);
			break;
	}
	set_weight(25);
}
