#include <std.h>
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("disjunction");
    set_spell_level(([ "mage" : 9, "cleric" : 9,"inquisitor":5 ]));
    set_spell_sphere("abjuration");
    set_syntax(
"cast CLASS disjunction on OBJECT");
    set_description("This spell disconnects beneficial magic from an object and allows it to float freely, forever lost in the weave. The object must be present in the caster's inventory.

This spell uses 14 142 gp as a material component.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
	set_helpful_spell(1);
}

string query_casting_string() {
    return "%^BOLD%^%^MAGENTA%^"+caster->QCN+" utters a short %^GREEN%^r%^CYAN%^h%^GREEN%^ym%^CYAN%^e %^MAGENTA%^under "+caster->QP+" breath.";
}

int preSpell() {
   if(!arg) {
       tell_object(caster, "You must specify what to disenchant.");
       return 0;
   }
   if(!caster->query_funds("gold", 14142))
   {
       tell_object(caster, "You don't have enough money.");
       return 0;
   }
   return 1;
}

void spell_effect(int prof)
{
    object ob;
    int enchantment;

    ob = present(arg,caster);
    if (!objectp(ob))
    {
        tell_object(caster,"That object is not present.");
        dest_effect();
        return;
    }

   if(!caster->query_funds("gold", 14142))
   {
       tell_object(caster, "You don't have enough money.");
       return;
   }

   caster->use_funds("gold",14142);

    enchantment = ob->query_property("enchantment");
    if(enchantment<0)
    {
        tell_object(caster,"%^BOLD%^%^MAGENTA%^You cannot unravel the magic of this object further.%^RESET%^");
        dest_effect();
        return;
    }

    ob->remove_property("enchantment");
    ob->set_property("enchantment",enchantment-1);
    tell_object(caster,"%^BOLD%^%^MAGENTA%^As the metal vapor rises it carries away the magic of "+ob->query_short()+"%^BOLD%^%^MAGENTA%^, and it becomes weaker.%^RESET%^");
    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" voices a few syllables and evaporates a pile of gold under "+ob->query_short()+".%^RESET%^", caster);

    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
