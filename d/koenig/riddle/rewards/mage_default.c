//mage_default.c - reward for Riddle Quest.  Coded by Circe 2/7/04
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
        set_name("silky gray robe");
	set_id(({ "robe", "gray robe","silk robe","silky gray robe" }));
	set_short("A silky gray robe");
	set_long(
@CIRCE
%^BOLD%^%^BLACK%^This robe is of simple make, flowing from the shoulders in pleats all the way to the wearer's ankles.  It may be gathered at the waist with a belt to make it a bit more flattering.  Despite the simple appearance, the robe is made of the highest quality gray silk that feels soft to the touch.
CIRCE
	);
}
