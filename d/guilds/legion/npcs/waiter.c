inherit "/std/barkeep";

create() {
    ::create();
    set_name("Rakhaz");
    set_id( ({ "waiter", "rakhaz"  }) );
    set_short("Rakhaz the waiter");
    set("aggressive", 0);
    set_level(10);
    set_long("Rakhaz waits paitently for your order.\n");
    set_gender("male");
    set_alignment(9);
    set("race", "human");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(250));
    set_max_mp(query_mp());
    add_money("copper", random(200));
    set_skill("melee",90);
    set_body_type("human");
    set_currency("silver");

    set_menu(
      ({"grilled steak", "spicy chili", "barbeque chicken", "graveyard cake"}),
      ({ "food", "food", "food", "food" }),
      ({60, 30, 40, 30})
    );
    set_my_mess(
      ({
	"The tender juicy stake satisfies you utterly.\n",
	"The chili burns on the way down and almost sets your stomach on fire.\n",
	"The chicken tastes great...  you remind yourself to find out what this 'secret sauce' is.\n",
	"A strange piece of cake.  When you bite into it, it feels like someone just steped on your grave.\n",
      })
    );
    set_your_mess(
      ({
	"savors the spices in the steak.\n",
	"savors the spices in the chili.\n",
	"enjoys that special sauce...  it's finger lickin' good!\n",
	"gets a strange look as they eat the cake.\n",
      })
    );
    set_menu_short(
      ({
	"Grilled Steak",
	"Spicy Chili",
	"Barbeque Chicken",
	"Graveyard Cake",
      })
    );
    set_menu_long(
      ({
	"Grilled Steak",
	"Spicy Chili",
	"Barbeque Chicken",
	"Graveyard Cake",
      })
    );
}
