//fixed by Circe to show whole description 
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(30000);
	set_id(({ "klauth tattoo", "tattoo" }));
	set_short("%^BOLD%^%^BLACK%^A huge %^RED%^i%^RESET%^%^ORANGE%^n%^BOLD%^%^ORANGE%^t%^GREEN%^r%^GREEN%^i%^BLUE%^c%^MAGENTA%^a%^RESET%^%^MAGENTA%^t%^BOLD%^%^RED%^e dr%^RESET%^%^RED%^a%^BOLD%^%^RED%^g%^BLACK%^o%^RED%^n %^BLACK%^t%^CYAN%^a%^BOLD%^%^BLACK%^tt%^CYAN%^o%^RESET%^%^CYAN%^o%^RESET%^");
	set_long(
"%^BOLD%^%^BLACK%^Inked across the upper portion of this elf's chest "+
"is this fearsome tattoo of a great %^RED%^r%^RESET%^%^RED%^e%^BOLD%^"+
"%^RED%^d w%^RESET%^%^RED%^y%^BOLD%^%^RED%^rm%^BLACK%^. He coils "+
"protectively around his %^ORANGE%^g%^RESET%^%^ORANGE%^o%^BOLD%^"+
"%^ORANGE%^ld%^WHITE%^e%^ORANGE%^n %^BLACK%^hoard, his many fanged "+
"maw open in a menacing snarl. Slanted eyes the color of sm%^RED%^o"+
"%^BLACK%^ld%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r%^RED%^i%^BLACK%^ng "+
"c%^WHITE%^o%^RED%^a%^BLACK%^ls emanate pure %^GREEN%^h%^BLACK%^a"+
"%^GREEN%^tr%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^d %^BLACK%^and "+
"%^MAGENTA%^m%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^lice%^BLACK%^. "+
"Stylized s%^WHITE%^m%^RESET%^o%^BOLD%^%^WHITE%^k%^BLACK%^e streams "+
"from his broad nostrils and curls around his massive horned head. "+
"Enormous h%^WHITE%^o%^BLACK%^le-r%^RESET%^i%^BOLD%^%^BLACK%^dd"+
"%^RED%^e%^BLACK%^n w%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^bb%^WHITE%^"+
"e%^BLACK%^d wings spread out across the surface of her light blue "+
"skin, spiked and knobby at the joints. Razor sharp b%^RED%^a%^BLACK%^"+
"rbs follow the length of his curved spine. A serpentine tail with "+
"a wicked, diamond shaped tip whips out defensively and curls down "+
"between her breasts. It is apparent that whoever executed the "+
"tattoo was extremely skilled. Every detail is meticulously rendered "+
"and the %^WHITE%^s%^BLACK%^h%^RESET%^a%^BOLD%^%^WHITE%^d%^BLACK%^i"+
"%^WHITE%^n%^BLACK%^g is so lifelike the creature almost appears "+
"animated. The unusual ink has a %^RED%^p%^RESET%^%^ORANGE%^r%^BOLD%^"+
"%^ORANGE%^i%^GREEN%^s%^BLUE%^m%^MAGENTA%^a%^RESET%^%^MAGENTA%^t%^BOLD%^"+
"%^RED%^i%^RESET%^%^ORANGE%^c %^BOLD%^%^BLACK%^quality, shimmering in "+
"the light and transitioning from a %^RED%^d%^RESET%^%^RED%^ee%^BOLD%^"+
"%^RED%^p %^RESET%^%^RED%^cr%^BOLD%^%^RED%^i%^RESET%^%^RED%^ms%^BOLD%^"+
"%^RED%^o%^RESET%^%^RED%^n %^BOLD%^%^BLACK%^to a pale %^CYAN%^a%^RESET%^"+
"%^CYAN%^z%^BOLD%^%^WHITE%^u%^CYAN%^re%^BLACK%^ and all the colors in between.%^RESET%^"
	);
	set_limbs(({"torso"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "huge"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

