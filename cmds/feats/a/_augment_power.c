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
    feat_prereq("Psion or Psywarrior");
    feat_syntax("augment_power");
    feat_desc("This Psionic feat will cause your next manifested power to be cast at a +4 caster level. Using this feat requires you to be focused and will expend your psionic focus.");
    set_required_for(({ }));
}


int allow_shifted() { return 1; }


int prerequisites(object ob)
{

    if(!objectp(ob)) { return 0; }

    if(!ob->is_class("psion") && !ob->is_class("psywarrior"))
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

    amount = 30;

    if(amount > caster->query_mp())
    {
        tell_object(caster, "You don't have that many power points.");
        return;
    }

    if(!USER_D->spend_pool(caster, 1, "focus"))
    {
        tell_object(caster, "You need to have psionic focus to use this feat.");
        return;
    }

    ::execute_feat();

    caster->add_mp(-amount);
    tell_object(caster, "You use your meta psionic knowledge to augment your next power.");
    caster->set_property("augment power", 4);
    caster->add_cooldown("augment power", 60);

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
