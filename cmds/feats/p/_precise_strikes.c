#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("UnarmedCombat");
    feat_name("precise strikes");
    feat_prereq("Improved Rapid Strikes and Not Monk");
    feat_desc("This feat grants a character who is unarmed an effective enchantment of +1/per 8 levels. This feat DOES NOT stack with the monk unarmed enchantment bonus, or the enchanted fists feat available to way of the fists monks. Thus, it is not available to monks.");
    permanent(1);
    set_required_for(({}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) {return 0; }
    if(!FEATS_D->has_feat(ob,"improved rapid strikes") || ob->is_class("monk"))
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

