#include <std.h>
#include <daemons.h>

inherit FEAT;

string *allowed = ({ "mage", "sorcerer", "cleric", "oracle", "bard", "inquisitor", "magus", "warlock" });

void create()
{
    ::create();
    set_author("tlaloc");
    feat_type("instant");
    feat_category("MetaMagic");
    feat_name("quicken spell");
    feat_prereq("31 levels in any single spellcaster class");
    feat_syntax("quicken_spell");
    feat_desc("This Meta Magic feat will cause your next spell to cast immediately, without the usual casting delay. This feat has a long cooldown.");
    set_required_for(({ }));
}


int allow_shifted() { return 1; }


int prerequisites(object ob)
{
    int success = 0;
    string *classes;
    
    if(!objectp(ob)) { return 0; }

    classes = ob->query_classes();

    foreach(string cls in classes)
    {
        if(member_array(cls, allowed) >= 0)
        {
            if(ob->query_class_level(cls) > 30)
                success = 1;
        }
    }
        
    if(!success)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_quicken_spell(string str)
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
    int i;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    
    if(caster->cooldown("quicken spell"))
    {
        tell_object(caster, "You can't use quicken spell yet.");
        return;
    }

    ::execute_feat();

    tell_object(caster, "You use your meta magic knowledge to quicken your next spell.");
    caster->set_property("quicken spell", 1);
    caster->add_cooldown("quicken spell", 1200);
    
    return;
}

void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property("quicken spell");
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
