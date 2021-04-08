#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Presence");
    feat_name("leadership");
    //feat_prereq("Force of personality");
    feat_desc("This feat represents the pinnacle of renown for a character, allowing them to attract a number of loyal followers based upon their influence skill.

%^BOLD%^%^WHITE%^See also:%^RESET%^ follower.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob))
        return 0;
    //if (!FEATS_D->has_feat(ob, "force of personality")) {
    //    dest_effect();
    //    return 0;
    //}
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
