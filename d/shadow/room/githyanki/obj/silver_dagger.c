
#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";


void create() {
    ::create();
   set_id(({"dagger"}));
   set_name("silver dagger");
   set_short("%^RESET%^%^BOLD%^%^WHITE%^sil%^RESET%^%^WHITE%^v%^RESET%^"+
"%^BOLD%^%^WHITE%^er d%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^gger"+
"%^RESET%^");
   set_long("%^RESET%^%^BOLD%^%^WHITE%^this small dagger's blade is "+
"made from what looks like silver etched with a %^RESET%^%^BOLD%^%^BLACK%^"+
"darker metal %^RESET%^%^BOLD%^%^WHITE%^in vei%^RESET%^%^WHITE%^n%^RESET%^"+
"%^BOLD%^%^WHITE%^s al%^RESET%^%^WHITE%^o%^RESET%^%^BOLD%^%^WHITE%^ng the "+
"edg%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^WHITE%^s. The blade is smaller "+
"then you would expect, but the blade is wickedly sharp. The hilt of the "+
"blade has been wrapped in the %^RESET%^%^ORANGE%^leather %^RESET%^%^BOLD%^"+
"%^WHITE%^from an unknown source%^RESET%^");
   set_property("enchantment",2);
   set_item_bonus("attack bonus",1);
   set("value", 2000);
   set_hit((:TO, "hit_func" :) );
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_property("lore difficulty",20);
   set_lore("%^BLACK%^%^BOLD%^Upon reaching a certain point in training, "+
"a young githyanki is given a silver blade and sent to fight until that "+
"blade has been whetted with the blood of either githzerai or illithid. "+
"Often large groups of young gith leave, with only one or two returning.%^RESET%^");
 
}

int wield_func(object targ){
        tell_room(EETO,"%^RESET%^%^BOLD%^As "+ETOQCN+" %^RESET%^%^BOLD%^wraps"+
" their hands around the "+query_short()+", %^RESET%^%^BOLD%^it glows "+
"softly.%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^RESET%^%^BOLD%^You wrap your hands around "+
"the "+query_short()+", %^RESET%^%^BOLD%^your head filling with strange"+
" images of the hunt. ");
        return 1;
}   

int unwield_func(object targ) { 
    tell_room(EETO,"%^RESET%^%^RED%^"+ETOQCN+"%^RESET%^%^RED%^ sets the"+
" blade aside, looking around with a frown.%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^RESET%^%^RED%^You set the "+query_short()+" "+
"%^RESET%^%^RED%^aside, longing for the images of greatness to return.%^RESET%^");
        return 1;
}

int hit_func(object targ){
        if(!objectp(targ)) return 0;
        if(!objectp(ETO)) return 0;
		
		
        if(random(1000) < 100){
		      switch(random(6)){
        case 0:
		tell_room(EETO,"%^RESET%^%^RED%^"+ETOQCN+" %^RESET%^%^RED%^thrusts"+
" the blade deeply into "+targ->QCN+"%^RESET%^%^RED%^.%^RESET%^",({ETO,targ}));
		tell_object(ETO,"%^RESET%^%^RED%^You thrust the blade deeply into "+
""+targ->QCN+"%^RESET%^%^RED%^ and feel it thrum with life.%^RESET%^"); 
		tell_object(targ,"%^RESET%^%^RED%^"+ETOQCN+" %^RESET%^%^RED%^thrusts"+
" the blade deeply into you.%^RESET%^");
		return roll_dice(3,4)+-1;
        	break;
			
		case 1..6:
		tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" %^BOLD%^%^RED%^slashes "+
"along "+targ->QCN+"%^BOLD%^%^RED%^.%^RESET%^'s body with the dagger",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^%^RED%^You slash your blade quickly along"+
" %^BOLD%^%^RED%^"+targ->QCN+"%^BOLD%^%^RED%^'s body.%^RESET%^"); 
		tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+"%^BOLD%^%^RED%^ slashes "+
"you horribly with the dagger, starting a torrent of blood!%^RESET%^");
		targ->set_paralyzed(roll_dice(1,6)+3,"%^RED%^%^BOLD%^You're trying "+
"to stop the blood!%^RESET%^");
			break;
		
        return 0;       
		}
    }
}
