//Coded by Bane//
#include <std.h>
inherit WEAPONLESS;
int anum, hitd, hitp, lleg, rleg, face, larm, rarm, qhp;
object* alimbs;
object ob;
void create()
{
    ::create();
    set_id(({ "wall", "living wall", "living" }));
    set_name("living wall");
    set_short("A living wall");
    set_long(
        "This is perhaps the most disgusting thing you have ever had the misfortune " +
        "of seeing.  A massive block of flesh and bone, arms and legs protrude from " +
        "the wall in many places.  The surface of the wall is alive with movement, " +
        "the faces of former victims cringe in horror and scream in eternal misery.  " +
        "The sound of hundreds of souls screaming is enough to drive nearly any man insane."
        );
    set_body_type("human");
    set_size(3);
    set_race("construct");
    set_gender("neuter");
    hitd = 14;
    set_hd(hitd, 2);
    hitp = 168;
    set_max_hp(hitp);
    set_hp(query_max_hp());
    set_class("fighter");
    set_mlevel("fighter", query_hd());
    set_guild_level("fighter", query_hd());
    set_overall_ac(-7);
    set_attack_bonus(1);
    set_property("no dominate", 1);
    set_property("no death", 1);
    set_mob_magic_resistance("average");
    remove_limb("head");
    add_limb("face1", "torso", 0, 0, 0);
    add_limb("face2", "torso", 0, 0, 0);
    add_limb("face3", "torso", 0, 0, 0);
    add_limb("face4", "torso", 0, 0, 0);
    add_limb("right arm2", "torso", 0, 0, 0);
    add_limb("right arm3", "torso", 0, 0, 0);
    add_limb("right arm4", "torso", 0, 0, 0);
    add_limb("right hand2", "right arm2", 0, 0, 0);
    add_limb("right hand3", "right arm3", 0, 0, 0);
    add_limb("right hand4", "right arm4", 0, 0, 0);
    add_limb("left arm2", "torso", 0, 0, 0);
    add_limb("left arm3", "torso", 0, 0, 0);
    add_limb("left hand2", "left arm2", 0, 0, 0);
    add_limb("left hand3", "left arm3", 0, 0, 0);
    add_limb("left leg2", "torso", 0, 0, 0);
    add_limb("left foot2", "left leg2", 0, 0, 0);
    add_limb("right leg2", "torso", 0, 0, 0);
    add_limb("right leg3", "torso", 0, 0, 0);
    add_limb("right foot2", "right leg2", 0, 0, 0);
    add_limb("right foot3", "right leg3", 0, 0, 0);
    face = 4;
    lleg = 2;
    rleg = 3;
    larm = 3;
    rarm = 4;
    anum = 4;
    set_attack_limbs(({ "right hand", "right hand2", "right hand3", "right hand4", "left hand", "left hand2", "left hand3", "left foot", "left foot2", "right foot", "right foot2", "right foot3" }));
    alimbs = (string*)TO->query_attack_limbs();
    set_base_damage_type("bludgeoning");
    set_attacks_num(anum);
    set_damage(1, 6);
    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("living stone");
    ob->move(TO);
}

void init()
{
    ::init();
    if (wizardp(TP)) {
        return 1;
    }
    if ((string)TP->query_name() == "hansoth") {
        return 1;
    }
    TO->kill_ob(TP, 1);
}

void heart_beat()
{
    object corpse;
    ::heart_beat();
    if (!objectp(TO)) {
        return 1;
    }
    if (objectp(TO) && objectp(ETO) && present("corpse", ETO)) {
        corpse = present("corpse", ETO);
        tell_room(ETO, "The corpse gets up and walks into the wall, merging with it.");
        corpse->remove();
        qhp = TO->query_hp();
        hitd += 2;
        set_hd(hitd, 2);
        hitp += random(10) + 10;
        set_max_hp(hitp);
        set_hp(qhp + random(10) + 10);
        set_stats("strength", 21);
        lleg += 1;
        rleg += 1;
        face += 1;
        larm += 1;
        rarm += 1;
        add_limb("right arm" + rarm, "torso", 0, 0, 0);
        add_limb("right hand" + rarm, "right arm" + rarm, 0, 0, 0);
        add_limb("left arm" + larm, "torso", 0, 0, 0);
        add_limb("left hand" + larm, "left arm" + larm, 0, 0, 0);
        add_limb("right leg" + rleg, "torso", 0, 0, 0);
        add_limb("right foot" + rleg, "right leg" + rleg, 0, 0, 0);
        add_limb("left leg" + lleg, "torso", 0, 0, 0);
        add_limb("left foot" + lleg, "left leg" + lleg, 0, 0, 0);
        add_limb("face" + face, "torso", 0, 0, 0);
        alimbs += ({ "right hand" + rarm, "left hand" + larm, "right foot" + rleg, "left foot" + lleg });
        set_attack_limbs(alimbs);
        set_mlevel("fighter", query_hd());
        set_guild_level("fighter", query_hd());
        if (anum < 8) {
            anum += 1;
        }
        set_attacks_num(anum);
    }
    if (query_hp() < query_max_hp()) {
        if (objectp(TO)) {
            TO->add_hp(1);
        }
    }
}
