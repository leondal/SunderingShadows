#include <std.h>

inherit "/d/common/obj/weapon/wakizashi.c";

void create(){
   ::create();
   set_name("silver wakizashi");
   set_id(({"sword","moon shadow","silver wakizashi","wakizashi","silver sword"}));
   set_short("%^RESET%^%^CYAN%^M%^BOLD%^%^WHITE%^o%^RESET%^o%^CYAN%^n"+
		" %^BOLD%^%^BLACK%^S%^RESET%^h%^BOLD%^a%^RESET%^%^CYAN%^d"+
		"%^RESET%^o%^BOLD%^%^BLACK%^w%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A silver wakizashi%^RESET%^");
   set_long("%^CYAN%^Forged of %^BOLD%^%^WHITE%^silver%^RESET%^%^CYAN%^,"+
		" this slender blade appears light and well balanced.  "+
		"Polished to a %^BOLD%^mirror%^RESET%^%^CYAN%^ like sheen,"+
		" the silver takes on a bright luster.  The thin blade has"+
		" a slight curve to it, tapering off at the tip.  Etched into"+
		" the silver is a highly detailed pattern of %^RESET%^s%^BOLD%^"+
		"w%^CYAN%^i%^RESET%^%^CYAN%^r%^BLUE%^l%^RESET%^s%^CYAN%^.  In"+
		" the center of each swirl, a %^BOLD%^%^CYAN%^crescent moon "+
		"%^RESET%^%^CYAN%^is framed.  The crescent moon shape has an "+
		"antiquated feel to it, artisticaly detailed and stylized.  The"+
		" hiltless blade elegantly merges with the pommel.  Wrapped "+
		"in %^BOLD%^%^BLACK%^dark gray %^RESET%^%^CYAN%^leather, the"+
		" pommel is well cushioned The texture of the leather creates"+
		" an easy grip, even in the worst of conditions.  The blade "+
		"seem extremely light and well balanced.%^RESET%^\n");
   set_lore("Crafted by the elven weaponsmith Nom, Moon Shadow, was "+
		"enchanted by the Selunite Priestess/Mage Kiya.  Moon Shadow "+
		"began as a weapon devoted to Selune, the Goddess of the Moon."+
		"  Copies of the blade were made by the faithful in their many "+
		"battles and fights with the forces of Shar.  Still, Moon Shadow "+
		"has found a home outside the religous wars between the two elder "+
		"faiths.  Several elves find the design of Moon Shadow to fit their"+
		" graceful hands better than any other weapon out there.  Others like"+
		" the stylized look of the blade, and the graceful displays one can "+
		"create in battle.  Moon Shadow's fame continues to evolve.");
   set_property("lore difficulty",8);
   set_property("enchantment",2);
   set("value",1000);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
   set_special_material_type("silver");
}
	int wield_func(string str) {
     		tell_object(ETO,"%^CYAN%^The crescent moons on the blade"+
			" shimmer softly as you grip the pommel.");
   		tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+"'s blade "+
			"shimmers softly as "+ETO->QS+" grips the pommel.",ETO);
   	   	return 1;
	}
	int unwield_func(string str) {
   		tell_object(ETO,"%^CYAN%^The crescent moon images go dark as"+
			" you release the blade.");
   		tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+"'s "+
      	"blade goes dark as "+ETO->QS+" releases it.",ETO);
   	   	return 1;
	}
int hit_func(object victim) {
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(victim)) return 1;
    if(random(1000) < 150)
    {
        switch(random(40))
        {	
        default:
            tell_object(ETO,"%^BOLD%^%^WHITE%^Silver flames lick off the "+
                "surface of the blade, burning "+victim->QCN+".");
            tell_object(victim,"%^BOLD%^%^WHITE%^Silver flames lick off "+
                "the surface of "+ETO->QCN+"'s blade, burning you.");
            tell_room(environment(ETO),"%^BOLD%^%^WHITE%^Silver flames "+
                "lick off the surface of "+ETO->QCN+"'s blade,"+
                " burning "+victim->QCN+".",({ETO,victim}));
            victim->cause_typed_damage(victim, victim->return_target_limb(), roll_dice(1, 4) + 1, "fire");
        break;
        case 34..39:
            tell_object(ETO,"%^BOLD%^%^CYAN%^Silver light bathes you for"+
                " a moment.  When the light fades, you have appeared "+
                "behind "+victim->QCN+".");
            tell_object(victim,"%^BOLD%^%^CYAN%^Silver light bathes "+
                ""+ETO->QCN+" for a moment.  When the light fades, "+ETO->QCN+""+
                " is gone!          "+
                "%^BOLD%^%^WHITE%^Suddenly you feel a sting of a "+
                "blade behind you!");
            tell_room(environment(ETO),"%^BOLD%^%^CYAN%^Silver light bathes "+
                ""+ETO->QCN+" for a moment.  When the light fades, "+ETO->QCN+""+
                " appears behind "+victim->QCN+".",({ETO,victim}));
            ETO->execute_attack();
            break;
	
        }
    return 1;
   }
}
