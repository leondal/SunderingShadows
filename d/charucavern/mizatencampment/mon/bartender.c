#include <std.h>
#include <daemons.h>
inherit BARKEEP;

void create()
{
    object ob;
    ::create();
    set_alignment(6);
    set_gender("male");
    set("aggressive",0);
    set_level(16 + random(4));
    set_hd(16 + random(4),2);
    set_hp(query_hd() * 7 + random(31));
    set_name("drynaal aarndholm");
    set_id(({"drynaal aarndholm", "drynaal", "bartender", "barkeep"}));
    set_short("%^BOLD%^%^WHITE%^Drynaal Aarndh%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^lm, Barkeep%^RESET%^");
    set_race("dwarf");
    set_long("%^RESET%^%^GREEN%^This massively built dwarf looks old. His face is wrinkled "+
    "and scarred. The flesh of the scars stands out againstly against his otherwise tan skin. He is "+
    "missing his left eye and his remaining one is a deep piercing %^BOLD%^%^WHITE%^silver%^RESET%^"+
    "%^GREEN%^. He keeps a very long and dark beard that is trimmed, kept neat, and tied together "+
    "with %^RESET%^%^WHITE%^dingy strings%^RESET%^%^GREEN%^. His arms and legs are thick and "+
    "muscular, though most of his body is adorned with a suit of full plate armor. He also carries an axe "+
    "that he constantly sharpens and polishes when not serving ale.%^RESET%^");

    ob = new("/d/common/obj/weapon/battle_axe");
    ob->set_property("enchantment", 2 + random(2));
    if(random(22)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield axe");

    ob = new("/d/common/obj/armour/sfullplate");
    ob->set_property("enchantment", 1 + random(2));
    if(random(33)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wear armor");
    set_stats("strength",23);
    set_stats("intelligence",15);
    set_stats("wisdom",12);
    set_stats("dexterity",13);
    set_stats("constitution",20);
    set_stats("charisma",10);
    add_money("copper", random(20));
    set_exp(query_hp() * 5);
    set_body_type("dwarf");
    set_currency("gold");

    set_menu(
        ({"dwarven ale stout", "dwarven ale light", "dwarven ale thick", "water", "slab of beef", "dwarven ale dark", "dwarven ale stouter", "dwarven ale thicker"}),
        ({ "alcoholic", "alcoholic", "alcoholic", "water", "food","alcoholic","alcoholic","alcoholic",}),
        ({ 10, 10, 10, 10, 10, 10, 10, 10,})
    );
    set_my_mess(
	({
	"You down the stout dwarven ale!\n",
    "You down the light dwarven ale!\n",
    "You down the thick dwarven ale!\n",
	"The water quenches your thirst.\n",
    "The slab of beef tastes surprisingly delicious and you can taste a bit of dwarven ale.\n",
    "You down the dark dwarven ale!\n",
    "You down the stouter dwarven ale!\n",
    "You down the thicker dwarven ale!\n",
	})
    );
    set_your_mess(
	({
	"downs the stout dwarven ale.\n",
    "downs the light dwarven ale.\n",
    "downs the thick dwarven ale.\n",
    "drinks the clear water.\n",
    "devours the slab of beef.\n",
    "downs the dark dwarven ale.\n",
    "downs the stouter dwarven ale.\n",
    "downs the thicker dwarven ale.\n",
        })
    );
    set_menu_short(
        ({
	"Dwarven ale stout",
	"Dwarven ale light",
	"Dwarven ale thick",
    "Clean water",
    "Slab of beef",
    "Dwarven ale dark",
    "Dwarven all stouter",
    "Dwarven all thicker",})
    );
    set_menu_long(
        ({
        "A stout dwarven ale.\n",
        "A light dwarven ale.\n",
        "A thick dwarven ale.\n",
	    "A glass of clean water.\n",
        "A slab of thick and juicy beef.\n",
        "A dark dwarven ale.\n",
        "An even stouter dwarven ale.\n",
        "An even thicker dwarven ale.\n",
        })
    );
}
