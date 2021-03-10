#include <std.h>
inherit "/std/guilds/guild.c";

void create()
{
	::create();
	set_weight(5);
	set_value(0);
	set_name("silver bracelet");
        set_id(({"regents guild bracelet","bracelet","silver bracelet","sparkling silver bracelet"})); 
	set_short("%^RESET%^Sparkling %^BOLD%^Silver%^RESET%^ Bracelet");
	set_long(
	"%^RESET%^This %^BOLD%^silver%^RESET%^ bracelet wraps twice around the"+
	" wrist of its wearer. Engraved on the band are a harp, quill, open"+
	" book, and a crystal ball. As you look at the bracelet it sparkles in"+
	" a %^RED%^r%^ORANGE%^a%^BOLD%^i%^GREEN%^n%^BLUE%^b%^CYAN%^o%^MAGENTA%^w%^RESET%^"+
	" of colors."
	);
	set_type("ring");
	set_limbs(({"right arm"}));
	set_guild_name("Regents of the Silver Lore");
    set_guild_object("/d/guilds/regents/obj/bracelet.c");
	//set_wear((:TO,"wearme":));
}

void init()
{
	::init();
     if(!objectp(TO)) {message("info","The bracelet rejects you.",TP);
     return;}
	if(!living(ETO)) return;
	if(!interactive(ETO)) return;
    ETO->force_me("wear silver bracelet");
}

