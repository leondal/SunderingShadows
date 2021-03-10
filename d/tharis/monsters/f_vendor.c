#include <std.h>

inherit "/std/barkeep";

void create() {
    ::create();
    set_name("food vendor");
    set_id( ({ "food vendor", "vendor" }) );
    set_short("A food vendor");
    set("aggressive", 0);
    set_level(10);
    set_long("She is ready to take your order.\n There is a sign on the cart that shows what is\n served");
   	set_gender("female");
   	set_alignment(4);
   	set_race("human");
   	set_hd(10,0);
   set_exp(10);
    set_max_hp(query_hp());
   	add_money("copper", random(200));
   	set_skill("melee",90);

    set_currency("silver");
   	set_menu(
        ({"ration" , "cheese", "bread","days meat"}),
       ({ "food", "food", "food", "food" }),
       ({ 3, 4, 1,1 })
   );
   set_my_mess(
       ({
       "A day's food on your adventure.\n",
       "A block of good cheese.\n",
       "With bread, you need meat.\n",
       "day's supply of meat. Very good!\n"
       })
   );
   set_your_mess(
       ({
       "eats a ration.\n",
       "eats a block of cheese.\n",
       "wolfs down a loaf of bread.\n",
       "downs some salted meat.\n"
        })
    );
    set_menu_short(
        ({
        "a ration",
        "a block of cheese",
        "a loaf of bread",
        "a strip of meat"
        })
    );
 set_menu_long(
        ({
        "A ration.\n",
        "A slab of cheese.\n",
        "A loaf of bread.\n",
        "A strip of good meat.\n"
        })
    );
   }


void init(){
	::init();
	add_action("read","read");
	}
	
	
int read(string str){
	if(!str || str != "sign") return 0;
	
	
	write("--------------------------------------------------------------------");
    write("Rations\t\t\t\t"+ (int)TO->get_price("ration") + " silver");
    write("Cheese\t\t\t\t"+(int)TO->get_price("cheese")+" silver");
    write("Bread\t\t\t\t"+(int)TO->get_price("bread")+" silver");
    write("days meat\t\t\t\t\t"+ (int)TO->get_price("days meat")+" silver");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}
