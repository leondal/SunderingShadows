#include <std.h>
#include "../antioch.h"
inherit STABLE;

void create()
{
	::create();
	set_short("Antioch Stables");
	set_long(
	"This is part of the Antioch Stables. Horses are kept in the stalls"+
	" around you. The stalls fill three quarters of the room, only"+
	" the southern passage way to the rest of the stable is free."+
	" They look to be kept very clean."
	);
	set_smell("default","You can smell the sweat of horses mingled"+
	" with hay.");
	set_listen("default","You can hear the animals stomping around in"+
	" their stalls.");
	set_items(([
	"sign" : "There is a little sign here for you to read.",
	]));
	set_exits(([
	"south" : ROOMS+"stables",
	]));
	set_animal(({"mare","stallion","gelding","charger","pony"}),({OBJH+"mare",OBJH+"stallion",OBJH+"gelding",OBJH+"charger",OBJH+"pony"}));
	set_animal_price(({"mare","stallion","gelding","charger","pony"}),({50, 150, 75, 200, 80}));
}

void init()
{
	::init();
	add_action("read_sign","read");
}

int read_sign(string str)
{
	if(!present("stable hand")) {
		write("Someone appears to have knocked over the sign and it"+
		" is covered in dirt and can't be read.\n");
		return 1;
	}
	else if(str == "sign") {
		write("%^BOLD%^This sign tells which horses are for sale.%^RESET%^\n\n"+
		"		A gentle gray mare			50 gold\n"+
		"		%^BOLD%^%^RED%^A fiery %^BLACK%^black%^RED%^ stallion%^RESET%^		150 gold\n"+
		"		%^BOLD%^A white charger%^RESET%^		200 gold\n"+
		"		%^ORANGE%^A shaggy mountain pony%^RESET%^	80 gold\n"+
		"		%^YELLOW%^A dun colored gelding%^RESET%^		75 gold\n"+
		"You can buy whichever horse you want, though the mountain"+
		" pony can only be ridden by children or very small people.\n");
		say(""+TP->query_cap_name()+" reads a sign.");
		return 1;
	}
}

void reset()
{
	object ob;

	::reset();
	if(present("stable hand")) {
		ob = present("stable hand");
		ob->set_long("This is a young stable boy of about fourteen"+
		" years in age. He has spent his entire life around horses"+
		" and knows how to handle them and care for them very well."+
		" His face and hands are a little dirty, probably from mucking"+
		" out the stalls. He's wearing a long sleeved blue cotton"+
		" shirt with numerous grass stains on it and some brown leather"+
		" britches that are quite worn. A pair of muddy looking brown"+
		" shoes cover his feet and a cap keeps his hair out of his"+
		" face.");
		ob->set_short("A young stable boy");
		ob->set_id(({"stable boy","young stable boy","stable hand","boy","young boy","stablehand"}));
		ob->set_gender("male");
		ob->set_race("human");
		ob->set_name("stable boy");
		ob->set_body_type("human");
	}
}
		