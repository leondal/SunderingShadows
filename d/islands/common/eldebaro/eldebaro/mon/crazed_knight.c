#include <std.h>
#include "../area_stuff.h"

inherit ELDEBARO_MONSTER;
int lev;

void plume(object targ);
void flame();
void wrack(object targ);
void charge();

void create() 
{
    string me;
    object ob;
    ::create();
    set_name("crazed knight");
    set_id(({"crazed knight", "insane knight", "knight", "eldebarocreature"}));
    
    set_short("%^RESET%^%^ORANGE%^A kn%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ght shrouded in %^BOLD%^%^BLACK%^darkness%^RESET%^");
    
    set_long("%^RESET%^%^ORANGE%^This man looks almost completely insane. It appears that something within him "+
    "is fighting against itself. Loose skin hangs heavily over his body, as if he has recently lost a "+
    "lot of weight and perhaps even muscle mass quickly. For some reason you believe that the cause of "+
    "this is great stress. You can ascertain that the reason is because of the immense internal conflict. "+
    "His once proud %^BOLD%^%^CYAN%^bluish%^RESET%^%^ORANGE%^-%^BOLD%^%^GREEN%^green %^RESET%^%^ORANGE%^"+
    "eyes look almost lifeless now, except for a faint hint of fight left in them. His hair, which was "+
    "one a brilliant sheen of black, has mostly either fallen out or been pulled out recently. A %^BOLD%^%^BLACK%^"+
    "darkness%^RESET%^%^ORANGE%^ visibly shrouds him and he seems to be constantly trying to get out "+
    "from it to no avail.%^RESET%^");
        
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_size(2);
    set_overall_ac(-20);
    set_class("paladin");
    
    lev = 32 + random(9);
    set_guild_level("paladin",lev);
    set_mlevel("paladin", lev);
    
    set_hp(33 * lev);
    set_speed(30);
    
    set_nogo(({DOCKROOM}));
    
    set_property("full attacks",1);
    set_property("no dominate",1);
    set_property("no paralyze",1);
    set_property("no death",1);
    
    set_stats("strength",19);
    set_stats("dexterity",15);
    set_stats("constitution",15);
    set_stats("intelligence", 10);
    set_stats("wisdom", 20);
    set_stats("charisma", 12);
    
    set("aggressive",55);
    me = TO->query_short();
    
    set_emotes(3, ({"%^BOLD%^%^BLACK%^Darkness threatens to overwhelm you!%^RESET%^",
	    me+" %^BOLD%^%^GREEN%^SCREAMS in rage!%^RESET%^",
	    me+" %^BOLD%^%^GREEN%^CACKLES%^BOLD%^%^WHITE%^ insanely!%^RESET%^",
	    me+" %^BOLD%^%^BLACK%^rips out some of his own hair and throws it into the wind!%^RESET%^",
	    me+" %^BOLD%^%^GREEN%^wails loudly for a brief moment!%^RESET%^",}),1);

    set_achats(4,({
        me +"%^BOLD%^%^BLACK%^ whispers hoarsely: %^RESET%^we should have not came here...", 
        me + "%^BOLD%^%^MAGENTA%^ says rapidly: %^RESET%^we will ALL die here.... ",
        me + "%^BOLD%^%^GREEN%^ utters barely above a whisper: %^RESET%^He's watching you too, you know.... he'll come for you...",
        me + "%^BOLD%^%^CYAN%^ cackles before speaking: %^RESET%^You're going to LOVE it on this side, the world looks so different!",
    }));
        
    set_new_exp(lev, "high");
    
    set_alignment(9);
    set_attack_bonus(10);
    
    set_spells(({"call lightning","dark bolt","sticks into snakes", "unholy orb"}));
 
    set_spell_chance(40);
    
    set_funcs(({"dark_bolts", "control_mind", "wrack", "charge", "something_evil", "control_mind", "wrack", "charge", "dark_bolts", "dark_bolts", "control_mind"}));
    
    set_func_chance(45);
	
    set_skill("athletics", 40);

	set_monster_feats(({
	    "charge",
		"mounted combat",
		"ride-by attack",
		"trample",
		"blade block",
		"impale",
		"light weapon",
		"strength of arm",
		"sweepingblow"
    }));
    if(!present("horse")) { call_out("do_horse",1,TO); }   
    add_money("platinum",random(500));
    ob = new("/d/common/obj/weapon/longsword");
    ob->set_property("enchantment", 5);
    ob->move(TO);
    ob = new("/d/common/obj/armour/shield");
    ob->set_property("enchantment", 5);
    ob->move(TO);
    command("wear shield");
    ob = new(ELOB+"lance_of_thorns");
    if(random(4)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
}

void control_mind(object targ)
{
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    
    me = TO->query_short();
    
    tell_object(targ, me+"%^BOLD%^%^BLACK%^ points a finger at you and screams: %^RESET%^"+
    targ->QCN+"%^RESET%^ SHOULD DIE!%^RESET%^");
    
    tell_room(ETO, me+"%^BOLD%^%^BLACK%^ points a finger at "+targ->QCN+"%^BOLD%^%^BLACK%^ and screams : %^RESET%^"+
    targ->QCN+"%^RESET%^ SHOULD DIE!%^RESET%^", targ);
    
    if(targ->will_save(28))
    {
        tell_object(targ, "%^BOLD%^%^CYAN%^You feel a sudden %^BOLD%^%^WHITE%^PULL%^BOLD%^%^CYAN%^"+
        " at your mind, but are able to resist it!%^RESET%^");
        tell_room(ETO, targ->QCN+"%^BOLD%^%^CYAN%^ seems to ignore "+me+"%^BOLD%^%^CYAN%^'s order!%^RESET%^", targ);
        return;
    }
    
    tell_object(targ, "%^BOLD%^%^CYAN%^You feel something invade your mind and you are "+
    "%^BOLD%^%^RED%^UNABLE%^BOLD%^%^CYAN%^ to move!%^RESET^");
    
    tell_room(ETO, targ->QCN+"%^BOLD%^%^CYAN%^ suddenly ceases all movement!%^RESET%^", targ);
    
    targ->set_paralyzed(20, "%^BOLD%^%^CYAN%^You are %^BOLD%^%^WHITE%^FROZEN%^BOLD%^%^CYAN%^ in "+
    "place, unable to move!%^RESET%^");    
    return;
}

void dark_bolts(object targ)
{
    string me, bolt_string;
    int bolts, dam;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    
    me = TO->query_short();
    
    tell_object(targ, me+"%^BOLD%^%^BLACK%^ points a finger at you and screams: %^RESET%^"+
    targ->QCN+"%^RESET%^ must be %^BOLD%^%^BLACK%^OVERTAKEN%^RESET%^!%^RESET%^");
    
    tell_room(ETO, me+"%^BOLD%^%^BLACK%^ points a finger at "+targ->QCN+"%^BOLD%^%^BLACK%^ and screams : %^RESET%^"+
    targ->QCN+"%^RESET%^ must be %^BOLD%^%^BLACK%^OVERTAKEN%^RESET%^!%^RESET%^", targ);
    
    bolts = 2 + random(4);
    dam = roll_dice((bolts*5), 6);
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
    
    tell_object(targ, capitalize(bolt_string) +"%^BOLD%^%^BLACK%^ bolts of %^BOLD%^%^WHITE%^PURE DARKNESS"+
    "%^BOLD%^%^BLACK%^ speed toward you!%^RESET%^");
    
    tell_room(ETO, capitalize(bolt_string) +"%^BOLD%^%^BLACK%^ bolts of %^BOLD%^%^WHITE%^PURE DARKNESS"+
    "%^BOLD%^%^BLACK%^ speed toward "+targ->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^", targ);
    
    if(targ->reflex_save(28))
    {
        tell_object(targ, "%^BOLD%^%^RED%^You are able to move out of the way just in the nick of "+
        "time and the bolts whiz harmlessly past you!%^RESET%^");
        
        tell_room(ETO, targ->QCN+"%^BOLD%^%^RED%^ is able to move out of the way just in the nick of "+
        "time and the bolts whiz harmlessly past "+targ->QO+"!%^RESET%^", targ);
        return;
    }
    
    tell_object(targ, "%^BOLD%^%^GREEN%^You are UNABLE to move out of the way and the "+
    bolt_string+" bolts slam into your chest!%^RESET%^");
    
    tell_room(ETO, targ->QCN+"%^BOLD%^%^GREEN%^ is UNABLE to move out of the way and the "+
    bolt_string+" bolts slam into "+targ->QP+" chest!%^RESET%^", targ);
    
    targ->cause_typed_damage(targ, "torso", dam, "negative energy");
    return;    
}

void wrack(object targ) 
{
  command("cause wracking pains "+targ->query_name()+"");
  return;
}

void charge()
{    
    object targ;
    targ = TO->query_current_attacker();
    if(!objectp(targ)) return;
    if(!TO->query_in_vehicle()) 
    { 
        switch (random(3))
        {
        case 0:
            wrack(targ);
            break;
        case 1:
            dark_bolts(targ);
            break;
        case 2:
            control_mind(targ);
            break;
        }
    }
    command("charge "+targ->query_name());
    return;
}
    
void do_horse()
{
    object horse;
    if(!objectp(ETO)) return;
    if(!objectp(TO)) return;
    horse = new("/d/common/mounts/war_horse.c");
    
    horse->set_owner(TO);
    horse->move(ETO);
    TO->force_me("mount horse");
    return;
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    if(TO->query_in_vehicle())
    {
        command("unwield sword");
        command("wield lance");
    }

    if(!sizeof(query_wielded())) { command("wield sword"); }
    return;
}

void init()
{
    if(!objectp(TO)) { return; }
    if(!objectp(TP)) { return; }
    ::init();

    if(TP->query_true_invis()) return;
    if(!userp(TP) || random(3)) return;
    command("say you SHOULD NOT BE HERE!");
    command("charge "+TPQN); 
}
