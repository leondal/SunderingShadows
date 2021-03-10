#include <std.h>
inherit "/std/guilds/guild.c";

string NAMEP;
int FLAG;

void create()
{
	::create();
	set_name("pendant");
	set_id(({"pendant","wooden pendant","engraved pendant","kindred pendant","special pendant"}));
	set_short("A special pendant");
	if(!FLAG) {
		set_long(
		"This pendant hangs from a strand of woven %^GREEN%^green silk%^RESET%^"+
		" that is worn around the neck, it can be easily tucked beneath your"+
		" shirt and kept close to your heart. The pendant itself is a round"+
		" circle that has been cut from an old branch of a mystical tree. "
		);
	}
	else {
		set_long(
		"This pendant hangs from a strand of woven %^GREEN%^green silk%^RESET%^"+
		" that is worn around the neck, it can be easily tucked beneath your"+
		" shirt and kept close to your heart. The pendant itself is a round"+
		" circle that has been cut from an old branch of a mystical tree."+
		" Carefully engraved onto its surface is the symbol of "+NAMEP+". "
		);
	}
	set_type("ring");
	set_limbs(({"neck"}));
	set_guild_name("The Kindred");
	set_guild_object("/d/guilds/kindred/obj/pendant.c");
	set_value(0);
	set_weight(5);
}

void init()
{
	::init();
	if(!objectp(TO)) {
		message("info","You may not wear this.",TP);
		return;
	}
    if(!objectp(ETO)) return;
	if(!living(ETO)) return;
	if(!interactive(ETO)) return;
	ETO->force_me("wear special pendant");
	set_hidden(1);

    if(objectp(query_worn()))
      if(stringp(query_worn()->query_diety()))
        NAMEP = capitalize(query_worn()->query_diety());

	if(!NAMEP) {
		FLAG = 0;
	}
	else {
		FLAG = 1;
	}
	if(!FLAG) {
		TO->set_long(
		"This pendant hangs from a strand of woven %^GREEN%^green silk%^RESET%^"+
		" that is worn around the neck, it can be easily tucked beneath your"+
		" shirt and kept close to your heart. The pendant itself is a round"+
		" circle that has been cut from an old branch of a mystical tree. "
		);
	}
	else {
		TO->set_long(
		"This pendant hangs from a strand of woven %^GREEN%^green silk%^RESET%^"+
		" that is worn around the neck, it can be easily tucked beneath your"+
		" shirt and kept close to your heart. The pendant itself is a round"+
		" circle that has been cut from an old branch of a mystical tree."+
		" Carefully engraved onto its surface is the symbol of "+NAMEP+". "
		);
	}
}

int is_detectable()
{
	return !query_worn();
}
