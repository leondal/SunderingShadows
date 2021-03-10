#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("PrestigeDuelist");
    feat_name("canny defense");
    feat_prereq("Duelist L1");
    feat_desc(""
"It is said that knowing your self and knowing your enemy will lead "
"to victory in a thousand battles. The duelist relies not only on the "
"quickness of their arm, or the discipline of their form, but also on "
"the sharpness of the mind to anticipate their opponents' moves. "
"This feat adds your intelligence modifier to your passive armor class "
"while wearing light or no armor and while not incapacitated. In addition "
"The duelist gains +4 to their reflex saves.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("duelist") < 1)
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