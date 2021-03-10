/*
  _discipline.c

  Allows the psion to change disciplines.

  -- Tlaloc -- 4.17.20
*/

#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include <schoolspells.h>

inherit FEAT;

string *valid_choices = ({ "egoist", "kineticist", "nomad", "seer", "shaper", "telepath" });

void create()
{
    ::create();
    set_author("tlaloc");
    feat_type("instant");
    feat_category("Psionics");
    feat_name("discipline");
    feat_prereq("Psion L1");
    feat_syntax("discipline [DISCIPLINE]");
    feat_desc("This feat allows a psion to select or change their psionic discipline.

Psionic Disciplines grant unique spells to the practitioner. The psion will
recieve mastery in one discipline spell per spell level.

%^BOLD%^You can select from the following disciplines:
 Egoist
 Kineticist
 Nomad
 Seer
 Shaper
 Telepath

A psion that has not made their choice will merely be precluded from access to
the discipline-specific spells.

To start selection process type <discipline>.");
    allow_tripped(1);
}

int allow_shifted() { return 1; }

int cmd_discipline(string str)
{
    object feat;

    if(!objectp(this_player()))
        return 0;

    if(this_player()->query_class_level("psion") < 1)
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
        write("%^BOLD%^You current discipline is: %^RESET%^RED%^" + this_player()->query_discipline());
        return 1;
    }

    if(this_player()->query_property("discipline_change") > time() - 259200)
    {
        write("%^BOLD%^You may only change your discipline once every three weeks.");
        return 1;
    }

    if(member_array(arg, valid_choices) < 0)
    {
        write("%^BOLD%^Valid choices are : %^RESET%^RED%^" + implode(valid_choices, ", "));
        return 1;
    }

    write("You have selected the %^CYAN%^ " + arg + "%^RESET%^ discipline. Type <yes> to confirm. Anything else will abort.");
    input_to("confirm_selection", 0);

    return 1;
}

void confirm_selection(string str)
{
    if (str != "yes") {
        tell_object(this_player(), "Aborting...");
        return;
    }

    write("%^BOLD%^You declare your psionic discipline as : %^CYAN%^" + arg + ".");
    this_player()->set_discipline(arg);
    this_player()->set_property("discipline_change", time());
    dest_effect();
    return;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!(ob->is_class("psion")))
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
