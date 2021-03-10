// Tiamat's Barb  - LoKi - 25-02-2008 ((gith_guard.c)

#include <std.h>
inherit "/d/common/obj/weapon/whip.c";


void create() {
    ::create();
   set_id(({"barb","whip","tiamats barb"}));
   set_name("black barb");
   set_short("%^RESET%^%^BOLD%^%^BLACK%^Ti%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^"+
"%^BLACK%^mat's B%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^rbed Wh%^RESET%^"+
"%^WHITE%^i%^RESET%^%^BOLD%^%^BLACK%^p%^RESET%^");
   set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^sm%^RESET%^%^WHITE%^a%^RESET%^"+
"%^BOLD%^%^BLACK%^ll bla%^RESET%^%^WHITE%^c%^RESET%^%^BOLD%^%^BLACK%^k "+
"barb%^RESET%^");
   set_long("%^RESET%^%^BOLD%^%^BLACK%^The handle of this small whip is "+
"wrapped in black leather and seems to almost contain the constantly writhing"+
" whip. The whole length of the business end of this weapon is black and "+
"glistening with a %^RESET%^%^GREEN%^fo%^RESET%^%^BOLD%^%^BLACK%^u%^RESET%^"+
"%^GREEN%^l smell%^RESET%^%^BOLD%^%^BLACK%^i%^RESET%^%^GREEN%^ng li%^RESET%^"+
"%^BOLD%^%^BLACK%^q%^RESET%^%^GREEN%^uid%^RESET%^%^BOLD%^%^BLACK%^. It sways "+
"back and forth as if alive. The end of the whip is tipped with a%^RESET%^"+
"%^BOLD%^%^WHITE%^ sm%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^ll gem-like"+
" b%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^rb %^RESET%^%^BOLD%^%^BLACK%^"+
"that catches the light. The weapon is small enough that it could be wielded "+
"easily in even the smallest of hands.%^RESET%^");
   set_property("enchantment",random(2) + 1);
   set_item_bonus("attack bonus",1);
   set("value", 2000);
   set_hit((:TO, "hit_func" :) );
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_property("lore difficulty",20);
   set_lore("%^RESET%^%^BOLD%^%^BLACK%^The creation of this whip is clouded in"+
" secrecy, but it has been rumored that a githyanki weaponsmith gained the "+
"insight and fortune of one of Tiamat's generals, the ancient black. The "+
"weapon created was named after Tiamat herself in homage. %^RESET%^");
   set_size(1);
   set_wc(1,3);
   set_large_wc(1,2);
 
}

int wield_func(object targ){
        tell_room(EETO,"%^BLACK%^%^BOLD%^As "+ETOQCN+" %^BLACK%^%^BOLD%^wraps"+
" their hands around the "+query_short()+", %^RESET%^%^BOLD%^it begins to writhe"+
" around.%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^BLACK%^%^BOLD%^You wrap your hands around "+
"the "+query_short()+", %^BLACK%^%^BOLD%^it comes alive, attempting to sting you");
        return 1;
}   

int unwield_func(object targ) { 
    tell_room(EETO,"%^RESET%^%^RED%^"+ETOQCN+"%^RESET%^%^RED%^ sets the"+
" whip aside, it stops writhing slowly.%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^RESET%^%^RED%^You unwield the "+query_short()+" "+
"%^RESET%^%^RED%^it stops its constant writhing.%^RESET%^");
        return 1;
}

int hit_func(object targ){
        if(!objectp(targ)) return 0;
        if(!objectp(ETO)) return 0;
		
		
        if(random(1000) < 100){
		      switch(random(6)){
        case 1..4:
		tell_room(EETO,"%^RESET%^%^RED%^"+ETOQCN+" %^RESET%^%^RED%^rakes the barb "+
"across "+targ->QCN+"%^RESET%^%^RED%^'s face.%^RESET%^",({ETO,targ}));
		tell_object(ETO,"%^RESET%^%^RED%^You rake the whip across "+targ->QCN+"%^RESET%^"+
"%^RED%^'s face.%^RESET%^"); 
		tell_object(targ,"%^RESET%^%^RED%^"+ETOQCN+" %^RESET%^%^RED%^bloodies your face"+
" with their barb.%^RESET%^");
		return roll_dice(3,4)+-1;
        	break;
			
		default:
		tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" %^BOLD%^%^RED%^'s whip grabs onto"+
" "+targ->QCN+"%^BOLD%^%^RED%^.%^RESET%^'s body.%^RESET%^",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^%^RED%^The barb comes to life, snaking around %^BOLD%^"+
"%^RED%^"+targ->QCN+"%^BOLD%^%^RED%^'s body.%^RESET%^"); 
		tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+"%^BOLD%^%^RED%^ 's barb snakes around"+
" your body!%^RESET%^");
		targ->set_paralyzed(roll_dice(1,6)+3,"%^RED%^%^BOLD%^You're trying to free "+
"yourself!%^RESET%^");
			break;
		
        return 0;       
		}
    }
}
