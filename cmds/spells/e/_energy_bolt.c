//altered from lightning bolt for psions
//~Circe~ 7/21/05

#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

void dest_effect();

#define MYTYPES ({ "fire", "electricty", "cold", "acid", "sonic", "random" })

void create() {
     ::create();
     set_spell_name("energy bolt");
     set_spell_level(([ "psion" : 3 ]));
     set_spell_sphere("psychokinesis");
     set_syntax("cast CLASS energy bolt on TARGET as TYPE");
     set_description("By manifesting this power, the psion calls on a reserve of energy that can materialize in a number of different ways to assault the target.  Valid energy types are fire, electricity, cold, acid, sonic, or random.");
     set_verbal_comp();
     set_somatic_comp();
     set_arg_needed();
     set_save("reflex");
}

string query_cast_string() {
     return ""+caster->QCN+"'s eyes burn like points of %^BOLD%^silver fire "+
          "%^RESET%^as "+caster->QS+" flicks "+caster->QP+" hand with an upward "+
          "motion.";
}

void spell_effect(int prof){
     string dam_type;
     int damage, num, mylevel, mynum;
     string target_limb, thetarg, args, realname;
     caster = CASTER;
     target = TARGET;
     place = environment(caster);
     damage = 0;
     spell_successful();

     if (!arg) {
          tell_object(caster,"You need to specify a target and a type for this power!");
          dest_effect();
          return;
     }
     if (sscanf(arg,"%s as %s",thetarg,args) != 2) {
          tell_object(CASTER,"You need to specify both your target and the type of energy.");
          dest_effect();
          return;
     }
     if(member_array(args,MYTYPES) == -1){
          tell_object(caster,"That is not a valid type!");
          dest_effect();
          return;
     }
     if(thetarg == "attacker"){
          target = caster->query_current_attacker();
          if(!objectp(target)){
               tell_object(caster,"You don't see an attacker here!");
               dest_effect();
               return;
          }
     }else{
          target = present(thetarg,environment(caster));
          if(!objectp(target)){
               if(userp(caster)) realname = caster->realName(thetarg);
               else realname = thetarg;
               if(avatarp(caster) && !objectp(target)) realname = thetarg; // it was screwing out on imms.
               target = present(realname,place);
               if(!objectp(target)){
                    tell_object(caster,"You don't see "+thetarg+" here!");
                    dest_effect();
                    return;
               }
               dest_effect();
               return;
          }
     }
     if (environment(caster) != environment(target)) {
          tell_object(caster,"Your target has left your range.\n");
          dest_effect();
          return;
     }
     if(args == "random"){
          mynum = random(5);
          args = MYTYPES[mynum];
     }

     //mylevel = clevel;
     //damage = sdamage;
     target_limb = target->return_target_limb();
     switch(args)
     {
     case "fire": tell_object(target,"%^BOLD%^%^RED%^You are enveloped "+
                              "in the flames blazing up from beneath your feet!");
          tell_room(place,"%^BOLD%^%^RED%^"+target->QCN+" is "+
                    "suddenly enveloped in flames blazing up from beneath "+
                    ""+target->QP+" feet!",({target,caster}));
          if(interactive(caster)){
               tell_object(caster,"%^BOLD%^%^RED%^Your psychic "+
                           "energies cause fire to spring up beneath "+
                           ""+target->QCN+"'s feet, enveloping "+target->QO+" "+
                           "in flames!");
          }
          dam_type = "fire";
          break;
     case "electricity": tell_object(target,"%^YELLOW%^A crackling ball of "+
                                     "arcing energy bounds along the ground, electrifying "+
                                     "you!");
          tell_room(place,"%^YELLOW%^A crackling ball of "+
                    "energy bounds along the ground from "+caster->QCN+", "+
                    "electrifying "+target->QCN+"!",({target,caster}));
          if(interactive(caster)){
               tell_object(caster,"%^YELLOW%^A crackling ball "+
                           "of arcing energy bounds along the ground "+
                           "from you, electrifying "+target->QCN+"!");
          }
          dam_type = "electricity";
          break;
     case "cold": tell_object(target,"%^BOLD%^%^CYAN%^You suddenly become "+
                              "glaciated within a mind-numbing rime!");
          tell_room(place,"%^BOLD%^%^CYAN%^"+target->QCN+" suddenly "+
                    "becomes glaciated in rime ice before it shatters!",({target,caster}));
          if(interactive(caster)){
               tell_object(caster,"%^BOLD%^%^CYAN%^You conjure a "+
                           "deathly cold, encasing "+target->QCN+" in rime "+
                           "ice before it shatters!");
          }
          dam_type = "cold";
          break;
     case "acid": tell_object(target,"%^BOLD%^%^GREEN%^A line of acid "+
                              "streaks outward from "+caster->QCN+"'s hand, "+
                              "eating away at your flesh!");
          tell_room(place,"%^BOLD%^%^GREEN%^A line of acid "+
                    "streaks outward from "+caster->QCN+"'s hand, "+
                    "eroding "+target->QCN+"'s flesh!",({target,caster}));
          if(interactive(caster)){
               tell_object(caster,"%^BOLD%^%^GREEN%^A line of acid "+
                           "streaks outward from your hand, "+
                           "eroding "+target->QCN+"'s flesh!");
          }
          dam_type = "acid";
          break;
     default: tell_object(target,"%^BOLD%^%^MAGENTA%^A deafening boom "+
                          "resounds within your mind as you feel blood oozing "+
                          "from your ears!");
          tell_room(place,"%^BOLD%^%^MAGENTA%^An echo of a "+
                    "thunderous pitch can be heard as blood abruptly "+
                    "trickles from "+target->QCN+"'s ears!",({target,caster}));
          if(interactive(caster)){
               tell_object(caster,"%^BOLD%^%^MAGENTA%^You hear the "+
                           "satisfying echo of the deafening boom that is "+
                           "causing "+target->QCN+"'s ears to bleed!");
          }
          dam_type = "sonic";
          break;
     }
     if(!do_save(target,0)) {
          //if (!do_saving_throw(target, "spell", (4-prof/25))) {
          damage_targ(target, target_limb, sdamage, dam_type);
     } else {
          damage_targ(target, target_limb, to_int(sdamage / 2),dam_type );
     }
     spell_successful();
     dest_effect();
}

void dest_effect() {
     ::dest_effect();
     if(objectp(TO)) TO->remove();
}
