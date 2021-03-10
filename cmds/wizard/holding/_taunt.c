//      Taunt
//      Thorn@Shadowgate
//      1/3/95 
//      Wizard Spells
//      taunt.c
//      Modified and updated by Vashkar -- 12/18/95

#include <spell.h>
inherit SPELL;
int num, need, roll;
object caster, target, place;

create()
{
    ::create();
    set_spell_name("taunt");
    set_spell_level(1);
    set_spell_type("wizard");
    set_spell_sphere("enchantment_charm");
    set_components(([
        "slug" : 1,
    ]));
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_xp_bonus(10);
}

string query_cast_string
{
    return caster->query_cap_name()+" chants to "+
        caster->query_possessive()+"self, with a slight "+
        "smile on "+caster->query_possessive()+" face.";
}

spell_effect()
{
    ::spell_effect();
    caster=CASTER;
    target=TARGET;
    place=PLACE;
    tell_object(caster,"%^YELLOW%^You mock "+
        target->query_cap_name()+" by saying, \""+insult()+
        "\"\n%^RESET%^%^CYAN%^You throw a slug at "+
        target->query_possessive()+" feet!");
    if(interactive(caster))
    {
        tell_object(target,"%^YELLOW%^"+caster->query_cap_name()+
            " mocks you by saying, \""+insult()+"\"\n"+
            "%^RESET%^%^CYAN%^"+caster->query_objective()+
            " throws a slug at your feet!");
        tell_room(place,"%^YELLOW%^"+
            caster->query_cap_name()+" mocks "+
            target->query_cap_name()+" by saying, \""+insult()+
            "\"\n"+"%^RESET%^CYAN%^"+caster->query_cap_name()+
            " throws a slug at "+target->query_possessive()+
            " feet!", ({target, caster}) );
    }
    else
    {
        tell_object(target,"%^YELLOW%^You hear words of mockery "+
            "from "+caster->query_cap_name()+", \""+insult()+"\"\n"+
            "%^RESET%^%^CYAN%^A slug arcs in the air away from "+
            caster->query_objective()+" and it lands at your feet!");
        tell_room(place,"%^YELLOW%^Words of mockery from "+
            caster->query_cap_name()+" taunt "+target->query_short()+
            ", \""+insult()+"\"\n%^RESET%^%^CYAN%^A slug arcs in "+
            "the air away from "+caster->query_objective()+" and "+
            "it lands at "+target->query_possessive()+" feet!",
            ({target, caster}) );
    }
    if( ("/daemon/saving_d"->saving_throw(target, "spell")) ||
        target->query_stats("intelligence") < 2 )
    {
	tell_object(target,"%^ORANGE%^You look at the slug thrown "+
	    "at your feet then growl angrily at "+
	    caster->query_cap_name()+".");
	tell_object(caster,"%^ORANGE%^"+target->query_cap_name()+
	    " stares at the slug you threw at "+
	    target->query_possessive()+" feet and growls at you "+
	    "angrily.");
	tell_room(environment(caster),"%^ORANGE%^"+
	    target->query_cap_name()+" stares at the slug at "+
	    target->query_possessive()+" feet for a second and "+
	    "then growls angrily at "+caster->query_cap_name()+".",
	    ({target, caster}) );
	return;
    }
    spell_successful();
    tell_object(target,"%^BOLD%^%^RED%^Enraged at this insult, "+
	"you charge towards "+caster->query_cap_name()+" and "+
	"attack!");
    tell_object(caster,"%^BOLD%^%^RED%^Enraged at this insult, "+
	target->query_cap_name()+" charges towards you and "+
	"attacks!");
    tell_room(place,"%^BOLD%^%^RED%^"+
	"Enraged at the insult, "+target->query_cap_name()+
	" charges towards "+caster->query_cap_name()+" and "+
	"attacks!", ({target, caster}) );
    target->force_me("kill "+caster->query_name());
}

string insult()
{
    string *insults;
    insults = ({
        "Yo momma wears army boots!",
        "My grandma can fight better than you!",
    })
    return insults[random(sizeof(insults))];
}

int help()
{
    write(
@EndText
Syntax: cast taunt on <target>

     Taunt, when cast, is easily described as magically amplified
insults.  If a saving throw is not made, and the target isn't too
stupid to understand the insult, rage will grow inside the target.
The victim will maliciously attack the caster furiously.

Material component required:

A slug

EndText
    );
    return 1;
}
