#include <std.h>
#include "../antioch.h"
inherit TOWNSMAN;

void create()
{
	::create();
	set_name("Chirecien");
	set_short("Chirecien, the bank teller");
	set_id(({"Chirecien","bank teller","teller","chirecien"}));
	set_long(
	"Chirecien is a pretty girl in her early twenties. She has long black hair that"+
	" flows down her back and is kept out of her face by a bright yellow ribbon that"+
	" is tied in a bow. Her eyes are misty grey and seem to calmly analyze everything."+
	" She seems pleasant and friendly with the customers, and definitely makes the"+
	" transactions easy for you. After watching her for a time you also realize that"+
	" she is very good at her job. She has an obvious knack for numbers and figures"+
	" and takes only a moment to do complex accounting in her head. She also keeps"+
	" careful record of everything on sheets of paper that are neatly filed away."+
	" You doubt there is much that this girl misses."
	);
	set_gender("female");
	set_race("human");
	set_hd(10,5);
	set_max_hp(100+random(25));
	set_hp(query_max_hp());
	set_alignment(1);
	set_overall_ac(-10);
	set_class("mage");
	set_mlevel("mage",10);
	set_level(10);
	set_stats("intelligence",20);
	set_stats("charisma",16);
	set_stats("wisdom",14);
	set_stats("strength",8);
	set_stats("dexterity",10);
	set_stats("constitution",12);
	set_emotes(1,({
	"Chirecien reties the yellow ribbon that holds her hair back.",
	"Chirecien writes down some figures on a piece of paper.",
	"Chirecien carefully files away the latest transactions.",
	"Chirecien puts some money into the back vault.",
	"Chirecien smiles at the bank guard.",
	}),0);
	set_exp(100);
	set_property("swarm",1);
	set("aggressive",0);
	set_spells(({
	"fireball",
	"web",
	"scorcher",
	"magic missile",
	"burning hands",
	}));
	set_spell_chance(100);
}
