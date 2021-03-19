//Meld into Stone - spell for the new Cavern domain
//by ~Circe~ 4/27/08 created with the rebalancing of domains

#include <std.h>
#include <magic.h>
#include <rooms.h>

#define val_terrains ({"desert rocks","rocky","old mounts","new mounts","ruins","stone building","nat cave","built cave","nat tunnel","built tunnel"})

inherit SPELL;

object invisob;

void create() {
    ::create();
    set_spell_name("meld into stone");
    set_spell_level(([ "cleric" : 3, "druid":3]));
    set_domains( ({ "cavern", "earth" }) );
    set_spell_sphere("alteration");
    set_mystery("stone");
    set_syntax("cast CLASS meld into stone");
    set_description("This spell allows the caster to meld with nearby stone, rendering him invisible to most viewers.  "
"The spell likewise confers the ability to move while invisible, so long as the caster does not pass out of the "
"appropriate terrain.  To end the spell, the caster can type <appear>, engage in combat, or leave the rocky terrain.  In "
"addition, the spell may wear off over time.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
string mytype = environment(caster)->query_terrain();
    if(member_array(mytype,val_terrains) == -1){
        tell_object(caster,"You may cast this spell only in "+
           "rocky surroundings.");
        return 0;
    }
    return 1;
}

spell_effect(int prof) {
   tell_object(caster,"%^ORANGE%^Pressing your palms to the stone, "+
      "you begin to chant an ancient spell.%^RESET%^");
   tell_room(place,"%^ORANGE%^"+caster->QCN+" presses "+caster->QP+" "+
      "palms to the stone and begins to chant.%^RESET%^",caster);
    call_out("targ_vanish",2, prof);
}

void targ_vanish(int prof) {
    if (caster->query_invis()) {
        tell_object(caster,"You are already invisible!");
        dest_effect();
        return;
    }
    if(caster->query_property("visible")){
        tell_object(caster,"Strangely, the spell fails utterly on you.");
        dest_effect();
        return;
    }
    spell_successful();
    invisob=new("/d/magic/obj/cavern_invisob.c");
    invisob->set_property("spell",TO);
    invisob->set_property("spelled", ({TO}) );
    invisob->move_is_ok(1);
    invisob->move(caster);
    invisob->set_prof(prof);
    invisob->move_is_ok(0);
    addSpellToCaster();
    return;
}

void dest_effect() {
    if (objectp(invisob)) {
        invisob->show_up();
    }
    if(objectp(caster))
	caster->remove_property("visible");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

void reverse_spell(){
    target->set_property("visible",1);
    call_out("dest_effect",clevel*8);
}
