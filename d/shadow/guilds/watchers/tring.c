//onyx_ring.c

#include <std.h>
inherit "/std/guild";


void create(){
	guild::create();
	set_name("Onyx Ring");
	set_id(({"ring","Ring","onyx","Onyx","onyx ring"}));
	set_short("Onyx Ring");
	set_long(
@PACK
	This ring is made of Onyx and it is taken from the depths of this realm. 
It is black and so it reflects what is in the heart of it's wearer. It 
radiates with a power that bonds all of those who have the same item 
into a strong and homogenous family.
PACK
	);
	set_weight(2);
	set_value(1);
        set_ac(1);
// set_leader("anna");
//   set_leader("knowla");
//  set_leader("soth");
  set_leader("beowulf");
	set_guild_items(({"/d/shadow/guilds/pack/pack_ring"}));
     set_guild_hc(({"beowulf","soth"}));
	set_guild_home("/d/shadow/guilds/pack/pack");
	set_welcome("Welcome to the Pack oh dark at heart!!");
	set_guild_name("Shades of Death");
	set_type("ring");
	set_limbs(({"right hand"}));
   set_wear((:TO,"wear_me":));
   set_remove((:TO,"remove_me":));
}
void init(){
	guild::init();
	if(ETO==TP) TP->force_me("wear onyx ring");
}
int wear_me(){
  if(TP->query_property("guildwear")){
    write("You are already wearing a guild object.\n");
    return 0;
  }
  else{
    TP->set_property("guildwear",1);
    return 1;
  }
}

int remove_me(){
  TP->remove_property("guildwear");
  return 1;
}
