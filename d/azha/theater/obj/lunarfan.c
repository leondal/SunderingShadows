#include <std.h>

inherit "/d/common/obj/weapon/fan.c";

void create(){
  	::create();
  	set_name("lunar fan");
   	set_id(({"fan","lunar fan"}));
   	set_obvious_short("%^BOLD%^%^WHITE%^A %^RESET%^%^MAGENTA%^c"+
		"%^BLUE%^o%^CYAN%^l%^BLUE%^o%^MAGENTA%^r%^BLUE%^f"+
		"%^CYAN%^u%^MAGENTA%^l%^RESET%^%^BOLD%^ fan%^RESET%^");
   	set_short("%^RESET%^%^MAGENTA%^L%^CYAN%^u%^BLUE%^n%^CYAN%^"+
		"a%^MAGENTA%^r Fan%^RESET%^");
   	set_long("%^RESET%^This elegant fan is made from a combination"+
		" of silk and mithril.  The outer frame of the fan"+
		" is made from thick %^BOLD%^%^WHITE%^mithril%^RESET%^ giving "+
		"the fan strength and stability.  Opening the fan up"+
		" reveals an image of a %^BOLD%^%^WHITE%^si%^RESET%^l%^BOLD%^v"+
		"%^CYAN%^e%^WHITE%^ry crescent moon%^RESET%^ against"+
		" flowing colors of %^MAGENTA%^purple%^RESET%^, %^CYAN%^"+
		"blue-green%^RESET%^, and %^BLUE%^dark blue%^RESET%^.  Salt"+
		" has been added to the dye process causing the %^MAGENTA%^c"+
		"%^BLUE%^o%^CYAN%^l%^MAGENTA%^o%^CYAN%^r%^BLUE%^s%^RESET%^"+
		" to streak together and create what looks to be vague star"+
		" shapes.  %^BOLD%^Mithril%^RESET%^ points rise out of the"+
		" folds of the fan, each point sharpened to a star like point"+
		".  A heavy tassel in %^MAGENTA%^purple%^RESET%^, "+
		"%^CYAN%^blue-green%^RESET%^, and %^BLUE%^dark blue%^RESET%^"+
		" hangs from the hand hold of the fan on a %^BOLD%^"+
		"silvery cord%^RESET%^.\n");
   	set_lore("Hivetta's Harmony was the last performance staged at"+
		" The Desert Sun, Azha's premier theater.  No is sure what this"+
		" mysterious opera written by Ixi Desterl was about. What few "+
		"facts have been gathered deal mainly with the outside contract"+
		" work that Ixi commissioned for the opera.  The case in point "+
		"is a mithril and silk fan.  Ixi placed an order for numerous "+
		"of these fans, giving a hint to the blacksmith and tailor that"+
		" worked on the order that the fans would play an important "+
		"role in his play.  Some have guessed that Hivetta was a "+
		"priestess of follower of Selune, due to the image on the "+
		"fans, though others are quick to point out that just because"+
		" something has the image of a moon on it does not mean it's "+
		"related to Selune.  All attempts to learn more about Hivetta's"+
		" Harmony have been met with dead ends to this point.  Will the"+
		" world ever know what happened to The Desert Sun on that night?"+
		" - The Desert Sun: The Rising and Setting of a Legacy - Aisha"+
		" Mydrid");
   	set_property("lore difficulty",9);
	set_property("enchantment",2);
	set_item_bonus("attack bonus",1);
   	set("value",200);
   	set_wield((:TO,"wield_func":));
   	set_unwield((:TO,"unwield_func":));
   	set_hit((:TO,"hit_func":));
   	set_prof_type("fan");
}
int wield_func(string str) {
   	tell_object(ETO,"%^MAGENTA%^You snap the fan open, "+
		"revealing an image of a crescent moon in a star filled"+
		" sky.%^RESET%^");
   	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" snaps "+
		"the fan open, revealing an image of crescent moon"+
		" in a star filled sky.",ETO);
				return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^MAGENTA%^You close the fan and tuck it away"+
		" in a safe spot.");
   	tell_room(environment(ETO),"%^MAGENTA%^"+ETO->QCN+" "+
      	"closes the fan and tucks it away in a safe spot.",ETO);
   				return 1;
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;
  	if(random(1000) < 200)
    {
      	switch(random(50))
        {
        case 0..40:
              tell_object(ETO,"%^CYAN%^You swipe your target quickly "+
                "with the mithril tips of your fan.");
              tell_object(targ,"%^CYAN%^"+ETO->QCN+" swipes "+
                " you with the mithril tips of "+ETO->QO+" fan.");
              tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+" swipes "+targ->QCN+""+
                " with the mithril tips of "+ETO->QP+" fan.", ({ETO,targ}));
              targ->cause_typed_damage(targ, "torso", roll_dice(1, 4) + 1, "slashing");
            break;
        case 41..49:
            tell_object(ETO,"%^BLUE%^Spinning your fan rapidly, a "+
                "%^BOLD%^%^WHITE%^shooting star%^RESET%^%^BLUE%^"+
                " streaks through the air and into "+targ->QCN+".");
              tell_object(targ,"%^BLUE%^"+ETO->QCN+" starts to spin "+ETO->QP+" fan"+
                " rapidly.  A %^BOLD%^%^WHITE%^shooting star%^RESET%^%^BLUE%^ streaks"+
                " through the air and into "+targ->QCN+".");
              tell_room(environment(ETO),"%^BLUE%^"+ETO->QCN+" spins "+ETO->QP+" "+
                "fan rapidly.  A %^BOLD%^%^WHITE%^"+
                "shooting star%^RESET%^%^BLUE%^ streaks through the air and"+
                " into "+targ->QCN+".", ({ETO,targ}));
            set_property("magic",1);
            targ->cause_typed_damage(targ, "torso", roll_dice(1, 5) + 9, "divine");
            set_property("magic",-1);

        default:  
            break;
		}
    return 1;
    }
}
