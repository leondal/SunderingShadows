#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
   ::create();
   feat_type("permanent");
   feat_category("ArmorMastery");
   feat_name("medium armor proficiency");
   feat_prereq("Light armor proficiency");
   feat_desc("Medium Armor Proficiency is a passive feat that allows the use of various types of mail, including chain, ring, scale, splint, and banded. It also allows the use of brigandine armor and breastplates. Requires light armor proficiency feat.");
   permanent(1);
   set_required_for(({"heavy armor proficiency","shield proficiency"}));
}

int allow_shifted() { return 1; }

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

int prerequisites(object ob)
{
    if(!objectp(ob)) {return 0; }

    if(!FEATS_D->has_feat(ob,"light armor proficiency"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
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
