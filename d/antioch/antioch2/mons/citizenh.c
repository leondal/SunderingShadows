#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Elares");
	set_short("Elares, a well to do man");
	set_id(({"citizen","male","human","man","Elares","elares"}));
	set_long(
	"Elares is an older man who looks like he is fairly well off. His auburn hair"+
	" is slightly frosted with the first touches of gray. He keeps his beard and"+
	" mustache neatly trimmed. His hands are clean and soft, he's probably never"+
	" had to work very much. An expensive wedding band is on one hand. He does"+
	" walk with a slight limp, so something obviously must have happened to his"+
	" leg at one point in time. He is well dressed and composed, and even a bit"+
	" on the handsome side."
	);
	set_gender("male");
	set_race("human");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
}
