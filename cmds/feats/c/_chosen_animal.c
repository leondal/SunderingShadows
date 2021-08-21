/*
  _chosen_animal.c
  
  Lets the Beast Master choose an animal type to focus on.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

string *valid_types = ({ "ape", "badger", "bear", "bird", "boar", "camel", "cheetah", "crocodile", "dinosaur", "dog", "horse", "lion", "snake", "wolf", "fox" });

void create()
{
    ::create();
    set_author("tlaloc");
    feat_type("instant");
    feat_category("BeastMastery");
    feat_name("chosen animal");
    feat_prereq("Beast Master L1");
    feat_syntax("chosen_animal [TYPE]");
    feat_desc("The pack as a whole is better than the sum of its individual parts. " +
              "The Beast Master becomes part of a pack of their choosing, boosting the " +
              "effectiveness of the members of the pack around them. This feat allows the " +
              "Beast Master to choose an animal type. As long as your animal companion is of " +
              "the chosen type, it will be stronger and more resistant to damage.");
    allow_tripped(1);
}

int allow_shifted() { return 1; }

int cmd_chosen_animal(string str)
{
    object feat;

    if(!objectp(this_player()))
        return 0;

    if(this_player()->query_class_level("beast_master") < 1)
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
        write("%^BOLD%^You current chosen animal is: %^RESET%^RED%^" + this_player()->query_chosen_animal());
        return 1;
    }

    if(this_player()->query_property("chosen_animal") > time() - 259200)
    {
        write("%^BOLD%^You may only change your chosen animal once every three weeks.");
        return 1;
    }

    if(member_array(arg, valid_types) < 0)
    {
        write("%^BOLD%^Valid choices are : %^RESET%^RED%^" + implode(valid_types, ", "));
        return 1;
    }

    write("You have selected the %^CYAN%^ " + arg + "%^RESET%^ animal type. Type <yes> to confirm. Anything else will abort.");
    input_to("confirm_selection", 0);

    return 1;
}

void confirm_selection(string str)
{
    if (str != "yes" && str != "Yes") {
        tell_object(this_player(), "Aborting...");
        return;
    }

    write("%^BOLD%^You declare your chosen animal as : %^CYAN%^" + arg + ".");
    this_player()->set_chosen_animal(arg);
    this_player()->set_property("chosen_animal", time());
    dest_effect();
    return;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!(ob->is_class("beast_master")))
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