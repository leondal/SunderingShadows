#include <std.h>
inherit "/std/armour";
#define COLORS ({"%^BOLD%^%^BLACK%^jet black",\
"%^BOLD%^%^WHITE%^brilliant white",\
"%^BOLD%^%^RED%^crimson red",\
"%^RESET%^%^RED%^scarlet red",\
"%^RESET%^%^ORANGE%^bright orange",\
"%^RESET%^%^ORANGE%^earth brown",\
"%^YELLOW%^sunshine yellow",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^RESET%^%^GREEN%^forest green",\
"%^BOLD%^%^BLUE%^sapphire blue",\
"%^BOLD%^%^BLUE%^royal blue",\
"%^RESET%^%^BLUE%^midnight blue",\
"%^RESET%^%^CYAN%^ocean blue",\
"%^BOLD%^%^CYAN%^azure blue",\
"%^RESET%^%^MAGENTA%^deep purple",\
"%^MAGENTA%^plum",\
"%^BOLD%^%^MAGENTA%^bright pink",\
"%^BOLD%^%^BLACK%^stormy gray",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r",\
"%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d",\
"%^BOLD%^%^RED%^ruby red",\
"%^BOLD%^%^WHITE%^light cream",\
"%^BOLD%^%^BLACK%^raven black",\
"%^MAGENTA%^wine",\
"%^BOLD%^%^MAGENTA%^rose pink",\
"%^CYAN%^sea green"})


void create(){
string COLOR;
int j;
	tell_player(find_player("styx"), "Int j is "+j+" at the very beginning of create before the super.\n");
     	::create();
	j = random(sizeof(COLORS));
	tell_player(find_player("styx"), "Int j is "+j+" after j = random....\n");
      COLOR = COLORS[j];
   set_name("cloak of silk");
   set_id( ({"cloak","silk cloak","cloak of silk"}) );
   set_short("%^RESET%^"+COLOR+" silk cloak%^RESET%^");
   set_long("This shimmering "+COLOR+" %^RESET%^cloak is made of the"+
		" best quality silk.  The cloak is double lined with"+
		" "+COLOR+" %^RESET%^silk, giving added body to its shape."+
		"  The edges of the cloak are trimmed with %^BOLD%^e%^YELLOW%^"+
		"l%^WHITE%^e%^YELLOW%^c%^WHITE%^t%^YELLOW%^r%^WHITE%^u%^YELLOW%^m"+
		"%^RESET%^ threads, creating an elegant curling patten.  A "+
		"perfect clasp of %^BOLD%^platinum%^RESET%^ is attached to the"+
		" throat.  The large circular clap is left naked in "+
		"the center, allowing for a personalized clasp to be added.  "+
		"A high pointed collar rises up around the neck of the wearer,"+
		" showcasing the platinum clasp. This cloak looks particularly "+
		"expensive and of particularly good crafting, the kind of garment"+
		" the upper-class would probably wear.\n");
   set_weight(2);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_ac(0);
   set_property("enchantment",2);
   set_value(500+random(3)*500);
   set_wear((: TO,"wear_func" :));
   set_remove((: TO,"remove_func" :));
   set_lore("Crafted by elven slaves, these silk cloaks were used by the"+
		" Dark Sisters and their apprentices in necromancy.  The "+
		"sisters always kept on at least five elven slaves as "+
		"seamstresses and tailors.  The elves, I was told by an "+
		"high elf sage, secretly stitched into the cloak "+
		"sigils and signs that allowed the elves of Synoria"+
		" to track down their missing brothers and sisters.  "+
		"In the end it was the elven slaves that were able "+
		"to expose the sinister deeds of the Dark Sisters with"+
		" their craft.  The cloaks now days are favored by most"+
		" elves, in rememberance to the wisdom and cunning "+
		"nature of the slaves. Some say the Dark Sisters and"+
		" their apprentices wove into the cloak enchantments "+
		"to aid them in resisting magical spells. - I Feel My Freedom: "+
		"Heartwarming Tales of Slavery - Elorium Therodale");
   set_property("lore difficulty",9);
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" stylish in "+
		""+ETO->QP+" "+query_short()+".",ETO);
     	tell_object(ETO,"%^BOLD%^You feel stylish in your "+query_short()+".");
      return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" remove"+
		" "+ETO->QP+" stylish "+query_short()+".",ETO);
     	tell_object(ETO,"%^BOLD%^You remove your stylish "+query_short()+".");
     	return 1;
}