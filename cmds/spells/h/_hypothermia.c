//Updated by ~Circe~ 5/13/08 to be more in line with the
//other 7th level spells.  Did only clevel,6 damage and
//drained a slight bit of stamina.  Made to last a few
//rounds with a minor damage over time and paralyzation
//at the end.  Rebalancing cleric domains

#include <spell.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;
//added this here as a global variable - so that it
//can be kept track of - previously it was
//being reset to 0 each time hypo was being
//called and as a result the spell was neverending - Saide
int hypo_count = 0;

void create(){
    ::create();
    set_author("ares");
    set_spell_name("hypothermia");
    set_spell_level(([ "cleric" : 7, "druid":7, "oracle" : 7 ]));
    set_mystery("winter");
    set_spell_sphere("invocation_evocation");
    set_domains("cold");
    set_syntax("cast CLASS hypothermia on TARGET");
    set_description("This spell creates a freezing ray of bitter cold.  The ray will seek to drain the heat from the "
"target as the cold moves through his body.  Because it is a ray, there is a chance the target can dodge some of the "
"bitter cold.  However, if hit with the full force of the spell, the target will also begin to grow chilled, eventually "
"becoming frozen and blinded for a time.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
}

string query_cast_string(){
   	tell_object(caster,"%^BOLD%^%^CYAN%^%^Your hands grow cold and "+
		"numb as you murmur your prayer.");
    	tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" murmurs a prayer,"+
		" "+caster->QP+" breath turning into a frozen vapor.",caster);}

void spell_effect(int prof){
    int damage;
    if (!present(target,place)){
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return 1;
    }
    if(do_save(target,0)) {
    //if(SAVING_D->saving_throw(target,"spell")){
        tell_object(caster,"%^BOLD%^%^WHITE%^A thin blue ray swirled with white"+
		" streaks from your outstretched hand.\n "
            "%^BOLD%^%^CYAN%^"+target->QCN+" manages to dodge the full force of it!");
        tell_object(target,"%^BOLD%^%^WHITE%^A thin blue ray swirled with white"+
		" streaks from "+caster->QCN+"'s outstretched hand."+
		"\n%^BOLD%^%^CYAN%^ You manage to slightly dodge it!");
        tell_room(place,"%^BOLD%^%^WHITE%^A thin blue ray swirled with white"+
		" streaks from "+caster->QCN+"'s outstretched hand."+
		"\n%^BOLD%^%^CYAN%^"+target->QCN+" manages to slightly dodge it!");
        damage = sdamage / 2;
        damage_targ(target,target->return_target_limb(),damage,"cold");
        spell_successful();
        dest_effect();
    }else{
        tell_object(caster,"%^BOLD%^%^WHITE%^A thin blue ray swirled with white"+
		" streaks from your outstretched hand.\n "
            "%^BOLD%^%^CYAN%^"+target->QCN+" is hit with the full force of your"+
		" frozen ray!");
        tell_object(target,"%^BOLD%^%^WHITE%^A thin blue ray swirled with white"+
		" streaks from "+caster->QCN+"'s outstretched hand."+
		"\n%^BOLD%^%^CYAN%^ You are struck with the full force of the ray, "+
		"feeling it draining you of your heat!");
        tell_room(place,"%^BOLD%^%^WHITE%^A thin blue ray swirled with white"+
		" streaks from "+caster->QCN+"'s outstretched hand."+
		"\n%^BOLD%^%^CYAN%^"+target->QCN+" is hit with the full force of"+
		" the frozen ray!");
        damage = sdamage;
        damage_targ(target,target->return_target_limb(),damage,"cold");
        target->use_stamina(clevel/2);
        call_out("hypo",ROUND_LENGTH,target);
        spell_successful();
    }
}

int hypo(object obj){
   int num;
   object room;
   if(!objectp(obj))               { dest_effect(); return 0; }
   if(!objectp(environment(obj)))  { dest_effect(); return 0; }
   if(!objectp(caster))            { dest_effect(); return 0; }
   room = environment(obj);
   define_base_damage(0);
   switch(hypo_count){
      case 0:  tell_object(obj,"%^CYAN%^You feel the ice from "+
                  ""+caster->QCN+"'s frozen ray creep slowly up "+
                  "your arm.%^RESET%^");
               tell_room(room,"%^CYAN%^"+obj->QCN+" shivers for "+
                  "a brief moment.%^RESET%^",obj);
               num = clevel/3;
               damage_targ(obj,obj->return_target_limb(),sdamage,"cold");
               hypo_count++;
               call_out("hypo",ROUND_LENGTH,obj);
               break;
      case 1:  tell_object(obj,"%^BOLD%^%^BLUE%^The %^WHITE%^ice "+
                  "%^BLUE%^spreads quickly, moving across your "+
                  "body and making you feel sluggish.%^RESET%^");
               tell_room(room,"%^BOLD%^%^BLUE%^"+obj->QCN+"'s teeth "+
                  "chatter uncontrollably.%^RESET%^",obj);
               num = clevel/2;
               damage_targ(obj,obj->return_target_limb(),sdamage,"cold");
               hypo_count++;
               call_out("hypo",ROUND_LENGTH,obj);
               break;
      default: tell_object(obj,"%^BOLD%^%^CYAN%^Suddenly, all of your "+
                  "limbs seize up, freezing you in place!%^RESET%^");
               tell_room(room,"%^BOLD%^%^CYAN%^"+obj->QCN+" suddenly "+
                  "freezes in place!%^RESET%^",obj);
               obj->set_paralyzed(roll_dice(3,2),"You are frozen in place!");
               obj->set_temporary_blinded(3,2);
//Takes a bit for their vision to clear
               dest_effect();
               break;
   }
}


void dest_effect(){
   ::dest_effect();
   if(objectp(TO)) TO->remove();
}
