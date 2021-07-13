/*
  _telekinetic_hurl.c
  
  Kineticist feat.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("active");
    feat_category("Psionics");
    feat_name("telekinetic hurl");
    feat_prereq("Psion (Kineticist) L2");
    feat_syntax("teleinetic_hurl [TARGET]");
    feat_desc("The kineticist can spen their Psionic Focus to hurl small objects at their foe, causing bludgeoning damage on a ranged touch attack. If no target is designated, this feat will target your current attacker.");
    psionic(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("psion") < 2)
    {
        dest_effect();
        return 0;
    }
    
    if(ob->query_discipline() != "kineticist")
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_telekinetic_hurl(string str)
{
    object feat;
    
    if(!this_player())
        return 0;
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}

void execute_feat()
{
    ::execute_feat();
    
    if(!caster)
        return;
    
    if(!USER_D->spend_pool(caster, 1, "focus"))
    {
        tell_object(caster, "You need to be focused to use telekinetic hurl.");
        return;
    }
    
   if ((int)caster->query_property("using instant feat"))
   {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    
    
    if(!target)
        target = caster->query_current_attacker();
    if(!target)
    {
        tell_object(caster, "That target isn't here.");
        dest_effect();
        return;
    }
    
    tell_object(caster, "%^CYAN%^BOLD%^You raise a hand and hurl a nearby stone at " + target->QCN + " with your telekinetic powers!%^RESET%^");
    tell_object(target, "%^BOLD%^" + caster->QCN + " raises a hand and hurls a nearby stone at you with their telekinetic powers!");
    tell_room(place, caster->QCN + " raises a hand and hurls a nearby stone at " + target->QCN + " with their telekinetic powers!", ({ caster, target }));
    caster->set_property("using instant feat", 1);
    spell_kill(target, caster);
}

void execute_attack()
{
    int roll, damage;
    
    if(!caster)
    {
        dest_effect();
        return;
    }
    
    caster->remove_property("using instant feat");
    
    if(!target || caster->query_unconscious() || environment(target) != place)
    {
        dest_effect();
        return;
    }

    roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    
    if(!roll)
    {
        tell_object(caster, "%^WHITE%^" + target->QCN + " jumps aside and avoids your hurled stone!%^RESET%^");
        tell_object(target, "%^WHITE%^You jump aside and avoid the hurled stone!%^RESET%^");
        tell_room(place, target->QCN + " jumps aside and avoids the hurled stone!", ({ caster, target }));
        return;
    }
    
    damage = roll_dice(caster->query_prestige_level("psion"), 4);
    
    tell_object(caster, "%^ORANGE%^Your stone smashes hard into" + target->QCN + " and they scream in pain!%^RESET%^");
    tell_object(target, "%^RED%^The stone smashes hard into you and you scream in pain!%^RESET%^");
    tell_room(place, "The stone smashes hard into " + target->QCN + " and they scream in pain!", ({ caster, target }));
    
    target->cause_typed_damage(target, target->return_target_limb(), damage, "bludgeoning");
    dest_effect();
    return;
}   
    

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}

