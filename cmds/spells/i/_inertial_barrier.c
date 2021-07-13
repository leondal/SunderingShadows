#include <priest.h>
#include <daemons.h>
inherit SPELL;

int feattracker, feattracker2;

void create() {
    ::create();
    set_spell_name("inertial barrier");
    set_spell_level(([ "psywarrior" : 4, "psion" : 4 ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS inertial barrier");
    set_description("Using this power, the psionic character bolsters "
       "his physical defenses, gaining some resistance to "
       "physical attacks.  The spell does not stack with the damage "
       "resistance and improved damage resistance feats.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    set_helpful_spell(1);
}

int preSpell(){
	string *TmpFeats;
	TmpFeats = caster->query_temporary_feats();
	if(!sizeof(TmpFeats)) TmpFeats = ({});
   	if(member_array("damage resistance",TmpFeats) != -1 || member_array("improved damage resistance",TmpFeats) != -1) 
	{
	      tell_object(CASTER,"You are already under the influence of a similar effect.");
      	return 0;
   	}
   	return 1;
}

void spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    feattracker = 0;
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^BLACK%^As you ready your body to reject "
           "physical attacks, the air around you glimmers a faint %^MAGENTA%^r"
           "%^BLACK%^o%^MAGENTA%^se %^BLACK%^c%^MAGENTA%^ra%^BLACK%^ckl%^MAGENTA%^"
           "e%^BLACK%^d with bl%^MAGENTA%^a%^BLACK%^ck.%^RESET%^");
        tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+"%^BOLD%^%^BLACK%^'s eyes "
           "take on a faraway look as the air around "+caster->QO+" glimmers a "
           "faint %^MAGENTA%^r%^BLACK%^o%^MAGENTA%^se %^BLACK%^c%^MAGENTA%^ra%^BLACK%^"
           "ckl%^MAGENTA%^e%^BLACK%^d with bl%^MAGENTA%^a%^BLACK%^ck.%^RESET%^%^RESET%^",caster);
    }
    if(pointerp(caster->query_temporary_feats()))
    {
        if(member_array("damage resistance",(string*)caster->query_temporary_feats()) == -1) 
        {
            caster->add_temporary_feat("damage resistance");
            feattracker = 1;
        }
        if(member_array("improved damage resistance",(string*)caster->query_temporary_feats()) == -1) 
        {
            caster->add_temporary_feat("improved damage resistance");
            feattracker2 = 1;
        }
    }
    spell_successful();
    addSpellToCaster();
}

void dest_effect() {
    if(objectp(CASTER)) {
      tell_object(caster,"%^RESET%^%^MAGENTA%^Your mental defenses falter, "
         "making you vulnerable to physical attacks once more.%^RESET%^");
      if(feattracker == 1) caster->remove_temporary_feat("damage resistance");
      if(feattracker2 == 1) caster->remove_temporary_feat("improved damage resistance");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
