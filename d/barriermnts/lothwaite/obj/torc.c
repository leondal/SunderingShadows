// a large torc that bites -hades 8/10
#include <std.h>
#include <daemons.h>
inherit ARMOUR;


void create(){
        ::create();
        set_name("lion torc");
        set_id(({ "torc", "lion torc" }));
        set_short("%^RESET%^%^ORANGE%^lion's torc%^RESET%^");
        set_obvious_short("%^RESET%^%^ORANGE%^large torc%^RESET%^");
        set_long(""+
          "%^ORANGE%^This masterfully crafted torc looks somewhat "+
		  "like a necklace.  It goes around the wearers"+
		  " neck and has an open spot at the front of the"+
		  " neck.  The torc is made from a mix of %^RESET%^brass%^ORANGE%^ "+
		  "and %^BOLD%^gold%^RESET%^ %^ORANGE%^with "+
		  "two %^YELLOW%^lions heads%^RESET%^%^ORANGE%^ at the either "+
		  "end of the torc.   The heads have two yellow"+
		  " sapphires for eyes that seem to watch as if "+
		  "to protect the wearer.%^RESET%^");


        set_weight(5);
        set_value(3000);
                set_property("lore difficulty",25);
        set_lore("It is said that this torc was "+
		"once made by a firbolg chieftan to show"+
		" his leadership over the warriors of his"+
		" tribe.  Priests enchanted it to give "+
		"additional protections making him "+
		"an even more powerful leader." );
        set_type("clothing");
        set_limbs(({ "neck" }));
        set_size(3);
        set_property("enchantment",3);
        set_ac(0);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
        set_struck((:TO,"strike_func":));
}
int wear_func(){
      if(!objectp(ETO)) return 1;
      if(!objectp(EETO)) return 1;
 
       tell_room(environment(ETO),"%^ORANGE%^"
	   +ETOQCN+" slips"+
        " a torc on making "+ETO->QO+""+
        " them look noble",ETO);
        tell_object(ETO,"%^ORANGE%^you slip the torc "+
        "around your neck.");       
          return 1;
}
int remove_func(){
        tell_room(environment(ETO),"%^ORANGE%^As "+ETOQCN+
        "removes "+ETO->QP+" they look less noble.",ETO);
        tell_object(ETO,"%^ORANGE%^You remove your"+
		" torc and feel a little less epic.");
                return 1;


}
int strike_func(int damage, object what, object who){
if(!objectp(ETO)) return 1;
     

        if(random(500) < 100){
        tell_room(environment(query_worn()),"%^ORANGE%^For"+
        " a moment "+who->QCN+" looks surprised"+
        " by "+ETOQCN+"'s torc, the lions head bites "+
        who->QCN+".",({ETO,who}));
        tell_object(ETO,"%^ORANGE%^Your torc comes alive"+
        " and bites"+
        " "+who->QCN+" when they get too close.");
        tell_object(who,"%^ORANGE%^"+ETOQCN+"'s"+
        " torc's lion head bites you!");
		 who->do_damage(random(6)+2);
         return 0;
		}
}
