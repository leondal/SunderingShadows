#include <std.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() {
    ::create();
    feat_type("premanent");
    feat_category("Archdruid");
    feat_name("wild shape elemental");
    feat_prereq("Archdruid L1");
    feat_syntax("shapeshift elemental [| VARIANT]");
    feat_prereq("Having this feat will allow the character access to the shapeshift feat. The shapeshift feat is used to change into animal form. <shapeshift elemental> will transform the user into an elemental. While the elemental is not possessed of powerful melee abilities, it is somewhat resilient against the damages and magic of the material plane, and commands a powerful affinity for spellcraft. This form does not require the 'wild spellcraft' feat to be able to cast, and allows the casting of targetted and offensive spell types while shapeshifted, as well as the use of the <surge> command.");
    permanent(1);
    allow_blind(1);
}

int allow_shifted() { return 1; }

void execute_feat() {
    ::execute_feat();
    dest_effect();
}

int prerequisites(object ob) 
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("archdruid") < 1) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void permanent_effects(object ob) {
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob) {
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}

