#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("PrestigeDuelist");
    feat_name("elaborate parry");
    feat_prereq("Duelist L7");
    feat_desc(""
"Anyone who strikes at the trained duelist had better be prepared for the " +
"inevitable repercussions. The duelist is trained to punish anyone who attacks " +
"without thinking of their own defenses. This feat adds counter attacks to " +
"your parries. (Parry or Opportunistic Parry). In addition, your counter attacks will " + 
"do more damage the more you shift your Expertise towards defense. This feat only works in light or " +
"no armor.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("duelist") < 7)
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