#include <std.h>
inherit "/std/armour";

void create(){
      ::create();
     	set_name("silk vest");
      set_id(({ "vest","azure silk vest","blue silk vest" }));
	set_short("%^BOLD%^%^BLUE%^A%^RESET%^%^CYAN%^z%^BOLD%^u%^BLUE%^r"+
		"%^RESET%^%^BLUE%^e %^CYAN%^Silk Vest%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^An %^BOLD%^%^BLUE%^a"+
		"%^RESET%^%^CYAN%^z%^BOLD%^u%^BLUE%^r%^RESET%^%^BLUE%^"+
		"e%^CYAN%^ silk vest%^RESET%^");
      set_long("%^CYAN%^Lightly shaped from heavy "+
		"%^BOLD%^%^BLUE%^b%^RESET%^%^CYAN%^l%^BOLD%^u%^RESET%^%^BLUE%^e"+
		"%^CYAN%^ silk, this vest has an %^BOLD%^%^WHITE%^exotic%^RESET%^"+
		"%^CYAN%^ look to it.  The shoulders of the vest rise to narrow "+
		"points on either side, the edges of the seams trimmed in a deeper"+
		" shade of %^RESET%^%^BLUE%^b%^BOLD%^%^BLACK%^l%^RESET%^%^BLUE%^ue"+
		"%^CYAN%^.  From there the lines of the vest taper downwards, creating"+
		" an illusion of an inverted triangle - broad across the shoulders and"+
		" narrow to the waist.  The edge of the vest is %^RESET%^frayed %^CYAN%^"+
		"and %^BOLD%^%^BLACK%^tattered%^RESET%^%^CYAN%^ slightly, creating a"+
		" carefree feeling,  A slightly raised neckline circles around the "+
		"back of the vest before tapering down to the waist.  There are no "+
		"buttons or fasteners on the vest.\n%^RESET%^");
    	set_weight(3);
      set_value(7000);
      set_lore( "Part of the garb worn by the warrior's of the Yarlan tribe,"+
		" the silk vests were worn by great leaders and chieftains alike."+
		"  The Yarlan Warriors prized a combination of strength and "+
		"fleetness in battle to overcome their foes, where as at the "+
		"time most warriors only focused on strength alone.  The Yarlan "+
		"served as guides for travelers and pilgrims who came to the "+
		"islands of Graez for enlightenment and trade.  The Yarlan folk"+
		" were ones who always were the first to leap into battle "+
		"against the giants and goblinkind that once infested the "+
		"mountains of Graez, seeking to lend a helping hand to those"+
		" in need.  It was said that the Yarlan were the first to "+
		"worship Shaundakul and through them his faith spread in the "+
		"lands.");
    	set_property("lore difficulty",14);
      set_type("clothing");
      set_limbs(({ "torso" }));
      set_size(2);
      set_property("enchantment",5);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
      set_struck((:TO,"strike_func":));

}
int wear_func(){
	if((string)ETO->query_gender() == "female") {
      	tell_object(ETO,"%^BOLD%^%^BLUE%^You notice the vest would "+
			"leave you VERY exposed, and rethink your choice.");
             tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->QCN+""+
                	" takes one look at the vest and shakes her head.",ETO);
		   		 return 0;
	}
        if((int)ETO->query_highest_level() < 30) {
             tell_object(ETO,"The vest refuses to be worn as weak as you!");
                                 return 0;
   }

      	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" pulls on the silk vest.",ETO);
        	tell_object(ETO,"%^CYAN%^You pull on the silk vest, feeling the "+
			"softness of the fabric against your skin.%^CYAN%^.");
        			return 1;
}
int remove_func(){
	  tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" removes his vest, showing off"+
		" his naked torso.",ETO);
        tell_object(ETO,"%^CYAN%^Feeling a need to cool off some, you yank your vest off,"+
		" feeling the air against your naked chest.");
        			return 1;
}
int strike_func(int damage, object what, object who){
        if(random(1000) < 175){
        tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^"+ETOQCN+" spins around"+
			" "+who->QCN+", lashing out with a quick hit.",({ETO,who}));
        tell_object(ETO,"%^CYAN%^You spin around "+who->QCN+", pressing your advantage forward.");
        tell_object(who,"%^CYAN%^"+ETOQCN+" spins in under a gap in your defenses, pressing"+
		" forward his advantage.");
				ETO->execute_attack();
	}
    return damage;
}