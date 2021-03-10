//racial innate for shades - based off dimension slide, psywarrior spell
#include <std.h>
#include <spell.h>
inherit SPELL;

#define DELAY 180 //3 min delay

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("shadow stride");
    set_spell_level(([ "innate" : 1, "monk" : 7, "assassin" : 1, "oracle" : 4]));
    set_mystery("shadow");
    set_spell_sphere("alteration");
    set_monk_way("way of the shadow");
    set_syntax("cast CLASS shadow stride on <direction>");
    set_description("This spell allows the caster to step into the nearest shadow, "
"using it to travel a short distance away. It can be used in combat and will ignore "
"mundane impediments, such as caltrops or closed doors, but will be barred by "
"magically sealed doors.");
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
       tell_object(caster, "%^BOLD%^%^WHITE%^You must specify a direction for this spell!%^RESET%^");
       return 0;
   }
   return 1;
}

void spell_effect(int prof) {
    string *exits, dest_name;
    object dest;

    exits = (string *)place->query_exits();
    if((member_array(arg, exits) == -1)) {
        tell_object(caster,"%^BOLD%^%^WHITE%^You can't stride in that direction!%^RESET%^");
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
    tell_object(caster,"%^RESET%^%^BLUE%^You slip just for a second into the shadows, "
"and use their concealment to stride towards the "+arg+" exit.%^RESET%^");
    if(!caster->query_invis()){
       tell_room(place,"%^RESET%^%^BLUE%^"+caster->QCN+" glances over the shadows "
"towards the "+arg+" exit just before "+caster->QS+" vanishes!%^RESET%^",caster);
    }
    caster->clear_followers();
    caster->move_player(dest);
    caster->remove_property("slide time");
    caster->set_property("slide time",time());
    if(!caster->query_invis()){
       tell_room(dest,"%^RESET%^%^BLUE%^"+caster->QCN+" steps quite suddenly from a patch of shadow.%^RESET%^",caster);
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
