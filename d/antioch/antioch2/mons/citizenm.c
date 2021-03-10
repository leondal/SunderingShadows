#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Jeroidan");
	set_short("Jeroidan, a grumpy old man");
	set_id(({"citizen","man","male","human","grumpy old man","jeroidan","Jeroidan"}));
	set_long(
	"Jeroidan appears to be a grumpy old man who is just trying to enjoy what life"+
	" he has left. His hair is completely silver, and flows down his back. This is"+
	" most probably because he simply hasn't bothered to cut it than any sense of"+
	" style or fashion. His beard is also rather long, but looks as though it gets"+
	" trimmed every other week or so. He is missing a few teeth, and doesn't really"+
	" seem to be interested in talking to you. In fact, you get the impression he'd"+
	" be a lot happier if you'd go away and never come back. For whatever reasons,"+
	" he reminds you of someone you know...."
	);
	set_gender("male");
	set_race("human");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
	set_emotes(3,({
	"Jeroidan glares at you balefully.",
	"The old man rolls over and tries to get some sleep.",
	"The old man begins to snore rather loudly.",
	"Jeroidan clears his throat and points towards the door.",
	"The old man belches rather rudely.",
	"The old man sighs in frustration.",
	}),0);
}
