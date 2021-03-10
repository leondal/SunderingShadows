
#include <std.h>
inherit "/std/guilds/guild.c";

void create()
{
	::create();
	set_weight(5);
	set_value(0);
	set_name("tattoo");
        set_id(({"tattoo","iron fist tattoo"})); 
	set_short("A tattoo");
	set_long(
	"%^BLUE%^This is a small, black, tattoo on the inside of the left bicep, it reads"+
  "\n\n%^CYAN%^'Quo Bello Et Gloria Ducunt'%^RESET%^\n\n");
	set_type("ring");
	set_limbs(({"left arm"}));
	set_guild_name("Iron Fist");
    set_guild_object("/d/guilds/fist/obj/tattoo.c");
	//set_wear((:TO,"wearme":));
}

void init()
{
	::init();
     if(!objectp(TO)) {message("info","The bracelet rejects you.",TP);
     return;}
	if(!living(ETO)) return;
	if(!interactive(ETO)) return;
set_hidden(1);    
ETO->force_me("wear tattoo");
}

