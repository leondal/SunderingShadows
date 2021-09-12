#include <std.h>

inherit "/d/common/obj/weapon/sstaff";

void create() {
    ::create();
    set_name("mnizichalilian stalk");
    set_id(({"staff","mushroom staff","stalk","mushroom stalk",
            "mnizichalilian stalk"}));
    set_short(
        "%^RESET%^"
        "%^CYAN%^M%^BOLD%^%^BLACK%^n%^CYAN%^i%^BLACK%^z%^RESET%^%^CYAN%^i"
        "%^WHITE%^c%^CYAN%^h%^BOLD%^%^BLACK%^a%^CYAN%^l%^BLACK%^i"
        "%^RESET%^%^CYAN%^l%^WHITE%^i%^CYAN%^an "
        "S%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^l"
        "%^RESET%^%^CYAN%^k%^WHITE%^"
    );
    set_obvious_short(
        "%^RESET%^%^BOLD%^a "
        "%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^p%^RESET%^o%^BOLD%^n"
        "%^RESET%^%^CYAN%^g%^WHITE%^y "
        "%^BOLD%^m%^RESET%^u%^BOLD%^s%^CYAN%^h%^WHITE%^r%^RESET%^%^CYAN%^o"
        "%^BOLD%^o%^WHITE%^m s%^RESET%^t%^BOLD%^a%^CYAN%^l%^WHITE%^k%^RESET%^"
    );
    set_long(
        "%^BOLD%^This long mushroom stalk is a %^RESET%^pale white %^BOLD%^in "
        "color with scaly %^CYAN%^light blue "
        "%^WHITE%^r%^CYAN%^e%^WHITE%^t%^RESET%^i%^BOLD%^cul%^CYAN%^a%^WHITE%^t"
        "%^RESET%^i%^BOLD%^o%^CYAN%^n%^WHITE%^s running over its bumpy surface. "
        "It is light and spongy to the touch and quite flexible, able to bend "
        "from side to side without snapping or showing any signs of damage. A "
        "small w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e "
        "m%^RESET%^ush%^BOLD%^ro%^RESET%^o%^BOLD%^m c%^RESET%^a%^BOLD%^p sits "
        "upon one end of the stalk, wobbling slightly with every motion. Although "
        "it is clearly not connected to the ground, the stalk never seems to "
        "shrivel or lose its color.%^RESET%^"
    );
    set_lore(
        "%^CYAN%^The Mnizichalilian Spore is a breed of long-stalked fungus "
        "native to the lower underdark, where it can only grow in the presence "
        "of a specific type of faerzress-infused rock. Knowledge of its "
        "existence was first made commonly known by a deep gnome druid ("
        "identified only by a short nickname, Mnizichalil,), who began cultivating the "
        "fungus after noticing that its spores proved deadly when in contact with "
        "drow. In the centuries since, this fungus has often been found "
        "growing around deep gnome settlements, acting as a first defense "
        "against drowish raiding parties.%^WHITE%^"
    );
    set_wield((:TO, "wield_func":));
    set_unwield((:TO, "unwield_func":));
    set_hit((:TO, "hit_func":));
    set_value(3000);
    set_property("id difficulty", 25);
    set_property("lore difficulty", 25);
    set_property("no alter", 1);
    set_property("enchantment", 3+random(2));
    set_item_bonus("attack bonus", 2);
}

void reset_bonuses() {
    item_bonuses = (["attack" : 2]);
    if (query_property("added_castable")) {
        remove_property("added_castable");
        remove_property("able to cast");
    }
}

int wield_func() {
    reset_bonuses();
    if((string)ETO->query_race() == "drow") {
        tell_object(ETO,
            "%^CYAN%^The mushroom stalk "
            "%^BOLD%^%^RED%^b%^RESET%^%^ORANGE%^u%^BOLD%^%^RED%^r%^BLACK%^n"
            "%^RED%^s %^RESET%^%^CYAN%^you as you try to grasp it, and you "
            "double over in a coughing fit!"
        );
        tell_room(EETO,
            "%^CYAN%^The mushroom stalk "
            "%^BOLD%^%^RED%^b%^RESET%^%^ORANGE%^u%^BOLD%^%^RED%^r%^BLACK%^n"
            "%^RED%^s %^RESET%^%^CYAN%^"+ETO->QCN+" as "+ETO->QS+" tries to grasp it, "
            "and "+ETO->QS+" doubles over in a coughing fit!"
        ,({ETO}));
        ETO->do_damage("head",roll_dice(3,10));
        return 0;
    }
    else if (ETO->query_class_level("druid") > 11) {
        item_bonuses += ([
            "caster level" : 1,
            "bonus spell slots" : 1,
            ]);
        if (!query_property("able to cast")) {
            // This should allow the weapon to be oiled, while still being
            // naturally castable for druids. Still a slight issue if it's
            // oiled while being wielded by a druid, though
            set_property("added_castable",1);
            set_property("able to cast", 1);
        }
        tell_object(ETO,
            "%^CYAN%^Your druidic senses reveal a %^BOLD%^hidden power "
            "%^RESET%^%^CYAN%^within the mushroom stalk as you grasp it."
        );
    }
    else {
        tell_object(ETO,
            "%^CYAN%^The mushroom "
            "w%^BOLD%^o%^RESET%^%^CYAN%^b%^BOLD%^b%^RESET%^%^CYAN%^l%^BOLD%^e"
            "%^RESET%^%^CYAN%^s about in your hand as you grasp it."
        );
    }
    tell_room(EETO,
        "%^CYAN%^The mushroom "
        "w%^BOLD%^o%^RESET%^%^CYAN%^b%^BOLD%^b%^RESET%^%^CYAN%^l%^BOLD%^e"
        "%^RESET%^%^CYAN%^s about in "+ETO->QCN+"'s hand as "+ETO->QS+" grasps it."
    ,({ETO}));
    return 1;
}

int unwield_func() {
    if(query_property("added_castable")){
        remove_property("added_castable");
        remove_property("able to cast");
    }
    return 1;
}

int hit_func(object target) {
    int drow_bonus;
    drow_bonus = 0;
    if((string)target->query_race() == "drow") {
        // Just base the extra damage off of wielder level for now. Might change
        // this to have a poison-like effect later.
        drow_bonus = ETO->query_level();
        if(drow_bonus > 15) { drow_bonus = 15; }
    }
    if(random(1000) < 200) {
        switch(random(30)) {
            case 0..19 :
                tell_object(ETO,
                    "%^CYAN%^The mushroom stalk releases a small cloud of "
                    "%^BOLD%^s%^WHITE%^p%^CYAN%^or%^RESET%^e%^BOLD%^%^CYAN%^s "
                    "%^RESET%^%^CYAN%^as it connects with "+target->QCN+"!"
                );
                tell_room(EETO,
                    "%^CYAN%^The mushroom stalk releases a small cloud of "
                    "%^BOLD%^s%^WHITE%^p%^CYAN%^or%^RESET%^e%^BOLD%^%^CYAN%^s "
                    "%^RESET%^%^CYAN%^as "+ETO->QCN+"'s strike connects with "
                    +target->QCN+"!"
                ,({ETO,target}));
                tell_object(target,
                    "%^CYAN%^The mushroom stalk releases a small cloud of "
                    "%^BOLD%^s%^WHITE%^p%^CYAN%^or%^RESET%^e%^BOLD%^%^CYAN%^s "
                    "%^RESET%^%^CYAN%^as "+ETO->QCN+"'s strike connects with you!"
                );
                if(drow_bonus) {
                    tell_object(target,
                        "%^BOLD%^%^RED%^The spores burn as they come into "
                        "contact with you!"
                    );
                    tell_room(EETO,
                        "%^BOLD%^%^RED%^The spores seem to burn "+target->QCN+"!"
                    ,({target}));
                }
                set_property("magic",1);
                target->do_damage(roll_dice(1,10)+drow_bonus);
                remove_property("magic");
                break;
            case 20..29 :
                tell_object(ETO,
                    "%^BOLD%^%^CYAN%^The mushroom stalk "
                    "%^WHITE%^b%^RESET%^o%^BOLD%^u%^RESET%^n%^BOLD%^c%^RESET%^e"
                    "%^BOLD%^s %^CYAN%^off "+target->QCN+", then quickly springs "
                    "back for a second strike!"
                );
                tell_room(EETO,
                    "%^BOLD%^%^CYAN%^"+ETO->QCN+"'s mushroom stalk "
                    "%^WHITE%^b%^RESET%^o%^BOLD%^u%^RESET%^n%^BOLD%^c%^RESET%^e"
                    "%^BOLD%^s %^CYAN%^off "+target->QCN+", then quickly springs "
                    "back for a second strike!"
                ,({ETO,target}));
                tell_object(target,
                    "%^BOLD%^%^CYAN%^"+ETO->QCN+"'s mushroom stalk "
                    "%^WHITE%^b%^RESET%^o%^BOLD%^u%^RESET%^n%^BOLD%^c%^RESET%^e"
                    "%^BOLD%^s %^CYAN%^off of you, then quickly springs back "
                    "for a second strike!"
                );
                ETO->execute_attack();
                break;
        }
    }
    return 0;
}
