#include <std.h>

inherit ARMOUR;

nosave int prev_blind, isblinded, isused;
nosave object who;

void create() {
  ::create();
  set_name("blindfold");
  set_short("A blindfold");
  set_long("This is a blindfold. It is meant to blind people.");
  set_value(0);
  set_type("sheath");
  set_weight(0);
  set_limbs(({"head"}));
  set_remove((:TO, "remove_me" :));
  isused = 0;
}

void init() {
  ::init();
  if (wizardp(TP))
    return;
  if (isused)
    return;
  isused = 1;
  who=ETO;
  if ( (who->query_unconscious()) || (who->query_bound()) ) {
  // Need to wear it anyhow...
  who->equip_armour_to_limb(TO,({"head"}));
  message("other_action", (string)who->query_cap_name()+" wears "+TO->query_short()+".", environment(who), ({ who }));
  TO->set_worn(who);
  TO->set_actualLimbs("head");
  }  else  {
  who->force_me("wear blindfold");
  }
  if ( ((int)who->query_blind()) && ((int)who->query_blind() != 10) )   prev_blind=1;
  else prev_blind = 0;
  who->set_blind(0);
  who->set_blind(10+prev_blind);

  isblinded = 1;
  set_heart_beat(1);
}

void heart_beat() {
  int blind_level;
  if (!objectp(ETO)) {
    TO->remove();
    return ;
  }
  if (!isblinded || (ETO != who) || (!objectp(who)) ) {
      TO->remove();
      return;
    }
  if ((blind_level = (int)who->query_blind()) != 10+prev_blind) {
    if (blind_level > 10+prev_blind)
      prev_blind = 1;
    else
      prev_blind = 0;
    who->set_blind(0);
    who->set_blind(10+prev_blind);
  }
  if (!random(160)) {
    if (prev_blind)
      tell_object(who,"You feel the blindfold slip but you're blind underneath it!");
    else {
      who->set_blind(0);
      tell_object(who,"The blindfold slips and allows you to glance around.");
   message("my_environment",environment(who)->query_long(), ({who}));
      who->set_blind(10+prev_blind);
    }
  }
}

int remove() {
  if (objectp(TO))
    TO->set_not_equipped();
  set_heart_beat(0);
  if (objectp(who) && isblinded) {
    who->set_blind(0);
    if (prev_blind)
      who->set_blind(prev_blind);
    isblinded=0;
  }
  return ::remove();
}

int remove_me() { call_out("disintegrate_me",0); return 1; }

disintegrate_me() { TO->remove();}
