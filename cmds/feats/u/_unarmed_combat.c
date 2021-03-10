#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("UnarmedCombat");
    feat_name("unarmed combat");
    feat_prereq("Dexterity 15 or Strength 15, Not Monk");
    feat_desc("This feat represents a better than average ability to fight without a weapon. A character that takes this feat will do 1d6 base damage through level 20 when fighting unarmed, this increases to 1d8 from level 21 to 30, and to 1d10 after level 30. A monk, by default uses a higher damage table and cannot take this feat.

NOTE: this feat does not apply to shapeshift forms, which have their own base damage table for natural weapons where appropriate.");
    permanent(1);
    set_required_for(({"spinning kick"}));
}

int prerequisites(object ob) 
{
    if(!objectp(ob)) { return 0; }
    if((int)ob->query_base_stats("dexterity") < 15 && (int)ob->query_base_stats("strength") < 15)
    {
        dest_effect();
        return 0;
    }
    if((int)ob->is_class("monk")) 
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

