#include <std.h>
inherit BARKEEP;

// Tharis Duke's Hunting Lodge - attendant.c  (hunting lodge)
// LoKi - August 2008

create() {
  ::create();
  set_property("no bump", 1);
  set_name("attendant");
  set_id( ({"fordel","Fordel","attendant","lodge attendant"}) );
  set_short("%^RESET%^%^ORANGE%^Fordel the Lodge Attendant");

  set_long("");


  set_gender("male");
  set_alignment(5);
  set("race","human");
  set_level(15);
  set("aggressive", 0);
  set_hd(12,2);   
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_mp(random(400));
  set_max_mp(query_mp());
  add_money("copper", random(20));
  set_exp(20);
  set_body_type("human");
  set_currency("platinum");
  
  
  set_menu(
      ({"a snifter of cognac","a glass of berrywine","a flute of sparkling cider",
	  "a glass of mountain spring water","cold roasted boar sandwich","almond crusted trout filet",
	  "pinenut and wild greens salad","sampling of cheeses"}),
      ({"alcoholic","alcoholic","soft drink","soft drink","food","food","food","food"}),
      ({30,20,10,5,40,25,10,10})
  );
  set_my_mess(({
    "You swirl the cognac about in the snifter, drawing in a deep breath of the slightly fruity scent before tilting the glass back and drinking the semi-sweet, thick brandy down.",
	"The deep purplish blue liquid glitters darkly in the light as you lift it to your lips and drink your fill of the slightly tart liquid.",
	"The bubbles tickle your pallet with a faint apple evanescence.",
	"The water is naturally pure and ice cold as you drink it.",
	"The tender boar falls apart as you eat the hardy sandwich down to the last bite of herbed bread.",
	"The flakey bites of trout are enhanced by the thin coating of crushed almond and sweet coconut milk breading.",
	"Roasted pine nuts crunch with every bite of the bitter greens and tart berries that are mixed into this salad.",
	"You nibble on a bit of brie, a sampling of gouda, a sliver of roquefort and several bites of creamy dry jack, rinsing it all down with a few sweet green olives."
  }));
  
  set_your_mess(({
    "swirls cognac about in their glass before taking a long drink.",
	"drinks from their glass then puckers their lips at the tartness of the berrywine.",
	"smacks their lips after drinking their glass of sparkling cider.",
	"shivers as they drink from the icy glass of mountain spring water.",
	"tears into the cold roasted boar sandwich with a voracious hunger.",
	"breaks apart their trout filet and eats the flaky bites all up.",
	"samples the wild grown greens of the salad and crunches on the roasted pine nuts.",
	"picks at a sampling of cheeses, enjoying the rich verity of offerings."
  }));
  
  set_menu_short(({
    "A Snifter of Cognac",
	"A Glass of Berrywine",
	"A Flute of Sparkling Cider",
	"A Glass of Mountain Spring Water",
	"Cold Roasted Boar Sandwich",
	"Almond Crusted Trout Filet",
	"Pine nut and Wild Greens Salad",
	"Sampling of Cheeses"
  }));
  
  set_menu_long(({
    "This pear shaped glass sits on a short stem and holds a few ounces of sweet cognac brandy.  The liquid is thick and rich, featuring a deep red shade that is almost purple in hue.  The scent is a blend of fruity overtones with a deeper earthen undertone that rolls across the tongue and warms the senses.",
	"The dark purplish blue wine is made from fermented berries collected from the forest.  Predominantly made from black and blue berries, these give the wine its dark coloration while the smaller amount of huckleberries, raspberries and salmonberries add a tart kick to the otherwise sweet blend.",
	"Ripe with the scent of tart apples and served in a long, thin flute, the cider is a pale creamy color with a myriad of evanescent bubbles trapped within.",
	"This tall glass is filled with clear, glassy orbs of frozen ice, each one carefully sculpted into round balls that tumble and clink within the glass as the pure mountain spring water begins to melt them away.",
	"Herbed bread makes a delicious contrast to the thick slabs of cold roasted boar, tangy tomatoes and mild greens which create this large and filling sandwich.  Cut in half on the diagonal, and filled with hardy portions, this sandwich would fill even the hungriest of hunters.",
	"A light and delicate selection, the almonds have been crushed into a near powder and mixed with a blend of herbs and coconut milk to make a thin breading for the filet.  Aromatic jasmine rice complements the flaky trout and is paired with a selection of baby vegetables.",
	"A blend of hand selected wild grown lettuces, greens and other vegetables are mixed into this salad and topped with a generous sprinkling of roasted pine nuts and dried berries.",
	"This small tray of cheeses features a generous selection of cheese samplings.  Complementing it are spears of roasted rosemary over which ripe green olives have been strung."
  }));

}

void init(){
    ::init();
}

