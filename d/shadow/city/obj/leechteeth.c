#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";
#include "/realms/titania/shadowcity/sewers/ssewers.h"


void create(){
  ::create();
  	set_name("nightmarish teeth");
  	set_id(({"teeth","nightmarish teeth"}));
  	set_short("%^BOLD%^%^WHITE%^nightmarish teeth%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a nightmarish set of teeth%^RESET%^");
  	set_long("%^BOLD%^%^WHITE%^The leech's teeth are a thing of nightmares. "+ 
	"The teeth are as sharp as razors, and there are so, "+ 
	"so many of them. The teeth fill the leech's ring-shaped mouth, "+
	"and it is truly terrifying.%^RESET%^");
	set_property("monsterweapon",1);
  	set_hit((:TO,"leech":));
  	set_weight(1);
  	set_value(5);
}

int leech(object targ){
	int i;
	object ob;
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;
        if((random(100) < 2 && !interactive(ETO)) || random(100) < 2){
	tell_object(targ,"%^RESET%^%^ORANGE%^The leech latches its hideous teeth into your flesh and "+
	"begins to drain your blood! %^BOLD%^%^RED%^Tear%^RESET%^%^ORANGE%^ it from your flesh before it drains you dry!");
    		targ->do_damage("torso",roll_dice(2,3));
    		ob = new(OBJ"leech.c");
 		ob->move(targ);
                if(objectp(ob) && objectp(targ)) { ob->hurt(targ); }
  }
  return 0;
}
