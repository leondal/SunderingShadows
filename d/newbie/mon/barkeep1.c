#include <std.h>
inherit BARKEEP;

void create() {
	::create();
	set_name("Jeraemos");
	set_short("Jeraemos, the bartender");
	set_id(({"barkeep","Jeraemos","jeraemos","bartender"}));
	set_long(
	"Jeraemos is a large burly man and doesn't look like the typical friendly barkeep"+
	" that everyone pours their troubles on. He is definitely business oriented, and"+
	" his famous yarrow ale, clean bar, and good service keep his customers coming"+
	" back each time. His hair is dark and kept cut short and he has weary hazel"+
	" eyes that scan the crowd for any possible trouble. He's usually busy polishing"+
	" glasses or wiping down the bar. You notice a wedding ring on his hand and"+
	" remember someone mentioning that his wife is the one that makes the cherry"+
	" pie that they serve here that's supposed to be so good."
	);
	set_race("human");
	set_body_type("human");
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
	({"yarrow ale","ale","wine","water","apple cider","coffee","cheese","ham","sausage","stew","duck","cherry pie"}),
	({"alcoholic","alcoholic","alcoholic","water","soft drink","caffeine","food","food","food","food","food","food"}),
	({15, 5, 10, 1, 5, 3, 8, 12, 12, 15, 20, 4})
	);
	set_my_mess(
	({
	"The yarrow ale has a smooth, almost sweet taste to it as it slides down your throat.",
	"You gulp down the mug of ale, enjoying its coolness.",
	"You sip the red wine, savoring its flavor.",
	"You drink a glass of water.",
	"The hot apple cider warms your body and soul.",
	"You drink the steaming mug of coffee and feel more awake and alert.",
	"You devour the block of cheese quickly, fortunately it tastes better than it smells.",
	"You eat the large haunch of ham, licking your sticky fingers when you're done.",
	"You eat the large sausage, enjoying its smokey taste.",
	"The bowl of stew is quite good, even if it could have had more meat in it.",
	"You slowly devour the delicious duck, savoring every bite.",
	"The pie is delicious and sweet, but with that wonderful cherry tang to it.",
	})
	);
	set_your_mess(
	({
	"drinks a mug of yarrow ale.",
	"gulps down a mug of frosty ale.",
	"sips a glass of wine.",
	"drinks a glass of water.",
	"drinks a mug of hot apple cider.",
	"drinks a mug of coffee and seems to perk up a bit.",
	"quickly eats a block of cheese.",
	"finishes the haunch of ham and licks sticky fingers clean.",
	"eats a large sausage.",
	"eats an entire bowl of the hot stew.",
	"slowly eats the duck, relishing every bite.",
	"enjoys a slice of cherry pie.",
	})
	);
	set_menu_short(
	({
	"A mug of rich yarrow ale",
	"A mug of frosty ale",
	"A glass of wine",
	"A glass of water",
	"A mug of apple cider",
	"A steaming mug of coffee",
	"A large block of cheese",
	"A big haunch of ham",
	"A large sausage",
	"A bowl of hot stew",
	"A large basted duck",
	"A slice of cherry pie",
	})
	);
	set_menu_long(
	({
	"The yarrow ale is a dark red in color. It's a special brew made by the bartender"+
	" Jeraemos and is exceptionally good ale.",
	"This is a mug of ale that is actually nice and cool.",
	"This is a glass of red wine, nothing too special about it. Elves tend to prefer"+
	" wine with their meals for whatever reasons.",
	"This is a glass of water. It can be refreshing after a long day, but it would"+
	" be rather hard to carry out adventuring with you. Best to just drink it now.",
	"This is a mug full of apple cider, holding the mug you can feel that it is still"+
	" warm. This is a great drink for warming you up on cold nights if you don't want"+
	" to get drunk.",
	"This is a steaming hot mug of coffee. This will wake you up if you're getting"+
	" too sleepy, or maybe have just had one too many drinks.",
	"This is a block of goat's cheese. It smells rather strongly and has a taste that"+
	" you have to 'grow into' but it is somewhat filling.",
	"This large haunch of ham has been slowly roasted over the fire. It has a sweet"+
	" smelling glaze covering it that is getting your fingers sticky.",
	"This large sausage looks like it has perhaps been cooked just a tad bit too"+
	" long. It is still nice and juicy, and seems to be popular among the breakfast"+
	" crowd.",
	"This is a bowl of piping hot stew, you can still see the steam rising up from"+
	" it. There are several chopped vegetables in it, and some chunks of beef. There"+
	" could be more meat to it, but you probably got what you paid for.",
	"This is a nice sized duck that has been basted in a sugar-lemon sauce of some"+
	" sort. It looks tender and delicious, you can't wait to eat it.",
	"This is a slice of cherry pie. The top is criss-crossed with flaky dough and"+
	" there are lots of cherries in it.",
	})
	);
        new("/d/newbie/obj/misc/lpouch.c")->move(TO);
}
