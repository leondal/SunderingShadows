// really big drill for giants
#include <std.h>
inherit "/d/common/obj/weapon/giant_club.c";

void create() {
    ::create();
   set_id(({"drill","giant drill"}));
   set_name("%^BOLD%^%^BLACK%^giant drill%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A giant drill%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Giant Drill%^RESET%^");
   set_long("This clublike weapon is a drill on a "+
     "metal shaft. There is a large gear at"+
	 " the bottom of the shaft and a %^BOLD%^diamond%^RESET%^"+
	 " tip%^RESET%^.  There are many etchings of runes used "+
	 "for added strength.  It would be terrible to hit someone with this.");
	set_lore("This drill was actually created by "+
    "gnomes to equip on their machines."+
    "  The large creations could drill through "+
    "most everything in their way."	);
	set_property("lore difficulty",15);
   set("value",2000);
   set_property("enchantment",2);
   set_hit((:TO,"hit_func":));

}

int hit_func(object targ){
     if(random(1000) < 250){
        tell_room(ETO, "%^ORANGE%^"+ETOQCN+"'s "+
         "drill %^RED%^_SMASHES_%^ORANGE%^ "+targ->QCN+"."+
		 " hisses from acid.",({ETO,targ}));
        tell_object(ETO,"%^ORANGE%^You %^RED%^_SMASH_%^ORANGE%^ "+
           targ->QCN+" in a serious manner.");
        tell_object(targ,"%^ORANGE%^"+
           "The blow from "+ETOQCN+"'s drill %^RED%^_SMASHES_%^ORANGE%^ you.");

		return roll_dice(3,10)+1;}

   return 0;
}
