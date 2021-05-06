#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    set_author("tlaloc");
    feat_type("instant");
    feat_category("Psionics");
    feat_name("augment power");
    feat_prereq("Psion L31");
    feat_syntax("augment_power [AMOUNT]");
    feat_desc("This Meta Psionic feat will cause your next manifested power to be cast at a higher caster level, depending on the number of power points spent on the power. The conversion rate is 100 power points per caster level gained.");
    set_required_for(({ }));
}


int allow_shifted() { return 0; }


int prerequisites(object ob)
{
    
    if(!objectp(ob)) { return 0; }

    if(ob->query_class_level("psion") < 31)
    {
        dest_effect();
        return 0;
    }
    
    return ::prerequisites(ob);
}

int cmd_augment_power(string str)
{
    object feat;
    if(!objectp(this_player())) { return 0; }
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}


void execute_feat()
{
    object obj;
    string * elements;
    int amount;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    
    if(caster->cooldown("augment power"))
    {
        tell_object(caster, "You can't use augment power yet.");
        return;
    }
    
    if(!arg)
    {
        tell_object(caster, "You need to specify the amount of power points you want to use.");
        return;
    }
    
    amount = to_int(arg);
    
    if(amount > caster->query_mp())
    {
        tell_object(caster, "You don't have that many power points.");
        return;
    }

    ::execute_feat();

    caster->add_mp(-amount);
    amount = amount / 100;
    tell_object(caster, "You use your meta psionic knowledge to augment your next power.");
    caster->set_property("augment power", amount);
    caster->add_cooldown("augment power", 300);
    
    return;
}

void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property("empower spell");
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
