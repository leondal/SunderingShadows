#include <std.h>
inherit BARKEEP;

int greeted;
void greet_me(object targ);

void create() {
  ::create();
  set_name("Salvadare");
  set_id(({"salvadare","waiter","waitstaff", "Salvadare"}));
  set_emotes(1,({
   "Salvadare bows crisply to a customer across the room.",
   "Salvadare discretely checks his appearance in the mirror.",
   "Salvadare carefully re-arranges and refills the items on the center tables.",
   "Salvadare straightens a few chairs.",
   "Salvadare places a few drops of perfumed oil in the candelabra.",
   "Salvadare motions to a busboy and sends him scurrying to clear tables.",
  }),0);
  set_property("always interact",1);
  set_short("Salvadare the waiter");
  set("aggressive", 0);
  set_level(20);
  set_long(
@STYX
This gentleman is impeccably groomed and dressed in a dark blue, pin-striped vest worn over a long-sleeved cyan shirt.  The shirt and vest are both tailored to fit him perfectly and accentuate his broad shoulders, muscular arms, and firm, squarish jaw.  
A black leather belt tops his crisply pressed trousers and you catch clear reflections in the shine of his gleaming black leather shoes.  He looks to be in his late-twenties and has thick, dark brown hair and intense blue eyes.  You can't help but notice his impeccable manners too.
STYX
  );
  set_gender("male");
  set_alignment(2);
  set("race", "human");
  set_hd(20,20);
  set_exp(10);
  set_max_hp(query_hp());
  add_money("gold", random(50));
  set_body_type("human");
  set_currency("gold");
set_menu(({ "roast duck",  "lobster tail", "soup", "chef salad",
	    "flan",        "sherbet",      "water",  "tea",  }),
    ({ "food","food","food","food","food","food","water","water", }),
    ({  22,35,18,11,9,6,1,3  }) 
);

set_my_mess(({
"The rich succulent duck captures you in its reverie of flavor.",
"The luscious lobster compliments the satisfying prime rib.",
"The cold soup tantalizes your tastebuds.",
"The salad is cool and crisp with a tangy house dressing.",
"The flan is cool and rich, filling your taste buds to overflowing.",
"The sherbet is a rainbow of colors and flavors.",
"The water is cool and refreshing with a twist of lemon.",
"The iced herbal tea cools and calms you, leaving you refreshed.",
 }));

set_your_mess(({
"obviously enjoys the roast duck immensely.",
"greedily eats all of the lobster and prime rib.",
"sighs at the exquisite taste of the cold soup.",
"relaxes while slowly enjoying the salad.",
"savors every bite of the cool desert.",
"lets the rainbow of different flavors flow throughout their mouth.",
"drinks some refreshing water.",
"has a glass of ice cold herbal tea.",
}));

set_menu_short(({
"Roast Duck in Cranberry Sauce",
"Lobster Tail and Prime Rib",
"Gazpacho Soup",
"Chef Salad",
"Flan",
"Sherbet",
"Water",
"Iced Herbal Tea",
}));

set_menu_long(({
"The roast duck in rich and luscious in a cranberry sauce accompanied"+
  " with cranberry stuffing and asparagus spears.",
"The lobster tail is large moist and covered with butter while the prime"+
  " rib is cooked exactly to order and comes with baked potato and baby"+
  " peas in butter sauce.",
"This cold soup has cucumbers, tomatos, onions, peppers, and seasonings"+
  " in a base of tomato juice and comes with fresh bread and butter.",
"This salad has crisp fresh lettuce, sliced egg, sliced meat, and croutons.",
"A cool rich desert that is truly a mouth's delight.",
"A light ice cream desert of many colors and flavors that cleans and"+
  " refreshes the palate.",
"A glass of refreshing water with a twist of lemon.",
"A glass of ice cold, sparkling herbal tea.",
}));
}

void init() {
   ::init();
   if(greeted) {
      greeted = random(8);
      return;
   }
   if(!TP->query_invis()) {
      call_out("greet_me",2,TP);
      greeted = random(6);
   }
}

void greet_me(object targ) {
   if(!present(targ))    return;
   if( (string)TP->query_gender() == "female") {
      force_me("bow crisply to "+TPQCN);
      force_me("smile charmingly");
      force_me("say Welcome mi'lady.  My name is Salvadare and I'll be most "
        "pleased to be your waiter today.");
      return;
   };
   force_me("bow "+TPQCN+" crisply");
   force_me("say Welcome sir, my name is Salvadare and I will be your waiter today.  Please take a seat at whichever table suits you.");
   return;
}
