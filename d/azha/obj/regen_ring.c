// Ring of Regeneration
// Thorn@ShadowGate
// 970410
// regen_ring.c

// --- Ring Configuration ---
#define REGEN_HP       2
#define REGEN_TIME     5
#define MAX_HP_REGEN   500
// --------------------------

#include <std.h>
inherit "/std/armour";

int uses, old;
object protect;

int resist_magic();



create() {
  ::create();
  set_property("ring of regeneration", 1);
  set_name("ring");
  set_id(({
  "ring", "ring of regeneration",
  "wooden band", "tarnished band",
  "wooden ring", "band", "smooth wooden ring"
  }));
  set("short","a smooth wooden ring");
  set_long(
@AZHA
  This band appears to be made out of wood, without mark or
decoration.  It is smooth and varnished, and so will safely fit
on your finger without splinters, but who wants to wear a ring
made of wood?  You assume this to be a child's toy.
AZHA
);
  set_type("ring");
  set_ac(0);
  set_weight(0);
  set("value", 5);
  set_limbs(({"right hand","left hand"}));
  set_wear((:TO,"do_wear":));
  set_remove((:TO,"takeoff":));
  uses = MAX_HP_REGEN;
}

int do_wear()
{
        object *stuff, onering, env;
        int i,j, flag;

        stuff = TP->all_armour();
        j = sizeof(stuff);
        for(i=0;i<j;i++){
            if((string)stuff[i]->query_type() == "ring" &&
            stuff[i]->query_property("ring of regeneration")) {
                onering = stuff[i];
                flag = 1;
                break;
            }
        }
        if(flag){

            write("The magic of this ring reacts with the one already worn...\n"+
            "and they repel violently!");
            env = environment(TP);
            onering->move(env);
            return 0;
            return 0;
        }
        if(TP->query_hp() >= TP->query_max_hp()) {
        	write("You feel that you have no need to wear this ring now and you "+
        	      "remove it.");
        	return 0;
        }
        protect = TP;
        set_heart_beat(10);
        tell_object(TP, "%^GREEN%^The ring seems to come alive, "+
        "%^GREEN%^growing little leaves on short branches!%^RESET%^");
        TO->set_short("a %^BOLD%^GREEN%^living%^RESET%^ wooden ring");
        TO->set_long(
@AZHA
  On your finger is revealed a living band of wood where little
green leaves seem to have grown atop tiny sliver-sized branches
on the outside of the band.
AZHA
        );
        set_heart_beat(REGEN_TIME);
        return 1;
}

int heart_beat()
{
        if(uses <= 0) {
                tell_object(protect, "%^GREEN%^The ring seems to wilt "+
                "%^GREEN%^and suddenly turn to dust!%^RESET%^");
                set_heart_beat(0);
                if(!TO->remove()) destruct(TO);
                return 1;
        }
        if(protect->query_hp() >= protect->query_max_hp()) {
          tell_object(protect,
        	           "You feel that you have no need to wear this ring "+
        	           "now and you remove it.");
        	if(protect->is_monster()) { 
        	  if(!TO->remove()) destruct(TO);
        	  return 1;
        	}
        	protect->force_me("remove ring of regeneration");
        	return 1;
        }
        uses -= REGEN_HP;
        tell_object(protect, 
                    "%^BLUE%^You feel life return to your body.%^RESET%^");
        protect->do_damage(0,(0 - REGEN_HP));
        return 1;
}

int takeoff()
{
  set_heart_beat(0);
  tell_object(protect, 
              "%^GREEN%^The leaves turn brilliant shades of red and yellow "+
              "%^GREEN%^and suddenly the ring reverts to a lifeless state.%^RESET%^"
             );
  set("short","a smooth wooden ring");
  set_long(
@AZHA
  This band appears to be made out of wood, without mark or
decoration.  It is smooth and varnished, and so will safely fit
on your finger without splinters, but who wants to wear a ring
made of wood?  You assume this to be a child's toy.
AZHA
);
  protect = 0;
  return 1;
}

