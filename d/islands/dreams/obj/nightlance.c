//removed references to old gods - Circe 7/30/19
#include <std.h>
inherit "/d/common/obj/weapon/hhlance.c";

int FLAG;

void create(){
   	::create();
   	set_name("Smoldering Lance");
   	set_short("%^BOLD%^%^BLACK%^Sm%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^l"+
		"d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ring L%^RESET%^"+
		"%^RED%^a%^BOLD%^%^BLACK%^nce%^RESET%^");
   	set_obvious_short("%^BOLD%^%^BLACK%^A sardonyx lance%^RESET%^");
   	set_id(({"lance","smoldering lance","nightmare lance","sardonyx lance"}));
   	set_long("%^RED%^This lance is made out of solid %^BOLD%^%^BLACK%^black"+
   		" sardonyx%^RESET%^%^RED%^ that is perfectly smooth and formed into the"+
   		" well balanced lance. You can see heat waves emanating from the"+
   		" shaft, and the tip appears to be smoking slightly.%^RESET%^");
	set_lore("Praise be to Ryorik, the Lord of Elemental Planes for the blessing of the Smoldering Lance.  Blessed be Sir Karim Falldor, Holy Knight of the Flames.  Let the foes of Ryorik taste the fires of destruction that he controls.  All creatures shall fear the elements and praise them! - Part of a Lengthy Prayer to Ryorik about the dedication and creation of the Smoldering Lance");
   	set_property("lore difficulty",18);
   	set_value(2000);
   	set_property("enchantment",3);
   	set_hit((:TO,"hitme":));
   	set_wield((:TO,"wieldme":));
   	set_unwield((:TO,"removeme":));
}

int wieldme()
{
	if(ETO->query_lowest_level() < 17) {
      	return notify_fail("%^RED%^You're not yet strong enough"+
			" to master such a lance.");
        return 0;
   	}
/*
Removing these two functions since all elements are under Ryorik now
   	if((string)ETO->query_diety() == "istishia" || (string)ETO->query_diety() == "auril") {
      	tell_object(ETO,"%^BOLD%^%^RED%^The incredible pain is absolutely"+
      		" devastating, you can't maintain a grip on the lance at all!");
     		tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+""+
      		" screams out in agony as "+ETO->QS+" tries to"+
      		" wield the smoldering lance.",ETO);
      			set_property("magic",1);
      			ETO->do_damage("torso",random(5)+20);
      			ETO->add_attacker(TO);
      			ETO->continue_attack();
      			ETO->remove_attacker(TO);
      			remove_property("magic");
      return 0;
   	}
   	if(ALIGN->is_good(ETO)) {
      	tell_object(ETO,"%^RED%^The lance burns your hands as you try"+
			" to use it!");
      			set_property("magic",1);
      			ETO->do_damage("torso",random(5)+10);
      			ETO->add_attacker(TO);
      			ETO->continue_attack();
      			ETO->remove_attacker(TO);
      			remove_property("magic");
      return 0;
   	}
*/
   	if((string)ETO->query_diety() == "ryorik") {
      	tell_object(ETO,"%^RED%^The smoldering lance is wonderfully hot"+
      		" against your skin.");
      	tell_room(environment(ETO),"%^RED%^"+ETO->QCN+""+
      		" smiles faintly as "+ETO->QS+" grips the"+
      		" smoldering lance.",ETO);
        FLAG=1;
      return 1;
   	}
//not sure about keeping this, but retaining it for now since this has always been an evil weapon
   	if(ALIGN->is_evil(ETO)) {
      	tell_object(ETO,"%^RED%^You can feel the heat against your skin, but"+
      		" it doesn't bother you.");
      	tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" grips"+
      		" the smoldering lance without flinching.",ETO);
      return 1;
   	}
   	else {
      	tell_object(ETO,"%^BOLD%^%^RED%^You feel blisters form on your hand"+
      		" from the smoldering lance as you grip it. Letting go "+
			"is going to hurt even worse...");
      	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+""+
      		" flinches in pain as "+ETO->query_subjective()+" grips the"+
      		" smoldering lance.",ETO);
      			set_property("magic",1);
      			ETO->do_damage("torso",random(3)+6);
      			ETO->add_attacker(TO);
      			ETO->continue_attack();
      			ETO->remove_attacker(TO);
      			remove_property("magic");
      return 1;
   	}
}

int removeme()
{
   	if((string)ETO->query_diety() == "ryorik") {
      	tell_object(ETO,"%^RED%^You release the lance and feel the "+
			"blessed heat diminish.");
        FLAG=0;
      return 1;
   	}
   	if(ALIGN->is_evil(ETO)) {
      	tell_object(ETO,"%^BOLD%^%^BLUE%^You feel cooler as you release"+
      		" the smoldering lance.");
      return 1;
   	}
   	else {
      	tell_object(ETO,"%^BOLD%^%^RED%^You cry out in pain as the skin is"+
      		" torn from your hand when you remove the lance.");
      	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+""+
      	" cries out in pain as "+ETO->QS+" releases the"+
      	" lance, "+ETO->QP+" hands are missing a layer of"+
      	" skin.",ETO);
      		set_property("magic",1);
      		ETO->do_damage("torso",random(3)+12);
      		ETO->add_attacker(TO);
      		ETO->continue_attack();
      		ETO->remove_attacker(TO);
      		remove_property("magic");
      return 1;
   	}
}

int hitme(object targ)
{
   	//if(!objectp(ETO)) return 0;
   //	if(!ETO->query_in_vehicle() || objectp(ETO->query_in_vehicle())) {
     // 	ETO->force_me("drop lance");
     // return 0;
	//}
   	if(!random(8)) {
      	tell_object(ETO,"%^RED%^The lance singes "+targ->QCN+"'s skin!");
      	tell_object(targ,"%^RED%^"+ETO->QCN+"'s smoldering"+
      		" lance singes your skin!");
      	tell_room(environment(ETO),"%^RED%^"+ETO->QCN+"'s"+
      		" smoldering lance singes "+targ->QCN+"'s skin.",({ETO,targ}));
      			set_property("magic",1);
      			targ->do_damage("torso",random(5)+8);
      			remove_property("magic");
      return 1;
   	}
   	if(!random(12)) {
      	tell_object(ETO,"%^RED%^%^BOLD%^You smell the scent of burned"+
      		" flesh as your lance digs deeply into "+targ->QCN+".");
      	tell_object(targ,"%^RED%^%^BOLD%^"+ETO->QCN+"'s"+
      		" smoldering lance burns your flesh!!");
      	tell_room(environment(ETO),"%^RED%^%^BOLD%^You smell the scent of"+
      		" burned flesh as "+ETO->QCN+"'s lance digs deeply"+
      		" into "+targ->QCN+".",({ETO,targ}));
      			set_property("magic",1);
      			targ->do_damage("torso",random(8)+10);
      			remove_property("magic");
      return 1;
   	}
	if(!random(20) && FLAG == 1) {
      	tell_object(ETO,"%^YELLOW%^The lance's fires blaze across your "+
			"flesh, leaving you feeling renewed.");
      	tell_room(environment(ETO),"%^YELLOW%^The fiery glow around "+ETO->QCN+"'s"+
      		" lance increases and "+ETO->QS+" looks refreshed.",({ETO}));
      			set_property("magic",1);
                		ETO->do_damage("torso",(-1)*(random(8)+5));
				remove_property("magic");
      return 1;
   	}
}
