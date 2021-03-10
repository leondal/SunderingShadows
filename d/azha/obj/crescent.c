// Crescent of Domination
// Thorn@ShadowGate
// 970302
// crescent.c

#include <std.h>

inherit "/std/armour";

int uses, open;
object caster, place, target;
object clothes, remote;
int clevel, change, duration, quitting;


void check();
int dominate(string str);
void dest_effect();
int query_uses();



void create() {
   ::create();
   set_property("silver crescent", 1);
   set_name("silver crescent");
   set_id(({
      "crescent",
      "silver crescent",
      "silver crescent on a silver chain",
      "crescent of domination"
   }));
   set_short("%^BOLD%^%^WHITE%^a s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r "+
      "crescent on a chain%^RESET%^");
   set_long("%^BOLD%^This is a silver crescent, about three inches "+
      "tall from tip to tip, strung on thin, silver chain.  In the "+
	  "center of the crescent is set a single %^RESET%^%^GREEN%^"+
	  "emerald%^BOLD%^%^WHITE%^.  The quality of workmanship leaves "+
	  "much to be desired and is indicative of something found in a "+
	  "seedy booth at a bazaar.%^RESET%^");
   set_lore("You can immediately tell that this is an item of great "+
      "power, and untold wonders.  One thing goes through your mind "+
	  "while you have this.  Be careful, this much power can %^BOLD%^"+
	  "dominate %^RESET%^you as well as dominating others.");
   set_type("ring");
   set("value", 100);
   set_ac(0);
   set_weight(10);
   set_limbs(({"neck"}));
   set_property("lore difficulty",7);
   uses = random(2)+1;
   open = 0;
   set_size(-1);
}

void init()
{
   ::init();
   add_action("dominate", "dominate");
}

int dominate(string str)
{
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!uses) {
   	tell_object(TP, "The crescent dissolves into dust!\n");
   	if(!(this_object()->remove())) destruct(TO);
          	return 1;
   	}
  	if(!str) 
      	return notify_fail("Dominate who?\n");
   	if(!present(str,ETP)) return notify_fail("That is not here.\n");
    uses--;            
   new("/cmds/spells/d/_domination")->use_spell(TP,str,12,100,"mage");
return 1;
  }
/*
int heart_beat()
{
        if(uses <= 0) {
          set_heart_beat(0);
          tell_object(caster, "The crescent dissolves into dust!\n");
    if(!TO->remove()) destruct(TO);
    return 1;
  }
  uses--;
  return 1;
}
*/
int query_uses() { return uses; }

/*
int query_size(){
    if(!objectp(ETO) || !living(ETO)) return 2;
    return ETO->query_size();
}
*/
