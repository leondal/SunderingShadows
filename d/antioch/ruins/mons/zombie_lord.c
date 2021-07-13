#include <std.h>
#include "../ruins.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("zombie lord");
    set_short("A horrifying zombie lord");
    set_id(({ "zombie", "zombie lord", "horrifying zombie", "horrifying zombie lord", "lord", "monster" }));
    set_long(
        "This is a simply terrifying monster that stands before you. His skin is" +
        " grey and rotted in places, and his entire body gives off a terrible" +
        " stench of death and decay. Wiry black hair trails in patches from his" +
        " skull, yellow eyes stare at you in hunger. His teeth are more like" +
        " fangs, sharpened to allow him to eat the flesh of the dead easier. Some" +
        " clothing hangs from his body still, mostly covered in blood and other" +
        " vile substances that you'd rather not think about. He is quite large," +
        " however, and looks like a formidable opponent."
        );
    set_gender("male");
    set_race("zombie");
    set_body_type("humanoid");
    set_property("undead", 1);
    set_hd(20, 10);
    set_max_hp(170 + random(60));
    set_hp(query_max_hp());
    set_alignment(6);
    set_overall_ac(-8);
    set_class("fighter");
    set_mlevel("fighter", 25);
    set_level(25);
    set_stats("dexterity", 1);
    set_stats("charisma", 1);
    set_max_level(25);
    set_exp(6500);
    set_stats("strength", 20);
    set_property("swarm", 1);
    set("aggressive", 25);
    set_attack_limbs(({ "right hand", "left hand" }));
    set_attacks_num(3);
    set_damage(1, 10);
    set_mob_magic_resistance("average");
    set_funcs(({ "stench" }));
    set_func_chance(40);
    set_resistance("negative energy", 10);
    set_resistance("positive energy", -10);
}

void stench(object targ)
{
    int i, j;
    object* inven;
    inven = all_living(ETO);
    j = sizeof(inven);

    for (i = 0; i < j; i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i] == TO) {
            continue;
        }
    if (!"/daemon/saving_d"->fort_save(targ, -20)) {
            tell_object(inven[i], "%^BOLD%^%^GREEN%^The sickly stench of the" +
                        " zombie lord causes you to become nauseaus and gag!");
            inven[i]->set_paralyzed(roll_dice(1, 4), "You can't stop yourself from vomiting!");
        }else {
            tell_object(inven[i], "You can barely manage to withstand the stench" +
                        " of the zombie lord and continue fighting.");
        }
    }
}
