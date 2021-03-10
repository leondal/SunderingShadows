#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Presence");
    feat_name("aura of fury");
    feat_prereq("Paladin L11");
    feat_desc("Paladins are known for their fury in battle, along with their ability to inspire the fury of those around them. When the paladin uses her smite on her enemies, the members of her party also smite her foes with their own fury. This causes each member of the paladin's party to gain a +2 damage bonus against the paladin's smite target.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob) {
   if(!objectp(ob)) { return 0; }

   if((int)ob->query_class_level("paladin") < 11) 
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

