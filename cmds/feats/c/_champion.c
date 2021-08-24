#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Presence");
    feat_name("champion");
    feat_prereq("Paladin L20");
    feat_desc("The paladin becomes a rallying beacon for her cause and an object of awe for her enemies. She has become a guardian of her home and a bane to all who would invade. This feat grants the paladin an additional 5 damage reduction against enemies of the opposing alignment. In addition, her smite now banishes the souls of outsiders, of the opposing alignment, back to their home plane on a failed fortitude save.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob) {
   if(!objectp(ob)) { return 0; }

   if((int)ob->query_class_level("paladin") < 20) 
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

