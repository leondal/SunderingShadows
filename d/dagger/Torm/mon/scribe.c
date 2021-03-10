// scribe for Gwen/Girruuth's shop 

#include <std.h>
#include <langs.h>

inherit SCRIBE;

int end_game(string str, object ob, string lang);

void create() {
    ::create();
    set_name("Tarsea");
    set_id(({"scribe", "vendor", "tarsea", "Tarsea"}));
    set_race("human");
    set_gender("female");
    set_short("Tarsea, local scribe");
    set("long", "This pale, scrawny woman sits behind her small desk.  She is dressed in a faded plain cotton dress.  Her %^ORANGE%^mousy brown hair %^CYAN%^is up in a bun and her thin lips are pursed in a hard line as she squints at you from behind her gold rimmed spectacles.  Her pen is poised and ready to <write> any message you request in the language you specify, for a price of course.");
    set_level(1);
    set_body_type("human");
    set_class("mage");
    set("aggressive", 0);
    set_alignment(2);
    set_size(2);
    set_stats("intelligence",18);
    set_stats("wisdom",9);
    set_stats("strength",13);
    set_stats("charisma",6);
    set_stats("dexterity",14);
    set_stats("constitution",7);
    set_hd(1, 1);
    set_exp(10);
    set_max_hp(query_hp());
    add_money("silver",random(10));
    add_money("gold",random(5));
    add_money("copper",random(20));
}

void init() {
   ::init();
   if(!interactive(TP))  return;
   if(!random(4)) {
      if(!random(5))
	force_me("emote glances up briefly and nods in greeting.");
      return;
   }
   if(!random(3)) {
      if((string)TP->query_name() == "girruuth") {
	switch(random(3)) {
	   case 0:
		force_me("emote glances up briefly and then quickly back down to her work.");
		break;
	   case 1:
		force_me("emote adjusts her spectacles as she busies herself straightening some papers.");
		break;
	   case 2:
		force_me("emote tucks a wisp of hair back into the bun with the rest.");
		break;
	}
        return;
      } 
      if((string)TP->query_name() == "gwenhwyfar") {
	switch(random(3)) {
	   case 0:
		force_me("nod gwenhwyfar and seems to almost manage a smile.");
		break;
	   case 1:
		force_me("say Greetings mi'lady.");
		break;
	   case 2:
		force_me("emote sits up a little straighter as she glances up before turning back to her work.");
		break;
	}
      }
   }
}
