//She was hired by the Fist guild and is used in the guilds dir now.
//Her menu items were combined with barkeep6's who now served both rooms.
//*Styx*  3/9/02

#include <std.h>
inherit BARKEEP;

void create() {
  ::create();
  set_name("Melissa");
  set_id(({"melissa","waitress","waitstaff", "Melissa"}));
  set_emotes(1,({
   "Melissa smiles sweetly at you.",
   "Melissa wipes a table down and straightens the flower arrangement on it.",
  }),0);
  set_property("always interact",1);
  set_short("Melissa the waitress");
  set("aggressive", 0);
  set_level(10);
  set_long(
  "This tall girl has bright eyes and an open cheery face, which reminds you of someone but you can't put your finger on it."
   "  She is quite busy making sure that everyone's orders are filled and that the food meets their standards. She is wearing a nice summer dress in blues and greens with a silk belt tied around her waist."
  );
  set_gender("female");
  set_alignment(4);
  set("race", "human");
  set_hd(10,0);
  set_exp(10);
  set_max_hp(query_hp());
  add_money("copper", random(200));
  set_body_type("human");
  set_currency("gold");
  set_menu(({
  "salmon filet",
  "crab bisque",
  "watercress salad",
  "seafood fettucini",
  "sashimi",
  "water",
  "mint tea",
  }),({
   "food","food","food","food","food","water","water",
  }),
  ({
  25,15,10,25,40,1,2
  }));
  set_my_mess(({
  "The warm, tender flakes of the salmon melt in your mouth.",
  "The bisque has a deliciously light flavor and is incredibly creamy.",
  "The watercress salad is most interesting, though an acquired taste.",
  "The sauce these noodles are doused in certainly brings out the delicate flavor of the crab, baby clams and shrimp in a good way.",
  "The sashimi is cool and light, the sauce has a nice tangy flavor.",
  "The water is cool and refreshing with a twist of lemon.",
  "The mint tea cools you down and leaves your mouth feeling fresh.",
  }));
  set_your_mess(({
  "seems to enjoy the salmon filet.",
  "eats the entire bowl of creamy crab bisque.",
  "slowly eats the watercress salad.",
  "enjoys a delicious looking noodle dish.",
  "dips each slice of sashimi and a dark sauce and swallows it down.",
  "drinks some refreshing water.",
  "has a glass of mint tea."
  }));
  set_menu_short(({
  "Salmon Filet",
  "Crab Bisque",
  "Watercress Salad",
  "Seafood Fettucini",
  "Sashimi",
  "Water",
  "Mint Tea",
  }));
  set_menu_long(({
  "The salmon filet has been lightly grilled and is a light orange-pink"+
  " in color. It appears flaky and delicious, free of bones.",
  "A thick pale blue bowl decorated with seahorses holds the crab"+
  " bisque. It looks thick and creamy.",
  "This is an exotic salad filled with slightly wilted watercress"+
  " leaves. It is supposed to be a delicacy.",
  "A delicious looking plate of thin long noodles, smothered in a creamy"+
  " sauce with baby clam, bits of crab and shrimp in it.",
  "This is a plate of raw fish that has been sliced into slender pieces"+
  " and placed on a bed of shredded cabbage. There is a small dish of"+
  " dark sauce that you dip the fish in. It is a foreign dish that has"+
  " become quite popular with Torm's nobility.",
  "A glass of refreshing water with a twist of lemon.",
  "A glass of cool mint tea.",
  }));
}
