#include <std.h>

inherit "/d/common/obj/weapon/rapier.c";

void create(){
   ::create();
   set_name("songblade");
   set_id(({"songblade","rapier","sword","song rapier","blade","+
    	""darksteel rapier"}));
   set_short("%^RESET%^%^MAGENTA%^S%^CYAN%^o%^BLUE%^n"+
	"%^MAGENTA%^g%^CYAN%^b%^BLUE%^l%^MAGENTA%^a%^CYAN%^d%^BLUE%^e%^RESET%^");
   set_obvious_short("%^RESET%^%^MAGENTA%^A darksteel rapier%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Forged from precious darksteel, this "+
    	"slender rapier is sharpened to a fine point.  The lightweight blad"+
    	"e is so thin that it looks as if it almost might snap in two.  The"+
    	" silvery hue of the darksteel has a %^RESET%^%^MAGENTA%^deep purple"+
    	"%^BOLD%^%^WHITE%^ luster to it when exposed to light.  Near the bas"+
    	"e of the rapier three interlocking circles have been etched into the met"+
    	"al.  A swept guard on the rapier made from platinum and gold  angles"+
    	" to the left elegantly.  The flowing guard is inlaid with rare "+
    	"%^RESET%^%^MAGENTA%^purple sapphires%^BOLD%^%^WHITE%^ and "+
    	"%^BLUE%^blue diamonds%^WHITE%^, giving the rapier a rich "+
    	"opulent feeling.  The ivory handle is smooth to the touch"+
    	", worn by time.  The claw mounting on the pommel of this "+
    	"slender rapier holds a faceted colorless ruby sphere.%^RESET%^\n");
   set_lore("A favored blade by the Cacophony Sirens,  the Songblade"+
	" rapier is said to be infused with the life of music itself."+
    	"  Unlike their aquatic counterparts, the Cacophony Sirens are not"+
    	" tied to the water.  These vicious women posses some of the same "+
    	"powers over song as their counterparts.  Able to tap into a rare"+
	" ancient type of magic called Song Magic, the Sirens are able to"+
	" create blades that deal sonic damage.  The blades are a favorite"+
	" with bards, who find the music soothing. - The Ecology of Sirens "+
	"- Larex Trayum ");
   set_property("lore difficulty",13);
   set_property("enchantment",2);
   set_item_bonus("attack bonus",1);
   set_item_bonus("damage bonus",1);
   set_weight(4);
   set("value",100);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(string str) {
   if((int)ETO->query_level() < 13) {
      tell_object(ETO,"%^BOLD%^%^GREEN%^A wild chaotic song fills your"+
		" senses as you try to wield the rapier.");
      tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" drops th"+
      	"e rapier as a wild chaotic song issues forth from the blade.");
	return 0;
}
   	tell_object(ETO,"%^MAGENTA%^The rapier begins to hum a sweeping"+
		" melody as you wield it.");
   	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+"'s rapier hums a swe"+
   		"eping melody as "+ETO->QS+" wields it.",ETO);
   	return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^CYAN%^The rapier's humming ceases.");
   	tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+"'s "+
      	"rapier ceases its sweeping song abruptly.",ETO);
   	return 1;
}
int hit_func(object victim) {
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(victim)) return 1;
    
    if(random(1000) < 150)
    {
   	
        switch(random(50))
        {	
        case 0..35:
            tell_object(ETO,"%^MAGENTA%^The rapier sings a pier"+
                "cing note to "+victim->QCN+".");
              tell_object(victim,"%^MAGENTA%^"+ETO->QCN+"'s rapier sings "+
                "an ear piercing note at you.");
              tell_room(environment(ETO),"%^MAGENTA%^"+ETO->QCN+"'s rapier"+
                " sings a brief ear piercing note, directed at "+
                ""+victim->QCN+".",({ETO,victim}));
                    return roll_dice(1,6)+2;
             break;
        case 36..49:
              tell_object(ETO,"%^CYAN%^"+victim->QCN+" is held enthralled"+
                    " by the song that your rapier sings.");
              tell_object(victim,"%^CYAN%^An enthralling song fills your "+
                "sense, captivating you in its beauty.",);
              tell_room(environment(ETO),"%^CYAN%^"+victim->QCN+" is enth"+
                "ralled by a beautiful song, that seems to be coming from "+
                ""+ETOQCN+"'s rapier.",({ETO,victim}));
                        victim->set_paralyzed(random(10)+5);
            break;
            
        default:  
            break;
            
        }
    return 1;
    }
}
