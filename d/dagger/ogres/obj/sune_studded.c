// adapted to Jarmila. N, 12/18.
#include <std.h>
inherit "/d/common/obj/armour/studded";

void create(){
	::create();
	set_name("%^RESET%^%^BOLD%^%^WHITE%^T%^RESET%^%^RED%^o%^RESET%^%^BOLD%^%^WHITE%^"+
"uch of R%^RESET%^%^RED%^o%^RESET%^%^BOLD%^%^WHITE%^se studd%^RESET%^%^WHITE%^e"+
"%^RESET%^%^BOLD%^%^WHITE%^d le%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^"+
"ther%^RESET%^");
	set_id(({ "studded", "white studded leather", "studded", "touch of rose", "Touch of Rose studded leather"}));
	set_short("%^RESET%^%^BOLD%^%^WHITE%^T%^RESET%^%^RED%^o%^RESET%^%^BOLD%^"+
"%^WHITE%^uch of R%^RESET%^%^RED%^o%^RESET%^%^BOLD%^%^WHITE%^se studd%^RESET%^"+
"%^WHITE%^e%^RESET%^%^BOLD%^%^WHITE%^d le%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^"+
"%^WHITE%^ther%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^WHITE%^white st%^RESET%^%^RED%^u"+
"%^RESET%^%^BOLD%^%^WHITE%^dded leat%^RESET%^%^RED%^h%^RESET%^%^BOLD%^"+
"%^WHITE%^er%^RESET%^");
	set_long("%^RESET%^%^BOLD%^%^WHITE%^The soft pure white leather of"+
" this suit of armor is perfect, free of blemishes and soft to the touch. "+
"Studs of %^RESET%^%^RED%^ro%^RESET%^%^BOLD%^%^RED%^s%^RESET%^%^RED%^e q"+
"%^RESET%^%^BOLD%^%^RED%^u%^RESET%^%^RED%^artz %^RESET%^%^BOLD%^%^WHITE%^"+
"line the seams of the suit, providing more protection and shaping the "+
"armor perfectly. The suit clasps at the side with %^RESET%^%^YELLOW%^go"+
"%^RESET%^%^ORANGE%^l%^RESET%^%^YELLOW%^d buck%^RESET%^%^ORANGE%^l%^RESET%^"+
"%^YELLOW%^es %^RESET%^%^BOLD%^%^WHITE%^and white leather straps. The armor"+
" is cut close to the body, but is easily adjustable for either a man or "+
"woman. Around the collar is a complex embroidery of a %^RESET%^%^RED%^s"+
"%^RESET%^%^BOLD%^%^RED%^t%^RESET%^%^RED%^ring of %^RESET%^%^BOLD%^%^RED%^"+
"ros%^RESET%^%^RED%^e%^RESET%^%^BOLD%^%^RED%^s%^RESET%^%^BOLD%^%^WHITE%^.%^RESET%^");
	set_weight(20);
	set_value(3000);
	set_lore("%^RED%^%^BOLD%^Defenders of the faith of Jarmila, though beautiful "+
"and sometimes seen as wistful, ardently defend the doctrine of their faith. A "+
"group of templars known as the Everlasting Rose show regularly how following a "+
"faith of love does not mean they lack battle prowess. Each of them takes to the "+
"field to hunt undead, defend the helpless, and further the cause of their Lady "+
"to their last breaths. The armor known as Touch of Roses is given to the "+
"templar once they take their vows.%^RESET%^ ");
	set_property("lore difficulty",15);
	set_size(2);
      set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+"%^BOLD%^%^RED%^ clasp on the"+
" "+query_short()+"%^BOLD%^%^RED%^, looking around with a smile.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You clasp the "+query_short()+"%^BOLD%^"+
"%^RED%^. You feel an urge to protect.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(EETO,"%^BOLD%^%^RED%^As "+ETOQCN+"%^BOLD%^%^RED%^ removes the"+
" "+query_short()+"%^BOLD%^%^RED%^, they stretch slowly.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You remove the "+query_short()+"%^BOLD%^"+
"%^RED%^and relish once again the freedom without armor.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(EETO,"%^RESET%^%^GREEN%^As "+who->QCN+"%^RESET%^%^GREEN%^ str"+
"ikes "+ETOQCN+"%^RESET%^%^GREEN%^, "+ETOQCN+"%^RESET%^%^GREEN%^ moves quick"+
"ly, striking them! %^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^GREEN%^As "+who->QCN+"%^RESET%^%^GREEN%^'s "+
"blow is about to strike you, you take the opportunity to strike them soundly!%^RESET%^");
	tell_object(who,"%^RESET%^%^GREEN%^As you strike "+ETOQCN+"%^RESET%^"+
"%^GREEN%^ they spin and strike you soundly!%^RESET%^");
		who->set_paralyzed(random(2));
return damage;	}
}
