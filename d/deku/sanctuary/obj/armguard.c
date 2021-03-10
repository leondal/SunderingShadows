//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit "/d/common/obj/armour/buckler";

#define COLORS ({"%^BOLD%^%^BLACK%^ebony black",\
"%^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r",\
"%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d",\
"%^BOLD%^%^WHITE%^iv%^YELLOW%^o%^WHITE%^ry white%^RESET%^",\
"%^BOLD%^%^BLUE%^s%^CYAN%^a%^RESET%^%^CYAN%^p%^BLUE%^p%^BOLD%^h%^CYAN%^i%^RESET%^%^CYAN%^r%^BLUE%^e %^BOLD%^b%^CYAN%^l%^RESET%^%^CYAN%^u%^BLUE%^e",\
"%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^m%^BOLD%^e%^RESET%^%^GREEN%^r%^BOLD%^a%^RESET%^%^GREEN%^l%^BOLD%^d %^RESET%^%^GREEN%^g%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^e%^RESET%^%^GREEN%^n",\
"%^BOLD%^%^BLACK%^b%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^y%^BOLD%^%^BLACK%^l%^RESET%^ g%^BOLD%^%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^y",\
"%^BOLD%^%^GREEN%^p%^YELLOW%^e%^GREEN%^r%^YELLOW%^i%^GREEN%^d%^YELLOW%^o%^GREEN%^t green",\
"%^BOLD%^%^MAGENTA%^rose quartz pink",\
"%^RESET%^%^MAGENTA%^a%^BOLD%^m%^RESET%^%^MAGENTA%^e%^BOLD%^t%^RESET%^%^MAGENTA%^h%^BOLD%^y%^RESET%^%^MAGENTA%^s%^BOLD%^t%^RESET%^%^MAGENTA%^ purple",\
"%^YELLOW%^citrine yellow%^RESET%^",\
"%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^u%^BOLD%^r%^RESET%^%^CYAN%^q%^BOLD%^u%^RESET%^%^CYAN%^o%^BOLD%^i%^RESET%^%^CYAN%^s%^BOLD%^e %^RESET%^%^CYAN%^blue",\
"%^RESET%^%^ORANGE%^to%^BOLD%^p%^RESET%^%^ORANGE%^az orange"})


void create(){
	int j;
	string str, X, COLOR;
	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
	if(COLOR == "%^BOLD%^%^BLACK%^ebony black" || COLOR == "%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^m%^BOLD%^e%^RESET%^%^GREEN%^r%^BOLD%^a%^RESET%^%^GREEN%^l%^BOLD%^d %^RESET%^%^GREEN%^g%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^e%^RESET%^%^GREEN%^n" || COLOR == "%^BOLD%^%^WHITE%^iv%^YELLOW%^o%^WHITE%^ry white%^RESET%^" || COLOR == "%^RESET%^%^MAGENTA%^a%^BOLD%^m%^RESET%^%^MAGENTA%^e%^BOLD%^t%^RESET%^%^MAGENTA%^h%^BOLD%^y%^RESET%^%^MAGENTA%^s%^BOLD%^t%^RESET%^%^MAGENTA%^ purple") {
		X = "An";
	}
	else {
		X = "A";
	}
	set_name("armguard");
   	set_id(({"armguard","silken armguard","shield"}));
   	set_short("%^BOLD%^%^WHITE%^Armguard of the %^RED%^B%^RESET%^"+
		"%^ORANGE%^e%^YELLOW%^j%^GREEN%^e%^CYAN%^w%^BLUE%^e%^BOLD%^"+
		"%^MAGENTA%^l%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^d%^BOLD%^"+
		"%^WHITE%^ Swashbuckler%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^"+X+" "+COLOR+" %^RESET%^%^BOLD%^silk"+
		" armguard%^RESET%^");
   set_long(
      "%^BOLD%^%^WHITE%^This armguard that fits securely over the forearm. There are two"+
      " %^RESET%^%^ORANGE%^leather %^BOLD%^%^WHITE%^straps to wrap around the"+
	" unprotected bottom half of the arm, each one studded with "+COLOR+" "+
	"%^BOLD%^%^WHITE%^gems.  A hardened%^RESET%^ %^ORANGE%^leather "+
	"%^BOLD%^%^WHITE%^shell is made to fit snug against the forearm.  "+
	"Wrapped with "+COLOR+" %^BOLD%^%^WHITE%^silk, the armguard has a "+
	"stylish if not flamboyant touch.  The "+COLOR+" %^BOLD%^%^WHITE%^silk "+
	"has been magically treated to repel dirt and stains, and never seems "+
	"to rip or tear!%^RESET%^\n ");
   set_lore(
      "This armguard is fancied by many duelists for its ability to protect"+
      " and the freedom of movement it allows in battle beyond the average shield."+
      " The first one in existance was seen by Cassius, a renown rapier specialist"+
      " who is dueling champion for three years straight in the city of Torm."
   );
   //set_weight(5);
   set_value(random(500)+222);
   //set_armor_prof("light");
   //set_limbs( ({ "right hand" }) );
   //set_ac(1);
   set_property("enchantment",3+random(2));
   //set_type("thiefshield");
   //set_block_chance(15);
}
