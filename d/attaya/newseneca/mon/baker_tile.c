#include <std.h>

inherit NPC;

string *menu_items;

mapping menu;

string currency;

void set_menu(string *item_names, string *types, int *strengths);
void set_my_mess(string *msg);
void set_your_mess(string *msg);
void set_empty_container(string *empty);
void set_menu_short(string *str);
void set_menu_long(string *str);
void set_currency(string str);
int price(object tp, string strength);
int convert(int cost);
string *query_menu();

void init() {
    ::init();
   add_action("buy", "buy");
   add_action("buy","order");
}

void set_menu(string *item_names, string *types, int *strengths) {
    int i;

    menu_items = item_names;
    if(!menu) menu = ([]);
    for(i=0; i<sizeof(menu_items); i++) {
	menu[menu_items[i]] = ([ "type": types[i], "strength": strengths[i] ]);
    }
}

void set_my_mess(string *msg) { 
    int i;
   
    for(i=0; i<sizeof(menu_items); i++) {
    	menu[menu_items[i]]["my message"] = msg[i];
    }
}

void set_your_mess(string *msg) {
    int i;
 
    for(i=0; i<sizeof(menu_items); i++) {
	menu[menu_items[i]]["your message"] = msg[i];
    }
}

void set_empty_container(string *container) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
	menu[menu_items[i]]["empty container"] = container[i];
    }
}

void set_menu_short(string *str) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
	menu[menu_items[i]]["short"] = str[i];
    }
}

void set_menu_long(string *str) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
 	menu[menu_items[i]]["long"] = str[i];
    }
}

void set_currency(string str) {
    currency = str;
}

int price(object tp, int strength) {
    int cost;
    cost = strength;
        if(!tp->query_funds(currency, cost)) return 0;
    tp->use_funds(currency, cost);
    return cost;
}

int convert(int x) {
    if(!x) return 0;
    else return 1+to_int(currency_rate(currency)*x);
}

void create(){
   ::create();
   remove_std_db();
   remove_dbs(({"barkeep","waitress"}));
   remove_random_act_dbs(({"barkeeprandom","waitress"}));
   set_name("baker tile");
   set_short("baker tile");
   set_id(({"baker_tile111"}));
   set_long("This is a tile sitting on a table. You should not be able to see this description.");
   set_race("human");
   set_gender("male");
   set_hd(10,5);
   set_max_hp(50+random(25));
   set_hp(query_max_hp());
   set_alignment(1);
   set_overall_ac(5);
   set_level(10);
   set_exp(10);
   remove_std_db();
   remove_dbs(({"barkeep"}));
   remove_random_act_dbs(({"barkeeprandom"}));
   set("aggressive",0);
   set_currency("silver");
   set_property("no detect",1);
   set_invis();
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

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

void set_invis(){
   if(TO->query_invis()) return;
   else ::set_invis();
   return;
}


int buy(string str) {
    int i, cost;
    object ob;
    if(!str) {
	notify_fail("What is it you would like to order?\n");
	return 0;
    }
    str = lower_case(str);
    if(member_array(str, menu_items) == -1) {
	notify_fail("You can't seem to find a stone with that item written on it.\n");
	return 0;
    }
    if(!(cost = price(this_player(), menu[str]["strength"]))) {
	write("You realize you don't have enough "+currency+" for that!\n");
	return 1;
    }
    write("You rummage through the hurricane vase and select the appropriate "
       "stone to order "+str+". Then you drop "+cost+" "+currency+" coins and "
       "the stone into the opening beneath the vase.\n");
    say(""+TPQCN+" drops a stone and a handful of coins into the opening beneath the hurricane vase.\n", this_player());
    if(menu[str]["type"] == "food") {
	ob = new("std/food");
	ob->set_name(str);
      ob->set_id( ({str, "food" }) );
      ob->set_value(0);
    }else{
	ob = new("std/drink");
	ob->set_name(str);
	ob->set_type(menu[str]["type"]);
	ob->set_id( ({ str, "drink" }) );
    }
    ob->set_strength(menu[str]["strength"]);
    ob->set_weight(1);
    i = menu[str]["strength"];
    set("cointype","silver");
    ob->set_value(0);
    ob->set_destroy();
    if(menu[str]["short"]) ob->set_short(menu[str]["short"]);
    else ob->set_short(capitalize(str));
    if(menu[str]["long"]) ob->set_long(menu[str]["long"]);
    else ob->set_long(capitalize(str) + " from "+(string)environment(this_object())->query_short()+".\n");
    if(menu[str]["empty container"]) ob->set_empty_name(menu[str]["empty container"]);
    if(menu[str]["my message"]) ob->set_my_mess(menu[str]["my message"]);
    if(menu[str]["your message"]) ob->set_your_mess(menu[str]["your message"]);
    tell_room(ETO,""+ob->query_short()+" materializes on the small table.");
    ob->move(ETO);
    return 1;
}

int get_price(string str) {
    int foo;
    foo = menu[str]["strength"];
    return foo;
}

string *query_menu() { return menu_items; }
