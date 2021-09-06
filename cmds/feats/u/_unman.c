#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    set_author("tlaloc");
    feat_type("instant");
    feat_category("Performance");
    feat_name("unman");
    feat_prereq("Bard L31");
    feat_syntax("unman [TARGET]");
    feat_desc("With this feat, the bard has perfected the art of the ultimate insult. She is able to completely debilitate an enemy with her words and performance alone, stopping even the hardiest of enemies in their tracks. This feat, when used, will attempt to apply a myriad of status effects on the target, each with its own individual save. This ability has a cooldown.");
    set_target_required(1);
    set_required_for(({ }));
}


int allow_shifted() { return 0; }

string color(string str)
{
    return CRAYON_D->color_string(str, "whisper");
}


int prerequisites(object ob)
{

    if(!objectp(ob)) { return 0; }

    if(ob->query_class_level("bard") < 31)
    {
        dest_effect();
        return 0;
    }

    return ::prerequisites(ob);
}

int cmd_unman(string str)
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
    int power;

    if(!objectp(caster) || !target)
    {
        dest_effect();
        return;
    }

    if(caster->cooldown("unman"))
    {
        tell_object(caster, "You can't use unman yet.");
        dest_effect();
        return;
    }
    
    tell_object(caster, color("You lay into " + target->QCN + " with an epic verbal assault, attempting to break " + target->query_possessive() + " will to fight."));
    tell_room(place, color(caster->QCN + " lays into " + target->QCN + " with an epic verbal assault, attempting to break " + target->query_possessive() + " will to fight."));
    
    if(!SAVING_THROW_D->reflex_save(target, 0))
    {
        tell_room(place, target->QCN + " loses " + target->query_possessive() + " footing and falls down in a crumpled heap.", ({ target }));
        tell_object(target, "%^BOLD%^You lose your footing and fall down in a crumpled heap.");
        target->set_tripped(roll_dice(1, 6), "You are trying to regain your footing!");
    }
    if(!SAVING_THROW_D->will_save(target, 0))
    {
        tell_room(place, target->QCN + " loses " + target->query_possessive() + " grip on reality and swings wildly.", ({ target }));
        tell_object(target, "%^BOLD%^You lose your grip on reality and swing wildly.");
        find_object("/std/effect/status/confused")->apply_effect(target, roll_dice(1, 6));
    }
    if(!SAVING_THROW_D->fort_save(target, 0))
    {
        tell_room(place, target->QCN + " grabs " + target->query_possessive() + " stomach as self-loathing sets in.", ({ target }));
        tell_object(target, "%^BOLD%^You grab your stomach as self-loathing sets in.");
        find_object("/std/effect/status/sickened")->apply_effect(target, roll_dice(1, 6));
    }     
    if(!SAVING_THROW_D->will_save(target, 0))
    {
        tell_room(place, target->QCN + " grips " + target->query_possessive() + " head as the world becomes too big to handle.", ({ target }));
        tell_object(target, "%^BOLD%^You grip your head as the world becomes too big to handle.");
        find_object("/std/effect/status/panicked")->apply_effect(target, roll_dice(1, 6));
    }
    if(!SAVING_THROW_D->reflex_save(target, 0))
    {
        tell_room(place, target->QCN + " fumbles " + target->query_possessive() + " steps with self-conscious footing.", ({ target }));
        tell_object(target, "%^BOLD%^You fumble your steps with self-conscious footing.");
        find_object("/std/effect/status/staggered")->apply_effect(target, roll_dice(1, 6));
    }
    if(!SAVING_THROW_D->will_save(target, 0))
    {
        tell_room(place, target->QCN + " is frozen in place by the futility of " + target->query_possessive() + " existence.", ({ target }));
        tell_object(target, "%^BOLD%^You are frozen in place by the futility of your existence.");
        target->set_paralyzed(roll_dice(1, 6) * 8, "You are frozen in place by the futility of your existence.");
    }
    if(!SAVING_THROW_D->fort_save(target, 0))
    {
        tell_room(place, target->QCN + " scratches at " + target->query_possessive() + " skin, trying to feel something, anything.", ({ target }));
        tell_object(target, "%^BOLD%^You scratch at your skin, trying to feel something, anything.");
        target->set_property("rend", 6);
    }

    ::execute_feat();

    tell_object(caster, color("You finish your ultimate insult and observe the impact."));
    caster->add_cooldown("unman", 300);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
