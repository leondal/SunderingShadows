#include <std.h>
#include "../area_stuff.h"

inherit ELDEBARO_MONSTER;

int lev;

int timer;

void create()
{
    object ob;
    ::create();
    set_name("raging storm elemental");
    set_id(({"elemental", "raging storm elemental", "storm elemental", "raging elemental", "eldebarocreature"}));
    
    set_short("%^RESET%^%^ORANGE%^A r%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^"+
    "i%^RESET%^%^ORANGE%^ng st%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^rm %^BOLD%^%^BLACK%^"+
    "e%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^m%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^"+
    "nt%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^l%^RESET%^");
    
    set_long("%^BOLD%^%^WHITE%^This bizarre and massive creature looks at first glance almost like "+
    "nothing more than a very dark st%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^rm cloud. However, you "+
    "quickly realize that it is something much worse. It is almost solid, but not quite. There are "+
    "large chunks of %^BOLD%^%^BLACK%^stone%^BOLD%^%^WHITE%^, clumps of %^RESET%^%^ORANGE%^wet sand%^BOLD%^"+
    "%^WHITE%^, and crackling bolts of %^BOLD%^%^CYAN%^electricity%^BOLD%^%^WHITE%^ all contained "+
    "within a %^BOLD%^%^BLACK%^dark%^BOLD%^%^WHITE%^ and %^BOLD%^%^RED%^raging%^BOLD%^%^WHITE%^ "+
    "nimbus. The creature looks almost intelligent and seems to be seething with an uncontrollable "+
    "%^BOLD%^%^RED%^rage%^BOLD%^%^WHITE%^.%^RESET%^");
      
    set_race("storm elemental");
    set_alignment(5);
    set_gender("neuter");
    set_body_type("human");
    set_class("fighter");
    lev = 32 + random(9);
    set_guild_level("fighter", lev);
    set_mlevel("fighter", lev);
    set_overall_ac(-20);
    set_size(4);
    
    set_property("damage resistance", 8);
    set_property("spell damage resistance", 75);
    
    set_max_hp(lev * 60);
    set_hp(query_max_hp());
    set("aggressive",66);

    set_attacks_num(6);
    set_property("full attacks", 1);
    set_base_damage_type("bludgeoning");
    set_damage(4,10);
    set_stats("strength",26);
    set_stats("dexterity",5);
    set_stats("constitution",28);
    set_stats("intelligence",5);
    set_stats("wisdom",4);
    set_stats("charisma",4);
    set_new_exp(lev, "very high");    
    
    add_attack_bonus(15);
    set_func_chance(50);
    set_funcs(({"electrify", "smash", "absorb", "something_evil", "absorb", "smash", "clump", "electrify", "smash", "electrify", "absorb"}));    
}

void absorb(object targ)
{
    int x;
    string me;
    object *vics;
    if(!objectp(targ)) return;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();
    vics = filter_array(TO->query_attackers(), "non_player_target", TO);
    
    if(!sizeof(vics)) return;
    x = random(sizeof(vics));
    while(x--)
    {
        if(x < 0) break;
        if(!objectp(vics[x])) continue;
        tell_room(ETO, vics[x]->QCN+ "%^BOLD%^%^GREEN%^ is suddenly sucked into "+me+" and absorbed by it!%^RESET%^");
        TO->set_max_hp((int)TO->query_max_hp() + (int)vics[x]->query_hp());
        TO->heal((int)vics[x]->query_hp());
        vics[x]->move("/d/shadowgate/void");
        if(objectp(vics[x])) vics[x]->remove();
        continue;
    }
    
}

void smash(object targ)
{
    string me;
    if(!objectp(targ)) return;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    
    me = TO->query_short();
    
    tell_object(targ, "%^BOLD%^%^WHITE%^A massive chunk of %^BOLD%^%^BLACK%^stone%^BOLD%^%^WHITE%^ from within "+
    me+"%^BOLD%^%^WHITE%^ flies out and smashes into you!%^RESET%^");
    
    tell_room(ETO, "%^BOLD%^%^WHITE%^A massive chunk of %^BOLD%^%^BLACK%^stone%^BOLD%^%^WHITE%^ from "+
    "within "+me+"%^BOLD%^%^WHITE%^ flies out and smashes into "+targ->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^", targ);
    
    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(12, 12) ,"bludgeoning");
    
    if(!random(3)) absorb(targ);
   
    return;
}

void clump(object targ)
{
    string me;
    if(!objectp(targ)) return;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();
    
    tell_object(targ, "%^RESET%^%^ORANGE%^A massive clump of wet sand flies out from "+me+"%^RESET%^%^ORANGE%^"+
    " and slams into you, pinning you to the ground!%^RESET%^");
    
    tell_room(ETO, "%^RESET%^%^ORANGE%^A massive clump of wet sand flies out from "+me+"%^RESET%^%^ORANGE%^"+
    " and slams into "+targ->QCN+"%^RESET%^%^ORANGE%^, pinning "+targ->QO+" to the ground!%^RESET%^", targ);
    
    targ->set_paralyzed(20, "%^RESET%^%^ORANGE%^You are pinned to the ground!%^RESET%^");
    
    if(!random(3)) absorb(targ);    
    
    return;    
}

void electrify(object targ)
{
    string me, bolt_string, tlim;
    int bolts, dam;
    if(!objectp(targ)) return;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();
    
    bolts = 2 + random(4);
    dam = roll_dice((bolts*10), 6);
    switch(bolts)
    {
        case 2: 
            bolt_string = "two";
            break;
        case 3:
            bolt_string = "three";
            break;
        case 4:
            bolt_string = "four";
            break;
        case 5:
            bolt_string = "five";
            break;
    }
    tlim = targ->return_target_limb();
    
    tell_object(targ, "%^BOLD%^%^CYAN%^"+capitalize(bolt_string)+"%^BOLD%^%^CYAN%^ bolts of electricity zap out "+
    "from "+me+"%^BOLD%^%^CYAN%^ and streak toward you!%^RESET%^");
    
    tell_room(ETO, "%^BOLD%^%^CYAN%^"+capitalize(bolt_string)+"%^BOLD%^%^CYAN%^ bolts of electricity zap out "+
    "from "+me+"%^BOLD%^%^CYAN%^ and streak toward "+targ->QCN+"%^BOLD%^%^CYAN%^!%^RESET%^", targ);
    
    if(!random(3)) absorb(targ);
    if(!objectp(targ)) return;
    if(targ->reflex_save(28))
    {
        tell_object(targ, "%^BOLD%^%^WHITE%^You duck out of the way just in time and your "+tlim+" is only partially "+
        "%^BOLD%^%^CYAN%^electrified%^BOLD%^%^WHITE%^ by the "+bolt_string+" bolts!%^RESET%^");
        
        tell_room(ETO, targ->QCN+"%^BOLD%^%^WHITE%^ ducks out of the way just in time and "+targ->QP+" "+tlim+" is only "+
        "partially %^BOLD%^%^CYAN%^electrificied by%^BOLD%^%^WHITE%^ the "+bolt_string+" bolts!%^RESET%^", targ);
        
        targ->cause_typed_damage(targ, tlim, (dam/2), "electricity");
        return;
    }
    
    tell_object(targ, "%^BOLD%^%^BLACK%^You are unable to move out of the way in time and your "+tlim+" is "+
    "%^BOLD%^%^CYAN%^ELECTRIFIED%^BOLD%^%^BLACK%^ by the "+bolt_string+" bolts!%^RESET%^");
    
    tell_room(ETO, targ->QCN+"%^BOLD%^%^BLACK%^ is unable to move out of the way in time and "+targ->QP+" "+tlim+
    " is %^BOLD%^%^CYAN%^ELECTRIFIED%^BOLD%^%^BLACK%^ by the "+bolt_string+" bolts!%^RESET%^", targ);
    
    targ->cause_typed_damage(targ, tlim, dam, "electricity");
    return;   
}

void die(object ob)
{
    object mat;
    if(!objectp(TO)) return ::die(ob);
    if(!objectp(ETO)) return ::die(ob);
    mat = new(ELOB+"heart_of_the_storm");    
    tell_room(ETO, TO->query_short() + " %^BOLD%^%^YELLOW%^erupts in a shower of sparks "+
    "and all that is left in its place is "+mat->query_short()+"!");
    mat->move(ETO);
    TO->move("/d/shadowgate/void");
    if(objectp(TO)) TO->remove();
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

int query_watched() { return random(101); }