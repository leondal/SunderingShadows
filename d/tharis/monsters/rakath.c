#include <std.h>
inherit BARKEEP;

void create() {
    ::create();
    set_property("no bump", 1);
    set_name("Rakath");
    set_id(({"rakath","Rakath","barkeep"}));
    set_short("Rakath, Proprietor of the Merchant's cup");
    set("aggressive", 0);
    set_level(12);
    set_long(
@OLI
   Rakath is a tall thin armed man. He would be called skinny if it
weren't for the massive bulge around his mid section. Often you wonder
how this man's skinny legs can hold up the massive girth of his belly.
His girth doesn't seem to slow him down at all as he slips back and 
forth with meals and drinks.
OLI

	    );
    set_gender("male");
    set_alignment (122);
    set_race("human");
    set_hp(300);
    add_money("gold", random(200));
    set_body_type("human");
    set_currency("silver");
    set_menu(
        ({
	"tharisian ale","tsarven wine","forest water","bread","squirrel stew","side of meat","rakath's special blend",
        }),
        ({ "alcoholic", "alcoholic", "water","food","food","food","alcoholic" }),
        ({ 25, 15, 30, 10, 15, 25, 45})
    );
    set_my_mess(
        ({
       "You drink the dark frothy brew and taste the blend of dwarven and gnomish heritage.",
       "You drink this dark sun ripened wine of the arid grapes of Tsarven",
       "Clean and clear this water comes from the springs in the forest surrounding Tharis.",
       "Freshly baked on the hearth of a blazing fire.",
       "The meat is light but filling, the gravy and vegetables are tasty.",
       "This side of meat is large. Taken from the ribs of a local steer, this is dark and juicy.",
       "This blend is strong, you can taste the strong level of distillation in its bitter after taste.",
        })
    );
    set_your_mess(
        ({
        "drinks the frothy brew and wipes "+TP->query_possessive()+" mouth clean.",
	"drinks the dark wine with lust.",
	"gulps down the refreshing water.",
	"tears pieces of the bread and gulps them down.",
	"eats the stew and licks up the gravy.",
	"tears at the meat like an animal at a carcass.",
	"winces as the liquid burns its way down.",
        })
    );
    set_menu_short(
        ({
        "Tharisian ale",
	"Tsarven wine",
	"Forest water",
	"Loaf of bread",
        "Squirrel stew",
	"Side of meat",
	"Rakath's special",
        })
    );
    set_menu_long(
        ({
       "This is a dark mug of the famous Tharisian ale.",
       "This is an imported wine from the arid area of Tsarven Empire.",
       "This is a cup of the clean water from the springs of the surrounding forest.",
       "This is a loaf of freshly baked bread.",
       "This is a mixture of squirrel meat vegetables and some fine gravy.",
       "This is a side of meat from a rather large animal.",
       "This is the dark liquid that Rakath makes in a hidden back room of his bar.",
        })
    );
} 
int should_interact(object ob){ return 1;}
