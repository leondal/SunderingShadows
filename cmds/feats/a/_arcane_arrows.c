#include <std.h>
#include <daemons.h>

inherit FEAT;

#define ELEMENTS ({"acid","cold","fire","sonic"})
#define COLORS (["acid":"%^BOLD%^%^GREEN%^",\
        "cold":"%^BOLD%^%^BLUE%^",\
        "fire":"%^BOLD%^%^RED%^",\
        "sonic":"%^BOLD%^%^CYAN%^"])

void create() 
{
    ::create();
    feat_type("instant");
    feat_category("ArcaneArcher");
    feat_name("arcane arrows");
    feat_syntax("arcane_arrows [acid|cold|fire|sonic]");
    feat_desc("With knowledge of the arcane caster imbues her projectiles, placing simple elemental spell onto them. When struck, such projectiles have a chance to explode with raw elemental damage. Without an argument, this feat will apply fire damage.");
    permanent(1);
}

int allow_shifted() { return 0; }

int cmd_arcane_arrows(string str)
{
    string element;
    if(member_array(str,ELEMENTS)==-1)
    {
        element = "fire";
    } else {
        element = str;
    }
    write("%^BOLD%^%^BLACK%^Arcane arrows are set to cause "+COLORS[element]+element+"%^RESET%^%^BOLD%^%^BLACK%^ damage.");
    TP->remove_property("arcane arrows");
    TP->set_property("arcane arrows", element);
    return 1;
}

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("arcane_archer") < 1)
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

