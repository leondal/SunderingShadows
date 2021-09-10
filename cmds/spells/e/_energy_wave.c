#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void dest_effect();

#define MYTYPES ({ "fire", "electricity", "cold", "acid", "sonic", "random" })

void create() {
    ::create();
    set_spell_name("energy wave");
    set_spell_level( ([ "psion" : 8 ]) );
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS energy wave on TARGET as <type>");
    set_description("The psionicist delves deep into their kinetic powers, produce a much more powerful energy cone that strikes their opponents with the fury of whichever TYPE of energy they choose.When manifesting this power, please choose one of the following types : fire, electricity, cold, acid, sonic or random.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_save("reflex");
    splash_spell(1);
}

string query_cast_string() {
    return "%^ORANGE%^"+caster->QCN+"'s eyes burn like points of "+
       "%^BOLD%^%^WHITE%^silver fire %^RESET%^%^ORANGE%^as "+
       ""+caster->QS+" places "+caster->QP+" wrists together "+
       "and splays "+caster->QP+" fingers.";
}

void spell_effect(int prof){
    int damage,num,stop, mylevel,mynum;
    object *foes, *ownparty;
    string energy, color, dam_type, thetarg, args, realname;

    damage = 0;
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
    foes = ({});
    ownparty = ({});
    mylevel = clevel;
    if (environment(caster) != environment(target)) {
        tell_object(caster,"Your target has left your range.\n");
        dest_effect();
        return;
    }
    //damage = roll_dice(mylevel,6);

    if(args == "random"){
       mynum = random(5);
       args = MYTYPES[mynum];
    }
    spell_successful();
    switch(args){
       case "fire": color = "%^RED%^";
               energy = "%^BOLD%^fire%^RESET%^%^RED%^";
               dam_type = "fire";
               break;
       case "electricity": color = "%^ORANGE%^";
               energy = "%^YELLOW%^lightning%^RESET%^%^ORANGE%^";
               dam_type = "electricity";
               break;
       case "cold": color = "%^CYAN%^";
               energy = "%^BOLD%^ice%^RESET%^%^CYAN%^";
               dam_type = "cold";
               break;
       case "acid": color = "%^GREEN%^";
               energy = "%^BOLD%^acid%^RESET%^%^GREEN%^";
               dam_type = "acid";
               break;
       default: color = "%^MAGENTA%^";
                energy = "%^BOLD%^sound%^RESET%^%^MAGENTA%^";
               dam_type = "sonic";
                break;
    }
    foes += target_selector();

    if(!sizeof(foes))
    {
        dest_effect();
        return;
    }

    if (caster->query_party())
    {
        ownparty=PARTY_D->query_party_members(caster->query_party());
        foes -= ownparty;
    }
    else
    {
        ownparty = ({ caster });
    }

    foes -= ({caster});

    if (caster->query_followers())
        foes -= caster->query_followers();
    tell_object(caster,""+color+"You summon a latent energy inside your "+
       "mind and send forth a wave of "+energy+" into "+target->QCN+"!");
    tell_object(target,""+color+""+caster->QCN+" inhales sharply "+
       "before focusing "+caster->QP+" entire being on you!\nSuddenly, "+
       "a wave of "+energy+" shoots forth from "+caster->QP+" palms "+
       "and envelopes you!");
    tell_room(place,""+color+""+caster->QCN+" focuses on "+target->QCN+" "+
       "and sends forth a wave of "+energy+" from "+caster->QP+" "+
       "palms, enveloping "+target->QO+"!",({caster,target}));
    if(!do_save(target,0)) {
    //if (!do_saving_throw(target, "spell", 0)) {
        damage_targ(target, target->return_target_limb(), sdamage,dam_type);
    } else {
        damage_targ(target, target->return_target_limb(), to_int(sdamage/2),dam_type);
    }
    stop = random(mylevel);
    
    foes -= ({ target });
    
    if(sizeof(foes)){
       for(num=0;num<sizeof(foes);num++){
          if(!objectp(foes[num])) continue;
          if(!living(foes[num])) continue;
          tell_object(foes[num],""+color+"You are hit by the wave of "+energy+"!");
          tell_room(place,""+color+""+foes[num]->QCN+" is hit by the "+
             "wave of "+energy+"!",foes[num]);
          if(!do_save(foes[num],0)) {
          //if (!do_saving_throw(foes[num], "spell", 0)) {
             damage_targ(foes[num], foes[num]->return_target_limb(), sdamage,dam_type);
          } else {
             damage_targ(foes[num], foes[num]->return_target_limb(), to_int(sdamage/2),dam_type);
          }
          if(!stop) break;
       }
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
