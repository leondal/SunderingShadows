#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Cardo");
	set_short("Cardo, a citizen of Antioch");
	set_id(({"citizen","man","cardo","Cardo","male","human"}));
	set_long(
	"Cardo is a rather normal looking man. Nothing in particular stands out about"+
	" him. He has brown hair, brown eyes, and tanned skin from being out in the"+
	" sun so much. He looks a little lonely, and could probably use a long bath."+
	" This man is obviously single, and it isn't too hard to see why."
	);
	set_gender("male");
	set_race("human");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
}
