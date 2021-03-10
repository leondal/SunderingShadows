#include <std.h>
inherit "/std/monster";
#define H_M ({"flowing","curly","frizzled","short","long flowing",\
"long, curly","long, frizzled","short, frizzled","short curly",})

#define H_C ({"%^RED%^red","%^YELLOW%^blonde","%^YELLOW%^dirty blonde",\
"%^MAGENTA%^brown","%^BOLD%^%^BLACK%^black","%^RED%^scarlet",\
"%^BOLD%^%^BLACK%^midnight black","%^RED%^crimson"})

#define E_C ({"%^BLUE%^blue","%^CYAN%^sa%^RESET%^%^BLUE%^pph%^CYAN%^ire",\
"%^GREEN%^green","%^MAGENTA%^brown","%^BOLD%^%^BLACK%^black" })

create() {
  object ob;
  string hair, eye;
  ::create();
  set_name("A female human");
  set_id(({"mage","fortress mage","female human"}));
  set_gender("female");
  set_race("human");
  hair = H_M[random(sizeof(H_M))] + " " + H_C[random(sizeof(H_C))] + "%^RESET%^";
  eye = E_C[random(sizeof(E_C))];
  set_short("A robed female human with "+hair+"%^RED%^ hair%^RESET%^");

  set_long("This mysterious lady is quite obviously alive, yet her "+
  "sickly pale flesh reflects a long absence from the presence of "+
  "sunlight.  She is dressed in a simple robe, her eyes an intense "+
  eye + "%^RESET%^%^CYAN%^ and her "+hair+"%^RESET%^%^CYAN%^ hair "+
  "slightly greasy.  She carries a lone dagger in one hand, though "+
  "something hints that she is not at all defenseless.  A heavy body "+
  "odor is given off by her and in conjuction with the state of her "+
  "hair you can safely reason that she has not bathed in a long "+
  "time.");
  set_class("mage");
  set_guild_level("mage",12 + random(4));
  set_mlevel("mage",query_guild_level("mage"));
  set("aggressive","kill_em");
  set_hp(query_guild_level("mage") * 6 + random(31));
  set_alignment(9);
   set_new_exp(10, "normal");
  set_overall_ac(4);
  set_stats("intelligence", 18);
  set_stats("dexterity",12);
  set_stats("strength",13);
  set_stats("wisdom",17);
  set_stats("constitution",14);
  set_stats("charisma",13);
  new("/d/common/obj/armour/robe")->move(TO);
  command("wear robe");
  new("/d/common/obj/weapon/dagger")->move(TO);
  command("wield dagger");
  if(random(20) >= 17) {
	ob = new("/d/magic/scroll");
	ob->set_spell(2 + random(3));
	ob->move(TO);
  }
  set_spell_chance(85);
  set_spells(({"acid arrow","lightning bolt","fireball",
  "magic missile"}));
}

void kill_em() {
  if(!TP->query_invis()) {
    switch(random(3)) {
    case 0:
      TO->force_me("emote hisses and begins muttering under her breath");
      break;
    case 1:
      TO->force_me("say you should not be here, SCUM!!");
      break;
    case 2:
      TO->force_me("say how wonderful will your boiling flesh smell?");
      TO->force_me("emote cackles evily and begins muttering under her breath");
      break;
    }
    TO->force_me("kill "+TP->query_name());
    if(random(5) >= 3) {
     switch(random(2)) {
      case 0:
       new("/cmds/spells/l/_lower_resistance")->use_spell(TO,TP,TO->query_guild_level("mage"),8,"mage");
      break;
      case 1: 
       new("/cmds/spells/s/_stoneskin")->use_spell(TO,TO,TO->query_guild_level("mage"),8,"mage");
       break;
     }
    }
    
    return;
  }
}
