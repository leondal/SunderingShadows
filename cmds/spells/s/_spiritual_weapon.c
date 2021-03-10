#include <magic.h>
#include <std.h>
#include <spell.h>
inherit SPELL;

object *animated, *monsters, control;
string arg;
int amount;

void create() {
    ::create();
    set_spell_name("spiritual weapon");
    set_spell_level(([ "inquisitor":2,"oracle":2,"cleric":2 ]));
    set_spell_sphere("invocation_evocation");
    set_domains("war");
    set_syntax("cast CLASS spiritual weapon");
    set_mystery("ancestor");
    set_description("A weapon made of force appears and attacks foes at a distance, as you direct it.

To remove weapon use %^ORANGE%^<dismiss weapon>%^RESET%^
To command weapon use %^ORANGE%^<command weapon to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost weapon to follow use %^ORANGE%^<command weapon to follow>%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
   if(caster->query_property("spiritual_weapon")) {
        tell_object(caster,"%^CYAN%^You are incapable of controling two such summonings.%^RESET%^");
        return 0;
   }
   return 1;
}

void spell_effect(int prof){
	if(!objectp(environment(caster)))
    {
		dest_effect();
		return;
	}
	place = environment(caster);
    summon_servant();
}

void summon_servant() {
    object ob, thing;
    string deity = caster->query_diety();
    string normalizedDeity;
    normalizedDeity = replace_string(deity," ","_");
    if(deity == "godless")
        normalizedDeity = "kismet";

    tell_object(caster,"%^CYAN%^%^BOLD%^As you complete the spell a weapon forms out of thin air in front of you.%^RESET%^");
    tell_room(place,"%^CYAN%^%^BOLD%^As "+caster->QCN+" completes the spell a weapon forms out of thin air.%^RESET%^",caster);

    ob=new("/d/magic/mon/spiritual_weapon.c");
    ob->set_alignment(caster->query_alignment());
    ob->set_short(("/d/magic/obj/weapons/"+normalizedDeity)->query_short());
    ob->set_long(("/d/magic/obj/weapons/"+normalizedDeity)->query_long());
    ob->set_id(ob->query_id()+("/d/magic/obj/weapons/"+normalizedDeity)->query_id());
    ob->setup_servant(caster,clevel);

    control = new("/d/magic/obj/holder");
    control->set_caster(caster);
    control->move(caster);
    control->set_property("spell",TO);
    control->set_property("spelled", ({TO}) );
    control->set_elemental(ob);

    caster->add_follower(ob);

    ob->move(environment(caster));

    ob->set_property("spell",TO);
    ob->set_property("spell", ({TO}) );
    ob->set_property("spell_creature", TO);
    ob->set_property("minion", caster);

    addSpellToCaster();

    caster->set_property("spiritual_weapon",ob);
    return;
}

void dest_effect() {
    object sword;

    if (objectp(caster)) {
        tell_object(caster,"%^CYAN%^Spiritual weapon fades away.%^RESET%^");
    }

    if(objectp(control)) {
		if (objectp(sword = control->query_mon())){
			sword->remove();
			destruct(control);
		}
    }
    if(objectp(caster)) { caster->remove_property("spiritual_weapon"); }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
