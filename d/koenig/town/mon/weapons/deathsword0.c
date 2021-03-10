//Redesigned blade to update - Cythera 5/05\\
#include <std.h>
inherit "/d/common/obj/weapon/khopesh.c";

void create()
{
   	::create();
   	set_name("tomb jade khopesh");
   	set_short("%^RESET%^%^RED%^Tomb Jade Khopesh%^RESET%^");
   	set_obvious_short("%^RESET%^%^RED%^A tomb jade khopesh%^RESET%^");
   	set_id(({"sword","khopesh","tomb jade khopesh","tomb jade sword"}));
   	set_long("%^RED%^Magically crafted from tomb jade, this "+
		"khopesh sword has a wicked curve to it.  The heavy "+
		"blade has been polished smooth, letting the earthy"+
		" luster of the tomb jade shine through.  The edges"+
		" of the sword have been magically sharpened to a "+
		"keen edge.  %^RED%^Dark gray %^RED%^strips of "+
		"tattered cloth wind their way around the handle "+
		"of the sword.  The end of the pommel has been "+
		"rounded off to form an orb, in which the symbol "+
		"of a skeletal hand holding a pair of scales has "+
		"been carved.%^RESET%^\n"); 
   	set_value(300);
   	set_property("enchantment",2);
	set_lore("The Tome Jade Khopesh was attributed to an"+
		" order of rangers in Kelemvor's faith.  The "+
		"rangers were a grim and morose bunch, forsaking"+
		" the wilds of the forest for graveyards and crypts."+
		"  Committed to stalking undead creatures and ending"+
		" their unnatural lives, the Rangers of the Crypts "+
		"were not often pleasant people to be around.  Known"+
		" for their swords crafted from tomb jade the rangers"+
		" were the first line of defense against any undead "+
		"attack usually.");
   	set_property("lore difficulty",10);
	set_hit((:TO,"hitme":));
   	set_wield("%^RED%^You feel the need to slay undead as you wield the blade.");
	set_unwield("%^RED%^The feeling that you must slay undead leaves"+
		" you as you release the sword.");
}

int hitme(object targ){
if(!objectp(targ)) return 0;
if(!objectp(ETO)) return 0;

   if(!random(8)) {
      tell_object(ETO,"%^RED%^You hack into "+
      	" "+targ->QCN+" with a strong blow.");
      tell_object(targ,"%^RED%^"+ETO->QCN+" hacks into"+
		" you with a strong blow.");
      tell_room(environment(ETO),"%^RED%^"+ETO->QCN+""+
      	" hacks into "+targ->QCN+" with a strong"+
		" blow.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+2);
      return 1;
   }
}