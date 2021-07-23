#include <std.h>
inherit "/d/common/obj/weapon/claw.c";

void create(){
	::create();
	set_name("bear claw");
	set_id(({ "claw", "bear claw", "glove", "clawed glove", "bearclaw" }));
	set_short("%^RESET%^%^ORANGE%^B%^YELLOW%^e%^RESET%^a%^ORANGE%^r C%^BOLD%^%^BLACK%^l%^YELLOW%^a%^RESET%^%^ORANGE%^w%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a c%^YELLOW%^l%^RESET%^%^ORANGE%^a%^WHITE%^w%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d glove%^RESET%^");
	set_long("%^RESET%^Made from sturdy, tanned leather and covered "+
	   "in %^ORANGE%^thick brown fur%^RESET%^, this hand covers look "+
	   "less like a glove and more like a bear's paw.  The fur is "+
	   "coarse and mottled with %^ORANGE%^brown%^RESET%^, %^YELLOW%^"+
	   "gold%^RESET%^, %^BOLD%^%^BLACK%^black %^RESET%^and %^BOLD%^"+
	   "%^WHITE%^gray %^RESET%^shades to it.  Extending from each "+
	   "finger are shards of %^BOLD%^%^WHITE%^ivory%^RESET%^, darkened "+
	   "and made glossy so that they gleam a pale %^YELLOW%^y%^RESET%^"+
	   "%^ORANGE%^e%^YELLOW%^l%^BLACK%^l%^RESET%^o%^YELLOW%^w-g%^RESET%^"+
	   "r%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^y%^RESET%^.  These have "+
	   "been filed to sharp, sturdy points, much the way one would "+
	   "expect bear claws to look in the wild.  Sewn into the glove, "+
	   "between the lairs of leather, are reinforcements of %^BOLD%^"+
	   "%^WHITE%^bone %^RESET%^to provide strength and power to this "+
	   "curious weapon.");
   set_value(0);
	set_lore("The people of the Veymer tribe believe that each person "+
	   "is born with a guardian animal.  One which will grant them powers "+
	   "and insight into their true selves as they reach maturity.  When a "+
	   "Veymer child reaches his fifteenth year, he goes into the wilds and "+
	   "beseeches his animal to reveal itself to him.  When the animal "+
	   "appears, the young Veymer is granted insight into his future and "+
	   "what he will become.  Those who have bears appear become warriors "+
	   "of the tribe, exceptional combatants who specialize in close "+
	   "fighting, often called boxing.  Some, who feel exceptionally "+
	   "close to their guardian spirits will even make garments and "+
	   "weapons to resemble their guardian spirit's form.");
	set_property("lore difficulty",20);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
      set_item_bonus("damage bonus",2);
	set_hit((:TO,"hit_func":));
    set_overallStatus(220);
    set_property("no disenchant",1);
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^RESET%^%^ORANGE%^"+ETOQCN+" suddenly sinks both claws into "+targ->QCN+" and draws them close for a crushing bearhug!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^ORANGE%^With fast motions, you step forward and sink your claws into "+targ->QCN+", pulling them close for a crushing bearhug!%^RESET%^");
	tell_object(targ,"%^RESET%^%^ORANGE%^You feel yourself pulled swiftly toward "+ETOQCN+" as their claws sink into your flesh and you are crushed in a powerful bearhug!%^RESET%^");
		return roll_dice(2,4)+2;	}
}