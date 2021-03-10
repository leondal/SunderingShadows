//updated by Circe 4/1/05
#include <std.h>
inherit BARKEEP;
void create() {
    ::create();
    set_property("no bump", 1);
    set_name("iladeth");
    set_id(({"iladeth","Iladeth","barkeep","waiter","bartender"}));
    set_short("Iladeth, rough and tumble bartender of The Last Stand");
    set_level(12);
    set_long(
      "This rough-edged looking fellow seems like he could "+
      "very well have given this tavern its name.  His bristly "+
      "brown and gray beard has holes in it where you see scars "+
      "showing through, and his eyebrows have grown together in "+
      "a long bushy line.  His eyes glitter beneath, quick to "+
      "twinkle at a joke or flash dangerously at a fight that "+
      "threatens his business.  His burned arms are riddled "+
      "with scars, and the tail end of a tattoo is just visible "+
      "beneath the edge of his sleeve.  Obviously he has had "+
      "to break up a few fights.");
    set_gender("male");
    set_alignment(6);
    set_race("human");
    set_hp(300);
    add_money("gold", random(200));
    set_body_type("human");
    set_currency("copper");
    set_menu(
        ({
	"tharisian ale","tharisian dark lager","dark liquid","old bread","meat stew","full meal","the last stand",
        }),
        ({ "alcoholic", "alcoholic", "water","food","food","food","alcoholic" }),
        ({ 25, 30, 5, 10, 15, 25, 65})
    );
    set_my_mess(
        ({
       "You drink the dark frothy brew and taste the blend of dwarven and gnomish heritage.",
       "You drink the extremely dark, thick lager and feel it as it rolls down your throat.",
       "This liquid tastes like gritty water.",
       "This bread is obviously old, but you eat it anyway.",
       "As you chew and chew you wonder what meat it was today.",
       "This plate of food will actually serve to fill you up.",
       "You feel pain and then numbness, then the world starts to spin.",
        })
    );
    set_your_mess(
        ({
        "drinks the frothy brew and wipes "+TP->query_possessive()+" mouth clean.",
	"pours the thick dark brew down "+TP->query_possessive()+" gullet.",
	"seems to chew something as "+TP->query_subjective()+" drinks.",
	"tears pieces of the bread and gulps them down and then looks at the bread sorta funny",
	"eats the stew and seems to ponder each peice of meat.",
	"eats the meal less than zealously.",
	"eyes cross and arms go limp.",
        })
    );
    set_menu_short(
        ({
        "Tharisian ale",
	"Tharisian dark lager",
	"Dark liquid",
	"Old bread",
	"Meat stew",
	"Full meal",
	"The last stand",
        })
    );
    set_menu_long(
        ({
       "This is a dark mug of the famous Tharisian ale.",
       "This is a dark dark dark brew, famous to Tharis. this brew doesn't even slosh it sorta oozes.",
       "This is a cup of very dark water. Seems there is some stuff in it.",
       "This is a hunk of some old bread. There doesn't appear to be any mold on it.",
       "This is a mixture of some unknown meat and some thin gravy",
       "This at least looks like a full meal. There appears to be all the major food groups in it.",
       "This is the drink that gave the bar its name.One of the most toxic and powerful drink available, it has even been outlawed in cities like antioch and tonovi.",
        })
    );
} 
