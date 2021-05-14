#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include <schoolspells.h>
inherit FEAT;

int FLAG;

string sschool;
string oschool;
string *vschools;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("ArcaneSpellcraft");
    feat_name("magic school");
    feat_syntax("magic_school");
    feat_desc("This feat allows a mage or an archmage to select magic school dedication and school that opposes it.

School of magic gives mages a degree of specialization. Spells of that school become more potent, gaining a +1 bonus to caster level and spell DC.
Spells of the opposing school have a -1 penalty to caster level and spell DC. These bonuses and penalties increase to +2/-2 once 31 mage class
levels are reached.

%^BOLD%^You can select from the following schools%^RESET%^
 Abjuration
 Alteration
 Conjuration_Summoning
 Divination
 Enchantment_Charm
 Illusion
 Invocation_Evocation
 Necromancy

A mage that haven't made his choice will belong to %^WHITE%^%^BOLD%^Universalist%^RESET%^ school, having no penalties or bonuses.

To start selection process type %^ORANGE%^<magic_school>%^RESET%^.

%^BOLD%^N.B.%^RESET%^ Without this selection many of archmage's powers won't work.");
    permanent(1);
    allow_tripped(1);
}

int cmd_magic_school(string args)
{
    if(TP->query_school() && TP->query_opposing_school())
    {
        tell_object(TP,"%^BOLD%^%^WHITE%^You already have your schools set.");
        return 1;
    }
    vschools = sort_array(SCHOOL_LIST, 1);
    tell_object(TP,"%^BOLD%^%^WHITE%^Select your school of magic:\n");
    tell_object(TP,"%^BOLD%^%^MAGENTA%^" + implode(map_array(vschools, (:"  " + $1:)), "\n"));
    tell_object(TP,"%^BOLD%^%^WHITE%^\nEnter anything else to abort.");
    input_to("select_school", 0);
    return 1;
}

void select_school(string args)
{
    if(member_array(args, vschools) == -1)
    {
        tell_object(TP,"%^BOLD%^%^WHITE%^Aborting...");
        return;
    }
    sschool = args;
    vschools -= ({args});
    tell_object(TP,"%^BOLD%^%^WHITE%^Select your school of opposition:\n");
    tell_object(TP,"%^BOLD%^%^MAGENTA%^" + implode(map_array(vschools, (:"  " + $1:)), "\n"));
    tell_object(TP,"%^BOLD%^%^WHITE%^\nEnter anything else to abort.");
    input_to("select_oschool", 0);
    return;
}

void select_oschool(string args)
{
    if(member_array(args, vschools) == -1)
    {
        tell_object(TP,"%^BOLD%^%^WHITE%^Aborting...");
        return;
    }
    oschool = args;
    tell_object(TP,"%^BOLD%^%^WHITE%^You have selected %^CYAN%^" + sschool + "%^WHITE%^ as your school of magic with %^CYAN%^" + oschool + "%^WHITE%^ as your opposing school.");
    tell_object(TP,"%^BOLD%^%^WHITE%^Is this a correct choice? Type %^GREEN%^yes%^WHITE%^ to confirm, anything else to abort.");
    input_to("confirm_selection", 0);
    return;
}

void confirm_selection(string args)
{
    if (args != "yes") {
        tell_object(TP, "%^BOLD%^%^WHITE%^Aborting...");
        return;
    }

    TP->set_school(sschool);
    TP->set_opposing_school(oschool);
    tell_object(TP,"%^BOLD%^%^WHITE%^Your schools have been set.");
    return;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!(ob->is_class("mage") ||
          ob->is_class("archmage"))) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
