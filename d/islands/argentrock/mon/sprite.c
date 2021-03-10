//Mob for the Thinblade of Vines -- Yves
#include <std.h>
inherit WEAPONLESS;

void create(){
     ::create();
    set_name("sprite");
    setenv("MIN", "$N flies in.");
    setenv("MOUT", "$N flies off to the $D.");
    set_id(({
        "sprite",
        "fairy",
        "fey"
    }));
    set_short("%^BOLD%^%^GREEN%^Sprite%^RESET%^");
    set_long((:TO,"long_desc":));
    set_hd(35,5);
    set_max_hp(25);
    set_hp(25);
    set_gender("female");
    set_race("sprite");
    set_body_type("human");
    set_overall_ac(0);
    set_size(1);
    set_exp(1);
    set_property("magic",1);
    set_mob_magic_resistance("very high");
    set_attacks_num(1);
    set_damage(3,3);
    set_attack_limbs(({"torso"}));
    set_base_damage_type("slashing");
    set_property("knock unconscious",1);
}

string long_desc(){
    return
        "%^BOLD%^%^GREEN%^This sprite is a tiny winged fey creature dressed in greens and "
        "%^RESET%^%^ORANGE%^browns%^BOLD%^%^GREEN%^ to help her blend in with her forest home. Her small "
        "irridescent wings %^WHITE%^sparkle%^GREEN%^ and let off pixie dust as she "
        "flutters and moves about.%^RESET%^";
}
