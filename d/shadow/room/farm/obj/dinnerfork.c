#include <std.h>
inherit "/d/common/obj/weapon/trident.c";

void create()
{
   	::create();
   	set_name("gold fork");
   	set_short("%^YELLOW%^Mechanical Dinner Fork%^RESET%^");
   	set_obvious_short("%^YELLOW%^A gold fork%^RESET%^");
   	set_id(({"gold fork","fork","dinner fork","mechanical dinner fork"}));
   	set_long("%^YELLOW%^Fashioned from yellow gold is what "+
		"looks like a large dinner fork attached to a "+
		"%^RESET%^%^ORANGE%^brass%^YELLOW%^"+
		" base.  The three pronged fork tapers to fine points,"+
		" looking as if it could pierce through even the toughest"+
		" meats.  The patterned fork has been bolted onto a "+
		"%^RESET%^%^ORANGE%^bronze%^BOLD%^ metal rod that has"+
		" been inserted into the brass base.  The brass base "+
		"of the fork is heavy, hinting at that something might"+
		" be housed within the shaft.%^RESET%^\n"); 
   	set_value(100);
	set_lore("The Mechanical Dinner Fork was crafted by the "+
		"gnomish inventor Piaf Huffelmuffin in an attempt "+
		"to simplify the ritual of dining.  Piaf often found "+
		"his meals overcooked or burnt due to his absent "+
		"minded nature.  Tired of always having to fight to "+
		"cut the tough cuts of meat, Piaf instead invented a"+
		" mechanical fork that would force its way into even"+
		" the toughest hides.  Because Piaf was usually moving"+
		" about his home and workshop, he attached the fork to"+
		" a shaft so that he might eat from across the room.-"+
		" An Observation"+
		" of Piaf - Theadora Illonium");
	set_property("lore",5);
   	set_property("enchantment",1);
   	set_hit((:TO,"hitme":));
   	set_wield("%^YELLOW%^The gold fork feels heavy in your hands.");
	set_unwield("%^YELLOW%^You set the heavy gold fork down.");
}

int hitme(object targ)
{
   if(!random(8)) {
      tell_object(ETO,"%^ORANGE%^%^The gold fork begins to move back and "+
		"forth, piercing "+targ->QCN+" twice!");
      tell_object(targ,"%^ORANGE%^From "+ETO->QCN+"'s gold fork "+
		"begins to move back and forth, piercing you twice!.");
      tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+"'s gold fork"+
      	" begins to move back and forth, piercing"+
      	" "+targ->QCN+" twice.",({ETO,targ}));
      	     	targ->do_damage("torso",random(4)+1);
      return 1;
   }
   if(!random(16)) {
      tell_object(ETO,"%^YELLOW%^Your gold fork moves at rapid speed "+
		"jabbing into "+targ->QCN+".\n Suddenly the fork stops as"+
		" clouds of smoke rolls out of the brass base.");
      tell_object(targ,"%^YELLOW%^"+ETO->QCN+"'s gold fork starts to move rapidly"+
     		" jabbing into your flesh.\n Suddenly "+ETO->QP+" "+
		"fork stops moving as clouds of smoke rolls out of"+
		" the brass base.");
      tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+"'s gold fork "+
		"starts to move rapidly"+
     		" jabbing into "+targ->QCN+"'s flesh.\n Suddenly "+ETO->QP+" "+
		"fork stops moving as clouds of smoke rolls out of"+
		" the brass base.",({ETO,targ}));
      		targ->do_damage("torso",random(8)+2);
      return 1;
   }
}
