/*
  _layonhands.c
  
  Rewrite for paladin remap. Now will use dedications,
  based on PF mercies for varying effects.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

#define FEATTIMER 80

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Presence");
    feat_name("layonhands");
    feat_syntax("layonhands TARGET");
    feat_desc("This will heal the player you choose, increasing in power with your paladin level and your charisma. Invoking this kind of divine power can be wearying, so the paladin will need to wait a few minutes before they can attempt to use such a blessing again. Lay on hands matches your positive/negative energy affinity and can be used to cause damage, much like channel. Lay on Hands costs one Divine Grace point to use.");
    feat_prereq("Paladin L2");
}

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("paladin") < 2 )
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_layonhands(string str)
{
    object feat;
    
    if(!objectp(this_player())) 
        return 0;
    
    if(!stringp(str))
        return 0;
    
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat()
{
    int delay;
 
    if(!(int)USER_D->spend_pool(this_player(), 1, "grace"))
    {
        tell_object(caster, "You don't have the Divine Grace to use Lay on Hands!");
        return;
    }
    
    ::execute_feat();
    
    if(!objectp(target))
        target = this_player();
    
    tell_object(caster, "%^BOLD%^You begin to channel divine energy.%^RESET%^");
    
    //delay = time() + FEATTIMER;
    //delay_msg(FEATTIMER,"%^BOLD%^%^WHITE%^You can %^CYAN%^layonhands%^WHITE%^ again.%^RESET%^");
    caster->remove_property("using layonhands");
    caster->set_property("using layonhands",delay);
    return;
}

void execute_attack()
{
    int amount;
    string dedication;
    object *effects;
    
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    
    if(caster->query_unconscious())
    {
        dest_effect();
        return;
    }
    if(!objectp(target) || !present(target,place))
    {
        tell_object(caster,"Your target has vanished!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^%^CYAN%^You concentrate deeply and touch "+(string)target->QCN+".%^RESET%^");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" touches "+(string)target->QCN+" and concentrates for a moment.%^RESET%^",({target,caster}));
    if(target != caster)
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" touches you and concentrates for a moment.%^RESET%^");
    
    amount = caster->query_guild_level("paladin") * 2;
    amount = 30 + roll_dice(amount, 6) + BONUS_D->query_stat_bonus(caster, "charisma");
    dedication = caster->query_dedication();
    
    //If used offensively, has to pass touch attack test
    if(member_array(target, caster->query_attackers()) >= 0 && BONUS_D->process_hit(caster, target, 1, 0, 0, 1) <= 0)
    {
        tell_object(caster, "You attempt to lay hands on your opponent but miss!");
        tell_object(target, caster->QCN + " attempts to lay hands on you but misses!");
        return;
    }
    
    //Undead paladins channel negative energy
    if(caster->query_property("negative energy affinity"))
        caster->cause_typed_damage(target, target->return_target_limb(), amount, "negative energy");
    else
        caster->cause_typed_damage(target, target->return_target_limb(), amount, "positive energy");
    
    if(dedication && target != caster->query_current_attacker())
    {
        string ename;
        
        tell_object(caster, "%^BOLD%^Your healing is enhanced through your dedication to those who are %^CYAN%^" + dedication +"%^WHITE%^.");
    
        if(dedication == "blinded")
        {
            target->set_blind(0);
            target->set_temporary_blinded(0);
            dest_effect();
            return;
        }
        if(dedication == "poisoned")
        {
            if(POISON_D->clear_poisons_by_dc(target, clevel, 0))
                tell_object(caster, "You are able to cleanse the poison and it fades away.");
            else
                tell_object(caster, "You were not able to cleanse the poison.");
            
            dest_effect();
            return;
        }
        
        effects = target->query_property("status_effects");
        
        //fatigued, exhausted, confused, dazzled, sickened, panicked, shaken
        foreach(object ef in effects)
        {
            ename = explode(ef->query_name(), "_")[1];
            if(ename = dedication)
            {
                ef->dest_effect();
                break;
            }
        }
    }
    
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(this_object());
    return;
}  