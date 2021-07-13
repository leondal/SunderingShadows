// Incite Bravery
// Based on rally, melee version only
#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

object *cur_players;
string myname;
int mod, duration;
void check();
void do_bravery();

void create() {
    ::create();
    set_author("circe");
    set_spell_name("incite bravery");
    set_spell_level((["psywarrior" : 2 ]));
    set_spell_sphere("telepathy");
    set_bonus_type("morale");
    set_syntax ("cast CLASS incite bravery");
    set_description("Upon manifesting this power, the psionic character "
       "projects courageous impulses into his allies, bolstering their "
       "confidence and improving their martial prowess. This power does "
       "not stack with the bard's rally ability.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

void spell_effect(int prof){
    object *inven, *partied;
    int i;
    if((int)caster->query_property("using rally") > time()){ // retaining the same variables so they won't stack
        tell_object(caster,"You can't try to incite bravery in your allies again yet!");
        dest_effect();
        return;
    }
    inven = ({});
    cur_players = ({});
    partied = PARTY_D->query_party_members(caster->query_party());
    if(!sizeof(partied)) partied = ({ caster });

    if(sizeof(all_living(environment(caster)))) { inven += all_living(environment(caster)); }
    for(i = 0;i<sizeof(inven);i++) {
        if(userp(inven[i]) && (member_array(inven[i],partied) != -1) && !inven[i]->query_true_invis())
          cur_players += ({inven[i]});
    }
    tell_object(caster,"%^BOLD%^%^BLUE%^You start inspiring bravery in your companions.%^RESET%^");
    tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" begins to inspire "+caster->QP+" companions.%^RESET%^",caster);
    caster->remove_property("using rally");
    call_out("do_bravery",ROUND_LENGTH);
    addSpellToCaster();
    spell_successful();
    return;
}

void do_bravery(){
    int i;
    object *inv;
    string myclass;
    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    ::execute_attack();
    inv = ({});
    place = environment(caster);
    if(caster->is_class("psywarrior")){
       myclass = "psywarrior";
    }else if(caster->is_class("psion")){
       myclass = "psion";
    }else{
       tell_object(caster,"You must be a psionic character to manifest this power!");
       dest_effect();
       return;
    }
    mod = ((int)caster->query_guild_level(myclass) +9)/10;
    duration = 150 + ((int)caster->query_guild_level(myclass)*10);
    for(i=0;i<sizeof(cur_players);i++) {
        if(!objectp(cur_players[i])) continue;
        if(!present(cur_players[i],place)) continue;
        if(cur_players[i]->query_property("raged")) {
          tell_object(cur_players[i],"%^BOLD%^%^RED%^You are already in a frenzy and feel no different!");
          continue;
        }
   	  if(pointerp(cur_players[i]->query_property("rally")) &&
          member_array(caster->query_name(),cur_players[i]->query_property("rally")) != -1) continue;
        inv += ({ cur_players[i] });
    }
    cur_players = inv;
    myname = (string)caster->query_name();

    for(i=0;i<sizeof(cur_players);i++){
       if(!objectp(cur_players[i])) continue;
       cur_players[i]->add_attack_bonus(mod);
       cur_players[i]->add_damage_bonus(mod);
       cur_players[i]->set_property("rally",({ myname }));
       if(cur_players[i] == caster){
          tell_object(caster,"%^BOLD%^%^CYAN%^You feel a surge of bravery "
             "coursing through your veins.%^RESET%^");
       }else{
          tell_object(cur_players[i],"%^BOLD%^%^CYAN%^Your bravery is "
             "bolstered thanks to "+caster->QCN+"'s efforts!%^RESET%^");
       }
    }
    tell_object(caster,"%^BOLD%^%^CYAN%^You finish inspiring your comrades.%^RESET%^");
    caster->set_property("using rally",time() + duration);
    call_out("check",ROUND_LENGTH);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void check(){
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    call_out("check",ROUND_LENGTH);
}

void dest_effect(){
    int i;
    string *holding;
    mod = mod*(-1);
    if(objectp(caster)) { caster->remove_property("using rally"); }
    if(!sizeof(cur_players)) {
      ::dest_effect();
      if(objectp(TO)) TO->remove();
      return;
    }
    for(i=0;i<sizeof(cur_players);i++){
       if(!objectp(cur_players[i])) continue;
       tell_object(cur_players[i],"You feel the inspired bravery leave you in a rush.");
       cur_players[i]->add_attack_bonus(mod);
       cur_players[i]->add_damage_bonus(mod);
       holding = cur_players[i]->query_property("rally");
       if(sizeof(holding)) {
         if(member_array(myname,holding) != -1) holding -= ({ myname });
       }
       cur_players[i]->remove_property("rally");
       if(sizeof(holding)) cur_players[i]->set_property("rally",holding);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
