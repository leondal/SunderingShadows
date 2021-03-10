#include <std.h>
inherit "/std/guilds/guild.c";

void create() {
   ::create();
   set_weight(5);
   set_value(0);
   set_name("cowl of knowledge");
   set_id(({"cowl of knowledge","cowl","Cowl of Knowledge"})); 
   set_short("Cowl of Knowledge");
   set_long(
@OLI
     This dark hood has been attached to the robe. It is said to be the
symbol of the great consortium. The dark brown cowl covers the entire face 
so initially any observer only sees the cowl. 

OLI
           );
   set_type("ring");
   set_limbs(({"head"}));
   set_guild_name("The Consortium");
   set_guild_object("/d/guilds/consortium/obj/cowl_knowledge.c");
}

void init() {
   ::init();
   if(!objectp(TO)) {
      message("info","The cowl rejects you.",TP);
      return;
   }
   if(!living(ETO)) return;
   if(!interactive(ETO)) return;
   ETO->force_me("wear cowl");
}

