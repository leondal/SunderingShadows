#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Psionics");
    feat_name("armored manifester");
    feat_prereq("Psion or Psywarrior");
    feat_desc("The Armored Manifester feat will allow a psionic character to manifest their powers while wearing any type of armor. Please note that the character must still have the appropriate armor feats to wear various types of armor.");
    permanent(1);
    psionic(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }
    if(!ob->is_class("psion") && !ob->is_class("psywarrior")) {
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

