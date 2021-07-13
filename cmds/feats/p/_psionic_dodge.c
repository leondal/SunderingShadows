#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

int mod, duration;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Psionics");
    feat_name("psionic dodge");
    feat_prereq("Psion or Psywarrior, Dodge Feat");
    psionic(1);
    feat_desc("A psionic manifester with this feat expends their Psionic Focus to gain additional armor class for a short duration. The amount of armor class gained increases as the manifester gains in power.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(!ob->is_class("psion") || !ob->is_class("psywarrior"))
    {
        dest_effect();
        return 0;
    }

    if(!FEATS_D->usable_feat(ob, "dodge"))
    {
        dest_effect();
        return 0;
    }

    return ::prerequisites(ob);
}

int cmd_psionic_dodge(string str)
{
    object feat;

    if(!objectp(this_player()))
        return 0;

    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(),str);
    return 1;
}

void execute_feat()
{
    ::execute_feat();

    if((int)caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    if(caster->query_property("psionic dodge"))
    {
        tell_object(caster,"You are already using psionic dodge!");
        dest_effect();
        return;
    }

    if(!USER_D->spend_pool(caster, 1, "focus"))
    {
        tell_object(caster, "You need to be focused before you can attempt Psionic Dodge.");
        return;
    }

    caster->set_property("using instant feat", 1);
    caster->set_property("psionic dodge", 1);

    tell_object(caster, "You expend your psionic focus and you feel your body begin to accelerate.");
    tell_object(caster, "%^CYAN%^BOLD%^Your body picks up speed and your reflexes become enhanced.%^RESET%^");

    mod = 4 + flevel / 12;
    duration = (5 + flevel / 5 + BONUS_D->query_stat_bonus(caster, "intelligence")) * ROUND_LENGTH;

    caster->add_ac_bonus(mod);
    call_out("dest_effect", duration);
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

void dest_effect()
{
    if(caster)
    {
        caster->add_ac_bonus(-mod);
        caster->remove_property("psionic dodge");
        tell_object(caster, "You feel the effects of psionic dodge fading from you.");
    }

    ::dest_effect();
    remove_feat(TO);
    return;
}
