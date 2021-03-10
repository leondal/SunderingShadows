//Stef Caradan


#include <std.h>

inherit BARKEEP;

create() {
  ::create();
  set_property("no bump", 1);
  set_name("waitress");
  set_id( ({ "stefanie","stefanie Bergun", "Stefanie Bergun", "waitress" }) );
  set_short("%^RESET%^%^MAGENTA%^Stefanie Bergun, Wa%^RESET%^%^BOLD%^%^"+
"MAGENTA%^i%^RESET%^%^MAGENTA%^tre%^RESET%^%^WHITE%^s%^RESET%^%^MAGENTA%^"+
"s of t%^RESET%^%^WHITE%^h%^RESET%^%^MAGENTA%^e Tr%^RESET%^%^BOLD%^"+
"%^MAGENTA%^a%^RESET%^%^MAGENTA%^der Caf%^RESET%^%^BOLD%^%^MAGENTA%^e%^RESET%^");
  set("aggressive", 0);
  set_long("%^RESET%^%^MAGENTA%^A young woman, most likely in her early"+
" twenties, Stefanie is dressed in a %^RESET%^%^BOLD%^%^MAGENTA%^sim%^RESET%^"+
"%^MAGENTA%^p%^RESET%^%^BOLD%^%^MAGENTA%^le purple dre%^RESET%^%^MAGENTA%^s"+
"%^RESET%^%^BOLD%^%^MAGENTA%^s %^RESET%^%^MAGENTA%^covered by an %^RESET%^"+
"%^ORANGE%^apron%^RESET%^%^MAGENTA%^. Her %^RESET%^%^RED%^cu%^RESET%^%^BOLD%^"+
"%^RED%^r%^RESET%^%^RED%^ly red %^RESET%^%^BOLD%^%^RED%^h%^RESET%^%^RED%^air "+
"%^RESET%^%^MAGENTA%^falls in waves over her shoulders and %^RESET%^%^BOLD%^"+
"%^GREEN%^de%^RESET%^%^GREEN%^e%^RESET%^%^BOLD%^%^GREEN%^p g%^RESET%^%^GREEN%^"+
"r%^RESET%^%^BOLD%^%^GREEN%^een eye%^RESET%^%^GREEN%^s%^RESET%^%^BOLD%^%^GREEN%^"+
" %^RESET%^%^MAGENTA%^greet each customer with a sparkle of someone who loves "+
"what they do. A %^RESET%^%^BOLD%^%^BLACK%^grease pencil %^RESET%^%^MAGENTA%^is "+
"tucked behind one ear and she carries a tray with a small %^RESET%^%^ORANGE%^sheet"+
" of parchment %^RESET%^%^MAGENTA%^to take orders.%^RESET%^");
  set_gender("female");
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
  set_currency("gold");
  set_menu(
      ({"late harvest red wine", "aged whiskey", "traders pale ale", "dark coffee", 
         "sweet coffee", "lemon iced tea", "chicken herb wrap", "chef's salad",
        "pulled pork sandwich", "chocolate swirl cheesecake", "rice pudding"}),
      ({ "alcoholic", "alcoholic", "alcoholic", "caffeine", "caffeine", 
         "soft drink", "food", "food", "food", "food", "food"}),
      ({ 10, 30, 8, 5, 8, 5, 12, 10, 12, 10, 5 })
  );
  set_my_mess(({
    "You tip the glass back and drink the deep red wine.\n",
    "The whiskey goes down perfectly and you feel it's warmth spread through you.\n",
    "The ale has a light body and as you drain the glass you feel like another.\n",
    "The bitter coffee's warmth spreads through you.\n",
    "The sugared milk adds just the right amount of sweetness to the bitter coffee.\n",
    "The iced tea is a perfect balance of sweetness and refreshment.\n",
    "You eat the wrap with both hands, enjoying the lightly seasoned chicken.\n",
    "The produce in the salad is in perfect ripeness, and you feel healthier just for"+
" having chosen it.\n",
    "You eat the pork sandwich quickly to avoid spilling the contents. The strange spices adding"+
" an amazing taste to the pork and make your eyes water.\n",
    "You eat the cheesecake slowly, relishing the dark rich taste.\n",
    "You pick the raisins out of the rice pudding as you eat it, leaving them in the dish.\n"
  }));
  set_your_mess(({
    "drinks the wine with a smile.\n",
    "downs the whiskey, licking their lips.\n",
    "drinks the pint of ale, then looks at the glass as if pondering.\n",
    "drinks the coffee and stretches.\n",
    "licks foam from their lips as they finish the coffee.\n",
    "quickly drinks the iced drink.\n",
    "eats the chicken wrap slowly.\n",
    "eats the salad then smiles.\n",
    "seems to be in a hurry to eat the pork sandwich.\n",
    "eats the cheesecake slowly, enjoying every last bite.\n",
    "picks raisins out of the pudding as they finish it.\n"


  }));
  set_menu_short(({
    "Late Harvest Red Wine",
    "Aged Whiskey",
    "Traders Pale Ale",
    "Dark Coffee",
    "Sweet Coffee",
    "Lemon Iced Tea",
    "Chicken Herb Wrap",
    "Chef's Salad",
    "Pulled Pork Sandwich",
    "Chocolate Swirl Cheesecake",
    "Rice Pudding"

  }));
  set_menu_long(({
    "%^RESET%^%^RED%^A deep red wine harvested from Tabor grapes picked "+
"just at the first frost, this wine has a deep rich taste with a heady "+
"scent.%^RESET%^\n",
    "%^RESET%^%^ORANGE%^A dwarven whiskey stored in used wine barrels "+
"for twenty years, this drink is a deep amber color with a smoky "+
"scent.%^RESET%^\n",
    "%^RESET%^%^ORANGE%^A full pint of light coloured beer, a thin "+
"foamy head tops the glass.%^RESET%^\n",
    "%^RESET%^%^BOLD%^%^BLACK%^This small cup of coffee is almost pure"+
" black. The beans are imported from the depths of the Tsarven Empire "+
"and have been roasted until the coffee produced is thick and bitter"+
".%^RESET%^\n",
    "%^RESET%^%^ORANGE%^A local creation, this mug of %^RESET%^%^BOLD%^"+
"%^BLACK%^thick black coffee %^RESET%^%^ORANGE%^has been mixed with a "+
"%^RESET%^%^BOLD%^%^WHITE%^sugared milk %^RESET%^%^ORANGE%^that has "+
"been steamed until it is a rich %^RESET%^%^BOLD%^%^WHITE%^foam%^RESET%^"+
"%^ORANGE%^. %^RESET%^%^RED%^Cinnamon %^RESET%^%^ORANGE%^has been ground"+
" up and the drink is served with a %^RESET%^%^RED%^cinnamon stick "+
"%^RESET%^%^ORANGE%^as a straw.%^RESET%^\n",
    "%^RESET%^%^BOLD%^%^WHITE%^A tall glass has been filled with a "+
"mixture of water, sugar, and whole chunks of %^RESET%^%^YELLOW%^lemons"+
"%^RESET%^%^BOLD%^%^WHITE%^. The rim of the glass is covered with "+
"sugar.%^RESET%^\n",
    "%^RESET%^%^ORANGE%^Grilled chicken is mixed in with %^RESET%^%^BOLD%^"+
"%^GREEN%^lettuce%^RESET%^%^ORANGE%^, %^RESET%^%^BOLD%^%^RED%^tomato "+
"%^RESET%^%^ORANGE%^and various other %^RESET%^%^YELLOW%^vegetables "+
"%^RESET%^%^ORANGE%^and wrapped up in a thin bread. A long toothpick "+
"holds the wrap together and is topped with a small %^RESET%^%^RED%^red"+
" flag.%^RESET%^\n",
    "%^RESET%^%^BOLD%^%^GREEN%^This salad is full of every vegetable "+
"possible. There is almost an entire head of %^RESET%^%^GREEN%^lettuce "+
"%^RESET%^%^BOLD%^%^GREEN%^in it and the slices of %^RESET%^%^GREEN%^"+
"cucumber%^RESET%^%^BOLD%^%^GREEN%^, %^RESET%^%^BOLD%^%^RED%^tomatos"+
"%^RESET%^%^BOLD%^%^GREEN%^, and the rest almost overflow from the bowl."+
" A %^RESET%^%^ORANGE%^light oil %^RESET%^%^BOLD%^%^GREEN%^has been "+
"drizzled over the salad. %^RESET%^\n",
    "%^RESET%^%^ORANGE%^Served on a large sandwich bun, the %^RESET%^"+
"%^RED%^pork %^RESET%^%^ORANGE%^in this meal is almost overflowing. It "+
"has been torn into strands rather then cut, and a %^RESET%^%^RED%^thick"+
" sauce %^RESET%^%^ORANGE%^has been added. The spices in this are brought"+
" specially by Babra from his contacts deep in the south and they are a "+
"close guarded secret. A %^RESET%^%^BOLD%^%^GREEN%^pic%^RESET%^%^GREEN%^k"+
"%^RESET%^%^BOLD%^%^GREEN%^le s%^RESET%^%^GREEN%^p%^RESET%^%^BOLD%^%^GREEN%^"+
"ear %^RESET%^%^ORANGE%^is the only garnish served on the plate.%^RESET%^\n",
    "%^RESET%^%^ORANGE%^A favorite of the traders and clerks, this desert "+
"is made daily by Stefanie. A thin slice of %^RESET%^%^BOLD%^%^BLACK%^dark "+
"chocolate %^RESET%^%^ORANGE%^cheesecake with swirls of %^RESET%^%^BOLD%^"+
"%^WHITE%^white chocolate %^RESET%^%^ORANGE%^is served on a plate dusted "+
"with %^RESET%^%^BOLD%^%^WHITE%^sugar %^RESET%^%^ORANGE%^and drizzled with"+
" %^RESET%^%^BOLD%^%^WHITE%^white %^RESET%^%^ORANGE%^and %^RESET%^%^BOLD%^"+
"%^BLACK%^dark %^RESET%^%^ORANGE%^chocolate. Two forks are placed on the "+
"plate, as if you would share this!%^RESET%^\n",
    "%^RESET%^%^BOLD%^%^WHITE%^Served in a small bowl, this rice pudding "+
"is a thick desert of %^RESET%^%^WHITE%^rice %^RESET%^%^BOLD%^%^WHITE%^"+
"enveloped in a silky sugar flavored milk. %^RESET%^%^ORANGE%^Th%^RESET%^"+
"%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ck jui%^RESET%^%^BOLD%^%^BLACK%^c%^RESET%^"+
"%^ORANGE%^y r%^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^isins %^RESET%^"+
"%^BOLD%^%^WHITE%^have been mixed throughout it, adding the interesting "+
"contrast of color and taste.%^RESET%^\n"

  }));
}
