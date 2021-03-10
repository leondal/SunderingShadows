#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/club.c";

void create()
{
	::create();
	set_name("club");
	set_short("A large club");
	set_id(({"club","large club"}));
	set_long(
	"This is a very large, knarled wooden club."+
	" It looks like it comes from the trunk of a"+
	" large tree. It's been worn with age, the"+
	" handle having slight grooves to allow a good"+
	" grasp for a very large hand."
	);
	set_weight(3);
	set_size(3);
	set_value(4);
	set_wc(1,6);
	set_large_wc(1,3);
	set_type("bludgeoning");
	set_prof_type("large club");
}
