// Modified by Pator@ShadowGate
// August 25 1995
//changed criteria argument to check for issingleclass so dual classers could use it -tsera

#include <priest.h>
#include <daemons.h>

object vestments;

void create() {
    ::create();
    set_author("cythera/pator");
    set_spell_name("magic vestments");
    set_spell_level(([ "cleric" : 3,"inquisitor" : 3, "oracle" : 3 ]));
    set_mystery("battle");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS magic vestments");
    set_description("Calling for a blessing from their deity, the cleric can recieve magical vestments that will protect "
"them for a time.  The spell will not work if the priest is wearing any form of armor on their torso, including leather, "
"chain, and armour types.  The magical vestments will grow in strength as the priest's power grows, as will the duration"
".  The vestments are meant only for the cleric, and can not be given to another.  To do so usually brings about the "
"wrath of their god upon the priest.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

int preSpell() {
    object *armour;
    int j, i, flag;
    armour = caster->query_armour("torso");
    j = sizeof(armour);
    for (i=0;i<j;i++)
    {
        if(!FEATS_D->usable_feat(caster,"armored caster"))
        {
            if((string)armour[i]->query_type() == "leather") flag = 1;
        }
        else if ((string)armour[i]->query_type() == "chain" || (string)armour[i]->query_type() == "armour")
        {
            flag=1;
        }
	}
    if(flag) {
        tell_object(caster,"%^BOLD%^You are already wearing armour!%^RESET%^");
        return 0;
    }
	if((vestments=present("vestments",CASTER))&&vestments!=TO){
   	tell_object(CASTER,"You have already recieved the protection from"+
	""+capitalize(CASTER->query_diety())+".");
   	return 0;
   	}
   /*if ((sizeof(CASTER->query_classes()) > 1) && !avatarp(CASTER)) {
   	tell_object(CASTER,"You have not committed yourself solely to "+
		""+capitalize(CASTER->query_diety())+" and therefor your prayer goes unnoticed.");
   return 0;
   }*/
  return 1;
}


string query_cast_string() {
    return "%^BOLD%^%^BLUE%^"+caster->QCN+" presses "+caster->QP+" hands together and prays!";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^CYAN%^Your prayer is heard. The air around"+
		" you glows as you feel your deity offering you protection.");
        tell_room(place,"%^CYAN%^The air around "+caster->QCN+" glows, as "+
 		""+caster->QS+" receives the protection of "+caster->QP+" deity.",caster);
    }
    vestments = new("/d/magic/obj/vestments.c");
    vestments->move(caster);
    caster->remove_paralyzed();
    caster->force_me("wear vestments");
    spell_successful();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 6;
    set_end_time();
    call_out("dest_effect",spell_duration);
     addSpellToCaster();
}

void dest_effect() {
    if (objectp(vestments) && objectp(caster)) {
        tell_object(caster,"%^BOLD%^The vestments fade away as your blessing ends.");
        tell_room(environment(caster),"%^CYAN%^The vestments fade away from "+caster->QCN+"'s body.",caster);
        vestments->remove();
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
