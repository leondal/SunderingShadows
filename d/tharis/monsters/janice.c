#include <std.h>

inherit BARKEEP;

void create() {
    ::create();
   set_property("no bump", 1);
	set_name("janice");
	 set_id( ({ "janice", "Janice", "barmaid" }) );
	 set_short("Janice, the barmaid");
   set("aggressive", 0);
set_level(14);
	 set_long("Janice is short and petite. Though beautiful, she can be deadly if given the chance. Whcih is why all the barflies treat her with respect!");
	set_gender("female");
set_alignment(9);
   set_race("human");
   set_hp(300);
   add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_menu(
	({
	"ok soda", "issaquah ale", "wine"
	}),
	({ "soft drink", "alcoholic", "alcoholic" }),
	({ 25, 15, 3 })
    );
    set_my_mess(
	({
	"The OK Soda goes down easy and is refreshing. You feel like another!\n",
	"The Issaquah Ale tastes great! I hometown favorite!\n",
	"The wine tastes fair. Standard wine imported from Asgard\n",
	})
    );
    set_your_mess(
	({
	"chugs an OK Soda. My that looks refreshing!\n",
	"samples an Issaquah Ale. Something the natives are proud of!\n",
	"sips some of the imported wine and looks mildly satisfied.\n",
    	})
    );
    set_menu_short(
	({
	"OK soda",
	"Issqaquah ale",
	"Wine",
	})
    );
    set_menu_long(
	({
	"A can of OK Soda from the city of Issaquah.\n",
	"A specialty of the Gaslamp Tavrn-- Issaquah Ale.\n",
	"Some fair tasting wine from the Gaslamp Tavern.\n"
   	})
    );
}
