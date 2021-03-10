#include <std.h>

inherit MONSTER;

void create(){
   ::create();
   set_name("Delia");
   set_short("Delia, a gemcutter");
   set_id(({"cutter","gemcutter","delia","Delia"}));
   set_long("Appearing to be no more than twenty years of "+
      "age, Delia is a young psion who has a peculiar talent "+
      "for working with gems.  Her long, %^BOLD%^%^BLACK%^sable "+
      "hair %^RESET%^%^CYAN%^is gathered into a transparent net of "+
      "%^MAGENTA%^c%^BOLD%^r%^RED%^y%^YELLOW%^s%^GREEN%^t%^CYAN%^a"+
      "%^WHITE%^l%^BLUE%^s%^RESET%^%^CYAN%^ that glitter as she moves.  "+
      "She can typically be seen in the foyer of the enclave in "+
      "Seneca, where she finds many psions seek her out for the "+
      "special crystals she creates.  Though she carries "+
      "nothing else, it is well known that a psion might "+
      "ask her to <shape> a gem to be attuned to the "+
      "psion's image.");
   set_race("human");
   set_gender("female");
   set_class("psion");
   set_mlevel("psion",14);
   set_guild_level("psion",14);
   set_hd(14,8);
   set_spells(({"mind thrust","mind thrust","mind thrust","swarm of crystals","breath of the black dragon"}));
   set_spell_chance(60);
   set_exp(1);
   force_me("speech purr with a slight accent");
}

void init(){
   ::init();
   add_action("shape_em","shape");
}

int shape_em(){
   object ob;
   command("emoteat "+TPQN+" glances up at $N for a moment.");
   command("say You wish a gem that resonates with your spirit, hmm?");
   command("emoteat "+TPQN+" draws forth a gem from a pouch and "+
      "studies $N through it.");
   if(!TP->is_class("psion") && !avatarp(TP)){
      command("say I will not do it.  Your mind does not hold the "+
         "capacity to use such a thing, and my time is precious.");
      return 1;
   }
   if(!TP->query_funds("gold",2000))  {
      command("say You lack the funds to pay me, dear one.  For "+
         "you, it will cost two thousand gold coins.");
      command("emote slips the gem back into a pouch.");
      return 1;
   }
   TP->use_funds("gold",2000);
   command("emote allows the crystal to hover in the air before "+
      "her as she summons power.");
   tell_room(ETO,"The crystal flashes with a brilliant "+
      "light before the carver plucks it from the air.");
   ob = new("/d/magic/obj/exigency_gem");
   ob->set_weight(0);
   ob->move(TP);
   ob->move(TO);
   ob->set_weight(10);
   command("give exigency gem to "+TPQN+"");
   return 1;

}