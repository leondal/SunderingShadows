inherit "/d/common/obj/armour/hide.c";

/* changing to inherit the /d/common file (let's zap this and make the ones that use it all go direct eventually *Styx* 12/24/03
#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("hide");
	set_short("A suit of hide armor");
	set_id(({"hide","armor","hide armor","armour"}));
	set_long(
	"This armor has been prepared from the thick hide of some creature and"+
	" has been double layered for protection.  The hide has been boiled to"+
	" to toughen it, which also makes it stiff and harder to move in. "
	);
	set_weight(30);
	set_value(15);
	set_ac(4);
	set_type("leather");
	set_limbs(({"torso"}));
}
*/