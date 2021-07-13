/*
  _alter_the_waves.c

  Seer feat.

  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

int bonus;

void create()
{
    ::create();
    feat_type("active");
    feat_category("Psionics");
    feat_name("alter the waves");
    feat_prereq("Psion (Seer) L11");
    feat_syntax("alter_the_waves");
    feat_desc("A seer with this power can slightly alter the strands of time, slightly altering the waves of causality to render a slight advantage to themselves. With this feat, the Seer will gain a slight bonus to Armor Class, Damage Resistance, Attack Roll, and Miss Chance. This feat consumes the psion's focus.");
    psionic(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;

    if(ob->query_class_level("psion") < 11)
    {
        dest_effect();
        return 0;
    }

    if(ob->query_discipline() != "seer")
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_alter_the_waves(string str)
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
    int mod;

    ::execute_feat();

    if(!caster)
        return;

    if(!USER_D->spend_pool(caster, 1, "focus"))
    {
        tell_object(caster, "You need to be focused to use alter the waves.");
        return;
    }

   if ((int)caster->query_property("using instant feat"))
   {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    if(caster->query_property("alter the waves"))
    {
        tell_object(caster, "You are already under the effects of alter the waves.");
        dest_effect();
        return;
    }

    tell_object(caster, "%^CYAN%^BOLD%^You place your finger upon your temple and look into the immediate future!%^RESET%^");
    tell_room(place, caster->QCN + " places a finger upon their temple and concentrates!", ({ caster }));

    mod = 5 + caster->query_prestige_level("psion") / 10;
    mod += BONUS_D->query_stat_bonus(caster, "intelligence");
    bonus = 3 + caster->query_prestige_level("psion") / 21;

    caster->set_property("alter the waves", 1);
    caster->add_attack_bonus(bonus);
    caster->add_ac_bonus(bonus);
    caster->set_property("damage resistance", bonus);
    caster->set_missChance(caster->query_missChance() + bonus);

    caster->set_property("using instant feat", 1);
    call_out("dest_effect", mod * ROUND_LENGTH);
}

void execute_attack()
{
    caster->remove_property("using instant feat");
}

void dest_effect()
{
    if(caster)
    {
        caster->add_attack_bonus(-bonus);
        caster->add_ac_bonus(-bonus);
        caster->set_property("damage resistance", -bonus);
        caster->set_missChance(caster->query_missChance() - bonus);
        caster->remove_property("alter the waves");
        tell_object(caster, "%^BOLD%^You stop altering the waves of causality.%^RESET%^");
    }

    ::dest_effect();
    remove_feat(TO);
    return;
}
