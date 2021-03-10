#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("KiEnhancement");
    feat_name("elemental opportunist");
    feat_prereq("Monk L15, Way of The Elements or Grandmaster of The Way");
    feat_desc("This feat allows a monk who is dedicated to the way of the elements the chance when using any elemental combat spell, to summon an elemental guardian of her current elemental focus. This guardian will follow the monk for as long as it lives. The effect is beyond the control of the particular monk and the guardian does not accept commands. 

%^BOLD%^N.B.%^RESET%^ This effect will have a chance of happening when using any offensive elemental monk spell, the chance increases slightly by level, as well as the power of the summoned guardian. This feat only functions while unarmored.");
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
   if(((string)ob->query("monk way") != "way of the elements") && !FEATS_D->usable_feat(ob, "grandmaster of the way"))
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
