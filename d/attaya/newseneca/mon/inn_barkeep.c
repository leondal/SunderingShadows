#include <std.h>
inherit BARKEEP;

void create(){
   ::create();
   remove_std_db();
   remove_dbs(({"barkeep","waitress"}));
   remove_random_act_dbs(({"barkeeprandom","waitress"}));
   set_name("Ferran");
   set_short("Ferran Ironbringer, dwarven barkeep");
   set_id(({"ferran","Ferran","ferran ironbringer","Ferran Ironbringer","barkeep","dwarven barkeep"}));
   set_long("%^RESET%^%^CYAN%^With broad shoulders and a thick chest, Ferran looks more "
      "blacksmith than bartender. The burly dwarf wears his %^RED%^auburn hair %^CYAN%^"
      "and beard long. Both sport thick and thin braids set with %^ORANGE%^copper "
      "bands %^CYAN%^that %^YELLOW%^gleam %^RESET%^%^CYAN%^in the dim light. His "
      "lined face often breaks into an easy smile as he serves customers, but it "
      "settles into its customary gruff expression as he polishes glasses or "
      "takes stock of his inventory. Ferran keeps busy, cleaning the lounge and "
      "polishing the bar in between orders.%^RESET%^");
   set_race("dwarf");
   set_gender("male");
   set_hd(10,5);
	set_max_hp(50+random(25));
	set_hp(query_max_hp());
	set_alignment(1);
	set_overall_ac(5);
	set_level(10);
	set_exp(10);
	set_property("swarm",1);
   remove_std_db();
	remove_dbs(({"barkeep"}));
	remove_random_act_dbs(({"barkeeprandom"}));
	set("aggressive",0);
	set_currency("silver");
   set_menu(
   ({"dwarven ale","lager","mulberry wine","mead","chardonnay","merlot","malbec","attaya ale","apple cider","currant wine","pomegranate wine","coffee","cappuccino","espresso","water","raspberry lemonade"}),
({"alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","caffeine","caffeine","caffeine","water","water"}),
   ({75,10,10,20,10,12,15,25,8,11,8,10,25,40,8,10})
   );
   set_my_mess(({
   "The full-bodied ale has quite a kick. You can see why dwarves have so much hair on their chest ... and everywhere else.",
   "The beer has a light taste that is perfect for the heat of Attaya.",
   "This full-bodied wine has a fruity finish with the fragrance of cherries.",
   "The mead warms you with the sweet flavor of honey and the burn of alcohol.",
   "Slightly dry, the chardonnay has a light, crisp flavor.",
   "The rich merlot carries the flavor of plums with a smooth finish.",
   "The malbec has a complex flavor of blackberry and plum with hints of cocoa and violet.",
   "Nothing quite like a good mug of ale.",
   "The delicate apple cider has a fruity flavor with a faint tingle of alcohol.",
   "The currant wine seems to have more fragrance than flavor as your senses are overcome with floral notes.",
   "The sweet pomegranate wine has a tart finish that makes your lips pucker.",
   "You down the black coffee, feeling it heat you from within.",
   "The foamed milk lessens the intensity of the espresso base, and the drink finishes with the sweet, spicy taste of cinnamon.",
   "The stout espresso is thick and pungent, bringing a bold, almost bitter flavor.",
   "The glass is filled with water that has been infused with cucumber - a favorite practice among the citizens of Seneca. The result is a refreshingly cool flavor.",
   "Plenty of sugar has been used to bring the tartness of the lemons in line with the delicate sweetness of the ripe raspberries."
   }));
   set_your_mess(({
   "downs a mug of dwarven ale.",
   "drinks amber beer from a frosted mug.",
   "sips from a slender glass of mulberry wine.",
   "seems to enjoy a glass of honey mead.",
   "tips back a glass of chardonnay.",
   "drinks deeply from a glass of merlot.",
   "swirls the malbec in the glass before taking a sip.",
   "drains a mug of ale.",
   "enjoys a bottle of cold apple cider.",
   "drinks a glass of currant wine and looks somewhat confused.",
   "drains a glass of pomegranate wine through puckered lips.",
   "tips back a mug of black coffee.",
   "sips foam from the cappuccino before drinking.",
   "slams back a small mug of espresso and looks more alert.",
   "drinks a glass of water.",
   "nurses a tall glass of raspberry lemonade."
   }));
   set_menu_short(({
   "%^RESET%^%^RED%^Dwarven Ale%^RESET%^",
   "%^RESET%^%^ORANGE%^Lager%^RESET%^",
   "%^RESET%^%^MAGENTA%^Mulberry Wine%^RESET%^",
   "%^YELLOW%^Mead%^RESET%^",
   "%^BOLD%^%^WHITE%^Chardonnay%^RESET%^",
   "%^RESET%^%^RED%^Merlot%^RESET%^",
   "%^RESET%^%^MAGENTA%^Malbec%^RESET%^",
   "%^RESET%^%^ORANGE%^Attaya Ale%^RESET%^",
   "%^RESET%^%^RED%^Apple Cider%^RESET%^",
   "%^RESET%^%^MAGENTA%^Currant Wine%^RESET%^",
   "%^BOLD%^%^MAGENTA%^Pomegranate Wine%^RESET%^",
   "%^RESET%^%^ORANGE%^Coffee%^RESET%^",
   "%^RESET%^%^ORANGE%^Cappuccino%^RESET%^",
   "%^BOLD%^%^BLACK%^Espresso%^RESET%^",
   "%^RESET%^%^CYAN%^Water%^RESET%^",
   "%^BOLD%^%^RED%^Raspberry %^YELLOW%^Lemonade%^RESET%^"
   }));
   set_menu_long(({
   "%^RESET%^%^RED%^This ale is so dark it is a deep burgandy when held up "
      "to the light. Served warm in a thick mug, there is likely nothing "
      "refreshing about it, but it sure seems to be a favorite among the "
      "more hearty dwarves.%^RESET%^",
   "%^RESET%^%^ORANGE%^This amber beer has a thin head that does not quite "
      "reach the rim of the tall glass. The fragrance of hops and malt "
      "rises from the drink, which is enjoyed by citizens and visitors "
      "throughout Seneca. It is served with a slender slice of lime.%^RESET%^",
   "%^RESET%^%^MAGENTA%^A graceful stemmed glass holds this deep purple wine "
      "that has a fruity aroma. If you swirl the glass, you can just catch "
      "a hint of cherries mixed with the mulberry.%^RESET%^",
   "%^YELLOW%^The honey yellow color of this beverage gives the illusion "
      "of sweetness and innocence. While a hint of sweetness remains from the "
      "honey, the high alcohol content and kick of spice bring some heat.%^RESET%^",
   "The %^BOLD%^chardonnay%^RESET%^ is served in a slender stemmed glass "
      "that is foggy with condensation from the chilled wine. A fruity flavor "
      "with a faint scent of tannins and perhaps oak rises from the glass.", 
   "%^RESET%^%^RED%^The merlot is a deep red bordering on purple that hints "
      "at the %^MAGENTA%^plums%^RED%^ mixed with the grapes. Served in a wide, "
      "stemmed glass, the wine is customarily allowed to breathe for a time "
      "before it is consumed.%^RESET%^",
   "%^RESET%^%^RED%^Served in a wide, stemless glass, the malbec is the deep "
      "purple-black of a fresh bruise. The flavor is complex, and the fragrance "
      "no less so. You catch the expected notes of grape and blackberry with "
      "more unexpected floral tones and even a whiff of cocoa.%^RESET%^",
   "%^RESET%^%^ORANGE%^The standard brew of Attaya, this ale is not too strong "
      "and not too weak. It has a brown tint with a bitter smell, and it is "
      "enjoyed by many of the citizens of Seneca.%^RESET%^",
   "%^RESET%^%^RED%^Served in a bottle, the apple cider is a rich %^ORANGE%^golden color %^RED%^"
      "with the crisp scent of apples. A hint of cinnamon has been added, and "
      "many say this drink is the perfect companion to Kairi's desserts.%^RESET%^",
   "%^RESET%^%^MAGENTA%^Currant wine is typically considered an acquired taste - "
      "though some wonder why one would bother acquiring it. The currants used have "
      "little flavor, so their juice is often mixed with other fruits to obtain a "
      "drinkable beverage. This particular vintage has a strong floral note rising "
      "from the fluted glass.%^RESET%^", 
   "%^BOLD%^%^MAGENTA%^This tall, stemmed glass is filled with a deep pink wine with "
      "a sweet, fruity fragrance. As a garnish, a few fresh pomegranate seeds have been "
      "dropped into the bottom of the glass.%^RESET%^", 
   "%^RESET%^%^ORANGE%^This coffee is served %^BOLD%^%^BLACK%^black %^RESET%^"
      "%^ORANGE%^in a simple white mug. Steam rises from the cup, and it thankfully "
      "has none of that acrid burnt smell sometimes encountered.%^RESET%^",
   "%^RESET%^%^ORANGE%^Served in a dark brown cup, this cappuccino is essentially "
      "espresso tempered with cream and sugar. It is topped with foamed milk and a "
      "sprinkling of cinnamon.%^RESET%^",
   "%^BOLD%^%^BLACK%^Served in a mug that seems made for a halfling, this coffee "
      "drink is thick and black, making normal coffee seem pale in comparison. It "
      "is topped with a scant amount of crema, but no sugar has been added.%^RESET%^",
   "The glass is filled with water that has been infused with cucumber - a favorite "
      "practice among the citizens of Seneca. The result is a refreshingly cool flavor.",
   "%^YELLOW%^This tall, slender glass has been filled with a cold pink liquid that "
      "smells of lemon, raspberry - and sugar. Frozen raspberries bob inside the "
      "glass, cooling the drink, while the top has been garnished with a sugar rim "
      "and a slice of lemon.%^RESET%^"
   }));
}
