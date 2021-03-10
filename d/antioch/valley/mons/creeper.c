//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("yellow musk creeper");
    set_id(({ "yellow musk creeper", "creeper", "plant", "monster", "musk creeper", "yellow creeper", "yellow musk" }));
    set_short("A %^YELLOW%^yellow%^RED%^ musk creeper");
    set_long(
        "This is a lovely and rather exotic light green plant. It is adorned with" +
        " numerous flowers that look like orchids, they're a" +
        " %^YELLOW%^brilliant yellow%^RESET%^%^CYAN%^ shade with splashes of" +
        " %^MAGENTA%^purple%^CYAN%^. There are a couple of" +
        " %^GREEN%^dark green%^CYAN%^ buds nestled in ivy like leaves." +
        " The plant takes up a sizable area, approximately twenty" +
        " square feet. It is strange to find such a beautiful plant" +
        " in a dark forest like this."
        );
    set_gender("neuter");
    set_race("plant");
    set_body_type("snake");
    set_hd(15, 6);
    set_max_level(25);
    set_size(3);
    set_alignment(5);
    set_overall_ac(3);
    set_property("no dominate", 1);
    set_property("no bows", 1);
    set_property("no rush", 1);
    set_property("magic", 1);
// removing this while fixing bugs since it autos everything *Styx*  5/14/06
//	set_property("alignment adjustment",2);
    set_max_hp(random(50) + 310);
    set_hp(query_max_hp());
    set_level(18);
    set_class("fighter");
    set_mlevel("fighter", 15);
    set_class("mage");
    set_mlevel("mage", 25);
    set_property("swarm", 1);
    add_limb("bulb", "torso", 0, 0, 0);
    add_limb("aerial roots", "bulb", 0, 0, 0);
    add_limb("roots", "bulb", 0, 0, 0);
//	set_exp(20000);
    set_new_exp(18, "high");
    add_limb("flower 1", "bulb", 0, 0, 0);
    add_limb("flower 2", "bulb", 0, 0, 0);
    add_limb("flower 3", "bulb", 0, 0, 0);
    add_limb("flower 4", "bulb", 0, 0, 0);
    add_limb("flower 5", "bulb", 0, 0, 0);
    add_limb("flower 6", "bulb", 0, 0, 0);
    add_limb("flower 7", "bulb", 0, 0, 0);
    add_limb("flower 8", "bulb", 0, 0, 0);
    set_attack_limbs(({ "flower 1", "flower 2", "flower 3", "flower 4", "flower 5", "flower 6", "flower 7", "flower 8" }));
    set_attacks_num(6);
    set_base_damage_type("slashing");
    set_damage(1, 4);
    set_hit_funcs(([
                       "flower 1" : (: TO, "puff" :),
                       "flower 2" : (: TO, "puff" :),
                       "flower 3" : (: TO, "puff" :),
                       "flower 4" : (: TO, "puff" :),
                       "flower 5" : (: TO, "puff" :),
                       "flower 6" : (: TO, "puff" :),
                       "flower 7" : (: TO, "puff" :),
                       "flower 8" : (: TO, "puff" :)
                   ]));
    set("aggressive", 25);
    set_mob_magic_resistance("high");
}

void init()
{
    ::init();
    if (TP->query_invis() && !avatarp(TP)) {
        write("The creeper seems to sense you with its creeping tendrils, and reaches out for you!");
        TO->force_me("kill " + TP->query_name() + "");
        return 1;
    }
}

int query_watched()
{
    return 1000000;
}

int puff(object targ)
{
    tell_object(targ, "The flower releases a puff of musk smelling" +
                " dust in your face.");
    tell_room(ETO, "The flower releases a puff of dust into" +
              " " + targ->query_cap_name() + "'s face.", targ);
    if (!"/daemon/saving_throw_d.c"->fort_save(targ, -14)) {
        tell_object(targ, "%^GREEN%^You become entranced and walk" +
                    " into the mass of the plant.");
        tell_room(ETO, "%^GREEN%^" + targ->query_cap_name() + " becomes" +
                  " entranced and walks into the mass of the plant.", targ);
// shortening the paralyze to be more reasonable so it's not a certain death *Styx*
        targ->set_paralyzed(10, "You are entranced by the plant!");
        targ->cease_all_attacks();
        remove_attacker(targ);
// does it also need a targ->remove_attacker(TO)  ???? *Styx* 5/14/06
        call_out("suck_int", 4, targ);
    }
}

void suck_int(object targ)
{
    int sint, chp;
// adding check for valid object due to bugs  *Styx*  11/20/03, last change 3/13/01
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!present(targ)) {
        return;
    }
//added by Circe 1/19/04 so people wouldn't die long after they left the creeper
    sint = random(2) + 1;
    chp = targ->query_max_hp();

    tell_object(targ, "Aerial roots descend and attach themselves to" +
                " your skull, sucking away your brain.");
    targ->add_stat_bonus("intelligence", -sint);
    if (targ->query_stats("intelligence") < 0) {
        tell_object(targ, "The yellow musk creeper has sucked away" +
                    " the last of your brain and discards your dead body.");
        targ->set_hp(-1);
        targ->add_attacker(TO);
        targ->continue_attack();
        targ->set_paralyzed(0, "You should be released from entrancement!");
        targ->remove_attacker(TO);   // adding to be sure it ends *Styx* 5/14/06
        if (!objectp(targ)) {
            return;
        }
//		targ->set_hp(chp);  // no idea why this was here but it might have been making bugs on death too.
    }else {
        call_out("suck_int", 8, targ);
    }
}

void die(object ob)
{
/*   switch(random(320)) {
        case 0..50:
            add_money("gold",random(4000));
            new(OBJ+"orchid")->move(TO);
            break;
        case 51..99:
            new(OBJ+"c_weapon")->move(TO);
            break;
        case 100..149:
            new(OBJ+"sun_shield")->move(TO);
            new(OBJ+"orchid")->move(TO);
            break;
        case 150..199:
            new(OBJ+"orchid")->move(TO);
            new(OBJ+"evisor")->move(TO);
            break;
        case 200..220:
            new(OBJ+"sunblade")->move(TO);
            break;
        case 221..240:
            new(OBJ+"ice_cutlass")->move(TO);
            break;
        case 241..260:
            new(OBJ+"tempus_sword")->move(TO);
            break;
        case 261..280:
            new(OBJ+"gauntlets")->move(TO);
            break;
   // fixed this from being 320, outside the switch *Styx* 11/20/03
            case 281..319:
                new(OBJ+"axe")->move(TO);
                break;
 */
    switch (random(4)) {
    case 0:
        add_money("gold", random(4000));
        new(OBJ + "orchid")->move(TO);
        break;

    case 1:
        new(OBJ + "gauntlets")->move(TO);
        new(OBJ + "orchid")->move(TO);
        break;

    case 2:
        new(OBJ + "sun_shield")->move(TO);
        new(OBJ + "orchid")->move(TO);
        break;

    case 3:
        new(OBJ + "orchid")->move(TO);
        new(OBJ + "evisor")->move(TO);
        break;
    }
    switch (random(4)) {
    case 0:
        new(OBJ + "sunblade")->move(TO);
        break;

    case 1:
        new(OBJ + "ice_cutlass")->move(TO);
        break;

    case 2:
        new(OBJ + "tempus_sword")->move(TO);
        break;

    case 3:
        new(OBJ + "axe")->move(TO);
        break;
    }
    ::die(ob);
}
