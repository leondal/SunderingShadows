#include <std.h>
inherit BARKEEP;

void create() {
	::create();
	set_name("Olerraf");
	set_short("Olerraf, the bartender");
	set_body_type("humanoid");
	set_id(({"barkeep","Olerraf","olerraf","bartender"}));
	set_long(
	"Olerraf is a very large and rather jolly man. His belly is large from eating"+
	" and drinking all that he wants, and he could never really be described as"+
	" handsome even if he lost the weight. He seems happy enough, however, with a"+
	" smile almost always on his face. He enjoys running the Dancing Ogre and loves"+
	" to have the place packed with adventurers. You can often find him at one of"+
	" the tables, finding out about the latest adventures that he can then relate"+
	" to his other customers."
	);
	set_race("human");
	set_gender("male");
	set_hd(19,1);
	set("aggressive",0);
	add_money("gold",random(100));
	set_alignment(8);
	set_max_hp(100);
	set_hp(100);
	set_exp(10);
	remove_std_db();
        add_dbs(({"barkeep"}));
	set_currency("silver");
	set_menu(
	({"water","tea","soda","mulled wine","spiced wine","ale","bread","stew","pork chops","ribs","pot roast","peach cobbler"}),
	({"water","water","soft drink","alcoholic","alcoholic","alcoholic","food","food","food","food","food","food"}),
	({1, 2, 3, 7, 10, 5, 8, 15, 20, 20, 25, 4}),
	);
	set_my_mess(
	({
	"You drink a glass of water.",
	"You drink a refreshing glass of tea and munch the sprig of mint.",
	"The bubbles tickle your throat as you drink the soda.",
	"You drink the mulled wine, enjoying its warmth.",
	"You sip the spiced wine, savoring the rich flavor.",
	"You gulp down the mug of ale.",
	"You eat the buttered bread, licking off your fingers when you're done.",
	"You eat the thick stew, noting that the mystery meat isn't half-bad.",
	"You devour the plate full of hot pork chops, they're quite filling.",
	"You eat the barbeque ribs, making a complete mess in the process.",
	"The pot roast is delicious and tender, practically falling apart in your mouth.",
	"The peach cobbler tastes as good as it looks and you enjoy every last bite.",
	})
	);
	set_your_mess(
	({
	"drinks a glass of water.",
	"drinks a glass of tea and munches on a sprig of mint.",
	"seems to enjoy the soda.",
	"drinks a mug of mulled wine.",
	"savors a glass of spiced wine.",
	"gulps down a mug of ale.",
	"eats a large piece of buttered bread.",
	"eats a bowl of thick stew.",
	"eats an entire plate of pork chops.",
	"manages to make a huge mess while eating the ribs.",
	"enjoys the large pot roast.",
	"devours the peach cobbler.",
	})
	);
	set_menu_short(
	({
	"A glass of water",
	"A glass of cool tea",
	"A tall bubbling drink",
	"A mug of mulled wine",
	"A glass of spiced wine",
	"A mug of ale",
	"A thick slice of buttered bread",
	"A bowl of thick stew",
	"A plate full of pork chops",
	"A plate full of juicy ribs",
	"A large pot roast",
	"A serving of peach cobbler",
	})
	);
	set_menu_long(
	({
	"This is a glass of water. It can be refreshing after a long day, but it would"+
	" be rather hard to carry out adventuring with you. Best to just drink it now.",
	"This is a glass of lemon-mint tea that is refreshingly cool. There is even a"+
	" sprig of mint in the glass, helps keep your breath fresh.",
	"This is a tall glass of clear bubbling liquid. The bartender calls it a 'soda'"+
	" and it seems to be quite popular.",
	"This is a warm glass of mulled wine, nice to sip by the fire side and relax"+
	" after a hard day's work. It has been watered down so as not to get you drunk"+
	" very fast.",
	"This is a glass of fine spiced wine. It is a very deep reddish-purple color,"+
	" almost black. It has a wonderful aroma to it.",
	"This is a mug of ale. Ale is obviously not the specialty of this bar, and you"+
	" have to wonder just how long this has been sitting in its keg.",
	"This is a thick slice of hot bread that is dripping with butter. Not too filling"+
	" on its own, good for a snack or with a bowl of stew.",
	"This is a very thick stew. It has some vegetables in it, you can make out the"+
	" carrots and potatoes quite easily, along with some other green vegetables that"+
	" are probably supposed to be good for you. The meat is, well, you'd rather just"+
	" think of it as mystery meat and try not to figure out what kind of animal it"+
	" came from.",
	"This is a plate full of sizzling hot pork chops. They've obviously been taken"+
	" right off the grill and are good and juicy.",
	"This plate is piled high with juicy ribs, smeared in barbeque sauce. They look"+
	" great, and you can't wait to sink your teeth into them.",
	"This is a large pot roast that has been baking in the oven until it was"+
	" perfectly tender. Some carrots and potatoes are on the plate around it, but"+
	" this looks like a meal that could fill up almost anyone!",
	"The peach cobbler smells deliciously sweet. The crust is golden and flaky and"+
	" you can see the sliced peaches inside.",
	})
	);
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland
}
