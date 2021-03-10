/*
  _dedication.c

  Allows the paladin to change dedications.

  -- Tlaloc -- 
*/

#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

string *valid_choices = ({ "fatigued", "exhausted", "confused", "dazzled", "sickened", "panicked", "shaken", "blinded", "poisoned" });

void create()
{
    ::create();
    set_author("tlaloc");
    feat_type("instant");
    feat_category("Presence");
    feat_name("dedication");
    feat_prereq("Paladin L13");
    feat_syntax("dedication [DEDICATION]");
    feat_desc("This feat allows the paladin to choose her dedication.

A Paladin's dedication grants additional healing power to her Lay On Hands.
When Lay on Hands is used, it will cleanse the status effect associated with
the chosen Dedication.

%^BOLD%^You can select from the following dedications:
 Fatigued
 Exhausted
 Confused
 Dazzled
 Sickened
 Panicked
 Shaken
 Blinded
 Poisoned

This dedication will not be applied when Lay on Hands is used offensively.
You can change your dedication once every three days, so choose carefully!

To start selection process type <dedication>.");
    allow_tripped(1);
}

int allow_shifted() { return 1; }

int cmd_dedication(string str)
{
    object feat;

    if(!objectp(this_player()))
        return 0;

    if(this_player()->query_class_level("paladin") < 13)
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
        write("%^BOLD%^You current dedication is: %^RESET%^CYAN%^" + this_player()->query_dedication());
        return 1;
    }

    if(this_player()->query_property("dedication_change") > time() - 259200)
    {
        write("%^BOLD%^You may only change your dedication once every three weeks.");
        return 1;
    }

    if(member_array(arg, valid_choices) < 0)
    {
        write("%^BOLD%^Valid choices are : %^RESET%^RED%^" + implode(valid_choices, ", "));
        return 1;
    }

    write("You have selected the %^CYAN%^ " + arg + "%^RESET%^ dedication. Type <yes> to confirm. Anything else will abort.");
    input_to("confirm_selection", 0);

    return 1;
}

void confirm_selection(string str)
{
    if (str != "yes") {
        tell_object(this_player(), "Aborting...");
        return;
    }

    write("%^BOLD%^You declare your dedication as : %^CYAN%^" + arg + ".");
    this_player()->set_dedication(arg);
    this_player()->set_property("dedication_change", time());
    dest_effect();
    return;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if(ob->query_class_level("paladin") < 13)
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
