#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("VersatileArcanist");
    feat_name("master of versatility");
    feat_prereq("Versatile arcanist L7");
    feat_desc("A versatile arcanist with master of versatility is able to effortlessly transition in his mind the arcane energies necessary for one level of power into another, such that he can combine or disassemble power levels to create the precise amount of energy needed. What this means is that if a versatile arcanist runs out of 9th level powers to cast then she instead can combine an 8th and 1st level power to form the necessary energy required. This happens automatically and effortlessly for a master of versatility.");
    permanent(1);
    //set_required_for(({""}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("versatile_arcanist") < 7)
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
