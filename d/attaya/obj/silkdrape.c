#include <std.h>
inherit "/std/armour";

void create(){
      ::create();
     	set_name("silk drape");
      set_id(({ "drape","silk drape","purple silk drape","top" }));
	set_short("%^RESET%^%^MAGENTA%^Pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple"+
		" Silk Drape%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^A purple silk top%^RESET%^");
      set_long("%^RESET%^%^MAGENTA%^This sultry little top made from"+
		" thin diaphanous silk that leaves little to the imagination."+
		"  The %^BOLD%^%^WHITE%^s%^RESET%^%^MAGENTA%^h%^BOLD%^i"+
		"%^WHITE%^m%^RESET%^%^MAGENTA%^m%^BOLD%^e%^WHITE%^r%^RESET%^"+
		"%^MAGENTA%^i%^BOLD%^n%^WHITE%^g%^RESET%^%^MAGENTA%^ purple "+
		"silk drapes across the bustline of the top, attracting "+
		"attention to the breasts.  The lengths of silk are held "+
		"by thin %^BOLD%^%^WHITE%^glittering%^RESET%^%^MAGENTA%^"+
                " chains made of pure %^BOLD%^%^WHITE%^crystal %^RESET%^"+
                "%^MAGENTA%^that cross in the back to "+
		"join again at the sides.  The bottom edge of the top is "+
		"left to float freely, hanging above the navel.\n%^RESET%^");
    	set_weight(3);
      set_value(7000);
      set_lore( "Once said to have been crafted by the Enchantress "+
		"Tiergaina, this little top has a bit of a history.  Tiergaina"+
		" was often snubbed by her fellow mages, for she rejected a "+
		"life of the tower and of dusty tomes.  It was in her adventures"+
		" and explorations that she discovered ancient relics of power "+
		"and rediscovered some old ways of magic.  Though none of her "+
		"counterparts would admit it, it was these relics of the past "+
		"that helped vault the Enchantress in power to become their "+
		"equal, if not surpassing them in might.  When the Enchantress "+
		"had to deal with the mages who denied her the respect she "+
		"deserved, she decided to play on her physical attributes to "+
		"put them on the defensive.  Thus the drape was born.");
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
	if((string)ETO->query_gender() == "male") {
      	tell_object(ETO,"%^MAGENTA%^You dont think you have shoes to match the top.");
             tell_room(environment(ETO),"%^MAGENTA%^"+ETO->QCN+""+
                	" takes one look at the top and shakes his head.",ETO);
		   		 return 0;
	}
       if((int)ETO->query_highest_level() < 30) {
               tell_object(ETO,"The drape slips away from your body, refusing to be worn by you.");
                             return 0;
        }
       tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" pulls on the silk top.",ETO);
        	tell_object(ETO,"%^CYAN%^You pull on the silk top, feeling the "+
			"softness of the fabric against your skin.%^CYAN%^.");
        			return 1;
}
int remove_func(){
	  tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" strips out of her top very slowly,"+
               " almost as if she was teasing you.",ETO);
        tell_object(ETO,"%^MAGENTA%^You slowly start to pull the top off, enjoying the attention"+
		" that it brings.");
        			return 1;
}
int strike_func(int damage, object what, object who){
        if(!random(10)){
        tell_room(environment(query_worn()),"%^BOLD%^%^MAGENTA%^"+ETOQCN+" presses her advantage as "+
			" "+who->QCN+" stares at her breasts.",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^MAGENTA%^"+who->QCN+" stares right at your breasts!");
        tell_object(who,"%^BOLD%^%^MAGENTA%^Your gaze falls to "+ETOQCN+"'s breasts for a moment.");
				ETO->execute_attack();
	}
    return damage;
}