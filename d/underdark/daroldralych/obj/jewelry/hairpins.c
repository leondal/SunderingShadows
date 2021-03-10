#include <std.h>
inherit ARMOUR;

#define COLORS ({"%^RESET%^%^RED%^rich scar%^MAGENTA%^l%^RED%^et",\
"%^RESET%^%^RED%^b%^BOLD%^l%^RESET%^%^RED%^ood red",\
"%^BOLD%^%^RED%^vivid crim%^RESET%^%^RED%^s%^BOLD%^on",\
"%^RESET%^%^BLUE%^midn%^BOLD%^%^BLACK%^i%^RESET%^%^BLUE%^ght blue",\
"%^RESET%^%^MAGENTA%^dusky vio%^BLUE%^l%^MAGENTA%^et",\
"%^RESET%^%^MAGENTA%^de%^BOLD%^e%^RESET%^%^MAGENTA%^p purple",\
"%^RESET%^%^RED%^bu%^MAGENTA%^r%^RED%^gundy",\
"%^BOLD%^%^BLACK%^jet black",\
"%^BOLD%^%^BLACK%^dark e%^RESET%^%^BLUE%^b%^BOLD%^%^BLACK%^ony",\
"%^BOLD%^%^BLACK%^dusky gr%^RESET%^a%^BOLD%^%^BLACK%^y",\
"%^BOLD%^%^BLACK%^sl%^RESET%^a%^BOLD%^%^BLACK%^te gray",\
"%^RESET%^%^GREEN%^emer%^BOLD%^a%^RESET%^%^GREEN%^ld green",\
"%^RESET%^%^GREEN%^cloudy j%^RESET%^a%^GREEN%^de"})

#define DESIGNS ({"panthers","salamanders","spiders","serpents","dragons","gloomwings","imps","ravens","chimeras","wolves","wyverns"})

#define DESIGNS2 ({"slinking","curling","creeping","coiling","soaring","fluttering","scampering","gliding","clawing","prowling","circling"})

void create(){
   string color, design, design2;
   int i;
   ::create();
   color = COLORS[random(sizeof(COLORS))];
   i = random(sizeof(DESIGNS));
   design = DESIGNS[i];
   design2 = DESIGNS2[i];
   set_name("hairpins");
   set_id(({"hairpins",""+color+" hairpins"}));
   set_short(""+color+" hairpins%^RESET%^");
   set_long("These %^CYAN%^el%^GREEN%^e%^CYAN%^gant %^RESET%^hairpins "
"would form the basis of any number of hairstyles.  Each is formed by a "
"curl of metal that doesn't quite close, with a narrow base that broadens "
"to a wider head in a smooth, straight line.  While underneath you can "
"see that they have been made from a %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^"
"%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r %^RESET%^base, upon the upper "
"side of the curl is a coating of "+color+"%^RESET%^ gloss.  Parts of the "
"gloss have been carefully cut away to reveal the bright %^BOLD%^"
"%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r "
"%^RESET%^beneath, to form a design of "+design+" "+design2+" their way "
"across the hairpins.\n");
   set_limbs(({"head"}));
   set_weight(0);
   set_type("ring");
   set_size(2);
   set_value(310);
}
