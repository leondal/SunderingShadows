#include <std.h>
#include "../tharis.h"
inherit BARKEEP;

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Fattened Dwarf Remodle - Created in February 2009 by Ari

void create(){
	::create();
    set_property("no bump",1);
    set_name("gralesh");
    set_id(({"gralesh","Gralesh","barkeep","dwarf"}));
    set_short("Gralesh - Cook, keeper and name sake of the "+
		"Fattened Dwarf");
    set_level(12);
    set_long("%^RESET%^%^CYAN%^Gralesh is a short, rotund dwarf "+
		"with a regular smile and a jolly demeanor.  As wide as "+
		"he is tall, he waddles about the Fattened Dwarf with a "+
		"cheery, often exuberant greeting for both new and old "+
		"comer alike.  Dressed in simple clothing over which he "+
		"wears a heavy apron, Gralesh is clearly the name sake "+
		"for the restaurant.  His thickly graying hair is pulled "+
		"back into a cumbersome braid, and his beard is kept "+
		"neatly trimmed near his face.  This opens his features "+
		"up and makes the otherwise pudgy face warm and inviting. "+
		"%^RESET%^");
    set_gender("male");
    set_alignment (2);
    set_race("dwarf");
    set_hp(300);
    add_money("gold", random(200));
    set_body_type("human");
    set_currency("copper");

    set_menu(({"stuffed pheasant","tharisian dark lager",
		"water","bread","dwarven stew","antiochish wine",
		"fattened dwarf"}),({"food","alcoholic","water","food",
		"food","alcoholic","food"}),({ 45, 30, 15, 15, 20, 25, 
		65}));
    set_my_mess(({
		"You taste the spices in the bread as you wolf down "+
			"the bird.",
		"You drink the extremely dark, thick lager and feel "+
			"it as it rolls down your throat.",
		"You drink down the fresh water.",
		"You chew the thick crust and pulpy inner area of the "+
			"bread.",
		"You marvel at the flavor of this mysterious dwarven "+
			"recipe.",
		"You drink the pale wine from the fairly untended "+
			"vineyards of antioch.",
		"You eat the fattening stuff, feeling the pounds "+
			"pack on.",
    }));
    set_your_mess(({
		"eats the spicey cooked bird.",
        "pours the thick dark brew down "+TP->QP+" gullet.",
        "quickly gulps down the clear water.",
        "tears pieces of the bread and gulps them down.",
        "eats the stew and seems to wonder what the recipe is.",
        "sips carefully the pale wine.",
        "seems to get fatter as the food is consumed.",
	}));
    set_menu_short(({
		"Stuffed Pheasant",
		"Tharisian dark lager",
		"Mug of Water",
		"Loaf of Bread",
		"Dwarven Stew",
		"Antiochish Wine",
		"The Fattened Dwarf",
	}));
    set_menu_long(({
		"This is a well cooked bird stuffed with heavily spiced "+
			"bread.",
		"This is a dark dark dark brew, famous to Tharis. this "+
			"brew doesn't even slosh it sorta oozes.",
		"This is a mug of clear water.",
		"This is a loaf of heavily crusted white bread.",
		"This is a thick based stew that The dwarves of the "+
			"world have made famous.",
		"This is the pale wine from the un-tended vineyard of "+
			"antioch.",
		"This is the famous fattened dwarf. It is served in a "+
			"well formed rotund pile. Its flavor is famous, as "+
			"are the effects.",
	}));
} 