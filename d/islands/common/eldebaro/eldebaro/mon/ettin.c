#include <std.h>
#include "../area_stuff.h"

inherit ELDEBARO_MONSTER;
int lev;

void create() 
{
    object ob;
    ::create();
	set_race("ettin");
    set_name("monstrous windburned ettin");
    set_id(({"ettin", "giant", "windburned ettin", "monstrous ettin", "monstrous windburned ettin", "eldebarocreature"}));
    
    set_short("%^RESET%^%^ORANGE%^A Monstr%^BOLD%^ou%^RESET%^%^ORANGE%^s w%^BOLD%^i%^RESET%^%^ORANGE%^"+
    "ndb%^BOLD%^u%^RESET%^%^ORANGE%^rn%^BOLD%^e%^RESET%^%^ORANGE%^d %^BOLD%^e%^RESET%^%^ORANGE%^tt%^BOLD%^"+
    "i%^RESET%^%^ORANGE%^n%^RESET%^");
    
    set_long("%^RESET%^%^ORANGE%^This monstrous two headed giant is %^BOLD%^%^RED%^ENRAGED%^RESET%^%^ORANGE%^"+
    " and it quite obvious why that is. His skin is a %^BOLD%^%^RED%^bright red%^RESET%^%^ORANGE%^ "+
    "and most of it looks quite thin. In fact you believe that it has been burned by the continous, chaotic "+
    "wind that currently plagues the island. Both of his heads are bald and look scraped, as if he has "+
    "fallen or been blown over by the wind and ground both of his heads into the wet sand. He only has "+
    "one good eye, which is an unnatural %^BOLD%^%^CYAN%^azure%^RESET%^%^ORANGE%^. The other three are "+
    "a %^BOLD%^%^BLACK%^dull gray%^RESET%^%^ORANGE%^ and look quite dead, each is full of particles of sand "+
    "that have likely been blown into them by the unrelenting wind. He carries no weapons and is entirely "+
    "naked, which likely makes the wind even worse. A %^BOLD%^%^BLACK%^darkness%^RESET%^%^ORANGE%^ hangs "+
    "heavily over him.%^RESET%^");
    
    set_body_type("humanoid");
    set_size(4);
    lev = 32 + random(9);
    set_class("fighter");
    set_guild_level("fighter", lev);
    set_mlevel("fighter", lev);
    set_max_hp(lev * 38);
    set_hp(query_max_hp());
	set_new_exp(lev, "high");
    set_stats("strength",27);
    set_stats("intelligence",4);
    set_stats("wisdom",6);
    set_stats("charisma",5);
    set_stats("constitution",24);
    set_stats("dexterity",4);
    set_alignment(9);
    set("aggressive",55);
    set_property("full attacks",1); 
    set_func_chance(25);
    set_funcs(({"pound", "tackle", "tackle_n_pound", "something_evil", "tackle", "pound", "tackle_n_pound", "pound", "pound", "pound"}));
    set_overall_ac(-20);
    set_property("add kits",10);
    add_attack_bonus(10);
    add_damage_bonus(15);
    set_nogo(({DOCKROOM}));
}

varargs void pound(object targ, int hits)
{
    string me, tlim;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    me = TO->query_short();
    tlim = targ->return_target_limb();
    if(!intp(hits)) hits = 1 + random(2);
    while(hits--)
    {
        if(hits < 0) break;
        tell_object(targ, me+"%^BOLD%^%^MAGENTA%^ pounds you in the "+tlim+" with his meaty fists!%^RESET%^");
        tell_room(ETO, me+"%^BOLD%^%^MAGENTA%^ pounds "+targ->QCN+"%^BOLD%^%^MAGENTA%^ in the "+tlim+" with his meaty fists!%^RESET%^", targ);
        targ->cause_typed_damage(targ, tlim, roll_dice(6, 12), "bludgeoning");
        continue;
    }
    return 1;    
}

int tackle(object targ)
{
    string me;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    me = TO->query_short();
    tell_object(targ, me+"%^BOLD%^%^BLACK%^ charges toward you and then leaps in the air!%^RESET%^");
    tell_room(ETO, me+"%^BOLD%^%^BLACK%^ charges at "+targ->QCN+"%^BOLD%^%^BLACK%^ and then leaps in the air!%^RESET%^", targ);
    
    if(targ->reflex_save(28))
    {
        tell_object(targ, "%^BOLD%^%^RED%^You move out of the way just in time and "+me+"%^BOLD%^%^BLACK%^ tumbles to the ground right where "+
        "you were standing!%^RESET%^");
        
        tell_room(ETO, targ->QCN+"%^BOLD%^%^RED%^ moves out of the way just in time and "+me+"%^BOLD%^%^BLACK%^ tumbles to the ground right where "+
        targ->QS+" was standing!%^RESET%^", targ);
        
        TO->set_paralyzed(10, "%^BOLD%^%^GREEN%^You are struggling to get back on your feet!%^RESET%^");
        return 0;       
    }
    
    tell_object(targ, "%^BOLD%^%^BLACK%^You FAIL to move out of the way in time and "+me+"%^BOLD%^%^BLACK%^ lands on you, crushing you "+
    "with his weight and pinning you under him!%^RESET%^");
    
    tell_room(ETO, targ->QCN+"%^BOLD%^%^BLACK%^ FAILS to move out of the way in time and "+me+
    "%^BOLD%^%^BLACK%^ lands on "+targ->QO+", pinning "+targ->QO+" to the ground!%^RESET%^", targ);
    
    targ->cause_typed_damage(targ, "torso", roll_dice(8, 12), "bludgeoning");
    targ->set_paralyzed(20, "%^BOLD%^%^BLACK%^You are pinned beneath "+me+"%^BOLD%^%^BLACK%^!%^RESET%^");
    TO->set_paralyzed(20, "%^BOLD%^%^GREEN%^You are struggling to get back on your feet!%^RESET%^");    
    return 1;   
}


void tackle_n_pound(object targ)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    if(tackle(targ))
    {
        pound(targ, 2 + random(3));
        return;
    }
    return;
}
int query_watched() { return random(101); }