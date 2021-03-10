inherit "/std/barkeep";

create() {
    ::create();
   set_name("rocko");
    set_id( ({ "rocko", "barkeep" }) );
    set_short("Rocko, the barkeep");
   set("aggressive", 0);
  set_level(12);
    set_long("He will sell you a drink, but he won't put up with your crap.\n");
   set_gender("male");
   set_alignment(-232);
   set("race", "half-orc");
   set_hp(480);
   add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_menu(
	({
        "whiskey", "ale", "pretzel"
	}),
	({ "alcoholic", "alcoholic", "food" }),
	({ 25, 15, 13 })
    );
    set_my_mess(
	({
	"The whiskey burns your throat!\n",
        "Mmmmm good.\n",
        "Munchin' on a pretzel.\n"
	})
    );
    set_your_mess(
	({
	"screams form the burning of a drink of a whiskey.\n",
	"drinks an assassin's ale.\n",
	"munches on a pretzel.\n"
    	})
    );
    set_menu_short(
	({
	"Whiskey",
	"Assassin's ale",
	"A pretzel"
	})
    );
    set_menu_long(
	({
        "A shot of of whiskey from the Brigand's Pub.\n",
        "A tasty looking glass of assassin's ale.\n",
        "A huge, salty pretzel.\n"
   	})
    );
}
