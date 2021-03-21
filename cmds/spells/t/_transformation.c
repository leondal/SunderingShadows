// this spell also does set the caster to have BAB & # attacks as a fighter,
// but this is done directly in the bonus daemon. N, 5/15.
#include <priest.h>
inherit SPELL;

#define VALIDSTATS ({"strength","dexterity","constitution" })
int *statperks, feattracker;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("transformation");
    set_spell_level(([ "mage" : 6, "oracle" : 6, "magus" : 6 ]));
    set_mystery("battle");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS transformation");
    set_description("An experienced mage can use this spell to reshape their own body into a powerful fighting "
"machine. It adds extensive physical prowess to the caster, as well as a degree of resilience, but comes at a "
"price - while active, the mage will be unable to concentrate enough to use offensive spells. This spell does not "
"work alongside similarly powerful melee spells, such as rage, dance of a thousand cuts, or cunning insight.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
      "mage" : ([ "fur" : 1, "dung scrapings" : 1, ]),
    ]));
	set_helpful_spell(1);
}

int preSpell(){
   if((int)CASTER->query_property("raged") || (int)CASTER->query_property("transformed") || (int)CASTER->query_property("dance-of-cuts") || caster->query_property("shapeshifted")){
      tell_object(CASTER,"You are already under the influence of such a spell.");
      return 0;
   }
   return 1;
}

string query_cast_string() {
    return "%^BOLD%^%^WHITE%^"+caster->QCN+"'s expression grows fierce.%^RESET%^";
}

void spell_effect(int prof) {
    int i;
    if (!objectp(caster)) {
      dest_effect();
      return;
    }
    if (interactive(caster)) {
      tell_object(caster, "%^YELLOW%^You can feel yourself growing larger and stronger!%^RESET%^");
      tell_room(place,"%^YELLOW%^"+caster->QCN+" seems to grow larger and stronger before your eyes!%^RESET%^",caster);
    }
    spell_successful();
    statperks = ({});
    for(i = 0;i<sizeof(VALIDSTATS);i++) {
      if((int)caster->query_stats(VALIDSTATS[i]) > 29) statperks += ({0});
      if((int)caster->query_stats(VALIDSTATS[i]) == 29) statperks += ({1});
      if((int)caster->query_stats(VALIDSTATS[i]) < 29) statperks += ({2});
      caster->add_stat_bonus(VALIDSTATS[i],statperks[i]);
    }
    caster->add_saving_bonus("fortitude",5);
    caster->add_ac_bonus(4);
    caster->set_property("transformed",1);
    if(pointerp(caster->query_temporary_feats()))
    {
        if(member_array("martial weapon proficiency",(string*)caster->query_temporary_feats()) == -1)
        {
            caster->add_temporary_feat("martial weapon proficiency");
            feattracker = 1;
        }
    }
// call_out("dest_effect", 1800 + (clevel * 10));
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    int i;
    if(objectp(CASTER)) {
      tell_object(caster,"%^CYAN%^Your transformation ebbs away.%^RESET%^");
      tell_room(environment(caster),"%^CYAN%^"+caster->QCN+"'s powerful transformation fades away.%^RESET%^",caster);
      for(i = 0;i<sizeof(VALIDSTATS);i++) caster->add_stat_bonus(VALIDSTATS[i],(-1)*statperks[i]);
      caster->add_saving_bonus("fortitude",-5);
      caster->add_ac_bonus(-4);
      caster->set_property("transformed",-1);
      if(feattracker == 1) caster->remove_temporary_feat("martial weapon proficiency");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
