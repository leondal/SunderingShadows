#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("KiDefense");
    feat_name("stillness of mind");
    feat_prereq("Monk L7");
    feat_syntax("stillness_of_mind");
    feat_desc("A monk that is unarmored and unarmed, or wielding small weapons, may attempt to still her mind, freeing herself from all movement impairing affects. This focus is intense and requires the use of 2 ki. Furthemore, the monk must wait a period of time being being able to focus her mind in such a way again.");
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) return 0;
    if((int)ob->query_class_level("monk") < 7 || (int)ob->query_alignment() > 3)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_stillness_of_mind(string str)
{
    object feat;
    if(!objectp(TP)) return 0;
    if(!TP->is_class("monk")) return 0;
    if((int)TP->query_class_level("monk") < 7) return 0;
    if(!(int)USER_D->can_spend_ki(TP, 2))
    {
        tell_object(TP, "%^BOLD%^%^CYAN%^You lack the needed ki to still your mind.%^RESET%^");
        dest_effect();
        return 1;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

int check_can_use()
{
    object *weapons;
    int x;
    if(!objectp(caster)) return 0;
    weapons = caster->query_wielded();
    for(x = 0;x < sizeof(weapons);x++)
    {
        if(!objectp(weapons[x])) continue;
        if((int)weapons[x]->query_size() > 1)
        {
            tell_object(caster, "%^BOLD%^%^GREEN%^Your "+weapons[x]->query_short()+
            " interferes with your stillness of mind!%^RESET%^");
            return 0;
        }
        continue;
    }
    if(!caster->is_ok_armour("barb"))
    {
        tell_object(caster, "%^BOLD%^%^GREEN%^Your armor interferes "+
        "with your stillness of mind!%^RESET%^");
        return 0;
    }
    if(!(int)USER_D->can_spend_ki(caster, 2))
    {
        tell_object(caster, "%^CYAN%^You lack the needed ki to still "+
        "your mind!%^RESET%^");
        return 0;
    }
    return 1;
}

void execute_feat()
{
    ::execute_feat();
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(caster->query_bound())
    {
        caster->send_paralyzed_message("info",caster);
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if(caster->query_casting())
    {
        tell_object(caster,"%^BOLD%^You are already in the middle of casting a spell.%^RESET%^");
        dest_effect();
        return;
    }
    if(!check_can_use())
    {
        dest_effect();
        return;
    }
    if(!caster->query_tripped() && !caster->query_paralyzed())
    {
        tell_object(caster, "%^BOLD%^%^CYAN%^You are suffering from no ailment "+
        "that would require you to still your mind!%^RESET%^");
        dest_effect();
        return;
    }
    if(caster->query_property("using stillness of mind") > time()+90)
    {
        tell_object(caster, "%^BOLD%^%^CYAN%^You are still recovering, you "+
        "must wait awhile longer before you can still your mind again!%^RESET%^");
        dest_effect();
        return;
    }
    if(!TP->spend_ki(2))
    {
        tell_object(caster, "%^CYAN%^You lack the needed ki to still "+
        "your mind!%^RESET%^");
        dest_effect();
        return;
    }
    tell_object(caster, "%^BOLD%^%^CYAN%^You focus intenting, stilling your "+
    "mind and envisioning yourself free to move about at will!%^RESET%^");
    if(objectp(environment(caster)))
    {
        tell_room(environment(caster), caster->QCN+"%^BOLD%^%^CYAN%^ begins focusing "+
        "intently and you watch as "+caster->QS+" envisions himself free to "+
        "move at will!%^RESET%^", caster);
    }
    caster->set_tripped(0);
    caster->set_paralyzed(0);
    delay_messid_msg(90,"%^BOLD%^%^WHITE%^You can %^CYAN%^stillness of mind%^WHITE%^ again.%^RESET%^");
    caster->remove_property("using stillness of mind");
    caster->set_property("using stillness of mind", time());
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
