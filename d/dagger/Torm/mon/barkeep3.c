#include <std.h>
inherit BARKEEP;

void create() {
  ::create();
  set_name("Caliny");
  set_id(({"Caliny","waiter","caliny","waitstaff"}));
  set_emotes(2,({
    "Caliny slams a plate down on a table, giving the customer a dirty look and "
       "goes back to picking his fingernails at the back of the restaurant.",
     "Caliny clears a table, muttering to himself.",
     "Caliny glances up from his seat at the back of the restaurant, looking bored."
  }),0);
  set_property("always interact",1);
  set_short("Caliny, your surly waiter");
  set("aggressive", 0);
  set_level(10);
  set_long(
  "This large burly human spends a great deal more time picking his fingers with a table knife than making sure his establishment is clean."
   "  Every once in a while you can hear shouts in orcish from the kitchen and he takes a quick peek, yells something and returns to his self manicure."
   "  Despite his obsession with his fingernails, he is not the cleanest of people.  His black hair is rather greasy and has been pulled back into a loose pony tail.  His shirt and pants could use a good wash, as well as the rest of him."
  );
  set_gender("male");
  set_alignment(4);
  set("race", "human");
  set_hd(10,0);
  set_exp(10);
  set_max_hp(query_hp());
  add_money("copper", random(200));
  set_body_type("human");
  set_currency("gold");
  set_menu(({
  "liver and onions",
  "seafood gumbo",
  "steak",
  "dark ale",
  "brackish water"
  }),({
  "food","food","food","alcoholic","water"
  }),
  ({
  20,10,15,20,1
  }));
  set_my_mess(({
  "Hmm, that was awfully tough to have been liver.",
  "Chunky is about the best this mixture can be described, as it's"+
    " been far too overcooked to have much flavor left.",
  "You wonder if the cook is missing some shoe leather as you choke down"+
    " the last bit of overcooked steak.",
  "Hmm, that isn't a bad ale and it's got a neat bottle, you wonder if"+
    " the coakroach stuck in it cost extra or if you got if for free.",
  "Looks like dishwater... tastes like dishwater...",
  }));
  set_your_mess(({
  "suddenly smells a lot like an onion left in the sun too long as they"+
    " devour a blackened piece of meat covered in onions.",
  "pokes at a bowl of chunky, creamy stew and finally finishes it.",
  "looks like a dog gnawing on a bone as they tear at a piece of what"+
    " might have been steak, or possibly a boot.",
  "takes a deep drink from a dark ale and then looks closely at"+
    " something moving in the empty bottle...",
  "gulps down the water and makes a face.",
  }));
  set_menu_short(({
  "Liver and onions",
  "Seafood Gumbo",
  "Steak",
  "Dark Ale",
  "Brackish Water"
  }));
  set_menu_long(({
  "A plate full of blackened onions over a bit of tough greyish pink meat.",
  "A bowl of white, thick soup with bits of chunky colorful things"+
    " floating in it.",
  "A hard, leathery looking thing. Dry, tasteless other than burnt."+
    " Hmm, not that bad for some though.",
  "A dark ale, with just a touch of foam at the top, it's swirling a"+
    " little like something's doing the backstroke in it.",
  "Water, with a twist of dirt."
  }));
}
