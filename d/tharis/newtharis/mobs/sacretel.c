#include <std.h>
inherit BARKEEP;

void create() {
    ::create();
    set_property("no bump", 1);
    set_name("sacretel");
    set_id( ({ "sacretel", "Sacretel","barkeep" }) );
    set_short("Sacretel, spit master and brewsman of the Turning Spit Tavern");
    set("aggressive", 0);
    set_level(12);
    set_long(
@OLI
   This droopy-eyed middle-aged man has dark rough hands from frequently
handling the spit and the hot coals under it. He takes this task very 
seriously. He has a high brow with deep dark yet receeding hair. Clean shaven,
he looks around the tavern as he paces back and forth between the bar and 
the turning spit. Occasionally he will pour some spicey smelling liquid over
the turning meat. You can hear the liquid pop and sizzle as it hits the hot 
coals.
OLI

	    );
    set_gender("male");
    set_alignment (1);
    set_race("human");
    set_hp(300);
    add_money("gold", random(200));
    set_body_type("human");
    set_currency("silver");
    set_menu(
        ({
	     "tharisian dark lager","fire roasted nuts","verbonese ale","traveler's meal","spit turned meat","cravnarian wine",
        }),
        ({ "alcoholic", "food", "alcoholic","food","food","alcoholic",}),
        ({ 30, 30, 15, 15, 20, 25, 65})
    );
    set_my_mess(
        ({
       "You drink the extremely dark, thick lager and feel it as it rolls down your throat.",
       "You crunch the roasted nuts as your chew.",
       "You drink the golden ale and wince at the slight bite it offers back.",
       "You eat the sparse but painfully healthy meal.",
       "You eat the tender well cooks piece of spicey meat with lust and vigor.",
       "You drink down the red tinted ale quickly in a single gulp.",
        })
    );
    set_your_mess(
        ({
	      "pours the thick dark brew down "+TP->query_possessive()+" gullet.",
   	   "crunches on some nuts.",
	      "drinks the golden ale slowly.",
	      "eats the sparse yet healthy looking meal.",
   	   "tears into the fragrant meat fresh from the spit.",
	      "gulps down the red tinted wine.",
        })
    );
    set_menu_short(
        ({
	      "Tharisian dark lager",
	      "Fire Roasted Nuts",
	      "Verbonese Ale",
	      "Traveler's Meal",
   	   "Spit Turned Meat",
	      "Cravnarian Wine",
        })
    );
    set_menu_long(
        ({
       "This is a dark dark dark brew, famous to Tharis. this brew doesn't even slosh it sorta oozes.",
       "This is a small package of various nuts that are roast along with the meat on the spit.",
       "This is the golden ale imported from the city of Verbone across the ocean.",
       "This is a well packaged little meal made of more nutrious stuffs for the active traveler.",
       "This is a grand hunk of sizzling, well spiced meat from the spit at the Turning Spit Tavern.",
       "This is a small glass of imported wine from the legendary ciy of Cravnari, the sister city to Tharis to the south of the mountains.",
        })
    );
} 
