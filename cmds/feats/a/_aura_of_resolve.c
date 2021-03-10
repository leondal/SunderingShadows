#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Presence");
    feat_name("aura of resolve");
    feat_prereq("Paladin L8");
    feat_desc("Paladins are known for their unbreakable resolve when taking up a cause. The influences of others will not shake them or steer them away from their chosen path. Their companions can rely on the paladin to provide a solid rock on which to cling in times of trouble. This feat gives the paladin immunity to charm effects and gives their party +2 on will saves vs charm effects.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob) {
   if(!objectp(ob)) { return 0; }

   if((int)ob->query_class_level("paladin") < 8) 
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

