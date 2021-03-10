#include <std.h>
inherit BARKEEP;


void create() {
	::create();
	remove_std_db();
   remove_dbs(({"barkeep","waitress"}));
   remove_random_act_dbs(({"barkeeprandom","waitress"}));
	set_name("Stanshar");
	set_short("Stanshar, waiter of the Seneca Restaurant");
	set_id(({"waiter","stanshar","Stanshar"}));
	set_long(
	"Stanshar looks to be in his late twenties and very fit.  His biceps bulge "
	"below the rolled up short sleeves of his dark blue denim shirt that is open "
	"about halfway down revealing a muscular chest.  He has thick, dark brown, "
	"wavy hair cut to just above his shoulders and a bit of stubble on his chin "
	"that accentuates a square, ruggedly handsome jawline and deep blue eyes.  "
	"The shirt tucks into a pair of dark brown pants that have to stretch a "
	"little to fit his muscular thighs.  His soft leather boots allow him to "
	"navigate the tables rather unobtrusively as he serves the patrons and "
   "generally keeps the bar clean and everything in order."
	);
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_hd(30,8);
	set_class("fighter");
	set_class("mage");
	set_mlevel("mage",30);
	set_mlevel("fighter",30);
	set_level(30);
	set_max_hp(250+random(50));
	set_hp(query_max_hp());
	set_overall_ac(-10);
	set_alignment(2);
	set("aggressive",0);
	set_stats("intelligence",18);
	set_stats("strength",19);
	set_stats("charisma",16);
	set_stats("wisdom",14);
	set_stats("dexterity",17);
	set_stats("constitution",16);
	set_mob_magic_resistance("average");
	set_exp(500);
	set_max_level(30);
	set_spells(({ "magic missile", "power word stun", "magic missile" }));
	set_spell_chance(100);
	set_currency("gold");
	set_menu(
   ({"wild boar","beef stew","potato soup","toasted bread","banana nut bread","water","coffee","dark ale","chocolate cake"}),
   ({"food","food","food","food","food","water","caffeine","alcoholic", "food"}),
   ({50, 45, 30, 15, 20, 5, 10, 20, 25})
	);
	set_my_mess( ({
	 "You eat the somewhat chewy haunch of wild boar, licking your greasy fingers "
      "when you finish.",
	 "The stew is a thick broth with chunks of meat, potatoes, and carrots.",
	 "The soup is thick and creamy with chunks of potatoes, carrots, and celery.",
	 "The bread has been toasted on a griddle and lightly buttered.",
	 "You can taste the banana in the cake-like bread that has chunks of walnuts "
	   "generously mixed in to add a flavor contrast.",
	 "You enjoy a cool glass of water that seems to have been drawn from a spring.",
	 "You sip the hot coffee carefully.  It's quite hot and very strong.",
	 "The mug of ale is smooth and well aged.",
   "The chocolate cake is rich and sweet, you savor every bite.",
	}) );
	set_your_mess(	({
	 "seems to work at chewing the haunch of wild boar.",
	 "slowly eats the stew, spooning up the delicious-looking chunks of meat and "
      "vegetables.",
	 "seems to be enjoying the bowl of potato soup.",
	 "nibbles at a piece of toasted bread that is lightly buttered.",
	 "picks a few pieces of walnut out of the banana nut bread and then eats the "
	   "rest quickly.",
	 "drinks a glass of water.",
	 "sips at the steaming coffee and blinks as the caffeine takes effect.",
	 "slurps down the mug of ale.",
   "slowly eats every bite of the chocolate cake.",
	}) );
	set_menu_short( ({
	 "Roasted haunch of wild boar",
	 "Beef and vegetable stew",
	 "A cup of potato soup",
	 "Toasted bread",
	 "Banana nut bread",
	 "A glass of water",
	 "A cup of strong coffee",
	 "A mug of dark ale",
    "A slice of chocolate cake",
	}) );
	set_menu_long( ({
	"This haunch of wild boar has been cooked over an open fire.  It's somewhat "
	  "chewy and greasy, but quite flavorful.",
	"This is a bowl of beef and vegetable stew in a rich broth.",
	"The bowl of potato soup is rich and creamy with nice chunks of carrots "
	  "and celery mixed in for extra flavor and color.",
	"A large slice of bread that has been toasted on a griddle and lightly "
	  "buttered.",
	"You can smell the bananas and walnuts in this cake-like bread.",
	"This is a cool glass of water.",
	"The dark, obviously strong coffee steams in the cup.",
	"This is a mug of dark ale with a bit of foam on top.",
   "This is a large slice of chocolate cake. The cake has two layers, with chocolate icing spread between them"+
   " and more icing that covers the back and top of the slice. The chocolate is dark and rich and it smells"+
   " so good it makes your mouth water.",
	}) );
}

