#include <std.h>
inherit BARKEEP;

void create() {
  ::create();
   set_nwp("eavesdropping",10,500);
  set_name("Melissa");
  set_id(({"melissa","waitress","waitstaff", "Melissa"}));
  set_emotes(1,({
   "Melissa smiles sweetly at you.",
   "Melissa wipes a table down and straightens the chairs.",
   "Melissa checks and refills the food and drinks on the center tables.",
   "Melissa hums a soft, relaxing melody, just barely audible.",
  }),0);
  set_property("always interact",1);
  set_short("Melissa the waitress");
  set("aggressive", 0);
  set_level(10);
  set_long(
  "This tall girl has bright eyes, shoulder-length, wavy brown hair and an open cheery face that reminds you of someone but you can't put your finger on who.  Maybe you just remember her from when she worked at the place on the south side of town."
   "  She is quite busy making sure that everyone's orders are filled and that the food meets their standards.  She is wearing a nice summer dress in blues and greens with a silk belt tied around her waist."
  );
  set_gender("female");
  set_alignment(5);
  set("race", "human");
  set_hd(10,0);
  set_exp(10);
  set_max_hp(query_hp());
  add_money("copper", random(200));
  set_body_type("human");
  set_currency("gold");
set_menu(({ "grilled chicken", "herb encrusted pork chops",   "pasta salad",
     "stuffed artichokes",    "chocolate mousse", "peach and champagne sorbet",
     "water",                 "herbal tea",
  }),
  ({ "food","food","food","food","food","food","water","water", }),
  ({ 20,16,8,11,6,18,1,3  })
);

set_my_mess(({
   "The grilled chicken is light and zesty tasting.",
   "The pork chops melt flavorfully in your mouth.",
   "The pasta is cool spicy and refreshing.",
   "The artichokes tease your taste buds leaving you wanting more.",
   "The cold chocolate desert satisfies your sweet tooth.",
   "The peach and champagne ice cream desert is a marvel to taste.",
   "The water is cool and refreshing with a twist of lemon.",
   "The herbal tea cools and calms you leaving you refreshed.",
}));

set_your_mess(({
  "tears into the chicken, eating readily.",
  "savors every bite of the pork chops.",
  "hmms while enjoying the zesty pasta salad.",
  "laps up every bite of the artichokes and looks up as if hoping to find more.", 
  "slowly spoons the desert with an almost reverence.",
  "seems surprised at this light and tasty desert.",
  "drinks some refreshing water.",
  "has a glass of cool herbal tea.",
}));

set_menu_short(({
  "Grilled Chicken",
  "Herb Encrusted pork chops",
  "Pasta Salad",
  "Stuffed Artichokes",
  "Chocolate Mousse",
  "Peach and Champagne Sorbet",
  "Water",
  "Herbal Tea",
}));

set_menu_long(({
  "The grilled chicken is nice and spicey and comes with black beans,"
    " white rice, and a small caesar's salad.",
  "The pork chops are wrapped in bacon and seasoned heavily with garlic,"
    " other herbs, and salt and pepper.",
  "This pasta dish is served chilled with a spiced olive oil dressing,"
    " leaf lettuce, and artichoke heart chunks.",
  "These artichokes are stuffed with a special blend of rice, herbs,"
    " seasonings, and tomato slices.",
  "A rich creamy delight that one can get lost in.",
  "A light ice cream dish with all the flavor and style that peaches and"
    " champagne can lend to it.",
  "A glass of refreshing water with a twist of lemon.",
  "A glass of cool herbal tea.",
}));

}
