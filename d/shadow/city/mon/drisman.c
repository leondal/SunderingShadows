#include <std.h>
inherit "/std/barkeep";

void create() {
    ::create();
   	set_name("waitress");
    	set_id( ({ "waitress", "restaurant waitress", "catherina" }) );
    	set_short("%^RESET%^%^MAGENTA%^Catherina,%^BLUE%^ Waitress of the Three Coins");
        set_long("%^CYAN%^She is a woman of average height and average"+
                " build.  She is dressed in an "+
                "ankle length %^BLUE%^blue cotton skirt%^CYAN%^ and "+
                "matching %^BLUE%^blue shirt%^CYAN%^.  A "+
                "%^BOLD%^%^BLACK%^black leather %^RESET%^%^CYAN%^bodice"+
                " is laced over her blue shirt, as if she wears a"+
                " uniform of some kind.  Her %^YELLOW%^wheat blonde"+
                "%^RESET%^%^CYAN%^ hair falls in a single braid down "+
                "her back.  Her attitude seems calm and friendly as "+
                "she waits to take orders and tends to cleaning tables"+
                " that have been used by customers already gone.");
   	set_gender("female");
   	set_exp(20);
   	set_alignment(1);
   	set_level(10);
        set_race("human");
        set_body_type("human");
   	set_hd(10,0);
	set_max_hp(query_hp());
   	add_money("copper", random(200));
   	set_currency("gold");
	set_menu(
      ({"onion soup", "roasted wild pork", "alehouse chicken", "stuffed veal loin", "fried squash", "green peas royal", "gingerbread", "green apple tart", "griddle cakes", "water", "eggnog", "three coins ale", "mulled wine", "apple cider", "white wine" }),
      ({"food", "food", "food", "food", "food", "food", "food", "food", "food", "water", "soft drink", "alcoholic", "alcoholic", "soft drink", "alcoholic" }),
      ({15,25,23,35,8,13,15,13,8,1,15,20,45,20,45})
   );
   set_my_mess(({
      "The carmelized onions are infused with the fragrant beef broth.\n",
      "The wild pork is infused with cloves, red wine and pepper.\n",
      "The half a chicken is infused with a pale ale and some tarragon.\n",
      "The tender veal is stuffed with spinach, endive, sage, and onions.\n",
      "The slices of yellow squash are coated in a light batter and fried to a golden color.\n",
      "Springs of mint are used to add a burst of flavor to the sweet peas.\n",
      "The gingerbread is still warm and fresh!\n",
      "The green apples used for the tart have a tangy flavor to them, which blends well with the shortbread crust.\n",
      "The warm and fluffy griddle cakes are served with a hot maple syrup that just melts in your mouth.\n",
      "The water is very refreshing.\n",
      "The eggnog is thick and creamy, with just a hint of brandy.\n",
      "The ale is ice cold and has a foamy head on it - making it easy to enjoy.\n",
      "The mulled red wine is warm and very fragrant with cloves, cinnamon, and nutmeg flavors.\n",
      "The apple cider is served warm, reminding you of the autumn.\n",
      "The white wine has a fruity bouquet to it, going down easily.\n"       
      }));
   set_your_mess(({
       "finishes off the onion soup, then starts to chew on the sourdough bread bowl.\n",
       "chews on the tender slices of roasted wild pork.\n",
       "enjoys the tender moist chicken half.\n",
       "smiles blissfully at the tender slices of stuffed veal.\n",
       "blows on the slices of fried squash before eating them one by one.\n",
       "spoons up the mashed peas and slowly savors the flavors.\n",
       "bites the heads of the platter of gingerbread men before devouring the rest.\n",
       "smacks their lips after eating the green apple tart.\n",
       "licks the syrup off their lips after polishing off the platter of griddle cakes.\n",
       "drinks a glass of water.\n",
       "drinks down the thick eggnog in one gulp.\n",
       "gulps down the foamy pale ale.\n",
       "nurses a glass of mulled red wine.\n",
       "sips on the hot apple cider, enjoying every sip.\n",
       "sips on a glass of white wine until its empty.\n"
        })); 
    set_menu_short(({
         "Onion Soup",
         "Roasted Wild Pork",
         "Alehouse Chicken",
         "Stuffed Veal Loin",
         "Fried Squash",
         "Green Peas Royal",
         "Gingerbread",
         "Green Apple Tart",
         "Griddle Cakes",
         "Water",
         "Eggnog",
         "Three Coins Ale",
         "Mulled Wine",
         "Apple Cider",
         "White Wine"
        }));
    set_menu_long(({
      "%^ORANGE%^A thick soup of carmelized onions in a beef broth, served in a sourdough bread bowl.%^RESET%^\n",
      "%^RED%^Tender slices of roasted pork infused with cloves, red wine, and pepper.  Mashed turnips and some chard is served with the pork.%^RESET%^\n",
      "%^YELLOW%^A half of a chicken infused with a pale ale and tarragon.  The chicken is served with some grilled corn on the cob and fire roasted potatoes.%^RESET%^\n",
      "%^ORANGE%^Slices veal loin stuffed with sage, spinach, endive and onions are piled onto a platter with steamed cauliflower and broccoli.  A dark gravy is drizzled over the succulent loin.%^RESET%^\n",
      "%^YELLOW%^Slices of yellow squash are dipped in a light batter and fried to a golden color.%^RESET%^\n",
      "%^BOLD%^%^GREEN%^Sweet peas are cooked with almond milk before they are mashed with mint to create a rich and royal dish.%^RESET%^\n",
      "%^ORANGE%^Shaped into silhouettes of drow, ogres, goblins, and orcs - the gingerbread is still fresh and hot!%^RESET%^\n",
      "%^BOLD%^%^GREEN%^Slices of green apple are spread out on a shortbread tart and flavored with cinnamon, cloves, and sugar.%^RESET%^\n",
      "%^ORANGE%^A platter of light and fluffy griddle cakes are served with a hot maple syrup.  Links of a fried sausage are served with the cakes.%^RESET%^\n",
      "%^BOLD%^%^CYAN%^This is a tall glass of water served with a slice of green apple. %^RESET%^\n",
      "%^YELLOW%^Served in a small cup, the eggnog is thick and creamy and served with a sprinkle of nutmeg.%^RESET%^\n",
      "%^YELLOW%^Served in a flagon, the pale ale is light and easy to handle.%^RESET%^\n",
      "%^MAGENTA%^Served in a flagon, the mulled wine is hot and fragrant.%^RESET%^\n",
      "%^ORANGE%^Served in a small cup, the apple cider is warm and garnished with a cinnamon stick.%^RESET%^\n",
      "%^YELLOW%^Served in a tall glass, the white wine is chilled to the right temperature to bring out its fruity bouquet.%^RESET%^\n"   	
    }));
}
void receive_given_item(object ob){
   if((string)ob->query_short() == "An empty bottle" ||
      (string)ob->query_name() == "bottle"){
      force_me("emote puts away the empty bottle.");
      ob->remove();
   }
}
