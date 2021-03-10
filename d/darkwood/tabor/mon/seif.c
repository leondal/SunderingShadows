// Seif al-Islam, Master Chef of the Crown and Castle
//Seif was killed - new chef - cythera 11/05
//Hessa is the wife of Tamir the barkeep
// Thorn@ShadowGate
// 000925
// Tabor
// seif.c

inherit "/std/barkeep";

void create() {
  object obj;
  ::create();
  set_name("hessa");
  set_id( ({ "hessa", "hessa alrazan", "hostess" }) );
  set_short("Hessa Alrazan, Hostess of the Crown and Castle");
  set_level(10);
  set_long(
//"Seif al-Islam is the Master Chef of the Crown and Castle.  Trained in "
//"the culinary arts in Tsarven itself, he holds two gold medals from the "
//"Most Serene and Imperial Guild of Chefs for his famed Chilled Monkey "
//"Brains.  He came to Tabor at the invitation of Amergin who he met after "
//"losing his post as the Bey of Verhedin's personal chef due to the "
//"actions of one of his assistant cooks.  Although he often complains "
//"about the less mannered customers in Tabor, he is none the less pleased "
//"to be doing the job he loves in such an esteemed establishment.  Seif "
//"has brought many of his Tsarvani tastes to the city, and the locals "
//"have embraced many of them."
"Hessa is a swarthy skinned female hailing from the Tsarven Empire.  "+
"Dressed in an elegant sari, with brilliant gold accents, she moves "+
"freely about the cafe, instructing the staff to attend to the needs "+
"of the patrons.  Her dark black hair is neatly combed back to form a "+
"chignon at the base of her neck.  Her eyes are rimmed in khol, a "+
"standard practice for the women of the Empire.  Brass bangles adorn "+
"her arms, clinking together as she offers a greeting or a wave to the "+
"patron of the Crown and Castle."
  );
  set_gender("female");
  set_exp(20);
  set_alignment(1);
  set_race("human");
  set_hd(10,0);
  set_hp(100);
  set_max_hp(query_hp());
  add_money("gold", random(10));
  set_body_type("human");
  set_currency("silver");
  set_menu(
       ({ "chilled monkey brains", "pigs feet", "beef tenderloin", "spiced deer eyes", "tandoori chicken", "lamb masala", "cheese naan", "curry pot pie", "tabouli", "baklava",             "blackberry custard", "roasted dates", "caerveron", "mango lassi", "sikanjabin", "jasmine tea", "spiced wine", "rose water", "tsarven mead" }),
       ({ "food", "food", "food", "food", "food", "food", "food", "food", "food", "food", "food", "food", "food", "soft drink", "soft drink", "soft drink", "alcoholic", "water", "alcoholic" }),
       ({40,25,35,25,40,35,5,20,12,15,7,12,8,15,12,15,25,2,60})
   );
   set_my_mess(({
       "Oooey, gooey, grey matter always hits the spot!\n",
       "Tastes much like salted pork...oh, wait.\n",
       "Perfect cut of meat, melts in your mouth!\n",
       "These deer eyes aren't bad.  Squishy, but not bad.\n",
       "The spicy chicken seems to melt in your mouth...delicious!\n",
       "The fantastic sauce makes your mouth tingle!\n",
       "Gooey cheese mixed with fresh, wholesome flatbread...fantastic!\n",
       "The curry definitely spices up this warm pot pie.\n",
       "Bulgar wheat and spices.  Its not high cuisine, but its filling.\n",
       "The cinnamon and cloves bring the sugary pastry to life.\n",
       "The wholesome sweetness of blackberries puts a smile on your face.\n",
       "The tart taste of the dates is sweetened by the light syrup.\n",
       "The light flaky pastry only emphasizes the fantastic richness of the chocolate and hazelnut.  Oh wow...that's heaven!\n",
       "The sweet taste of mango in a cold, creamy shake.\n",
       "A sugary sweet drink flavored with mint.\n",
       "You can't help but inhale the soft, healthy fragrance of jasmine as you drink the warm, soothing tea.\n",
       "The fragrance of cinnamon and cloves fills the air as you drink the spiced wine.\n",
       "The clear, cool water is tinged with just a hint of rose.  Delightful.\n",
       "The heavenly blend of cardamom, cinnamon, and clove with the sweetness of grapes and honey...altogether, amazing.\n"
       }));
   set_your_mess(
       ({
       "makes an interesting face and downs the brains.\n",
       "savors the taste of the pigs feet.\n",
       "smiles broadly and attacks the steak.\n",
       "pops an eyeball in.\n",
       "smiles quietly and savors the tandoori chicken.\n",
       "eats the lamb masala with a sigh of delight.\n",
       "enjoys a piece of cheesy flatbread.\n",
       "scarfs down the pot pie.\n",
       "eats the tabouli, makes a face, and calls for something to drink.\n",
       "sighs contentedly after eating the syrupy baklava.\n",
       "eats the blackberry custard and smiles sweetly.\n",
       "eats the sticky dates.\n",
       "seems to derive pleasure from the Caerveron...perhaps too much pleasure.  Oh, my.\n",
       "sips the mango lassi with a satisfied smile.\n",
       "drinks the Sikanjabin with wide eyes.\n",
       "drinks the tea and inhales deeply.\n",
       "drinks the spiced wine and the scent of cloves and cinnamon fills the air.\n",
       "drinks a glass of cool rose water.\n",
       "seems to enjoy the glass of Tsarven mead.\n"
        })
    );
    set_menu_short(
        ({
        "Chilled Monkey Brains",
        "Pigs Feet",
        "Beef Tenderloin",
        "Spiced Deer Eyes",
        "Tandoori Chicken",
        "Lamb Masala",
        "Cheese Naan",
        "Curry Pot Pie",
        "Tabouli",
        "Baklava",
        "Blackberry Custard",
        "Roasted Dates",
        "Caerveron",
        "Mango Lassi",
        "Sikanjabin",
        "Jasmine Tea",
        "Spiced Wine",
        "Rose Water",
        "Tsarven Mead"
        })
    );
    set_menu_long(
        ({
        "%^RED%^A chilled delight, the skull of a monkey is used as a bowl for this treat!%^RESET%^\n",
        "%^BOLD%^%^MAGENTA%^Pickled and jellied with Chef al-Islam's secret family recipe, these pigs feet are served arranged nicely on a platter with a bit of cilantro.%^RESET%^\n",
        "%^RED%^The finest cut of beef with bearnaise and bordalaise sauces.  The meat is served medium with a side of rice.%^RESET%^\n",
        "%^GREEN%^Six deer eyes, spiced with peppers, basil, and cilantro and covered in a light glaze.%^RESET%^\n",
        "%^ORANGE%^A wonderfully spicy chicken in a yogurt glaze, seared in a hot clay oven.%^RESET%^\n",
        "%^ORANGE%^Delectable bite-sized pieces of lamb in a delicious spicy sauce served over rice.\n",
        "%^BOLD%^%^WHITE%^A fluffy flatbread baked and topped with %^YELLOW%^melted cheese%^WHITE%^.%^RESET%^\n",
        "%^YELLOW%^A new twist on a traditional chicken pot pie, the curry powder gives this pie a yellowish hue, and the aroma of spices wafting up from it is mouthwatering.%^RESET%^\n",
        "Bulgar wheat, spices, and lemon juice.  Not an exciting meal, but filling.  Many commoners make this meal their staple.\n",
        "%^YELLOW%^A golden phyllo pastry baked with the fragrant spices of cinnamon, cloves, and allspice, mixed with crushed almonds and covered with a light, sugary honey syrup.%^RESET%^\n", 
        "%^MAGENTA%^Seif has taken to making this local favorite of the residents of Tabor, and - like most things - it nears perfection in his hands.  The smooth custard is creamy with the taste of crushed blackberries, and it alternates with layers of whole blackberries in a tall parfait glass.%^RESET%^\n",
        "%^MAGENTA%^This small platter has five delicious roasted dates arranged in a circle.  A very light syrup made of honey and crushed dates has been drizzled on top of them, making this a tasty treat.%^RESET%^\n",
        "%^YELLOW%^Named for the first king of Tabor, the Caerveron has become the local choice for desserts.  The king, it is said, served this dish at his wedding feast, the first time any of the locals had ever tried it.  A mouth-watering creation of almond pastry wrapped around gooey %^BLACK%^chocolate %^YELLOW%^and %^RESET%^%^ORANGE%^hazelnut%^YELLOW%^, the creamy aroma of this dessert is almost overwhelming.%^RESET%^\n",
        "%^BOLD%^%^MAGENTA%^A delicious shake made of crushed mango and milk, poured over crushed ice and served in a tall glass with a wedge of %^GREEN%^lime%^MAGENTA%^.  This drink is a house favorite among relaxing patrons.%^RESET%^\n",
        "%^BOLD%^%^GREEN%^Made from a sugary base, this is a drink of the Tsarven empire that is flavored with mint.  It is quite sweet, and most people of Tabor consider it an acquired taste...one they don't necessarily want to acquire.  Still, it is Seif's favorite drink on the menu, and he serves it with pride.%^RESET%^\n",
        "%^ORANGE%^Made from the fragrant jasmine, this tea has a light, floral flavor that clears the mind and opens the senses.  It is served in a warm mug with a single sugar cube to sweeten the soft flavor.%^RESET%^\n",
        "%^BOLD%^%^RED%^A local favorite, this spiced wine is made by taking sweet red wine and adding hints of cinnamon, cloves, mace, and ginger.  The result is a fragrant wine with a delightful taste and a heady bouquet.%^RESET%^\n",
        "%^BOLD%^%^MAGENTA%^The light scent of roses rises from this glass of clear, cool water.  The water has a light pink tint.  It is said that rose water is good for relaxing the senses and clearing the body of impurities.%^RESET%^\n",
        "%^MAGENTA%^This wonderful import from the southern reaches of the Tsarven empire has taken the city of Tabor by storm.  It is flavored with those spices the Tsarvani seem to favor - cardamom, cinnamon, and cloves - and the base is made of grape juice simmered with honey.  The drink smells wonderfully spicy and sweet, and it's served chilled in a tall glass.%^RESET%^\n"
        })
    );
}

void receive_given_item(object ob){
   if((string)ob->query_short() == "An empty bottle" ||
      (string)ob->query_name() == "bottle"){
      force_me("emote puts away the empty bottle.");
      ob->remove();
   }
}