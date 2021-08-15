#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("instant");
    feat_category("WildernessLore");
    feat_name("wild hunter");
    feat_prereq("Ranger L31");
    feat_syntax("wild_hunter");
    feat_desc("With this feat, the ranger becomes a hunter that no prey can hope to escape from. With this feat, the ranger is able to observe their quarry as if affected by true seeing. This feat allows the ranger to bypass all hiding, magical invisibility, and even concealment effects utilized by their quarry.");
    allow_blind(1);
}


int allow_shifted() { return 1; }


int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if((int)ob->query_class_level("ranger") < 31)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}


string cm(string str) { return CRAYON_D->color_string(str,"green"); }


int cmd_wild_hunter(string str)
{
    object feat;
    
    if(!objectp(this_player()))
        return 0;
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(),str);
    return 1;
}

void execute_feat()
{
    int bonus;
    object obj;
    
    if((int)caster->query_property("using instant feat")) 
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    
    if(FEATS_D->is_active(caster,"wild hunter"))
    {
        obj = query_active_feat("wild hunter");
        tell_object(caster, cm("You relax your intense focus on finding your quarry."));
        obj->dest_effect();
        dest_effect();
        return;
    }
    
    if(!caster->query_property("quarry"))
    {
        tell_object(caster, "You need to designate your quarry.");
        dest_effect();
        return;
    }
    
    tell_object(caster, cm("You bend your will towards your quarry, bringing their scent, mannerisms, and tactics to the forefront of your mind."));   

    caster->set_property("active_feats",({ this_object() }));
    
    ::execute_feat();
    return;
}


void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property_value("active_feats",({ this_object() })); 
    }

    ::dest_effect();
    remove_feat(this_object());
    return;
}

