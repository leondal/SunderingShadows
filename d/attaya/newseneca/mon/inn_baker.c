#include <std.h>
inherit BARKEEP;

void create(){
   ::create();
   remove_std_db();
   remove_dbs(({"barkeep","waitress"}));
   remove_random_act_dbs(({"barkeeprandom","waitress"}));
   set_name("Kairi");
   set_short("Kairi Kevynson, a friendly baker");
   set_id(({"baker","kairi","Kairi","Kairi Kevynson","friendly baker"}));
   set_long("%^RESET%^%^CYAN%^Known as the singing baker, Kairi Kevynson "
      "is rarely seen without a smile - or a song - on her lips. She hums "
      "as she moves through the bakery, helping customers and checking the "
      "quality of the %^ORANGE%^pastries%^CYAN%^ she has for sale. Her long "
      "%^ORANGE%^brown hair %^CYAN%^is worn in a braid down her back, ending "
      "in a %^GREEN%^green ribbon %^CYAN%^tied with a single %^RESET%^silver "
      "bell%^CYAN%^. Her wide eyes are a warm %^ORANGE%^brown %^CYAN%^the "
      "color of coffee with a hint of %^RESET%^cream%^CYAN%^, and they always "
      "seem to twinkle with amusement. Her %^BOLD%^apron %^RESET%^%^CYAN%^"
      "changes daily - it seems she has a neverending supply. All of them are "
      "%^BOLD%^bright %^RESET%^%^CYAN%^and %^RED%^c%^ORANGE%^o%^YELLOW%^l%^RESET%^"
      "%^GREEN%^o%^BOLD%^r%^CYAN%^f%^RESET%^%^CYAN%^u%^MAGENTA%^l%^CYAN%^, decorated "
      "with flowers, birds, abstract designs, and animals - most often sheep. "
      "She is always ready to take your %^BOLD%^<%^RESET%^%^CYAN%^order%^BOLD%^>"
      "%^RESET%^%^CYAN%^.%^RESET%^");
   set_race("human");
   set_gender("female");
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
   ({"raspberry tarts","glazed beignets","chocolate eclair","cream puffs","fruit tart","cinnamon pinwheels","cookie platter","apple turnover","attaya lime pie","coffee","milk","hot chocolate","buttered bread","tomato bruschetta","cucumber sandwiches","croquetas","papas rellenas","seneca turnover","fried plantains","orange juice","water","white wine","red wine"}),
({"food","food","food","food","food","food","food","food","food","caffeine","water","water","food","food","food","food","food","food","food","water","water","alcoholic","alcoholic"}),
   ({10,8,5,7,8,6,8,5,8,10,5,8,12,10,12,10,15,11,8,10,8,12,15})
   );
   set_my_mess(({
   "The raspberry tarts have a wonderful tangy flavor with just enough sweetness.",
   "The beignets are warm, fluffy, and wonderfully sweet.",
   "The rich cream is delicious and mixes well with the chocolate.",
   "The pastry is filled with a luscious orange pastry cream.",
   "The cream and fruit mix together delightfully well.",
   "The pinwheels are hot, sticky, and wonderfully cinnamony.",
   "The cookie platter has a great selection, always something different and each cookie delicious.",
   "The apple turnover has that wonderful cinnamon apple taste mixed with sugary sweetness.",
   "The Attaya lime pie is tart and refreshing.",
   "The coffee is steaming hot and wakes you up.",
   "The goat's milk is quite rich and sometimes is an acquired taste.",
   "The hot chocolate is rich and thick and chocolate...mmmm.",
   "The bread is fresh, hot, and covered in melted butter.",
   "The tomato bruschetta has a nice zesty flavor and the diced tomatoes are a perfect compliment.",
   "The cucumber sandwiches are cool and great for a snack.",
   "The croquetas are smooth and warm, filled with the salty taste of smoked ham.",
   "The delicate mashed potatoes give way to wonderfully spiced ground lamb mixed with onions, peppers, and chopped olives.",
   "The gooey cheese stretches as you take a bite.",
   "The plaintain chips are crunchy, and the salsa has just the right kick of heat.",
   "The orange juice is refreshingly cold and sweet.",
   "The cool cucumber-infused water soothes your thirst.",
   "You enjoy a glass of sweet white wine with an undertone of peach.",
   "The red wine is dry with a hint of blackberry and spice."
   }));
   set_your_mess(({
   "seems to really enjoy the raspberry tarts.",
   "eats several glazed beignets and licks the sugar off their fingers.",
   "fully enjoys a cream-filled chocolate-covered eclair.",
   "devours half a dozen cream puffs.",
   "eats a fruit tart and looks satisfied.",
   "gobbles up several cinnamon pinwheels.",
   "eats an entire platter of cookies without offering to share.",
   "enjoys a hot apple turnover.",
   "eats a slice of Attaya lime pie.",
   "drinks a mug of coffee and seems more alert.",
   "downs a glass of goat's milk.",
   "slowly drinks a mug of rich hot chocolate and smiles.",
   "eats a loaf of buttered bread and licks the butter off their fingers.",
   "enjoys the tomato bruschetta.",
   "eats a small pile of cucumber sandwiches.",
   "devours a handful of piping hot croquetas.",
   "eats several round papas rellenas.", 
   "makes a mess eating a stick of twisted bread filled with melted cheese.",
   "enjoys a basket of plantain chips with salsa.",
   "drinks a tall glass of orange juice.",
   "drinks a glass of water.",
   "sips from a slender glass of white wine.",
   "enjoys a glass of deep red wine."
   }));
   set_menu_short(({
   "%^RESET%^%^MAGENTA%^Some scrumptious raspberry tarts%^RESET%^",
   "%^BOLD%^%^WHITE%^A trio of glazed beignets%^RESET%^",
   "%^RESET%^%^ORANGE%^A tasty %^BOLD%^%^BLACK%^chocolate %^RESET%^%^ORANGE%^eclair%^RESET%^",
   "%^BOLD%^%^WHITE%^A half-dozen cream puffs%^RESET%^",
   "%^YELLOW%^A delicious fruit tart%^RESET%^",
   "%^RESET%^%^ORANGE%^A few cinnamon pinwheels%^RESET%^",
   "%^YELLOW%^A platter of cookies%^RESET%^",
   "%^RESET%^%^RED%^A warm apple turnover%^RESET%^",
   "%^RESET%^%^GREEN%^A slice of %^BOLD%^Attaya lime%^RESET%^%^GREEN%^ pie%^RESET%^",
   "%^BOLD%^%^BLACK%^A mug of hot coffee%^RESET%^",
   "%^BOLD%^%^WHITE%^A tall glass of milk%^RESET%^",
   "%^RESET%^%^ORANGE%^A warm mug of hot chocolate%^RESET%^",
   "%^RESET%^%^ORANGE%^A huge slice of hot buttered bread%^RESET%^",
   "%^RESET%^%^RED%^A warm tomato bruschetta%^RESET%^",
   "%^BOLD%^%^GREEN%^Several small cucumber sandwiches%^RESET%^",
   "%^BOLD%^%^WHITE%^A paper cone of croquetas%^RESET%^",
   "%^RESET%^%^ORANGE%^A few papas rellenas%^RESET%^",
   "%^YELLOW%^A twisted Seneca turnover%^RESET%^",
   "%^RESET%^%^ORANGE%^A basket of fried plantains%^RESET%^",
   "%^RESET%^%^ORANGE%^A glass of orange juice%^RESET%^",
   "%^RESET%^%^CYAN%^A glass of water%^RESET%^",
   "%^BOLD%^%^WHITE%^A glass of white wine%^RESET%^",
   "%^RESET%^%^RED%^A glass of red wine%^RESET%^"
   }));
   set_menu_long(({
   "This platter is heaped with raspberry tarts that look absolutely scrumptious. "
      "A flaky crust covers the cooked raspberry centers, and they have been "
      "lightly brushed with a sugary glaze.",
   "The glazed beignets are round, fluffy, and "
      "still warm. They are covered in a thin layer of sugary glaze and dusted "
      "with powdered sugar and a hint of cinnamon.",
   "This is a long eclair that is made out of fluffy bread and filled with "
      "cream. The eclair is covered in rich chocolate with a decorative drizzle "
      "of white chocolate.",
   "This plate holds six little cream puffs. They are small balls of bread "
      "that have been hollowed out and filled with orange-flavored cream. They are topped "
      "with a little bit of whipped cream and sprinkled with powdered sugar.",
   "This is a circular pastry that has a flaky pie crust and is filled with "
      "a layer of rich cream topped with various fruits native to Attaya. It looks quite good.",
   "There are a couple pastries made from thin cinnamon bread that are "
      "wrapped around in a circle to create a pinwheel shape. In between the "
      "bread layers is a mix of sugary-cinnamon goo. They're best when still "
      "hot.",
   "This platter always has a mix of cookies. Sometimes you can find "
      "chocolate chip, peanut butter, shortbread, molasses, gingerbread, "
      "butterscotch squares, sugar cookies, lemon drops or oatmeal raisin "
      "cookies. There's always at least three types and the combinations "
      "change daily.",
   "This is a crisp apple turnover. The center is made of diced apples "
      "and sugar, while the outside is a criss-crossing of sweet bread "
      "that has been brushed with a light sugary glaze to hold it all "
      "together.",
   "This slice of Attaya lime pie has a graham cracker crust with tart lime "
      "filling. On top is a peaked meringue torched to a light golden brown. "
      "The pie is finished with a slice of lime and a sprinkling of zest.",
   "This is a mug of hot coffee. Some people like to add cream or sugar "
      "to it, while others prefer to drink it black.",
   "This is a tall glass of room-temperature goat's milk. It is quite "
      "thick, but hasn't soured yet.",
   "This is a mug of rich hot chocolate that has been topped with a dollop "
      "of thick cream. Curls of dark chocolate have been shaved onto the top.",
   "This is a very large slice of freshly baked bread that has been coated "
      "in hot butter.",
   "This is a slice of thick bread spiced with herb seasonings that has been "
      "lightly toasted and rubbed with garlic. It is topped with tomato salad "
      "and parmesan shavings.",
   "There are several small cucumber sandwiches here. Each dainty sandwich is "
      "made of two small squares of fresh bread surrouding sliced cucumbers and butter.",
   "A simple paper cone has been filled with golden brown croquetas. The little "
      "morsels of creamy ham are still steaming, releasing the mouth-watering "
      "aroma of smoked pork.",
   "This small plate has a trio of papas rellenas fried golden brown. Each small "
      "ball is made of mashed potatoes stuffed with spiced ground lamb that has "
      "been mixed with diced onions, peppers, and olives. Some sort of spicy cream "
      "sauce has been drizzled on top, adding extra heat.",
   "Not actually a turnover at all, these breadsticks are favorites of the "
      "citizens of Seneca. Thin, slightly sweet dough is wrapped around a thick "
      "stick of cheese and then fried to a golden brown. Grated parmesan adds "
      "the perfect finishing touch.",
   "Served in a small basket filled with parchment paper, these plantain chips have "
      "been thinly sliced and fried to crisp perfection. They are served with a small "
      "bowl of warm salsa made from red peppers and tomatoes that lend a smokey flavor.",
   "This tall, narrow glass is filled with freshly squeezed orange juice and garnished "
      "with a thin slice of orange.",
   "The glass is filled with water that has been infused with cucumber - a favorite "
      "practice among the citizens of Seneca. The result is a refreshingly cool flavor.",
   "The house blend white wine smells sweet and is served chilled, fogging the glass "
      "with condensation.",
   "This glass is filled with the house blend red wine served at room temperature. A "
      "slightly floral aroma rises from the glass with an undertone of blackberry and spice."
   }));
}
