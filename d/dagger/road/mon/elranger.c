#include "/d/dagger/road/short.h"
inherit "/d/dagger/road/mon/wonder.c";


void create() {
   object ob;

    ::create();
    set_name("Elven ranger");
    set_id( ({"elf", "ranger", "elven ranger", "elf ranger"}) );
    set_short("Elven ranger");
    set_long(
      "This is one of the elven scout rangers that can be found on the roads in this area.  Good at hiding in the brush around the roads, they are not commonly seen until they wish you to see them."
    );
  if(!random(5)){ set_mob_magic_resistance("average");}
    set_overall_ac(-7);
    set_class("ranger");
  set_class("cleric");
  set_spells(({"call lightning",
  "call lightning",
  "dispel magic"}));
  set_spell_chance(25);
  set_mlevel("ranger", 35);
  set_mlevel("cleric",20);
  set_guild_level("cleric",20);
    set_guild_level("ranger", 35);
    set_hd(35,3);
    set_max_hp(275);
    set_hp(275);
    set_property("full attacks", 1);
//   set_property("swarm",1); Removed by Crystal on August 19th, they're fairly solitary
    set_gender("male");
    set("race", "elf");
    set_body_type("human");
    set_size(2);
    set_stats("strength", 16);
    set_stats("dexterity", 19);
    set_stats("constitution", 15);
    set_stats("intelligence", 14);
    set_stats("charisma", 14);
    set_stats("wisdom", 14);
    set_alignment(4);
    set("aggressive", 2);
    ob = new("/d/dagger/road/obj/elfsword");
    if(random(20)) ob->set_property("monsterweapon",1);
    ob->move(TO);
    set_speed(30);
    set_moving(1);
    new(OPATH "studded+2")->move(TO);
    new("/d/tharis/obj/psword")->move(TO);
    command("wield longsword");
    command("wield longsword 2");
    command("wearall");
	set_invis();
    add_money("gold", 150 + random(100));
    add_money("platinum", 50 + random(10));
    set_funcs( ({"slash"}) );
    set_func_chance(29);
}

void init() {
    ::init();
    if( (string)TP->query_name() == "Wandering guard") {
	command("say You shall soon take your last breath!");
	command("kill Wandering guard");
    }
/* I can't figure out why this throws error messages off and on so I made the 
wandering guards not drop so much stuff so it's not really needed.
   if(present("corpse",ETO) && !present("corpse",ETO)->is_living()) {
      command("get corpse");
      command("offer corpse");
   }
*/
}

int query_watched(){
    return 90;
}

int slash(object targ){
    tell_room(ETO, "%^BOLD%^%^GREEN%^Someone lunges at "+targ->query_cap_name()+", the sword glowing in his hands!", targ);
    tell_object(targ, "%^BOLD%^%^GREEN%^Someone lunges at you with a great glowing sword!");
    if(targ->query_stats("dexterity") < random(30)){
      tell_room(ETO, "%^BOLD%^%^GREEN%^Someone strikes "+targ->query_cap_name()+" powerfully with his sword!", targ);
     tell_object(targ, "%^BOLD%^%^GREEN%^Someone slashes you with his powerful glowing sword!");
      targ->do_damage("torso",roll_dice(4,10));
      targ->set_paralyzed(random(30), "That blow left you shaken up.");
    } else {
      tell_room(ETO, "%^BOLD%^%^GREEN%^"+targ->query_cap_name()+" moves out of the way of Someone's blow!", targ);
      tell_object(targ, "You are able to move out of the way of Someone's blow!");
    }
    return 1;
}
