#include <std.h>
inherit ARMOUR;
#define WAIT_TIME 14400
#define WAIT_TIME2 5

int used_time, used_time2, uses;
int query_uses(){return uses;}

void create() {
    ::create();
    set_name("wand");
    set("id",({"wand","wand of wonder"}));
    set("short",
	"Wand of "
	"%^BLUE%^w%^WHITE%^o%^RED%^n%^YELLOW%^d"
	"%^MAGENTA%^e%^GREEN%^r%^RESET%^"
    );
    set(
	"long","Thiwlkewour target."
    );
    set_value(200);
    set_weight (10);
    set_heart_beat(1);
}
void init() {
    ::init();
    add_action("aim_func","aim");
}
int aim_func(string str) {
    string who;
    object ob;
    if(!str) {
	notify_fail("Syntax: aim circlet at <target>\n");
	return 0;
    }
    if(!objectp(ETO)){
   return ;
   }
   if(uses>0){
   used_time = time();
   }
   if(WAIT_TIME < (time() - used_time)) {
   uses=3;
   }
   if(WAIT_TIME2 > (time() - used_time2)) {
   return;
   }
   if(!TO->query_worn()){
   return ;
   }
    }
    if(!query_worn()) return notify_fail("Wear it first?\n");

    if(sscanf(str,"circlet at %s",who)!= 1) {
        notify_fail("Syntax: aim circlet at <target>\n");
	return 0;
    }
    if(!(ob=present(who,environment(TP)))) {
	notify_fail("You must have a valid target.\n");
	return 0;
    }
	tell_room(ETP,
            "%^BOLD%^%^CYAN%^"+TPQCN+" touches the circlet and it "
	    "%^BOLD%^%^RED%^glows red %^BOLD%^%^CYAN%^as"+TPQCN+" focuses towards the "
	    +ob->query_cap_name()+"!%^RESET%^\n"
 	,({TP,ob}));
	tell_object(TP,
	    "%^BOLD%^%^YELLOW%^You feel a strange sensation in your body "
	    "as you focus on the "
	    +ob->query_cap_name()+"!%^RESET%^\n");
        new("/cmds/spells/p/_prismatic_spray")->use_spell(ETO,targ,20,100,"mage");
      used_time2 = time();
      uses --;
      }
      return 1;
        }

void set_used_time(int x) {
   used_time = x;
}

void set_used_time2(int y) {
   used_time2 = y;
}
