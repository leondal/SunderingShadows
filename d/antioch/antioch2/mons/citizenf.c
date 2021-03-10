#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Thoiria");
	set_short("Thoiria, a citizen of Antioch");
	set_id(({"citizen","female","woman","human","thoiria","Thoiria"}));
	set_long(
	"Thoiria is in her mid to late twenties. Although she is still young, she has"+
	" obviously been through much. There are scars that criss-cross her neck, and"+
	" despite the long-sleeved dresses she wears you can see more scars marking her"+
	" arms. There is a deep sorrow in her grey eyes still, but she seems like she"+
	" is trying to get over it and put the past behind her. She has a wedding band"+
	" on that seems rather new. Perhaps her new life will allow her to finally forget"+
	" whatever past it is that plagues her."
	);
	set_gender("female");
	set_race("human");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
}
