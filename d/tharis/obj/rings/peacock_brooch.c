//coded by Circe 9/14/04 - designed by Eiryasha
#include <std.h>
inherit ARMOUR;

void create()
{
	::create();
	set_name("%^BOLD%^%^BLUE%^P%^WHITE%^e%^YELLOW%^a%^GREEN%^c%^CYAN%^o"+
         "%^MAGENTA%^c%^RED%^k %^BLUE%^Brooch%^RESET%^");
	set_short("a bejeweled %^BOLD%^%^BLUE%^p%^WHITE%^e%^YELLOW%^a"+
         "%^GREEN%^c%^CYAN%^o%^MAGENTA%^c%^RED%^k %^BLUE%^brooch%^RESET%^");
	set_id(({"brooch","peacock brooch","bird brooch","pin"}));
	set_long(
         "%^BOLD%^A lacquered wood pin shaped to resemble a peacock.  "+
         "Each gaily colored tail plume is a different sliver of "+
         "precious gem.  The pin upon the back is easily adjustable "+
         "to place onto a collar or to clasp the front of a cloak.%^RESET%^"
	);
	set_weight(1);
	set_value(750);
	set_type("ring");
	set_limbs(({"neck"}));
}
