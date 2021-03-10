//changes made to fix errors in call out.  Circe 9/20/03 - there was no valid target
#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

void stab_em(object targ);
object equipment;

void create(){
    ::create();
    set_name("shadow monster");
    set_id(({"shadow","monster","shadow monster","demon"}));
    set_short("%^BOLD%^%^BLACK%^Shadow Monster%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Black%^RESET%^%^BLUE%^ as "+
	"night, this large creature appears as if is is "+
	"composed of pure %^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^."+
	"  Violent %^BOLD%^%^RED%^red%^RESET%^%^BLUE%^ eyes shine "+
	"from the darkness, filled with %^RED%^hatred%^BLUE%^ "+
	"and %^GREEN%^%^BOLD%^malice%^RESET%^%^BLUE%^.  A jagged"+
	" mouth glows %^RED%^red %^BLUE%^as the creature sneers. "+
	" Wearing a %^RED%^red%^BLUE%^ spiked suit of leather, the"+
	" creature has a devilish appearance to it.  It's huge hands"+
	" grip the blades of two weapons as it steps forth from the "+
	"darkness, ready to inflict harm.%^RESET%^");       
    set_race("devil");
    set_gender("male");
    set_body_type("human");
    set_hd(20,1);
    set_size(2);
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    set_max_hp(500);  
    set_hp(500);
    set_exp(14000);
    set_stats("strength",20);
    set_stats("intelligence",10);
    set_stats("wisdom",10);
    set_stats("dexterity",24);
    set_stats("constitution",18);
    set_stats("charisma",10);
    set_alignment(3);
    set_diety("bane");
//   set_speed(60);
    set_invis();
    set("aggressive","agg_func");
    set_class("thief");
    set_mlevel("fighter",20);
    set_guild_level("fighter",20);
    set_mlevel("thief",20);
    set_guild_level("thief",20);
    set_mlevel("ranger",20);
    set_guild_level("ranger",20);
    set_property("full attacks",1);
    add_search_path("/cmds/thief");
    set_thief_skill("move silently",120);
    set_thief_skill("hide in shadows",120);
    set_thief_skill("pick pockets",120);
    set_mob_magic_resistance("average");
    set_scrambling(1);
    set_parrying(1);
    set_overall_ac(-1);

  //equipment = new(OBJ"doomsword");
  //  if(random(5)) equipment->set_property("monsterweapon",1);
  //  equipment->move(TO);
  //  command("wield sword in left hand");
  //equipment = new(OBJ"doommace")->move(TO);
  //  command("wield mace in right hand");
  equipment = new(OBJ"baneblade");
      if(random(4)) {
	equipment->set_property("monsterweapon",1);
	}
   equipment->move(TO);
    command("wield sword");
/*  equipment = new("/d/common/obj/special/sp_randwpn");
     equipment->remove_property("enchantment");
     equipment->set_property("enchantment",2);
     equipment->move(TO);
     command("wield weapon"); */
  equipment = new("/d/common/obj/armour/bracers");
     if(random(5)){
         equipment->set_property("monsterweapon",1);
     }
     equipment->set_property("enchantment",2);
     equipment->move(TO);
     command("wear bracers");
  equipment = new(OBJ"demonskin")->move(TO);
    command("wear demonskin");
  equipment = new(OBJ"darkring")->move(TO);
    command("wear ring");
   add_money("gold", random(200)+300);
   add_money("platinum", random(50)+150);
}

int agg_func(){
  string victemgod=TP->query_diety();
  if(TP->query_true_invis()) return 1;
  if(victemgod=="bane"){
    command("say You understand, don't you?"); 
    command("cackle");
    command("say GO spread your fear!");
    return 1;
  } else 
  stab_em(TP);
}

void stab_em(object targ){
  if(TO->query_invis()) 
     set_invis();
  command("say Give in to your fears, mortal!");
  command("say GIVE YOUR SOUL TO BANE!");
   command("stab "+targ->query_name()+"");
  command("kill "+targ->query_name()+"");
}
//void die(object ob){
//if(!random(4)){
//		new("/d/islands/pirates/obj/baneblade.c")->move(TO);
//    		}
//	::die(ob);
//}
