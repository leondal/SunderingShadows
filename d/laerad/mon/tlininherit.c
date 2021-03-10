//Updated description and mechanics - Octothorpe 11/10/09
//Coded by Bane//
// updated by *Styx* 12/20/03 to be moving and have all the common settings
//fixed by Circe to not attack true invis avatars 6/14/07

#include <std.h>
inherit WEAPONLESS;

void create()
{
    ::create();
    set_id(({ "tlincalli", "Tlincalli", "laeradmon","monstrous humanoid" }));
    set_name("tlincalli");
    set_short("%^RESET%^%^RED%^b%^BOLD%^i%^RESET%^%^RED%^z%^BOLD%^a" +
              "%^RESET%^%^RED%^rr%^BOLD%^e %^RESET%^%^RED%^tl%^BOLD%^i%^RESET%^" +
              "%^RED%^nc%^BOLD%^a%^RESET%^%^RED%^ll%^BOLD%^i%^");
    set_long("%^RED%^This horror appears to be part human and part " +
             "scorpion.  It has a bare, red-skinned human torso, supported " +
             "by a bony-plated insectoid body.  Bony plates completely " +
             "cover its eight legs making them appear skeletal.  The " +
             "protruding spine continues along the abdomen and extends " +
             "behind it to form a tail ten feet long tipped in a nasty " +
             "stinger.%^RESET%^");
    set_body_type("human");
    set_race("tlincalli");
    set_gender("male");
    set_alignment(6);
    set_size(3);
    set_max_level(22);
    set_hd(18, 23);
    set_hp(195 + random(100));
    set_attack_bonus(1);
    set_exp(12500);
    set_overall_ac(-10);
    set("aggressive", 21);
    set_property("swarm", 1);
    set_mob_magic_resistance("average");
    remove_limb("right leg");
    remove_limb("left leg");
    remove_limb("right foot");
    remove_limb("left foot");
    add_limb("abdomen", "torso", 0, 0, 0);
    add_limb("right foreleg", "abdomen", 0, 0, 0);
    add_limb("left foreleg", "abdomen", 0, 0, 0);
    add_limb("right middle leg", "abdomen", 0, 0, 0);
    add_limb("left middle leg", "abdomen", 0, 0, 0);
    add_limb("right rear leg", "abdomen", 0, 0, 0);
    add_limb("left rear leg", "abdomen", 0, 0, 0);
    add_limb("tail", "abdomen", 0, 0, 0);
    add_limb("stinger", "tail", 0, 0, 0);
    set_attack_limbs(({ "right hand", "left hand", "stinger" }));
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_damage(2, 4);
    set_hit_funcs((["stinger" : (: TO, "poison" :)]));
    set_stats("strength", 18);
    set_stats("dexterity", 18);
    set_stats("intelligence", 16);
    set_stats("wisdom", 12);
    set_stats("constitution", 12);
    set_stats("charisma", 12);
    set_property("add kits", 10);
    set_moving(1);
    set_speed(60);
    set_nogo(({ "/d/laerad/wasteland/waste1" }));
    force_me("message in crawls in.");
    force_me("message out crawls to the $D%^RESET%^.");
}

int poison(object targ)
{
    if (!"/daemon/saving_throw_d.c"->fort_save(targ, -14)) {
        tell_object(targ, "%^BOLD%^RED%^The tlincalli's poison burns " +
                    "in your veins like fire!");
        tell_room(ETO, "%^BOLD%^RED%^The tlincalli's sting causes " +
                  "" + targ->QCN + " to scream out in pain!", targ);
        targ->add_poisoning(10);
        targ->do_damage("torso", roll_dice(10, 5));
        return 1;
    }
}
