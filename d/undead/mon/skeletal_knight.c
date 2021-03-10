//Added feats - Octothorpe 6/22/10

#include <std.h>
#include "../undead.h"

inherit CREATURE;

void plume(object targ);
void flame();
void wrack(object targ);
void charge();

void create() 
{
    object ob;
    ::create();
    set_name("skeletal knight");
    set_id(({"skeleton","warrior","knight","skeletal knight","death knight"}));
    set_short("Death knight of the Empire");
    set_long("The Death knights are Kartakass's most experienced troops, sent only "
        "when there is dire need for them. It is said that a dozen Death "
        "knights were all that was needed to crush the entire first wave of "
        "Morock's army in the days of old. They are powerfull warriors, not "
        "to be taken lightly.");
    set_race("undead");
    set_body_type("human");
    set_gender("male");
    set_hd(roll_dice(3,6)+15,8);
    set_size(2);
    set_overall_ac(0);
    set_class("antipaladin");
    set_guild_level("antipaladin",query_hd());
    add_search_path("/cmds/antipaladin");
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
    set_new_exp(25,"very high");
    set_alignment(9);
    set_attack_bonus(3);
    set_spells(({"call lightning","dark bolt"}));
    set_spell_chance(20);
    set_funcs(({"plume","flame","wrack","charge","impaleit","sweepit"}));
    set_func_chance(35);
	set_skill("athletics", query_hd()+1);
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
    ob = new(CWEAP"hhlance.c");
    ob->set_property("enchantment",3);
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    ob=new(OBJS"ancient_great_blade.c");
    if(random(50)) { ob->set_property("monsterweapon",1); }
    ob->move(TO);
    ob=new(OBJS"death_plate.c");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wear plate");
    add_money("gold",random(2500));
    add_money("platinum",random(100));
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

void wrack(object targ) 
{
  command("cause wracking pains "+targ->query_name()+"");
  return;
}

void charge()
{    
    object targ;
    targ = TO->query_current_attacker();
    if(!TO->query_in_vehicle()) 
    { 
        switch (random(3))
        {
        case 0:
            wrack(targ);
            break;
        case 1:
            flame();
            break;
        case 2:
            plume(targ);
            break;
        }
    }
    command("charge "+targ->QN);
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