#include <std.h>
inherit ARMOUR;

#define MAXUSES 50

int uses;

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring", "weather ring" }));
	set_short("%^CYAN%^Ring of Rain%^RESET%^");
	set_obvious_short("an electrum ring");
	set_long(
@AVATAR
%^CYAN%^This ring is made of a thick band of electrum. The metal is dull and tarnished with many years of grim. Around the band of the ring are images of clouds, cut into the metal, with a large central cloud in the center of the ring. It seems there is something written in each of the clouds.

AVATAR
	);
	set("read",
@AVATAR
Speak the phrase, Eldavar, to enact the power of the ring.

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(30);
	set_lore(
@AVATAR
The Ring of Rain was first made by the half-elven wizard, Jardest, who hated the fact his robes would constantly get soaked on adventures. The ring is said to shield one from rain, snow, sleet, and hail of natural origins. There is no rumor if it protects from temperature changes.

AVATAR
	);
	set_property("lore",9);
	set_type("ring");
	set_limbs(({ "right hand","left hand" }));
	set_size(2);
	set_property("enchantment",0);
}


void init() {
   ::init();
   add_action("weather","eldavar");
}

int weather() {
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paraylyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) return notify_fail("You have to wear the ring first.");
   if(uses < MAXUSES) {
      tell_object(TP, "%^RESET%^%^CYAN%^You speak a word and feel protected from all forms of precipitation.");
      tell_room(ETP, "%^RESET%^%^CYAN%^"+TPQCN+" speaks a word and a blue dome surrounds "+TPQCN+", then fades.",TP);
      uses +=1;
      return 1;
      }
   else{
      set_value(0);
      tell_object(TP, "The ring is out of charges.");
   }
   return 1;
}
