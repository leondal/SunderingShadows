#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("PrestigeDuelist");
    feat_name("artful precision");
    feat_prereq("Duelist L4");
    feat_desc(""
"Strike with purpose, strike with discipline and strike with precision. "
"The duelist carries this mantra with them wherever they go, seeking to "
"end battles seemingly before they start. The duelist has mastered the art "
"of striking their opponents in the most vulnerable spots. This feat adds "
"additional damage to the duelist's opportunistic strikes.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("duelist") < 4)
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
    remove_feat(this_object());
    return;
}