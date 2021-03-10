#include <std.h>
#include "../area_stuff.h"

inherit ELDEBARO_MONSTER;
int lev;

void create() 
{
    object ob;
    ::create();
	set_race("storm giant");
    set_name("massive storm giant");
    set_id(({"giant", "storm giant", "massive storm giant", "eldebarocreature"}));
    
    set_short("%^BOLD%^%^BLACK%^A M%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^ss%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^"+
    "v%^BOLD%^%^WHITE%^e st%^BOLD%^%^BLACK%^o%^BOLD%^%^BLACK%^rm g%^BOLD%^%^WHITE%^ia%^BOLD%^%^BLACK%^nt%^RESET%^");
    
    set_long("%^BOLD%^%^CYAN%^This massive creature has deep %^RESET%^%^MAGENTA%^vi%^BOLD%^o%^RESET%^%^MAGENTA%^let "+
    "%^BOLD%^%^CYAN%^skin which is stretched tight over an enormous frame. His body ripples with muscles and almost seems to be giving "+
    "off a glow. He has very long and well kept thick %^RESET%^%^BLUE%^bluish%^BOLD%^%^CYAN%^ hair which flows freely "+
    "about his head and almost looks as if it is charged with static electricity constantly. He has very intelligence "+
    "%^RESET%^%^MAGENTA%^deep purple%^BOLD%^%^CYAN%^ eyes which also seem very angry. He carries a massive %^RESET%^%^BLUE%^"+
    "black bladed%^BOLD%^%^CYAN%^ sword which crackles with electricity frequently. He also carries a large %^BOLD%^%^BLACK%^ebon "+
    "%^BOLD%^%^CYAN%^tower shield. A deep %^BOLD%^%^BLACK%^darkness%^BOLD%^%^CYAN%^ hangs heavily over him.%^RESET%^");
    
    set_body_type("humanoid");
    set_size(4);
    lev = 40 + random(3);
    set_class("fighter");
    set_guild_level("fighter", lev);
    set_mlevel("fighter", lev);
    set_guild_level("mage", lev);
    set_mlevel("mage", lev);
    set_guild_level("cleric", lev);
    set_mlevel("cleric", lev);
    set_max_hp(lev * 65);
    set_hp(query_max_hp());
	set_new_exp(lev, "very high");
    set_stats("strength",27);
    set_stats("intelligence",26);
    set_stats("wisdom",6);
    set_stats("charisma",5);
    set_stats("constitution",24);
    set_stats("dexterity",4);
    set_alignment(9);
    set("aggressive",55);
    set_property("full attacks",1); 
    
    set_func_chance(25);
    
    set_funcs(({"electrify", "impale", "electrify", "impale", "electrify", "something_evil", "impale", "electrify", "impale"}));
    set_overall_ac(-27);
    
    set_spell_chance(35);
    set_monster_feats(({"impale", "sweepingblow", "unassailable parry", "reflection", "counter", "shieldbash", "perfect caster"}));
    
    set_spells(({"call lightning", "chain lightning"}));
    
    set_property("add kits",15);
    add_attack_bonus(10);
    set_resistance("electricity", 3500);
    add_damage_bonus(15);
    set_property("no paralyze", 1);
    set_property("no tripped", 1);
    set_property("no trip", 1);
    set_property("no death", 1);
    ob = new(ELOB+"stormbringer_armor");
    if(random(4)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wear armor");
    ob = new(ELOB+"ebon_reflector");
    if(random(4)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wear shield");
    ob = new(ELOB+"electrified_sword");
    if(random(10)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield sword");
}

void init()
{
    ::init();
    if(!objectp(TP)) return;
    if(TP->query_true_invis()) return;
    command("say %^BOLD%^%^BLACK%^ Asantra GUIDE my hand against this Intruder!%^RESET%^");
    command("impale "+TPQN);
    if(!random(4)){
        if(objectp(TO) && objectp(TP)) { TO->force_me("shieldbash "+TPQN); }
    }
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
    dam = roll_dice((bolts*10), 8);
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

void impale(object targ)
{
    string me, tlim;
    int dam;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    me = TO->query_short();
    tlim = targ->return_target_limb();
    dam = roll_dice(lev, 10);
    if(!random(30)) dam *= 2;
    if(targ->reflex_save(28))
    {
        tell_object(targ, me+"%^BOLD%^%^RED%^ slashes his massive sword into your "+tlim+" and you quickly "+
        "move out of the way, avoiding most of the damage!%^RESET%^");
        tell_room(ETO, me+"%^BOLD%^%^RED%^ slashes his massive sword into "+targ->QCN+"%^BOLD%^%^RED%^'s "+
        tlim+" and "+targ->QS+" manages to move out of the way, avoiding most of the damage!%^RESET%^", targ);
        targ->cause_typed_damage(targ, tlim, (dam/2), "slashing");
        return;
    }
    tell_object(targ, me+"%^BOLD%^%^GREEN%^ IMPALES%^BOLD%^%^RED%^ your "+tlim+" with his massive sword!%^RESET%^");
    
    tell_room(ETO, me+"%^BOLD%^%^GREEN%^ IMPALES%^BOLD%^%^RED%^ "+targ->QCN+"%^BOLD%^%^RED%^'s "+tlim+" with his "+
    "massive sword!%^RESET%^", targ);
    
    targ->cause_typed_damage(targ, tlim, dam, "slashing");
    return 1;    
}

int query_watched() { return random(101); }