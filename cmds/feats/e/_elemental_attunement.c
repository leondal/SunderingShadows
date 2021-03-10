#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("KiEnhancement");
    feat_name("elemental attunement");
    feat_prereq("Monk L10, Way of The Elements or Grandmaster of The Way");
    feat_desc("This feat represents an even further attunement with the elements, granting an additional +5 to caster level when using monk spells.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob) 
{
   if(!objectp(ob)) { return 0; }

   if((int)ob->query_class_level("monk") < 10) 
   {
      dest_effect();
      return 0;
   }
   if(((string)ob->query("monk way") != "way of the elements") && !FEATS_D->usable_feat(ob,"grandmaster of the way"))
   {
       dest_effect();
       return 0;
   }
   if(!ob->is_ok_armour("barb"))
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

