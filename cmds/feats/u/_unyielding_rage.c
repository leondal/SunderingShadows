#include <std.h>
#include <daemons.h>
inherit FEAT;

void create()
{
   ::create();
   feat_type("permanent");
   feat_category("RagePower");
   feat_name("unyielding rage");
   feat_prereq("Barbarian L20");
   feat_desc("This feat allows the barbarian to avoid death's door whilst raging. After avoiding mortal death the barbarian will be unable to do so again for some time.");
   permanent(1);
   allow_blind(1);
   set_required_for(({}));
}

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("barbarian") < 20) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
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

void execute_feat()
{
   ::execute_feat();
   dest_effect();
}

void dest_effect()
{
   ::dest_effect();
   remove_feat(TO);
   return;
}
