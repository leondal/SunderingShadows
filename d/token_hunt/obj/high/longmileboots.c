#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("heavy boots");
	set_id(({ "boots", "boots of the long mile", "heavy boots" }));
	set_short("%^BOLD%^%^BLACK%^B%^RESET%^%^ORANGE%^o%^RESET%^o%^BOLD%^%^BLACK%^ts of the %^RESET%^%^ORANGE%^Long Mile%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A set of heavy %^RESET%^%^ORANGE%^leather %^BOLD%^%^BLACK%^boots%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This pair of heavy leather boots is formed out of thick cowhide dyed a deep shade of %^RESET%^%^ORANGE%^russet "
"brown%^BOLD%^%^BLACK%^.  Over the top of this leather, squares of %^RESET%^metal %^BOLD%^%^BLACK%^have been sewn, providing a bit of extra "
"protection for the foot and ankle, though the addition makes them that much heavier then leather alone.  The thick soles are softened by a "
"lining of soft %^RESET%^rabbit fur%^BOLD%^%^BLACK%^, and supported by two strips of metal studded with small %^RESET%^%^ORANGE%^spikes "
"%^BOLD%^%^BLACK%^that allow them to get a firm, solid grip on the ground.  The combination of which would allow one to travel easily over "
"difficult ground, without becoming as strained and tired.  Small decorations of %^RESET%^%^ORANGE%^braided fringe%^BOLD%^%^BLACK%^ and "
"%^RESET%^b%^ORANGE%^e%^RED%^a%^RESET%^d%^BOLD%^%^BLACK%^s add a little flare to these otherwise clunky boots.%^RESET%^");
	set_weight(7);
	set_value(0);
	set_lore("There are many tales about similar boots, born from the many copies that have been made over the years.  But most agree that "
"the original set was crafted by a halfling named Tesolmela Halftop, who served Shandakul in her young life and Akadi later on.  Tesolmela "
"was said to have spent her whole life caught up with the need to travel.  The need was almost curse like, it is said that she was compelled "
"to view every sight to be found in the world and that she would not be permitted to stop until she had done so.  Because of this, Tesolmela "
"created several items to aid in her journeys.  These boots gave her a more solid footing, as well as, aiding in her climbing over dangerous "
"areas where a secure grip was required.");
	set_property("lore difficulty",18);
	set_type("clothing");
	set_limbs(({ "right foot", "left foot" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("constitution",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
    set_overallStatus(220);
    set_property("no disenchant",1);
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" slips the "+query_short()+" %^BOLD%^%^WHITE%^on to their feet and appears ready to go exploring.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You wiggle your feet into the soft fur that lines the boots and feel safe and secure, ready for your travels.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" slides their feet free of the "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You slide your feet free of the soft fur that lines your boots.%^RESET%^");
	return 1;
}