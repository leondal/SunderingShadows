//Revamp of weapon -Cythera 5/05\\
#include <std.h>
inherit "/d/common/obj/weapon/double_bladed_sword.c";

void create()
{
   	::create();
   	set_name("double bladed sword");
   	set_short("%^BOLD%^%^BLUE%^Sword of the Whirling Steel%^RESET%^");
   	set_obvious_short("%^BOLD%^%^BLUE%^A blue steel double bladed sword%^RESET%^");
   	set_id(({"sword","double bladed sword","blue sword","sword of the whirling steel"}));
   	set_long("%^BOLD%^%^BLUE%^Twin curved blue tinted blades have been"+
		" mounted onto an %^YELLOW%^oak%^BLUE%^ pole.  The scimitar"+
		" looking blades are engraved with an intricate "+
		"%^RESET%^%^CYAN%^geometric patterns%^BOLD%^%^BLUE%^, "+
		"giving the weapon an elven feel.  The edges of the "+
		"scimitars bevel upwards, creating a greater surface to"+
		" slash into flesh. The oak shaft that the blades are "+
		"mounted on is carved with a similar geometrical pattern.\n"); 
   	set_value(200);
   	set_property("enchantment",1);
	set_lore("A band of elven warriors called the South Wind"+
		" Blades were known for their mastery and grace in "+
		"combat.  The elves wielded double bladed swords, "+
		"strange and exotic weapons of elven make, in battle."+
		"  Some claim that the elves were able to spin the "+
		"blades with such speed that they would whistle.");
   	set_property("lore difficulty",8);
	set_hit((:TO,"hitme":));
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}

int wield_fun() {
	if (!ETO->query_property("silent_wield")) {
		tell_object(ETO, "%^BOLD%^%^BLUE%^The double bladed sword feels well balanced in your hands.");
	}
	return 1;
}

int unwield_fun() {
	if (!ETO->query_property("silent_wield")) {
		tell_object(ETO, "%^BOLD%^%^BLUE%^You set aside the well balanced double bladed sword.");
	}
	return 1;
}

int hitme(object targ){
if(!objectp(targ)) return 0;
if(!objectp(ETO)) return 0;
   if(!random(10)) {
      tell_object(ETO,"%^BOLD%^%^BLUE%^You follow through your attack by "+
		"whipping your double bladed sword around.");
      tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->QCN+" whips "+ETO->QP+""+
      	" double bladed sword around in an attempt to follow "+
		"through "+ETO->QP+" attack on you.");
      tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->QCN+""+
      	" whips "+ETO->QP+" double bladed sword around in an attmpt"+
		" to follow through "+ETO->QP+" attack "+
		"on "+targ->QCN+".",({ETO,targ}));
      		ETO->execute_attack();
      return 1;
   }
}