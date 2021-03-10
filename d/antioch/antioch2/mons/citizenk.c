#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Bricalya");
	set_short("Bricalya, a lovely house wife");
	set_id(({"citizen","half-elf","female","woman","Bricalya","bricalya","house wife","wife"}));
	set_long(
	"Bricalya is an attractive young woman with long strawberry blonde tresses and"+
	" warm brown eyes. She seems to have an ever-present smile on her rosey lips"+
	" that is almost contagious. She is obviously rather young, even for a half-elf,"+
	" but she has a wedding ring on her finger. She looks as though she doesn't"+
	" have a care in the world."
	);
	set_gender("female");
	set_race("half-elf");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
}
