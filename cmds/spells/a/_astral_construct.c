//_astral_construct by ~Circe~ 7/27/05
//based on priest summoning spells

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int i, v;
object endplace, device;
object elem;


void create()
{
    ::create();
    set_spell_name("astral construct");
    set_spell_level(([ "psion" : 7 ]));
    set_discipline("shaper");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS astral construct");
    set_description("By manifesting this command, a shaper may pull small portions of ectoplasm from the Astral Plane and weave from them a construct to do his bidding.  The shaper must be careful, else he may lose control of his new creation. This is a greater summon, you can't control two such powerful beings.

To command this construct use <command construct to ACTION>.
To command lost construct to follow you again, <command construct to follow>.
To dismiss construct, <dismiss construct>.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


string query_cast_string()
{
    return "%^BOLD%^%^MAGENTA%^"+caster->QCN+" reaches out and seems to grasp the air itself.";
}


int preSpell()
{
    if(caster->query_property("mages_sword") || caster->query_property("has_elemental")) {
        tell_object(caster,"You already have a powerful summoned creature under your control.");
        return 0;
    }
    if (present("celemdevicex999",caster))
    {
        tell_object(caster,"You can only control one construct at a time!\n");
        return 0;
    }
    return 1;
}


void spell_effect(int prof)
{
    string him;
    mapping tmp;

    if (!objectp(caster) || !objectp(environment(caster)))
    {
        TO->remove();
        return;
    }

    if(objectp(environment(caster))) place = environment(caster);
    him = caster->QCN;

    tell_room(place,"%^BOLD%^%^BLUE%^"+him+" begins to pull at the "+
       "air, creating fine, translucent filaments.", caster);
    tell_object(caster,"%^BOLD%^%^BLUE%^You seem to pull at the air "+
       "as you reach into the Astral Plane and draw forth fine "+
       "filaments of ectoplasm.");
    caster->set_property("has_elemental",1);
    call_out("next_step",10);
    spell_successful();
}


void next_step()
{
    string him;
    if (!objectp(caster) || !objectp(environment(caster)))
    {
        TO->remove();
        return;
    }

    if(objectp(environment(caster))) { place = environment(caster); }
    him = caster->QCN;

    tell_room(place,"%^BOLD%^%^CYAN%^"+him+" begins to shape the "+
        "filaments, weaving them together rapidly in a way "+
        "you cannot quite see.",caster);
    tell_object(caster,"%^BOLD%^%^CYAN%^Working quickly and precisely, "+
        "you begin to weave the ectoplasm into the shape you desire.");
    call_out("step3",5);
}


void step3()
{
    string him;
    object ob;
    int mylevel;

    if (!objectp(caster) || !objectp(environment(caster)))
    {
        TO->remove();
        return;
    }

    mylevel = clevel;

    if (objectp(environment(caster))) { place = environment(caster); }

    him = caster->QCN;
    ob = new("/d/magic/mon/astral_construct");
    elem = ob;
    ob->set_property("spell",TO);
    ob->set_static_bab(clevel);
    ob->set_mylevel(mylevel);
    ob->set_property("spelled", ({TO}) );
    ob->set_property("spell_creature", TO);
    ob->set_caster(caster); //added by ~Circe~ 9/8/09 to make construct attack immediately
    ob->set_property("minion", caster);
    device = new("/d/magic/obj/cconstructholder");

    if(objectp(place))
    {
        tell_room(place,"%^BOLD%^All at once "+him+"'s workings "+
            "become clear, and before you stands a form unlike "+
            "any other!",caster);
    }
    if(objectp(caster))
    {
        tell_object(caster,"%^BOLD%^You complete your work, crafting "+
            "the last of the construct as you animate it with a small "+
            "push of your psyche!");
    }
    if(objectp(place))
    {
        tell_room(place,"%^MAGENTA%^A wave shifts through the "+
            "construct's newly created form, and it swings its massive "+
            "head slowly from side to side.");
    }
    if(objectp(caster))
    {
        tell_object(caster,"%^BOLD%^%^MAGENTA%^Finding you, the construct "+
            "kneels down, ready to accept your commands!");
        tell_room(place,"%^BOLD%^%^MAGENTA%^The construct catches sight "+
            "of "+him+" and kneels, awaiting "+caster->QP+" command!",caster);
    }

    device->set_elemental(ob);
    device->set_caster(caster);
    caster->add_follower(ob);
    device->move(caster);
    device->set_property("spell",TO);
    device->set_property("spelled", ({TO}) );
    ob->move(place);
}


void dest_effect()
{
    if(objectp(elem))
    {
        tell_room(environment(elem), "%^YELLOW%^The construct disperses into the air.");
        elem->move("/d/shadowgate/void");
        elem->remove();
    }
    if(objectp(caster)) { caster->remove_property("has_elemental"); }
    if(objectp(device)) { device->remove(); }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
