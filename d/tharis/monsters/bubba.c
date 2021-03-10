inherit "/std/barkeep";

void create() {
    ::create();
   set_name("Bubba");
    set_id( ({ "Bubba", "tavern keep" }) );
           set_short("Bubba, your tavern keep");
   set("aggressive", 0);
  set_level(10);
    set_long("He is ready to take your order.\n");
   set_gender("male");
   set_alignment(4);
   set_race("dwarf");
   set_hd(10,0);
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
       ({"dwarf stew", "rock stew", "water stew", "dog scraps"}),
       ({ "food", "food", "food", "food" }),
       ({ 10, 7, 5, 3 })
   );
   set_my_mess(
       ({
       "Best meal in the house!\n",
       "A common meal for foreigners.\n",
       "A poor mans meal.\n",
"Some great dog food, just for you.\n"
       })
   );
   set_your_mess(
       ({
       "enjoys a good meal.\n",
       "gobbles down a common meal.\n",
       "gags on the poor mans meal.\n",
	"eats what is only fit for a dog.\n"
        })
    );
    set_menu_short(
        ({
        "Dwarf stew",
        "Rock stew",
        "Water stew",
        "Dog food"
        })
    );
    set_menu_long(
        ({
        "A tasty looking plate of some really good food.\n",
        "An appetizing plate of some food.\n",
        "A bowl of pitiful looking water.\n",
        "This was meant for the dog.\n"
        })
    );
}
