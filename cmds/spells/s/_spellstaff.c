#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;
object cont,staff;


void create()
{
    ::create();
    set_spell_name("spellstaff");
    set_spell_level(([ "druid" : 6 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS spellstaff on SPELL_NAME [. SPELL_ARGS]");

    set_description("NOTE: You must carry a staff with you when casting this spell.\n\n"
        "This spell allows the druid to hold a spell in reserve to be called upon at a later "
        "time by typing <now>.  If the spell normally requires a target, that target will "
        "automatically be the druid.  If you need to add arguments to the reserved spell, you "
        "must add them at the time of casting spellstaff.\n\nexample of usage: cast spellstaff "
        "on word of recall | <remembered location>\nNote: You do need the | symbol if the "
        "spell requires arguments, such as a location.");

    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_peace_needed(1);
    set_casting_time(2);
    set_helpful_spell(1);
}


string query_cast_string()
{
    return "%^GREEN%^"+caster->QCN+" closes "+caster->QP+" eyes and lifts a staff into the air.";
}


int preSpell()
{
    if(!present("staff",caster))
    {
        tell_object(caster,"You need a staff to place your spell into.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof)
{
    string spell, args, *comp_names, orgSpell;
    int x, spellProf;
    object spellObj;

    if (!ARG)
    {
        dest_effect();
        return;
    }

    if (sscanf(ARG,"%s . %s",spell,args) != 2)
    {
        spell = ARG;
        args = 0;
    }

    if(!objectp(staff=present("staff",caster)))
    {
        tell_object(caster,"You need a staff to place your spell into.");
        dest_effect();
        return;
    }

    if ((int)caster->query_memorized(spell_type,spell) < 1)
    {
        tell_object(caster,"You don't have that spell prepared.");
        dest_effect();
        return;
    }

    orgSpell = spell;
    spell = replace_string(spell," ","_");
    spell = "/cmds/spells/"+spell[0..0]+"/_"+spell;

    if (!file_exists(spell+".c"))
    {
        tell_object(caster,"That spell doesn't seem to exist");
        dest_effect();
        return;
    }

    if (spell->query_spell_level(spell_type) > 8)
    {
        tell_object(caster,"That spell is too powerful to put into a staff.");
        dest_effect();
        return;
    }

    if (!caster->query_memorized(spell_type,orgSpell))
    {
        tell_object(caster,"You don't have that spell prepared.");
        dest_effect();
        return;
    }

    if (stringp(args) && !spell->query_arg_needed()) { args = 0; }

    if (present("remotespellstaff",caster))
    {
        present("remotespellstaff",caster)->remove_me();
    }

    //tell_object(caster,"staff: "+identify(staff));

    staff->set_property("spellstaff_object",1);

    //caster->forget_spell(orgSpell);
    //spellObj = new(spell);
    //spellObj->set_caster(caster);

    cont= new("/d/magic/obj/spellstaff");
    cont->set_prof(100);
    cont->set_spell(spell);
    cont->set_args(args);
    cont->set_clevel(clevel);
    cont->set_spell_ob(TO);
    cont->move(caster);

    tell_object(caster,"%^GREEN%^Your staff glows an eerie green for an instant and then returns to normal.");
    tell_room(place,"%^GREEN%^The staff held by "+caster->QCN+" glows an eerie green for an instant "
        "and then returns to normal.",caster);

    tell_object(caster,"Type <now> to activate");

    set_heart_beat(3);
    addSpellToCaster();
    caster->set_property("spelled",({TO}));
}

void dest_effect()
{
    if(objectp(staff))
    {
        staff->remove_property("spellstaff_object");
    }

    if(objectp(cont))
    {
        tell_room(environment(caster),"%^GREEN%^The scent of fresh leaves fills the air for "
            "a moment before it fades away.");
        cont->remove(0);
    }
    if(objectp(caster))
    {
        caster->remove_property_value("spelled", ({TO}) );
        removeSpellFromCaster();
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

void heart_beat()
{
    if (!objectp(cont)) { TO->dest_effect(); }
}
