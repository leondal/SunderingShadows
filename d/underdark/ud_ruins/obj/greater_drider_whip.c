#include <std.h>

inherit "/d/common/obj/weapon/whip";

void create() {
    ::create();
    set_name("spiderlash");
    set_id(({"whip","lash","barbed whip","spiderlash"}));
    set_short(
        "%^BOLD%^%^BLACK%^S%^RED%^p%^BLACK%^i%^RESET%^%^RED%^d%^WHITE%^e"
        "%^BOLD%^%^BLACK%^r%^RESET%^l%^BOLD%^a%^RED%^s%^BLACK%^h%^RESET%^"
    );
    set_obvious_short(
        "%^RED%^a nasty-looking %^BOLD%^b%^BLACK%^a%^RED%^r%^BLACK%^b%^RED%^e"
        "%^BLACK%^d %^RED%^w%^BLACK%^h%^RED%^i%^BLACK%^p%^RESET%^"
    );
    set_long(
        "%^RED%^This weapon was clearly designed with %^BOLD%^pain "
        "%^RESET%^%^RED%^in mind. Its design is simple, made up of a length of "
        "%^BOLD%^%^WHITE%^b%^RESET%^r%^BOLD%^a%^RESET%^i%^BOLD%^d%^RESET%^e"
        "%^BOLD%^d "
        "s%^RESET%^p%^BOLD%^i%^RESET%^d%^BOLD%^e%^RESET%^r%^BOLD%^s%^RESET%^i"
        "%^BOLD%^lk %^RESET%^%^RED%^that is slightly acidic to the touch, with "
        "a handle made from a strange kind of r%^MAGENTA%^e%^RED%^d, "
        "r%^MAGENTA%^u%^RED%^b%^MAGENTA%^b%^RED%^e%^MAGENTA%^r%^RED%^y "
        "h%^MAGENTA%^i%^RED%^d%^MAGENTA%^e%^RED%^. The silken braid has "
        "%^WHITE%^fr%^ORANGE%^a%^WHITE%^yed %^RED%^and come undone in some "
        "places, but rather than mending the weapon, "
        "%^BOLD%^%^WHITE%^s%^RED%^h%^WHITE%^arp ba%^RED%^r%^WHITE%^bs "
        "%^RESET%^%^RED%^of %^BOLD%^%^WHITE%^b%^BLACK%^o%^WHITE%^ne "
        "%^RESET%^%^RED%^have been fixed to ends of the loose strands.%^WHITE%^"
    );
    set_lore(
        "%^BOLD%^%^BLACK%^Even amongst the drow, little is truly known about "
        "the fate of the driders following their curse of transformation. "
        "While many remain near to their former homes, dwelling in the shadows "
        "just outside of cities and waiting to take revenge on their former kin,"
        "others venture deeper into the underdark in search of a new purpose. "
        "What horrors and challenges these driders face, or what they must do to "
        "survive in the lowest reaches of the underdark, remains a tale that is "
        "only theirs to tell. Those that do return from the depths are rarely in "
        "the mood for storytelling, unfortunately.%^RESET%^"
    );
    set_property("lore difficulty",20);
    set_property("lore difficulty",25);
    set_property("enchantment",3+random(2));
    set_cointype("gold");
    set_value(3000);
    set_item_bonus("damage bonus", 2);
    set_item_bonus("attack bonus", 2);
    set_wield((:TO, "wield_func":));
    set_unwield((:TO, "unwield_func":));
    set_hit((:TO, "hit_func":));
}

int wield_func() {
    string msg;
    if((int)ETO->query_class_level("barbarian") < 11) {
        tell_object(ETO,
            "%^RED%^An unsettling %^BOLD%^wildness %^RESET%^%^RED%^seems to "
            "pulse through the whip's handle as you grip it."
        );
        tell_room(EETO,
            "%^RED%^"+ETO->QCN+" grips the %^WHITE%^silken %^RED%^whip, looking "
            "vaguely unsettled about something."
        ,({ETO}));
        item_bonuses = ([
                "attack bonus" : 2,
                "damage bonus" : 2,
            ]);
    }
    else {
        tell_object(ETO,
            "%^RED%^Gripping the whip's strange hide handle, you feel a twinge of "
            "%^BOLD%^primal bloodlust %^RESET%^%^RED%^surge through your veins."
        );
        tell_room(EETO,
            "%^RED%^"+ETO->QCN+" gets a strange look in "+ETO->QP+" eye as "
            +ETO->QS+ "grips the %^WHITE%^silken %^RED%^whip."
        ,({ETO}));
        item_bonuses = ([
                "attack bonus" : 2,
                "damage bonus" : 2,
                "will" : 2,
            ]);
    }
    return 1;
}

int unwield_func() {
    tell_object(ETO,
        "%^RED%^You release the whip, and a previously unfelt anxiety "
        "suddenly washes away."
    );
    tell_room(EETO,
        "%^RED%^"+ETO->QCN+" releases the whip, and suddenly looks a lot "
        "less menacing."
    ,({ETO}));
    return 1;
}

int hit_func(object target) {
    int special_chance;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    target = ETO->query_current_attacker();
    if(!objectp(target) || !objectp(ETO)) { return 1;}
    special_chance = ((int)ETO->query_class_level("barbarian") > 11) ? 300 : 200;
    if (random(1000) < special_chance) {
        object *enemies;
        int i,j;
        switch(random(11)) {
            case 0..3:
                tell_object(ETO,
                    "%^BOLD%^%^RED%^With a flick of the wrist, you rake "
                    +target->QCN+" with your whip's "
                    "%^WHITE%^s%^RESET%^h%^BOLD%^a%^RESET%^r%^BOLD%^p "
                    "sp%^RESET%^i%^BOLD%^k%^RESET%^e%^BOLD%^s%^RED%^! "
                    +target->QCN+" cries out in pain!"
                );
                tell_object(target,
                    "%^BOLD%^%^RED%^The %^WHITE%^s%^RESET%^h%^BOLD%^a%^RESET%^r"
                    "%^BOLD%^p b%^RESET%^a%^BOLD%^r%^RESET%^b%^BOLD%^s %^RED%^of "
                    +ETO->QCN+"'s whip dig into your skin, sending a wave of "
                    "%^ORANGE%^agony %^RED%^coursing through you!"
                );
                tell_room(EETO,
                    "%^BOLD%^%^RED%^"+target->QCN+" cries out in pain as the "
                    "%^WHITE%^s%^RESET%^h%^BOLD%^a%^RESET%^r%^BOLD%^p "
                    "b%^RESET%^a%^BOLD%^r%^RESET%^b%^BOLD%^s %^RED%^of "
                    +ETO->QCN+"'s whip dig into "+target->QP+" skin!"
                ,({ETO,target}));
                target->set_paralyzed(8,
                    "%^BOLD%^%^RED%^You are fighting off the wave of intense pain!"
                );
                break;
            case 4..7:
                tell_object(ETO,
                    "%^BOLD%^%^RED%^You lash your whip around in a wide arc, "
                    "raking all foes around you before delivering a blow upon "
                    +target->QCN+ " with a loud %^WHITE%^CRACK%^RED%^!"
                );
                tell_object(target,
                    "%^BOLD%^%^RED%^"+ETO->QCN+" lashes "+ETO->QP+" whip around in "
                    "a wide arc, raking all foes around "+ETO->QS+" before "
                    "delivering a blow upon you with a loud "
                    "%^WHITE%^CRACK%^RED%^!"
                );
                tell_room(EETO,
                    "%^BOLD%^%^RED%^"+ETO->QCN+" lashes "+ETO->QP+" whip around in "
                    "a wide arc, raking all foes around "+ETO->QS+" before "
                    "delivering a blow upon "+target->QCN+" with a loud "
                    "%^WHITE%^CRACK%^RED%^!"
                ,({ETO, target}));
                enemies = ETO->query_attackers();
                set_property("magic",1);
                j = sizeof(enemies);
                for(i=0;i<j;i++) {
                    if(!objectp(enemies[i])) { continue; }
                    if(enemies[i] == target) { continue; }
                    if(enemies[i] == ETO) { continue; }
                    tell_object(enemies[i],
                        "%^BOLD%^%^RED%^You are raked by the whip's sharp barbs!"
                    );
                    enemies[i]->do_damage(roll_dice(1,8));
                    remove_property("magic");
                }
                break;
            case 8..10:
                if((int)ETO->query_class_level("barbarian") >= 11
                  && ETO->query_property("raged")) {
                    int damage;
                    tell_object(ETO,
                        "%^BOLD%^%^RED%^Overcome with a sudden, "
                        "%^RESET%^%^GREEN%^sick %^BOLD%^%^RED%^impulse, you "
                        "lunge forward and %^ORANGE%^bite %^RED%^down into "
                        ""+target->QCN+"'s flesh! The whip in your hand seems to "
                        "%^RESET%^%^MAGENTA%^throb %^BOLD%^%^RED%^with approval "
                        "as you gulp down the essence of your foe."
                    );
                    tell_object(target,
                        "%^BOLD%^%^RED%^"+ETO->QCN+" gets a %^GREEN%^crazed "
                        "%^RED%^look in "+ETO->QP+" eye and snarls, just before "
                        "lunging at you! Dread and pain course through your "
                        "body in equal measures as "+ETO->QCN+" %^ORANGE%^bites "
                        "%^RED%^down into your flesh!"
                    );
                    tell_room(EETO,
                        "%^BOLD%^%^RED%^"+ETO->QCN+" gets a %^GREEN%^crazed "
                        "%^RED%^look in "+ETO->QP+" eye and snarls, just before "
                        "lunging at "+target->QCN+" and %^ORANGE%^biting "
                        "%^RED%^down into "+target->QP+" flesh!"
                    ,({ETO, target}));
                    damage =  roll_dice(((int)ETO->query_class_level("barbarian") / 7),6);
                    set_property("magic",1);
                    target->do_damage("head",damage);
                    remove_property("magic");
                    if(damage > 50) { damage = 50; }
                    ETO->add_hp(damage);
                }
                break;
        }
    }
    return 0;
}
