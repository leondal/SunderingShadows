#include <std.h>
#include "../defs.h"
inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("shadow mastiff");
    set_id(({ "mastiff", "shadow mastiff", "shadow", "monster", "dream mon" }));
    set_short("A shadow mastiff");
    set_long("%^BOLD%^%^BLACK%^A low growl rumbles out from the shadows as you " +
             "look towards this beast.  Just as you start to make " +
             "out the general shape of a very large, muscular dog, it " +
             "seems to simply fade into the shadows.  A snarl from " +
             "behind you lets you know he is still nearby.");
    set_race("canine");
    set_body_type("quadruped");
    set_gender("male");
    set_hd(20, 12);
    set_size(1);
    set("aggressive", 25);
    set_class("fighter");
    set_mlevel("fighter", 20);
    add_limb("mouth", "head", 0, 0, 0);
    add_limb("tail", "torso", 0, 0, 0);
    set_attack_limbs(({ "mouth" }));
    set_attacks_num(3);
    set_base_damage_type("piercing");
    set_damage(2, 4);
    set_hp(random(50) + 200);
    set_speed(30);
    set_nogo(({ ROOMDIR "pedestal" }));
    set_exp(4000);
    set_max_level(37);
    set_property("swarm", 1);
    set_overall_ac(1);
    set_alignment(5);
    set_emotes(10, ({
        "%^BOLD%^%^BLACK%^The dog growls menacingly from the darkness.",
        "%^BOLD%^%^BLACK%^The beast slips in and out of the shadows, darting all around you."
    }), 1);
    if (!random(15)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("dream fragment");
        ob->move(TO);
    }
}
