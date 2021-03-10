//Removed ac(1) and added another + to make it +3 Octothorpe 5/27/09
//Added Lore and Cleaned up Code - Cythera 8/05
#include <std.h>
inherit "/d/common/obj/armour/shield.c";

void create() {
    	::create();
	set_name("gibbering shield");
  	set_id(({"shield","gibbering shield","gibbering"}));
	set_obvious_short("%^BOLD%^%^BLUE%^A round shield with a demonic face%^RESET%^");
  	set_short("%^BOLD%^%^BLUE%^G%^RED%^i%^BLUE%^bbe%^RED%^r%^BLUE%^ing Shield%^RESET%^");
    	set_long("%^BOLD%^%^BLUE%^This round steel shield has the image of"+
		" a %^RED%^demonic face%^BLUE%^ on its front.  A large hook"+
		" nose rests in the center of the image's face.  "+
		"Curling %^YELLOW%^goat-like horns%^BLUE%^ pierce either "+
		"side of his forehead, curling inwards. His large %^RED%^red"+
		" eyes %^BLUE%^gaze around with a hungry look burning in them."+
   		"  The face's large %^WHITE%^toothed%^BLUE%^ maw drools and "+
		"mutters incessantly in a low monotone."   
   		"  Anyone who gets too close to the shield gets a nip as the"+
		" shield lunges at them dragging you along.%^RESET%^");
	set_lore("The Gibbering Shield was a common shield for a tribe of "+
		"warriors.  Some would said the warriors were crazed and "+
		"insane due to years of inbreeding, though others claim that"+
		" the tribe fell under the sway of a demonic fiend that corrupted"+
		" their minds.  What ever the case maybe the warriors were a "+
		"fearsome bunch, not as much for thier skill but how crazed "+
		"they became in battle.  It was not uncommon to see these "+
		"warriors race into battle with only the shield to protect "+
		"their nude bodies from damage.  The warriors use to live within"+
		" the caves of the Barrier Mountains before they simply just "+
		"vanished one day.");
	set_property("lore",10);
    	set_weight(10);
  	set_struck((:TO,"strikeme":));
  	set_wear((:TO,"wearme":));
  	set_value(1500);
    	set_type("shield");
	set_limbs( ({ "right hand" }) );
        //set_ac(1);
        set_property("enchantment",3);
}
int strikeme(int damage, object what, object who){
  	tell_object(ETO,"%^BOLD%^%^BLUE%^The shield lunges at"+
		" "+who->QCN+", snapping and snarling, making the"+
		" blow glance off course!");
   	tell_object(who,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s shield "+
		"lunges at you and tries to bite you as you swing!");
   	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s "+
		"shield bites at "+who->QCN+" as "+who->QS+" gets too"+
		" close!",({who,ETO}));
  if(!random(4)){
    	who->do_damage("torso",random(6)+2);
   	who->set_paralyzed((random(6)+3),"%^BOLD%^You struggle to free your hand "+
		"from the shield's mouth!");
   tell_room(environment(ETO),"%^BOLD%^The shield bites "+who->QCN+" and"+
		" won't let go!");
  }
  return (-1)*(damage/2);
}
int wearme(){
  if((int)ETO->query_highest_level() <15){
  	write("%^GREEN%^The shield chuckles as you try to wear it but"+
		" your inexperiance shows when it bites you!");
   	say("%^GREEN%^"+TPQCN+" fiddles with "+TP->QP+" shield and it bites "+ETO->QO+"!");
  		ETO->do_damage("torso",20);
  		ETO->set_paralyzed(10,"You struggle to free your hand from its mouth!");
  return 0;
  }
  	write("%^BOLD%^%^BLUE%^The shield pulls against you as it snarls"+
		" and drools.");
   	say("%^BOLD%^%^BLUE%^The shield in "+TPQCN+"'s hands seems to grin"+
		" and lick its lips.");
  return 1;
}
