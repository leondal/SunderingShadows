#include <std.h>

inherit "/d/common/obj/weapon/scimitar";

int flourish_cooldown;

void create() {
    ::create();
    set_name("mistblade");
    set_id(({"saber","sabre","mistblade","mist blade","blade","sword"}));
    set_short(
        "%^BOLD%^%^CYAN%^M%^RESET%^i%^BOLD%^s%^CYAN%^t%^RESET%^b%^BOLD%^l"
        "%^CYAN%^a%^RESET%^d%^BOLD%^%^CYAN%^e%^RESET%^"
    );
    set_obvious_short(
        "%^RESET%^"
        "%^BOLD%^a g%^RESET%^le%^BOLD%^am%^RESET%^i%^BOLD%^%^CYAN%^n%^WHITE%^g "
        "%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^l%^CYAN%^u%^RESET%^i%^BOLD%^s"
        "%^RESET%^%^CYAN%^h-w%^BOLD%^h%^RESET%^i%^BOLD%^t%^RESET%^%^CYAN%^e "
        "%^BOLD%^%^WHITE%^s%^RESET%^a%^BOLD%^b%^CYAN%^r%^WHITE%^e%^RESET%^"
    );
    set_long(
        "%^CYAN%^This lightweight sabre is about two and a half feet long, with "
        "a curved, %^BOLD%^shimmering %^RESET%^%^CYAN%^blade making up most of "
        "its length. The blade is crafted from an unusual, %^WHITE%^bluish-white "
        "%^CYAN%^material that is not quite metal - slightly %^WHITE%^cool "
        "%^CYAN%^to the touch at all times and with a "
        "c%^GREEN%^o%^BOLD%^%^BLUE%^r%^GREEN%^r%^RESET%^%^CYAN%^u%^GREEN%^g"
        "%^BOLD%^%^BLUE%^a%^GREEN%^t%^RESET%^%^GREEN%^e%^CYAN%^d coloration "
        "like the o%^BOLD%^%^GREEN%^c%^BLUE%^e%^RESET%^%^GREEN%^a%^CYAN%^n's "
        "s%^GREEN%^u%^BOLD%^r%^BLUE%^f%^RESET%^%^GREEN%^a%^BOLD%^c"
        "%^RESET%^%^CYAN%^e. Its hilt is made of a %^WHITE%^lighter%^CYAN%^, "
        "%^BOLD%^%^WHITE%^sil%^CYAN%^v%^WHITE%^ery metal%^RESET%^%^CYAN%^, with "
        "%^WHITE%^r%^BOLD%^%^BLACK%^i%^WHITE%^d%^RESET%^g%^BOLD%^%^BLACK%^e"
        "%^RESET%^s %^CYAN%^cut into the metal to provide a steady grip, and "
        "with an elegant hand guard molded into the image of a %^BOLD%^cresting "
        "wave %^RESET%^%^CYAN%^sweeping over it.%^WHITE%^"
    );
    set_lore(
        "%^CYAN%^Created by the clergy of Istishia, the %^BOLD%^Mistblade "
        "%^RESET%^%^CYAN%^is a holy weapon most often found in use of the "
        "%^BOLD%^%^BLUE%^Water Queen's %^RESET%^%^CYAN%^rangers, although some "
        "warriors of %^BOLD%^%^WHITE%^Akadi %^RESET%^%^CYAN%^and "
        "%^WHITE%^Shaundakul %^CYAN%^have occasionally proven themselves attuned enough "
        "to the elements to tap into the weapon's magic. The sword's blade is "
        "similar to a water elemental in composition, made from saltwater "
        "enchanted to hold a small degree of awareness in relation to its "
        "wielder.%^WHITE%^"
    );
    set_property("lore difficulty",25);
    set_property("id difficulty",25);
    set_property("enchantment",3+random(2));
    set_cointype("gold");
    set_value(3000);
    set_item_bonus("damage bonus", 2);
    set_item_bonus("attack bonus", 2);
    set_item_bonus("cold resistance", 10);
    set_wield((:TO, "wield_func":));
    set_unwield((:TO, "unwield_func":));
    set_hit((:TO, "hit_func":));
    flourish_cooldown = 0;
    set_heart_beat(1);
}

void init() {
    ::init();
    add_action("conjure_func","flourish");
}

int is_valid_wielder(object wielder){
    string deity;
    int rlevel;
    if (!objectp(wielder)) { return 0;}
    rlevel = wielder->query_class_level("ranger");
    if (rlevel < 11) { return 0;}
    deity = wielder->query_diety();
    switch (deity) {
        case "ryorik" :
            return 1;
            break;
        case "nimnavanon" :
        case "callamir" :
            if (rlevel >= 21) {
                return 1;
            }
            break;
    }
    return 0;
}

int wield_func() {
    tell_object(ETO,
        "%^CYAN%^The sabre's center of balance "
        "r%^GREEN%^o%^BOLD%^c%^BLUE%^k%^RESET%^%^CYAN%^s back and forth "
        "before growing still, feeling like a small "
        "o%^BOLD%^c%^RESET%^%^GREEN%^e%^BOLD%^a%^RESET%^%^CYAN%^n in "
        "your hand. "

    );
    tell_room(EETO,
        "%^CYAN%^"+ETO->QCN+" takes up the bluish-white sabre."
    ,({ETO}));
    if (is_valid_wielder(ETO)) {
        tell_object(ETO,
            "%^BOLD%^%^CYAN%^The blade gives a sparkle of approval at your touch, "
            "yielding a more vivid "
            "%^BLUE%^o%^RESET%^%^GREEN%^c%^BOLD%^e%^BLUE%^a%^RESET%^%^GREEN%^n"
            "%^WHITE%^i%^BOLD%^%^BLUE%^c %^CYAN%^hue. A simple %^WHITE%^flourish "
            "%^CYAN%^is all it would take to show off the blade's color even "
            "further.%^RESET%^"
        );
    }
    return 1;
}

int unwield_func() {
    tell_object(ETO,
        "%^CYAN%^The sabre loses much of its balance as you unwield it."
    );
    tell_room(EETO,
        "%^CYAN%^"+ETO->QCN+" unwields the bluish-white sabre."
    ,({ETO}));
    return 1;
}

int hit_func(object target) {
    int special_chance;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    target = ETO->query_current_attacker();
    if(!objectp(target) || !objectp(ETO)) { return 1;}
    if (random(1000) < 200) {
        int rlevel, dmg;
        rlevel = ETO->query_class_level("ranger");
        switch(random(40)) {
            case 0..19 :
                tell_object(ETO,
                    "%^BOLD%^%^CYAN%^A light %^RESET%^mist %^BOLD%^%^CYAN%^rises "
                    "off of your blade as you give it a deft twirl, settling "
                    "over your skin and soothing your wounds!%^RESET%^"
                );
                tell_room(EETO,
                    "%^BOLD%^%^CYAN%^A light %^RESET%^mist %^BOLD%^%^CYAN%^rises "
                    "off of "+ETO->QCN+"'s blade as "+ETO->QS+" gives it a deft twirl! "
                    "It settles over "+ETO->QP+" body and seems to close "+ETO->QP+" "
                    "wounds!"
                ,({ETO}));
                dmg = roll_dice(1,8) + 2;
                if (is_valid_wielder(ETO)) {
                    // 1 extra HP per ranger level seems fair?
                    dmg += rlevel;
                    if (dmg > 40) { dmg = 40; }
                }
                set_property("magic",1);
                ETO->do_damage("torso",dmg * (-1));
                remove_property("magic");
                break;
            case 20..39 :
                tell_object(ETO,
                    "%^CYAN%^You follow up a strike with a single "
                    "%^BOLD%^%^WHITE%^slash %^RESET%^%^CYAN%^through the air! "
                    "A sharp blade of %^BOLD%^%^BLUE%^water %^RESET%^%^CYAN%^leaps "
                    "from your sabre and cuts into "+target->QCN+"!"
                );
                tell_object(target,
                    "%^CYAN%^"+ETO->QCN+" follows up a strike with a single "
                    "%^BOLD%^%^WHITE%^slash %^RESET%^%^CYAN%^through the air! A "
                    "sharp blade of %^BOLD%^%^BLUE%^water %^RESET%^%^CYAN%^leaps "
                    "from "+ETO->QP+" sabre and cuts into you!"
                    );
                tell_room(EETO,
                    "%^CYAN%^"+ETO->QCN+" follows up a strike with a single "
                    "%^BOLD%^%^WHITE%^slash %^RESET%^%^CYAN%^through the air! A "
                    "sharp blade of %^BOLD%^%^BLUE%^water %^RESET%^%^CYAN%^leaps "
                    "from "+ETO->QP+" sabre and cuts into "+target->QCN+"!"
                ,({ETO,target}));
                dmg = 1;
                if(is_valid_wielder(ETO)) {
                    int num;
                    num = ((rlevel / 7) > 1) ? rlevel / 7 : 1;
                    dmg = roll_dice(num, 4);
                }
                else {
                    dmg = roll_dice(1,4);
                }
                set_property("magic",1);
                target->cause_typed_damage(target,"torso",dmg,"slashing");
                remove_property("magic");
                break;
        }
    }
    return 0;
}

int conjure_func(string str) {
    int rlevel;
    if(!objectp(TO)) { return 0; }
    if (!is_valid_wielder(ETO)) {
        return 0;
    }
    if (!query_wielded()) { return 0; }
    if (flourish_cooldown) {
        tell_object(ETO,
            "%^CYAN%^The sabre seems to the lack enough energy for that."
        );
        return 1;
    }
    tell_object(ETO,
        "%^CYAN%^The blade "
        "g%^BOLD%^l%^GREEN%^i%^RESET%^%^CYAN%^t%^BOLD%^t%^RESET%^%^CYAN%^e"
        "%^BOLD%^%^GREEN%^r%^RESET%^%^CYAN%^s like the sea as you twirl it about "
        "in the air. It begins to exude a cool, refreshing "
        "%^BOLD%^mist%^RESET%^%^CYAN%^!"
    );
    tell_room(EETO,
        "%^CYAN%^"+ETO->QCN+" twirls his blade about in the air, and it "
        "g%^BOLD%^l%^GREEN%^i%^RESET%^%^CYAN%^t%^BOLD%^t%^RESET%^%^CYAN%^e"
        "%^BOLD%^%^GREEN%^r%^RESET%^%^CYAN%^s like the sea before exuding a "
        "cool, refreshing %^BOLD%^mist%^RESET%^%^CYAN%^!"
    ,({ETO}));
    rlevel = ETO->query_class_level("ranger");
    new("/cmds/spells/m/_mist_of_the_goddess")->use_spell(ETO,ETO,rlevel,1000, "cleric");
    flourish_cooldown = 60;
    return 1;

}

void heart_beat() {
    if(!objectp(TO)) { return; }
    if(!flourish_cooldown) { return; }
    if(flourish_cooldown < 0) { flourish_cooldown = 0; return; }
    flourish_cooldown--;
}
