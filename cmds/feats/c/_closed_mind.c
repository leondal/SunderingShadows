#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Psionics");
    feat_name("closed mind");
    feat_prereq("Psywarrior L1 or Psion L1");
    feat_desc("Your mind is better able to resist psionics than normal. You gain +2 to all saving throws against powers and spells.");
    permanent(1);
    allow_blind(1);
    psionic(1);
}

int allow_shifted()
{
    return 1;
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!(ob->is_class("psywarrior") ||
          ob->is_class("psion"))) {
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
