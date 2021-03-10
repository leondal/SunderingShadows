#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

int FLAG;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("NonCombat");
    feat_name("skill focus");
    feat_desc("Skill Focus allows the selection of one non-class skill, which the character will then be skilled at as per a class skill.

%^BOLD%^N.B.%^RESET%^ If multiclassing in future causes the skill to be a class skill (skill on the class helpfile), this feat will have no effect. It must be abandoned and regained in order to select a different skill focus. Crafting skills cannot be taken by way of this feat."+(FEATS_D->usable_feat(TP,"skill focus")?"

"+"%^YELLOW%^You have chosen your skill focus as: %^BOLD%^%^WHITE%^"+TP->query("skill_focus")+".":""));
    permanent(1);
}

int allow_shifted() { return 1; }

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
