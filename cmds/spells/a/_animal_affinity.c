#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <clock.h>
inherit SPELL;

#define VALIDSTATS ({"wisdom","intelligence","charisma","strength","dexterity","constitution" })
int mydiff;

void create() {
    ::create();
    set_spell_name("animal affinity");
    set_spell_level(([ "psywarrior" : 2, "psion" : 1 ]));
    set_spell_sphere("psychometabolism");
    set_discipline("egoist");
    set_bonus_type("enhancement");
    set_syntax("cast CLASS animal affinity on <stat>");
    set_description("This power allows a psionic character to focus her "
       "mental acuity, granting a +4 enhancement bonus to one of her stats. Only one "
       "stat can be raised at a time.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell() {
    if(!arg){
       tell_object(caster,"You must specify a stat for this power!");
       return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    caster = CASTER;
    place = PLACE;
    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if(!arg){
       tell_object(caster,"You must specify a stat for this power!");
       dest_effect();
       return;
    }
    if(!stringp(arg)){
       tell_object(caster,"You must specify a stat for this power!");
       dest_effect();
       return;
    }
    
    target = caster;
    
    if (objectp(place)) place = environment(caster);
    /*
    if((int)caster->query_property("augmentation")){
      tell_object(caster,"%^YELLOW%^You are already under the influence of such a spell.%^RESET%^");
      dest_effect();
      return;
    }
    */
    if(member_array(arg,VALIDSTATS) == -1){
      tell_object(caster,""+capitalize(arg)+" is not a valid attribute to augment.");
      dest_effect();
      return;
    }
    switch(arg){
       case "wisdom":         tell_room(place,"%^RESET%^%^CYAN%^"+caster->QCN+"'s grow "
                                 "wide as an owl's and shimmer with wisdom.%^RESET%^",caster);
                              tell_object(caster,"%^RESET%^%^CYAN%^A heaviness settles in your "
                                 "soul as the wisdom of the owl descends upon you.%^RESET%^");
                              break;
       case "intelligence":   tell_room(place,"%^RESET%^%^ORANGE%^"+caster->QCN+" gives a sudden "
                                 "chatter eerily reminiscent of a monkey.%^RESET%^",caster);
                              tell_object(caster,"%^RESET%^%^ORANGE%^The cunning of the monkey "
                                 "fills you as you let out a wild chatter.%^RESET%^");
                              break;
       case "charisma":       tell_room(place,"%^RESET%^%^MAGENTA%^As "+caster->QCN+" whispers a "
                                 "single word, you swear you see the feathers of a %^GREEN%^p"
                                 "%^BOLD%^e%^RESET%^%^CYAN%^a%^BOLD%^c%^RESET%^%^CYAN%^o%^BOLD%^"
                                 "%^GREEN%^c%^RESET%^%^GREEN%^k %^RESET%^%^MAGENTA%^ruffle behind "
                                 ""+caster->QO+".%^RESET%^",caster);
                              tell_object(caster,"%^RESET%^%^MAGENTA%^You draw upon the essence of "
                                 "the %^GREEN%^p%^BOLD%^e%^RESET%^%^CYAN%^a%^BOLD%^c%^RESET%^%^CYAN%^o"
                                 "%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^k%^RESET%^%^MAGENTA%^, "
                                 "bolstering your charisma.%^RESET%^");
                              break;
       case "strength":       tell_room(place,"%^YELLOW%^A low, feral growl issues from "+
                                 ""+caster->QCN+" while "+caster->QP+" muscles take on "+
                                 "more definition!",caster);
                              tell_object(caster, "%^YELLOW%^You let forth a low, feral "+
                                 "growl as you feel the power of the "+
                                 "lion strengthen your sinews");
                              break;
       case "dexterity":      tell_room(place,"%^RESET%^%^GREEN%^"+caster->QCN+"'s eyes narrow "
                                 "to slits as "+caster->QS+" begins to move with greater agility.%^RESET%^",caster);
                              tell_object(caster,"%^RESET%^%^GREEN%^You give a feline stretch "
                                 "as you harness the dexterity of the cat.%^RESET%^");
                              break;
       default:               tell_room(place,"%^RESET%^%^RED%^"+caster->QCN+" gives a ponderous "
                                 "snuffle and lets out a low ursine roar.%^RESET%^",caster);
                              tell_object(caster,"%^RESET%^%^RED%^You let out a low ursine roar as "
                                 "you harness the constitution of the bear.%^RESET%^");
                              break;
    }

    mydiff = 4;
    mydiff = min(({ mydiff, (30 - target->query_stats(arg)) }));
    //if(caster->query_stats(arg) > 28) mydiff = 1;
    //if(caster->query_stats(arg) > 29) mydiff = 0;
    if(mydiff) {
      caster->add_stat_bonus(arg,mydiff);
      //caster->set_property("augmentation",1);
    }
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){

    if(objectp(caster) && mydiff) {
      tell_object(caster,"%^BOLD%^%^GREEN%^The spell of animal affinity fades from you.%^RESET%^");
      caster->add_stat_bonus(arg,(-1)*mydiff);
      //caster->set_property("augmentation",-1);
    }
     ::dest_effect();
    if(objectp(TO)) TO->remove();
}
