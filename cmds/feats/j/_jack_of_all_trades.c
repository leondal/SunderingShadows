#include <std.h>
#include <daemons.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Performance");
    feat_name("jack of all trades");
    feat_prereq("Bard L21");
    feat_desc("With this feat, the bard treats all skills as class skills.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob)
{
   if(!objectp(ob)) { return 0; }

   if((int)ob->query_class_level("bard") < 21)
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
