/* Similar problem to other dragons found a few months ago - had to move body type above limb settings and made second and third heads connect to torso instead of themselves
   I also noticed the special wasn't working either - had to change the name of the function to match what the create called.
   Styx 11/23/01
 */

#include <std.h>
inherit WEAPONLESS;
void create()
{
    ::create();
    set_name("aramanthae hydra");
    set_id(({ "aramanthae dragon", "dragon", "hydra" }));
    set_short("Aramanthae Hydra");
    set_long("
     %^CYAN%^The Aramanthae Hydra is a massive oceanic dragon with multiple heads and powerful jaws.  It towers above you, its scaly hide glistening in the sunlight.
");
    set_race("hydra");
    set_hd(23, 10);
    set_level(50);
    set_size(5);
    set_overall_ac(-12);
    set_class("fighter");
    set_guild_level("fighter", 30);
    set_body_type("dragon");
    set_max_hp(410);
    set_hp(410);
    remove_limb("left wing");
    remove_limb("right wing");
    add_limb("second head", "torso", 96, 1, 4);
    add_limb("third head", "torso", 96, 1, 4);
    set_attacks_num(8);
    set_attack_limbs(({ "second head", "tail", "third head", "head" }));
    set_base_damage_type("bludgeoning");
    set_funcs(({ "blast" }));
    set_func_chance(35);
    set_damage(2, 8);
    set_property("swarm", 1);
    set_property("magic", 1);
    set_property("no bump", 1);
    set_stats("strength", 19);
    set_stats("dexterity", 16);
    set_stats("constitution", 17);
    set("aggressive", "aggfunc");
    set_mob_magic_resistance("average");
    set_exp(30000);
    set_alignment(5);
}

void die(object ob)
{
    message("environment",
            "%^CYAN%^Aramanthe hydra shrieks horribly.\n" "%^BOLD%^The Hydra collapses ito the water with a tremendous splash!\n" "%^CYAN%^An enormous wave strikes you!\n"
            , environment(TO));
    :: die(ob);
}

int aggfunc()
{
    TP->kill_ob(TO, 0);
    force_me("emote rises from the water before you.                                                               %^BOLD%^%^CYAN%^An enormous wave strikes you!");
}

void blast(object targ)
{
    string dam;
    if ("daemon/saving_d"->saving_throw(targ, "spell", -7)) {
        dam = "wounding";
    } else {
        dam = "massive";
    }
    tell_object(targ,
                "%^BOLD%^%^RED%^Aramanthae hydra blasts you with a wave of crimson flame.\n" "%^RESET%^%^BOLD%^A gush of steam rises off the water."
                );
    tell_room(environment(targ),
              "%^BOLD%^%^RED%^Aramanthae hydra blasts " + targ->query_cap_name() + " with a wave of crimson flame.\n" "%^RESET%^%^BOLD%^A gush of steam rises off the water."
              , targ);
    if (dam == "massive") {
        targ->do_damage("torso", roll_dice(3, 15));
    } else {
        tell_object(targ,
                    "You quickly dive beneath the water and avoid much of the flame."
                    );
        tell_room(environment(targ),
                  "" + targ->query_cap_name() + " dives beneath the water and avoids much of the flame."
                  , targ);
        targ->do_damage("torso", roll_dice(1, 6));
    }
    return 1;
}

void init()
{
    ::init();
    if (userp(TP) && !TP->query_true_invis()) {
        TP->set_disabled(30);
        return;
    }
    if ((string)TP->query_body_type() == "snake") {
        TP->die();
    }
}
