//updated by Circe 1/17/05 with new menu by Lusell
inherit "/std/barkeep";

void create() {
    ::create();
    set_name("Kean");
    set_id(({"kean","waiter","Kean"}));
    set_short("Kean the waiter");
    set("aggressive", 0);
    set_level(10);
    set_long(
      "Kean is a young man dressed in a well-tailored suit.  He "+
      "carries a white cloth over his left forearm and bustles "+
      "about, placing menus on the tables and taking orders.  His "+
      "thick black hair is close-cropped above his deep green eyes, "+
      "which seem intent upon his job.  You could probably read "+
      "the menu before you before you order your meal."
    );
    set_gender("male");
    set_alignment(6);
    set_race("human");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    add_money("copper", random(200));
    set_currency("silver");
    set_menu(
      ({"lamb barley soup","grilled prawns","mushroom medley","pan-seared salmon","roasted chicken","steak and prawns","creme brulee","sticky toffee pudding","chocolate drambuie trifle","lemon water","chamomile tea","iced brandy","smoked sherry","aged scotch","golden chardonnay"}),
      ({"food","food","food","food","food","food","food","food","food","water","soft drink","alcoholic","alcoholic","alcoholic","alcoholic"}),
      ({25,35,45,60,75,90,20,25,30,10,15,20,30,40,50}),
    );
    set_my_mess(
      ({
	"You eat the hearty soup and feel yourself warm up.",
      "You eat the prawns, enjoying the tangy flavor.",
      "You eat the mushroom medley, noticing how the pastry holds in the flavor.",
      "You eat the flakey salmon flavored with lemon and a dash of pepper.",
      "The chicken melts in your mouth, flavored with shallots and thyme.",
      "You eat the steak and prawns, savoring the way the flavors blend.",
      "You eat the creme brulee, noticing the way the fruit flavors the dessert.",
      "You enjoy the spongy cake filled with dates.",
      "You savour the chocolate dessert, noticing how the layers blend.",
      "You drink down the cool lemon water and feel refreshed.",
      "You drink the soothing tea, relaxing with the fragrance of chamomile.",
      "You savour the snifter of iced brandy, letting the liquid fire do its work.",
      "You drink the sherry, noticing the unusual smokey flavor.",
      "You sip the aged scotch, savoring the aged flavor.",
      "You sip the glass of golden chardonnay, enjoying the fragrance."
      })
    );
    set_your_mess(
      ({
	"eats a hearty bowl of soup.",
      "eats the grilled prawns.",
      "eats the puffed pastry filled with mushrooms.",
      "savors the delicious-smelling salmon.",
      "eats the chicken with a contented smile.",
      "enjoys a plate of steak and prawns.",
      "eats a dessert of creme brulee and fruit.",
      "enjoys a spongy cake filled with dates.",
      "seems to enjoy a tall chocolate dessert.",
      "drinks a glass of lemon water.",
      "drinks a glass of chamomile tea and sighs contentedly.",
      "downs the snifter of iced brandy.",
      "drinks a glass of smoked sherry.",
      "drinks a glass of aged scotch.",
      "enjoys a glass of golden chardonnay."
      })
    );
    set_menu_short(
      ({
	"Lamb Barley Soup",
      "Grilled Prawns",
      "Mushroom Medley",
      "Pan-seared Salmon Filet",
      "Roasted Chicken",
      "Steak and Prawns",
      "Creme Brulee",
      "Sticky Toffee Pudding",
      "Chocolate Drambuie Trifle",
      "Lemon Water",
      "Chamomile Tea",
      "Iced Brandy",
      "Smoked Sherry",
      "Aged Scotch",
      "Golden Chardonnay"
      })
    );
    set_menu_long(
      ({
	"%^ORANGE%^A hearty soup that is good for cold winter days.  Lamb and "+
      "vegetables are cooked in a beefy broth with chewy barley.",
      "%^BOLD%^%^MAGENTA%^Prawns marinated in lime, onion, "+
      "and garlic and then quickly grilled.",
      "%^ORANGE%^Mushrooms cooked with garlic, shallots, and cream, "+
      "topped with a puffed pastry.",
      "%^BOLD%^%^MAGENTA%^Pan-fried salmon filets with a garlic and "+
      "lemon sauce, covered with peppers.",
      "%^YELLOW%^ Thyme and shallots take a starring role in this "+
      "moist, flavorful preparation for chicken that's sure to "+
      "become a house favorite.",
      "%^RED%^Pan-seared steak, horseradish butter, batter-fried "+
      "prawns, mashed potatoes, and seasonal vegetables heaped "+
      "into a very large serving.",
      "%^YELLOW%^Stovetop creme brulee with a brown sugar top, "+
      "served over fruit.",
      "%^MAGENTA%^This cake is rich with dates.  A dessert type "+
      "pudding cake with caramel sauce served over the top.",
      "%^BOLD%^%^BLACK%^A traditional trifle made from homemade "+
      "sponge cake brushed with raspberry jam and sprinkled with "+
      "drambuie liquore, then layered in a glass dish with fruit, "+
      "vanilla pudding, and whipped cream.",
      "%^YELLOW%^A sparkling glass of clear, clean water with a "+
      "wedge of lemon placed on the rim of the glass.",
      "%^BOLD%^%^MAGENTA%^A wonderfully scented cup of fresh tea, "+
      "the fragrance of which seems to fill the room.",
      "%^RED%^A house creation, this is a snifter of regional brandy "+
      "that has been placed on ice for at least a day.",
      "%^BOLD%^%^BLACK%^A cooking concoction that has caught on as "+
      "a drink.  This particular sherry has been run through a "+
      "barrel of smoldering oak.",
      "%^ORANGE%^A house creation, this scotch is 25 years old and is "+
      "golden brown.  Connoisseurs and bards of the realms have "+
      "written about how smooth and warm this drink goes down.",
      "%^YELLOW%^This tall glass of wine contains a perfectly aged, "+
      "golden medley of regional grapes.  The wine was crafted locally."
      })
    );
}
