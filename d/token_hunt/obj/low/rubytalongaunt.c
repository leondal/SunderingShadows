#include <std.h>
inherit "/d/common/obj/armour/gauntlets.c";

void create(){
	::create();
	set_name("gauntlets");
	set_id(({ "gauntlets", "ruby talons", "ruby gauntlets", "ruby studded gauntlets", "talons" }));
	set_short("%^BOLD%^%^RED%^R%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^b%^RED%^y T%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^l%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^n%^RED%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a set of %^RED%^ruby studded%^BLACK%^ gauntlets%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Made from a %^WHITE%^s%^RESET%^il%^BOLD%^%^BLACK%^v%^RESET%^er%^BOLD%^%^WHITE%^y %^BLACK%^metal that has been textured into the shape of small rippling %^RED%^scales%^BLACK%^, these gauntlets stretch from a tight, flexible glove up to about midway on the arm.  Highlighted with a lace like mesh about the wrist and cuff, small spheres of polished %^RED%^ruby %^BLACK%^adorn the larger mesh holes, held in place by a thin piece of wire that passes through the center of the spheres.  Across the knuckle joints more %^RED%^rubies %^BLACK%^have been set, these wider ovals that lift above the knuckles through the raised %^WHITE%^j%^RESET%^o%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^%^WHITE%^t %^BLACK%^of metal.  Extending from each finger, %^RED%^ruby talons %^BLACK%^can be found, though on closer inspection it is clear that the ruby is actually fit around sharp metal claws.%^RESET%^

AVATAR
	);
	set_value(0);
	set_lore(
@AVATAR
Uskatho Blielm is credited with making these types of gauntlets in the early third century.  Fascinated by the way that lizards moved and fought, he modeled several items after their lithe, quick shapes.  Of high interest to him were the small fire lizards that lived on his native island.  These little creatures were predominantly black in coloration but featured small bands of red spotting along their backs and a ruffle of bright red around the neck.  To mimic this coloration Uskatho created several of the items that came out of his workshop with similar markings.  Everything from the delicate ruffles to the dots of bright red ruby coloring.  It is said that he died a pauper due to his overwhelming reliance upon the ruby coloring, refusing to work with lesser stones such as agate.

AVATAR
	);
	set_property("lore difficulty",15);
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",1);
   }
	set_struck((:TO,"strike_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^As "+who->QCN+" lands a solid blow upon "+ETOQCN+", "+ETOQCN+" appears to come to life, retaliating with several lightning quick slashes to "+who->QCN+"'s arms and face!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^RED%^As "+who->QCN+"'s blow lands you feel the muscles in your arms tighten and respond!  With lightning speed you strike out with your talon covered hands, ripping and tearing at any exposed area you can see in "+who->QCN+"'s guard!%^RESET%^");
	tell_object(who,"%^BOLD%^%^RED%^You grin as you land a telling blow on "+ETOQCN+" only to be stunned as they appear to react not in pain but in aggression!  With a series of lightning fast strikes, they claw and tear at your arms and face, ripping gashes anywhere they land their "+query_short()+"%^BOLD%^%^RED%^!%^RESET%^");
	who->cause_typed_damage(who, "torso", roll_dice(3, 3), "slashing");
return damage;	}
}