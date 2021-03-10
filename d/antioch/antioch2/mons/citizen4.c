#include <std.h>
#include "../antioch.h"
inherit MONSTER;

int head_home;

void create()
{
	::create();
	set_name("young man");
	set_short("A studious young man");
	set_id(({"man","young man","studious man","studious young man","citizen"}));
	set_long(
	"This young man has his nose buried in a book. He is probably about"+
	" eighteen years old, and already has to wear glasses, probaby due to the"+
	" strain on his eyes from reading all the time. He is dressed rather"+
	" simply in a robe with some leggings on beneath. His hair is kept well"+
	" combed and cut short. The book he is reading appears to be one about"+
	" magic, but it is hard to tell for sure because he jealously guards it."
	);
	set_gender("male");
	set_race("human");
	set_body_type("humanoid");
	set_hd(2,10);
	set_class("mage");
	set_mlevel("mage",1);
	set_exp(10);
	set_spells(({"magic missile"}));
	set_spell_chance(100);
	set_speed(50);
	set_emotes(10,({
	"The young man slowly turns a page.",
	"The young man pauses to wipe off his glasses, then goes back to reading.",
	"The young man seems lost in thought for a moment.",
	"The young man takes out a piece of paper and quickly jots something down.",
	"The young man completely ignores you.",
	}),0);
	command("message in wanders in with his nose in a book.");
	command("message out departs in search of silence to the");
	command("speech speak in a bored tone");
	call_out("head_home",400+random(100));
}

int head_home()
{
	tell_room(ETO,"%^BOLD%^%^GREEN%^With a sigh, the young man departs back to"+
	" his house.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}

