#include <std.h>
#include "../../inherit/keep.h"
inherit MONSTER;

void create() {
   object ob;
   ::create();
   set_name("xvart shaman");
   set_id(({"xvart","xvart shaman","shaman","robed xvart"}));
   set_short("%^RESET%^%^BLUE%^a robed xvart shaman%^RESET%^");
   set_long("%^BLUE%^This must be the leader of the xvarts, judging from her appearance. She looks similar to "
"others of her kind with %^BOLD%^bright blue skin %^RESET%^%^BLUE%^and %^ORANGE%^orange eyes %^BLUE%^that "
"stare all around, but she walks with an air of command unlike the rest. She is wearing a %^BOLD%^%^BLACK%^"
"dark blue robe %^RESET%^%^BLUE%^and holding a %^WHITE%^staff of bone %^BLUE%^that she shakes every now and "
"then with the dry rattling sound. She definitely appears to be far more dangerous than the rest of the "
"%^BOLD%^blue-skinned%^RESET%^%^BLUE%^ creatures.%^RESET%^");
   set_race("xvart");
   set_body_type("human");
   set_gender("female");
   set_size(1);
   set("aggressive",25);
   set_property("swarm",1);
   set_level(5);
   set_class("mage");
   set_mlevel("mage",5);
   set_guild_level("mage", 5);
   set_stats("intelligence",17);
   set_hp(75);
   set_exp(750);
   set_max_level(3);
   set_ac(7);
   set_alignment(9);
   new(OBJ2"srobe")->move(TO);
   command("wear robe");
   new(OBJ2"sstaff")->move(TO);
   command("wield staff");
   ob=new("/d/magic/scroll");
   ob->set_av_spell(2);
   ob->move(TO);
   add_money("gold",random(20)+5);
   add_money("silver",random(500)+5);
   add_money("copper",random(5000)+500);
   set_spells(({ "magic missile", "magic missile", "burning hands", "burning hands", "acid arrow" }));
   set_spell_chance(50);
   set_emotes(6,({
        "%^ORANGE%^The xvart shaman chants a few low syllables.%^RESET%^",
        "%^RED%^The xvart shaman throws something into the air, and then screams and points at you!%^RESET%^",
        "%^GREEN%^The xvart shaman waves her staff around, the bones rattling against its end.%^RESET%^"
  }),1);
}

void die(object ob) {
   tell_room(ETO,"%^YELLOW%^As the shaman falls lifeless to the ground, a "
"small carved statue tumbles out of one of her pockets.%^RESET%^");
   new(OBJ2"staffdragon")->move(TO);
   ::die(ob);
}
