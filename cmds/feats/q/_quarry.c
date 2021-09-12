/*
  _quarry.c
  
  Ranger feat from PFSRD.
  
  Designates an enemy in the room as your quarry.
  Target must be a favored enemy.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

object feat;

void create()
{
    ::create();
    
    set_author("tlaloc");
    feat_type("instant");
    feat_prereq("Ranger L10");
    feat_syntax("quarry [TARGET]");
    feat_category("WildernessLore");
    feat_name("quarry");
    feat_desc("This feat allows the ranger to designate a target in the room " +
"as their quarry. Attacks the ranger makes against their quarry get an additional " +
"+2 to attack and damage rolls. The ranger can only designate targets that are already their " +
"favored enemy.");
    set_target_required(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) {
        return 0;
    }
    if(ob->query_class_level("ranger") < 10)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_quarry(string str)
{   
    if(!this_player())
        return 0;

    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}

void execute_feat(string str)
{
    ::execute_feat();
    
    if(!caster || !target || !living(target))
        return;
    
    if(caster->query_property("using instant feat"))
    {
        write("You are already in the middle of using a feat!");
        return;
    }
    
    /*
    if(caster->query_current_attacker())
    {
        write("You cannot choose your quarry during combat.");
        return;
    }
    */
    
    if(!caster->is_favored_enemy(target))
    {
        write("Your quarry MUST be a favored enemy.");
        return;
    }
    
    if((caster->query("no pk")) && (target->is_player())){
        tell_object(caster,"%^YELLOW%^You are unable to target another player while you have a %^MAGENTA%^NoPK %^YELLOW%^flag.");
        dest_effect();
        return;
    }
    
    write("%^GREEN%^You look your quarry over, learning their scent, their habit and their weaknesses.%^RESET%^");
    //say(caster->QCN + " looks over their quarry, learning as much useful information as possible.");
    
    caster->remove_property("quarry");
    caster->set_property("quarry", target);
}

void execute_attack()
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }   
    caster->remove_property("using instant feat");
    ::execute_attack();
}

void dest_effect()
{
    caster && tell_object(caster, "%^BOLD%^You lose track of your quarry.%^RESET%^");
    caster && caster->remove_property("quarry");
    ::dest_effect();
    remove_feat(this_object());
    return;
}
    