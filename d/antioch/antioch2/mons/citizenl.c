#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Galilacan");
	set_short("Galilacan, a citizen of Antioch");
	set_id(({"citizen","half-elf","male","man","Galilacan","galilacan"}));
	set_long(
	"Galilacan is a kindly looking man. Although he appears to be young, it is hard"+
	" to tell what ages half-elves really are, and he moves about rather slowly."+
	" Long blonde hair falls down his back, partially covering his slightly pointed"+
	" ears. He most definitely takes after his elven heritage, with delicate features"+
	" and slender body. His aqua eyes shine brightly with a passion for life. Even"+
	" though he appears to be alone, he doesn't seem to be unhappy. Instead he"+
	" immerses himself in the life around him."
	);
	set_gender("male");
	set_race("half-elf");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
}
