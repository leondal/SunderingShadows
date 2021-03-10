#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

int MAX;

void create() 
{
    ::create();
    feat_type("instant");
    feat_category("Bladeweaver");
    feat_name("shield of whirling steel");
    feat_prereq("Bladeweaver L4");
    feat_syntax("shield_of_whirling_steel");
    feat_desc("The shield of whirling steel feat allows the bladeweaver to set his weapons in a constant state of motion. Any enemies that get near the bladeweaver while the shield of whirling steel is activated will take damage from the shield of whirling weapons.");
    allow_blind(1);
    set_required_for(({"masters parry"}));
}


int allow_shifted() { return 0; }


int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if((int)ob->query_class_level("bladeweaver") < 4)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}


string cm(string str) { return CRAYON_D->color_string(str,"grey"); }


int cmd_shield_of_whirling_steel(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }

    if(!TP->validate_combat_stance("dual wield"))
    {
        tell_object(TP,"%^RESET%^%^BOLD%^You must be wielding two weapons to use shield of whirling steel.%^RESET%^");
        return 1;
    }

    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}


int check_my_status(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(ob->query_bound() || ob->query_unconscious() || ob->query_tripped() || ob->query_paralyzed())
    {
        return 0;
    }
    return 1;
}


void execute_feat()
{
    int bonus;
    object obj;
    
    if((int)caster->query_property("using instant feat")) 
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    
    if(FEATS_D->is_active(caster,"shield of whirling steel"))
    {
        obj = query_active_feat("shield of whirling steel");
        tell_object(caster, cm("You lower your guard and can feel the ache in your arms after the effort you've expended."));
        tell_room(place, cm(""+caster->QCN+" stops spinning "+caster->QP+" weapons in a frenzy around "+caster->QO+"self."),caster);
        obj->dest_effect();
        dest_effect();
        return;
    }
    
    if(!check_my_status(caster))
    {
        tell_object(caster,"You can't move well enough to do that.");
        dest_effect();
        return;
    }
    
    if(!caster->validate_combat_stance("dual wield"))
    {        
        tell_object(TP,"%^RESET%^%^BOLD%^You must be wielding two weapons to use shield of whirling steel.%^RESET%^");
        dest_effect();
        return 1;
    }
    
    tell_object(caster, cm("You begin to spin your weapons in a deadly wall of violence, protecting yourself from attacks and ready to harm any enemy who comes near!"));
    tell_room(place, cm(""+caster->QCN+" begins spinning "+caster->QP+" weapons in a deadly arc of violence, making it difficult to get anywhere near "+caster->QO+"!"),caster);    

    
    caster->remove_property_value("added short",({"%^RESET%^%^BOLD%^ (rapidly spinning "+caster->QP+" weapons)%^RESET%^"}));
    caster->set_property("added short",({"%^RESET%^%^BOLD%^ (rapidly spinning "+caster->QP+" weapons)%^RESET%^"}));

    caster->set_property("active_feats",({TO}));
    caster->query_property("shield_of_whirling_steel",10);
    
    ::execute_feat();
    return;
}


void execute_attack()
{    
    object* attackers;
    int i,count;
    object* weapons;

    if(!objectp(caster) || !objectp(environment(caster)))
    {
        dest_effect();
        return;
    }
    
    place = environment(caster);
    attackers = caster->query_attackers();
    weapons = caster->query_wielded();
    
    if(!check_my_status(caster))
    {
        if(objectp(place)) { place->addObjectToCombatCycle(TO,1); }
        tell_object(caster, cm("Your movements are too hampered to maintain the shield of whirling steel right now!"));
        return;
    }
    
    if(!caster->validate_combat_stance("dual wield"))
    {        
        tell_object(TP,"%^RESET%^%^BOLD%^You must be wielding two weapons to use shield of whirling steel.%^RESET%^");
        dest_effect();
        return 1;
    }
    
    if(!random(50))
    {
        tell_object(caster, cm("You put your weapons through a series of quick maneuvers, designed to intercept attacks from all angles!"));
        tell_room(place, cm(""+caster->QCN+" puts "+caster->QP+" weapons through a dizzying series of impossibly fast maneuvers!"),caster);
    }
    
    if(!sizeof(attackers))
    {
        if(!random(50))
        {
            tell_object(caster, cm("With no nearby attackers, you slow the speed of your weapons, giving your arms some much needed rest."));
            tell_room(place, cm("With no nearby attackers, "+caster->QCN+" slows the speed of the weapons spinning around "+caster->QO+"self, letting "+caster->QP+" arms rest."),caster);
        }
    }
    else
    {
        for(i=0;sizeof(attackers),i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            if(!check_my_status(attackers[i])) { continue; } // this is about attacking people who get too close, skip ones that are probably not
            if(attackers[i]->query_casting()) { continue; }
            if(attackers[i]->is_wielding("lrweapon")) { continue; }
            
            tell_object(attackers[i], cm("As you get close to "+caster->QCN+", "+caster->QP+" spinning weapons strike you painfully!"));
            attackers[i]->cause_typed_damage(attackers[i], attackers[i]->return_target_limb(), roll_dice(clevel, 5), weapons[0]->query_damage_type());
            count++;
        }
        
        if(count)
        {
            tell_object(caster, cm("You lash out at your enemies from behind your whirling weapons!"));
        }

    }

    if(objectp(place)) { place->addObjectToCombatCycle(TO,1); }
    else { dest_effect(); }
}


void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property_value("added short",({"%^RESET%^%^BOLD%^ (rapidly spinning "+caster->QP+" weapons)%^RESET%^"}));
        caster->remove_property_value("active_feats",({TO})); 
        caster->remove_property("shield_of_whirling_steel");
    }

    ::dest_effect();
    remove_feat(TO);
    return;
}

