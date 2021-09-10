//Took away the material component...blink does not have one and
//is more powerful than this spell.  Circe 8/21/05
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int cmychance,chance;

void create() {
    ::create();
    set_spell_name("concealing amorpha");
    set_spell_level(([ "psion" : 2, "psywarrior" : 2 ]));
    set_spell_sphere("metacreativity");
    set_syntax("cast CLASS concealing amorpha");
    set_description("When a psionic character manifests concealing amorpha, he draws ectoplasm from the Astral Plane to create a sort "
"of armor.  While it does not offer any physical protection, the translucent armor does make it more difficult to see "
"where exactly the psion's body lies, granting him protection by fooling the eyes of the onlooker.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string(){
   return "%^MAGENTA%^"+caster->QCN+" focuses on a %^BOLD%^g"+
      "%^RESET%^%^MAGENTA%^l%^BOLD%^i%^RESET%^%^MAGENTA%^t"+
      "%^BOLD%^t%^RESET%^%^MAGENTA%^e%^BOLD%^r%^RESET%^"+
      "%^MAGENTA%^i%^BOLD%^n%^RESET%^%^MAGENTA%^g crystal.";
}

int preSpell() {
    if (caster->query_property("amorpha") || caster->query_property("timeless body")) {
//together these were broken, stacking regularly 100% miss chance. N, 4/14
        tell_object(caster, "You are already protected by a spell of concealment.");
        return 0;
    }
    if (caster->query_blinking()) {
        tell_object(caster, "You can't maintain such a spell while blinking.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    int armor, mylevel;

    if(FEATS_D->usable_feat(caster,"armored manifester") || FEATS_D->usable_feat(caster,"eldritch conditioning")){
       armor = 0;
    }else if(!caster->is_ok_armour("mage") && !FEATS_D->usable_feat(caster,"armored caster")){
       armor = 1;
    }
    if(armor){
       tell_object(caster,"The power cannot offer protection while you "+
          "wear such armor.");
       if(objectp(TO)) TO->remove();
       return;
    }
    if (caster->query_property("amorpha")) {
        tell_object(caster, "You are already protected by the power "+
           "concealing amorpha.");
        if(objectp(TO)) TO->remove();
        return;
    }
    tell_object(caster,"%^MAGENTA%^You summon forth strands "+
       "of ectoplasm, weaving them with molecules of water "+
       "to form a %^BOLD%^%^CYAN%^translucent %^RESET%^%^MAGENTA%^"+
       "layer of protection.");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" seems to pull "+
       "strands out of thin air, weaving them with tiny particles "+
       "of water to form a %^BOLD%^%^CYAN%^translucent %^RESET%^"+
       "%^MAGENTA%^layer of protection.",caster);
    cmychance = 30; //changing to a flat 30% miss chance per new blink. Stacking broken with timeless body. N, 4/14
    caster->set_property("spelled", ({TO}) );
    caster->set_property("amorpha",1);
    caster->set_missChance(caster->query_missChance()+ cmychance);
    spell_successful();
    addSpellToCaster();
    call_out("test",2);
    mylevel = clevel;
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void test(){
    int armor;
    if (!objectp(TO) || !objectp(caster))
        return;
    if(FEATS_D->usable_feat(caster,"armored manifester") || FEATS_D->usable_feat(caster,"eldritch conditioning")){
       armor = 0;
    }else if(!caster->is_ok_armour("mage") && !FEATS_D->usable_feat(caster,"armored caster")){
       armor = 1;
    }
    if(armor){
       tell_object(caster,"The power cannot offer protection while you "+
          "wear such armor.");
       if(objectp(TO)) TO->remove();
       return;
    }
    call_out("test", 5);
}

void dest_effect() {
    remove_call_out("test");
    if(objectp(caster)){
       tell_object(caster,"%^CYAN%^You feel the ectoplasmic protection "+
          "fade away.");
       tell_room(environment(caster),"%^CYAN%^"+caster->QCN+" suddenly seems more "+
          "solid as "+caster->QP+" translucent layer of protection "+
          "fades away.",caster);
       chance = (int)caster->query_missChance()-cmychance;
       caster->set_missChance(chance);
       caster->remove_property("amorpha");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}
