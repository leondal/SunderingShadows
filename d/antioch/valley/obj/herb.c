#include <std.h>
#include "../valley.h"
inherit OBJECT;

void create()
{
   ::create();
   set_name("herb");
   set_id(({"herb","druid herb","herbs","druid herbs","green herbs","green
herb"}));
   set_short("%^GREEN%^A bundle of herbs%^RESET%^");
   set_long(
	"%^GREEN%^These herbs are wrapped together by a piece of string. It"+
	" looks like there are several different varieties judging by"+
	" the types of leaves. They could be helpful, but you never"+
	" know, they might also be poisonous to you.  You must ingest them."
	);
   set_weight(3);
   set_value(50);
}

void init()
{
   ::init();
   add_action("eat","eat");
}

int eat(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
   if(str != "herbs" && str != "herb") {
      notify_fail("Are you sure you really want to put that in your mouth?\n");
      return 0;
   }
   else {
      tell_object(ETO,"%^BOLD%^%^GREEN%^You eat the herbs.");
      tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->query_cap_name()+" eats some
herbs.",ETO);
      ETO->add_poisoning(-30);
      tell_object(ETO,"%^BOLD%^%^GREEN%^You feel a little bit better.");
      TO->remove();
      return 1;
   }
}
