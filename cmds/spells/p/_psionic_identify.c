//psionic identify
//adapted by ~Circe~ 7/21/05
#include <std.h>
#include <spell.h>

inherit SPELL;

object ob,*ppl;
int i;


void create() 
{
    ::create();
    set_spell_name("psionic identify");
    set_spell_level(([ "psion" : 2, "psywarrior": 2 ]));
    set_spell_sphere("clairsentience");
    set_syntax("cast CLASS psionic identify on <object>");
    set_description("This power allows a psion to attune his mind, focusing on the moment of an item's creation.  The "
        "psion then reveals what he has found, marking the enchantment of the item as well as the name, should the item have a "
        "specific one.  The psion does not know how an item is created using these means; he simply knows what the lasting effect "
        "is.  The item must be in the psion's hands or on the floor for the spell to work.\n\nNOTE: Anyone in the same room with "
        "you will also know the enchantment of that item.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}


string query_cast_string() { return "%^RED%^"+caster->QCN+" takes the item in hand and closes "+caster->QP+" eyes."; }


void spell_effect(int prof) 
{

    if (!arg) arg = "";
    
    ob = present(arg,environment(caster));

    if (!ob) { ob = present(arg,caster); }

    if (!ob) 
    {
        tell_object(caster,"You do not see that.");
        dest_effect();
        return;
    }
    if (living(ob)) 
    {
        tell_object(caster,"You realize "+arg+" is not a statue!");
        dest_effect();
        return;
    }
    spell_successful();

    ppl = all_inventory(environment(caster));
    for (i = 0;i < sizeof(ppl);i++) 
    {
        if (interactive(ppl[i]))
        {
            ob->add_identified(ppl[i]->query_name());
        }
    }

    tell_room(environment(caster),"%^BOLD%^%^RED%^"+caster->QCN+" utters aloud the secrets of the "+arg+"'s creation.",caster);
    tell_object(caster,"%^BOLD%^%^RED%^You attuned your mind to the "+arg+" and find the moment of its creation, revealing its secrets to those around you.");
    dest_effect();
}


void dest_effect() 
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
