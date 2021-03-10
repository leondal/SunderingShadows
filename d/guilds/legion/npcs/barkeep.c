#include <std.h>

inherit BARKEEP;

create() {
    ::create();
    set_property("no bump", 1);
    set_name("Grobo");
    set_id( ({"grobo", "Grobo", "barkeep"}) );
    set_short("Grobo the Lush");
    set("aggressive", 0);
    set_level(23);
    set_exp(10);
    set_long(
      "Grobo is a tall human, getting on in his years.  Once a great member of this guild, he was well known for his ability to drink 4 times as much as anyone else, and not have a slur in his speech.  Still today he drinks about as much as he passes out, but then again, he doesn't have the same ability to hold his liquor, and passes out himself many nights."
    );
    set_gender("male");
    set_alignment(9);
    set("race", "human");
    set_hp(400);
    add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_exp(5);
    set_menu(
      ({
	"hillbilly piss", "milk", "aftershock", "black coffee"
      }),
      ({ "alcoholic", "water", "alcoholic", "water" }),
      ({20,10,60,5})
    );
    set_my_mess(
      ({
	"%^YELLOW%^The sweet bubbling yellow liquid burns your throat as it goes down.\n",
	"%^BOLD%^Milk, does a body good.\n",
	"%^RED%^You take a shot of the strange red liquid, and a pleasing taste of cinnimon fills your mouth as it warms your stomach.\n",
	"You almost gag on the harsh tasting black liquid.\n",
      })
    );
    set_your_mess(
      ({
	"licks "+TP->query_possessive()+" lips repeatedly trying to get rid of the taste.\n",
	"looks up with a smile on his face and says, Milk, does a body good.\n",
	"gets a large smile on "+TP->query_possessive()+" face as the strange liquid slides down into his stomach.\n",
	"makes a strange face as the bitter coffee burns on the way down.\n",
      })
    );
    set_menu_short(
      ({
	"%^YELLOW%^Hillbilly Piss",
	"%^BOLD%^Milk",
	"%^RED%^AfTeRsHoCk",
	"A mug of black Coffee",
      })
    );
    set_menu_long(
      ({
	"A glass of a bubbling yellow concotion.  Somone said it's like the dew from the mountains.\n",
	"%^BOLD%^Cow Milk.\n",
	"A deep red substance in a glass shotglass.\n",
	"A mug of pitch black, wake you up, Coffee.",
      })
    );
}
