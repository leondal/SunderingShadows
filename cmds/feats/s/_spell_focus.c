#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("MagicAccuracy");
    feat_name("spell focus");
    feat_desc("Spell Focus is a feat that will allow the caster a better chance to bypass the saving throws of the target. It adds +1 to all of your spell DCs.");
    permanent(1);
    set_required_for(({"perfect caster","spell penetration","greater spell penetration","armored caster","eschew materials"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    string *classes,file;
    int i;
    if(!objectp(ob)) { return 0; }

    classes = (string *)ob->query_classes();
    for(i=0;i<sizeof(classes);i++)
    {
        file = DIR_CLASSES+"/"+classes[i]+".c";
        if(file->caster_class()) { return ::prerequisites(ob); }
    }
    return 0;
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

