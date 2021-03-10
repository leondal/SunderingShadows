#include <std.h>
#include <daemons.h>

inherit WEAPONLESS;

void create() {
    ::create();
    set_name("Hook Horror");
    set_id(({"hook horror","horror",}));
    set_short(
        "%^RESET%^"
        "%^BOLD%^%^BLACK%^a large h%^RESET%^o%^BOLD%^%^BLACK%^ok "
        "h%^RESET%^o%^BOLD%^%^BLACK%^r%^WHITE%^r%^RESET%^o%^BOLD%^%^BLACK%^r"
        "%^RESET%^"
    );
    set_long(
        "%^BOLD%^%^BLACK%^This bipedal creature is roughly nine feet tall, and "
        "resembles a cross between a %^RESET%^%^ORANGE%^vulture "
        "%^BOLD%^%^BLACK%^and a %^RESET%^%^CYAN%^beetle%^BOLD%^%^BLACK%^. Most "
        "of its body is covered in a thick %^RESET%^gray exoskeleton "
        "%^BOLD%^%^BLACK%^that looks like it would be difficult to pierce "
        "through. Rather than hands or paws, the creature's front limbs end in "
        "foot-long, "
        "s%^WHITE%^e%^BLACK%^r%^WHITE%^r%^BLACK%^a%^RESET%^t%^BOLD%^e%^BLACK%^d "
        "b%^WHITE%^l%^BLACK%^ad%^WHITE%^e%^BLACK%^s that taper to form two "
        "deadly-looking %^RESET%^%^CYAN%^hooks%^BOLD%^%^BLACK%^. It has two "
        "taloned feet, and a long pointed %^ORANGE%^beak %^BLACK%^to match."
        "%^RESET%^"
    );
    set_race("hook horror");
    set_body_type("human");
    set_hd(20,10);
    set_class("fighter");
    set_mlevel("fighter",20);
    set_guild_level("fighter",20);
    add_search_path("/cmds/fighter");
    set_all_stats(({18,14,14,1,14,10}));
    set_alignment(5);
    set_size(2);
    set_property("swarm",1);
    set_exp(4000);
    set_overall_ac(-5);
    set_max_hp(250+roll_dice(5,10));
    set_hp(query_max_hp());
    remove_limb("right hand");
    remove_limb("left hand");
    add_limb("beak","head",0,0,0);
    add_limb("right hook","right arm",0,0,0);
    add_limb("left hook","left arm",0,0,0);
    set_attack_limbs(({"right hook","left hook","beak"}));
    set_attacks_num(1);
    set_damage(2,6);
    set("aggressive",23);
}
