inherit "/std/barkeep";

void create() {
	::create();
	set_name("alder");
    set_id( ({ "alder", "Alder" }) );
    set_short("Alder, the jolly proprietor of the Elven inn");
    set("aggressive", 0);
    set_long("This jolly old elf will serve you as best he can.\n");
   	set_gender("male");
   	set_alignment(7);
   	set_race("elf");
    set_hd(20,0);
   	set_max_hp(query_hp());

   	add_money("copper", random(200));

    set_exp(10);
    set_body_type("human");
    set_currency("silver");

   set_menu(
       ({"elven stew", "deer cutlet", "elven biscuits", "cheese"}),
       ({ "food", "food", "food", "food" }),
       ({ 25, 15, 10, 3 })
   );
   set_my_mess(
       ({
       "A fine choice for those seeking great food!\n",
       "Cutlets of deer from the surrounding forest.\n",
       "A basket of some fine elven biscuits.\n",
       "Some of the elven cheese. Very good!\n"
       })
   );
   set_your_mess(
       ({
       "enjoys the wonderful Elven stew.\n",
       "devours the deer cutlets.\n",
       "breaks open some biscuits and eats.\n",
       "eats some really good cheese.\n"
        })
    );
    set_menu_short(
        ({
        "A bowl full of the Elven stew",
        "a fine deer cutlet",
        "A basket of some fine elven biscuits",
        "Some Cheese"
        })
    );
    set_menu_long(
        ({
        "A tasty looking plate of some really good food.\n",
        "A plate of wonderful deer cutlets.\n",
        "A basket of fine elven biscuits.\n",
        "A slab of some really tasty cheese.\n"
        })

    );
}
