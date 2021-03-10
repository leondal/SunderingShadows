// Magic Missile
// Updated 11/23/07 by Circe to not show number of missiles
// based on a suggestion by a player, Catherine
// removed interactive query so monsters are not showing number of missiles cast. Nienne, 09/08.
#include <spell.h>

inherit SPELL;

create() {
    ::create();
    set_spell_name("magic missile");
    set_spell_level(([ "mage" : 1, "magus" : 1 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS magic missile on TARGET");
    set_damage_desc("force");
    set_description("Magic missile will shoot darts of magical energy from your hand and they will fly towards your "
"target with the unfailing ability to hit it.  The damage it causes increases by level.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

spell_effect(int prof) {
    int num, numdarts;
    string hardness, mynum;

    spell_successful();
    if (interactive(caster)) {
        tell_object(caster,"%^YELLOW%^You point the palm of your hand at "+target->QCN+"!");
        tell_object(target,"%^YELLOW%^"+caster->QCN+" points the palm of "+caster->QP+" hand at you!");
        tell_room(place,"%^YELLOW%^"+caster->QCN+" points the palm of "+caster->QP+" hand at "+target->QCN+"!", ({caster, target}) );
    }
    if(target->query_property("spell shield")) {
        tell_object(caster,"%^YELLOW%^Darts of energy burst forth from your hand and fizzle harmlessly upon "
+target->QCN+"'s magical shield!");
        tell_object(target,"%^YELLOW%^Darts of energy burst forth from "+caster->QCN+"'s hand and fizzle harmlessly upon "
"your magical shield!");
        tell_room(place,"%^YELLOW%^Darts of energy burst forth from "+caster->QCN+"'s hand and fizzle harmlessly upon "
+target->QCN+"'s magical shield!", ({caster, target}) );
        TO->dest_effect();
        return;
    }
    if (CLEVEL)
        numdarts=to_int((CLEVEL+1)/2);
    else
        numdarts=to_int(((int)caster->query_guild_level("mage")+1)/2);

    switch (1+to_int(sdamage/numdarts)) {
    case 2:
        hardness="sting";
        break;
    case 3:
        hardness="shock";
        break;
    case 4:
        hardness="zap";
        break;
    default:
        hardness="blast";
        break;
    }
//    if (interactive(caster)) {
        if (numdarts > 1) {
           switch(numdarts){
              case 2..5:  mynum = "A few";
                          break;
              case 6..10:  mynum = "Many";
                           break;
              case 11..15: mynum = "A small swarm of";
                           break;
              default:  mynum = "A teeming legion of";
                        break;
           }
            tell_object(caster,"%^BOLD%^%^RED%^"+mynum+" ethereal darts shoot from your hand and "+hardness+" "+target->QCN+"!");
            tell_object(target,"%^BOLD%^%^RED%^"+mynum+" ethereal darts shoot from "+caster->QCN+"'s hand and "+hardness+" you!");
            tell_room(place,"%^BOLD%^%^RED%^"+mynum+
                      " ethereal darts shoot from "+caster->QCN+"'s hand and "+hardness+" "+target->QCN+"!",({caster, target}) );
        } else {
            tell_object(caster,"%^BOLD%^%^RED%^A dart of energy shoots from your hand and "+hardness+"s "+target->QO+"!");
            tell_object(target,"%^BOLD%^%^RED%^A dart of energy shoots from "+caster->QCN+"'s hand and "+hardness+"s you!");
            tell_room(place,"%^BOLD%^%^RED%^A dart of energy shoots from "+caster->QCN+"'s hand and "+hardness+"s "+target->QO+"!",({caster, target}) );
        }
    damage_targ(target, target->return_target_limb(), sdamage,"force");
    spell_successful();
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
