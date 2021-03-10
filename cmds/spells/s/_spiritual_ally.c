#include <magic.h>
#include <std.h>
#include <spell.h>
inherit SPELL;

object *animated, *monsters, control;
string arg;
int amount;

void create() {
    ::create();
    set_spell_name("spiritual ally");
    set_spell_level(([ "oracle":4,"cleric":4,"bard":3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS spiritual ally");
    set_mystery("ancestor");
    set_description("Call to one of your ancestors to aid you in combat. This spirit will have a chosen weapon of your deity and will obey all your commands.

This is a greater summons, and cannot be used simultaneously with other greater summons.
To remove ally use %^ORANGE%^<dismiss ally>%^RESET%^
To command ally use %^ORANGE%^<command ally to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost ally to follow use %^ORANGE%^<command ally to follow>%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    set_feats_required(([ "bard" : "timeweaver" ]));
}

int preSpell(){
    if(caster->query_property("mages_sword") || caster->query_property("has_elemental")) {
        tell_object(caster,"You already have a powerful summoned creature under your control.");
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

    tell_object(caster,"%^CYAN%^%^BOLD%^As you complete the spell a humanoid being descends to stand in your protection.%^RESET%^");
    tell_room(place,"%^CYAN%^%^BOLD%^As "+caster->QCN+" completes the spell a spectral humanoid being appears.%^RESET%^",caster);

    ob=new("/d/magic/mon/spiritual_ally.c");
    ob->set_alignment(caster->query_alignment());
    ob->setup_servant(caster,clevel);

    control = new("/d/magic/obj/holder");
    control->set_caster(caster);
    control->move(caster);
    control->set_elemental(ob);
    control->set_property("spell",TO);
    control->set_property("spelled", ({TO}) );


    caster->add_follower(ob);

    ob->move(environment(caster));

    ob->set_property("spell",TO);
    ob->set_property("spell", ({TO}) );
    ob->set_property("spell_creature", TO);
    ob->set_property("minion", caster);

    addSpellToCaster();

    caster->set_property("has_elemental",ob);
    return;
}

void dest_effect() {
    object sword;

    if (objectp(caster)) {
        tell_object(caster,"%^CYAN%^Spiritual ally fades away.%^RESET%^");
    }

    if(objectp(control)) {
		if (objectp(sword = control->query_mon())){
			sword->remove();
			destruct(control);
		}
    }
    if (objectp(caster)) {
        caster->remove_property("has_elemental");
    }
    ::dest_effect();
    if (objectp(TO))
        TO->remove();

}
