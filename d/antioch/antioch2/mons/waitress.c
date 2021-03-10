#include <std.h>
#include "../antioch.h"
inherit BARKEEP;

int CALL;

void create()
{
	::create();
	CALL = 0;
	remove_std_db();
	remove_dbs(({ "barkeep", "waitress" }));
	remove_random_act_dbs(({ "barkeeprandom", "waitress" }));
	add_dbs(({ "edandra" }));
	set_name("Edandra");
	set_short("Edandra, waitress of the White Dragon Inn");
	set_id(({ "waitress", "edandra", "Edandra" }));
	set_long(
		"Edandra is a young woman working as a waitress here at the White Dragon" +
		" Inn. She is wearing a pretty black dress with a white apron wrapped" +
		" around her waist. Brown hair tumbles down her back and is kept out of" +
		" her face by a white bow. She has friendly blue eyes and a smooth" +
		" complexion. She carries a menu in one hand and stands ready to serve" +
		" you."
		);
	set_gender("female");
	set_race("human");
	set_body_type("human");
	set_hd(30, 8);
	set_class("fighter");
	set_class("mage");
	set_mlevel("mage", 30);
	set_mlevel("fighter", 30);
	set_level(30);
	set_max_hp(250 + random(50));
	set_hp(query_max_hp());
	set_overall_ac(-10);
	set_alignment(1);
	set("aggressive", 0);
	set_stats("intelligence", 18);
	set_stats("strength", 15);
	set_stats("charisma", 16);
	set_stats("wisdom", 14);
	set_stats("dexterity", 17);
	set_stats("constitution", 12);
	set_mob_magic_resistance("low");
	set_exp(100);
	set_max_level(20);
	set_spells(({
		"meteor swarm",
		"monster summoning vii",
		"chain lightning",
	}));
	set_spell_chance(100);
	set_currency("silver");
	set_menu(
		({ "wild goose", "rack of lamb", "beef stew", "split pea soup", "bread", "apple pie", "spiced custard", "chocolate strawberries", "water", "mint tea", "red wine", "ale" }),
		({ "food", "food", "food", "food", "food", "food", "food", "food", "water", "soft drink", "alcoholic", "alcoholic" }),
		({ 50, 45, 30, 15, 5, 20, 10, 12, 1, 3, 5, 10 })
		);
	set_my_mess(
		({
		"You eat the wild goose, savoring the delicious herb seasonings that were used.",
		"You devour the juicy rack of lamb, licking your greasy fingers when you're done.",
		"The stew is filled with tender beef and well seasoned potatoes.",
		"You enjoy the hot split pea soup, it is well seasoned and has been cooked to perfection.",
		"The bread is still hot from the oven and is dripping with warm butter.",
		"The slice of apple pie is delicously sweet and it is still warm.",
		"You can taste the cinnamon and nutmeg in the spiced custard, it is very thick and slides down your throat.",
		"The strawberries are sweet and cool, with just the right amount of chocolate for flavor while not covering up the strawberry tang.",
		"You enjoy a cool glass of water.",
		"You slowly sip the cool mint tea.",
		"You enjoy the rich taste of the red wine.",
		"The mug of ale slides smoothly down your throat.",
	})
		);
	set_your_mess(
		({
		"savors the delicious flavor of the seasoned wild goose.",
		"devours the rack of lamb, licking each finger to get the last bit of sauce.",
		"slowly eats stew, savoring the taste of the tender beef.",
		"enjoys a bowl of split pea soup.",
		"eats a hot piece of bread that is dripping with butter.",
		"enjoys a slice of delicious hot apple pie.",
		"eats the spiced custard, scraping the bowl for the last spoon full.",
		"eats several chocolate covered strawberries.",
		"drinks a glass of water.",
		"drinks down a glass of cool mint tea.",
		"enjoys a glass of red wine.",
		"gulps down a mug of ale.",
	})
		);
	set_menu_short(
		({
		"Wild goose seasoned with herbs",
		"Rack of lamb with mint sauce",
		"Beef and potato stew",
		"A bowl of split pea soup",
		"Bread and butter",
		"Hot apple pie",
		"Spiced custard",
		"%^BOLD%^%^RED%^Several large %^BLACK%^chocolate%^RED%^ strawberries%^RESET%^",
		"A glass of water",
		"A glass of mint tea",
		"A glass of red wine",
		"A mug of ale",
	})
		);
	set_menu_long(
		({
		"This wild goose has been cooked slowly over a spitfire grill and" +
		" carefully seasoned with many types of herbs that add delicious" +
		" flavor to it.",
		"The rack of lamb has been slowly roasted and basted with a cool" +
		" mint sauce that contrasts nicely with the lamb.",
		"This is a bowl of steaming beef and potato stew. It has several other" +
		" vegetables and herbs mixed in, and lots of beef and potatoes.",
		"This is a bowl of split pea soup that has been cooked for long hours" +
		" on the stove to be smooth and delicious.",
		"This large slice of bread is still hot from the oven and is dripping" +
		" with warm butter.",
		"This is a generous slice of apple pie that is still warm from the oven." +
		" You can smell the wonderful aroma of the cooked apples, mixed with a" +
		" bit of cinnamon.",
		"This is a cup of spiced custard. A dollop of sweat cream has been placed" +
		" on top, and sprinkled with a bit of extra cinnamon. It looks rich and" +
		" thick, and you can smell the nutmeg.",
		"The little plate holds several large strawberries that have been dipped" +
		" in chocolate. The strawberries appear perfectly ripe, and the layer" +
		" of chocolate is just thick enough to give a nice flavor without" +
		" covering the strawberry taste.",
		"This is a cool glass of water.",
		"This is a tall glass of mint tea. A few mint sprigs have been placed on" +
		" the top for looks as well as additional flavor.",
		"This is a glass of red wine. You can smell its thick, sweet flavor.",
		"This is a mug of ale, foam covers the top of the glass, almost spilling" +
		" over.",
	})
		);
}

void heart_beat()
{
	object ob, *atkrs;
//	int x, CALL;
	int x;
	if (!objectp(TO)) return;
	atkrs = TO->query_attackers();
	::heart_beat();
	if (atkrs != ({ }) && CALL != 1) {
		call_out("summon_guards", 5);
		force_me("yell Help, I'm being attacked! Someone call the guards!");
		CALL = 1;
	}
}

int summon_guards()
{
	object ob;
	tell_room(ETO, "%^BOLD%^Several guards burst into the room.");
	new(MONS + "guard")->move(ETO);
	if (sizeof(TO->query_attackers()) > 1) {
		new(MONS + "guard")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 2) {
		new(MONS + "guard")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 3) {
		new(MONS + "guard")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 4) {
		new(MONS + "guard")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 5) {
		new(MONS + "guard")->move(ETO);
	}
	return 1;
}
