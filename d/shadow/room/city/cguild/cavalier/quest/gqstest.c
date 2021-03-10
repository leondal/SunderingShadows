#include <std.h>
#include <security.h>

inherit OBJECT;

#define LOGSTUFF 1
#define DAY 60*60*24

object owner;
void create() {
    ::create();
    set_name("%^BOLD%^%^WHITE%^Sword of the %^YELLOW%^Questing %^WHITE%^Knight");
    set_id(({"god_quest_sword","god_quest","sword","relic"}));
    set_short("%^BOLD%^%^WHITE%^Sword of the %^YELLOW%^Questing %^WHITE%^Knight");
    set_long("This sword is a fine work of art, though not meant for combat, it is a %^ORANGE%^relic%^RESET%^ utilized in the quest to join the service of a god as a %^BOLD%^%^CYAN%^holy%^RESET%^, or an %^BOLD%^%^RED%^unholy%^RESET%^ knight.");
    set_weight(7);
    set_value(100);
    set_heart_beat(10);
}

void heart_beat() {
    object holder,env;
    env = ETO;
    if(!objectp(ETO)) return;
    if (avatarp(ETO)) return;
    if (ETO->is_paladin() || ETO->is_antipaladin())
      return;
    if(objectp(env) && living(env) && interactive(env) ) {
        holder = env;
    } else {
      return;
    }
    if (ETO->query_age() < (DAY * 3)) {
      tell_object(env,"The sword rejects your inexperience.");
#ifdef LOGSTUFF
      seteuid(UID_LOG);
      log_file("god_quest",capitalize(TPQN) + " SWORD REJECTED HOLDER (age) "+ ctime(time()) +"\n");
      seteuid(geteuid(previous_object()));
#endif // LOGSTUFF
      TO->remove();
      return;
    }
    if( holder != owner) {
      tell_object(env,"The sword shimmers and vanishes!");
#ifdef LOGSTUFF
      seteuid(UID_LOG);
      log_file("god_quest",capitalize(TPQN) + " SWORD REJECTED HOLDER "+ ctime(time()) +"\n");
	seteuid(geteuid(previous_object()));
#endif // LOGSTUFF

      TO->remove();
        return;

    } else {
      return;
    }
}

void init() {
    ::init();
    if (!objectp(ETO)) return;
    if (!userp(ETO)) return;
    //if(TP->is_class("paladin") || TP->is_class("antipaladin") || (avatarp(TP)))
    //return;
    if(newbiep(TP)) {
      write("The sword shimmers and vanishes, noticing your protection from the gods.");
#ifdef LOGSTUFF
	seteuid(UID_LOG);
	log_file("god_quest",capitalize(TPQN) + " (NEWBIE!) FAILED to bond with the sword on "+ ctime(time())  +"\n");
	seteuid(geteuid(previous_object()));
#endif // LOGSTUFF

      TO->remove();
      return;
    }
    if(interactive(TP) && !owner) {
      if (TP->is_class("cavalier")) {
	owner = TPQN;
	write("You feel the sword bond with you.");
#ifdef LOGSTUFF
	seteuid(UID_LOG);
	log_file("god_quest",capitalize(TPQN) + " BONDED with the sword on "+ ctime(time())  +"\n");
	seteuid(geteuid(previous_object()));
#endif // LOGSTUFF
	return;
      } else {
	write("The sword shimmers and vanishes.");
#ifdef LOGSTUFF
	seteuid(UID_LOG);
	log_file("god_quest",capitalize(TPQN) + " FAILED to bond with the sword on "+ ctime(time())  +"\n");
	seteuid(geteuid(previous_object()));
#endif // LOGSTUFF
	TO->remove();
	return;
      }
    }
}

int move(mixed towhere) {
  mixed fromwhere;
  int movecode;
  int nolog=0;
  fromwhere=ETO;
  if (!objectp(fromwhere)) {
    nolog=1;
    fromwhere=ETP;
  }
    movecode=::move(towhere);

#ifdef LOGSTUFF
  if (!nolog && !movecode && (towhere == ETP) && objectp(fromwhere) && userp(fromwhere))
log_file("god_quest","Sword was dropped by "+ capitalize(fromwhere->query_name()) +" on "+ ctime(time()) +".\n");
  if (!nolog && !movecode && (fromwhere == ETP))
  log_file("god_quest","Sword was taken by "+capitalize(towhere->query_name())+" on "+ ctime(time()) +".\n");
  if (!nolog && !movecode && objectp(fromwhere) && userp(fromwhere) && objectp(towhere) && userp(towhere))
    log_file("god_quest","Sword moved from "+ capitalize(fromwhere->query_name()) +" to "+capitalize(towhere->query_name())+" on "+ ctime(time()) +".\n");
#endif // LOGSTUFF

  return movecode;
}
