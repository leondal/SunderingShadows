#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Presence");
    feat_name("aura of justification");
    feat_prereq("Paladin L17");
    feat_desc("A paladin who is heavily steeped in their cause can justify almost any action performed in service of that cause. With this feat, the paladin and her comrades gain protection from those opposed to the chosen cause of the paladin. The paladin and her party members gain 5 Damage Reduction when fighting enemies of the paladin's opposing alignment. The paladin gains an additional +5 damage reduction if the opponent is their polar opposite alignment.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob) {
   if(!objectp(ob)) { return 0; }

   if((int)ob->query_class_level("paladin") < 17) 
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
    remove_feat(this_object());
    return;
}

