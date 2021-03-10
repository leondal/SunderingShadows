/* originally by Grendel, adapted for nwps by *Styx*  10/12/02
whisper command sends the message here, per Grendel, using MONSTER for ease of heartbeat checks
*/

#include <std.h>
#include <daemons.h>

inherit MONSTER;

object caster, ecaster;
object target;
dest_me();

void create(){
    ::create();

    set_name("eavesdropper");
    set_property("no detect",1);
    set_id( ({"EavesDropper"}) );
    set_short(0);
    set_invis();
    add_limb("body","",0,0,0);
}

void init(){
    ::init();
    add_action("end_eavesdrop", "eavesdrop");
}

int move(mixed dest){
    ::move(dest);
}

set_caster(object cas){
    caster = cas;
    caster->set_property("eavesdropping", 1);
    ecaster = environment(caster);
}

set_targ(object targ) {
    target = targ;
    target->set_property("eavesdropper", TO);
}

set_caster_prof(int prof) {
    int caster_prof;
    caster_prof = prof;
}

object query_caster() {
    return caster;
}

void die(object ob) {
}

void heart_beat() {
    if(!objectp(TO))  return;
    if(!objectp(caster)) 		{ dest_me(); return; }
    if(environment(caster) != ecaster)  { dest_me(); return; }
    if(!objectp(target)) 		{ dest_me(); return; }
    if(environment(TO) != environment(target))  { dest_me(); return; }
}

dest_me() {
    if(objectp(caster)){
      caster->remove_property("eavesdropping");
      tell_object(caster, "You can no longer hear that conversation.");
    }
    if(objectp(target))
       target->remove_property("eavesdropper");
    remove();
}

int catch_eavesdrop(object spkr, object who, string msg, string lang) {
    int prof, i, j, bonus;
    string *words, ret = "";
    if(!objectp(caster))  { dest_me();  return 1; }
    if(!objectp(target))  { dest_me();  return 1; }

// no gaining or hearing double if you're already in the conversation
    if(caster == spkr || caster == who)         return 1;
// no eavesdropping
    if(!wizardp(caster)) {
	if(wizardp(spkr) || wizardp(who) || spkr->query_true_invis() ||
           who->query_true_invis())   		return 1;
    }
    if(wizardp(caster) || (avatarp(caster) && caster->query_lowest_level() > 99)) {
	 tell_object(caster, "%^BOLD%^%^CYAN%^You overhear "+spkr->query_cap_name()+
	     " whisper to "+who->query_cap_name()+":  %^RESET%^"+msg);
	 return 1;
    }
    prof = TP->query_skill("perception");
    if(!target->query_detecting_invis() && caster->query_invis()) bonus=4;
    if(FEATS_D->usable_feat(TP,"spot")) bonus = prof/5;
    if(TP->query("race")=="elf") bonus += 4;
    if(TP->query("race")=="half-elf") bonus += 2;
    if((target->query_skill("perception")) > prof+bonus) {

  if ((TP->query_hidden()) && (!random(4))) {
    if (objectp(present("TSR80",TP))) {
    present("TSR80",TP)->force_cancel();
    }
  }
      if(!random(3))
	tell_object(caster, "Your target moved, noticed you, or something/someone is in your way now.");
      if(!(random(prof) + caster->query_charisma())) {  // they won't always notice
	 tell_object(spkr, caster->query_cap_name()+"'s apparent interest is making you uncomfortable.");
	 tell_object(who, caster->query_cap_name()+"'s apparent interest is making you uncomfortable.");
      }
      dest_me();
      return 1;
    }
// you may miss it entirely from distractions/interference
    if(!random(10+prof)) return 1;
    if( interactive(spkr) || interactive(who) )
    msg= "daemon/language_d"->translate(msg, lang, caster);

// this essentially borrowed from T's language_d
// skipping words & using random affected by nwp prof for nwps by *Styx*
    words = explode(msg," ");
    j = sizeof(words);
    for(i=0;i<j;i++) {
      switch(random(30)+(prof*2)) {
	case 0:  words[i] = " ";	break;
	case 1:  words[i] = "_ _ _";	break;
	case 2:  words[i] = "_ _";	break;
	case 3:  words[i] = "_";	break;
	case 4..10:
	   words[i] = "/daemon/language_d"->fakeWord(lang);	break;
        default:  words[i];
      }
      ret+= words[i] + " ";
    }

    tell_object(caster, "%^BOLD%^%^CYAN%^You discern parts of "+spkr->query_cap_name()+" whispering to "+who->query_cap_name()+":  %^RESET%^"+msg);

    return 1;
}

int do_damage(string str, int i) {
    return 0;
}

int is_invincible() { return 1; }
int is_detectable() { return 0; }

int end_eavesdrop(string str){
    if(TP != caster) return 0;

    tell_object(TP, "You stop listening to "+target->query_cap_name());
    dest_me();
    return 1;
}
