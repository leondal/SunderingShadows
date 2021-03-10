#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Silath");
	set_short("Silath, a citizen of Antioch");
	set_id(({"citizen","silath","Silath","human","male","man"}));
	set_long(
	"Silath is probably in his mid to late thirties. His dark black hair is peppered"+
	" with streaks of gray, and the scars on his face show he has not lead the"+
	" easiest of lives. Despite the hardships, he does not seem to have given up,"+
	" he seems happy and satisfied with his life. He has a wedding band on one hand"+
	" that he absently touches now and then. He seems like a kind person."
	);
	set_gender("male");
	set_race("human");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
}
