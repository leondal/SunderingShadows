/*
  _master_strike.c
  
  Thief capstone ability.
  Active feat that does a lot of damage and paralyzes.
  Should bypass physical defense but be on cooldown.

  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <ansi.h>

inherit FEAT;

object *weapons;

void create()
{
    ::create();
    
    set_author("tlaloc");
    feat_type("instant");
    feat_name("master strike");
    feat_prereq("Thief L31");
    feat_syntax("master_strike [TARGET]");
    feat_desc("With this feat, the thief is able to perform a devastating strike on a vulnerable enemy, fully exploiting that vulnerability. Master strike can only be used against targets who are vulnerable to sneak attacks (paralyzed, tripped, blind, or attacking someone else). Master strike bypasses physical defenses, like armor class and damage resistance. This feat deals damage based on the thief's sneak attack dice. If the target does not make a fortitude save, they suffer internal bleeding. This feat has a cooldown.");
    set_save("fort");
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!ob || !objectp(ob))
        return 0;
    
    if(ob->query_class_level("thief") < 31)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_master_strike(string str)
{
    object feat;
    
    if(!objectp(this_player()))
        return 0;
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(),str);
    return 1;
}

int check_can_use()
{   
    if(!caster || !objectp(caster))
        return 0;
    
    weapons = caster->query_wielded();
    
    if(!sizeof(weapons))
        return 0;
    
    if(!objectp(weapons[0]))
    {
        tell_object(caster, "You need to wield a weapon to use master strike.");
        return 0;
    }
    
    if(caster->query_in_vehicle())
    {
        tell_object(caster, "You can't use master strike while mounted.");
        return 0;
    }
    
    if(!target->is_vulnerable_to(caster))
    {
        tell_object(caster, "Your target isn't vulnerable to sneak attacks.");
        return 0;
    }
    
    if(caster->cooldown("master strike"))
    {
        tell_object(caster, "You can't use master strike yet.");
        return 0;
    }
    
    return 1;
}

void execute_feat()
{
    object *attackers;
    
    ::execute_feat();
    
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        caster->send_paralyzed_message("info",caster);
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if(caster->query_casting())
    {
        tell_object(caster,"%^BOLD%^You are already in the middle of casting a spell.%^RESET%^");
        dest_effect();
        return;
    }
    if(target == caster)
    {
        tell_object(caster,"You cannot use master strike on yourself!");
        dest_effect();
        return;
    }
    
    if(!target)
    {
        attackers = caster->query_attackers();
        
        if(sizeof(attackers))
        {
            attackers = shuffle(attackers);
            target = attackers[0];
        }
    }
    
    if(!objectp(target) || !present(target, place))
    {
        tell_object(caster, "There's no one here to strike.");
        dest_effect();
        return;
    }
    
    if(!check_can_use())
    {
        dest_effect();
        return;
    }
    
    caster->use_stamina(roll_dice(1,6));
    caster->set_property("using instant feat",1);
    
    tell_object(caster, "%^YELLOW%^You position yourself to perform a master strike.");
    
    return;
}

void execute_attack()
{
    int damage, DC;
    object *weapons, stagger;
    string ename, pname;
    
    if(!caster || !target)
        return;
   
    if(!present(target, place))
        return;
    
    if(!check_can_use())
        return;
    
    spell_kill(target, caster);
    caster->remove_property("using instant feat");
    //Bypasses physical avoidance...needs to have a cooldown....starting with 5 minutes
    caster->add_cooldown("master strike", 300);
    ename = target->QCN;
    pname = caster->QCN;
    
    tell_object(caster, CRAYON_D->color_string("You strike " + ename + " in their most vulnerable spot with incredible ferocity!", "lightning yellow"));
    tell_room(place, sprintf("%s%s strikes %s ferociously in a vulnerable spot!%s", HIR, pname, ename, NOR), ({ caster }));
    
    damage = caster->query_class_level("thief") / 2;
    
    if(FEATS_D->usable_feat(target, "mighty resilience"))
        damage = 0;
        
    //Armor bond sneak attack resistance
    if(target->query_property("fortification 75"))
        damage /= 4;
    else if(target->query_property("fortification 50"))
        damage /= 2;
    else if(target->query_property("fortification 25"))
        damage = (damage * 3) / 4;
    
    if(FEATS_D->usable_feat(target, "undead graft"))
        damage /= 2;
        
    //Barbarians/Thieves with danger sense gain resistance to sneak attacks
    if(FEATS_D->usable_feat(target, "danger sense") && target->query_level() + 4 > caster->query_level())
        damage /= 2;
    
    if(caster->query_blind() || caster->light_blind())
    {
        if(FEATS_D->usable_feat(caster, "blindfight"))
            damage /= 2;
        else 
            damage = 0;
    }
    
    weapons = caster->query_wielded();

    damage = roll_dice(damage, 6);
    damage += sizeof(weapons) ? weapons[0]->query_wc() : caster->query_unarmed_damage();
    damage += BONUS_D->query_stat_bonus(caster, "dexterity");
    damage += caster->query_damage_bonus();
    
    target->cause_typed_damage(target, target->return_target_limb(), damage, "untyped");
    
    if(!objectp(target))
        return;
    
    DC = 10 + BONUS_D->query_stat_bonus(caster, "intelligence") + caster->query_class_level("thief") / 5;
    
    if(!do_save(target, DC))
    {
        
        tell_object(target, "%^BOLD%^RED%^The strike ruptures your organs!");
        tell_room(place, ename + "'s organs are ruptured by the strike!", ({ target }));
        target->set_property("rend", 5);
    }
    
    return;
}

void dest_effect()
{
    ::dest_effect();
    
    remove_feat(this_object());
    
    return;
}   