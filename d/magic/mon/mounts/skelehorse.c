#include <std.h>

inherit "/std/riding_animal";

void create() {
    ::create();
    set_name("a skeletal horse");
    set_id(({ "skeleton","skeletal horse","skelehorse","undead","horse" }));
    set_short("%^BOLD%^%^BLACK%^s%^WHITE%^k%^BLACK%^e%^WHITE%^l%^BLACK%^e%^WHITE%^t%^BLACK%^a%^WHITE%^l %^BLACK%^h%^WHITE%^o%^BLACK%^r%^WHITE%^s%^BLACK%^e%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Before you stands an undead creature, an equine skeleton. Its bones float in fell aura forming resemblance of an animal being, %^RED%^its eyes glow red with graft of undeath's hatred towards the life.");
    set_level(10);
    set_value(0);
    set_race("horse");
    set_property("undead", 1);
    set_gender("male");
    set_body_type("equine");
    set_size(3);
    set_max_hp(100);
    set_hd(10, 1);
    set_hp(100);
    set_overall_ac(3);
    set_exp(1);
    set_max_distance(500);
    set_enter_room("rides in on a skeletal horse.");
    set_exit_room("leaves riding a skeletal horse.");
    set_vehicle_short("%^BOLD%^%^BLACK%^s%^WHITE%^k%^BLACK%^e%^WHITE%^l%^BLACK%^e%^WHITE%^t%^BLACK%^a%^WHITE%^l %^BLACK%^h%^WHITE%^o%^BLACK%^r%^WHITE%^s%^BLACK%^e%^RESET%^");
}

int enter(string str) {
    /*int lev, temp;
    if (query_owner() != this_player()) {
        tell_room(ETP, "" + TPQCN + " seems unable to mount the spectral horse!", TP);
        return notify_fail("The horse is too insubstancial to mount!\n");
    }

    set_level(lev * 1 / 3);
    set_mlevel("fighter", lev * 1 / 3);
    set_max_hp(temp * 1 / 3);
    set_damage(2, 6);
    set_hp(query_max_hp());*/
    return ::enter(str);
    return 1;
}

int handle_critter(string str) {
    tell_room(ETP, "The skelehorse seems uninterested in " + TPQCN + "'s attempts to handle it.", TP);
    return notify_fail("%^RESET%^%^BOLD%^%^BLACK%^THE SKELEHORSE IGNORES %^WHITE%^YOUR %^WHITE%^PATHETIC%^BLACK%^ ATTEMPTS TO HANDLE IT!%^RESET%^\n");
}

int give_me_away(string str) {
    return notify_fail("%^RESET%^%^BOLD%^%^BLACK%^THIS PATHETIC IS %^WHITE%^NOT %^WHITE%^WORTHY%^BLACK%^ TO CONTROL YOUR SERVANTS!%^RESET%^\n");
    return 0;
}

int save_me(string file) {
    return 0;
}

int restore_me(string file) {
    TO->remove();
    return 0;
}
