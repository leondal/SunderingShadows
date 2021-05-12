#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int mod, duration, extra;
void check();


void create()
{
    ::create();
    feat_type("instant");
    feat_category("Psionics");
    feat_name("combatprescience");
    feat_prereq("Psywarrior L1");
    feat_syntax("combatprescience");
    feat_classes("psywarrior");
    feat_desc("This feat allows the psywarrior to use her mental prowess to gain insight into battle, granting her bonuses to attack and damage rolls and giving her a chance to slip in extra attacks. The feat grows in both strength and opportunities for extra attacks as the psywarrior gains levels and intelligence. This feat requires you to spend your Psionic Focus.");
    set_target_required(0);
    allow_blind(1);
    psionic(1);
    extra = 0;
}


int allow_shifted() { return 0; }


int prerequisites(object ob)
{
    if(!objectp(ob)) return 0;
    if(ob->query_class_level("psywarrior") < 1)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}


int cmd_combatprescience(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}


void execute_feat()
{
    int i,intelligence;
    if((int)caster->query_property("prescienced"))
    { //won't stack with the Prescience power
        tell_object(caster,"You are already enjoying the effects of prescience!");
        TO->remove();
        return;
    }
    
    if(!USER_D->spend_pool(caster, 1, "focus"))
    {
        tell_object(caster, "You must have psionic focus to use combatprescience!");
        dest_effect();
        return;
    }
    ::execute_feat();

    if((int)caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    caster->set_property("using instant feat",1);
    tell_object(caster,"%^RESET%^%^ORANGE%^You pluck the very essence of "
        "planning from the air around you, giving you insight into battle.%^RESET%^");
    tell_room(place,"%^RESET%^%^ORANGE%^Strange symbols flash in "
        ""+caster->QCN+"'s eyes as "+caster->QS+" gives a warcry.%^RESET%^",caster);

    //Should be 5 most of the time (except real low level) - new BAB adjustment
    //This should bridge the gap between 3/4 BAB to full BAB
    mod = caster->query_level() - BONUS_D->new_bab(caster->query_base_level(), caster); //5

    if(FEATS_D->usable_feat(caster,"battle psyche")) //10
        mod += 5;

    caster->add_attack_bonus(mod); //+10
    caster->add_damage_bonus(mod); //+10

    duration = 2 * (mod + BONUS_D->query_stat_bonus("intelligence", caster));
    duration *= ROUND_LENGTH;
    caster->set_property("prescienced",1);
    call_out("check",ROUND_LENGTH);
    call_out("dest_effect",duration);
    return;
}


void execute_attack()
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
}


void check()
{
    int mylvl;
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
//    tell_object(caster,"%^B_BLUE%^%^BOLD%^%^GREEN%^Check has been called!%^RESET%^");
// above message was for debugging. Leaving commented out for now, just in case it's needed later.

    mylvl = flevel;
    ::execute_attack();
    if(sizeof(caster->query_attackers()))
    {
        if(mylvl > 30)
        {
            tell_object(caster,"%^BOLD%^%^RED%^Your battle prowess and outstanding "
                "insight guide your hand, letting you slip in a quick attack!%^RESET%^");
            caster->execute_attack();
            if(!random(2))
            {
                tell_object(caster,"%^BOLD%^%^RED%^With unbelievable speed, "
                    "you make a second surprise attack!%^RESET%^");
                caster->execute_attack();
            }
        }
        else if(mylvl > 20)
        {
            tell_object(caster,"%^RESET%^%^RED%^Your insight guides your "
                "hand, and you slip in a quick attack!%^RESET%^");
            caster->execute_attack();
        }
        else if(mylvl > 10)
        {
            if(!random(2))
            {
                tell_object(caster,"%^RESET%^%^RED%^Your insight guides your "
                    "hand, and you slip in a quick attack!%^RESET%^");
                caster->execute_attack();
            }
        }
        if(FEATS_D->usable_feat(caster, "battle psyche"))
        {
            tell_object(caster,"%^BOLD%^%^RED%^Your mental dedication to battle guides "
                "you into an opening for a perfect strike!");
            caster->execute_attack();
        }
    }
    call_out("check",ROUND_LENGTH);
}


void dest_effect()
{
    ::dest_effect();
    if(!objectp(caster))
    {
        remove_feat(TO);
        return;
    }
    tell_object(caster,"%^RESET%^%^ORANGE%^Your insight into battle fades, leaving you feeling slightly disoriented.%^RESET%^");
    caster->add_attack_bonus(-mod);
    caster->add_damage_bonus(-mod);
    caster->remove_property("prescienced");
    remove_feat(TO);
    return;
}
