#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Presence");
    feat_name("unyielding soul");
    feat_prereq("Force of personality");
    feat_desc("This feat is a mark of those with such a powerful force of personality that they are sometimes able to repel mind-controlling effects. Instead, they simply take an amount of damage based upon the power of the spell itself.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"force of personality")) {
      dest_effect();
      return 0;
    }
    //Undead players don't need this, preventing them from making a mistake
    if(ob->is_undead())
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
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
