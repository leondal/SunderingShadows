#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("HellfireWarlock");
    feat_name("infernal practitioner");
    feat_prereq("Hellfire warlock L4, No Fear of The Flame");
    feat_desc("The warlock gains several new invocations which harness his or her command of hellfire. The invocations 'hellfire shield', 'infernal rain', 'infernal healing', 'fire storm', 'fiery body' and 'hurl through hell' are added to the known spell list.");
    permanent(1);
    set_required_for(({"hellfire blast"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("hellfire_warlock") < 4 || !FEATS_D->usable_feat(ob,"no fear of the flame"))
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

