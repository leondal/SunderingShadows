//Chef mob for refuge -- Yves
#include <std.h>
#include "../argabbr.h"
inherit BARKEEP;

void create() {
    ::create();
    set_id(({
        "alirin",
        "tanyrael",
        "alirin tanyrael",
        "chef",
        "baker",
        "hostess"
    }));
    set_name("Alirin");
    set_short("Alirin Tanyrael, Baker and Hostess");
    set_long((:TO,"long_desc":));
    set_hd(35,10);
    set("aggressive", 0);
    set_level(35);
    set_gender("female");
    set_class("fighter");
    set_mlevel("fighter", 35);
    set_guild_level("fighter",35);
    set_alignment(4);
    set_race("elf");
    add_money("gold", random(25));
    set_body_type("human");
    set_mob_magic_resistance("low");
    set_overall_ac(-20);
    set_stats("strength",19);
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("dexterity",18);
    set_stats("constitution",16);
    set_stats("charisma",14);
    set_max_hp(350+random(50));
    set_hp(query_max_hp());
    set_exp(100);
    set_property("swarm",0);
    force_me("speech seem to almost giggle as she talks");
    set_currency("gold");
    set_menu(
    ({
        "forest water",
        "iced tea",
        "fresh lemonade",
        "herbal tea",
        "feywine",
        "elverquisst",
        "elven waybread",
        "wild berry pie",
        "fried dula",
        "fruit salad",
        "voratae bisque",
        "corence and mushroom soup",
    }),
    ({
        "water",
        "soft drink",
        "soft drink",
        "soft drink",
        "alcoholic",
        "alcoholic",
        "food",
        "food",
        "food",
        "food",
        "food",
        "food",
    }),
    ({1, 3, 3, 5, 75, 150, 3, 3, 5, 3, 6, 6})
    );
    set_menu_short(({
        "A glass of water",
        "A glass of iced tea",
        "A glass of lemonade",
        "A cup of herbal tea",
        "A glass of feywine",
        "A glass of elverquisst",
        "A loaf of elven waybread",
        "A slice of wild berry pie",
        "A plate of fried dula",
        "A cup of fruit salad",
        "A bowl of voratae bisque",
        "A bowl of corence and mushroom soup",
    }));
    set_menu_long(({
        "%^BOLD%^%^CYAN%^This is a tall glass of crisp spring water, taken from the "
            "springs of %^RESET%^%^GREEN%^Argentrock%^BOLD%^%^CYAN%^.%^RESET%^",

        "%^YELLOW%^This is a nice tall glass of %^CYAN%^iced%^YELLOW%^ tea sweetened with %^RESET%^%^ORANGE%^honey%^BOLD%^.%^RESET%^",

        "%^YELLOW%^This is a cold glass of fresh lemonade that is brimming with "
            "pulp.%^RESET%^",

        "%^GREEN%^This is a cup of hot fragrant herbal tea with a hint of %^YELLOW%^lemon%^RESET%^%^GREEN%^.%^RESET%^",

        "%^BOLD%^%^RED%^The feywine comes up the halfway mark in this tall wine glass.%^RESET%^",

        "%^RED%^This is a wine glass, filled with a ruby colored substance.%^RESET%^",

        "%^ORANGE%^This is a loaf of famous freshly baked %^MAGENTA%^elven%^ORANGE%^ waybread. It is "
            "%^BOLD%^%^BLACK%^crispy%^RESET%^%^ORANGE%^ and brown on the outside, and soft on the inside "
            "with a %^BOLD%^%^WHITE%^creamy white%^RESET%^%^ORANGE%^ color.%^RESET%^",

        "%^MAGENTA%^This is a slice of pie that is stuffed full of %^BOLD%^%^RED%^wild cherries%^RESET%^%^MAGENTA%^, "
            "%^BLUE%^blueberries%^MAGENTA%^ and %^RED%^boysenberries%^MAGENTA%^.%^RESET%^",

        "%^ORANGE%^This is a plate of dula, a tuberous vegetable similar to the "
            "potato, that has been sliced and fried in vegetable oil.%^RESET%^",

        "%^BOLD%^%^BLUE%^This is a cup of fruits that have been tossed and topped with a "
            "%^WHITE%^whipped cream%^BLUE%^. There are small purple berries called %^RESET%^%^MAGENTA%^Ram "
            "Berries%^BOLD%^%^BLUE%^, an apple-like fruit called %^RESET%^Celarta%^BOLD%^%^BLUE%^, and %^RESET%^%^GREEN%^Davalsa%^BOLD%^%^BLUE%^ "
            "which are similar to grapes. There are also a few of the "
            "more %^BLACK%^common%^BLUE%^ fruits such as %^RESET%^%^RED%^apples%^BOLD%^%^BLUE%^, %^MAGENTA%^grapes%^BLUE%^ and %^YELLOW%^oranges%^BLUE%^.%^RESET%^",

        "%^BOLD%^%^WHITE%^This is a thick cream soup also known as a bisque that has been "
            "made with a shellfish called %^RESET%^Voratae%^BOLD%^ as well as chunks of "
            "%^RESET%^%^ORANGE%^potatoes%^BOLD%^%^WHITE%^, %^RESET%^%^GREEN%^onions%^BOLD%^%^WHITE%^, and other unidentifiable vegetables.%^RESET%^",

        "%^ORANGE%^This is a %^GREEN%^vegetable%^ORANGE%^ soup that has been made with fresh "
            "%^BOLD%^%^BLACK%^mushrooms%^RESET%^%^ORANGE%^ and %^RESET%^Corence%^ORANGE%^, a water plant somewhat like water "
            "chestnuts. The broth has been flavored with a few unknown "
            "%^GREEN%^herbs%^ORANGE%^ that blend together in a subtle way with the rest of "
            "the soup.%^RESET%^",
    }));
    set_my_mess(({
        "%^BOLD%^%^CYAN%^You drink a glass of crisp spring water that seems to restore "
            "your vitality instantly.%^RESET%^",

        "%^YELLOW%^The cool refreshing taste of the iced tea soothes your throat "
            "and your troubles.%^RESET%^",

        "%^YELLOW%^This is quite possibly the best tasting lemonade you have ever "
            "had, it is fresh and tastes like you are biting into a "
            "lemon picked straight from the %^RESET%^%^ORANGE%^tree%^BOLD%^.%^RESET%^",

        "%^GREEN%^The herbal tea goes down smooth and your entire body relaxes in "
            "euphoria.%^RESET%^",

        "%^BOLD%^%^RED%^You drink the feywine and feel an almost magical, %^WHITE%^blissful%^RED%^ "
            "peace wash over you as your skin starts to tingle all over. "
            "The glass almost slips from your hands as you hear a faerie "
            "%^MAGENTA%^giggling%^RED%^ in your ear. You set the glass down, letting the "
            "wine take full effect.%^RESET%^",

        "%^RED%^With each sip of the %^CYAN%^magicaly%^RED%^ distilled ruby colored drink you "
            "taste the full effect of a different fruit. As the smooth "
            "drink runs down your throat you almost feel like you are "
            "slipping from your body and becoming %^GREEN%^weightless%^RED%^.%^RESET%^",

        "%^ORANGE%^You bite into the %^MAGENTA%^elven%^ORANGE%^ waybread and enjoy the filling taste of "
            "fresh cooked bread. The %^BOLD%^%^BLACK%^crispness%^RESET%^%^ORANGE%^ of the outside and the "
            "%^RESET%^softness%^ORANGE%^ of the inside contrast %^CYAN%^perfectly%^ORANGE%^ and the flavor is "
            "simply delicious.%^RESET%^",

        "%^MAGENTA%^The %^BOLD%^%^RED%^cherries%^RESET%^%^MAGENTA%^, %^BLUE%^blueberries%^MAGENTA%^ and %^RED%^boysenberries%^MAGENTA%^ seem to almost "
            "%^BOLD%^%^WHITE%^blossom%^RESET%^%^MAGENTA%^ in your mouth as you bite into the %^ORANGE%^pie%^MAGENTA%^. The soft "
            "and flaky crust is somehow also perfectly %^BOLD%^%^BLACK%^crisp%^RESET%^%^MAGENTA%^ and melts "
            "in your mouth while being %^ORANGE%^crunchy%^MAGENTA%^ at the same time.%^RESET%^",

        "%^ORANGE%^The dula is %^BOLD%^%^BLACK%^crisp%^RESET%^%^ORANGE%^ on the outside and soft in the middle, you "
            "can taste a hint of %^GREEN%^rosemary%^ORANGE%^ as you eat it and it is very "
            "%^BOLD%^%^RED%^hot%^RESET%^%^ORANGE%^!%^RESET%^",

        "%^BOLD%^%^BLUE%^The subtle flavors of the %^RESET%^%^MAGENTA%^elven%^BOLD%^%^BLUE%^ fruits mixed with those of "
            "the more %^BLACK%^common%^BLUE%^ ones is simply amazing, the fresh %^WHITE%^whipped "
            "cream%^RESET%^%^BLUE%^ is just a bonus!%^RESET%^",

        "%^BOLD%^%^WHITE%^The %^RESET%^Vorartae%^BOLD%^ is suprisingly unsalty and very %^RESET%^%^ORANGE%^tender%^BOLD%^%^WHITE%^ unlike most "
            "shellfish. The chunks of %^RESET%^%^GREEN%^vegetables%^BOLD%^%^WHITE%^ have been cooked so "
            "perfectly that they just %^RESET%^%^CYAN%^melt%^BOLD%^%^WHITE%^ in your mouth when you try "
            "and eat them. As the bisque hits your stomach it warms "
            "your %^RED%^core%^WHITE%^ and radiates outward to your fingertips leaving "
            "you with a renewed feeling.%^RESET%^",

        "%^ORANGE%^The strong flavors of fresh %^BOLD%^%^BLACK%^mushrooms%^RESET%^%^ORANGE%^ and roasted %^RESET%^Corence%^ORANGE%^ blend "
            "together excellently with the subtle %^GREEN%^herbs%^ORANGE%^ used in the "
            "broth of the soup.%^RESET%^",
    }));
    set_your_mess(({
        "drinks a glass of forest water.",

        "enjoys glass of iced tea.",

        "puckers up after drinking the fresh lemonade.",

        "sighs softly after a cup of herbal tea.",

        "is overcome with an expression of peace and smiles softly.",

        "gets a distant look while enjoying the elverquisst.",

        "takes delight in the smell of the elven waybread before eating "
            "it all.",

        "scarfs down the entire slice of wild berry pie.",

        "carefully enjoys a plate of steaming hot fried dula.",

        "finishes a cup of mixed fruit and licks the whipped cream from "
            "the spoon.",

        "sighs exuberantly after eating the thick creamy bisque.",

        "slowly enjoys a bowl of vegetable soup.",
    }));
}

string long_desc(){
    return
        "%^BOLD%^%^BLACK%^Alirin is fairly tall for an %^RESET%^%^MAGENTA%^elf%^BOLD%^%^BLACK%^ and has the slim figure of a "
        "dancer. She has %^YELLOW%^golden blonde%^BLACK%^ hair that is worn loosely up in a "
        "bun on the back of her head. Dark kohl lines the lids of her "
        "almond shaped %^RESET%^%^ORANGE%^brown eyes%^BOLD%^%^BLACK%^, making them appear even larger than "
        "they already are and helping them to stand out from her %^RESET%^%^ORANGE%^olive "
        "skin%^BOLD%^%^BLACK%^. She has a small nose and full, pert lips with a flawless "
        "and %^YELLOW%^radiant%^BLACK%^ complexion. She is wearing a %^BLUE%^blue apron%^BLACK%^ over her "
        "simple %^RESET%^%^ORANGE%^tan dress%^BOLD%^%^BLACK%^ that reaches down to her ankles and she "
        "walks around barefoot.";
}
