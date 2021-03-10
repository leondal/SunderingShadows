#include <std.h>
inherit "/std/guild";


void create(){
	guild::create();
set_name("HC Tatoo");

set_id(({"tatoo","hc tatoo","HC Tatoo"}));
set_short("%^MAGENTA%^Tatoo of %^RED%^flaming%^MAGENTA%^ crossed swords, over a %^WHITE%^Yin%^MAGENTA%^/%^BLUE%^Yang%^MAGENTA%^ symbol");
	set_long(
@FIST
This is a beautiful and detailed Tatoo signifying the rank of High Commander Elite in the Iron Fist.
FIST
	);
	set_weight(0);
set_value(0);
set_leader("coyotte");
set_guild_items(({"/d/shadow/guilds/fist/fist_armband"}));
set_guild_hc(({"coyotte","oog","spider"}));
set_guild_home("/d/shadow/guilds/fist/fist");
set_welcome("You are a member of The Iron Fist. Welcome, brother.");
set_guild_name("Iron Fist");
set_type("clothing");
set_limbs(({"left leg"}));
}
void init(){
	guild::init();
if(ETO==TP) TP->force_me("wear tatoo");
}
