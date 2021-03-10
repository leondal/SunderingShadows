//light chain designed by zath 11/20/12
#include <std.h>
inherit "/d/common/obj/armour/chain";

void create() {
    ::create();
    set_name("elf chain");
    set_id( ({ "armor", "chain","light chain","elf chain" }) );
    set_short( "%^BOLD%^%^GREEN%^Ar-tel-Quessir chain%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^E%^BOLD%^m%^RESET%^%^GREEN%^erald l%^BOLD%^i%^RESET%^g%^GREEN%^ht c%^BOLD%^h%^RESET%^%^GREEN%^ain armor%^RESET%^");
    set_long(
        "%^GREEN%^Designed in classic Elven craftsmanship this armor fits the form of its "+
"wearer with a comfortable, snug fit. Closest to the body a thin layer of "+
"soft wool offers minor protection in battle, but even more from the "+
"elements and any chafing. Atop the thin layer of cloth sits the true bulk "+
"of the armor. Minute rings of a dull green metal loop into one another, "+
"creating the look of chain mail but the armor as a whole weighs next to "+
"nothing. Forming a collar that extends over the wearer's shoulders and "+
"partially down her back and chest, embroidered leather sits over the chain, "+
"offering more form and protection to these areas, as well as two embroidered "+
"lengths that run from under each arm to the end of the armor at the waist. "+
"Hidden beneath these side panels, small straps and buckles allow the armor "+
"to be fit to its wearer, extra length has been given to the upper straps, "+
"allowing the armor to be fit for a female warrior as easily as a male.%^RESET%^");
    set_lore("This armor bears the craftsmanship of the elves of the"+
	" citadel of Ashta'Rathai.  They are a tribe of gold elves that"+
	" once led a great nation of elves.  It is believed that they "+
	"were wiped out from conflict with neighboring humans and some catastrophe.");
	set_property("lore difficulty",35);
    set("value", 1000);
	set_property("enchantment",4);
    set_item_bonus("endurance",2);
	set_struck((:TO,"strike_func":));
	set_item_bonus("spell resistance",20);

}
int strike_func(int damage, object what, object who){
        if(!objectp(ETO)) return 1;
		if(!random(5)){
        tell_room(environment(query_worn()),"%^BOLD%^"+
            ""+who->QCN+"'s blow glances off "
            +ETO->QCN+" harmelessly.",({ETO,who}));
        tell_object(ETO,"%^BOLD%^As the blow lands against your armor you feel no pain.");
        tell_object(who,"%^BOLD%^Your stern blow lands,"+
		" but causes no effect and harmlessly glances off.");
        return (damage*-1);
       }
}
