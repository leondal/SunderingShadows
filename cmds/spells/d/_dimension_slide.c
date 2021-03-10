//Escape spell for psywarriors
//Unlike Expeditious Retreat, this is a short-range teleport and so is higher level and does not trigger caltrops/traps

#include <std.h>
#include <spell.h>
inherit SPELL;

#define DELAY 180 //3 min delay

void create() {
    ::create();
    set_author("circe");
    set_spell_name("dimension slide");
    set_spell_level(([ "psywarrior" : 3, "psion" : 1 ]));
    set_discipline("nomad");
    set_syntax("cast CLASS dimension slide on DIRECTION");
    set_description("Manifesting this power allows the psionic character "
       "to teleport a short distance away. The power can be used in combat "
       "and will ignore mundane impediments, such as caltrops or closed doors, "
       "but will be barred by magically sealed doors.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
	set_helpful_spell(1);
}

int preSpell() {
   if(((int)caster->query_property("slide time")+DELAY) > time()){
      tell_object(caster,"You need to take a moment's rest before you can try that again.");
      return 0;
   }
   if(!arg) {
       tell_object(caster, "%^BOLD%^%^WHITE%^You must specify a direction for this power!%^RESET%^");
       return 0;
   }
   return 1;
}

void spell_effect(int prof) {
    string *exits, dest_name;
    object dest;

    exits = (string *)place->query_exits();
    if((member_array(arg, exits) == -1)) {
        tell_object(caster,"%^BOLD%^%^WHITE%^You can find no exits to slide through!%^RESET%^");
        dest_effect();
        return;
    }

    spell_successful();
    if(place->query_property("no phase")){
       tell_object(caster,"This place seems to be enchanted against such things!\n");
       dest_effect();
       return;
    }
    dest_name = place->query_exit(arg);
    dest = find_object_or_load(dest_name);
    if(dest->query_property("no phase")){
       tell_object(caster,"This place seems to be enchanted against such things!\n");
       dest_effect();
       return;
    }

    /*if(!place->perform_pre_exits(arg))
    {
        dest_effect();
        return;
    } */


    tell_object(caster,"%^RESET%^%^CYAN%^You concentrate on the "+arg+" exit "
       "and will yourself there.%^RESET%^");
    if(!caster->query_invis()){
       tell_room(place,"%^RESET%^%^CYAN%^"+caster->QCN+"'s eyes focus on the "+arg+" "
          "exit just before "+caster->QS+" vanishes!%^RESET%^",caster);
    }
    caster->clear_followers();
    caster->move_player(dest);
    caster->remove_property("slide time");
    caster->set_property("slide time",time());
    if(!caster->query_invis()){
       tell_room(dest,"%^RESET%^%^CYAN%^"+caster->QCN+" suddenly appears before you.%^RESET%^",caster);
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
