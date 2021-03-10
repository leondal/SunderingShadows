#include <std.h>
#include "../antioch.h"
inherit BARKEEP;

int CALL;

void create()
{
	::create();
   CALL = 0;
	remove_std_db();
   remove_dbs(({"barkeep","waitress"}));
   remove_random_act_dbs(({"barkeeprandom","waitress"}));
	set_name("Selakin");
	set_short("Selakin, the Eagle's Roost bartender");
	set_id(({"barkeep","bartender","Selakin","selakin"}));
	set_long(
	"Selakin is a man in his mid forties, and still in fine shape though he's"+
	" slowly begun to put on a bit of a beer gut. Straight brown hair falls"+
	" down his back and is kept out of his face in a pony tail. He has a"+
	" well trimmed beard and %^BOLD%^%^BLUE%^dark blue%^RESET%^%^CYAN%^ eyes."+
	" He looks like a man who has been through an awful lot, knows the"+
	" sorrows of the world. He also looks like someone you could talk to"+
   " if you had problems, as most of his customers do. He's wearing a pair"+
	" of brown breeches with a brown cotton tunic, held together by a leather"+
	" belt. Tending bar is his life now, something he enjoys doing, and he"+
	" doesn't stand for any fights in his bar."
	);
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_hd(30,10);
	set_class("fighter");
	set_mlevel("fighter",30);
	set_level(30);
	set_overall_ac(-15);
	set_alignment(1);
	set_max_hp(500);
	set_hp(query_max_hp());
	set_stats("strength",20);
	set_stats("charisma",10);
	set_stats("intelligence",12);
	set_stats("constitution",18);
	set_stats("wisdom",13);
	set_stats("dexterity",15);
	set_exp(10);
	set_currency("silver");
	set_property("swarm",1);
	set_menu(
	({"raspberry tea", "lemonade", "chocolate malt", "blue velvet", "grasshopper", "blackberry wine", "pale ale", "shot of gin"}),
	({"soft drink","soft drink","soft drink","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic"}),
	({ 5, 5, 10, 15, 12, 10, 8, 20 })
	);
	set_my_mess(
	({
	"You drink the cool raspberry tea, the sweet taste is refreshing.",
	"The lemonade has a pleasant tang to it, sweet and sour at once.",
	"The delicious chocolate malt slips slowly down your throat, icey cold and very refreshing.",
	"You gulp down the blue velvet, it is pleasantly cold and has a vanilla"+
	" and raspberry taste to it, along with the kick of some sweet liquor.",
	"The grasshopper has a cool mint taste along with the undercut of hard liquor.",
	"You slowly drink the glass of blackberry wine, it warms your throat as"+
	" the sweet liquid slides down.",
	"You gulp down the mug of pale ale, savouring the aftertaste that stays"+
	" in your mouth.",
	"You drink the shot of gin and it burns its way down your throat.",
	})
	);
	set_your_mess(
	({
	"sips a refreshing raspberry tea.",
	"drinks a glass of lemonade.",
	"slurps down a delicious chocolate malt.",
	"gulps down the blue velvet, savoring the taste.",
	"drinks a minty grasshopper.",
	"slowly drinks a glass of blackberry wine.",
	"gulps down a mug of pale ale.",
	"quickly drinks the shot of gin.",
	})
	);
	set_menu_short(
	({
	"A glass of raspberry tea",
	"A glass of lemonade",
	"A large chocolate malt",
	"Blue velvet",
	"A Grasshopper",
	"A glass of blackberry wine",
	"A mug of pale ale",
	"A shot of gin",
	})
	);
	set_menu_long(
	({
	"%^MAGENTA%^This is a tall glass of tea that has been flavored with raspberry juice.%^RESET%^",
	"%^YELLOW%^This is a glass of tangy lemonade.%^RESET%^",
	"This is a large mug of chocolate malt. It is a mixture of chocolate"+
	" and ice cream, blended to perfection.",
	"%^BOLD%^%^BLUE%^The blue velvet is an exotic drink that is a favorite"+
	" in Antioch. It is made of vanilla ice cream, raspberry juice, and some"+
	" hard liquor that turns it blue. Elite citizens seem to especially prefer"+
	" this drink, it's more like a desert.%^RESET%^",
	"%^BOLD%^%^GREEN%^The grasshopper is a favored drink of hard workers who"+
	" like to splurge. It is made of vodka and mint, with a bit of powder"+
	" added to make it a bright green color, giving the drink its name.%^RESET%^",
	"%^RED%^The blackberry wine is a deep red color. It is common up in the"+
	" mountains where blackberries tend to grow more frequently than grapes."+
	" It has a sweet taste, and excellent bouquet.",
	"This is a mug of a pale ale. It has a light taste and slightly tangy"+
	" aftertaste. It was named for its color, and is the favored ale of Antioch.",
	"This is a shot of gin. It is a potent alcohol that was created by"+
	" Orflack. He brews it using some berries up in the mountains here, and"+
	" he taught Selakin how to make it. It is clear in color and has little"+
	" smell to it."
	})
	);
}

void heart_beat()
{
	object ob, *atkrs;
	int x, CALL;
	if(!objectp(TO)) return;
	atkrs = TO->query_attackers();
	::heart_beat();
	if(atkrs != ({ }) && CALL != 1) {
		call_out("summon_guards",5);
		force_me("yell Help, I'm being attacked! Someone call the guards!");
         CALL = 1;
	}
}

int summon_guards()
{
	object ob;
	tell_room(ETO,"%^BOLD%^Several guards burst into the room.");
	new(MONS+"guard")->move(ETO);
	if(sizeof(TO->query_attackers()) > 1) {
		new(MONS+"guard")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 2) {
		new(MONS+"guard")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 3) {
		new(MONS+"guard")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 4) {
		new(MONS+"guard")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 5) {
		new(MONS+"guard")->move(ETO);
	}
	return 1;
}
