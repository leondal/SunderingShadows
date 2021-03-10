#include <std.h>
#include "../antioch.h"
inherit MONSTER;

int head_home;

void create()
{
	::create();
	set_name("young lady");
	set_short("A young lady");
	set_id(({"lady","young lady","citizen","maiden","maid","young maid","young maiden","fair maid","fair maiden"}));
	set_long(
	"This young lady is one of the fair citizens of Antioch. She looks to be"+
	" about sixteen years old, and is wondering the streets in search of a"+
	" good bargain. She is wearing a pretty dress with matching sandals and a"+
	" ribbon ties back part of her hair. She has a smile on her face and seems"+
	" happy."
	);
	set_gender("female");
	set_race("human");
	set_body_type("humanoid");
	set_hd(1,5);
	set_exp(1);
	set_emotes(10,({
	"The young lady hums merrily to herself.",
	"The young maiden straightens out her dress.",
	"The young lady smiles pleasantly at you.",
	"The young lady runs her fingers through her hair.",	
	}),0);
	command("message in walks in with a smile on her face.");
   command("message out wanders off to the");
	command("speech speak with a lovely voice");
	set_speed(9);
	call_out("head_home",400+random(100));
}

int head_home()
{
	tell_room(ETO,"%^BOLD%^%^GREEN%^The young lady departs back to her home.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
