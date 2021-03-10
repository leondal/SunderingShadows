/*
  _improved_quarry.c
  
  Ranger feat from PFSRD.
  
  Makes the quarry command better.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

object feat;

void create()
{
    ::create();
    
    set_author("tlaloc");
    feat_type("permanent");
    feat_prereq("Ranger L18");
    feat_category("WildernessLore");
    feat_name("improved quarry");
    feat_desc("This feat makes your quarry better by providing an additional "+
"+2 to attack and damage rolls against them. You also will never fail to track your quarry " +
"unless they are also a Ranger.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("ranger") < 18)
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