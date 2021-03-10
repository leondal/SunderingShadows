// fixed wear/unwear to use ETO, added obvious short-last change was 4/00  *Styx* 8/2003

#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit ARMOUR;
// FLG = 0;  don't see a need for this, so I'm commenting out  *Styx*

void init() {
    ::init();
    add_action("look_func","gaze");
}

void create(){
    ::create();
    set_name("eye");
    set_id(({"eye of vecna"}));
    set_obvious_short("%^BOLD%^%^BLACK%^Mummified eye%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^Eye of Vecna%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This strange mummified eye is a sickly, white "
	"colour.  Myth tells it to have strange visionary powers "
	"which were endowed to it by Vecna, a great mage who vanished "
	"mysteriously decades ago.  His gaze was indeed fearsome and who knows what "
	"evil powers might lie within for those foolish enough to attempt to use "
	"it.  Many have claimed to have found his burial ground and removed the " 
	"eye but so far all these tales have been lies. A small leather strap "
	"is fixed to it allowing one to "
	"wear it over their own left eye.%^RESET%^"
    );
    set_weight(15);
    set_value(2000);
    set_wear((: this_object(),"wearit" :));
    set_remove((:this_object(),"removeit" :));
    set_type("visor");
    set_limbs(({"head"}));
//    set_ac(6);
}
 
int wearit(){
    object me = ETO;
    if(!me) return 0;
    if((int)me->query_level() < 45 && !wizardp(me)) {
	message("info", "As you try to wear the eye it vanishes!",me);
        TO->remove();
	return 0;
    }
    message("info",
	"%^BOLD%^%^BLACK%^As you wear the eye of Vecna, it slowly attaches itself onto your own "
	"left eye. Your vision clouds, then slowly clears again.%^RESET%^"
    ,me);
    message("info",
	"%^BOLD%^%^BLACK%^"+me->query_cap_name()+"'s attaches a mummified eye to "
	+me->query_possessive()+" own left eye!%^RESET%^"
    ,environment(me),me);	
//    FLG = 0;
    return 1;
}
int removeit(){
    object me = ETO;
 
    if(!me) return 0;
    message("info",
	"%^BOLD%^%^BLACK%^You yank the eye of Vecna out of your left eye socket!%^RESET%^"
    ,me);
    message("info",
	"%^BOLD%^%^BLACK%^"+me->query_cap_name()+" suddenly yanks out "+me->query_possessive()+
	" left eye!%^RESET%^",environment(me),me);
 //   if(FLG == 0) {
 //       FLG = 1;
        me->do_damage("head",50+random(50));
      me->add_attacker(TO);
      me->continue_attack();
      me->remove_attacker(TO);
//    }
    return 1;
}
int look_func(string str) {
    object ob = this_object();
    object me = query_worn();
    int i,x,CHECK;
    object locale,*inv,*exits;
    string desc,where;
    if(!me) return 0; 
    if(me->query_paralyzed() > 0) return 0;
    if(me->query_disabled()) return 0;
  if(ETO->query_bound() || ETO->query_unconscious()){
  ETO->send_paralyzed_message("info",ETO);
  return 1;
  }
    if(str) return 0;
    if(!str) {
        message("info", "%^BOLD%^%^BLACK%^"
	    "You cast forth the gaze of death upon your surroundings.%^RESET%^"	,TP);	
        message("info", "%^BOLD%^%^BLACK%^"
            "You shudder as the gaze of death falls upon you." ,ETP,TP);
        locale = environment(me);
        desc = (string)locale->query_long()+"\n";
        inv = all_inventory(locale);
        desc += "\n";
        for(i=0; i<sizeof(inv); i++) {
	    CHECK = 0;
            if(!living(inv[i])) continue;
            if(inv[i]->query_invis() && !inv[i]->query_true_invis() && inv[i] != TP) {
	        desc += (string)inv[i]->query_true_name()+"\n";
	        CHECK = 1;
	    } else {
              if(inv[i] != TP) {
                desc += (string)inv[i]->query_short()+"\n";
                CHECK = 1;
              }
            }
            if(CHECK == 0) { 
                if(inv[i]->query_invis() && !inv[i]->query_true_invis() && inv[i] != TP) {
	            desc += (string)inv[i]->query_true_name()+"\n";
	        } else {
                  if(inv[i] != TP) {
                    desc += (string)inv[i]->query_short()+"\n";
                  }
                }
            }
        }
        message("info", ""+desc+"", TP);
        return 1;
    }
}

