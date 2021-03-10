#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Jarelin");
	set_short("Jarelin, a citizen of Antioch");
	set_id(({"citizen","man","male","human","Jarelin","jarelin"}));
	set_long(
	"Jarelin looks like he is in good shape. He has sandy blonde hair that is kept"+
	" carefully cut, and he is smooth shaven. His hazel eyes seem to have an inner"+
	" sparkle to them and there is a slight smile tugging at the corners of his lips."+
	" You notice a wedding band on his finger. He can't be much older than twenty,"+
	" so he is probably newly married."
	);
	set_gender("male");
	set_race("human");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
}
