
#include <daemons.h>
#include <std.h>
#include "../gantioch.h"
#include <move.h>

inherit MONSTER;
object ob, *fighterz;
int step1;
int step2;
object ob;

void create(){
   	::create();
   	set_name("grolin");
   	set_short("Grolin, a Shifty Human Merchant");
   	set_id(({"grolin","merchant","human"}));
   	set_long("%^RESET%^%^ORANGE%^This lightly armored human stands"+
		" casually in front of you. His %^BOLD%^%^BLACK%^black%^RESET%^%^ORANGE%^"+
		" hair is pulled back into a ponytail. He seems slightly jittery"+
		" and does not seem to have been expecting company. His clothes are"+
		" %^BOLD%^%^YELLOW%^well-kept %^RESET%^%^ORANGE%^and are made of high"+
		" quality %^BOLD%^%^MAGENTA%^silks %^RESET%^%^ORANGE%^draping him loosely."+
		" He has a jagged %^BOLD%^%^WHITE%^scar %^RESET%^%^ORANGE%^across his"+
		" right eye, obviously blinding it.");
   	set_race("human");
   	set_gender("male");
   	set_hd(15,8);
   	set_max_hp(320+random(50));
   	set_hp(query_max_hp());
   	set_overall_ac(-2);
   	set_alignment(9);
   	set_class("mage");
	set_class("thief");
   	set_mlevel("mage",20);
	set_mlevel("thief",20);
   	set_level(15);
   	set_stats("intelligence",21);
   	set_stats("wisdom",12);
   	set_stats("charisma",16);
   	set_stats("strength",18);
   	set_stats("constitution",14);
   	set_stats("dexterity",20);
    ob = new(OBJ+"quickdagger");
    set_wielding_limbs(({"right hand","left hand"}));
    if(random(1)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield dagger");
    command("hide_in_shadows");
	add_search_path("/cmds/mage");
	add_search_path("/cmds/thief");
	set("aggressive","aggfunc");
	set_property("full attacks",3);
    set_func_chance(45);
    set_funcs( ({ "stabit" }) );
	force_me("wearall");
   	set_exp(15000);
     	add_money("gold",random(10000));
	add_money("silver",random(1000));
	add_money("copper",random(1000));
   	set_monster_feats(({
	  "dodge",
      "mobility",
	  "evasion",
	  "combat reflexes",
	  "hardenedminions",
	  "spell power",
	  "scramble",
	  "improved spell power",
	  }));
	  set_spells(({
      "blink",
      "magic missile",
      "monster summoning iii",
      "powerword stun",
      "lightning bolt",
      "dispel magic",
      "phantom guardians",
      "scorcher",
      }));
   set_spell_chance(50);

}

void reset(){
    ::reset();
    if(!present("note",TO))
    new(OBJ+"note")->move(TO);
}

void stabit(object targ) {
   TO->force_me("stab"+targ->query_name());
}

void aggfunc(object targ){
        force_me("speech say in a condecending tone");
        force_me("say I thought they were worthwhile fodder...Fine. I'll do this then!");
        TO->force_me("stab "+TP->query_name());
        force_me("scramble");
        if(TO->query_invis()) {
        }
}

void die(object ob) {
    object *ppl;
    int i;
    string queststring;
    queststring = "%^BOLD%^%^CYAN%^Dispatch the Murderer%^RESET%^";
    ppl = ({});
    fighterz = ({});
    fighterz += filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
    for(i=0;i<sizeof(fighterz);i++) {
      if(interactive(fighterz[i])) {
        ppl += ({ fighterz[i] });
        if(member_array(queststring,fighterz[i]->query_mini_quests()) == -1) {
          fighterz[i]->set_mini_quest(queststring,75000,queststring);
          tell_object(fighterz[i],"\n%^BOLD%^%^RED%^You have dispatched with the murderer!%^RESET%^\n");
        }
      }
    }
   ::die();
}
