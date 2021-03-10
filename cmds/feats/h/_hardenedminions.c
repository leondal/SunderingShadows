#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("MagicDamage");
    feat_name("hardenedminions");
    feat_syntax("hardenedminions");
    feat_prereq("Spell power");
    feat_desc("This feat will greatly improve any minions that you might have. They will grow to double size and become stronger in all regards. Please note that the bonus your minions receive is less based on the number of minions you currently have. This feat will only impact the first ten minions. As your minions die or vanish the bonus will be applied to the remaining ones.");
    set_target_required(0);
    allow_blind(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(!FEATS_D->has_feat(ob,"spell power"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_hardenedminions(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,"");
    return 1;
}

void execute_feat()
{
    if(FEATS_D->is_active(caster,"hardenedminions"))
    {
        tell_object(caster,"Your minions are already strengthened.");
        dest_effect();
        return;
    }
    ::execute_feat();

    tell_object(caster,"%^BOLD%^You close your eyes and concentrate, letting your will lend "
        "strength to your minions%^RESET%^");

    caster->set_property("active_feats",({TO}));

    call_out("execute_me",3);

    return;
}

int phantom_filter(object obj)
{
    if(!objectp(obj)) { return 0; }
    if(obj->id("phantom")) { return 1; }
    if(obj->id("psychic warrior")) { return 1; }
    if(obj->id("illusion")) { return 1; }
    if(obj->id("vampire bat")) { return 1; }
    return 0;
}

int adjust_minion(object minion, int bonus, int hpbonus)
{
    int cur_bonus, y = 1;
    if(!objectp(minion)) return 0;
    if(minion->query_property("hardened_minion"))
    {
        y = 0;
        cur_bonus = (int)minion->query_property("hardened_minion_bonus");
        if(cur_bonus != bonus)
        {
            minion->add_ac_bonus(-cur_bonus);
            minion->add_stat_bonus("strength", -cur_bonus);
            minion->add_stat_bonus("dexterity", -cur_bonus);
            minion->add_extra_hp(-(int)minion->query_property("hardened_minion_hpbonus"));
            minion->add_attack_bonus(-cur_bonus);
            minion->add_damage_bonus(-cur_bonus);
            minion->set_property("damage resistance", -cur_bonus);
            minion->remove_property("hardened_minion_bonus");
            minion->remove_property("hardened_minion_hpbonus");
            minion->remove_property("added short");
        }
        else return 0;
    }
    if(!minion->query_property("hardened_minion")) minion->set_property("hardened_minion", 1);
    minion->add_ac_bonus(bonus);
    minion->add_stat_bonus("strength",bonus);
    minion->add_stat_bonus("dexterity",bonus);
    minion->add_extra_hp(hpbonus);
    minion->add_attack_bonus(bonus);
    minion->add_damage_bonus(bonus);
    minion->set_property("damage resistance",bonus);
    minion->set_property("hardened_minion_bonus", bonus);
    minion->set_property("hardened_minion_hpbonus", hpbonus);
    return y;
}

void execute_me()
{
    object *minions,*followers, *minions_to_impact;
    int i,bonus, hpbonus, count, rb, rhpb, x;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(!objectp(environment(caster)))
    {
        caster->remove_property_value("active_feats",({TO}));
        dest_effect();
        return;
    }
    if(!FEATS_D->usable_feat(caster,"hardenedminions"))
    {
        dest_effect();
        return;
    }

    minions   = all_inventory(environment(caster));
    minions   = filter_array(minions,"phantom_filter",TO);
    minions   += all_living(environment(caster));
    followers = (object *)caster->query_followers();
    bonus     = (int)caster->query_highest_level() + caster->query_property("empowered");
    bonus     = (bonus / 10) + 1;
    hpbonus   = bonus*20;
    //Attempting to recode this so that the bonus to monsters is less based on the number of
    //them that exist - Saide

    //first 1 - 3 fodder get the full bonus
    //next 4 - 6 fodder get half the bonus
    //next 7 - 10 fodder get 1/3 the bonus
    //greater than 10 get no bonus - Saide
    minions_to_impact = ({});
    for(i=0;i<sizeof(minions);i++)
    {
        if(count > 10) break;
        if(!objectp(minions[i])) { continue; }
        if(interactive(minions[i])) { continue; }
        if(minions[i]->query_property("no detect")) { continue; }
        if(minions[i] == caster) { continue; }
        //if(minions[i]->query_property("")
        if(member_array(minions[i],followers) == -1) { continue; }
        if(minions[i]->is_merc()) { continue; }
        if(base_name(minions[i]) == "/d/token_hunt/token_monster") { continue; }
        if(minions[i]->query_property("minion") != caster && !minions[i]->query_property("spell_creature")) { continue; }
        if(minions[i]->query_property("hardened_minion"))
        {
            count++;
            minions_to_impact += ({minions[i]});
            continue;
        }
        count++;
        minions_to_impact += ({minions[i]});
    }

    for(i=0;i<sizeof(minions_to_impact);i++)
    {
        if(i < 3)
        {
            rb = bonus;
            rhpb = hpbonus;
        }
        else if(i < 6)
        {
            rb = bonus/2;
            rhpb = hpbonus/2;
        }
        else if(i <= 9)
        {
            rb = bonus/3;
            rhpb = hpbonus/3;
        }
        else
        {
            rb = 0;
            rhpb = 0;
        }
        x = adjust_minion(minions_to_impact[i], rb, rhpb);
        if(rb > 0 && x)
        {
            tell_object(caster,"%^BOLD%^%^YELLOW%^Your "+minions[i]->QCN+" grows to double "
            ""+minions_to_impact[i]->QP+" normal size and begins to glow!%^RESET%^");
            tell_room(environment(caster),"%^BOLD%^%^YELLOW%^"+minions[i]->QCN+" grows to "
            "double "+minions_to_impact[i]->QP+" size and begins to glow!%^RESET%^",caster);
        }
    }

    //environment(caster)->addObjectToCombatCycle(TO,1);
    call_out("execute_me",3);

    //::execute_attack();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
