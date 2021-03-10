#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloak of feathers");
	set_id(({ "cloak", "cloak of feathers", "feather cloak" }));
	set_short("%^BOLD%^%^BLUE%^Cloak of Fe%^RESET%^%^CYAN%^a"+
	"%^BOLD%^%^GREEN%^th%^RESET%^%^CYAN%^e%^BLUE%^rs%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A feathered cloak%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^This long sweeping cloak is crafted"+
	" from hundreds of peacock feathers.  The elegant"+
	" cloak is backed with matching blue silk, giving some strength"+
	" to such a fragile thing as feathers.  The peacock"+
	" feather shift in colors as the irisdescent hues of "+
	"%^RESET%^%^BLUE%^blue%^BOLD%^ and %^GREEN%^green%^BLUE%^.  Most"+
	" of the feathers used for this cloak are the smaller plumes"+
	" from a peacock though a few of the longer more famous"+
	" plumes have been worked into the lavish cloak.  The "+
	"%^YELLOW%^golden%^BLUE%^ eyes of the peacock resting on a field "+
	"of irisdescent %^BLACK%^black%^BLUE%^.  A simple silken"+
	" cord allows the cloak to be tied about one's neck.%^RESET%^\n");
	set_weight(5);
	set_value(1400);
	set_lore("The Thief of Tharis is one of the most popular plays,"+
	" due to it's complex range of emotions that"+
	" are covered within the performance.  Our protagonist, the "+
	"human rogue Kiram, falls in love with an elven woman"+
	" from the ghettos of Tharis, Nev'esha.  Seeking to show"+
	" his affection to the elven woman Kiram steals a noble"+
	" woman's elegant cloak made from peacock feathers.  "+
	"The cloak proves to be part of the undoing for Kiram and "+
	"the happiness he wants in his life. - The Play and Life"+
	" of Prenicus - Ovelia Fewenspare.");
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(TP->query_size());
	set_property("enchantment",3);
	set_item_bonus("charisma",1);
	set_ac(0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" tosses"+
	" on a cloak made of peacock feathers, making "+ETO->QO+""+
	" look very stylish!",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You toss on the cloak of "+
	"feathers and feel rather lavish and stylish.");
		return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^As "+ETOQCN+" "+
	"pulls off "+ETO->QP+" cloak, for a moment you "+
	"almost wish "+ETO->QS+" would put it back on.  The peacock "+
	"feathers looked so lovely.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You slip the cloak off"+
	" an take care to fold it carefully, you would "+
	"hate to damage the feathers after all.");
		return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 50){
	tell_room(environment(query_worn()),"%^BOLD%^%^GREEN%^For"+
	" a moment "+who->QCN+" looks bedazzled"+
	" by "+ETOQCN+"'s cloak, looking lost in the beauty of the"+
	" %^BLUE%^peacock%^GREEN%^ feathers.",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^A soft %^BLUE%^glow%^GREEN%^"+
	" begins to shed from the cloak, seeming"+
	" to dazzle "+who->QCN+" with the magnificent beauty of"+
	" the cloak!");
	tell_object(who,"%^BOLD%^%^GREEN%^Staring at "+ETOQCN+"'s"+
	" cloak the beauty of the %^BOLD%^%^BLUE%^"+
	"peacock%^GREEN%^ feathers just captivates you.  "+
	"What a lovely cloak!");
		return (damage*100)/100;}
}