#include <std.h>
#include "../antioch.h"
inherit MONSTER;

int head_home;

void create()
{
	::create();
	set_name("boy");
	set_short("A rambunctious little boy");
	set_id(({"boy","little boy","rambunctious boy","rambunctious little boy","citizen"}));
	set_long(
   "This little boy has apparently been allowed to wander off by himself and"+
	" roam the streets. He is perhaps ten years old, and looks as though he"+
	" is having an incredible amount of fun. He has already managed to dirty"+
	" his trousers and shirt, and dirt is smeared across his face. He's most"+
	" likely been playing in the stables again, and will undoubtedly have to"+
	" clean up before his mother sees him."
	);
	set_gender("male");
	set_race("human");
	set_body_type("humanoid");
	set_hd(1,5);
	set_speed(8);
	set_exp(1);
	set_emotes(10,({
	"The little boy skips around you in circles.",
	"The little boy bends down to tie his shoe.",
	"The little boy half-heartedly attempts to wipe some of the dirt off his face.",
	"The little boy takes off in a fast sprint.",	
	}),0);
	command("message in skips in merrily.");
	command("message out runs off to the");
	command("speech say in an excited tone");
	call_out("head_home",400+random(100));
}

int head_home()
{
	tell_room(ETO,"%^BOLD%^%^GREEN%^The little boy runs off to clean up before"+
	" his mother sees him.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
