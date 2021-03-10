//~Circe~ 7/29/05
#include <std.h>
#include <priest.h>

#define TYPES ({"sword","staff","battleaxe"})

inherit SPELL;

object mywpn;


void create() 
{
    ::create();
    set_spell_name("weapon of energy");
    set_spell_level(([ "psion" : 1, "psywarrior" : 1 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS weapon of energy on <sword|staff|battleaxe>");
    set_description("This power allows the psion to create a weapon made purely of energy and his psychic power.  The "
        "weapon may take one of three forms - sword, staff, or axe - chosen by the psion at the time of manifesting.  The weapon "
        "must be wielded as a normal weapon. If no choice is made, the weapon will automatically take the form of a sword.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}


string query_cast_string() 
{
    return "%^BOLD%^%^RED%^"+caster->QCN+" closes "+caster->QP+" "+
        "eyes, clasping "+caster->QP+" hands before "+caster->QO+".";
}


void spell_effect(int prof)
{
    if (!objectp(caster))
    {
        dest_effect();
        return;
    }
    
    if(!arg) arg = "sword";
    
    if(member_array(arg,TYPES) == -1)
    {
        tell_object(caster,"That is not a valid type!  You must "+
        "choose sword, staff, or battleaxe.");
        TO->remove();
        return;
    }
    
    if (interactive(caster))
    {
        tell_object(caster, "%^BOLD%^%^CYAN%^A "+arg+" made of pure "+
            "energy materializes in your hands as you concentrate!");
    }
    
    tell_room(place,"%^BOLD%^%^CYAN%^A dazzling light begins to "+
        "glow within "+caster->QCN+"'s hands, taking the shape of "+
        "a "+arg+"!",caster);
        
    mywpn = new("/d/magic/obj/psion_weapon");
    mywpn->make_me(""+arg+"");
    mywpn->move(caster);
    
    caster->remove_paralyzed();
    caster->force_me("wield weapon");
    spell_successful();
}


void dest_effect() 
{
    if (objectp(mywpn) && objectp(caster)) 
    {
        tell_object(caster,"%^BOLD%^%^RED%^The energy forming the "+
            "weapon disperses, causing the weapon to vanish.");
        tell_room(environment(caster),"%^BOLD%^%^RED%^The weapon "+
            "in "+caster->QCN+"'s hand fades away.",caster);
        mywpn->remove();
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
