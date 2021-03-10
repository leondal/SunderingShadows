#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Kera");
	set_short("Kera, a pretty house wife");
	set_id(({"citizen","female","woman","house wife","wife","kera","Kera","human"}));
	set_long(
	"Kera is a young woman, probably about sixteen years old. Her cheeks have a"+
	" naturally rosey glow to them, and her lips are also a natural red. Long blonde"+
	" hair falls in waves down her back. She blushes as she catches you looking at"+
	" her and turns her pretty hazel eyes away. You notice a wedding band on one of"+
	" her long slender fingers. Her husband is definitely a lucky man."
	);
	set_gender("female");
	set_race("human");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
}
