// repose sphere, summons a spectral mount. Nienne, 04/07
//Made level 3 with the rebalancing of domains.  This replaces
//fly, and travel domain will get a new spell at 6th, Pass Portal
//~Circe~ 4/26/08

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define HORSE "/d/magic/mon/mounts/"
inherit SPELL;

object ob;

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("faithful mount");
    set_spell_level(([ "cleric" : 3 ]));
    set_spell_sphere("conjuration_summoning");
    set_domains("travel");
    set_syntax("cast CLASS faithful mount");
    set_description("By means of this spell, the caster calls upon their god to send forth a horse to serve as their "
"faithful mount and to help defend them.\n\nThis spell will not work if you are already mounted.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

string query_cast_string(){
    return "%^ORANGE%^"+caster->QCN+" brings both hands forward, "
"and then raises one upwards to pause above "+caster->QP+
" head, and the other downwards to rest at leg-height.%^RESET%^";
}

int preSpell(){
    if(caster->query_in_vehicle()){
      tell_object(caster, "A mount will not come if you are already mounted.");
      return 0;
    }
    return 1;
}

void spell_effect(int prof){
    string name;

    if(!objectp(caster)) return 0;
    if(objectp(place)) place = environment(caster);
    name = caster->QCN;

    tell_room(place, "%^ORANGE%^Just in front of "+caster->QCN+
" along the path of "+caster->QP+" arms, a thin %^BLUE%^tear "
"%^ORANGE%^becomes apparent in the air!%^RESET%^", caster);
    tell_object(caster, "%^ORANGE%^Just in front of you along the path of your "
"arms, a thin %^BLUE%^tear %^ORANGE%^becomes apparent in the air!%^RESET%^");
    call_out("mount", ROUND_LENGTH);
}

void mount(){
    string name;

    name = caster->QCN;
    if(!objectp(caster)) return 0;
    if(objectp(place)) place = environment(caster);

    tell_object(caster,"%^ORANGE%^The tear widens as a narrow hooved leg "
"emerges from it, followed by the rest of a proud %^RED%^equine %^ORANGE%^creature. "
"You blink, and the tear in the air has already disappeared behind it.%^RESET%^");
    ob = new(HORSE+"travel");
    ob->set_property("spell", TO);
    ob->set_property("spell_creature", TO);
    ob->set_owner(caster);
    ob->set_property("minion", caster);
    ob->move(place);
    caster->force_me("mount faithful mount");
    return;
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
