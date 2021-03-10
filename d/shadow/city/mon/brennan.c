#include <std.h>
inherit "/std/barkeep";

void create() {
    ::create();
   	set_name("brennan");
    set_id( ({ "cofeemaster",
                    "shopkeeper",
                    "brennan",
                    "Brennan"}) );
    set_short("%^RESET%^%^BOLD%^%^BLACK%^Brenn%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^n %^BLACK%^th%^RESET%^%^ORANGE%^e %^ORANGE%^B%^BOLD%^%^BLACK%^arista%^RESET%^%^RESET%^");
    set_long("%^MAGENTA%^Having been in the business of coffee for years, Brennan is well known and loved for crafting the perfect cup of coffee for Shadow's busy residents. Always eager to serve up a snack as well as a smile, Brennan is brimming with energy and vibrancy, and never without a cup of his strongest brew in hand. The middle-aged man wears a pair of spectacles over his bright brown eyes, and is generally tidy in appearance, opting to wear a bowtie along with his apron.");
   	set_gender("male");
   	set_exp(20);
   	set_alignment(1);
   	set_level(10);
    set_race("human");
    set_body_type("human");
   	set_hd(10,0);
	set_max_hp(query_hp());
   	set_currency("silver");
	set_menu(({"coffee",
                    "espresso",
                    "cappuccino",
                    "iced green tea latte",
                    "strawberry smoothie",
                    "vanilla steamer",
                    "drinking chocolate",
                    "blueberry muffin",
                    "coffee cake",
                    "cinnamon bun",
                    "hot oatmeal",}),
        ({"soft drink",
                "soft drink",
                "soft drink",
                "soft drink",
                "soft drink",
                "soft drink",
                "soft drink",
                "food",
                "food",
                "food",
                "food", }),
        ({5,
                10,
                10,
                20,
                20,
                15,
                15,
                15,
                20,
                20,
                5,
                })
        );
    set_menu_short(({
                "A cup of steaming coffee",
                    "A small glass with a dark brown liquid",
                    "A squat steaming glass",
                    "A frothy green drink",
                    "A pink drink in a tall glass",
                    "A tall mug overflowing with whipped cream",
                    "A small striped mug",
                    "A huge blueberry muffin",
                    "A huge slice of coffee cake",
                    "A sticky cinnamon bun",
                    "A bowl of steaming oatmeal",
                    }));
    set_menu_long(({
                "The scent of this strong, steaming coffee is perfect. It is served in a white ceramic mug.",
                    "A richly brown shot of espresso in a clear glass, with a nice layer of crema on top.",
                    "Made from steamed milk and a double shot of espresso, the cappuccino features a frothy top with a spiral design adorning its surface.",
                    "Smooth and creamy green tea is lightly sweetened and served with steamed milk over ice. It's green so it must be healthy.",
                    "A whole banana, strawberries, milk and a couple secret ingredients are blended with ice. It is garnished with a strawberry, and served in a tall glass.",
                    "This drink is served in a tall ceramic mug, and iis made from warm milk and vanilla. It is topped with whipped cream and tiny chocolate sprinkles.",
                    "This thick drink is made from slivers of real chocolate, stirred with milk. It is topped off with whipped cream and flakes of white and dark chocolate.",
                    "A large muffin filled with blueberries and topped with sugary crumbs sit on a black and white striped plate, looking delicious.",
                    "This rich cake is served on a black and white striped plate, and looks incredibly appetizing. It is two layers, with a little taste of heaven in-between. The top is overflowing with crumbs.",
                    "Drizzled with icing and coated in thick, sweet, gooey cinnamon, this huge sticky bun is not for the faint of heart. It looks absolutely delicious.",
                    "This hearty and hot oatmeal is served in a white bowl with a black rim, alongside a small cup of blueberries and strawberries for some additional flavor.",
                    }));
    set_my_mess(({"The strong coffee makes you feel alive.",
                    "The rich, slightly bitter little espresso shot packs quite a punch.",
                    "The thick drink is warm and delicious.",
                    "The smooth, cool drink refreshes you.",
                    "You finish off the sweet, delicious drink and long for more.",
                    "The warm drink makes you feel warm and cozy.",
                    "The thick, melted chocolate is wonderfully satisfying.",
                    "The muffin is bursting with berries and simply delectable.",
                    "The sweet, sugary treat is perfection on a plate.",
                    "The icing leaves your lips sweet and sticky.",
                    "The oatmeal is quite warm and filling, and leaves you feeling ready for the day.",
                    }));
    set_your_mess(({
                "enjoys a fresh mug of coffee.",
                    "tosses back the last of the espresso.",
                    "finishes off the cappuccino and looks relaxed.",
                    "finishes the drink and places the tall glass aside.",
                    "drinks every last drop.",
                    "finishes the creamy drink and looks relaxed.",
                    "smiles as the last drop of chocolate is finished.",
                    "polishes off every last crumb of a blueberry muffin.",
                    "finishes the whole huge slice of cake.",
                    "finishes a sticky cinnamon bun and licks lips clean.",
                    "finishes off the warm bowl of oatmeal.",
                    }));
}

void receive_given_item(object ob){
    if((string)ob->query_short() == "An empty bottle" ||
       (string)ob->query_name() == "bottle"){
        force_me("emote puts away the empty bottle.");
        ob->remove();
    }
}

/* Emacs stuff
awk -F '|' '{printf("\"%s\",\n",$2)}' |sed -r 's/  +/ /g;s/" /"/;s/ "/"/'

   | Name                 | Type       | Price | short                                     | long                                                                                                                                                                                          | mymess                                                                           | yourmess                                             |
   |----------------------+------------+-------+-------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------+------------------------------------------------------|
   | Coffe                | soft drink |     5 | A cup of steaming coffee                  | The scent of this strong, steaming coffee is perfect. It is served in a white ceramic mug.                                                                                                    | The strong coffee makes you feel alive.                                          | enjoys a fresh mug of coffee.                        |
   | Espresso             | soft drink |    10 | A small glass with a dark brown liquid    | A richly brown shot of espresso in a clear glass, with a nice layer of crema on top.                                                                                                          | The rich, slightly bitter little espresso shot packs quite a punch.              | tosses back the last of the espresso.                |
   | Cappuccino           | soft drink |    10 | A squat steaming glass                    | Made from steamed milk and a double shot of espresso, the cappuccino features a frothy top with a spiral design adorning its surface.                                                         | The thick drink is warm and delicious.                                           | finishes off the cappuccino and looks relaxed.       |
   | Iced green tea latte | soft drink |    20 | A frothy green drink                      | Smooth and creamy green tea is lightly sweetened and served with steamed milk over ice. It's green so it must be healthy.                                                                     | The smooth, cool drink refreshes you.                                            | finishes the drink and places the tall glass aside.  |
   | Strawberry smoothie  | soft drink |    20 | A pink drink in a tall glass              | A whole banana, strawberries, milk and a couple secret ingredients are blended with ice. It is garnished with a strawberry, and served in a tall glass.                                       | You finish off the sweet, delicious drink and long for more.                     | drinks every last drop.                              |
   | Vanilla steamer      | soft drink |    15 | A tall mug overflowing with whipped cream | This drink is served in a tall ceramic mug, and iis made from warm milk and vanilla. It is topped with whipped cream and tiny chocolate sprinkles.                                            | The warm drink makes you feel warm and cozy.                                     | finishes the creamy drink and looks relaxed.         |
   | A small striped mug  | soft drink |    15 | A small striped mug                       | This thick drink is made from slivers of real chocolate, stirred with milk. It is topped off with whipped cream and flakes of white and dark chocolate.                                       | The thick, melted chocolate is wonderfully satisfying.                           | smiles as the last drop of chocolate is finished.    |
   | Blueberry Muffin     | food       |    15 | A huge blueberry muffin                   | A large muffin filled with blueberries and topped with sugary crumbs sit on a black and white striped plate, looking delicious.                                                               | The muffin is bursting with berries and simply delectable.                       | polishes off every last crumb of a blueberry muffin. |
   | Coffee Cake          | food       |    20 | A huge slice of coffee cake               | This rich cake is served on a black and white striped plate, and looks incredibly appetizing. It is two layers, with a little taste of heaven in-between. The top is overflowing with crumbs. | The sweet, sugary treat is perfection on a plate.                                | finishes the whole huge slice of cake.               |
   | Cinnamon Bun         | food       |    20 | A sticky cinnamon bun                     | Drizzled with icing and coated in thick, sweet, gooey cinnamon, this huge sticky bun is not for the faint of heart. It looks absolutely delicious.                                            | The icing leaves your lips sweet and sticky.                                     | finishes a sticky cinnamon bun and licks lips clean. |
   | Hot Oatmeal          | food       |     5 | A bowl of steaming oatmeal                | This hearty and hot oatmeal is served in a white bowl with a black rim, alongside a small cup of blueberries and strawberries for some additional flavor.                                     | The oatmeal is quite warm and filling, and leaves you feeling ready for the day. | finishes off the warm bowl of oatmeal.               |
 */
