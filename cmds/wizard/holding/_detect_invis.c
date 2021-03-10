// Detect Invisibility
// Wizard Spell: Level 2

#include <std.h>
#include <spell.h>

inherit SPELL;

object oldenv, caster;
int flag, x, num;

void dest_effect()

create() {
    ::create();
    set_spell_name("detect invisibility");
    set_spell_level(2);
    set_spell_type("wizard");
    set_spell_sphere("divination");
    set_components(([
	"talc" : 0,
	"powdered silver" : 0,
    ]));
    set_verbal_comp();
    set_somatic_comp();
/*
    set_cast_string(caster->query_cap_name()+" falls into "+
	"a trance while muttering something silently.");
*/
}

spell_effect()
{
    object *inv;
    string short;

    caster=CASTER;
    oldenv=environment(caster);
    num = 0;
    flag = 1;
    see_room();
    flag=0;
    tell_object(caster, "Type \"%^BOLD%^detect invis%^RESET%^\" to check "+
	"for invisible objects.");
    add_action("looking","detect");
    call_out("env_change", 2);
}

void looking(string str)
{
    if(str != "invis")
	return 0;
    flag=1;
    see_room();
    flag=0;
}

int env_change()
{
    if(environment(caster) != oldenv)
    {
	oldenv=environment(caster);
	see_room();
    }
    if( ((num++)*2) < (clevel * 5 * ROUND_LENGTH) )
	call_out("env_change", 2);
    else
	dest_effect();
}

void see_room()
{
    inv = all_inventory(environment(TP));
    if(!inv && flag)
    {
	tell_object(caster, "There are no invisible objects "+
	    "in this room.");
	return;
    }
    tell_object(caster, "\n%^BOLD%^%^WHITE%^Invisible Objects in "+
	"this room:");
    for(x=0;x<sizeof(inv);x++)
    {
	short = inv[x]->query_short();
	if (short ||
	    !wizardp(inv[x]) ||
	    (inv[x]->query_invis()) )
	    tell_object(caster, short);
    }
}

void dest_effect()
{
    if(find_call_out("env_change"))
	remove_call_out("env_change");
    destruct(TO);
}
