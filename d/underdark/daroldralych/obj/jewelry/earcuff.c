#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("spider earcuff");
   set_id(({"spider earcuff","earcuff","golden earcuff","golden spider earcuff","cuff"}));
   set_short("%^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en %^RED%^sp%^BOLD%^%^RED%^id%^RESET%^%^RED%^er %^ORANGE%^earcuff%^RESET%^");
   set_long("The entire piece of %^ORANGE%^go%^YELLOW%^l%^RESET%^"
"%^ORANGE%^d %^RESET%^that forms this jewelry has been shaped into a "
"creeping spider.  Designed to fit around the upper ear, the creature's "
"%^BOLD%^%^BLACK%^s%^RESET%^pi%^BOLD%^%^BLACK%^n%^WHITE%^d%^BLACK%^ly "
"%^RESET%^legs are set just right to fit in a comfortable grip, with the "
"piece light enough not to drag or be painful to wear.  A small chip of "
"%^RED%^bri%^BOLD%^l%^RESET%^%^RED%^lia%^BOLD%^n%^RESET%^%^RED%^t "
"ru%^BOLD%^b%^RESET%^%^RED%^y %^RESET%^shapes an hourglass figure on the "
"abdomen of the arachnid, adding a hint of %^CYAN%^ex%^BOLD%^p%^RESET%^"
"%^CYAN%^en%^GREEN%^s%^CYAN%^e %^RESET%^to the already elegant "
"jewelry.\n");
   set_limbs(({ "head" }));
   set_weight(0);
   set_value(780);
   set_ac(0);
   set_type("ring");
}
