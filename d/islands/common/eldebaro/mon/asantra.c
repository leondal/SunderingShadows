#include <std.h>
#include "../area_stuff.h"

inherit MONSTER;
int lev, summoning;
void impale(object targ);

void create() 
{
    object ob;
    ::create();
	set_race("storm giant");
    set_name("asantra queen of the storm giants");
    set_id(({"giant", "storm giant", "asantra", "massive storm giant", "queen", "eldebarocreature"}));
    
    set_short("%^RESET%^%^MAGENTA%^As%^BOLD%^a%^RESET%^%^MAGENTA%^ntra, Q%^BOLD%^u%^RESET%^%^MAGENTA%^"+
    "een of the %^BOLD%^%^BLACK%^St%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm G%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^"+
    "ants%^RESET%^");
    
    set_long("%^BOLD%^%^CYAN%^This massive female storm giant has deep %^RESET%^%^MAGENTA%^vi%^BOLD%^o%^RESET%^%^MAGENTA%^let "+
    "%^BOLD%^%^CYAN%^skin which is covered with strange symbols. Her eyes are a very %^RESET%^%^MAGENTA%^deep purple%^BOLD%^"+
    "%^CYAN%^ which seem immensely intelligent and seeth with an unmistakable rage. She has very long and "+
    "thick %^RESET%^%^BLUE%^bluish%^BOLD%^%^CYAN%^ hair which crackles with electricity constantly causing it to frizz "+
    "around her head wildly. Her body is muscular and very well toned, as if she has spent a lot of time training to "+
    "remain ready for physical combat. Scrawled into the flesh of her torso, right above her breasts, is the word "+
    "'%^BOLD%^%^BLACK%^Freeholm%^BOLD%^%^CYAN%^' and it looks as if it has been there for a very long time. She "+
    "carries a massive %^RESET%^%^BLUE%^blue%^BOLD%^%^CYAN%^ spear which crackles with electricity frequently and "+
    "an %^BOLD%^%^BLACK%^ebon %^BOLD%^%^CYAN%^round shield.%^RESET%^");
    
    set_gender("female");
    set_body_type("humanoid");
    set_size(4);
    lev = 60;
    set_class("fighter");
    set_guild_level("fighter", lev);
    set_mlevel("fighter", lev);
    set_guild_level("mage", lev);
    set_mlevel("mage", lev);
    set_guild_level("cleric", lev);
    set_mlevel("cleric", lev);
    set_max_hp(lev * (200+random(55)));
    set_hp(query_max_hp());
	set_new_exp(lev, "boss");
    set_stats("strength",30);
    set_stats("intelligence",26);
    set_stats("wisdom",6);
    set_stats("charisma",5);
    set_stats("constitution",24);
    set_stats("dexterity",4);
    set_alignment(9);
    set("aggressive",55);
    set_property("full attacks",1); 
    
    set_func_chance(25);
    
    set_funcs(({"electrify", "impale", "electrify", "impale", "electrify", "impale", "electrify", "impale", "companions"}));
    set_overall_ac(-30);
    
    set_spell_chance(35);
    set_monster_feats(({"impale", "sweepingblow", "unassailable parry", "reflection", "counter", "shieldbash", "perfect caster"}));
    
    set_spells(({"call lightning", "chain lightning"}));
    
    set_property("add kits",50);
    add_attack_bonus(10);
    set_resistance("electricity", 3500);
    add_damage_bonus(15);
    set_property("no paralyze", 1);
    set_property("no tripped", 1);
    set_property("no trip", 1);
    set_property("no death", 1);
    ob = new(ELOB+"ebon_reflector");
    ob->move(TO);
    command("wear shield");
    ob = new(ELOB+"charged_skewer");
    ob->move(TO);
    command("wield spear");
}

void init()
{
    ::init();
    if(!objectp(TP)) return;
    if(TP->query_true_invis()) return;
    command("say %^BOLD%^%^BLACK%^ You WILL NEVER see the inside of Castle Freeholm!! My KING WILL BE protected!%^RESET%^");
    impale(TP);
    command("kill "+TP->query_name());
    if(!random(4)){
        if(objectp(TO) && objectp(TP)) { TO->force_me("shieldbash "+TPQN); }
    }
}

void electrify(object targ)
{
    string me, bolt_string, tlim;
    int bolts, dam;
    object *vics;
    if(!objectp(targ)) return;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();
    
    bolts = 2 + random(4);
    dam = roll_dice((bolts*10), 12);
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
    vics = TO->query_attackers();
    if(!sizeof(vics)) return;
    if(random(3)) return;
    call_out("electrify", 6, vics[random(sizeof(vics))]);
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
    dam = roll_dice(lev, 8);
    if(targ->reflex_save(28))
    {
        tell_object(targ, me+"%^BOLD%^%^RED%^ stabs her massive spear into your "+tlim+" and you quickly "+
        "move out of the way, avoiding most of the damage!%^RESET%^");
        tell_room(ETO, me+"%^BOLD%^%^RED%^ stabs her massive spear into "+targ->QCN+"%^BOLD%^%^RED%^'s "+
        tlim+" and "+targ->QS+" manages to move out of the way, avoiding most of the damage!%^RESET%^", targ);
        targ->cause_typed_damage(targ, tlim, (dam/2), "slashing");
        return;
    }
    tell_object(targ, me+"%^BOLD%^%^GREEN%^ IMPALES%^BOLD%^%^RED%^ your "+tlim+" with her massive spear!%^RESET%^");
    
    tell_room(ETO, me+"%^BOLD%^%^GREEN%^ IMPALES%^BOLD%^%^RED%^ "+targ->QCN+"%^BOLD%^%^RED%^'s "+tlim+" with her "+
    "massive spear!%^RESET%^", targ);
    
    targ->cause_typed_damage(targ, tlim, dam, "slashing");
    return 1;    
}

void giants_arrive()
{
    object giant;
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();
    giant = new(ELMON+"storm_giant");
    tell_room(ETO, giant->query_short()+"%^BOLD%^%^CYAN%^ suddenly appears beside "+me+"%^BOLD%^%^CYAN%^ and stands "+
    "in protection of her!%^RESET%^");
    giant->move(ETO);
    giant->set_property("minion", TO);
    giant->force_me("protect asantra");
    giant->force_me("protect asantra");
    giant->force_me("protect asantra");
    if(!random(3)) call_out("giants_arrive", 10);
    return;
}

void companions(object targ)
{
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();
    if(summoning) return electrify(targ);
    tell_room(ETO, me+"%^BOLD%^%^CYAN%^ chants quickly in a strange language!%^RESET%^");
    call_out("giants_arrive", 10);
    summoning = 1;
    return;
}

int query_watched() { return random(101); }