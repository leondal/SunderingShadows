//"breath weapon" for the psion that does acid damage and
//continues to burn.  ~Circe~ 7/25/05
#include <spell.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

object tempob, *foes, *removefoes;
int dmg, x, y, bonus;

void create() {
    ::create();
    set_spell_name("breath of the black dragon");
    set_spell_level(([ "psion" : 6, "psywarrior" : 6 ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS breath of the black dragon on TARGET");
    set_description("This power allows the psion an acidic breath weapon, which can be directed once at a target and "
"those surrounding him.  Thereafter, those hit by the acid continue to burn until the acid has run its course.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
    splash_spell(1);
}

string query_cast_string() {
    return "%^BOLD%^%^GREEN%^"+caster->QCN+" focuses on a peridot, and it "+
       "crumbles to a fine powder!";
}

void spell_effect(int prof) {
    if(!objectp(target) || !present(target,environment(caster))){
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }
    spell_successful();
    dmg = sdamage;

    foes = target_selector();

    if (member_array(target,foes) != -1)
        foes -= ({target});



    if(interactive(caster)){
       tell_object(caster,"%^BOLD%^%^BLACK%^You spew forth a ghastly "+
       "stream of %^GREEN%^acid%^BLACK%^, directed at "+target->QCN+"!");
    }
    tell_object(target,"%^BOLD%^%^BLACK%^With horror, you watch "+
       ""+caster->QCN+" spew forth a stream of %^GREEN%^acid "+
       "%^BLACK%^directly at you!");
    tell_room(environment(caster),"%^BOLD%^%^BLACK%^The air fills "+
       "with a %^GREEN%^green mist %^BLACK%^as "+caster->QCN+" "+
       "spews forth a stream of %^GREEN%^acid %^BLACK%^directed at "+
       ""+target->QCN+"!",({target,caster}));
    if(do_save(target,0)) {
    //if("/daemon/saving_d"->saving_throw(target,"spell")){
       damage_targ(target,target->return_target_limb(),(dmg/2),"acid");
    }else{
       damage_targ(target,target->return_target_limb(),dmg,"acid");
    }
    y=2+to_int((clevel-5)/2);
    if (sizeof(foes) < y)
        y = sizeof(foes);
    for (x=0;x<y;x++) {
        tempob=foes[random(sizeof(foes))];
        if(do_save(tempob,0)) {
        //if ("/daemon/saving_d"->saving_throw(tempob, "spell")){
            foes -= ({tempob});
        }
    }
    removefoes = ({}); //setting up to revoke anyone with the dot effect already on them, as this stacks out of control! N, 5/11.
    for(x=0;x<sizeof(foes);x++){
      if(foes[x] && foes[x]->query_property("black dragon breath",1)) removefoes += ({ foes[x] });
    }
    foes -= removefoes;

    if(sizeof(foes)) {
      for(x=0;x<sizeof(foes);x++){
        if (!objectp(foes[x])) continue;
        tell_room(environment(foes[x]),"%^BOLD%^%^BLACK%^The "+
           "%^GREEN%^acid %^BLACK%^eats away at "+foes[x]->QCN+"'s "+
           "flesh!",foes[x]);
        tell_object(foes[x],"%^BOLD%^%^BLACK%^A fine mist of "+
           "%^GREEN%^acid %^BLACK%^settles on you, eating away "+
           "at your flesh!");
        foes[x]->set_property("black dragon breath",1);
        if(do_save(foes[x],0))
        //if ("/daemon/saving_d"->saving_throw(foes[x], "spell"))
            damage_targ(foes[x], foes[x]->return_target_limb(), to_int(dmg/2),"acid");
        else
            damage_targ(foes[x], foes[x]->return_target_limb(), dmg,"acid" );
      }
    }
    if(!target->query_property("black dragon breath")) {
        target->set_property("black dragon breath",1);
        foes += ({target});
    }
    bonus = 1 + to_int(clevel/12); //was 1+clevel/3, which is way
//too long since the spell can stack - toning down ~Circe~ 6/11/08
    call_out("burn_again", ROUND_LENGTH);
    spell_successful();
}

void burn_again(){
   if(sizeof(foes) < 1){
      dest_effect();
      return;
   }
   define_base_damage(-2);
   dmg = sdamage;
   for(x=0;x<sizeof(foes);x++){
        if (!objectp(foes[x])) continue;
        tell_object(foes[x],"%^GREEN%^You feel the acid course through your "+
           "body, burning you further!");
        tell_room(environment(foes[x]),"%^GREEN%^"+foes[x]->QCN+"'s "+
           "skin seems to burn!",foes[x]);
        set_save("fort");
        if(do_save(foes[x],0))
        //if("/daemon/saving_d"->saving_throw(foes[x], "spell"))
            damage_targ(foes[x], foes[x]->return_target_limb(), to_int(dmg/2),"acid");
        else
            damage_targ(foes[x], foes[x]->return_target_limb(), dmg,"acid" );
   }
   if (bonus-- > 0)
        call_out("burn_again", ROUND_LENGTH);
    else
        for(x=0;x<sizeof(foes);x++){
          if(!objectp(foes[x])) continue;
          foes[x]->remove_property("black dragon breath");
        }
        dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
