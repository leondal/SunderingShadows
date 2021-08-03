#include <std.h>

inherit "/d/common/obj/clothing/robe";

void create() {
    ::create();
    set_name("pugilist robe");
    set_id(({"robe","monk robe","pugilst's robe","cloth robe","brown robe"}));
    set_short(
        "%^RESET%^%^ORANGE%^Pugilist's Robe%^WHITE%^"
    );
    set_obvious_short(
        "%^BOLD%^%^BLACK%^a plain %^RESET%^%^ORANGE%^cloth %^BOLD%^%^BLACK%^robe%^RESET%^"
    );
    set_long(
        "%^ORANGE%^This plain-looking robe is sewn together from brown cloth, "
        "and bears no embroidery or embellishments to suggest that it was made "
        "for anyone of particularly important status or rank. However, it looks "
        "to be quite durable, and has been tailored in such a way that it would "
        "afford a wide range of movement to whoever wears it.%^WHITE%^"
    );
    set_lore(
        "%^ORANGE%^The simple design makes it difficult to know where this robe"
        "originally came from, but it most likely originated at one of the "
        "martial arts dojos around the realm. Worn repeatedly over years of rigorous "
        "practice, robes like this one have taken on a unique property that "
        "allow them to resonate with the natural ki of the wearer, reinforcing "
        "their innate physical strengths. As ki can be found in any living "
        "being, the robe might resonate with anyone of sufficient physical "
        "prowess. However, whatever process creates these robes is a delicate "
        "one, and tampering too much with it is said to unravel its magic."
    );
    set_wear((:TO, "wear_func":));
    set_size(2);
    set_remove((:TO, "remove_func":));
    set_value(3000);
    set_property("id difficulty", 20);
    set_property("lore difficulty", 25);
    set_property("no alter", 1); // <- No! The robe is brown and boring, and
                                 //    it will STAY that way!
    set_property("enchantment", 4);
    set_item_bonus("attack bonus", 2);
}

void reset_bonus() {
    item_bonuses = ([
        "attack bonus" : 2
        ]);
}

string get_bonus(string *classes) {
    string *res;
    int i,j;
    res = ({});
    j = sizeof(classes);
    for(i=0;i<j;i++) {
        switch (classes[i]) {
            case "fighter":
            case "paladin":
            case "cavalier":
                res += ({"strength"});
                break;
            case "thief":
            case "ranger":
            case "bard":
                res += ({"dexterity"});
                break;
            case "psywarrior":
            case "barbarian":
            case "warlock":
                res += ({"constitution"});
                break;
            case "monk":
                switch(ETO->query("monk way")) {
                    case "way of the fist" :
                        res += ({"strength"});
                        break;
                    case "way of the shadow" :
                        res += ({"dexterity"});
                        break;
                    case "way of the elements" :
                        res += ({"constitution"});
                        break;
                    default :
                        res += ({"constitution"});
                        break;
                }
                break;
        }
    }
    // Bonus priority : constitution > dexterity > strength
    if (member_array("constitution",res)) {
        return "constitution";
    }
    else if(member_array("dexterity",res)) {
        return "dexterity";
    }
    else if(member_array("strength",res)) {
        return "strength";
    }
    return 0;
}

int wear_func() {
    string bonus;
    reset_bonus();
    if(bonus = get_bonus((string*)ETO->query_classes())) {
        item_bonuses[bonus] = 2;
        tell_object(ETO,
            "%^ORANGE%^A marked feeling of self-worth overcomes you as you don "
            "the plain brown robe. You feel the results of your past training "
            "imbuing you with newfound power."
        );
    }
    else {
        tell_object(ETO,
            "%^ORANGE%^The robe feels slightly loose on you."
        );
    }
    tell_room(EETO,
        "%^ORANGE%^"+ETO->QCN+ "%^RESET%^%^ORANGE%^dons the plain brown robe."
    ,({ETO}));
    return 1;
}

int remove_func() {
    tell_object(ETO,
        "%^ORANGE%^You pull the plain brown robe off."
    );
    tell_room(EETO,
        "%^ORANGE%^"+ETO->QCN+" %^RESET%^%^ORANGE%^pulls the plain brown robe off."
    ,({ETO}));
    return 1;
}
