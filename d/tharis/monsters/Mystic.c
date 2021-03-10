#include <std.h>
inherit BARKEEP;

void create() {
    ::create();
   set_property("no bump", 1);
   set_name("Mystic");
    set_id( ({ "mystic", "Mystic","barkeep" }) );
    set_short("Mystic, the proprietor of the Pebble's Rumble Pub");
   set("aggressive", 0);
  set_level(12);
    set_long("She tends bar and listens.\n");
   set_gender("female");
   set_alignment(122);
   set_race("human");
   set_hp(300);
   add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_menu(
        ({
        "death by burning" , "dwarf killer" , "rolling rock" , "vodka" , "ale"
        }),
          ({ "alcoholic", "alcoholic", "water","alcoholic","alcoholic" }),
        ({ 25, 15, 10, 13,3 })
    );
    set_my_mess(
        ({
        "When the Death by burning hits your tongue, you drop to the floor in convulsive fits
of pain.\n",
        "Wow! That should have killed you and a dwarf.\n",
        "You down some great beer from another age.\n",
	"You appreciate the result of  the trade of this city.\n",
	"You chug some ale.\n"
        })
    );
    set_your_mess(
        ({
        "screams from a drink of a Death by burning, and falls to the ground in
convulsions.\n",
        "shakes their head in pain from drinking Dwarf killer.\n",
	"shakes his head in approval of this fine alcohol.\n",
	",after a squint, looks around for another drink.\n",
        "drinks some ale.\n"
        })
    );
    set_menu_short(
        ({
        "A death by burning",
        "A Dwarf killer",
	"A bottle of Rolling Rock",
	"A shot of Vodka",
        "A pale ale"
        })
    );
    set_menu_long(
        ({
        "A Death by burning from the Pebble's Rumble Pub.\n",
        "A Dwarf killer from the home of Dwarves.\n",
	"A Rolling rock from the fine brewers in Tharis.\n",
	"A Vodka from far lands.\n",
        "A pale ale brewed in the farming fields outside Tharis.\n"
        })
    );
} 
