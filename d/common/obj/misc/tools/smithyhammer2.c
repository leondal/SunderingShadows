#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("smithing hammer");
	set_id(({ "hammer", "smithy's hammer" }));
	set_short("%^RESET%^A %^BOLD%^%^RED%^stout %^BOLD%^%^WHITE%^mithril %^BLACK%^smithy's hammer %^RESET%^with an %^RESET%^%^ORANGE%^ironwood handle%^RESET%^");
	set_obvious_short("%^RESET%^A %^BOLD%^%^RED%^stout %^BOLD%^%^WHITE%^mithril %^BLACK%^smithy's hammer %^RESET%^with an %^RESET%^%^ORANGE%^ironwood handle%^RESET%^");
	set_long(
"This is a stout smithy's hammer.  The %^BOLD%^%^WHITE%^mithril %^RESET%^head is about five inches long and two inches thick and has been forged with a flat facing on one side and a round ball peen on the other.  The handle is carved out of stout %^RESET%^%^ORANGE%^ironwood %^RESET%^and is a little over a foot long. "
"Symbols of %^YELLOW%^Grumbar%^RESET%^, God of Crafters are etched into the hammer.  A %^BOLD%^%^RED%^heavy %^RESET%^%^ORANGE%^leather grip %^RESET%^has been fastened midshaft on the handle to allow for a firmer grip."
	);
	set_weight(4);
	set_value(250);
}


