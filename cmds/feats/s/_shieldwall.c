#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

int MAX;

void create() 
{
    ::create();
    feat_type("instant");
    feat_category("WeaponAndShield");
    feat_name("shieldwall");
    feat_prereq("Shieldbash");
    feat_syntax("shieldwall offensive|defensive|min|max|check");
    feat_desc("The Shieldwall feat allows you to fight defensively using your shield to help deflect attacks and avoid incoming damage. The more defensively that you fight with your shield, the fewer melee attacks that you will get. You may increase your defensive ability with your shield until you have only one melee attack remaining. Using shieldwall defensively will also reduce the power of your spells. Using shieldwall defensively when you have the counter feat will also increase the damage of your attacks.");
    set_target_required(0);
    allow_blind(1);
    set_required_for(({"deflection","reflection","counter"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob, "shieldbash"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void end_feat(object ob)
{
    int num;
    if(!objectp(ob)) { return; }
    num = (int)ob->query_property("shieldwall_bonus");
    if(!num) { return; }

    //ob->add_ac_bonus(num); // doesn't give ac anymore, it increases block chance
    ob->set_property("empowered",num);
    ob->set_property("damage resistance",-num * 2);
    ob->remove_property("shieldwall_bonus");
    ob->remove_property("shieldwall");
    ob->remove_property("number_of_attacks");
    return;
}

void init_num_attacks(object ob)
{
    string *classes,file;
    int i,num;

    if(ob->query_property("number_of_attacks")) 
    { 
        if(MAX) return;
    }
    
    classes = (string *)ob->query_classes();
    num = 0;
    if(sizeof(classes))
    {
        for(i=0;i<sizeof(classes);i++)
        {
            file = DIR_CLASSES+"/"+classes[i]+".c";
            if(!file_exists(file)) { num = 0; continue; }
            if((int)file->number_of_attacks(ob) > num) { num = (int)file->number_of_attacks(ob); }
        }
    }
    MAX = num + 1;
    return;
}

int cmd_shieldwall(string str)
{
    object feat;
    if (!objectp(TP)) { return 0; }
    if (str) str = lower_case(str);
    if (str != "offensive" &&
		str != "defensive" &&
		str != "min" &&
		str != "max") {
		str = "check";
	}

    if(!(int)TP->is_wearing_type("shield"))
    {
        tell_object(TP,"%^RESET%^%^BOLD%^You must be wearing a shield first.%^RESET%^");
        return 1;
    }

    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

int check_my_status(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(ob->query_bound() || ob->query_unconscious() || ob->query_tripped())
    {
        tell_object(ob,"You are unable to move well enough to do that.");
        return 0;
    }
    return 1;
}

void execute_feat()
{
    int bonus;

    if(!check_my_status(caster))
    {
        dest_effect();
        return;
    }

    ::execute_feat();

    bonus = (int)caster->query_property("shieldwall");

    init_num_attacks(caster);

    switch(arg)
    {

    case "defensive":

        if(bonus == MAX)
        {
            tell_object(caster,"%^RESET%^%^MAGENTA%^Your shield can give you no additional protection!%^RESET%^");
            break;
        }

        tell_object(caster,"%^BOLD%^%^YELLOW%^You shift your stance, positioning your shield to better defend "
            "against all attacks!%^RESET%^");
        tell_room(place,"%^BOLD%^%^YELLOW%^"+caster->QCN+" shifts "+caster->QP+" stance, positioning "
            ""+caster->QP+" shield to better defend against all attacks!%^RESET%^",caster);

        caster->set_property("shieldwall",1);
        //caster->add_ac_bonus(2); 
        caster->set_property("damage resistance",2);
        caster->set_property("shieldwall_bonus",1);
        caster->set_property("empowered",-1);
        break;

    case "offensive":

        if(!bonus)
        {
            tell_object(caster,"%^RESET%^%^MAGENTA%^You are no longer fighting defensively with your shield!%^RESET%^");
            break;
        }

        tell_object(caster,"%^BOLD%^%^YELLOW%^You shift your stance, moving from behind your shield into " +
            "better position to attack!%^RESET%^");
        tell_room(place,"%^BOLD%^%^YELLOW%^"+caster->QCN+" shifts "+caster->QP+" stance, moving from " +
            "behind "+caster->QP+" shield and into a better position to attack!%^RESET%^", caster);

        caster->set_property("shieldwall",-1);
        //caster->add_ac_bonus(-2);
        caster->set_property("damage resistance",-2);
        caster->set_property("shieldwall_bonus",-1);
        caster->set_property("empowered",1);
        break;
		
	case "max":
	
		tell_object(caster,"%^BOLD%^%^YELLOW%^You shift your stance, positioning your shield to better defend " +
            "against all attacks!%^RESET%^");
        tell_room(place,"%^BOLD%^%^YELLOW%^"+caster->QCN+" shifts "+caster->QP+" stance, positioning "
            + caster->QP + " shield to better defend against all attacks!%^RESET%^",caster);

        caster->set_property("shieldwall",MAX-bonus);
        caster->set_property("damage resistance",(MAX-bonus) * 2);
        caster->set_property("shieldwall_bonus",MAX-bonus);
        caster->set_property("empowered",bonus-MAX);
        break;
		
    case "min":
	
		tell_object(caster,"%^BOLD%^%^YELLOW%^You shift your stance, moving from behind your shield into " +
            "better position to attack!%^RESET%^");
        tell_room(place,"%^BOLD%^%^YELLOW%^"+caster->QCN+" shifts "+caster->QP+" stance, moving from " +
            "behind "+caster->QP+" shield and into a better position to attack!%^RESET%^", caster);
        caster->set_property("shieldwall",-bonus);
        caster->set_property("damage resistance",-bonus * 2);
        caster->set_property("shieldwall_bonus",-bonus);
        caster->set_property("empowered",bonus);
        break;

    case "check":
        tell_object(caster,"%^RESET%^%^GREEN%^You have shifted %^MAGENTA%^"+caster->query_property("shieldwall") +
            " %^RESET%^%^GREEN%^points into shieldwall.%^RESET%^");
        break;
    }

    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}

