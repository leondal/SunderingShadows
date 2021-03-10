inherit "/std/barkeep";

create() {
    ::create();
   set_name("waitress");
    set_id( ({ "waitress", "restaurant waitress" }) );
    set_short("A restaurant waitress");
   set("aggressive", 0);
  set_level(10);
    set_long("She is ready to take your order.\n");
   set_gender("female");
   set_alignment(164);
   set("race", "nymph");
   set_hp(270);
   add_money("copper", random(200));
   set_skill("melee",90);
    set_body_type("human");
    set_currency("gold");
    set_menu(
	({
	"lobster", "worms", "fish", "fries"
	}),
	({ "food", "food", "food", "food" }),
	({ 25, 15, 8, 3 })
    );
    set_my_mess(
	({
	"What a wonderful way of not cooking lobsters!\n",
	"Feel them wiggle in your throat?\n",
	"Tasty indeed!\n",
	"You enjoy them one by one to the end.\n"
	})
    );
    set_your_mess(
	({
	"enjoys some uncooked lobster.\n",
	"slides down a plate of worms.\n",
	"chomps on some Praxian fish.\n",
	"eats some fries one by one.\n"
    	})
    );
    set_menu_short(
	({
	"A lobster",
	"A plate of sea worms",
	"A nice fish",
	"Fries"
	})
    );
    set_menu_long(
	({
	"It is uncooked in a Praxia sort of way.\n",
	"They are still alive!\n",
	"Mmmmmmm good.\n",
	"Not many there, but something just the same.\n"
   	})
    );
}
