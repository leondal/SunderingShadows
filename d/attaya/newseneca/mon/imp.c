//imp.c - the familiar for Octavia in new Seneca's mage tower
//adapted from /d/newbie/mon/arvanador.c
//~Circe~ 1/7/08

#include <std.h>

inherit NPC;

void create(){
   ::create();
   set_name("abayal");
   set_short("Abayal, a mischievous imp");
   set_id(({"abayal","Abayal","imp","mischievous imp"}));
   set_long("This tiny winged creature has an exceptionally "+
      "long nose with hair bristling all around its garish "+
      "grin.  Its eyes are mischievous - almost playful - "+
      "while the sharp teeth give it a menacing appearance.  "+
      "The leathery wings sprouting from its back seem much "+
      "more useful than its spindly legs, though the prehensile "+
      "tail and sharp claws look vicious.");
   set_race("imp");
   set_body_type("demon");
   set_class("fighter");
   set_mlevel("fighter",35);
   set_guild_level("fighter",35);
   set_hd(35,6);
   set_max_hp(query_hp());
   set_exp(100);
   set_need_addressed(0);
}

void reset(){
   ::reset();
   if(!random(20)){
      tell_room(ETO,"%^BOLD%^%^RED%^With a mischievous grin, "+
         "Abayal vanishes, and you hear a wild cackle.%^RESET%^");
      tell_room(ETO,"%^MAGENTA%^Abayal screeches%^RESET%^: "+
         "Here I come, Godfrey!!");
      TO->remove();
   }
}