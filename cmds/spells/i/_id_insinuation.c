// Id Insinuation
// ~Circe~ 9/11/05

#include <spell.h>
#include <daemons.h>
inherit SPELL;

object mytarg;
int rnds,total;

void create() {
    ::create();
    set_spell_name("id insinuation");
    set_spell_level(([ "psion" : 2 ]));
    set_spell_sphere("telepathy");
    mental_spell();
    set_syntax("cast CLASS id insinuation on TARGET");
    set_description("Id Insinuation allows the psion to befuddle the target's mind, making him react in unpredictable "
"ways.  The target's confused state may make him babble incoherently, run away, or attack a nearby target - even one of "
"his own allies.  Quite powerful in nature, this power can be very helpful in battle.  %^BOLD%^NOTE:  This power does not "
"work on players.  It will work only on mobs or NPCs.%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

int preSpell() {
    if (target->is_player()) {
        tell_object(caster, "%^CYAN%^This power cannot be targeted at players!");
        return 0;
    }
    return 1;
}

spell_effect(int prof) {
    int bonus,mylevel;
    mylevel = clevel;
    mytarg = target;
    bonus = mylevel/6;
    bonus = -1*bonus;
    total = mylevel/5;
    if(total < 0) total = 0;
    total += 3;
    tell_object(mytarg,"%^CYAN%^"+caster->QCN+" gazes intently "+
       "at you, and you feel a force pulling at your mind!");
    tell_object(caster,"%^CYAN%^You focus your energies on "+
       ""+mytarg->QCN+", attempting to confound "+mytarg->QP+" mind!");
    tell_room(environment(caster),"%^CYAN%^"+caster->QCN+" focuses "+
       "intently upon "+mytarg->QCN+"!",({caster,mytarg}));
    if(do_save(target,bonus)) {
    //if(do_saving_throw(mytarg,"spell",bonus)){
       tell_object(mytarg,"%^BOLD%^%^CYAN%^Somehow, you manage to resist!");
       tell_object(caster,"%^BOLD%^%^CYAN%^Miraculously, "+mytarg->QCN+"'s "+
          "mind repels yours!");
       tell_room(environment(caster),"%^BOLD%^%^CYAN%^After an "+
          "intense mental struggle, "+mytarg->QCN+" manages to "+
          "tear "+mytarg->QP+" eyes from "+caster->QCN+"!",({caster,mytarg}));
       spell_kill(mytarg, caster);
       spell_successful();
       TO->dest_effect();
       return;
    }else{
       tell_object(mytarg,"%^BOLD%^%^CYAN%^Your mind slips "+
          "into the depths of insanity as you lose all control!");
       tell_object(caster,"%^BOLD%^%^CYAN%^With glee, you realize "+
          ""+mytarg->QCN+"'s mind is no longer "+mytarg->QP+" own!");
       tell_room(environment(mytarg),"%^BOLD%^%^CYAN%^"+mytarg->QCN+"'s "+
          "eyes become glazed and "+mytarg->QS+" gazes about in "+
          "confusion.",({caster,mytarg}));
       rnds = 0;
       mytarg->set_property("spelled", ({TO}) );
       call_out("confuse_em",3,mytarg);
       spell_kill(mytarg, caster);
       spell_successful();
   }
}

void confuse_em(object mytarg){
   int i;
   object *targs;
   object chosen;
   if(!objectp(mytarg)){
      TO->dest_effect();
      return;
   }
   if(!objectp(caster) || !present(caster,environment(mytarg))){
      TO->dest_effect();
      return;
   }
   if(rnds < total){
      switch(random(100)){
         case 0..10:  if(!present(caster,environment(mytarg))) TO->dest_effect();
                      mytarg->force_me("kill "+caster->query_name()+"");
                      tell_object(mytarg,"%^BOLD%^%^RED%^Outraged, "+
                      "you attack "+caster->QCN+"!");
                      tell_object(caster,"%^BOLD%^%^RED%^Outraged, "+
                      ""+mytarg->QCN+" attacks you!");
                      tell_room(environment(mytarg),"%^BOLD%^"+mytarg->QCN+" "+
                      "attacks "+caster->QCN+" in a violent rage!",({mytarg,caster}));
                      break;
         case 11..20: break;
         case 21..50: if(!present(caster,environment(mytarg))) TO->dest_effect();
                      tell_object(mytarg,"%^YELLOW%^A strange thought "+
                      "enters your mind, but you cannot grasp it!");
                      tell_room(environment(mytarg),"%^YELLOW%^"+
                      ""+mytarg->QCN+" stares at a point in space, "+
                      "babbling incoherently!",mytarg);
                      mytarg->set_paralyzed(4,"You are trying to recall that thought!");
                      break;
         case 51..70: if(!present(caster,environment(mytarg))) TO->dest_effect();
                      tell_object(mytarg,"%^BOLD%^%^BLUE%^With a "+
                      "sudden, uncontrolled fright, you run away "+
                      "from "+caster->QCN+"!");
                      tell_object(caster,"%^BOLD%^%^BLUE%^"+mytarg->QCN+" "+
                      "looks at you in terror and tries to run away!");
                      tell_room(environment(mytarg),"%^BOLD%^%^BLUE%^"+
                      ""+mytarg->QCN+" casts a look of pure terror "+
                      "at "+caster->QCN+" and tries to flee!",({mytarg,caster}));
                      mytarg->run_away();
                      mytarg->run_away();
                      mytarg->run_away();
                      mytarg->run_away();
                      break;
         default:  if(!present(caster,environment(mytarg))) TO->dest_effect();
                   targs = all_living(environment(mytarg));
                   filter_array(targs, "is_non_immortal", FILTERS_D);
                   targs -= ({mytarg});
                   i = random(sizeof(targs));
                   chosen = targs[i];
                   tell_object(mytarg,"%^BOLD%^%^RED%^In a blind "+
                   "rage, you attack the thing closest to you!");
                   tell_object(chosen,"%^BOLD%^%^RED%^"+mytarg->QCN+" "+
                   "suddenly turns and swings wildly at you!");
                   tell_room(environment(mytarg),"%^BOLD%^%^RED%^"+
                   ""+mytarg->QCN+" suddenly turns and swings wildly, "+
                   "attacking "+chosen->QCN+"!",({mytarg, chosen}));
                   mytarg->force_me("kill "+chosen->query_name()+"");
                   break;
      }
      rnds++;
      call_out("confuse_em",5,mytarg);
      return;
   }
   TO->dest_effect();
}



void dest_effect() {
    if(find_call_out("confuse_em")) remove_call_out("confuse_em");
//added the below check for objectp after environment bugs when the
//target had died.  Circe 9/19/05
    if(objectp(mytarg)){
       tell_object(mytarg,"%^MAGENTA%^Suddenly, your mind clears and "+
          "you feel in control again!");
       tell_room(environment(mytarg),"%^MAGENTA%^"+mytarg->QCN+"'s eyes "+
          "suddenly look much more focused.",mytarg);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
