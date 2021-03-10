#include <std.h>
#include "../valley.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("rope belt");
	set_id(({"belt","robe belt"}));
	set_short("Rope belt");
	set_long(
	"This belt is made out of coarse silk. Two thick strands"+
	" have been twisted around eachother and are tied"+
	" together on the side, allowing some rope to hang down."
	);
	set_type("clothing");
	set_limbs(({"waist"}));
	set_weight(2);
	set_size(2);
	set_value(1);
}
