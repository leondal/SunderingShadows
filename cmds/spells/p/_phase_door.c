#include <std.h>
#include <move.h>
inherit SPELL;

string where, *exits, dest_name;
object dest;

#define DELAY 180 //3 min delay

void create() {
    ::create();
    set_spell_name("phase door");
    set_spell_level(([ "psion" : 7, "mage" : 7,]));
    set_domains("travel");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS phase door on DIRECTION");
    set_description("With this spell the caster can teleport a short distance away, through doors or any exits. The spell can be used in combat and allows for fast escape, yet it will be barred by magically sealed doors. After phasing a door, caster must wait a while before she can do it again.");
    set_verbal_comp();
    set_somatic_comp();
    set_silent_casting(1);
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
  int pp,maxpp,hp,maxhp,mylevel,i,healed;
  if(!arg){
    tell_object(caster,"Phase where?\n");
    TO->remove();
    return 0;
  }
  if(sscanf(arg, "%s",where)!= 1){
    tell_object(caster,"You cannot phase "+arg+"!  Try <phase DIRECTION>.\n");
    TO->remove();
    return 0;
  }
  spell_successful();
  exits = place->query_exits();
  if(place->query_property("no phase")){
     tell_object(caster,"This place seems to be enchanted against such things!\n");
     TO->remove();
     return 0;
  }
  dest_name = place->query_exit(where);
  dest = find_object_or_load(dest_name);
  if(dest->query_property("no phase")){
     tell_object(caster,"This place seems to be enchanted against such things!\n");
     TO->remove();
     return 0;
  }
  if(member_array(where, exits) == -1){
    tell_object(caster,"You can't phase without an exit.\n");
    TO->remove();
    return 0;
  }
/*
  if(!place->query_door(where)){
     tell_object(caster,"There is no door blocking the "+where+" exit!");
     TO->remove();
     return 0;
  }
*/

  mylevel = clevel;

  if(!caster->query_invis()){
     tell_room(place,"%^BOLD%^%^BLACK%^A muted %^RESET%^%^RED%^p"+
        "%^ORANGE%^r%^YELLOW%^i%^RESET%^%^GREEN%^s%^CYAN%^m"+
        "%^BLUE%^a%^MAGENTA%^t%^RED%^i%^ORANGE%^c %^BOLD%^%^BLACK%^"+
        "light emanates from "+caster->QCN+" before "+caster->QS+" "+
        "vanishes.",caster);
  }
  tell_object(caster,"%^BOLD%^%^BLACK%^You attune your mind to the "+
     "barrier in your path and simply phase through it!");
  caster->clear_followers();
  caster->move_player(dest);

  pp = caster->query_mp();
  maxpp = caster->query_max_mp();
  if(pp < maxpp){
     i = maxpp/8;
     caster->add_mp(i);
//     tell_object(caster,"Added "+i+" power points.");
  }
  healed = ((roll_dice(6,4))+(mylevel*2)); // equiv to a cure serious
  healed *= -1;
  damage_targ(caster,"torso",healed,"untyped");
  caster->remove_property("slide time");
  caster->set_property("slide time",time());

  if(!caster->query_invis()){
     tell_room(dest,"%^BOLD%^%^BLACK%^A muted %^RESET%^%^RED%^p"+
        "%^ORANGE%^r%^YELLOW%^i%^RESET%^%^GREEN%^s%^CYAN%^m"+
        "%^BLUE%^a%^MAGENTA%^t%^RED%^i%^ORANGE%^c %^BOLD%^%^BLACK%^"+
        "light suddenly appears, bringing "+caster->QCN+" "+
        "with it!",caster);
   }
   dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
