#include <std.h>
inherit ARMOUR;

#define GEMS ({"%^MAGENTA%^ameth%^BOLD%^y%^RESET%^%^MAGENTA%^st",\
"%^MAGENTA%^purp%^BLUE%^l%^MAGENTA%^e jade",\
"%^RED%^gar%^MAGENTA%^n%^RED%^et",\
"%^RED%^ru%^BOLD%^b%^RESET%^%^RED%^y",\
"%^BOLD%^%^RED%^fla%^YELLOW%^m%^RED%^edan%^WHITE%^c%^RED%^e",\
"%^BOLD%^%^BLACK%^on%^RESET%^y%^BOLD%^%^BLACK%^x",\
"%^BOLD%^%^BLACK%^black sa%^RESET%^%^BLUE%^p%^BOLD%^%^BLACK%^phire",\
"%^BOLD%^%^BLACK%^sno%^WHITE%^w%^BLACK%^flake obsi%^WHITE%^d%^BLACK%^ian",\
"%^BOLD%^%^BLACK%^smoky qua%^RESET%^r%^BOLD%^%^BLACK%^tz",\
"%^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^y chalcedony",\
"%^GREEN%^emera%^BOLD%^l%^RESET%^%^GREEN%^d",\
"%^GREEN%^ja%^RESET%^d%^GREEN%^e",\
"%^BOLD%^%^BLUE%^blue t%^CYAN%^o%^BLUE%^paz",})

void create(){
   string gem;
   ::create();
   gem = GEMS[random(sizeof(GEMS))];
   set_name("circlet");
   set_id(({"circlet","ornate circlet","silver and gold circlet","circlet of silver and gold"}));
   set_short("%^BOLD%^%^CYAN%^ornate circlet of %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r %^CYAN%^and %^RESET%^%^ORANGE%^go%^YELLOW%^l%^RESET%^%^ORANGE%^d%^RESET%^");
   set_long("Four flat curling filaments of %^BOLD%^%^WHITE%^s%^RESET%^i"
"%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r %^RESET%^form this "
"exquisite circlet, interspersed with many half-length wires of the same "
"metal.  They rise and fall in %^BOLD%^%^CYAN%^w%^BLUE%^a%^CYAN%^v%^BLUE%^e"
"%^CYAN%^s%^RESET%^, criss-crossing each other and turning in spirals, to "
"form a loose net of graceful, chaotic swirls around the crown of the "
"wearer's head.  A single line of %^ORANGE%^go%^YELLOW%^l%^RESET%^"
"%^ORANGE%^d%^RESET%^ threads its way through the %^BOLD%^%^WHITE%^s"
"%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^, "
"accentuating the lighter metal with its bold, glossy hue.  It meets at "
"the brow of the circlet, and turns downward in two spirals to finally "
"end in a teardrop outline that holds a single polished "
+gem+"%^RESET%^.\n");
   set_limbs(({"head"}));
   set_weight(0);
   set_type("ring");
   set_size(2);
   set_value(530);
}
