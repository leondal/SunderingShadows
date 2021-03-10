#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("ShadowAdept");
    feat_name("gift of the shadows");
    feat_prereq("Shadow adept L1");
    feat_desc("A shadow adept gains ability to store spells in his shadow, more reliable than an archmage, gaining additional four spell slots per level. In addition to that, he will have some shadow themed spells always mastered:

umbral sight, shield of shadows, shadow vortex, night armor, darkbolt, shadow blast, shadow double, nightmare maw, shadow nova");
    permanent(1);
    set_required_for(({"shadow defense",}));
}

int allow_shifted() {return 1;}

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("shadow_adept") < 1)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

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
