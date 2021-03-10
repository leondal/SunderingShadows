//Added feats - Octothorpe 6/22/10

#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create() 
{
    object ob;
    ::create();
    set_name("infantry");
    set_id(({"skeleton","warrior","infantry","skeletal infantry"}));
    set_short("%^RED%^Heavy skeletal infantry%^RESET%^");
    set_long("The heavy skeletal infantry are among Kartakass's most elite troops "
        "sent to kill only Kartakass's most despised enemies. These creatures "
        "are ruthless, they have no hearts with which to feel mercy. Their "
        "only reason for existing is to bring your throbbing heart to their "
        "Lord Kartakass, and pray it pleases him.");
    set_race("undead");
    set_body_type("human");
    set_gender("male");
    set_hd(roll_dice(3,6)+15,8);
    set_size(2);
    set_overall_ac(10);
    set_class("fighter");
    set_guild_level("fighter",query_hd());
    set_guild_level("mage",query_hd());
    add_search_path("/cmds/fighter");
    add_search_path("/cmds/wizard");
    set_hp(20 * query_hd());
    set_speed(30);
    nogo("one");
    set_property("full attacks",1);
    set_property("no dominate",1);
    set_property("no paralyze",1);
    set_property("no death",1);
    set_stats("strength",19);
    set_stats("dexterity",19);
    set_stats("constitution",19);
    set("aggressive",25);
    set_exp(2000*query_hd());
    set_new_exp(query_hd(),"boss");
    set_alignment(9);
    set_attack_bonus(3);
    set_spells(({"cone of cold","lightning bolt","fireball","scorcher"}));
    set_spell_chance(25);
    //set_funcs(({"plume","flame","rushit","flashit","impaleit","sweepit"}));
    set_funcs(({"plume","flame"}));
    set_func_chance(35);
    ob=new(OBJS"ancient_great_blade.c");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wield sword");
    ob=new(OBJS"r_helm.c");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wear helm");
    ob=new(OBJS"death_plate.c");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wear plate");
    add_money("gold",random(1500));
    add_money("platinum",random(50));
	set_monster_feats(({
        "blade block",
		"impale",
		"light weapon",
		"strength of arm",
		"sweepingblow",
		"powerattack",
		"shatter",
		"sunder",
		"rush"
	}));
    if(!random(20)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("bone dust");
      ob->move(TO);
    }
    set_resistance("negative energy",10);
    set_resistance("positive energy",-10); 
}

void plume(object targ)
{
    tell_object(targ,"%^BOLD%^%^RED%^The Skeleton drops it's jaw and breathes fire at you!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^RED%^The Skeleton drops its jaw and breathes fire "
        "at "+targ->QCN+"!",targ);
    if(!ROLLSAVE(targ,BW))
    {
        tell_object(targ,"%^BOLD%^You are struck by a blaze of flames!%^RESET%^");
        tell_room(ETO,"%^BOLD%^A plume of flame shoots out from the Skeleton's "
            "mouth striking "+targ->QCN+"!",targ);
        TO->set_property("magic",1);
        targ->do_damage(targ->return_limb(),roll_dice(3,12));
        TO->set_property("magic",-1);
        targ->set_paralyzed(10 + roll_dice(3,6),"%^GREEN%^You scream in agony as the "
            "flames burn through to your soul!%^RESET%^");
        return;
    } 

    tell_object(targ,"%^CYAN%^You manage to duck out of the way of the flames "
        "just before they strike you!%^RESET%^");
    tell_room(ETO,"%^CYAN%^You see "+targ->QCN+" quickly duck out of the way of "
        "a giant plume of flames!%^RESET%^",targ);
    return;
}

void flame()
{
    object *targs;
    int i;
    targs = filter_array(all_living(ETO),"is_target",CREATURE);
    if(!sizeof(targs)) { return; }
    for(i=0;i<sizeof(targs);i++)
    {
        if(targs[i]->query_true_invis()) continue;
        if(targs[i] == TO) continue;
        tell_object(targs[i],"%^RED%^The Skeleton gets an evil grin on its face, "
            "and smashes his fist into the ground.%^RESET%^");
        if(!ROLLSAVE(targs[i],PPD))
        {
            tell_object(targs[i],"%^BOLD%^%^RED%^Flames errupt from beneath you, "
                "sending you crashing to the ground, and bathing you in molten rock!%^RESET%^");
            targs[i]->do_damage(targs[i]->return_target_limb(),roll_dice(5,6));
            targs[i]->set_paralyzed(20,"%^CYAN%^The flames burn and scorch you "
                "as you try to put them out!%^RESET%^");
            return;
        } 
        tell_object(targs[i],"%^RED%^Tremendous columns of flames shoot up from the "
            "ground scorching you, but you manage to dodge most of them!%^RESET%^");
        targs[i]->do_damage(targs[i]->return_target_limb(),roll_dice(3,6));
        return;
    }
}

void flashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return; 
   TO->force_me("flash "+targ->query_name());
}

void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return; 
   TO->force_me("rush "+targ->query_name());
}

void impaleit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return; 
   TO->force_me("impale "+targ->query_name());
}

void sweepit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return; 
   TO->force_me("sweepingblow");
}
