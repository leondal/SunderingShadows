//Just spiffed up the jewelry a bit - Cythera 5/05\\
#include <std.h>
inherit ARMOUR;

#define COLORS ({"%^BOLD%^%^CYAN%^steel",\
"%^BOLD%^%^WHITE%^platinum",\
"%^YELLOW%^yellow gold", \
"%^BOLD%^%^WHITE%^m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l",\
"%^BOLD%^%^RED%^fever iron",\
"%^ORANGE%^copper",\
"%^BOLD%^%^BLUE%^electrum",\
"%^YELLOW%^bronze",\
"%^BOLD%^%^CYAN%^adamantium",\
"%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r",\
"%^BOLD%^%^WHITE%^white gold",\
"%^BOLD%^%^MAGENTA%^rose gold",\
"%^BOLD%^%^WHITE%^titanium",\
"%^MAGENTA%^darksteel",\
"%^BOLD%^%^WHITE%^a%^GREEN%^r%^WHITE%^and%^BLUE%^u%^WHITE%^r",\
"%^BOLD%^%^WHITE%^dl%^GREEN%^a%^WHITE%^r%^GREEN%^a%^WHITE%^n"})

void create(){
     	int j;
	string str, COLOR;
	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
   set_name("anklets");
   set_short("%^RESET%^%^CYAN%^A pair of "+COLOR+" %^RESET%^%^CYAN%^anklets%^RESET%^");
   set_id(({"anklets","anklets","pair of anklets","dagger_jewelry"}));
   set_long("%^CYAN%^This is a pair of anklets that are made of "+COLOR+""+
	" %^RESET%^%^CYAN%^chain links"+
   	" with a simple clasp that is easy to fasten but won't open on its own."+
   	" Dainty "+COLOR+" %^RESET%^%^CYAN%^bells hang from the anklets and "+
	"they jingle whenever"+
   	" the wearer walks.%^RESET%^");
   set_weight(2);
   set_type("ring");
   set_limbs(({"right leg","left leg"}));
   set_value(200);
   set_wear("The dainty bells jingle as you put on the anklets.");
   set_remove("You remove the anklets with their tiny bells.");
}
