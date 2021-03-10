#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("KiEnhancement");
    feat_name("shadow opportunist");
    feat_prereq("Monl L15, Way of The Shadow or Grandmaster of The Way");
    feat_desc("This feat further increases the chance of flurry of blows landing a second attack. It represents the ability for a monk dedicated to the way of the shadow being able to discern openings in the defenses of their opponents that others often miss. NOTE: This feat only functions while unarmored.");
    permanent(1);
    set_required_for(({}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
   if(!objectp(ob)) { return 0; }

   if((int)ob->query_class_level("monk") < 15 || (int)ob->query_alignment() > 3)
   {
      dest_effect();
      return 0;
   }
   if(((string)ob->query("monk way") != "way of the shadow") && !FEATS_D->usable_feat(ob,"grandmaster of the way"))
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

int help() {
    write("%^RESET%^%^BOLD%^Name:           Shadow Opportunist\n"
          "%^RESET%^%^BOLD%^Type:           %^GREEN%^Permanent\n"
          "%^RESET%^%^BOLD%^Syntax:         %^RESET%^None\n"
          "%^RESET%^%^BOLD%^Prerequisites:  %^RESET%^L15 Monk\n"
          "%^RESET%^%^BOLD%^                %^RESET%^Way of The Shadow\n\n"
        "%^RESET%^%^BOLD%^\tThis feat further increases the chance of flurry "
        "of blows landing a second attack. It represents the ability for a monk "
        "dedicated to the way of the shadow being able to discern openings in the "
        "defenses of their opponents that others often miss. "
        "NOTE: This feat only functions while unarmored.");
    return 1;
}
