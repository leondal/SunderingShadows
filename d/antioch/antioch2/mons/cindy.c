#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Cindy");
   set_id(({"cindy","Cindy","vendor","little girl","young girl","cute girl","child","girl"}));
   set_short("Cindy, a cute little girl");
	set_long(
	"Cindy is a cute little girl, probably about nine years old. She"+
	" has golden curls that hang down to about the middle of her"+
	" back and they are tied back with a pretty blue ribbon. Her"+
	" dress is blue and white, though looks rather worn from all the"+
	" playing she likes to do. She is sitting on the ground here"+
	" next to a box of kittens that she seems to be watching over."+
	" There is a sign next to the box that Cindy has apparently"+
	" scrawled on, telling what types of kittens there are."
	);
	set_hd(5,2);
	set_exp(0);
	set_max_hp(20);
	set_hp(query_max_hp());
	set_gender("female");
	set_race("human");
	set_body_type("human");
	set_class("fighter");
	set_mlevel("fighter",5);
	set_overall_ac(6);
	set_stats("charisma",17);
	set_stats("dexterity",18);
	set_stats("intelligence",11);
	set_stats("strength",6);
	set_stats("wisdom",9);
	set_stats("constitution",10);
	set_emotes(3,({
	"Cindy plays with her kittens.",
	"Cindy twirls her hair around a finger.",
	"Cindy gives the kittens a bit of cheese.",
	"Cindy giggles merrily.",
	}),0);
}

void init()
{
	::init();
	TO->force_me("speech say in girlish tones");
} 

void heart_beat()
{
	::heart_beat();
	if(!random(50)) {
		switch(random(7)) {
			case 0:
				force_me("say Do you want to buy a kitten? They're"+
				" soooo cute!");
				break;
			case 1:
				force_me("say I need to find these kittens a good"+
				" home.");
				break;
			case 2:
				force_me("say I don't see how anyone could not like"+
				" kittens. They're so much better than dogs as a pet!");
				break;	
			case 3:
				force_me("say Their mamma wondered into the woods"+
				" and hasn't come back, so I'm taking care of them for"+
				" now.");
				break;
			case 4:
				force_me("say If you can think of anyone who would"+
				" like a kitten, please tell them about me.");
				break;
			case 5:
				force_me("say I just know you want a kitten!");
				break;
			case 6:
				force_me("say There are all different types of"+
				" kittens here, I'm sure there's one that you'd like.");
				break;
		}
	}
}

