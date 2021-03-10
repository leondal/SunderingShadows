//Bumping up to 75k, since they can be sorta dangerous, and don't spawn that often - Octothorpe 6/8/09
//Dropped xp from 150k to 15k - Octothorpe 6/6/09
//Added set_max_level to retard cycling - Octothorpe 6/4/09
//updated by Circe with new desc 6/13/04
#include <std.h>
#include <daemons.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

object caught;
int blah;

void create()
{
    ::create();
    set_name("gargantua");
    set_id(({ "gargantua", "Gargantua", "Reptilian Gargantua", "reptilian gargantua" }));
    set_short("Reptilian Gargantua");
    set_long(
        "Dwarfing the jungle around it, this massive reptilian " +
        "creature stands over 150 feet tall.  Even its massive " +
        "legs seem wider than the tree trunks around them.  The " +
        "creature is bipedal, and its hands end in long, reptilian " +
        "claws.  Its skin is the color of mottled granite, and it " +
        "is covered in rough, rocky scales.  A series of tall " +
        "ridges runs down the creature's spine, covering all the " +
        "way to the tip of its tail.  Its elongated face features " +
        "a narrow mouth filled with razor-sharp teeth, above which " +
        "peer cold, glittering eyes.  When the gargantua moves, " +
        "it seems the whole jungle shakes in response."
        );
    set_hd(50, 1);
    set_hp(roll_dice(query_hd(), 15));
    set_exp(75000);
    set_max_level(25);
    set_overall_ac(-7);
    set_body_type("dragon");
    remove_limb("right wing");
    remove_limb("left wing");
    set_attack_limbs(({ "jaws", "right foreclaw", "left foreclaw" }));
    set_hit_funcs((["jaws" : (: TO, "biting" :)]));
    set_damage(3, 10);
    set_attacks_num(3);
    set_alignment(5);
    set_gender("male");
    set_race("reptile");
    add_money("silver", random(5000));
    set_base_damage_type("slashing");
    set_funcs(({ "trample" }));
    set_func_chance(5);
    set_property("no death", 1);
    set_mob_magic_resistance("average");
    set_property("no knockdown", 1);   //that just looks stupid
    set_speed(50);
    set_new_exp(35, "boss");
    set_resistance("electricity", 10);
}

int biting(object targ)
{
    return roll_dice(3, 10);
}

int trample(object targ)
{
    if (!objectp(targ)) {
        return 1;
    }
    tell_object(targ, "%^BOLD%^%^RED%^The gargantua runs toward you, destroying everything in its path!");
    tell_room(ETO, "%^BOLD%^%^RED%^The gargantua runs toward " + targ->query_cap_name() + ", destroying everything in its path!", targ);
    tell_object(targ, "%^BOLD%^%^RED%^The gargantua tramples you to the ground!");
    tell_room(ETO, "%^BOLD%^%^RED%^The gargantua tramples " + targ->query_cap_name() + " to the ground!", targ);
    targ->do_damage("torso", roll_dice(10, 10));
    return 1;
}

void sweep()
{
    int i;
    object* targs;
    targs = all_living(ETO);
    targs -= ({ TO });
    targs = filter_array(targs, "is_non_immortal", FILTERS_D);
    tell_room(ETO, "%^BOLD%^%^RED%^The gargantua sweeps its tail along the ground!");
    for (i = 0; i < sizeof(targs); i++) {
        if (!objectp(targs[i])) {
            continue;
        }
        if (random(2)) {
            if (SAVING_D->saving_throw(targs[i], "paralyzation_poison_death", 0)) {
                tell_object(targs[i], "%^BOLD%^%^RED%^The gargantua's sweeping tail knocks you to the ground!");
                tell_room(ETO, "%^BOLD%^%^RED%^The gargantua's sweeping tail knocks " + targs[i]->query_cap_name() + " to the ground!", targs[i]);
                targs[i]->add_attacker(TO);
                targs[i]->do_damage("torso", roll_dice(8, 10));
                targs[i]->continue_attack();
                continue;
            }
        }
    }
}

void heart_beat()
{
    if (!objectp(TO)) {
        return;
    }
    if (blah > 4) {
        blah = 0;
        if (query_attackers() == ({}) && query_hp() != query_max_hp()) {
            if (query_hp() + 4 <= query_max_hp()) {
                add_hp(4);
            }else {
                set_hp(query_max_hp());
            }
        }
        sweep();
    }
    blah++;
    ::heart_beat();
}

void die(mixed ob)
{
    switch (random(4)) {
    case 0..1:  break;

    case 2:  new(OBJ + "scale")->move(TO);
        break;

    case 3:  new(OBJ + "scalehelm")->move(TO);
        break;

    default: break;
    }
    ::die(ob);
}
