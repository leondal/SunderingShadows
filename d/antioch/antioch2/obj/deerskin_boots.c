#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("deerskin boots");
	set_short("%^RESET%^%^ORANGE%^Soft deerskin boots%^RESET%^");
	set_id(({"boots","deerskin boots","soft deerskin boots","pair of boots","pair of deerskin boots"}));
	set_long(
	"%^ORANGE%^These are a pair of soft deerskin boots. They have been tanned perfectly,"+
	" and the insides are still lined with the soft hide of the deer to make"+
	" them even more comfortable. The tops have been turned down, showing"+
	" a bit of the hide for style. They lace up in the front and are very"+
	" comfortable, but not good for hiking or adventuring.%^RESET%^"
	);
	set_weight(4);
	set_value(40);
	set_type("clothing");
	set_limbs(({"left foot","right foot"}));
	set_ac(0);
}
