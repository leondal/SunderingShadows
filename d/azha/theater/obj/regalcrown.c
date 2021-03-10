#include <std.h>
inherit "/d/common/obj/jewelry/circlet";

void create(){
        ::create();
      set_name("regal crown");
      set_id(({ "crown","regal crown","gold crown" }));
      set_short("%^YELLOW%^R%^RED%^e%^YELLOW%^g%^RESET%^%^MAGENTA%^a"+
		"%^YELLOW%^l C%^BLUE%^r%^YELLOW%^o%^GREEN%^w%^YELLOW%^n%^RESET%^");
      set_obvious_short("%^YELLOW%^A %^BLUE%^b%^WHITE%^e%^GREEN%^g"+
		"%^BLUE%^e%^RED%^m%^WHITE%^e%^RESET%^%^MAGENTA%^d %^YELLOW%^"+
		"gold crown%^RESET%^");
      set_long("%^ORANGE%^This golden crown carries a regal air with"+
		" in.  %^BOLD%^%^WHITE%^White%^RESET%^%^ORANGE%^ and %^YELLOW%^"+
		"yellow%^RESET%^%^ORANGE%^ gold has been woven together to crea"+
		"te this solid looking crown.  Images of %^RED%^winged dragons"+
		"%^ORANGE%^, %^YELLOW%^lions%^RESET%^%^ORANGE%^, and %^BOLD%^"+
		"%^WHITE%^unicorns%^RESET%^%^ORANGE%^ circle around the crown,"+
		" giving it a noble quality.  The images are highly detailed and"+
		" life like, a true test to the quality.  Large %^RED%^ru%^BOLD%^"+
		"b%^RESET%^%^RED%^ies%^ORANGE%^, %^BLUE%^sa%^BOLD%^pp%^RESET%^"+
		"%^BLUE%^hires%^ORANGE%^, %^GREEN%^em%^BOLD%^er%^RESET%^%^GREEN%^"+
		"alds%^ORANGE%^, %^BOLD%^%^WHITE%^dia%^YELLOW%^m%^WHITE%^onds%^RESET%^"+
		"%^ORANGE%^, and %^MAGENTA%^ame%^BOLD%^th%^RESET%^%^MAGENTA%^ysts"+
		"%^ORANGE%^ are imbedded deep into the gold metal.  A band of the"+
		" richest velvet lines the inside of the crown for comfort.  This"+
		" is truly the crown that a noble might wear.\n%^RESET%^");
      set_weight(5);
      set_value(1000);
      set_lore("The novel play, All the King's Horsemen pits two prin"+
		"ces against each other.  The two princes fight a bloody war over"+
		" who will be the successor to the throne, and retain the crown. "+
		"  On the eve of the beginning of the war the Urtzbex crown, the "+
		"very thing the princes fight for, changes it's shape, an omen of"+
		" the bloody battle that will come to be.  The dragons on the new"+
		" crown represent Thaodal, the eldest son.  While the lions are a"+
		" symbol of Laodal, the younger twin of Thaodal.  The unicorns, a"+
		"s we find out in the play, pay homage to Usha and Jezrella Orim,"+
		" sisters who have married into the Urtzbex family.  Yaran Silver"+
		"page's play shows us an insight to war that does not often get pl"+
		"ayed out, how war crosses many familial boundaries. - Pages of Si"+
		"lverpage - The Avant Garde Playwright - Damona Silverpage");
      set_property("lore difficulty",14);
      set_limbs(({ "head" }));
      set_size(2);
      set_property("enchantment",2);
      set_item_bonus("spell damage resistance",5);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
int wear_func(){
   		tell_room(EETO,"%^ORANGE%^Placing the crown on "+ETO->QP+" head "+ETOQCN+""+
			" looks noble and regal.%^RESET%^",ETO);
      	tell_object(ETO,"%^ORANGE%^You place the crown on your head, feeling"+
			" regal and noble.%^RESET%^");
			return 1;
}
int remove_func(){
      	tell_room(EETO,"%^ORANGE%^"+ETOQCN+" removes "+ETO->QP+" crown, looking sl"+
			"ightly less noble.%^RESET%^",ETO);
      	tell_object(ETO,"%^ORANGE%^You pull off the crown, feeling slightly "+
			"less noble and regal.%^RESET%^");
			return 1;
}
