#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("black sapphire");
	set_id(({ "sapphire" }));
	set_short("%^BOLD%^%^BLACK%^bla%^RESET%^%^BLUE%^ck sapp%^BOLD%^%^BLACK%^hire%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This small blackish-blue gem has a dull luster to it.  If you look closely you notice it is flawless without one trace of a mark or scratch.
AVATAR
	);
        set_weight(5);
        set_property("no animate", 1);
	set_lore(
@AVATAR
The Black Sapphire is Shar's answer to Selune's Scimitar of the Silvery Moon.  Shar has found a way to corrupt the blade of light into an effective tool of her twisted desires.
AVATAR
	);
  set_value(random(2000)+1000);
}

int drop(){
   if(!interactive(ETO)){
     ::drop();
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^BLACK%^The black gem flashes in your hand before fading into nothingness!");
   tell_room(ETP,"%^BOLD%^%^BLACK%^The black gem flashes and fades into nothingness from the hands of "+TP->query_cap_name()+"!",TP);
   remove();
   return 1;
}
