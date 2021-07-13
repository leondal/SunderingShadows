//altered phantom guardians for psions
//~Circe~ 7/23/05

#include <std.h>
#include <magic.h>

inherit SPELL;

object *mons = ({});


void create() {
    ::create();
    set_spell_name("creation");
    set_spell_level(([ "psion" : 4 ]));
    set_discipline("shaper");
    set_spell_sphere("metacreativity");
    set_syntax("cast CLASS creation");
    set_description("This power creates psionic fighters to protect the psion.  These warriors do not truly exist but "
"are rather manifestations of the psion's own protective impulse.  The warriors will stand before the psion, mindlessly "
"protecting him in the event of attacks.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^BOLD%^%^CYAN%^"+caster->QCN+" grows still, focusing intently.";
}

int preSpell() {
    if (present(caster->query_name()+"monster",place)) {
        tell_object(caster,"You can't summon multiple sets of guardians.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    object ob;
    int i,num, mylevel;
    num = 0;
    mylevel = clevel;
    switch(mylevel){
       case 0..9: num = 1;
                   break;
       case 10..14: num = 2;
                    break;
       case 15..19: num = 3;
                    break;
       case 20..29: num = 4;
                    break;
       case 30..39: num = 5;
                    break;
       case 40..49: num = 6;
                    break;
       case 50..59: num = 7;
                    break;
       default: num = 8;
       break;
    }
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" draws forth two glittering "+
       "pieces of danburite and flings them to the ground!",caster);
    tell_object(caster,"%^BOLD%^%^WHITE%^You bring forth two glittering "+
       "pieces of danburite and fling them to the ground!");
    if(num == 1){
       tell_room(place,"%^BOLD%^%^CYAN%^In a flash, an ephemeral warrior "+
          "appears!%^RESET%^");
    }else{
       tell_room(place,"%^BOLD%^%^CYAN%^In a flash, ephemeral warriors "+
          "appear!%^RESET%^");
    }
    for (i=0;i<num;i++) {
       ob = new("/d/magic/mon/psychic_warrior");
       ob->move(place);
       ob->set_property("spelled", ({TO}) );
       ob->set_property("spell_creature", TO);
       ob->set_property("spell", TO);
       ob->set_damage_bonus(mylevel/4);
       ob->set_attack_bonus(mylevel/4);
       ob->set_max_hp((query_spell_level(spell_type)*2+clevel)*20+20);
       ob->set_hp(ob->query_max_hp());
       ob->set_exp(0);
       ob->add_id("summoned monster");
       ob->add_id(caster->query_name()+"monster");
       mons += ({ob});
       caster->add_follower(ob);
       if(objectp(caster)) ob->set_property("minion", caster);
       caster->add_protector(ob);
       tell_object(caster,"%^RED%^The psionic fighter stands in defense of you!");
       tell_room(place,"%^RED%^The psionic fighter stands in defense of "+caster->QCN+"!",caster);
    }
    addSpellToCaster();
    spell_successful();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 4;
    set_end_time();
    check();
    call_out("dest_effect",spell_duration);
}

void check()
{
    if(sizeof(mons))
    {
        foreach(object mon in mons)
        {
            if(mon && environment(mon) != environment(caster))
            {
                tell_room(environment(mon), "The psionic fighter seems to evaporate!");
                mon->move("/d/shadowgate/void");
                mon->remove();
                continue;
            }
            
            caster->add_protector(mon);
            caster->add_follower(mon);
        }
    }
    else
    {
        tell_object(caster, "Your psionic fighters vanish!");
        dest_effect();
        return;
    }
    
    call_out("check", 5);
}
    
void dest_effect() {
    int i;
    for (i=0;i<sizeof(mons);i++) {
        if (objectp(mons[i])) {
            caster->remove_protector(mons[i]);
            mons[i]->die();
        }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
