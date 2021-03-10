#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("KiEnhancement");
    feat_name("fists of fury");
    feat_prereq("Monk L15, Way of The Fist or Grandmaster of The Way");
    feat_desc("This feat allows a monk dedicated to the way of the  fist to add an additional 1d2 damage when making unarmed attacks.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob) 
{
   if(!objectp(ob)) { return 0; }

   if((int)ob->query_class_level("monk") < 15 || (int)ob->query_alignment() > 3) 
   {
      dest_effect();
      return 0;
   }
   if(((string)ob->query("monk way") != "way of the fist") && !FEATS_D->usable_feat(ob,"grandmaster of the way"))
   {
       dest_effect();
       return 0;
   }
   if(sizeof((object *)ob->query_wielded()))
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

