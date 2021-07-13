#include <priest.h>

inherit SPELL;

void create() 
{
    ::create();
    set_spell_name("aura sight");
    set_spell_level(([ "psion" : 4 ]));
    set_spell_sphere("clairsentience");
    set_syntax("cast CLASS aura sight on TARGET");
    set_description("This power will allow the seer to focus on a target to discover the target's alignment.  The "
        "target's mind might fight the seer, in which case the seer will get no reading.  Other manners of magic or psionics "
        "might alter the reading the seer gets.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string() { return ""+caster->QCN+" seems to stare off into space, growing still."; }

void spell_effect(int prof) 
{
    int al;
    string align;

    al = TARGET->query_alignment();
    align = capitalize(TARGET->query_al_title(al));
    tell_object(CASTER, "%^MAGENTA%^You focus your attentions on "+
        ""+HIM+", carefully probing "+HIS+" inner thoughts.");
    if(do_save(TARGET,0)) 
    {
    //if (do_saving_throw(TARGET, "spell",(-1*clevel))) {
        tell_object(CASTER,"%^BOLD%^%^MAGENTA%^"+HIM+"'s will "+
            "battles yours, and you get no impression about "+
            ""+HIS+" alignment.");
    } 
    else 
    {
        tell_object(CASTER, "%^BOLD%^%^MAGENTA%^You see that "+
            ""+HIM+"'s alignment is "+align);
    }
    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
