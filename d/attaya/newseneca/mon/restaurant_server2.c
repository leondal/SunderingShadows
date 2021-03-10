//random server for El Pescado
//Coded by ~Circe~ for new Seneca 6/3/08
#include <std.h>

inherit BARKEEP;

#define COLORS ({"%^ORANGE%^brown","%^BOLD%^%^BLACK%^black","%^RED%^aub%^ORANGE%^u%^RED%^rn","%^YELLOW%^golden","%^BOLD%^%^WHITE%^silvery blond"})

#define LENGTHS ({"shoulder-length","long","curly","short","chin-length"})

#define EYES ({"%^BOLD%^%^CYAN%^azure","%^BOLD%^%^BLUE%^blue","%^BOLD%^%^GREEN%^green","%^ORANGE%^chocolate","%^GREEN%^hazel"})

#define GOWNS ({"%^BOLD%^%^CYAN%^aquamarine",\
"%^GREEN%^olive green",\
"%^BOLD%^%^CYAN%^azure",\
"%^BLUE%^indigo",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^MAGENTA%^amethyst",\
"%^BOLD%^%^WHITE%^ivory",\
"%^BOLD%^%^BLUE%^ocean blue",\
"%^BOLD%^%^GREEN%^leaf green",\
"%^GREEN%^pine green",\
"%^BOLD%^%^BLUE%^cobalt blue",\
"%^BLUE%^navy blue",\
"%^GREEN%^forest green",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^BOLD%^%^BLUE%^sapphire blue",\
"%^CYAN%^blue-green",\
"%^GREEN%^gray-green",\
"%^BOLD%^%^BLACK%^black",\
"%^ORANGE%^rich brown",\
"%^ORANGE%^dark brown",\
"%^ORANGE%^walnut brown",\
"%^RED%^brick red",\
"%^ORANGE%^peach",\
"%^BOLD%^%^GREEN%^lime green",\
"%^BOLD%^%^RED%^ruby red",\
"%^MAGENTA%^royal purple",\
"%^RED%^blood red",\
"%^MAGENTA%^violet",\
"%^ORANGE%^rusty orange",\
"%^BOLD%^%^RED%^rusty red",\
"%^BOLD%^%^RED%^reddish orange",\
"%^BOLD%^%^RED%^fiery red",\
"%^BOLD%^%^BLUE%^cornflower blue",\
"%^MAGENTA%^lavender",\
"%^BOLD%^%^MAGENTA%^carnation pink",\
"%^ORANGE%^light brown",\
"%^CYAN%^turquoise",\
"%^BOLD%^%^BLACK%^charcoal gray",\
"%^CYAN%^cyan blue",\
"%^BOLD%^%^WHITE%^rich cream",\
"%^BOLD%^%^WHITE%^cream",\
"%^BOLD%^%^WHITE%^white",\
"%^YELLOW%^saphron",\
"%^YELLOW%^lemon yellow",\
"%^ORANGE%^tangerine",\
"%^BOLD%^%^MAGENTA%^mauve",\
"%^RED%^crimson",\
"%^BOLD%^%^MAGENTA%^lilac",\
"%^YELLOW%^daffodil",\
"%^ORANGE%^beige",\
"%^ORANGE%^taupe",\
"%^BOLD%^%^BLACK%^sable",\
"%^ORANGE%^fawn",\
"%^BOLD%^%^BLACK%^pale gray",\
"%^BOLD%^%^BLACK%^stormy gray",\
"%^ORANGE%^dusty brown",\
"%^BOLD%^%^BLACK%^dark gray"\
})

void create(){
   string COLOR,LENGTH,EYE,GOWN;
   object obj;
   ::create();
   COLOR = COLORS[random(sizeof(COLORS))];
   LENGTH = LENGTHS[random(sizeof(LENGTHS))];
   EYE = EYES[random(sizeof(EYES))];
   GOWN = GOWNS[random(sizeof(GOWNS))];
   set_name("a waitress");
   set_id(({"Waitress","waitress","server","waitress of el pescado"}));
   set_short("A Waitress of El Pescado");
   set_level(10);
   set_long("%^RESET%^%^CYAN%^Dressed in a flowing gown of "+
      ""+GOWN+" linen%^RESET%^%^CYAN%^ that hugs her form at the "+
      "bodice before flaring out from the hips down to her ankles, "+
      "this young woman stands ready to take your order.  Her neatly "+
      "cut "+COLOR+" hair %^RESET%^%^CYAN%^is "+LENGTH+" and held "+
      "back by a slender %^RESET%^silver headband%^CYAN%^, a style "+
      "that allows a good view of her "+EYE+" eyes%^RESET%^%^CYAN%^.  "+
      "She carries the menu tucked into the slender %^RESET%^silver "+
      "rope belt %^CYAN%^tied around her waist, and she always "+
      "stands alert and ready to tend the customers with a gentle smile.%^RESET%^");
   set_gender("female");
   set_exp(20);
   set_alignment(5);
   set_race("human");
   set_hd(10,0);
   set_hp(100);
   set_max_hp(query_hp());
   set_body_type("human");
   set_currency("gold");
   set_menu(
       ({"shrimp skewers","salmon salad","stuffed mussels","garlic prawns","chorizo and prawn soup","suquet","grouper a la mallorquina","caldereta de langosta","spiced clams","filet a la mussels vinaigrette","pulpo a feira","tuna empanadillas","herb-crusted tilapia","lasagne blanco","bread pudding","attaya lime pie","creme brulee","chocolate heaven","berry cheesecake","mango sorbet","ice water","jasmine tea","orange granizado","chocolate caliente","vino blanco","vino tinto","sangria","granizado de cafe","margarita"}),
       ({"food","food","food","food","food","food","food","food","food","food","food","food","food","food","food","food","food","food","food","food","water","soft drink","soft drink","soft drink","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic"}),
       ({15,35,10,25,30,40,45,60,10,70,75,30,40,50,8,10,12,15,10,5,1,5,10,12,50,50,60,65,70})
   );
    set_menu_short(({
        "Shrimp Skewers",
        "Salmon Salad",
        "Stuffed Mussels",
        "Garlic Prawns",
        "Chorizo and Prawn Soup",
        "Suquet",
        "Grouper a la Mallorquina",
        "Caldereta de Langosta",
        "Spiced Clams",
        "Filet a la Mussels Vinaigrette",
        "Pulpo a Feira",
        "Tuna Empanadillas",
        "Herb-crusted Tilapia",
        "Lasagne Blanco",
        "Bread Pudding",
        "Attaya Lime Pie",
        "Creme Brulee",
        "Chocolate Heaven",
        "Berry Cheesecake",
        "Mango Sorbet",
        "Ice Water",
        "Jasmine Tea",
        "Orange Granizado",
        "Chocolate Caliente",
        "Vino Blanco",
        "Vino Tinto",
        "Sangria",
        "Granizado de Cafe",
        "Margarita"
        }));
   set_my_mess(({
       "The savory flavors of the shrimp and vegetables are tempered perfectly by the sour cream.\n",
       "The delicious flavor of the salmon and lemon blend perfectly with the mixed greens - yummy and healthy!\n",
       "The spicy flavor of the peppers provides some kick to the mild flavor of the mussels.\n",
       "The hearty rice and flavorful prawns are a delightful taste combination.\n",
       "The bold flavors of the hearty stew are quite delicious - and definitely filling!\n",
       "Though a bit difficult to eat, the clams are never as fresh as when pulled from the shell.  How delicious!\n",
       "The blend of flavors and textures in this dish is unbelievable - each taste seems to enhance the others.\n",
       "Dipping a the slices of bread into the stew, you soak up flavor with every bite.\n",
       "Using a small fork, you pry each of the clams from their shells, savoring the burst of flavor each brings.\n",
       "You find you must use a knife and fork to fully enjoy this delectable meal, but the rich blend of flavors is well worth it!\n",
       "The slightly rubbery texture of the octopus and the almost bland flavor of the potatoes is an unusual combination.\n",
       "As you pop each of the bite-sized pastries into your mouth, you can taste the flavorful goat cheese and flaky tuna.\n",
       "The fish and vegetables are both light an flavorful, combining together perfectly.\n",
       "The melted cheese practically drips from your chin as you enjoy the creamy lasagne filled with chopped prawns.\n",
       "The cinammon sweetness of the bread pudding is enhanced by the delightful taste of the ice cream.\n",
       "The tart flavor of the limes and the soft sweetness of the meringue make for a refreshing dessert.\n",
       "You feel the soft, silky texture of the custard as you taste vanilla and amaretto.\n",
       "Quite messy, the chocolate heaven nevertheless lives up to its name.  Yummy!\n",
       "Creamy with a rich flavor, the slice of cheesecake is sweetened by the berries.\n",
       "The taste of the mango sorbet is light and fruity, perfect for a hot day.\n",
       "You sip the refreshing ice water and taste just a hint of lemon.\n",
       "You inhale the sweet fragrance of jasmine as you sip the tea, feeling it sooth your throat.\n",
       "The tangy sweet flavor of orange is muted by the cool relief of ice shavings.\n",
       "The hot chocolate warms your chest as you drink it, savoring the sweet aftertaste.\n",
       "The light, slightly sweet wine has a hint of pineapple.\n",
       "The red wine tastes lightly of plum and cloves.\n",
       "The sweet taste of peach lingers on your lips as you drink the sangria.\n",
       "The iced coffee packs a bit of a punch and leaves you with a light taste of cinnamon.\n",
       "The tart tang of the margarita is cooled by the shaved ice and hint of lime.  Ahhhhh...refreshing.\n"
       }));
   set_your_mess(({
       "enjoys a pair of shrimp skewers with a healthy serving of greens.\n",
       "eats a healthy green salad topped with flaky salmon.\n",
       "eats a plate of mussels straight from their shells, one by one.\n",
       "devours a bowl of fluffy rice topped with large prawns.\n",
       "savors a bowl of hearty stew made with chorizo, prawns, and fish.\n",
       "lifts shells from the stew and enjoys the clams before draining the rest of the bowl.\n",
       "eats a hole grouper simply slathered with vegetables.  Wow!\n",
       "enjoys an aromatic lobster stew with several thin slices of bread.\n",
       "uses a small fork to pry clams from their shells before eating them.\n",
       "enjoys a mussel-covered steak and a small bed of greens.\n",
       "eats a platter filled with chopped octopus and potatoes.\n",
       "enjoys a handful of small pastries one at a time.\n",
       "eats a platter of flavorful fish and grilled vegetables.\n",
       "savors a white lasagne dripping with cheese.\n",
       "enjoys a warm helping of bread pudding with ice cream.\n",
       "eats a thick slice of Attaya lime pie.\n",
       "eats a serving of creme brulee from a ramekin.\n",
       "enjoys a messy but delicious-looking chocolate dessert.\n",
       "eats a slice of cheesecake covered in berries.\n",
       "enjoys two scoops of mango sorbet.\n",
       "drinks a glass of ice water.\n",
       "sips a cup of jasmine tea.\n",
       "drinks a tumbler of an orange drink filled with shaved ice.\n",
       "enjoys a steaming mug of hot chocolate.\n",
       "swirls a glass of white wine and sips it.\n",
       "savors a glass of deep red wine.\n",
       "gives a small smile and drinks a glass of sangria.\n",
       "drinks a delicious looking iced coffee.\n",
       "enjoys a tangy margarita with a salted rim.\n"
       }));
    set_menu_long(({
        "Flecks of %^RED%^c%^BOLD%^a%^RESET%^%^RED%^y%^BOLD%^e%^RESET%^%^RED%^n%^BOLD%^n%^RESET%^%^RED%^e %^RESET%^and other %^GREEN%^p%^BOLD%^e%^RESET%^%^GREEN%^p%^BOLD%^p%^RESET%^%^GREEN%^e%^BOLD%^r%^RESET%^%^GREEN%^s %^RESET%^dot every inch of these perfectly grilled %^BOLD%^%^MAGENTA%^shrimp%^RESET%^.  Large slices of juicy %^GREEN%^bell pepper %^RESET%^and %^BOLD%^soft onion %^RESET%^alternate with the %^BOLD%^%^MAGENTA%^shrimp%^RESET%^, adding their savory flavors.  Two skewers are arranged on a simple bed of %^GREEN%^greens%^RESET%^ and served with a generous dollop of %^BOLD%^sour cream%^RESET%^.\n",
        "A thick bed of %^GREEN%^greens %^RESET%^made up of endives, romaine, watercress, and lollo rosso form the basis of this salad.  A smattering of plump %^BOLD%^%^RED%^cherry tomatoes %^RESET%^add a touch of color that spices up the pink slices of %^BOLD%^%^MAGENTA%^salmon%^RESET%^ that thickly cover the salad.  A few slices of fresh %^YELLOW%^lemon %^RESET%^provide a garnish as well as an additional bit of flavor.  A simple refreshing dressing of %^BOLD%^white wine vinegar %^RESET%^and oil provides the finishing touch.\n",
        "Served upon a %^ORANGE%^driftwood platter%^RESET%^, these mussels have been stuffed back into their own %^BOLD%^%^BLACK%^s%^RESET%^h%^ORANGE%^e%^RESET%^l%^BOLD%^%^BLACK%^l%^RESET%^s.  The flesh of the mussels have been removed and chopped before being mixed with chopped %^BOLD%^onion%^RESET%^, %^GREEN%^green peppers%^RESET%^, %^BOLD%^%^RED%^tomatoes%^RESET%^ and sauteed in olive oil.  Finally, they are placed back in the shells and topped with a delicious mixture of %^ORANGE%^bread crumbs%^RESET%^ baked golden brown.\n",
        "Fluffy %^BOLD%^rice%^RESET%^ simmered with diced %^BOLD%^onion%^RESET%^, %^BOLD%^garlic%^RESET%^, and %^BOLD%^%^RED%^tomatoes%^RESET%^ makes up the bulk of this hearty dish.  Placed over the top are a dozen large %^BOLD%^%^MAGENTA%^prawns %^RESET%^that have been sauteed in garlic and paprika to give them an extra kick.  A thick wedge of %^YELLOW%^lemon%^RESET%^ rests on the side of the platter, the perfect addition to the combination of flavors.\n",
        "This bowl of soup is thick, made from chunks of %^BOLD%^flaky white fish%^RESET%^, seared %^BOLD%^%^MAGENTA%^shrimp%^RESET%^, and hearty %^RED%^chorizo sausage%^RESET%^.  It is bursting with flavor, seasoned with onion and paprika and filled with chunks of %^BOLD%^potato%^RESET%^, diced %^BOLD%^%^RED%^tomatoes%^RESET%^, and %^RED%^red bell pepper%^RESET%^.  The ingredients are simmered together and finished off with a hint of oregano and thyme.\n",
        "This seafood stew is a feast for the eyes as well as the palate.  A dozen small %^BOLD%^%^BLACK%^cherrystone clams%^RESET%^ on the half-shell float within a thin %^BOLD%^broth%^RESET%^ flavored with the mixture of chunked %^BOLD%^monkfish %^RESET%^and %^BOLD%^hake%^RESET%^.  Adding color and additional flavor are an assortment of %^BOLD%^squid%^RESET%^, %^BOLD%^%^MAGENTA%^shrimp%^RESET%^, and %^BOLD%^mussels %^RESET%^mixed with grated %^BOLD%^%^RED%^tomato%^RESET%^.  The final touch to the stew is the flavoring of %^YELLOW%^saffron threads%^RESET%^ and %^ORANGE%^almonds%^RESET%^, making this an altogether unique dish.\n",
        "Beautiful in presentation, this dish features a whole %^ORANGE%^g%^RESET%^r%^ORANGE%^o%^RESET%^u%^ORANGE%^p%^RESET%^e%^ORANGE%^r %^RESET%^seasoned with %^BOLD%^salt%^RESET%^, %^BOLD%^%^BLACK%^p%^RESET%^e%^BOLD%^%^BLACK%^p%^RESET%^p%^BOLD%^%^BLACK%^e%^RESET%^r, and %^YELLOW%^lemon%^RESET%^ and topped with a bountiful collection of colorful vegetables.    %^BOLD%^Scallions%^RESET%^, %^BOLD%^%^GREEN%^leeks%^RESET%^, %^GREEN%^chard%^RESET%^, %^ORANGE%^carrots%^RESET%^, %^RED%^tomatoes%^RESET%^, and %^MAGENTA%^raisins%^RESET%^ are sprinkled atop the fish, which rests upon a bed of soft %^BOLD%^potatoes%^RESET%^.  A smattering of %^RED%^paprika%^RESET%^ and %^BOLD%^pine nuts%^RESET%^ provide the finishing touch.\n",
        "Crafted from a %^RED%^tomato base%^RESET%^, this stew features succulent pieces of soft %^BOLD%^lobster %^RESET%^mixed with chopped %^RED%^tomato%^RESET%^, %^GREEN%^bell pepper%^RESET%^, and %^YELLOW%^yellow onion%^RESET%^.  It is served in a paper-thin %^BOLD%^ceramic bowl %^RESET%^placed upon a large platter graced with several slices of thin %^ORANGE%^whole-grain bread %^RESET%^and a small container of %^BOLD%^alioli%^RESET%^.\n",
        "A savory blend of pungent spices rises from this dish of opened %^ORANGE%^clams%^RESET%^, which have turned a golden yellow as they were stir-fried in oil.  The clams are flavored with a bold mixture of %^BOLD%^onion%^RESET%^, %^GREEN%^celery%^RESET%^, %^YELLOW%^ginger%^RESET%^, %^BOLD%^garlic%^RESET%^, %^RED%^chili powder%^RESET%^, and %^BOLD%^tumeric%^RESET%^.  They rest in a light sauce with a %^BOLD%^white wine base%^RESET%^, allowing the %^ORANGE%^clams%^RESET%^ to take centerstage.\n",
        "A thick, juicy cut of %^RED%^filet mignon %^RESET%^is the centerpiece of this meal.  It is topped with aromatic %^BOLD%^mussels%^RESET%^ flavored with %^RED%^p%^GREEN%^e%^RED%^p%^GREEN%^p%^RED%^e%^GREEN%^r%^RED%^s%^RESET%^, %^BOLD%^onion%^RESET%^, and %^GREEN%^parsley%^RESET%^, which blend flavors well with the red meat of the steak.  A small bed of %^GREEN%^greens %^RESET%^with a %^BOLD%^white wine vinaigrette %^RESET%^rest at the side of the platter, making this a complete meal.\n",
        "Despite its most unique ingredient, this favorite dish of Seneca is actually pretty simple in design.  A three-pound %^MAGENTA%^octopus %^RESET%^cut into small chunks forms the basis of the dish, which is surrounded by thickly sliced %^BOLD%^potatoes%^RESET%^ still with their skins.  A simple flavoring of %^BOLD%^sea salt%^RESET%^, %^GREEN%^olive oil%^RESET%^, and %^RED%^paprika%^RESET%^ is sprinkled over the top of the octopus and potatoes, allowing the unique flavor of the octopus to shine through and making this a dish that is often an acquired taste.\n",
        "The small, bite-sized pastries of this dish make it a a favorite for those on the go in Seneca.  A light, delectable pastry baked %^ORANGE%^golden brown%^RESET%^ surrounds the piping hot stuffing made of flaky %^BOLD%^tuna%^RESET%^ and %^BOLD%^goat cheese %^RESET%^flavored with minced %^BOLD%^onion%^RESET%^, %^GREEN%^olives%^RESET%^, %^RED%^pimentos%^RESET%^, %^BOLD%^pine nuts%^RESET%^, %^GREEN%^capers%^RESET%^, %^RED%^paprika%^RESET%^, and %^BOLD%^garlic%^RESET%^.  The flavors blend delightfully, creating an aroma tempting enough for even the most discerning tastes.\n",
        "A fantastic blend of %^GREEN%^herbs %^RESET%^make up the seasoning for this delicious fish.  The light, flaky %^BOLD%^tilapia %^RESET%^is topped with a smattering of %^ORANGE%^bread crumbs %^RESET%^mixed with the herbs and a hint of %^YELLOW%^lemon juice%^RESET%^.  To the side, a pleasing array of grilled %^YELLOW%^squash%^RESET%^, %^GREEN%^zucchini%^RESET%^, and %^BOLD%^%^BLACK%^mushrooms%^RESET%^ adds a fantastic complement to the rather simple, yet tasty, fish.\n",
        "A piece of heaven wrapped up in %^YELLOW%^gooey cheese%^RESET%^ and %^BOLD%^rich cream sauce%^RESET%^, this lasagne is impeccable.  Succulent pieces of savory %^BOLD%^%^MAGENTA%^prawns %^RESET%^are mixed among tender %^BOLD%^artichoke hearts%^RESET%^, blending together in tasty harmony.  Hints of %^BOLD%^white pepper %^RESET%^and %^BOLD%^onion%^RESET%^ add a touch of spice to this delectable dish.\n",
        "%^ORANGE%^A slice of baked deliciousness, this bread pudding is made from chunks of bread sweetened with sugar, cinnamon, nutmeg, and vanilla.  Spread throughout are plump baked raisins, and the entire warm dessert is topped with a drizzling of rich caramel cream.  A generous serving of %^RESET%^ice cream %^ORANGE%^has been scooped right onto the center of this serving.%^RESET%^\n",
        "A thick layer of %^BOLD%^meringue %^RESET%^baked until %^ORANGE%^golden brown %^RESET%^tops this delectable slice of pie.  The filling is a rich %^YELLOW%^yellow%^RESET%^%^ORANGE%^-%^BOLD%^%^GREEN%^green%^RESET%^ with a tart taste and a creamy texture that is heavenly.  The crust is light and flaky, and the overall light-as-air consistency of this pie makes it a favorite for the heat of the Attaya summers - though, in truth, their winters are little different.\n",
        "A simple %^BOLD%^white ramekin%^RESET%^ with fluted sides holds this custard dish.  The thick, rich %^ORANGE%^custard%^RESET%^ has the simple flavor of %^ORANGE%^vanilla%^RESET%^ with just a hint of %^BOLD%^amaretto%^RESET%^.  A thin crust of %^ORANGE%^caramelized sugar %^RESET%^covers the top, adding a bit more texture to this dessert.\n",
        "This towering mountain of chocolate is made from alternating layers of thick %^BOLD%^%^BLACK%^chocolate cake%^RESET%^ with %^BOLD%^%^BLACK%^dark%^RESET%^ and %^BOLD%^white c%^BLACK%^h%^WHITE%^o%^BLACK%^c%^WHITE%^o%^BLACK%^l%^WHITE%^a%^BLACK%^t%^WHITE%^e %^BLACK%^m%^WHITE%^o%^BLACK%^u%^WHITE%^s%^BLACK%^s%^WHITE%^e%^RESET%^ within a wide, tall trifle glass.  A generous drizzle of %^BOLD%^%^BLACK%^ganache glaze %^RESET%^is spread over the creation, and a serving of light %^BOLD%^whipped cream %^RESET%^tops it all, graced with a ripe %^BOLD%^%^RED%^cherry%^RESET%^.\n",
        "A thick slice of rich, creamy %^ORANGE%^cheesecake %^RESET%^covered with stewed %^MAGENTA%^b%^RED%^e%^MAGENTA%^r%^RED%^r%^MAGENTA%^i%^RED%^e%^MAGENTA%^s %^RESET%^makes up this dessert.  The topping is made of a mixture of sweetened %^MAGENTA%^blackberries %^RESET%^and %^RED%^raspberries%^RESET%^ with a light hint of %^RED%^cherry brandy%^RESET%^, while the crust is made from crushed %^ORANGE%^graham crackers%^RESET%^.\n",
        "Simple in design but absolutely delicious, this sorbet is made from only a few ingredients - %^ORANGE%^mango%^RESET%^, fresh %^GREEN%^lime juice%^RESET%^, %^BOLD%^sugar%^RESET%^, and %^CYAN%^water%^RESET%^.  Blended together and frozen to a soft consistency, this dessert is extremely light and flavorful.  This bowl is filled with two large scoops.\n",
        "A tall, slender tumbler holds %^CYAN%^crystal clear water%^RESET%^ filled with %^BOLD%^%^CYAN%^ice%^RESET%^.  A wedge of %^YELLOW%^lemon %^RESET%^has been placed on the rim of the glass, allowing the drinker to give the water a bit more flavor if desired.  The water looks cool and refreshing, perfect for a hot Attaya day.\n",
        "A delicate %^BOLD%^china teacup %^RESET%^with no handle holds a serving of sweet %^ORANGE%^jasmine tea%^RESET%^.  Made from green tea that is fragranced with jasmine blossoms, this tea is said to sooth coughs and sore throats as well as provide a burst of energy.  This tea is served with a sprinkling of sugar and has an intoxicating fragrance of jasmine flowers.\n",
        "A slender %^BOLD%^frosted tumbler%^RESET%^ holds a generous serving of thick %^CYAN%^shaved ice%^RESET%^ suspended in nearly frozen %^ORANGE%^orange liquid%^RESET%^ in this drink.  It is sweet, quite cold, and extremely refreshing.  A wedge of %^ORANGE%^orange%^RESET%^ rests on the rim of the glass, which has been coated in %^BOLD%^sugar%^RESET%^.\n",
        "A %^YELLOW%^gold-rimmed%^WHITE%^ porcelain cup %^RESET%^holds a measure of steaming %^BOLD%^melted chocolate %^RESET%^mixed with %^BOLD%^milk%^RESET%^.  The chocolate is further sweetened by a dollop of fluffy %^BOLD%^whipped cream%^RESET%^ and is served with a single %^ORANGE%^churro%^RESET%^.  Despite its warmth, this drink is still very popular among the people of Seneca, especially as a nightcap.\n",
        "A delicate wine glass holds a measure of light %^ORANGE%^amber liquid%^RESET%^ that sparkles in the light.  A subtle fragrance of %^YELLOW%^pineapple%^RESET%^ seems to linger around the glass, inviting you to drink.\n",
        "This wine glass is filled with %^MAGENTA%^deep maroon wine%^RESET%^ that gives off the heady aroma of plums.  Near the center of the glass, the liquid grows more transluscent as the light brightens its color, bringing to mind the hue of fresh plums themselves.  A slight fragrance of cinnamon rises from the glass as well.\n",
        "Formed from a base of %^RED%^red wine%^RESET%^, this delicious drink features slices of %^ORANGE%^peach%^RESET%^, %^BOLD%^%^RED%^apple%^RESET%^, and %^ORANGE%^orange%^RESET%^ flavored with %^YELLOW%^lemonade%^RESET%^ and %^ORANGE%^cinnamon%^RESET%^.  The glass has been chilled until the outside is %^BOLD%^frosted %^RESET%^and a generous quantity of %^CYAN%^ice %^RESET%^is within, making this a refreshing choice for the heat of Seneca.\n",
        "Because hot coffee is generally an unpopular choice in intense heat such as that of Attaya, the locals of Seneca have taken to making this delicious iced substitute.  A slender glass has been filled with %^CYAN%^shaved ice%^RESET%^ and %^BOLD%^%^BLACK%^coffee %^RESET%^sweetened with %^BOLD%^sugar%^RESET%^.  The real punch to the drink comes in the form of the %^BOLD%^%^BLACK%^coffee-flavored liqueur%^RESET%^ and the dusting of %^ORANGE%^cinnamon%^RESET%^atop the dollop of %^BOLD%^whipped cream%^RESET%^ on top.\n",
        "A thick glass has been chosen for this frozen delight, and the top of the glass has been rimmed in coarse %^BOLD%^salt%^RESET%^.  Glistening within is a frozen concoction that is a tempting %^BOLD%^%^GREEN%^light green %^RESET%^in color and has a light fragrance.  Beads of condensation run down the side of the glass, mixing with the juice from the slice of %^BOLD%^%^GREEN%^lime%^RESET%^ perched on the rim.  It is customary to lick the salt as you drink and finish off with the lime.\n"
        }));
}

void receive_given_item(object ob){
   if((string)ob->query_short() == "An empty bottle" ||
      (string)ob->query_name() == "bottle"){
      force_me("emote puts away the empty bottle.");
      ob->remove();
   }
}