/*
  _third_favored_enemy.c
  
  Allows the ranger to set their third favored enemy
  
  -- Tlaloc -- 7.10.20
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
    feat_name("third favored enemy");
    feat_prereq("Ranger L17");
    feat_syntax("third_favored_enemy [TYPE]");
    feat_desc("This feat allows a ranger to focus their knowledge and training\
fighting a third enemy type of their choice. The ranger will recieve an\
addiional +2 bonus to attack and damage rolls while fighting their favored enemy.\
A ranger also adds this bonus when studying his favored enemy and doesn't need training in academics.\
You can select from the following favored enemies: \n\n" + "%^GREEN%^" + implode(valid_choices, "\n") +
"%^RESET%^\n\n\To start selection process type <third_favored_enemy> [TYPE].");
    allow_tripped(1);
    set_required_for(({ }));
}

int allow_shifted() { return 1; }

int cmd_third_favored_enemy(string str)
{
    object feat;
    
    if(!objectp(this_player()))
        return 0;
    
    if(this_player()->query_class_level("ranger") < 17)
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
        write("Your third favored enemy is: " + this_player()->query_favored_enemy(3));
        return 1;
    }
    
    if(this_player()->query_property("third_favored_enemy_change") > time() - 259200)
    {
        write("You may only change your third favored enemy once every three weeks.");
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
    this_player()->set_favored_enemy(3, arg);
    this_player()->set_property("third_favored_enemy_change", time());
    dest_effect();
    return;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("ranger") < 17)
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