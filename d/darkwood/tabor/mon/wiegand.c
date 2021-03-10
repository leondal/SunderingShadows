// Wiegand, Bartender of the Crown and Castle
// Wiegand was killed - new Bartender - Cythera 11/05
// Thorn@ShadowGate
// 000922
// Tabor
// wiegand.c

#include <std.h>

inherit BARKEEP;

create() {
  ::create();
  set_property("no bump", 1);
  set_name("Tamir");
  set_id( ({ "tamir","tamir alrazan", "bartender" }) );
  set_short("Tamir Alrazan, Bartender of the Crown and Castle");
  set("aggressive", 0);
  set_long(
//@TABOR
//Wiegand is an old soldier who is full of stories about fighting the
//goblins to the north and serving with the Tabor mercenaries that serve
//in the Imperial Army of Tsarven to the south.  Wiegand talks a lot, but
//like any bartender, he knows when to listen too.
//TABOR
  @CYTHERA
Tamir is a swarthy skinned male human hailing from the Tsarven Empire.  Dressed in a cream colored shirt, an embroidered red vest and a pair of full pants, Tamir's clothing makes him stand out more in the north than blend in.   His dark black hair is cropped short.  Though clean shaven, he has a prominent five o'clock shadow.  An easy grin is always on his face, inviting and calming others since he has started working for the Crown and Castle.
CYTHERA
  );
  set_gender("male");
  set_alignment(2);
  set("race", "human");
  set_level(12);
  set_hd(12,2);   
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_mp(random(400));
  set_max_mp(query_mp());
  add_money("copper", random(20));
  set_exp(20);
  set_body_type("human");
  set_currency("silver");
  set_menu(
      ({"pomegranate wine", "ginger tea", "coconut milk", "blinkdog", 
         "purple ale", "delorn's delight", "water", "coffee"}),
      ({ "alcoholic", "soft drink", "soft drink", "alcoholic", "alcoholic", 
         "alcoholic", "water", "caffeine"}),
      ({ 25, 10, 8, 40, 40, 15, 1, 5 })
  );
  set_my_mess(({
    "You go to take a small sip of the wine, but can't help but finish "+
       "the exotic fruity drink.\n",
    "The ginger tea clears your mind as it warms your throat.\n",
    "The creamy flavor of coconut with just a hint of spice.\n",
    "You blink rapidly as you down the delicious fruity concoction!\n",
    "You drink the strangely sweet ale as the aroma of dates rises "+
       "from the glass.\n",
    "The taste of the rum is masked somewhat by the sweetness of chocolate "+
       "and coconut milk.\n",
    "The water quenches your thirst.",
    "The hot coffee opens your eyes a bit."
  }));
  set_your_mess(({
    "raises a wine glass to take a sip, but ends up gulping the wine down!\n",
    "sips the warm ginger tea with closed eyes and a quiet smile.\n",
    "drinks a glass of sweet coconut milk.\n",
    "downs the fruity drink and blinks rapidly.\n",
    "drinks a mug of purple ale.\n",
    "giggles like a kid and drinks the chocolate concoction.\n",
    "guzzles a glass of water.\n",
    "sips the bitter hot coffee.\n"
  }));
  set_menu_short(({
    "Pomegranate Wine",
    "Ginger Tea",
    "Coconut Milk",
    "Blinkdog",
    "Purple Ale",
    "Delorn's Delight",
    "A mug of water",
    "A cup of coffee"
  }));
  set_menu_long(({
    "%^BOLD%^%^RED%^A deep ruby red color liquid with a %^MAGENTA%^pink "+
       "%^RED%^cast to it.  The wine has a fruity and exotic bouquet.%^RESET%^\n",
    "%^YELLOW%^This strong tea is made of ginger root and allspice, sweetened "+
       "with a hint of honey.%^RESET%^\n",
    "%^BOLD%^%^WHITE%^Thick, creamy coconut milk served in a squat "+
       "glass shaped like a coconut!%^RESET%^\n",
    "%^BOLD%^%^MAGENTA%^This fruity drink is deceptively smooth and sweet.  "+
       "Brewed from a secret recipe, it's said to contain apple juice, apricot "+
       "brandy, vodka, and champagne, and a certain secret incredient no one "+
       "can figure out.  It's a favorite of the locals in Tabor - just one sip "+
       "and you'll see where it gets its name.\n",
    "%^MAGENTA%^A thick mug holds an even thicker purple ale.  Even strong "+
       "enough for the Lutgehr Brothers, this ale is distilled from dates "+
       "by a process known only to gnomes.\n",
    "%^ORANGE%^Delorn, the town's psychic, once drank so many of these that they "+
       "are now named after him.  A delicious blend of dark rum, light "+
       "rum, whiskey, coconut, ice, and...%^BOLD%^%^BLACK%^CHOCOLATE"+
       "%^RESET%^%^ORANGE%^!!%^RESET%^\n",
    "%^BOLD%^%^CYAN%^A clear and filtered water, from nearby streams.%^RESET%^\n",
    "%^BOLD%^%^BLACK%^A bitter strong coffee. Sure to help sober "+
       "you up a bit.%^RESET%^\n"
  }));
}

void init(){
    ::init();
}
