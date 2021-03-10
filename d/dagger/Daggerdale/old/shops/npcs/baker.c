#include <std.h>
inherit BARKEEP;

void create()
{
   ::create();
   remove_std_db();
   remove_dbs(({"barkeep","waitress"}));
   remove_random_act_dbs(({"barkeeprandom","waitress"}));
   set_name("Kevyn");
   set_short("Kevyn, a friendly baker");
   set_id(({"baker","Kevyn","kevyn","friendly baker"}));
   set_long("Kevyn is a large and friendly looking man who apparently"+
   " enjoys the good food he serves. He wears an apron covered in flour"+
   " and sugar over simple workmans pants. He is probably in his late"+
   " thirties and has already started to go bald up front. His brown"+
   " hair is rather thin and kept short and he has warm brown eyes."+
   " He usually has a smile on his face and seems ready to get you"+
   " any pastry or bread that you might want.");
   set_race("human");
   set_gender("male");
   set_hd(10,5);
	set_max_hp(50+random(25));
	set_hp(query_max_hp());
	set_alignment(1);
	set_overall_ac(5);
	set_level(10);
	set_exp(10);
	set_property("swarm",1);
   remove_std_db();
	remove_dbs(({"barkeep"}));
	remove_random_act_dbs(({"barkeeprandom"}));
	set("aggressive",0);
	set_currency("silver");
   set_menu(
   ({"raspberry tarts","chocolate strawberries","glazed doughnuts","chocolate eclair","cream puffs","fruit pastry","cinnamon pinwheels","cookie platter","sticky buns","apple turnover","blueberry pie","tapioca pudding","coffee","milk","hot chocolate","buttered bread","tomato brochette","cucumber sandwiches"}),
   ({"food","food","food","food","food","food","food","food","food","food","food","food","caffeine","water","water","food","food","food"}),
   ({8,3,2,5,4,6,3,7,4,3,4,2,1,5,8,3,9,8})
   );
   set_my_mess(({
   "The raspberry tarts have a wonderful tangy flavor with just enough sweetness.",
   "The strawberries are sweet and cool, with just the right amount of chocolate for flavor while not covering up the strawberry tang.",
   "The doughnuts are warm, fluffy, and wonderfully sweet.",
   "The rich cream is delicious and mixes well with the chocolate.",
   "The cream puffs are sweet and light, a nice snack.",
   "The cream and fruit mix together delightfully well.",
   "The pinwheels are hot, sticky, and wonderfully cinnamony.",
   "The cookie platter has a great selection, always something different and each cookie delicious.",
   "The sticky buns are hot, sweet, and very messy.",
   "The apple turnover is has that wonderful apple taste mixed with sugary sweetness.",
   "The blueberry pie is wonderfully flavored and really hits the spot.",
   "The tapioca pudding has a nice flavor and is not too sweet or bitter, but just right.",
   "The coffee is steaming hot and wakes you up.",
   "The goat's milk is quite rich and sometimes is an acquired taste.",
   "The hot chocolate is rich and thick and chocolate...mmmm.",
   "The bread is fresh, hot, and covered in melted butter.",
   "The tomato brochette has a nice zesty flavor and the diced tomatoes are a perfect compliment.",
   "The cucumber sandwiches are cool and great for a snack.",
   }));
   set_your_mess(({
   "seems to really enjoy the raspberry tarts.",
   "eats several chocolate covered strawberries.",
   "eats several glazed doughnuts and licks the glaze off their fingers.",
   "fully enjoys a cream-filled chocolate covered eclair.",
   "devours half a dozen cream puffs.",
   "eats a fruit pastry and looks satisfied.",
   "gobbles up several cinnamon pinwheels.",
   "eats an entire platter of cookies without offering to share.",
   "makes a mess eating several sticky buns.",
   "enjoys a hot apple turnover.",
   "eats a slice of blueberry pie.",
   "eats a small dish of tapioca pudding.",
   "drinks a mug of coffee and seems more alert.",
   "downs a glass of goat's milk.",
   "slowly drinks a mug of rich hot chocolate and smiles.",
   "eats a loaf of buttered bread and licks the butter off their fingers.",
   "enjoys the tomato brochette.",
   "eats a small pile of cucumber sandwiches.",
   }));
   set_menu_short(({
   "%^RESET%^%^MAGENTA%^Some scrumptious raspberry tarts%^RESET%^",
   "%^BOLD%^%^RED%^Several large %^BLACK%^chocolate%^RED%^ strawberries%^RESET%^",
   "A couple of glazed doughnuts",
   "A tasty chocolate eclair",
   "%^BOLD%^%^WHITE%^A half-dozen cream puffs%^RESET%^",
   "%^YELLOW%^A delicious fruit pastry%^RESET%^",
   "%^RED%^A few cinnamon pinwheels%^RESET%^",
   "A platter of cookies",
   "Several hot sticky buns",
   "A warm apple turnover",
   "%^BOLD%^%^BLUE%^A slice of blueberry pie%^RESET%^",
   "A small dish of tapioca pudding",
   "A mug of hot coffee",
   "%^BOLD%^%^WHITE%^A tall glass of milk%^RESET%^",
   "A warm mug of hot chocolate",
   "A huge slice of hot buttered bread",
   "A warm tomato brochette", //??
   "%^BOLD%^%^GREEN%^Several small cucumber sandwiches%^RESET%^"
   }));
   set_menu_long(({
   "There are several raspberry tarts here that look absolutely scrumptious."+
   " A flaky crust covers the cooked raspberry centers, and they have been"+
   " lightly brushed with a sugary glaze.",
   "The little plate holds several large strawberries that have been dipped"+
   " in chocolate. The strawberries appear perfectly ripe, and the layer"+
   " of chocolate is just thick enough to give a nice flavor without"+
   " covering the strawberry taste.",
   "The glazed doughnuts look delicious. They are round and fluffy and"+
   " still warm, with a clear layer of sugary glaze over them.",
   "This is a long eclair that is made out of fluffy bread and filled with"+
   " cream, with the top covered in chocolate.",
   "This plate holds six little cream puffs. They are small balls of bread"+
   " that have been hollowed out and filled with cream. They are topped"+
   " with a little bit of whipped cream and sprinkled with powdered sugar.",
   "This is a circular pastry that has a flaky pie crust and is filled with"+
   " a layer of rich cream topped with various fruits. It looks quite good.",
   "There are a couple pinwheels made from thin cinnamon bread that are"+
   " wrapped around in a circle to create a pinwheel shape. In between the"+
   " bread layers is a mix of sugary-cinnamon goo. They're best when still"+
   " hot.",
   "This platter always has a mix of cookies. Sometimes you can find"+
   " chocolate chip, peanut butter, shortbread, molasses, gingerbread,"+
   " butterscotch squares, sugar cookies, lemon drops or oatmeal raisin"+
   " cookies. There's always at least three types and the combinations"+
   " change daily.",
   "There are several very sticky sweet bread buns here. They are coated"+
   " in a mixture of butter and partially caramalized sugar that make"+
   " them messy but delicious, especially when they're still hot.",
   "This is a crisp apple turnover. The center is made of diced apples"+
   " and sugar, while the outside is a criss-crossing of sweet bread"+
   " that has been brushed with a light sugary glaze to hold it all"+
   " together.",
   "This is a slice of blueberry pie. It has a flaky crust and is made"+
   " with many fresh blueberries that have been baked in the pie. The"+
   " very top is a layer of crumbled bread and sugar that is lightly"+
   " toasted.",
   "This is a small dish of tapioca pudding. The tapioca is of a nice,"+
   " thick consistancy but appears to have been well crushed.",
   "This is a mug of hot coffee. Some people like to add cream or sugar"+
   " to it, while others prefer to drink it black.",
   "This is a tall glass of room temperature goat's milk. It is quite"+
   " thick, but hasn't soured yet.",
   "This is a mug of rich hot chocolate that has been topped with a dollop"+
   " of thick cream.",
   "This is a very large slice of freshly baked bread that has been coated"+
   " in hot butter.",
   "This is a slice of thick bread spiced with herb seasonings that has been"+
   " lightly toasted with diced tomatoes on top.",
   "There are several small cucumber sandwiches here. They basically"+
   " consist of two slices of bread, with cucumber and butter between"+
   " the slices, and have been cut into quarters.",
   }));
   
}
