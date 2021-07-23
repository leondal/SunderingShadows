#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("circlet");
	set_id(({ "circlet", "forgotten soul circlet", "amethyst circlet", "bone circlet" }));
	set_short("%^RESET%^%^MAGENTA%^A%^BLACK%^%^BOLD%^m%^RESET%^e%^MAGENTA%^th%^BOLD%^%^BLACK%^y%^RESET%^%^MAGENTA%^st C%^BOLD%^%^BLACK%^i%^RESET%^r%^MAGENTA%^cl%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^t %^RESET%^of the %^BOLD%^%^BLACK%^Fo%^WHITE%^r%^RESET%^g%^BOLD%^%^BLACK%^ot%^WHITE%^t%^RESET%^e%^BOLD%^%^BLACK%^n S%^WHITE%^o%^RESET%^u%^BOLD%^%^BLACK%^l%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^a circlet made of %^BOLD%^%^BLACK%^b%^WHITE%^o%^RESET%^n%^BOLD%^%^BLACK%^e%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^Looking closely at this circlet you "+
	   "realized that over two hundred tiny %^WHITE%^bones %^BLACK%^"+
	   "have been used to form this circlet. In amazing detail, each "+
	   "tiny bone is a perfect replica of the human skeletal system in "+
	   "tiny miniature.  Starting with the skull, which is placed directly "+
	   "over the brow and whose eyes hold a pair of %^RESET%^%^MAGENTA%^"+
	   "amethyst orbs%^BOLD%^%^BLACK%^, the circlet is fashioned using "+
	   "the curved rib bones to create the circular structure of the "+
	   "circlet.  These are joined together by the vertebrae to extend "+
	   "their curves and make the circlet somewhat adjustable.  While "+
	   "the pelvic bones provide a clasp in the back.  The small bones "+
	   "of the hands and feet, create a mosaic of curls and curves that "+
	   "surround the skull, the pattern %^RESET%^%^MAGENTA%^unfathomable "+
	   "%^BOLD%^%^BLACK%^and %^RESET%^forgotten %^BOLD%^%^BLACK%^as soon "+
	   "as it is focused upon.  Strangely the arm and leg bones point "+
	   "inward, as though they are meant to be driven into the wearer's "+
	   "skull.%^RESET%^");
	set_weight(4);
	set_value(0);
	set_lore("%^BOLD%^%^BLACK%^What lore you recalled about such an "+
	   "object fades from your mind as swiftly as you recall it.  All "+
	   "that is left is the delectable remains of a whispered secret, "+
	   "forgotten.%^RESET%^");
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
      set_item_bonus("intelligence",1);
      set_item_bonus("wisdom",1);
      set_item_bonus("charisma",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
    set_overallStatus(220);
    set_property("no disenchant",1);
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" screams out in pain as they wrap the "+query_short()+" %^BOLD%^%^BLACK%^around their head, driving the thin %^RESET%^spikes of bone %^BOLD%^%^BLACK%^into their own head!%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^You set the skull bone against your brow and wrap the remaining portion of the "+query_short()+" %^RESET%^%^MAGENTA%^around your head, feeling the bones %^RED%^slide %^MAGENTA%^into your skull and %^RESET%^pierce %^MAGENTA%^your mind with shards of %^BOLD%^%^BLACK%^oblivion%^RESET%^%^MAGENTA%^.  As the pain passes, you realize your mind is filled with %^RED%^cunning knowledge %^MAGENTA%^you did not possess before.%^RESET%^");
	ETO->cause_typed_damage(ETO, "torso", roll_dice(1, 10) - 1, "piercing");
	ETO->set_property("evil item",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" cries out and grips their %^RESET%^%^RED%^bloody head%^BOLD%^%^BLACK%^ as they pull the sharp %^RESET%^bone spikes %^BOLD%^%^BLACK%^of the "+query_short()+" %^BOLD%^%^BLACK%^away from their head.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^The piercing pain of drawing the "+query_short()+"'s %^RESET%^%^MAGENTA%^spikes from your head, nearly cause you to collapse.  A scream tears from your lips as both the sharp %^RESET%^spikes of bone %^MAGENTA%^and the %^BOLD%^%^BLACK%^secret knowledge %^RESET%^%^MAGENTA%^that had been granted are torn away.%^RESET%^");
	ETO->cause_typed_damage(ETO, "torso", roll_dice(1, 10) - 1, "piercing");
	ETO->set_property("evil item",-1);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^"+ETOQCN+"'s eyes glow with a fathomless %^RESET%^%^MAGENTA%^purple aura %^BOLD%^%^BLACK%^as they move between "+who->QCN+"'s defenses and land a telling blow.%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^Knowledge fills your mind and the world seems to fade away as your focus narrows upon "+who->QCN+".  With a movement both %^RESET%^%^MAGENTA%^graceful %^BOLD%^%^BLACK%^and %^RESET%^cunning%^BOLD%^%^BLACK%^, you dart forward, turn and lay a devastating blow upon "+who->QCN+"'s body!%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s eyes glow with a fathomless %^RESET%^%^MAGENTA%^purple aura %^BOLD%^%^BLACK%^as they move between your defenses and land a telling blow.%^RESET%^");
		who->cause_typed_damage(who, "torso", roll_dice(12, 2), "untyped");
return damage;	}
}