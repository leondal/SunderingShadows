//random server for La Sangria
//Coded by ~Circe~ for new Seneca 11/15/07
#include <std.h>

inherit BARKEEP;

#define COLORS ({"%^ORANGE%^brown","%^BOLD%^%^BLACK%^black","%^RED%^aub%^ORANGE%^u%^RED%^rn","%^YELLOW%^golden","%^BOLD%^%^WHITE%^silvery blond"})

#define LENGTHS ({"shoulder-length","long","curly","short","chin-length"})

#define EYES ({"%^BOLD%^%^CYAN%^azure","%^BOLD%^%^BLUE%^blue","%^BOLD%^%^GREEN%^green","%^ORANGE%^chocolate","%^GREEN%^hazel"})

void create(){
   string COLOR,LENGTH,EYE;
   object obj;
   ::create();
   COLOR = COLORS[random(sizeof(COLORS))];
   LENGTH = LENGTHS[random(sizeof(LENGTHS))];
   EYE = EYES[random(sizeof(EYES))];
   set_name("a serving girl");
   set_id(({"girl","serving girl","waitress","server"}));
   set_short("A young serving girl");
   set_level(10);
   set_long("%^RESET%^%^CYAN%^This young serving girl has "+
      ""+LENGTH+" "+COLOR+" hair %^RESET%^%^CYAN%^worn loose "+
      "and flowing behind a %^BOLD%^%^BLACK%^black headband"+
      "%^RESET%^%^CYAN%^.  She has an %^GREEN%^olive %^CYAN%^"+
      "complexion and wears a %^BOLD%^%^BLACK%^black dress "+
      "%^RESET%^%^CYAN%^with a tight bodice and short sleeves.  "+
      "The skirt is flowing and ruffled, shifting lively as she "+
      "moves.  The bodice and ruffles have been edged in vibrant "+
      "%^BOLD%^c%^GREEN%^o%^RED%^l%^YELLOW%^o%^MAGENTA%^r%^BLUE%^s"+
      "%^RESET%^%^CYAN%^, brightening up the restaurant.  Her wide, "+
      "sparkling "+EYE+" eyes %^RESET%^%^CYAN%^are merry, and she "+
      "speaks with a light accent.%^RESET%^");
  set_gender("female");
  set_exp(20);
  set_alignment(1);
  set_race("human");
  set_hd(10,0);
  set_hp(100);
  set_max_hp(query_hp());
  set_body_type("human");
  set_currency("gold");
  set_menu(
       ({ "paella", "habas con jamon", "estofado", "plato seneca", "suquet", "filet with mushrooms", "gazpacho", "seneca bread", "beef empanadas", "anchovy-stuffed olives", "flan", "churros", "mato cheese", "turron", "water", "horchata", "cafe con leche", "granizado", "orange juice", "seneca select", "sangria blanca", "mango sangria", "cava" }),
       ({"food","food","food","food","food","food","food","food","food","food","food","food","food","food","water","soft drink","soft drink","soft drink","soft drink","alcoholic","alcoholic","alcoholic","alcoholic"}),
       ({40,35,25,30,25,45,20,15,25,15,35,30,25,45,10,50,35,25,25,90,60,60,85})
   );
   set_my_mess(({
       "The saffron rice blends well with the spicy chorizo sausage and shrimp.\n",
       "The saltiness of the ham and beans is tempered with the sweetness of olive oil.\n",
       "The potatoes melt in your mouth...could probably use a bit more beef though.\n",
       "Fried potatoes, spicy chorizo sausage, green peppers, and onions - what's not to love?\n",
       "The soft fish and potatoes have absorbed the tomato stew, creating a blend of flavors.\n",
       "The thin, delicate steak is delicious with the mushrooms!\n",
       "The cool tomato soup has just enough kick.\n",
       "The inside of the crusty loaf is still soft.\n",
       "The spicy beef is balanced by the potatoes and onions - delicious!\n",
       "The strong flavor of the anchovies nearly overpowers the briney olives.\n",
       "The creamy, sugary custard topped with caramel is a delight.\n",
       "Dipping the churros in chocolate sauce, you find they have a sweet crunch.\n",
       "Honey sweetens the curd cheese, making for a light dessert.\n",
       "Chewier and chewier, the turron is still pleasant with the mix of salty almonds and sweetened nougat.\n",
       "The cool, clear water has just a hint of lime flavoring.\n",
       "This isn't called the 'drink of the gods' for nothing - heavenly!\n",
       "Sipping the sweetened coffee, you feel warmed.\n",
       "The flavors of lemon and lime combine as you drink the icy beverage.  Ouch, brainfreeze!\n",
       "Juicy bits of pulp add flavor as you drink the orange juice.\n",
       "The deep red wine has a woodsy flavor that leaves you feeling light-headed.\n",
       "The sweet peaches and grapes mask the potent alcohol in this tasty drink.\n",
       "The mixture of lemonade and sweet mango blends delightfully with the red wine.\n",
       "Bubbles tickle your nose as you sip the fruity wine.\n"
       }));
   set_your_mess(
       ({
       "enjoys a bow of saffron rice with chorizo and shrimp.\n",
       "eats a serving of mushy beans with ham.\n",
       "finishes a beef and potato stew and seems slightly disappointed there isn't more.\n",
       "enjoys a plate of fried potatoes and sausage.\n",
       "sips at the tomato stew, picking out bits of fish to eat.\n",
       "devours a plate of sliced filet and mushrooms.\n",
       "drains a bowl of cold gazpacho with relish.\n",
       "breaks open a loaf of bread and eats it in pieces.\n",
       "gingerly eats the empanadas, careful not to spill the filling everywhere.\n",
       "makes a slight face and eats the anchovy-stuffed olives.\n",
       "savors the caramel-covered custard.\n",
       "dips the crispy churros in chocolate sauce before enjoying them.\n",
       "mixes the honey in the mato cheese before eating it.\n",
       "chews and chews on a bit of turron.\n",
       "drinks a refreshing glass of water.\n",
       "sips the sugary horchata with a quiet smile.\n",
       "inhales deeply and sips the coffee.\n",
       "drinks the icy beverage a little too fast and winces.\n",
       "drinks a glass of pulpy orange juice.\n",
       "swirls the deep red wine in a glass before drinking it.\n",
       "enjoys a glass of white sangria.\n",
       "drinks a glass of red sangria with delight.\n",
       "drinks a glass of sparkling pink wine.\n"
        })
    );
    set_menu_short(
        ({
        "Paella",
        "Habas con Jamon",
        "Estofado",
        "Plato Seneca",
        "Suquet",
        "Filet with Mushrooms",
        "Gazpacho",
        "Seneca Bread",
        "Beef Empanadas",
        "Anchovy-stuffed Olives",
        "Flan",
        "Churros",
        "Mato Cheese",
        "Turron",
        "Water",
        "Horchata",
        "Cafe con Leche",
        "Granizado",
        "Orange Juice",
        "Seneca Select",
        "Sangria Blanca",
        "Mango Sangria",
        "Cava"
        })
    );
    set_menu_long(
        ({
        "%^YELLOW%^A %^RESET%^%^ORANGE%^wooden bowl %^YELLOW%^has been filled with saffron rice mixed with %^RESET%^%^RED%^chorizo sausage %^YELLOW%^and %^MAGENTA%^shrimp%^YELLOW%^.  Onion, garlic, pimento, and even small bits of clam are mixed into the olive oil and white wine that make up a light sauce for this favorite dish of Seneca.%^RESET%^\n",
        "%^BOLD%^%^BLACK%^A square black plate with a deep basin is filled with %^RESET%^%^RED%^broad beans %^BOLD%^%^BLACK%^and chunks of %^MAGENTA%^ham%^BLACK%^.  The mixture has been cooked in a base of onions, garlic, and olive oil, making for a hearty - and tasty - meal.%^RESET%^\n",
        "%^ORANGE%^This thick stew is made of small chunks of %^RED%^beef %^ORANGE%^with cubes of %^RESET%^potato%^ORANGE%^.  Various other bits of vegetables are mixed within the translucent brown broth.%^RESET%^\n",
        "%^ORANGE%^Thick disks of spicy %^RED%^chorizo sausage %^ORANGE%^have been mixed with slices of %^RESET%^fried potato%^ORANGE%^.  A mixture of %^GREEN%^green pepper %^ORANGE%^and %^RESET%^onion %^ORANGE%^enhances the savory flavor.%^RESET%^\n",
        "%^RED%^A thick backdrop of tomato stew complements the light flavors of %^RESET%^fish %^RED%^and %^RESET%^shellfish%^RED%^ in this delighful concoction.  The aroma of %^YELLOW%^saffron%^RESET%^%^RED%^ rises from the steaming bowl, bringing with it a hint of %^BOLD%^wine%^RESET%^%^RED%^.%^RESET%^\n",
        "This oblong plate is layered with slices of %^ORANGE%^filet mignon %^RESET%^drizzled with a creamy sauce made up of sherry with diced %^BOLD%^%^MAGENTA%^ham%^RESET%^, %^BOLD%^%^BLACK%^truffles%^RESET%^, and %^RED%^liver%^RESET%^.  Served on the side is a generous helping of %^BOLD%^%^BLACK%^mushrooms %^RESET%^that have been sauteed in garlic and olive oil.\n",
        "Dished into a thick %^GREEN%^green earthenware bowl%^RESET%^, this %^RED%^tomato soup %^RESET%^is served cold.  It is made from a blending of ripe %^RED%^tomatoes%^RESET%^, %^GREEN%^cucumber%^RESET%^, %^GREEN%^green peppers%^RESET%^, and small cubes of %^ORANGE%^sour dough bread%^RESET%^.  Spiced lightly with %^BOLD%^garlic%^RED%^, %^RED%^red vinegar%^RESET%^, and %^GREEN%^olive oil%^RESET%^, it is a summertime favorite of the people of Seneca.\n",
        "%^ORANGE%^This small, rounded loaf of bread has a thick crust with a soft inside.  Small caraway seeds have been scattered along its top, giving it the pungent fragrance of anise.%^RESET%^\n",
        "A pair of flaky %^ORANGE%^browned pastries %^RESET%^are served on this plate.  Each is filled with a generous helping of spiced %^RED%^ground beef %^RESET%^mixed with %^BOLD%^diced onion%^RESET%^, %^RED%^tomato puree%^RESET%^, and %^BOLD%^potatoes%^RESET%^.  Empanadas are a favorite for a quick lunch in the town of Seneca.\n",
        "This small, oval %^BOLD%^%^BLUE%^blue bowl %^RESET%^is filled with large %^GREEN%^green olives %^RESET%^stuffed with %^BOLD%^%^BLACK%^anchovies%^RESET%^.  Definitely an acquired taste, the briney olives would likely be overpowered by the furry fish.\n", 
        "A small, %^BOLD%^cream-colored plate%^RESET%^ holds a %^YELLOW%^golden %^RESET%^bit of heaven.  The thick %^BOLD%^custard %^RESET%^is lightly browned and topped with gooey %^ORANGE%^caramel%^RESET%^, adding an extra touch of sweetness to this creamy concoction.\n",
        "%^ORANGE%^Lengths of pastry dough have been fried to a crispy consistency.  Each one is ridged and spirals loosely, giving it a unique shape.  A small cup of %^BOLD%^%^BLACK%^chocolate %^RESET%^%^ORANGE%^is served warm on the side and is used as a dipping sauce for the little pastries.%^RESET%^\n",
        "A small ceramic bowl has been filled with soft, fresh %^BOLD%^curd cheese%^RESET%^ mixed with a generous helping of %^ORANGE%^honey%^RESET%^.  The light dessert is eaten with a spoon and is well-liked in Seneca for an afternoon snack as well.\n",
        "Creamy %^BOLD%^white nougat %^RESET%^makes up the bulk of this delicious treat.  The nougat is created from %^ORANGE%^honey%^RESET%^, %^BOLD%^sugar%^RESET%^, and %^BOLD%^egg whites%^RESET%^ before being coated in sliced, toasted %^ORANGE%^almonds%^RESET%^.  It is served in slices rather like cake, and it appears awfully chewy.\n",
        "This slender glass has been filled with cool, crystal clear %^CYAN%^water%^RESET%^ and garnished with a slender slice of %^BOLD%^%^GREEN%^lime%^RESET%^.  It certainly looks refreshing, especially after a warm day in the sun.\n",
        "Called the 'drink of the gods', this concoction is served in a thick %^CYAN%^glass mug %^RESET%^that allows you to see the %^ORANGE%^creamy liquid %^RESET%^inside.  The color of coffee with very heavy cream, the drink is served %^CYAN%^ice cold %^RESET%^and is the chosen drink of Seneca.  It is made from water, sugar, and tigernuts, and its rich, smooth flavor is enjoyed year-round.\n",
        "%^BOLD%^%^BLACK%^A small black mug atop a matching saucer has been filled with hot, strong %^RESET%^%^ORANGE%^coffee %^BOLD%^%^BLACK%^mixed with an equal amount of %^WHITE%^milk%^BLACK%^.  It is served with a small container of %^WHITE%^sugar %^BLACK%^that may be mixed in according to taste.%^RESET%^\n",
        "A slender, thin %^CYAN%^glass tumbler%^RESET%^ has been filled with swirling bands of shaved ice in %^YELLOW%^yellow %^RESET%^and %^BOLD%^%^GREEN%^green%^RESET%^.  The icy swirls are flavored with sweetened lemon and lime juice, and this particular drink is so refreshing that those enjoying it often find themselves drinking it too quickly.\n",
        "This small tumbler holds a healthy serving of %^ORANGE%^orange juice %^RESET%^thick with pulp.  It has been kept cold and provides a wonderful addition to any meal.\n",
        "A delicate wine glass holds a deep %^RED%^red wine %^RESET%^with a heady, woodsy fragrance.  The light fruity fragrance of %^MAGENTA%^grapes %^RESET%^rises from the glass, making it a delicious choice for most spicy dishes.\n",
        "Made from %^BOLD%^white wine%^RESET%^, this fruity drink has been filled with sliced %^MAGENTA%^red %^RESET%^and %^GREEN%^green %^RESET%^grapes as well as sliced %^ORANGE%^peaches%^RESET%^.  Sweetened with %^YELLOW%^lemonade %^RESET%^and %^BOLD%^sugar%^RESET%^, it is further strengthed with a splace of %^ORANGE%^peach-flavored brandy%^RESET%^.\n",
        "With a base of %^RED%^red wine%^RESET%^, this sangria has a citrus flavor.  It has small slices of %^YELLOW%^lemon%^RESET%^, %^BOLD%^%^GREEN%^lime%^RESET%^, and %^ORANGE%^orange %^RESET%^with larger chunks of %^ORANGE%^mango%^RESET%^.  It is further sweetened with %^YELLOW%^lemonade %^RESET%^and a healthy shot of %^BOLD%^rum%^RESET%^.\n",
        "Served in a slender, fluted %^CYAN%^champagne glass%^RESET%^, this sparkling wine is a light %^BOLD%^%^MAGENTA%^pink %^RESET%^and has a fruity fragrance.  It is often enjoyed in times of celebration, though some prefer it as an occasional indulgence.\n"
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