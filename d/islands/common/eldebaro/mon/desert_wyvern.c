#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"

inherit ELDEBARO_MONSTER;
int lev;

void create(){
   ::create();
   set_name("desert wyvern");
   set_id(({"wyvern", "desert wyvern", "eldebarocreature"}));

   set_short("%^RESET%^%^ORANGE%^A d%^BOLD%^e%^RESET%^%^ORANGE%^s%^BOLD%^e"+
   "%^RESET%^%^ORANGE%^rt wyv%^BOLD%^e%^RESET%^%^ORANGE%^rn%^RESET%^");

   set_long("%^RESET%^%^ORANGE%^This monstrous dragon-like creature "+
   "towers above you. It stands nearly twenty feet tall, with two monstrous "+
   "and bony wings which span out more than twenty feet in each direction when they "+
   "are extended. It has a massive head, perhaps six feet in diameter, with huge "+
   "amber eyes which radiate with an amazing intellect. Its snout is pointed with nostrils "+
   "that flare widely and puffs of %^BOLD%^%^WHITE%^smoke%^RESET%^%^ORANGE%^ exit its "+
   "nostrils with each exhale. Its scales are thick and %^BOLD%^%^RED%^spiked%^RESET%^%^ORANGE%^ and "+
   "blend in so well with the sand that the creature itself is sometimes difficult to "+
   "make out. Its tail extends another ten feet or more behind it and you realize that the "+
   "end of its tail is composed of a massive ball of %^BOLD%^%^RED%^spikes%^RESET%^%^ORANGE%^ "+
   "which drip a %^BOLD%^%^GREEN%^foul%^RESET%^%^ORANGE%^ smelling liquid. A heavy "+
   "%^BOLD%^%^BLACK%^darkness%^RESET%^%^ORANGE%^ shrouds the entire creature.%^RESET%^");

   set_gender("male");
   set_race("wyvern");
   set_body_type("dragon");
   set_property("swarm",1);
   set_class("fighter");
   set_mlevel("fighter",44);
   set_guild_level("fighter", 44);
   set_overall_ac(-22);
   set_size(4);
   set_moving(1);
   set_speed(10);
   if(!random(2)) set_invis();
   set_stats("strength",22);
   set_stats("intelligence",25);
   set_stats("dexterity",15);
   set_stats("charisma",6);
   set_stats("wisdom",5);
   set("aggressive",55);
   set_alignment(5);
   set_hp(1800 + random(1200));
   set_new_exp(44, "high");
   set_nogo(({DOCKROOM}));
   set_funcs(({"fire", "flight", "tail", "flight", "fire", "tail", "something_evil", "flight", "fire", "tail", "flight", "fire", "tail"}));

   set_func_chance(50);
   set_attacks_num(5);
   set_damage(5,8);

   set_attack_limbs(({"left foreclaw","right foreclaw"}));
   add_money("gold",3500 + random(4500));
}

void tail(object targ)
{
    object *vics;
    int x, dam, hits;
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    vics = TO->query_attackers();
    if(!sizeof(vics)) return;
    me = TO->query_short();
    tell_room(ETO, me +"%^BOLD%^%^GREEN%^ swings its mighty tail at its attackers!%^RESET%^");
    hits = 0;
    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(vics[x])) continue;
        if(environment(vics[x]) != ETO) continue;
        hits++;
        if(hits > 3) break;
        if(vics[x]->reflex_save(30))
        {
            tell_object(vics[x], "%^BOLD%^%^WHITE%^You jump out of the way just in time as "+
            "the massive tail swings by you!%^RESET%^");
            tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^WHITE%^ jumps out of the way just in time "+
            "as the massive tail swings by "+vics[x]->QO+"!%^RESET%^", vics[x]);
            continue;
        }
        tell_object(vics[x], "%^BOLD%^%^BLACK%^You are unable to move out of the way and the "+
        "tails slams into you!%^RESET%^");

        tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^BLACK%^ is unable to move out of the way in time "+
        "and the massive tail slams into "+vics[x]->QO+"!%^RESET%^", vics[x]);
        vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), roll_dice(16, 12), "bludgeoning");
        POISON_D->ApplyPoison(vics[x], "/d/common/obj/poisons/base/wyvern_poison", TO, "injury");
        continue;
    }
    return;
}

void attack_with_vengence(object targ)
{
    object env;
    string me;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(!objectp(environment(targ))) return;
    if(strsrch(base_name(environment(targ)), "eldebaro") == -1)
    {
        TO->remove();
        return;
    }
    me = TO->query_short();
    env = environment(targ);
    if(!objectp(env)) return;
    tell_room(env, "%^RESET%^%^ORANGE%^You see the massive %^BOLD%^%^BLACK%^shadow%^RESET%^%^ORANGE%^"+
    " of "+me+" as it suddenly swoops down and viciously attacks "+targ->QCN+"%^RESET%^%^ORANGE%^ with "+
    "its claws!%^RESET%^", targ);

    tell_object(targ, "%^RESET%^%^ORANGE%^You see the massive %^BOLD%^%^BLACK%^shadow%^RESET%^%^ORANGE%^"+
    " of "+me+" as it suddenly sweeps down and viciously attacks you with its claws!%^RESET%^");

    TO->move(env);
    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(25,8), "slashing");
    return;
}


void flight(object targ)
{
    int x, dam;
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
    tell_object(targ, me+"%^BOLD%^%^RED%^ SHRIEKS loudly at you before taking taking flight!%^RESET%^");

    tell_room(ETO, me+"%^BOLD%^%^RED%^ SHRIEKS loudly at "+targ->QCN+"%^BOLD%^%^RED%^ before taking flight!%^RESET%^", targ);

    if(objectp(TO)) TO->move(WYVERNROOM);
    call_out("attack_with_vengence", 20, targ);
}

void fire(object targ)
{
    object *vics;
    int x, dam;
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    vics = TO->query_attackers();
    if(!sizeof(vics)) return;
    me = TO->query_short();

    tell_room(ETO, me +"%^BOLD%^%^RED%^ opens it's pointed snout and exhales a "+
    "billowing cloud of %^BOLD%^%^WHITE%^SMOKE%^BOLD%^%^RED%^ and %^RESET%^%^ORANGE%^"+
    "FIRE%^BOLD%^%^RED%^!%^RESET%^");

    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(vics[x])) continue;
        if(!interactive(vics[x])) dam = roll_dice(30,10);
        else dam = roll_dice(15,10);
        if(vics[x]->reflex_save(30))
        {
            tell_object(vics[x], "%^BOLD%^%^WHITE%^You manage to move out of the way "+
            "of the cloud of %^BOLD%^%^BLACK%^SMOKE%^BOLD%^%^WHITE%^ and %^BOLD%^%^RED%^"+
            "FIRE%^BOLD%^%^WHITE%^ and are only slightly burned by the flames!%^RESET%^");

            tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^WHITE%^ manages to move out of the way "+
            "of the cloud and is only slightly burned by the flames!%^RESET%^", vics[x]);

            vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), (dam/2), "fire");
            continue;
        }
        tell_object(vics[x], "%^BOLD%^%^BLACK%^You are %^BOLD%^%^RED%^ENGULFED%^BOLD%^%^BLACK%^"+
        " by the cloud of %^BOLD%^%^WHITE%^SMOKE%^BOLD%^%^BLACK%^ and %^BOLD%^%^RED%^FIRE"+
        "%^BOLD%^%^BLACK%^!!%^RESET%^");

        tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^BLACK%^ is %^BOLD%^%^RED%^ENGULFED%^BOLD%^%^BLACK%^"+
        " by the cloud of %^BOLD%^%^WHITE%^SMOKE%^BOLD%^%^BLACK%^ and %^BOLD%^%^RED%^FIRE"+
        "%^BOLD%^%^BLACK%^!!%^RESET%^", vics[x]);

        vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), (dam/2), "fire");

        if(!vics[x]->fort_save(20))
        {
            tell_object(vics[x], "%^BOLD%^%^CYAN%^You are blinded by the %^BOLD%^%^WHITE%^SMOKE"+
            "%^BOLD%^%^CYAN%^!%^RESET%^");
            vics[x]->set_temporary_blinded(3, "%^BOLD%^%^WHITE%^You have been blinded by the smoke!%^RESET%^");
        }
        continue;
    }
    return;
}

void init()
{
    if(!objectp(TO)) { return; }
    if(!objectp(TP)) { return; }

    ::init();
    if(TP->query_true_invis()) return;
    if(!userp(TP)) return;
    if(TP->query_invis())
    {
        tell_object(TP, TO->query_short()+" sees through your invisibility!");
    }
    command("kill "+TPQN);
}
