// planar_ally.c
#include <std.h>
inherit WEAPONLESS;

void do_create(int setlevel);
void do_customize(string setdeity);
int mydeity, mylevel;

void create()
{
    ::create();
    set_name("planar creature");
    set_id(({ "planar creature" }));
    set_short("planar creature");
    set_long("This is a creature from another plane.");
    set_hd(10, 8);
    set_max_hp(100);
    set_hp(100);
    set_exp(1);
    set_class("fighter");
    set_stats("strength", 12);
    set_stats("dexterity", 12);
    set_stats("constitution", 12);
    set_stats("intelligence", 12);
    set_stats("wisdom", 12);
    set_stats("charisma", 12);
    set_race("planar");
    set_alignment(5);
//    set_funcs(({"myspecial"}));
//    set_func_chance(10);
    set_damage(3, 4);
    set_gender("neuter");
    set_overall_ac(0);
    set_attacks_num(4);
}

int isMagic()
{
    return 3;
}

void do_create(int setlevel)
{
    int brackets;
    mylevel = setlevel;
    set_level(mylevel);
    set_mlevel("fighter", mylevel);
    set_guild_level("fighter", mylevel);
    set_hd(mylevel, 8);
    set_max_hp(mylevel * 8);
    set_hp(mylevel * 8);
    set_overall_ac(mylevel - 10);
    set_mob_magic_resistance("average");
    set_attacks_num(4);
}

void do_customize(string setdeity)
{
    if (!setdeity) {
        return;
    }
    mydeity = setdeity;

    switch (mydeity) {
    case "akadi":
        set_name("air elemental");
        set_id(({ "elemental", "air elemental", "whirling elemental", "whirling air elemental" }));
        set_short("whirling air elemental");
        set_long("This is an air elemental.");
        set_race("elemental");
        add_limb("torso", "torso", 50, 0, 2);
        add_limb("whirling winds", "torso", 50, 0, 2);
        set_attack_limbs(({ "whirling winds" }));
        set_base_damage_type("slashing");
        break;

    case "bane":
    case "loviatar":
        set_name("abishai");
        set_id(({ "abishai", "demon", "red abishai", "red-skinned abishai", "red skinned abishai" }));
        set_short("%^RESET%^%^RED%^red-skin%^BOLD%^n%^RESET%^%^RED%^ed abishai%^RESET%^");
        set_long("%^RESET%^%^RED%^This native of the nine hells bears closest resemblance to a gargoyle, the "
                 "fiendish %^BOLD%^%^BLACK%^stone guardians %^RESET%^%^RED%^of so many ancient buildings. Yet this one is quite "
                 "clearly alive, its scaled bat-like wings fanned to either side of its thin reptilian body. %^BOLD%^Crims"
                 "%^RESET%^%^RED%^o%^BOLD%^n scales %^RESET%^%^RED%^cover the creature from its blunt snout to the tip of its "
                 "prehensile tail. Its eyes %^BOLD%^%^BLACK%^gl%^RESET%^i%^BOLD%^t%^BLACK%^ter %^RESET%^%^RED%^with barely "
                 "restrained malice, as it opens its maw to display wickedly sharp %^BOLD%^%^WHITE%^fa%^RESET%^ng%^BOLD%^s"
                 "%^RESET%^%^RED%^.%^RESET%^");
        set_race("demon");
        set_alignment(3);
        set_body_type("dragon");
        set_attack_limbs(({ "right claw", "left claw", "mouth" }));
        set_base_damage_type("slashing");
        break;

    default: break;
    }
    set_stats("strength", 14);
    set_stats("dexterity", 14);
    set_stats("constitution", 14);
    set_stats("intelligence", 14);
    set_stats("wisdom", 14);
    set_stats("charisma", 14);
    set_attacks_num(4);
}
