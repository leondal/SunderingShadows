/*
  _smite.c
  
  Rewrite for Paladin remap. Now does lower base damage
  and is not AOE, but does bonus damage based on target
  alignment. Also adds chamod to attacks against target
  for a number of rounds if opposed alignment.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <favored_types.h>

inherit FEAT;

#define FEATTIMER 40

void finish_smite(object you, object me);

void create()
{
    ::create();
    feat_type("insant");
    feat_name("smite");
    feat_category("Presence");
    feat_syntax("smite [TARGET]");
    feat_prereq("Paladin L1");
    feat_classes("paladin");
    set_save("fort");
    feat_desc("With this feat, the paladin calls out to the powers of her beliefs to aid her in battle against those who oppose those beliefs. This results in an initial burst of divine damage against her primary attacker. If that enemy is of an opposed alignment, the damage is increased and the enemy becomes vulnerable to the paladin's attacks. For a few rounds, the paladin's attacks do additional damage based on her charisma modifier. Smite costs one Divine Grace point to use.");
}

int prerequisites(object ob)
{
    if(ob->query_class_level("paladin") < 1)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_smite(string str)
{
    object feat;
    
    if(!objectp(this_player()))
        return 0;
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(),"");
    return 1;
}

void execute_feat()
{
    int delay;

    if(!sizeof(caster->query_attackers()))
    {
        tell_object(caster,"You're not under attack!");
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }   
    if(!(int)USER_D->spend_pool(TP, 1, "grace"))
    {
        tell_object(caster, "You don't have the Divine Grace to Smite your foe!");
        return;
    }
    
    ::execute_feat();
    
    tell_object(caster, "%^BOLD%^You prepare to smite your foe with divine energy.%^RESET%^");
    
    //delay = time() + FEATTIMER;
    //delay_messid_msg(FEATTIMER,"%^BOLD%^%^WHITE%^You can %^CYAN%^smite%^WHITE%^ again.%^RESET%^");
    caster->set_property("using instant feat",1);
    caster->remove_property("using smite");
    caster->set_property("using smite",delay);
}

void execute_attack()
{
    int dam, mod, glvl, opposed;
    object target, attackers;
    
    if(!caster || caster->query_unconscious())
    {
        dest_effect();
        return;
    }
    
    caster->remove_property("using instant feat");
    ::execute_attack();
    
    if(!target)
        target = caster->query_current_attacker();
    
    if(!target)
        return;
    
    //Smites do not stack
    target->remove_property("paladin smite");
    
    glvl = caster->query_guild_level("paladin");
    mod = BONUS_D->query_stat_bonus(caster, "charisma");
    dam = 5 + roll_dice(glvl / 2, 8) + mod;
    opposed = opposed_alignment(caster, target);
    
    //Does double damage against opposed, triple damage against polar opposite
    //Opposed alignment also gets smite debuff that adds CHA bonus to this paladin's
    //attacks against it.
    if(opposed)
    {
        dam += dam * opposed;
        target->set_property("paladin smite", caster);
        
        //Smite banishes opposing outsiders when paladin has champion feat (non-players)
        if(FEATS_D->usable_feat(caster, "champion"))
        {
            if(member_array(target->query_race(), VALID_ENEMY["outsiders"]) >= 0 && 
            !userp(target) &&
            !do_save(target, 0) && 
            caster->query_level() + 10 >= target->query_level())
            {
                tell_object(caster, "You smite your opponent, banishing their soul back to their home plane!");
                tell_room(place, caster->QCN + " smites " + target->QCN + ", banishing their soul back to their home plane!", ({ caster }));
                target->set_hp(-100);
                return;
            }
        }
    }
    
    caster->set_property("magic", 1);
    tell_object(caster, "%^BOLD%^CYAN%^With a shout of your convictions, you unleash divine energy upon your foe!%^RESET%^");
    tell_room(place, "%^BOLD%^CYAN%^" + caster->QCN + " lets out a shout and strikes down " + caster->query_possessive() + " foe with divine energy!%^RESET%^", ({ caster }));
    caster->cause_typed_damage(target, "head", dam, "divine");
    caster->set_property("magic", -1);
    
    call_out("finish_smite", ROUND_LENGTH * 5, target, caster);
}

void finish_smite(object you, object me)
{
    if(you)
    {
        if(you->query_property("paladin smite"))
        {
            you->remove_property("paladin smite");
            tell_object(you, "%^BOLD%^You feel the paladin's smite fade from you.%^RESET%^");
            me && tell_object(me, "%^BOLD%^Your divine smite fades from your foe.%^RESET%^");
        }
    }
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
}