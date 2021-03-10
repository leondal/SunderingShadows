#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Reswena");
	set_short("Reswena, a stately woman");
	set_id(({"citizen","human","woman","female","Reswena","reswena"}));
	set_long(
	"Reswena is a stately woman in her late thirties. She dresses in a rather"+
	" reserved manner, but keeps up with the latest fashions. Her black hair"+
	" is kept back in a tight braid, and her blue eyes are rather cool. She seems"+
	" as though she tries to distance herself from life. She probably does a good"+
	" job of it, too. A rather expensive wedding ring is on one finger, and several"+
	" other expensive rings are on her other fingers."
	);
	set_gender("female");
	set_race("human");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
}
