#include <std.h>
inherit MONSTER;
#include "../area_stuff.h"

int wander;
void create() 
{
    int FLAG;
    object ob;
    ::create();
    set_name("goblin grave robber");
    set_id(({ "goblin", "robber", "grave robber", "goblin grave robber", "eldebarocreature"}));
    set_short("Goblin Grave Robber");
    set("aggressive", 1);
    
    set_long("%^BOLD%^%^WHITE%^This small frazzled goblin looks exhausted. "+
    "His body is coated with layers of sand which he constantly tries to remove, with "+
    "very little luck. He was a %^BOLD%^%^BLACK%^dark leather%^BOLD%^%^WHITE%^ helm which "+
    "keeps most of the sand out of his eyes but this doesn't prevent him from looking "+
    "really %^BOLD%^%^RED%^angry%^BOLD%^%^WHITE%^ about the sand in the first place. "+
    "His body is almost thin and wiry, as if he is constantly moving around quickly from "+
    "one place to another. In each of his thin hands he carries a small weapon, which "+
    "he keeps always at the ready, just in case he has to use one.%^RESET%^");
    
    
    set_thief_skill("pick pockets", 85);
    set_class("thief");
    set_mlevel("thief",40);
    set_guild_level("thief", 40);
    set_body_type("humanoid");
    set_alignment(9);
    set_race("goblin");
    set_overall_ac(-28);
    set_stats("strength",15);
    set_stats("dexterity",22);
    set_stats("constitution", 17);
    set_stats("wisdom", 18);
    set_stats("charisma", 12);
    set_stats("intelligence", 12);
    set_max_hp(2500);
    set_hp(2500);
    set_new_exp(40,"high");
    set_hidden(1);
    set_scrambling(1);
    set_monster_feats(({
	    "dodge",
		"evasion",
		"mobility",
		"scramble",
		"spring attack",
		"combat reflexes",
        "weapon finesse"
        "stab",
    }));		
    TO->add_money("gold",random(1000)+550);
    TO->add_money("silver",random(3000)+1500);
    TO->add_money("copper",random(25000)+5000);    
    remove_property("swarm");
    toggle_steal();
    new(ELOB+"instructions")->move(TO);
    ob = new(ELOB+"coif_of_silence");
    if(random(6)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wear coif");
    ob = new(ELOB+"mind_guard");
    if(random(4)) ob->set_property("monsterweapon", 1);
    else FLAG = 1;
    ob->move(TO);
    command("wield sword");
    ob = new(ELOB+"mind_pierce");
    if(random(4) || FLAG) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield dagger");
    set_nogo(({DOCKROOM}));
}

void heart_beat() 
{
    object ob,here,sucker,*players;
    int x,num_p,gold,silver,electrum,platinum,copper,i,j;
    string *exits;
    string exitn;
    ::heart_beat();
    if(random(100) < 50) return;
    if(!objectp(TO)) return;
    here=ETO;
    if(wander > 50)
    {
        exits = ETO->query_exits();
        i = sizeof(exits);
        j = random(i);
        exitn = (string)ETO->query_exit(exits[j]);
        if(exitn != "/d/shadow/room/forest/road3") 
        {
            TO->force_me(exits[j]);
            wander = 0;
			return;
	    } 
        else { return; }
	} 
    else 
    {
        if(random(5))   set_hidden(1);
	    wander = wander + 1;
	    return;
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
    command("stab "+TPQN); 
    command("stab "+TPQN);
}
