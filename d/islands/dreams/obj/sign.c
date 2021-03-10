#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("sign");
      set_id(({ "sign", "driftwood sign","wood sign"}));
      set_short("%^RESET%^%^WHITE%^A driftwood sign%^RESET%^");
      set_long("Made from what looks to be salvaged pieces"+
		" of wood from ships, a sign has been staked into"+
		" the sand.  The weathered sign has a gray hue to "+
		"it, from the salty air and humidity.  Painted on "+
		"the sign in %^GREEN%^m%^YELLOW%^i%^RED%^s%^BLUE%^"+
		"m%^BOLD%^%^CYAN%^a%^RESET%^%^ORANGE%^t%^BOLD%^"+
		"%^GREEN%^c%^BLUE%^h%^RED%^e%^WHITE%^d%^RESET%^ "+
		"colors appears to be a message.  Perhaps you "+
		"could read it?\n");
	set_read("\n\n%^BOLD%^%^RED%^The island of Ovadexel is cursed!\n"+
		"%^BLUE%^Turn back now if you can.\n "+
		"%^GREEN%^To stay here is your death.\n"+
		"%^YELLOW%^Do not be foolish.\n"+
		"\n\n%^BOLD%^%^MAGENTA%^OOC This area is meant for"+
		" parties from 30-35.  Anyone lower than that,"+
		" adventure at your own risk.%^RESET%^");
	set_language("common");

      set_weight(10000);
      set_value(0);
}

