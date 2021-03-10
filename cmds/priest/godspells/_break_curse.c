//_break_curse.c
//Updates by Cythera - 5/05\\
#include <std.h>
#include <spell.h>

inherit SPELL;

void create() {
    ::create();

    set_spell_name("break curse");
    set_spell_level(6);
    set_spell_type("priest");
    set_diety("mystra");
    set_spell_sphere("protection");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
}

string query_casting_string() {
   return "%^BLUE%^"+caster->query_cap_name()+" kneels and prays for the divine influence of Mystra.";
}

int preSpell() {
    if (!ARG) {
        tell_object(CASTER, "You must specify what to remove the curse from.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof) {
    string what,who;
    object ob, ob2;
    int ench;

    if (sscanf(arg,"%s at %s", what, who) != 2) {
        what = arg;
        who = 0;
    }

    if (!who) {
        ob = present(what,caster);
    } else {
// checks for a realName versus known as added by *Styx* 8/15/03 to fix recognize problem
        if((string)caster->realName(who) != "")
	   who = (string)caster->realName(who);   
        if (!ob2 = present(who, place)) {
            tell_object(caster,"That person isn't here.");
            dest_effect();
            return;
        }
        ob = present(what,ob2);
    }

    if (!objectp(ob)) {
        tell_object(caster,"That object is not present");
        dest_effect();
        return;
    }
    if (objectp(ob2)) {
        if((string)target->query_diety()== "bane" || (string)target->query_diety()== "shar" || (string)target->query_diety()== "cyric" || (string)target->query_diety()== "talos") {
            tell_object(caster,"%^BOLD%^%^BLUE%^Mystra will not allow her power to be used in that manner.");
            tell_room(place,"%^BOLD%^%^BLUE%^You see "+caster->QCN+" frown.",caster);
            dest_effect();
            return;
        }
    }

    ench = ob->query_property("enchantment");
    if (ench > -1) {
        tell_object(caster,"That object is not cursed.");
        dest_effect();
        return;
    }
    ob->set_property("enchantment",-1*ench);
    while (ench = ob->query_property("enchantment")) {
        ob->set_property("enchantment",-1*ench);

    }

    tell_room(place,"%^BOLD%^%^RED%^The power of Mystra flows down and magically encompasses the "+what+".");
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    TO->remove();
}

int help() {
    write(
@OLI
Spell  : Break Curse
Level  : 6th Level
Sphere : Protection
Deity  : Mystra
Syntax : chant break curse on <object> [at <player>]

Mystra grants this prayer to her cleric to counter
the effects of cursed items in the lands.  Though, 
priests should be warned that Mystra is very 
sensetive about how this prayer is used.  A 
donation to the church is required for the spell
to be cast, either with an equal value magic item
or with a large sum of gold.  Mystra also further
places some limits on the spell, restricting its 
use upon followers of gods that are enemies of her faith.
OLI
);
    return 1;
}
