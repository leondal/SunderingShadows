//updated spear for Tonerra

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit "/d/common/obj/weapon/spear_sm.c";

void create(){
  ::create();
  	set_name("%^YELLOW%^Citrine Monkey Spear%^RESET%^");
  	set_id(({"spear","short spear","citrine monkey spear"}));
  	set_short("%^YELLOW%^Citrine %^RESET%^%^ORANGE%^Monkey%^BOLD%^ Spear%^RESET%^");
	set_obvious_short("%^RESET%^A small spear with a %^YELLOW%^citrine%^RESET%^ carving");
  	set_long("This short spear is made from a combination of "+
		"%^ORANGE%^teak wood%^RESET%^ and %^BOLD%^%^BLACK%^"+
		"g%^WHITE%^r%^BLACK%^a%^WHITE%^n%^BLACK%^i%^WHITE%^t%^BLACK%^e"+
		"%^RESET%^.  The stout teak wood shaft is made to give "+
		"stability to the spear.  A diamond shaped piece of "+
		"%^BOLD%^%^BLACK%^ g%^WHITE%^r%^BLACK%^a%^WHITE%^n"+
		"%^BLACK%^i%^WHITE%^t%^BLACK%^e %^RESET%^has "+
		"been tied to the shaft with %^GREEN%^vines%^RESET%^"+
		".  Sharpened around the edges, the spearhead comes to"+
		" a sharp point.  Dangling from the %^GREEN%^vines%^RESET%^"+
		" that bind the spearhead to the shaft is a totem carving of"+
		" a %^ORANGE%^monkey%^RESET%^, out of %^YELLOW%^citrine%^RESET%^.");
	set_property("lore",14);
	set_lore("The natives of Tonerra look to the spirts of the jungle"+
		" to guide and protect their people.  One of the most beloved"+
		" spirts is the Yellow Monkey.  To the natives, the Yellow "+
		"Monkey is a trickster totem spirit, who posseses a cunning "+
		"mind and deft acrobatic feats.  The stories of the Yellow "+
		"Monkey usually involve him swindling some other animal spirit"+
		" out of something, or using his crafty mind to get him out of "+
		"danger. - Totem Spirits of Tonerra - Thalluke Des'Pordam");
  	set_hit((:TO,"hit_me":));
	set_value(700);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
   	set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) {
   if((int)ETO->query_level() < 17) {
      tell_object(ETO,"%^YELLOW%^The spear rolls out of your grasp.");
      tell_room(environment(ETO),"%^YELLOW%^The short spear rolls away"+
		" from "+ETOQCN+"'s grasp.");
	return 0;
}
   	tell_object(ETO,"%^YELLOW%^Light flickers inside the citrine carving"+
		" of the monkey as you grasp the spear.");
   	tell_room(environment(ETO),"%^YELLOW%^A yellow light flickers "+
		"from inside the carving of the monkey on "+ETOQCN+"'s spear.",ETO);
   	return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^YELLOW%^The carving of the monkey winks at you"+
		" before the flickering light fades away.");
   	tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+" releases "+ETO->QS+""+
		" hold of the spear.",ETO);
      return 1;
}

int hit_me(object targ)
{
   if(!random(8)) {
      tell_object(ETO,"%^YELLOW%^You slap "+targ->QCN+" with the butt of"+
		" the spear, dazing them for a brief moment.  Using the time "+
		"to your advantage, you spin the tip of the spear around and "+
		"jab it into "+targ->QS+".");
      tell_object(targ,"%^YELLOW%^"+ETO->QCN+" slaps you with the butt"+
      	" of "+ETO->QP+" spear, leaving your dazed for a brief moment."+
		"  "+ETO->QCN+" spins the tip of "+ETO->QP+" around and jabs"+
		" it into you!");
      tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+" slaps "+targ->QCN+""+
		" with the butt of "+ETO->QP+" spear.  Spinning "+ETO->QP+""+
		" spear around, "+ETO->QS+" jabs the spear "+
		"into "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+3);
      return 1;
   }
   if(!random(22)) {
      tell_object(ETO,"%^ORANGE%^You feel the spirt of the monkey "+
		"guide your attack on "+targ->QCN+".");
      tell_object(targ,"%^ORANGE%^"+ETO->QCN+" begins to leap about"+
		" you, jabbing you multiple times with "+ETO->QP+" spear.");
      tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+" begins to "+
		"wildly leap around "+targ->QCN+", jabbing "+targ->QO+" "+
		"multiple times.",({ETO,targ}));
      		targ->do_damage("torso",random(6)+10);
  	return 1;
   }
}
