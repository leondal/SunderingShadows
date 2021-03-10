#include "../undead.h"
inherit BARKEEP;

void create() {
    ::create();
    set_name("Sal");
    set_race("human");
    set_gender("male");
    set_body_type("human");
    set_id(({"Sal","sal","bartender","barkeep"}));
    set_short("Sal, the bartender");
    set("aggressive", 0);
    set_level(20);    
    set_long("%^RESET%^%^CYAN%^Sal is an hearty man in his late fourties.  His "
"%^ORANGE%^brown hair %^CYAN%^has begun to show signs of %^RESET%^gray %^CYAN%^"
"at the edges, and his face is worn with lines of near constant worry from many "
"decades on this island of perpetual struggle.  He carries a clean dish cloth "
"with him which he promptly wipes down tables and does his best to clean up "
"after the tired defenders of the besieged city when they come here for a "
"drink.%^RESET%^");
    set_alignment(1);
    set_hp(300);
    add_money("gold", random(200));
    set_currency("silver");
    
    set_menu(({ "deathblow", "special"  , "ale"      , "water"      , "pretzels" }),
	         ({ "alcoholic", "alcoholic", "alcoholic", "soft drink" , "food"     }),
             ({  100       ,  45        ,  25        ,  10          ,  20        }));
    
    set_my_mess(({
        "The Deathblow feels like it's eating away the inside of your throat as it makes its way down!\n",
        "A mixture of, well, it's hard to tell, but it sure is good!\n",
	    "You down a frothy, ice cold, ale.\n",
        "The ice cold water tastes pure and clean as it refreshes.\n",
        "You crunch into the salty pretzels.\n"
               }));
    
    set_your_mess(({
        "turns red as the deathblow makes its way down.\n",
	    "drinks a special of the house.\n",
	    "downs a mug of frothy ale.\n",
        "drinks down a glass of ice cold water.\n",
        "crunches on some salty pretzels.\n"
                 }));

    set_menu_short(({
        "A Deathblow",
	    "A special of the house",
	    "A frosty ale",
        "A tall glass of water",
        "Some salty pretzels"
	              }));

    set_menu_long(({
        "A Deathblow, brewed by Sal himself.\n",
        "A Saturday Night Special from the famous Graez Bar.\n",
        "A fine ale brewed in the royal fields of Graez.\n",
        "A tall, crystal clear glass full of pure water with beeds of moisture running down the sides.\n",
        "A handful of pretzels, some straight and some knotted.\n"
   	             }));
}

void receive_given_item(object ob)
{
    if((string)ob->query_short() == "An empty bottle" || (string)ob->query_name() == "bottle")
    {
        force_me("emote puts away the empty bottle.");
        ob->remove();
    }
}



