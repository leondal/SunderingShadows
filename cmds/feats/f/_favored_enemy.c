/*
  _favored_enemy.c
  
  Allows the ranger to set their favored enemy
  
  -- Tlaloc -- 7.9.20
*/

#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include <favored_types.h>

inherit FEAT;

string *valid_choices;

void create()
{
    ::create();
    
    valid_choices = keys(VALID_ENEMY);
    
    set_author("tlaloc");
    feat_type("instant");
    feat_category("WildernessLore");
    feat_name("favored enemy");
    feat_prereq("Ranger L1");
    feat_syntax("favored_enemy [TYPE]");
    feat_desc("This feat allows a ranger to focus their knowledge and training\
fighting an enemy type of their choice. The ranger will recieve a +2 bonus to\
attack and damage rolls while fighting their favored enemy.\
A ranger also adds this bonus when studying his favored enemy and doesn't need training in academics.\
You can select from the following favored enemies: \n\n" + "%^GREEN%^" + implode(valid_choices, "\n") +
"\n\n\To start selection process type <favored_enemy>.");
    allow_tripped(1);
    set_required_for(({ "second favored enemy" }));
}

int allow_shifted() { return 1; }

int cmd_favored_enemy(string str)
{
    object feat;
    
    if(!objectp(this_player()))
        return 0;
    
    if(this_player()->query_class_level("ranger") < 1)
    {
        dest_effect();
        return 0;
    }
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    
    return 1;
}

int execute_feat()
{
    ::execute_feat();
    
    if(!arg)
    {
        write("Your first favored enemy is: " + this_player()->query_favored_enemy(1));
        return 1;
    }
    
    if(this_player()->query_property("favored_enemy_change") > time() - 259200)
    {
        write("You may only change your favored enemy once every three weeks.");
        return 1;
    }
    
    if(member_array(arg, valid_choices) < 0)
    {
        write("Valid choices are : " + implode(valid_choices, ", "));
        return 1;
    }
    
    write("You have selected " + arg + " as a favored enemy. Type <yes> to confirm. Anything else will abort.");
    input_to("confirm_selection", 0);
    
    return 1;
}

void confirm_selection(string str)
{
    if (str != "yes") {
        tell_object(this_player(), "Aborting...");
        return;
    }

    write("You declare your favored enemy as : " + arg + ".");
    this_player()->set_favored_enemy(1, arg);
    this_player()->set_property("favored_enemy_change", time());
    dest_effect();
    return;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!(ob->is_class("ranger")))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}