#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Evasion");
    feat_name("tools of the trade");
    feat_prereq("Thief L10, Bard L10");
    feat_desc("This feat represents a knack for using items that would befuddle a normal person. Such rogue-ish tactics include the use of powder, caltrops, smoke bombs, and other trickery both in and out of combat.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob) {
   if(!objectp(ob)) { return 0; }

   if((int)ob->query_class_level("thief") < 10 && (int)ob->query_class_level("bard") < 10) {
      dest_effect();
      return 0;
   }
   return ::prerequisites(ob);
}

void execute_feat() {
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
