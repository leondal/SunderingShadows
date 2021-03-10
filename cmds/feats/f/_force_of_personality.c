#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Presence");
    feat_name("force of personality");
    feat_desc("This passive feat grants an additional amount equivalent to the character's charisma bonus (maximum +5), to all of their saving throws.");
    feat_prereq("Indomitable");
    permanent(1);
    set_required_for(({"unyielding soul","leadership"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob))
        return 0;
    if (!FEATS_D->has_feat(ob, "indomitable") && !ob->is_class("inquisitor")) {
        dest_effect();
        return 0;
    }
    return::prerequisites(ob);
}

void execute_feat(){
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob){
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob){
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
