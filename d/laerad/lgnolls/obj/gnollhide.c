//Essyllis: Marts 2015

#include <std.h>
inherit "/d/common/obj/armour/hide.c";


void create(){ 
        
        ::create();
      
	set_name("thick hyena hide");
        set_id(({ "hide","leather","armor","armour","Hide" }));
	set_short("%^RESET%^%^ORANGE%^A th%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ck h%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^a h%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^de%^RESET%^");
        set_long("%^ORANGE%^The h%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^de is very much thicker than normal "+
		"h%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^des. It is made of the skins of h%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^as "+
		"boiled hard and %^BOLD%^%^BLACK%^double padded %^RESET%^%^ORANGE%^for extra thickness. It opens up at the side where thick cured "+
		"l%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^at%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^er straps tie it together for a "+
		"perfect fit. Elevated %^BOLD%^%^BLACK%^shoulder-plates %^RESET%^%^ORANGE%^rise high enough to protect both "+
		"shoulders and neck. Even though the h%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^de has been boiled, a lot of the "+
		"original h%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^a f%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^r "+
		"still clings to the hide, giving it an almost an%^GREEN%^i%^ORANGE%^m%^GREEN%^a%^ORANGE%^l "+
		"c%^GREEN%^a%^ORANGE%^m%^GREEN%^o%^ORANGE%^u%^GREEN%^f%^ORANGE%^l%^GREEN%^a%^ORANGE%^ge appearance. It is obvious "+
		"that this hide has been made with %^BOLD%^%^BLACK%^protection %^RESET%^%^ORANGE%^and %^GREEN%^survival %^ORANGE%^in mind.%^RESET%^");
      set_value(700);
      set_lore("The gnolls often revered the Hyena as the perfect survivors, adapted to manage in almost any environment"+
		". And like gnolls themselves, they eat pretty much any meat they can come by, dead or alive. Alive preferred. "+
		"It is often said amongst the gnoll, that if you kill a hyena, you have to eat its heart and wears its hide to "+
		"absorb their survival instincts. -- Sallonir deldor, Bard of Torm");
    	set_property("lore difficulty",17);
      set_size(2);
      set_property("enchantment",3);
      set_item_bonus("survival",1);
	  set_item_bonus("endurance",1);
      set_wear((:TO,"wear_func":));
//      set_remove((:TO,"remove_func":));
// were bugging, had to remove - no such function!
}
int wear_func(){
        if((int)ETO->query_level()<15){
			tell_object(ETO,"%^ORANGE%^The leather is too thick and heavy for you to wear yet.%^RESET%^");
			tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETO->QCN+" %^RESET%^%^ORANGE%^struggles and fails to wear the thick hide.%^RESET%^",ETO);
			return 0;
		}
		
		tell_room(EETO,"%^BOLD%^%^BLACK%^After a short struggle with the %^RESET%^%^ORANGE%^heavy hide%^BOLD%^%^BLACK%^, "+ETO->QCN+" %^BOLD%^%^BLACK%^finally manages to wear it.%^RESET%^",ETO);
        tell_object(ETO,"%^GREEN%^After a struggle, you manage to wear the heavy hide.%^RESET%^");
                                return 1; 
}
