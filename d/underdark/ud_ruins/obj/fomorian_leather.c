#include <std.h>

inherit "/d/common/obj/armour/leather";

void create() {
    ::create();
    set_name("fomorian armor");
    set_id(({"leather","fomorian leather","black leather","leather armor"
            "fomorian leather armor","armor",
    }));
    set_short(
        "%^BOLD%^%^BLACK%^F%^RESET%^%^MAGENTA%^o%^BOLD%^m%^BLACK%^o"
        "%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^a"
        "%^BOLD%^%^BLACK%^n "
        "L%^RESET%^%^MAGENTA%^e%^BOLD%^a%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^h"
        "%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^r "
        "A%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^m%^MAGENTA%^o%^BLACK%^r%^RESET%^"
    );
    set_obvious_short(
        "%^BOLD%^%^BLACK%^a l%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rge "
        "s%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^it of "
        "g%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^i%^MAGENTA%^m%^BLACK%^m"
        "%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ri%^RESET%^%^MAGENTA%^n"
        "%^BOLD%^%^BLACK%^g l%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^a%^MAGENTA%^t"
        "%^BLACK%^h%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^r%^RESET%^"
    );
    set_long(
        "%^BOLD%^%^BLACK%^This large suit of armor is made from a strange "
        "material that resembles leather, but colored black and with an odd "
        "%^RESET%^%^MAGENTA%^p%^WHITE%^u%^MAGENTA%^rple "
        "s%^WHITE%^p%^BOLD%^e%^RESET%^c%^MAGENTA%^ul%^WHITE%^a%^BOLD%^r"
        "%^RESET%^i%^MAGENTA%^ty %^BOLD%^%^BLACK%^that never seems to match up "
        "with the area's lighting. Whatever the material, it is cut at least "
        "five inches "
        "thick, and fashioned in such a way that the armor would likely deflect "
        "all but the most telling blows, provided one was large enough to put it "
        "on in the first place.%^RESET%^"
    );
    set_lore(
        "%^BOLD%^%^BLACK%^Though it is difficult to come across any direct "
        "evidence proving it, this armor seems to have been crafted by the "
        "%^CYAN%^Fomorians%^BLACK%^, the elusive giants said to dwell deep "
        "within the underdark. Legend has it that these giants originally made "
        "their home not on the Prime, but in the %^MAGENTA%^Feywild%^BLACK%^, "
        "where they ruled as one of the plane's most powerful races. However, a "
        "revolt amongst the other fey saw them cast from the Feywild, and they were "
        "forced into hiding on the Prime deep below the earth, their bodies "
        "forever twisted by the event. It seems the Fomorians are still quite "
        "capable of tapping into the feywild's energies, however, as this armor "
        "seems to hold a potent enchantment for any wearer who shares their "
        "blood.%^RESET%^"
    );
    set_wear((:TO, "wear_func":));
    set_size(3);
    set_remove((:TO, "remove_func":));
    set_struck((:TO, "struck_func":));
    set_value(3000);
    set_property("id difficulty", 20);
    set_property("lore difficulty", 25);
    set_property("no resize", 1);
    set_property("enchantment", 3+random(2));
    set_item_bonus("caster level", 1);
    set_item_bonus("sonic resistance percent", 10);
}

void reset_bonuses() {
    item_bonuses = ([
        "caster level" : 1,
        "sonic resistance percent" : 10,
        ]);
}

int is_giant(object player) {
    switch (player->query_race()) {
        case "ogre":
        case "ogre-mage":
        case "half-ogre":
        case "voadkyn":
        case "firbolg":
            return 1;
            break;
    }
    return 0;
}

void set_bonuses(object wearer) {
    reset_bonuses();
    if (is_giant(wearer)) {
        item_bonuses += ([
            "charisma" : (int)wearer->query_level() / 10,
            "sonic resistance percent" : 20,
            ]);
    }
}

int wear_func() {
    set_bonuses(ETO);
    if(is_giant(ETO)) {
        tell_object(ETO,
            "%^BOLD%^%^GREEN%^You feel a slight %^ORANGE%^twinge %^GREEN%^in "
            "your blood, and the armor begins to tingle against your skin as an "
            "invisible aura of "
            "c%^MAGENTA%^h%^GREEN%^a%^RESET%^%^RED%^o%^BOLD%^t%^MAGENTA%^i"
            "%^GREEN%^c "
            "e%^MAGENTA%^n%^GREEN%^er%^RED%^g%^RESET%^%^RED%^i%^BOLD%^%^MAGENTA%^"
            "e%^GREEN%^s springs up around you!"
        );
        tell_room(EETO,
            "%^BOLD%^%^GREEN%^As "+ETO->QCN+" fastens the strange black armor, a "
            "flurry of glimmering "
            "f%^RESET%^%^MAGENTA%^l%^BOLD%^u%^RESET%^%^MAGENTA%^o"
            "%^BOLD%^%^GREEN%^r%^ORANGE%^e%^RED%^s%^RESET%^%^MAGENTA%^c%^BOLD%^e"
            "%^RESET%^%^MAGENTA%^n%^BOLD%^%^GREEN%^t "
            "m%^ORANGE%^o%^RED%^t%^ORANGE%^e%^GREEN%^s flashes in and out of "
            "existence around "+ETO->QO+"! After they fade, "+ETO->QS+" somehow seems "
            "a good deal more %^WHITE%^imposing%^GREEN%^."
        ,({ETO}));
    }
    else {
        tell_object(ETO,
            "%^BOLD%^%^BLACK%^A strange feeling of %^GREEN%^vitality "
            "%^BLACK%^and %^RESET%^%^CYAN%^refreshment %^BOLD%^%^BLACK%^comes "
            "over you as you strap on the dark armor."
        );
        tell_room(EETO,
            "%^BOLD%^%^BLACK%^"+ETO->QCN+" straps on the dark armor and "+ETO->QP+
            "skin takes on a slightly %^GREEN%^healthier %^BLACK%^tone."
        ,({ETO}));
    }
    if(find_call_out("reset_bonuses") != -1) {
        remove_call_out("reset_bonuses");
    }
    return 1;
}

int remove_func() {
    if(is_giant(ETO)) {
        tell_object(ETO,
            "%^GREEN%^The glamoured magic surrounding you fades away as you "
            "remove the armor."
        );
        tell_room(EETO,
            "%^GREEN%^"+ETO->QCN+" seems to lose some of "+ETO->QP+" stature as" +ETO->QS+ "removes the armor."
        ,({ETO}));
    }
    else {
        tell_object(ETO,
            "%^BOLD%^%^BLACK%^You unfasten and remove the leather armor."
        );
        tell_room(EETO,
            "%^BOLD%^%^BLACK%^"+ETO->QCN+" unfastens and remove the leather armor."
        ,({ETO}));
    }
    call_out("reset_bonuses",1);
    return 1;
}

int struck_func(int damage, object what, object who) {
    // Deflect special for all wearers.
    // Giant-kin are healed by 1/3 the damage.
    if (!(random(1000) < 200)) { return 0; }
    tell_object(who,
        "%^MAGENTA%^"+ETO->QCN+"'s armor "
        "g%^BOLD%^l%^RESET%^%^MAGENTA%^i%^BOLD%^%^WHITE%^m%^MAGENTA%^m"
        "%^RESET%^%^MAGENTA%^e%^BOLD%^r%^RESET%^%^MAGENTA%^s a strange "
        "p%^BOLD%^u%^WHITE%^r%^RESET%^%^MAGENTA%^p%^BOLD%^l%^RESET%^%^MAGENTA%^e "
        "h%^BOLD%^u%^RESET%^%^MAGENTA%^e, and your blow is turned aside by "
        "some unseen force!"
    );
    tell_room(EETO,
        "%^MAGENTA%^"+ETO->QCN+"'s armor "
        "g%^BOLD%^l%^RESET%^%^MAGENTA%^i%^BOLD%^%^WHITE%^m%^MAGENTA%^m"
        "%^RESET%^%^MAGENTA%^e%^BOLD%^r%^RESET%^%^MAGENTA%^s a strange "
        "p%^BOLD%^u%^WHITE%^r%^RESET%^%^MAGENTA%^p%^BOLD%^l%^RESET%^%^MAGENTA%^e "
        "h%^BOLD%^u%^RESET%^%^MAGENTA%^e, and "+who->QCN+"'s blow is turned aside "
        "by some unseen force!"
    ,({ETO,who}));
    if(is_giant(ETO)) {
        tell_object(ETO,
            "%^BOLD%^%^MAGENTA%^A sudden surge of %^GREEN%^revitalizing "
            "%^MAGENTA%^energy pours out from your armor, turning "+who->QCN+"'s "
            "blow aside and soothing your wounds!"
        );
        ETO->add_hp(damage / 3);
        ETO->do_damage("head",0);
        return (damage*-1);
    }
    else {
        tell_object(ETO,
            "%^BOLD%^%^BLACK%^A strange %^MAGENTA%^energy %^BLACK%^springs up "
            "around you, turning "+who->QCN+"'s blow aside!"
        );
        return (damage*-1);
    }
}
