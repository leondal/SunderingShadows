//Coded by Bane//
//This is, I think, an exact copy of the other antipaladin - with the exception of this one
//having a check that initiates communication with a paladin in regards to the sacrifice 
//action that was once in the room this anti is loaded into ("/d/deku/fortress/chapel2") - 
//I'll load two of the others into that room for now. Saide
#include <std.h>
inherit MONSTER;
int speaking;
object ob;
void create(){
    ::create();
    set_id(({"antipaladin","human","anti"}));
    set_name("antipaladin");
    set_short("An evil Antipaladin");
    set_long(
	"Before you stands a knight of darkness.  Tall and fearsome "+
	"he strides around in black fullplate armor and a black "+
	"cloak.  A massive sword is at his side stained in blood."
    );
  set_race("human");
  set_gender("male");
  set_size(2);
  set_alignment(9);
  set_overall_ac(4);
  set_stats("strength",19);
  set_stats("dexterity",19);
  set("aggressive",1);
  set_class("antipaladin");
  set_guild_level("antipaladin",11);
		set_mlevel("antipaladin",11);
  set_hp(100 + random(21));
		set_exp(query_max_hp() * 15);
  set_property("swarm",1);
  add_money("gold",random(200)+250);

  new("/d/common/obj/weapon/two_hand_sword")->move(TO);
  command("wield sword");
  ob = new("/d/shadow/room/city/cguild/antipaladin/antiplate");
  ob->move(TO);
  ob->set_property("monsterweapon",1);
  command("wear plate");
}
void init(){
    ::init();
    call_out("check",3);
}
void check(){
    if(!TP->is_class("paladin")) return 1;
    if(speaking == 1) return 1;
    force_me("say Welcome Paladin.");
    force_me("grin");
    call_out("check2",7);
    speaking = 1;
}
void check2(){
    if(!present(TP)) return 1;
    if((string *)TO->query_attackers() != ({})) return 1;
    force_me("say Doer of good, I feel a shift of dark energy inside of you.");
    force_me("say Join us in our quest for everlasting evil...");
    call_out("check3",6);
}
void check3(){
    if(!present(TP)) return 1;
    if((string *)TO->query_attackers() != ({})) return 1;
   force_me("say Help me <sacrifice> the lamb on this altar and join our cause!");
    force_me("cackle");
    speaking = 0;
}
