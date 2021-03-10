#include <std.h>

inherit "/d/common/obj/lrweapon/shortbow";

void create() {
    ::create();
    set_name("kuo-toa shortbow");
    set_id(({"shortbow","composite bow","composite shortbow","bow","short bow"}));
    set_short(
        "%^RESET%^"
        "%^BOLD%^K%^CYAN%^u%^WHITE%^o-t%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^a "
        "S%^RESET%^%^CYAN%^h%^BOLD%^%^WHITE%^o%^CYAN%^r%^WHITE%^tb"
        "%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^w%^RESET%^"
    );
    set_obvious_short(
        "%^RESET%^a %^BOLD%^p%^RESET%^o%^BOLD%^lished %^RESET%^composite shortbow"
    );
    set_long(
        "%^BOLD%^This composite shortbow is made of some unidentified "
        "w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e "
        "s%^RESET%^i%^BOLD%^n%^RESET%^e%^BOLD%^w, and bears a decidedly "
        "utilitarian design, with no more embellishments or decorations than "
        "necessary. Despite it's small size, the design of the shortbow seems "
        "like it would lend quite a lot of force to its arrows, although it "
        "would take some practice to use it effectively."
    );
    set_lore(
        "%^BOLD%^In Kuo-toa culture, great value is placed on martial prowess, "
        "such that outsiders have come to fear Kuo-toa warriors as the "
        "underdark's most powerful martial artists. However, with the underdark "
        "being what it is, there are always occasions where approaching a foe "
        "to strike directly may be considered (amongst other things) unwise. "
        "For these occasions, many Kuo-toa have grown adept at using these "
        "shortbows to keep their enemies at a distance. Made from sinews "
        "harvested from deep-dwelling sea creatures, the Kuo-toa are said to be "
        "especially deadly while wielding these in watery environments."
    );
    // Set to use longbow's damage and weapon prof, to make it more useful for
    // small races with the archery tree.
    set_weapon_prof("martial");
    set_wc(1,8);
    set_large_wc(1,8);
    set_wield((:TO, "wield_func":));
    set_unwield((:TO, "unwield_func":));
    set_lrhit((:TO, "extra_lrhit":));
    set_value(3000);
    set_property("id difficulty", 25);
    set_property("lore difficulty", 20);
    set_property("enchantment", 4);
    set_item_bonus("attack bonus", 2);
    set_item_bonus("damage bonus", 2);
}

int wield_func() {
    tell_object(ETO,
        "%^BOLD%^You take up and string the sinewy shortbow. It is slightly "
        "%^CYAN%^cool %^WHITE%^and %^RESET%^%^CYAN%^clammy %^BOLD%^%^WHITE%^to "
        "the touch."
    );
    tell_room(EETO,
        "%^BOLD%^"+ETO->QCN+" takes up and strings the sinewy shortbow."
    ,({ETO}));
    return 1;
}


int unwield_func() {
    tell_object(ETO,
        "%^BOLD%^You set aside the shortbow."
    );
    tell_room(EETO,
        "%^BOLD%^"+ETO->QCN+" sets aside the shortbow."
    ,({ETO}));
    return 1;
}

int extra_lrhit(object target) {
    int special_chance;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    // Double the special chance if fighting in/near water.
    special_chance = (TERRAIN_GROUPS[EETO->query_terrain()] == 8) ? 400 : 200;
    if(random(1000) < special_chance) {
        switch(random(60)) {
            case 0..29 :
                tell_object(ETO,
                    "%^BOLD%^You adeptly notch a second arrow to rest against the "
                    "shortbow's %^RESET%^sinewy string %^BOLD%^before you fire, and "
                    "watch as both shots soar toward "+target->QCN+"!"
                );
                tell_room(EETO,
                    "%^BOLD%^"+ETO->QCN+" adeptly notches a second arrow against "
                    +ETO->QP+" bowstring before loosing two shots at once!"
                ,({ETO}));
                ETO->execute_attack();
                break;
            case 30..59 :
                tell_object(ETO,
                    "%^BOLD%^Your shortbow %^RESET%^trembles %^BOLD%^as you "
                    "notch your next arrow, and you find it surprisingly easy "
                    "to draw the string back further than usual. Your shot "
                    "flies with double the force toward "+target->QCN+"!"
                );
                tell_object(target,
                    "%^BOLD%^"+ETO->QCN+" suddenly looses a surprisingly powerful "
                    "shot at you!"
                );
                tell_room(EETO,
                    "%^BOLD%^"+ETO->QCN+" suddenly looses a surprisingly powerful "
                    "shot at "+target->QCN+"!"
                ,({ETO,target}));
                set_property("magic",1);
                target->cause_typed_damage(target,"torso",random(8)+1,"piercing");
                remove_property("magic");
                break;
        }
    }
    return 0;
}
