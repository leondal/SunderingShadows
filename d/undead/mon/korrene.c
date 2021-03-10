#include "../undead.h"
inherit BARKEEP;

void create() {
    ::create();
    set_name("Korrene");
    set_race("human");
    set_gender("female");
    set_body_type("human");
    set_id(({"Korrene","korrene","innkeeper"}));
    set_short("Korrene, owner of the Rum and Monkey");
    set("aggressive", 0);
    set_level(20);    
    set_long("%^RESET%^%^CYAN%^Korrene seems to be barely older than a girl, "
"but has a hardened look to her %^BLUE%^cobalt eyes %^CYAN%^that betrays "
"experience beyond her years.  Her %^BOLD%^%^BLACK%^dark hair %^RESET%^%^CYAN%^"
"is cropped short, forming a glossy frame that falls to either side of her face"
".  Her skin is fairly %^RESET%^pale%^CYAN%^, likely for lack of exposure to "
"the sun.  She seems right at home here, moving around with an assured ease "
"that could only belong to the owner of this place.%^RESET%^");
    set_alignment(6);
    set_hp(300);
    add_money("gold", random(30));
    set_currency("silver");
    set_menu(
({ "juice", "ale", "coffee", "deathblow", "nuts", "pretzels", "potato", "eggs" }),
({ "soft drink", "alcoholic", "coffee", "alcoholic", "food", "food", "food", "food" }),
({ 12, 7, 15, 25, 7, 5, 10, 12 })
    );
    
    set_my_mess(({
      "The juice seems to have been watered down, but it is very refreshing.\n",
      "The ale goes down smooth, leaving flecks of foam around your mouth.\n",
      "The usually bitter taste of coffee is tinged with a faint hint of sweetness.\n",
      "You throw back the mouthful of dark liquid, and it burns all the way down.\n",
      "The nuts are crisp and rich in flavor.\n",
      "The salty taste of the pretzels is a pleasantly savory snack.\n",
      "The topping adds just the right amount of flavor to the bland potato.\n",
      "The pickled eggs leave a spicy aftertaste in your mouth.\n",
    }));
    
    set_your_mess(({
      "looks refreshed after drinking a glass of juice.\n",
      "throws back a frosted glass of ale.\n",
      "sips from the mug of hot coffee.\n",
      "throws back the mouthful of dark liquid and turns a little red.\n",
      "eats a handful of nuts.\n",
      "crunches on a pretzel.\n",
      "eats the last of a baked potato.\n",
      "pops a pickled egg into their mouth.\n",
    }));

    set_menu_short(({
      "%^RESET%^%^ORANGE%^A glass of fruit juice%^RESET%^",
      "%^RESET%^%^ORANGE%^A frosted glass of ale%^RESET%^",
      "%^BOLD%^%^BLACK%^A steaming mug of coffee%^RESET%^",
      "%^RESET%^%^RED%^A short glass of dark crimson liquid%^RESET%^",
      "%^RESET%^%^RED%^A bowl of mixed nuts%^RESET%^",
      "%^RESET%^A plate of salted pretzels%^RESET%^",
      "%^YELLOW%^A hot baked potato%^RESET%^",
      "%^RESET%^%^GREEN%^A plate of pickled eggs%^RESET%^",
    }));

    set_menu_long(({
      "%^RESET%^%^ORANGE%^This glass is filled with juice of a pale orange "
"color.%^RESET%^\n",
      "%^RESET%^%^ORANGE%^Thick foam lies atop this frosted glass full of "
"amber-colored ale.%^RESET%^\n",
      "%^BOLD%^%^BLACK%^Thick steaming coffee swirls in this mug, with lighter "
"traces throughout. It seems they've even added milk!.%^RESET%^\n",
      "%^RESET%^%^RED%^This short glass is barely bigger than a shotglass, and "
"is filled with a deep crimson liquid.  It smells very strong, a little like "
"rum.%^RESET%^\n",
      "%^RESET%^%^RED%^This bowl is filled with unshelled nuts.  Fortunately "
"they are easily broken to reveal the tasty inner portion.%^RESET%^\n",
      "%^RESET%^%^CYAN%^Several large curls of pretzel lie on this platter.  "
"They seem freshly made and are heavily salted.%^RESET%^\n",
      "%^YELLOW%^A steaming-hot baked potato sits in the middle of this plate, "
"topped with slices of onion and wild mushroom, and a dash of cream.%^RESET%^\n",
      "%^RESET%^%^GREEN%^Pickled eggs, some whole and some sliced, form the "
"centrepiece for this dish.  Slices of beet and onion accompany the dish as a "
"garnish.%^RESET%^\n",
    }));
}

void receive_given_item(object ob) {
    if((string)ob->query_short() == "An empty bottle" || (string)ob->query_name() == "bottle") {
      force_me("emote puts away the empty bottle.");
      ob->remove();
    }
}
