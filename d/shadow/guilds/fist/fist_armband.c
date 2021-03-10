#include <std.h>
inherit "/std/guild";


void create(){
	guild::create();
set_name("Adamantite Armband");

set_id(({"armband","Armband","adamantite","adamantite armband"}));
set_ac(1);
set_short("%^CYAN%^Adamantite Armband%^RESET%^");
	set_long(
@FIST
This armband is made of adamantite, forged into an unbreakable circle by
the most skilled of smiths.
The phrase 'quo bello et gloria decunt' is inlaid in black onyx around it's
circumfrence.
As you look at it, you feel a potent sense of unity and power.
FIST
	);
	set_weight(2);
set_value(1);
set_leader("coyotte");
set_guild_items(({"/d/shadow/guilds/fist/fist_armband"}));
  set_guild_hc(({"coyotte","oog","piezo","spider"}));
set_guild_home("/d/shadow/guilds/fist/fist");
set_welcome("You are a member of The Iron Fist. Welcome, brother.");
set_guild_name("Iron Fist");
set_type("clothing");
set_limbs(({"left arm"}));
}
void init(){
	guild::init();
if(ETO==TP) TP->force_me("wear armband");
}
