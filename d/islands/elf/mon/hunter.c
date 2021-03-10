#include <daemons.h>
#include <std.h>
#include "../elf.h"

#define PATHFINDER "/daemon/pathfinder_d.c"

inherit MONSTER;

string target_name;


void create ()
{
    object obj, pouch;
    
    ::create ();
    
    set_moving(0);
    set_name("hunter");
    set_id(({ "hunter","Ashta'Rathai hunter","elf" }));
    set_property("swarm",1);
    set_property("no dominate",1);
    set_property("no bows",1);
    set_mob_magic_resistance("average");
    set_property("magic",1);
    set_short("An Ashta'Rathai hunter");
    set_property("bounty hunter",1);
    
    add_damage_bonus(7);
    add_attack_bonus(7);
    
    set_long("A rather road worn elf in mismatched "+
        "clothing build for the road.  "+QP+" gear is neatly arranged.  "+
        QO+" has a determined look upon"+ QP+" face.  This elf is used "+
        "to dealing with hard tasks and getting them done."  );
    set_monster_feats(({"daze","disarm","expertise","knockdown",
        "weapon finesse","exotic weapon proficiency"}));
    
    set_property("swarm",1);
    set_gender(random(2)?"male":"female");
    set_race("elf");
    add_search_path("/cmds/feats/");
    add_search_path("/cmds/mortal/");
    set_hd(30,1);
    set_class("fighter");
    set_mlevel("fighter",30);
    set_property("full attacks",1);
    set_stats("strength",18);
    set_stats("intelligence", 13);
    set_stats("dexterity", 17);
    set_stats("charisma", 16);
    set_stats("wisdom", 10);
    set_stats("constitution", 18);
    set_alignment(1);
    set_max_hp(250);
    set_hp(250);
    set("aggressive", 0);
    set_overall_ac(-5);
    add_money("platinum",random(100));
    
    "/d/common/daemon/randgear_d"->arm_me(TO,"edgedm",70,4); 
    new("/d/common/obj/rand/cloak")->move(TO);
    new("/d/common/obj/rand/r_shoes")->move(TO);
    new("/d/common/obj/rand/rand_leath_head")->move(TO);
    new("/d/common/obj/rand/base_pants")->move(TO);
    
    pouch = new ("/d/common/obj/misc/pouch.c");
    pouch->set_property("monsterweapon",1);
    pouch->move(TO);
    
    obj = new("/d/azha/obj/gmr_ring.c");
    obj->set_property("monsterweapon",1);
    obj->move(pouch);

    command("wearall");
    set_new_exp(30,"normal");
    set_max_level(35);
}


void heart_beat()
{
    object far_targ, targ, * players;
    int i;
  
    if(!objectp(TO) || !objectp(ETO)) { return; }
    
    targ = present(target_name, ETO);
    
    if(objectp(targ))
    {
        force_me("get band from pouch");
        force_me("wear band");
        return;
    }
    else
    {
        force_me("put band in pouch");
    }

    if(!random(5))
    {
        far_targ = PATHFINDER->far_present(ETO, target_name,  5);
        if(!objectp(far_targ))
        {
            off_duty();
        }
    }
}


void off_duty()
{
    if(objectp(ETO)) { tell_room(ETO, "%^ORANGE%^Elf leaves the area."); }
    TO->move("/d/shadowgate/void");
    TO->remove();
}


void rush_em(object ob)
{
    object net;
    
    command("disarm "+ob->query_name());
    
    TO->kill_ob(ob,1);
    
    if(!present("net",TO))
    {
        net = new("/d/laerad/obj/net.c")->move(TO);
        command("wield net");
        net->set_property("monsterweapon",1);
        command("throw net at "+ob->query_name());
        command("get all");
    }

    return;
}


void set_target(string name) { target_name = name; }

string query_target() { return target_name; }