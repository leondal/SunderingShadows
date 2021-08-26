#include <std.h>
inherit "/d/common/obj/armour/shield.c";

void create(){
	::create();
	set_name("jeweled shield");
	set_id(({ "shield", "jeweled shield", "spidersilk shield", "spider silk shield", "ruby shield", "round shield", "jeweled round shield" }));
	set_short("%^BOLD%^%^BLACK%^S%^RED%^p%^RESET%^%^RED%^id%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r%^BOLD%^si%^BLACK%^lk S%^RESET%^%^RED%^h%^BOLD%^i%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ld%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A %^RESET%^%^RED%^j%^BOLD%^e%^BLACK%^w%^RED%^e%^RESET%^%^RED%^l%^BOLD%^e%^RESET%^%^RED%^d %^BOLD%^%^BLACK%^round shield%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This shield is simple in its basic design "+
	   "but quite stunning to look at.  Round and made of %^RESET%^"+
	   "%^CYAN%^ironwood%^BOLD%^%^BLACK%^, it is quite sturdy and "+
	   "very resistant to attacks.  Made more so by the covering of "+
	   "woven %^RESET%^spider silk%^BOLD%^%^BLACK%^ that is stretched "+
	   "over it.  The silk has been dyed black and seems to absorb the "+
	   "light rather then reflect it, helping to keep it from being "+
	   "noticed, although the sixteen %^RESET%^%^RED%^dark rubies "+
	   "%^BOLD%^%^BLACK%^that ring its center do cause a bit of "+
	   "flare upon the shield.  However, like the silk, these gems "+
	   "appear to be enchanted to draw in the light rather then "+
	   "reflect it back.%^RESET%^");
	set_value(0);
	set_lore("Said to be crafted by the drow of the Underdark, these "+
	   "shields were crafted to help protect their wearer during "+
	   "battle.  Though the exact nature of this protection is "+
	   "unknown, the material that stretches over them is said to "+
	   "be very resistant.  The silky having been harvested by "+
	   "special spiders that the drow keep in order to make "+
	   "strong armor to use against their enemies.  The gemstones "+
	   "are said to be a mark of favor, their natural ability to "+
	   "draw the light helping the drow conceal themselves even further");
	set_property("lore difficulty",22);
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_func(){
	tell_object(ETO,"%^RESET%^%^BLUE%^You secure the %^RESET%^"+query_short()+" %^RESET%^%^BLUE%^about your forearm and feel more protected!%^RESET%^");
	return 1;
}

int remove_func(){
	tell_object(ETO,"%^RESET%^%^BLUE%^You feel less protected as you draw the %^RESET%^"+query_short()+" %^RESET%^%^BLUE%^from your arm.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(!random(10)){
	tell_room(environment(query_worn()),"%^RESET%^%^BLUE%^The %^RED%^rubies %^BLUE%^of "+ETOQCN+"'s %^RESET%^"+query_short()+" %^RESET%^%^BLUE%^suddenly spark and a field of protection swirls around them!  "+ETOQCN+"'s attack is easily deflected!",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^BLUE%^The %^RED%^rubies %^BLUE%^of your %^RESET%^"+query_short()+" %^RESET%^%^BLUE%^suddenly spark and a field of protection swirls around you!  "+who->QCN+"'s attack is easily deflected!");
	tell_object(who,"%^RESET%^%^BLUE%^The %^RED%^rubies %^BLUE%^of "+ETOQCN+"'s %^RESET%^"+query_short()+" %^RESET%^%^BLUE%^suddenly spark and a field of protection swirls around them!  Your attack is easily deflected!");
//return (damage*0)/100;	}
//the above was doing nothing
    return 0;
   }
   return damage;
}

int is_metal() { return 0; }