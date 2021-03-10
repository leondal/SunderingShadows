#include <std.h>
inherit BARKEEP;

void create() {
  ::create();
  set_name("Penny");
  set_id(({"penny","waitress","waitstaff"}));
  set_emotes(1,({
   "Penny wipes a table down and straightens the flower arrangement on it.",
   "Penny smiles sweetly at you.",
   "Penny wanders around and straightens a few chairs.",
   "Penny glances toward the door then sits down with a cup of coffee."
  }),0);
  set_property("always interact",1);
  set_short("Penny the waitress");
  set("aggressive", 0);
  set_level(10);
  set_long(
  "This tall girl has bright eyes and an open cheery face, which reminds you of someone but you can't put your finger on it."
  "  She bustles about and makes sure anyone who passes through here is at home."
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
  "fish and chips",
  "seafood gumbo",
  "salad",
  "seared swordfish",
  "shucked oysters",
  "water",
  "tea",
  }),({
   "food","food","food","food","food","water","water",
  }),
  ({
  20,15,5,25,40,1,2
  }));
  set_my_mess(({
  "Mmm, saltwater bass and fried potato sprinkled with vinegar, nothing"+
  " hits the spot like that does sometimes.",
  "Chunky bits of seafood in a creamy gumbo that steams and smells of the sea.",
  "Healthy yes, terribly filling, no.",
  "The swordfish is delicious with great flavor.",
  "You swallow the slippery little oysters down.",
  "The water has a slight aftertaste of salt but is still refreshing.",
  "The herbal tea is hot and delicious.",
  }));
  set_your_mess(({
  "chows down on a couple pieces of battered fish and some vinegary smelling fried potatoes.",
  "pokes at a bowl of chunky, creamy stew and finally finishes it.",
  "nips at a few pieces of green leafy lettuce and a tomato.",
  "enjoys a plate of lightly seared fish.",
  "slurps down a few raw oysters out of their half shells.",
  "chugs some refreshing water.",
  "has a glass of fragrant herbal tea."
  }));
  set_menu_short(({
  "Fish and Chips",
  "Seafood Gumbo",
  "Salad",
  "Seared Swordfish",
  "Shucked Oysters",
  "Water",
  "Tea",
  }));
  set_menu_long(({
  "A couple of pieces of battered sea bass served in a basket with some"+
  " fried potatoes dripping with viniger.",
  "A bowl of chunky white soup with bits of things floating about in it.",
  "A plate piled with green leaf lettuce and a few pieces of tomato and"+
  " some other garden vegetables.",
  "The swordfish has been removed of most bones and sliced long and"+
  " thin, then seasoned with herbs and lightly seared.",
  "A plate of raw oysters on the half shell.",
  "A glass of refreshing water.",
  "A glass of steaming, fragrant herbal tea.",
  }));
}
