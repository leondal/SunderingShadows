//Madelyn, head cook for the Golden Perch.  Circe 7/25/04
#include <std.h>

inherit "/std/barkeep";

void create() {
  ::create();
  set_name("madelyn");
  set_id(({"madelyn","Madelyn","bartender","barkeep","serving woman","waitress"}));
  set_short("Madelyn, head serving woman");
  set_level(16);
  set_long(
     "Madelyn is an aging firbolg matron with streaks of gray in "+
     "her long auburn hair.  She maintains control of the other "+
     "serving girls in the Golden Perch with a wooden spoon she "+
     "wields like a scepter.  Her crisp orders are punctuated with "+
     "a smooth smack of the spoon, though the other girls are "+
     "hard working enough that it hardly seems needed.  She speaks "+
     "in a heavily accented dialect of the firbolg language, and "+
     "she seems more inclined to talk to her stews than the patrons.  "+
     "Still, she takes their orders and delivers in record time, and "+
     "there is no firbolg in Lothwaite who does not admire her "+
     "discipline...or her food."
  );
  set_gender("female");
  set_exp(20);
  set_alignment(4);
set_race("firbolg");
  set_hd(16,0);
  set_hp(200);
  set_max_hp(query_hp());
  add_money("gold", random(50));
  set_body_type("human");
  set_currency("silver");
  set_menu(
       ({ "mead","honey ale","lothwaite lager","mulled cider","hot toddy",
          "whiskey","dandelion wine","rum","brandy","gin","water",
          "berry breeze","honey chocolate","honey lemonade","cabbage soup",
          "deer stew","roasted venison","bread","cottage cheese and fruit",
          "salted bacon","nuts and berries","honeyed fruit","lamb kebabs",
          "roasted salmon","honeycake","fruit parfait","pear delight" }),
       ({ "alcoholic","alcoholic","alcoholic","alcoholic","alcoholic",
          "alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","water",
          "soft drink","soft drink","soft drink","food","food","food",
          "food","food","food","food","food","food","food","food","food",
          "food"}),
       ({18,15,15,20,10,35,50,30,35,25,10,20,20,10,10,15,20,5,8,12,8,10,20,30,5,7,10})
   );
   set_my_mess(({
      "The mead slides smoothly down your throat, leaving the sweet taste of honey.\n",
      "The somewhat bitter taste of the ale mixes with the sweetness of honey.\n",
      "The cool, refreshing taste of the lager is heightened with a hint of honey.\n",
      "You drink the thick cider flavored with apple brandy, cinnamon, and allspice.\n",
      "The hot tea warms you to the bone as the flavor of brandy and honey hits your tongue.\n",
      "You slam down the whiskey and feel your throat tighten.\n",
      "You drink the surprisingly sweet wine and inhale the fragrance of summers gone by.\n",
      "Your tongue tingles with the taste of sugar as you slam down the shot of rum.\n",
      "You take the shot of brandy, relishing the smooth taste on your tongue.\n",
      "The dry gin makes your eyes bulge as you down the shot.\n",
      "You drink the cool, refreshing water and feel your thirst fade away.\n",
      "You taste the sweetness of berries and honey as you drink the milk.\n",
      "You taste the slightly bitter cocoa before it is sweetened with the smoothness of honey and milk.\n",
      "As you drink the lemonade, you taste sweet honey and can't help but smile.\n",
      "You lift the bowl of cabbage soup to your lips and drain the last of the pungent cabbage.\n",
      "You eat the deer stew and notice the meat is slightly gamey but the vegetables are good.\n",
      "You enjoy the roasted venison seasoned with parsley and herbs.\n",
      "You eat a piece of the thin, flaky flatbread.\n",
      "The thick cottage cheese masks the sweetness of the berries.\n",
      "You eat the bacon, leaving your fingertips covered in salty grease.\n",
      "The crunch of the nuts adds texture to the sweet berries.\n",
      "You enjoy a bowl of cut fruit ladled with rich honey cream sauce.\n",
      "The spicy taste of lamb is further enhanced by the carrots and peppers.\n",
      "You eat the salmon with gusto, enjoying the fragrant herb seasoning and the crisp roasted skin.\n",
      "You eat a light, sweet honeycake and feel warm inside.\n",
      "You dig into the fruit parfait and taste a mixture of sweetened cream, berries, apples, and pears.\n",
      "The buttery, flakey pastry provides a smooth contrast to the sweet honey-coated pears.\n"
      }));
   set_your_mess(
       ({
       "drinks a tall mug of mead with a smile.\n",
       "downs the ale with a somewhat surprised expression.\n",
       "seems to enjoy the cool honey lager.\n",
       "slowly drinks a thick brown cider.\n",
       "sips the tea as steam rises from the cup.\n",
       "slams down a shot of whiskey.\n",
       "drinks the glass of wine with closed eyes.\n",
       "slams down a shot of rum.\n",
       "slams down a shot of brandy.\n",
       "slams down a shot of gin with bulging eyes.\n",
       "drinks a glass of cool, clear water.\n",
       "enjoys a thick glass of berries crushed in milk.\n",
       "makes a slight face then seems to enjoy the cocoa-flavored milk.\n",
       "drinks the glass of lemonade with a smile.\n",
       "drains a bowl of cabbage soup.\n",
       "eats the deer stew with a somehwat thoughtful expression.\n",
       "tears into the roasted leg of vension.\n",
       "eats a piece of thin, flakey flatbread.\n",
       "eats a small bowl of cottage cheese and berries.\n",
       "gobbles down several slices of bacon, leaving a greasy mess.\n",
       "crunches on a mixture of nuts and berries.\n",
       "eats a light mixture of cut fruit in a honey cream sauce.\n",
       "enjoys the spicy lamb straight off the skewer.\n",
       "eats the salmon with gusto, skin and all.\n",
       "eats a small, sweet honeycake.\n",
       "enjoys a refreshing dessert of fruit and cream.\n",
       "eats a honeyed pear baked in a thin, flakey pastry.\n"
       })
    );
    set_menu_short(
        ({
        "Mead",
        "Honey Ale",
        "Lothwaite Lager",
        "Mulled Cider",
        "Hot Toddy",
        "Shot of Whiskey",
        "Dandelion Wine",
        "Shot of Rum",
        "Shot of Brandy",
        "Shot of Gin",
        "Glass of Water",
        "Berry Breeze",
        "Honey Chocolate",
        "Honey Lemonade",
        "Cabbage Soup",
        "Deer Stew",
        "Roasted Venison",
        "Bread",
        "Cottage Cheese and Fruit",
        "Salted Bacon",
        "Nuts and Berries",
        "Honeyed Fruit",
        "Lamb Kebabs",
        "Roasted Salmon",
        "Honeycake",
        "Fruit Parfait",
        "Pear Delight"
        })
    );
    set_menu_long(
        ({
        "%^YELLOW%^A thick soapstone mug fitted with a handle carved "+
           "in the likeness of a bear holds this drink.  The mug is "+
           "filled with a thick, honey-colored liquid that seems "+
           "to reflect the light.  This drink is the pride of Lothwaite, "+
           "and it is the chosen drink of the townsmen here - all of "+
           "whom, it seems, know how to brew their own.%^RESET%^\n",
        "%^ORANGE%^The thick liquid in this mug is a dark amber, "+
           "lightened somewhat by the swirling %^YELLOW%^honey "+
           "%^RESET%^%^ORANGE%^added by hand to each glass.  The "+
           "ale is said to come from the dwarves of Kinaro, one of "+
           "the few societies the people of Lothwaite have approached "+
           "to establish regular trade.  A somewhat earthy fragrance "+
           "rises from the mug.%^RESET%^\n",
        "%^ORANGE%^This thick lager is made in the colder reaches of "+
           "the valley, where it is brewed and left to chill.  The "+
           "residents of Lothwaite make it from their own recipe, "+
           "sweetened - naturally - with %^YELLOW%^honey%^RESET%^"+
           "%^ORANGE%^.  Each batch is left to chill for one full "+
           "winter, a fact which locals claim accounts for the way "+
           "the lager stays cold without ice.%^RESET%^\n",
        "%^RED%^Originally made as a non-alcoholic drink for the "+
           "children of Lothwaite, the citizens soon found a way "+
           "to make it even better by fermenting the apples, then "+
           "adding an even more potent apple brandy.  A light dusting "+
           "of cinnamon and allspice completes the drink, which is "+
           "served warm in a soapstone mug and garnished with a stick "+
           "of cinnamon.%^RESET%^\n",
        "A small mug is used to serve this %^ORANGE%^tea %^RESET%^"+
           "steaming hot.  The scent of brandy rises from the pale "+
           "%^ORANGE%^orange liquid%^RESET%^, and a swirling line of "+
           "%^YELLOW%^honey %^RESET%^seems to be dissolving in it "+
           "even as you watch.\n",
        "An unusual shot glass made of thin soapstone holds a larger-"+
           "than-usual shot of %^BOLD%^whiskey%^RESET%^.   The glass "+
           "has been decorated with colored glazes, streaking the "+
           "outside of the glass in all shades of %^BOLD%^%^CYAN%^"+
           "b%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^u%^RESET%^%^BLUE%^e"+
           "%^RESET%^.\n",
        "%^ORANGE%^This fragrant wine is served in a delicate wooden "+
           "wine glass carved with a repeating band of colored "+
           "%^BOLD%^%^GREEN%^d%^YELLOW%^andelion%^GREEN%^s%^RESET%^"+
           "%^ORANGE%^.  The wine itself is of a light %^YELLOW%^yellow "+
           "hue %^RESET%^%^ORANGE%^and has a sweet fragrance "+
           "reminiscent of a %^CYAN%^cool breeze %^ORANGE%^on a "+
           "warm summer day.%^RESET%^\n",
        "A squat, square wooden shot glass holds the thick "+
           "%^BOLD%^rum %^RESET%^that it tinted slightly %^YELLOW%^"+
           "golden%^RESET%^.  The rum bears the sweet fragrance of "+
           "sugar and coconuts.\n",
        "A simple wooden shot glass holds this large shot of "+
           "brandy.  The bold, fragrant aroma of the brandy "+
           "rises from the glass.\n",
        "This tall shot glass is made of thin soapstone that holds "+
           "a clear gin.  The rather dry aroma of gin rises from the "+
           "swirling liquid inside.\n",
        "The %^CYAN%^cool water %^RESET%^in this soapstone mug "+
           "was drawn from the clean lake on the northern edge "+
           "of Lothwaite.  It would probably prove quite refreshing.\n",
        "A thick mug has been chilled and used to hold this sweet "+
           "dairy concoction, which is a local favorite among "+
           "the children of Lothwaite.  %^BOLD%^Cold milk %^RESET%^"+
           "has been mixed with mashed %^BOLD%^%^BLUE%^blueberries"+
           "%^RESET%^, %^MAGENTA%^blackberries%^RESET%^, and a few "+
           "%^BOLD%^%^RED%^strawberries %^RESET%^mixed with a "+
           "generous dollop of %^YELLOW%^honey%^RESET%^.\n",
        "%^BOLD%^%^BLACK%^Cocoa powder has been mixed with sweet "+
           "%^WHITE%^milk %^BLACK%^to create this unusual drink.  "+
           "%^YELLOW%^Honey %^BLACK%^has been stirred in to "+
           "further sweeten the drink, which has been garnished "+
           "with a fresh dusting of cocoa powder.%^RESET%^\n",
        "A simple twist on normal %^YELLOW%^lemonade%^RESET%^, "+
           "this drink has been made with %^CYAN%^cool water "+
           "%^RESET%^and fresh %^YELLOW%^lemon juice %^RESET%^"+
           "then sweetened with %^YELLOW%^honey %^RESET%^taken "+
           "from one of the many beehives around the valley.\n",
        "A shallow %^ORANGE%^wooden bowl %^RESET%^holds this "+
           "%^BOLD%^%^GREEN%^pale green soup %^RESET%^made "+
           "primarily of boiled %^GREEN%^cabbage leaves%^RESET%^.  "+
           "The %^GREEN%^cabbage %^RESET%^has been boiled to a "+
           "point where it has lost most of its color and texture, "+
           "but it still smells the same.\n",
        "The thick %^ORANGE%^brown broth %^RESET%^that forms "+
           "the base of this stew was made from boiling the "+
           "bones of a deer along with its %^RED%^meat%^RESET%^.  "+
           "After the bones were removed, %^ORANGE%^carrots%^RESET%^, "+
           "%^GREEN%^beans%^RESET%^, and %^BOLD%^turnips%^RESET%^ "+
           "were added along with various herbs and seasonings.  "+
           "The result is a hearty, aromatic stew that looks "+
           "tantalizing.\n",
        "This succulent leg of venison was roasted on a spit over "+
           "the open %^RED%^flame%^RESET%^, leaving the edges "+
           "crispy.  A mixture of %^GREEN%^herbs %^RESET%^and "+
           "%^YELLOW%^butter %^RESET%^was poured onto the meat "+
           "while it cooked, sealing in the flavor.\n",
        "%^BOLD%^There is little to this bread, which is a simple "+
           "flakey flatbread only slightly risen.  Despite its "+
           "simplicity, it looks like it would make a nice "+
           "addition to any meal, especially a soup or stew.%^RESET%^\n",
        "%^ORANGE%^This small wooden bowl holds a mixture of berries - "+
           "mostly %^RED%^raspberries%^ORANGE%^, %^MAGENTA%^"+
           "elderberries%^ORANGE%^, %^BOLD%^%^RED%^cherries%^RESET%^"+
           "%^ORANGE%^, and %^MAGENTA%^blackberries%^ORANGE%^.  "+
           "Covering the berries is a thick, lumpy %^WHITE%^cottage "+
           "cheese%^ORANGE%^.%^RESET%^\n",
        "Half a dozen thick-cut slices of marbled %^RED%^bacon "+
           "%^RESET%^lie on this wooden platter.  The %^RED%^"+
           "bacon %^RESET%^looks somewhat greasy, a fact that "+
           "has been covered over with a good layer of %^BOLD%^"+
           "salt %^RESET%^sprinkled generously all around it.  "+
           "This is a favorite breakfast among the men of Lothwaite, "+
           "although many are known to eat it at any time with "+
           "a piece of bread.\n",
        "This simple fare is a bowl of %^RED%^raspberries%^RESET%^, "+
           "%^MAGENTA%^elderberries%^RESET%^, and bright %^BOLD%^"+
           "%^RED%^cherries %^RESET%^mixed with a liberal amount "+
           "of chopped %^ORANGE%^walnuts %^RESET%^and %^BOLD%^"+
           "hazelnuts%^RESET%^.  No glaze has been added, but the "+
           "sweetness of the fruit would most likely be enough.  "+
           "This dish is a favorite among the people of Lothwaite, "+
           "either alone as a midday snack or as a beginning course "+
           "for a full meal.",
        "This dish consists of a bowl of cut fruit - fresh "+
           "%^RED%^apples%^RESET%^, %^YELLOW%^pears%^RESET%^, "+
           "and %^BOLD%^%^RED%^cherries %^RESET%^- drizzled in "+
           "a light sauce made of %^BOLD%^sweet cream %^RESET%^"+
           "and %^YELLOW%^pure honey%^RESET%^.  The fruit is "+
           "normally eaten with the fingers and is considered a "+
           "side dish to the citizens of Lothwaite.\n",
        "Because of the small size of lamb pieces compared to "+
           "venison and beef, the citizens of Lothwaite have "+
           "devised an ingenious way to cook it over the open "+
           "%^RED%^flame%^RESET%^.  The small %^ORANGE%^lamb "+
           "pieces %^RESET%^are placed on an %^BOLD%^%^BLACK%^"+
           "iron skewer %^RESET%^alongside %^BOLD%^onions"+
           "%^RESET%^, %^GREEN%^peppers%^RESET%^, and - "+
           "a Lothwaite favorite - %^BOLD%^turnips%^RESET%^.  "+
           "The skewer is then placed upon a grate over the "+
           "%^RED%^flames%^RESET%^, where it cooks to perfection.\n",
        "A culinary treat, it is said that no one in the realms "+
           "can cook %^BOLD%^%^MAGENTA%^salmon %^RESET%^better "+
           "than those who live in Lothwaite.  And in Lothwaite, "+
           "it is said that no one's %^BOLD%^%^MAGENTA%^salmon "+
           "%^RESET%^is better than Madelyn's.  The fish is "+
           "cooked whole, skin on to seal in the flavor.  "+
           "Small incisions have been made along the body, with "+
           "%^YELLOW%^butter %^RESET%^and Madelyn's secret "+
           "blend of %^GREEN%^herbs %^RESET%^pressed inside.\n",
        "%^ORANGE%^This flat cake is a delight to the children "+
           "of Lothwaite.  Simple in design, it is nothing more "+
           "than a thin bread flavored with %^YELLOW%^honey "+
           "%^RESET%^%^ORANGE%^and drizzled with a smooth caramel "+
           "%^YELLOW%^honey sauce%^RESET%^%^ORANGE%^.%^RESET%^\n",
        "%^BOLD%^A thick %^YELLOW%^honeyed %^WHITE%^cream makes "+
           "up the majority of this naturally sweet dessert.  Beneath "+
           "the top layer of cream are alternating layers of cream, "+
           "%^BLUE%^blueberries%^WHITE%^,%^RED%^strawberries%^WHITE%^, "+
           "and %^RED%^raspberries%^WHITE%^, each of which adds "+
           "its own unique taste to this dessert.%^RESET%^\n",
        "This baked dessert is made from a %^BOLD%^flakey pastry "+
           "%^RESET%^sweetened with %^ORANGE%^honey%^RESET%^.  "+
           "Nestled within the pastry is a peeled %^YELLOW%^"+
           "golden pear half%^RESET%^.  The %^YELLOW%^pear "+
           "%^RESET%^has been drizzled with %^ORANGE%^honey "+
           "%^RESET%^and dusted with a light coating of %^ORANGE%^"+
           "cinnamon%^RESET%^.\n"
        })
    );
}
