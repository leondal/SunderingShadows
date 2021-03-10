#include <std.h>
#include <security.h>

inherit OBJECT;

#define LOGSTUFF 1
#define DAY 60*60*24

string owner;
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
    if (ETO->query_age() < (DAY * 1)) {
      tell_object(env,"The sword rejects your inexperience.");
#ifdef LOGSTUFF
      seteuid(UID_LOG);
      log_file("god_quest",capitalize(ETO->query_name()) + " SWORD REJECTED HOLDER "+ ctime(time()) +"\n");
      seteuid(geteuid(previous_object()));
#endif // LOGSTUFF
      TO->remove();
      return;
    }

   if ( owner != (string)holder->query_name() ) {
      tell_object(env,"The sword shimmers and vanishes!");
#ifdef LOGSTUFF
      seteuid(UID_LOG);
      log_file("god_quest",capitalize(ETO->query_name()) + " SWORD REJECTED HOLDER "+ ctime(time()) +"\n");
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
    if(TP->is_class("paladin") || TP->is_class("antipaladin") || (avatarp(TP)))
      return;
    if(newbiep(TP)) {
      write("The sword shimmers and vanishes, noticing your protection from the gods.");
#ifdef LOGSTUFF
	seteuid(UID_LOG);
	log_file("god_quest",capitalize(ETO->query_name()) + " (NEWBIE!) FAILED to bond with the sword on "+ ctime(time())  +"\n");
	seteuid(geteuid(previous_object()));
#endif // LOGSTUFF

      TO->remove();
      return;
    }
    if(interactive(ETO) && !owner) {
      if (TP->is_class("cavalier")) {
	owner = ETO->query_name();
	write("You feel the sword bond with you.");
#ifdef LOGSTUFF
	seteuid(UID_LOG);
	log_file("god_quest",capitalize(ETO->query_name()) + " BONDED with the sword on "+ ctime(time())  +"\n");
	seteuid(geteuid(previous_object()));
#endif // LOGSTUFF
	return;
      } else {
//	write("The sword shimmers and vanishes.");  moved into call_out *Saide's fix* 12/30/03, last change 10/04/03
#ifdef LOGSTUFF
	seteuid(UID_LOG);
	log_file("god_quest",capitalize(ETO->query_name()) + " FAILED to bond with the sword on "+ ctime(time())  +"\n");
	seteuid(geteuid(previous_object()));
#endif // LOGSTUFF
  // remove moved into call_out *Saide's fix* 12/30/03, last change 10/04/03
	//TO->remove();
	call_out("remove_sword",0,TP);
	return;
      }
    }
}

int remove_sword(object who) {
   tell_room(environment(who), "The sword shimmers and vanishes.");
   TO->remove();
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
