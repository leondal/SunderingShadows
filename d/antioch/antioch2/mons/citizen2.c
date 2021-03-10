#include <std.h>
#include "../antioch.h"
inherit MONSTER;

int head_home;

void create()
{
	::create();
	set_name("woman");
	set_short("A woman out shopping");
	set_id(({"woman","woman out shopping","lady","citizen"}));
	set_long(
	"This woman is busy browsing through the different stores around Antioch,"+
	" trying to find the best things to buy. She has a list in one hand and"+
	" already a bag full of purchases in the other. She is wearing a long"+
	" dress and some comfortable shoes, a pair of glasses is on her face. Her"+
	" hair has a few streaks of gray in it, and has been pulled back into a"+
	" practical bun. She is probably just in her late thirties, but after"+
	" everything that the citizens of Antioch have been through, it's not"+
   " surprising that she has some gray streaks already."
	);
	set_race("human");
	set_gender("female");
	set_body_type("humanoid");
	set_hd(1,5);
	set_exp(1);
	set_speed(10);
	set_emotes(10,({
	"The woman pushes the glasses back on her face.",
	"The woman checks over her list to see what she still needs.",
	"The woman adjusts her bag of packages to her other hand.",
	"The woman gathers up her skirt and prepares to move on.",
	}),0);
	command("message in walks in looking for a good deal.");
	command("message out looks for a better bargain to the");
	command("speech speak with common sense");
	call_out("head_home",400+random(100));
}

int head_home()
{
	tell_room(ETO,"%^BOLD%^%^GREEN%^The woman grows tired of shopping and heads"+
	" back to her house with her purchases.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
