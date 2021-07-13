#include <spell.h>
#include <daemons.h>
inherit SPELL;

object tempob;
object *foes;
int dmg, x, y;

void create() {
    ::create();
    set_spell_name("ultrablast");
    set_spell_level(([ "psion" : 7 ]));
    set_spell_sphere("telepathy");
    set_damage_desc("Mental damage to enemies");
    set_syntax("cast CLASS ultrablast on TARGET");
    set_description("A psion begins manifesting this spell by creating a psychic 'grumbling' that toys with the minds of "
"those nearby.  The psion allows his brain to emit an earsplitting shriek that resounds in the minds of the one targetted "
"and those around him.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_save("will");
}

string query_cast_string() {
    return "%^BOLD%^%^BLACK%^You sense a grumbling originating from "+
       ""+caster->QCN+", somehow causing the area around "+caster->QO+" to shake!";
}

spell_effect(int prof) {
    object *tmp;
    if(!objectp(target) || !present(target,environment(caster))){
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }
    spell_successful();
    dmg = sdamage;
    foes = target_selector();

    if(caster->is_player()) { // added to make perfect caster useful. N, 6/11.
      tmp = target->query_attackers();
      tmp = filter_array(tmp,"live_filter",TO);
      foes += tmp;
    }
    if (member_array(target,foes) != -1)
        foes -= ({target});

    if(interactive(caster)){
       tell_object(caster,"%^BOLD%^%^CYAN%^Your mind releases a "+
          "horrid shriek directed at "+target->QCN+"!");
    }
    tell_object(target,"%^BOLD%^%^CYAN%^A horrid, jarring shriek "+
       "fills your mind, sending you reeling in pain and clasping "+
       "your ears!");
    tell_room(environment(caster),"%^BOLD%^%^CYAN%^"+target->QCN+" "+
       "reels back in pain and clasps "+target->QP+" ears as the "+
       "echo of a shriek rises in the air!",target);
    damage_targ(target,target->return_target_limb(),dmg,"mental");

    for(x=0;x<sizeof(foes);x++){
        dmg = sdamage;
        if (!objectp(foes[x])) continue;
        if(foes[x]->query_true_invis()) continue;
        if(foes[x] == target) continue;
        tell_room(environment(foes[x]),"%^RESET%^%^CYAN%^"+foes[x]->QCN+" "+
           "reels back in pain and clasps "+foes[x]->QP+" ears!",foes[x]);
        tell_object(foes[x],"%^RESET%^%^CYAN%^A horrid, jarring shriek "+
           "fills your mind, sending you reeling in pain and clasping "+
           "your ears!");
        damage_targ(foes[x], foes[x]->return_target_limb(), dmg,"mental" );
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
