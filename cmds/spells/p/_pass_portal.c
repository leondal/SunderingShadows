//New travel domain spell adapted from Phase Door
//by ~Circe~ 4/26/08 with the rebalancing of domains
#include <std.h>
#include <move.h>

inherit SPELL;

string where, *exits, dest_name;
object dest;

void create() {
    ::create();
    set_spell_name("pass portal");
    set_spell_level(([ "cleric" : 6, "oracle" : 6 ]));
    set_domains("travel");
    set_mystery("waves");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS pass portal on <direction>");
    set_description("A priest with the travel domain may use this spell to bypass many doors and barriers found blocking "
"her path.  Some rooms may be enchanted to prevent such magic, but most are not.  If the priest is visible when casting "
"this spell, her movements are accompanied by a bright light.");
    set_verbal_comp();
    set_somatic_comp();
    set_silent_casting(1);
    set_arg_needed();
	set_helpful_spell(1);
}

void spell_effect(int prof) {
  if(!arg){
    tell_object(caster,"Try <chant pass portal on [direction]>.");
    TO->remove();
    return 0;
  }
  if(sscanf(arg, "%s",where)!= 1){
    tell_object(caster,"You cannot pass "+arg+"!  Try <chant pass portal on [direction]>.\n");
    TO->remove();
    return 0;
  }
  exits = place->query_exits();
  if(place->query_property("no phase")){
     tell_object(caster,"This place seems to be enchanted against such things!");
     TO->remove();
     return 0;
  }
  dest_name = place->query_exit(where);
  dest = find_object_or_load(dest_name);
  if(dest->query_property("no phase")){
     tell_object(caster,"This place seems to be enchanted against such things!");
     TO->remove();
     return 0;
  }
  if(member_array(where, exits) == -1){
    tell_object(caster,"You can't phase without an exit.");
    TO->remove();
    return 0;
  }
  if(!place->query_door(where)){
     tell_object(caster,"There is no door blocking the "+where+" exit!");
     TO->remove();
     return 0;
  }
  if(!caster->query_invis()){
     tell_room(place,"%^ORANGE%^"+caster->QCN+" seems to %^YELLOW%^"+
        "shine %^RESET%^%^ORANGE%^brightly for a moment before "+
        "vanishing!%^RESET%^",caster);
  }
  tell_object(caster,"%^ORANGE%^You study the barrier in your path "+
     "and call upon the power of your deity, allowing you to simply "+
     "pass through it!%^RESET%^");
  caster->move_player(dest);
  if(!caster->query_invis()){
     tell_room(dest,"%^ORANGE%^A nimbus of light %^YELLOW%^flashes "+
        "%^RESET%^%^ORANGE%^brightly, bringing "+caster->QCN+" "+
        "with it!%^RESET%^",caster);
   }
   dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
