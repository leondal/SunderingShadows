
#include <std.h>
inherit "/std/guild";



void create(){
    guild::create();
    set_name("A simple medallion");
    set_id(({"medallion","simple medallion"}));
    set_short("A simple medallion");
    set_long("This is a similar medallion to one found in Tharis.");
    set_weight(1);
    set_type("ring");
    set_limbs(("neck"));
    set_value(10);
    set_ac(0);
    set_guild_name("Watcher");
    set_guild_items(({base_name(TO)}));
    set_leader("zaphod");
    set_guild_hc(({"niksa","sassy","dakkon","havoc","galahad"}));
}

void init(){
    ::init();

    if(ETO == TP){
	TP->force_me("wear medallion");
	tell_object(TP,"Go forth.  Gather knowledge.  Gain wisdom for the guild.");
    }
}
