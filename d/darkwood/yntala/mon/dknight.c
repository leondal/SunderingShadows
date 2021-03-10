#include <std.h>
#include "/d/darkwood/yntala/yntala.h"
inherit MONSTER;

object obj;
void create (){

::create ();
   set_name("Grenedal");
   set_id(({"undead","Undead","dead fighter","Grendedal","grenedal"}));
set_short("%^RESET%^%^ORANGE%^A %^BOLD%^%^BLACK%^heavily armored %^RESET%^%^ORANGE%^ undead with %^BOLD%^%^BLACK%^no eyes%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This undead makes his armor clank eerily anytime he moves.  Quite tall, he"
" stands about six feet in height.  His has long %^RESET%^white %^ORANGE%^hair that falls in messy tangles"
" around the rotting flesh of his face.   Where his eyes should be are two %^BOLD%^%^BLACK%^hollow voids.%^RESET%^");
   set_race("undead");
   set_gender("male");
   set_body_type("humanoid");
   set_hd(18,2);
   set_overall_ac(-5);
   set_size(2);
   set_stats("intelligence",18);
   set_stats("strength",18);
   set_stats("wisdom",5);
   set_stats("dexterity",18);
   set_stats("constitution",15);
   set_stats("charisma",1);
   set_money("gold",random(200));
   set_money("silver",random(200));
   set_money("copper",random(1000));
   set_money("electrum",random(20));
    set_exp(3500);
   set_max_level(16);
   set_alignment(8);
   set_hp(random(200)+150);
   set_max_hp(query_hp()); 
     set_class("fighter");
   set_moving(1);
   set_speed(60);
   set_exp(4400);
   set("aggressive",25);
   set_property("full attacks",1);
   obj=new("/d/shadow/obj/armor/fullplate.c");
   obj->set_property("enchantment",2);
   obj->set_long("%^BOLD%^%^BLACK%^This set of fullplate looks to be quite heavy, but the thick metal also appears"
" as though it would lend plenty of protection against most any onslaught.   Three small %^RED%^sp%^YELLOW%^i%^RESET%^%^ORANGE%^k%^RED%^e%^BOLD%^s %^BLACK%^stick up from either"
" shoulder plate, giving the wearer of the armor an imposing shadow. In the center of the breastpiece is the image"
    "of a dark, eyeless face with long, ragged %^RESET%^white hair.  %^BOLD%^%^BLACK%^Behind the face, a %^RESET%^gauntleted hand %^BOLD%^%^BLACK%^rises, it's fist wrapped around a dying %^RED%^sun%^BOLD%^%^BLACK%^. A slight %^RESET%^%^CYAN%^magical"
 " %^BOLD%^%^BLACK%^shift"
" can sometimes be seen etching its way across the darkened metal.%^RESET%^");
     obj->set_short("%^BOLD%^%^BLACK%^Black fullplate%^RESET%^");
     obj->move(TO);
     command("wear armor");
   obj=new("/d/shadow/obj/clothing/silkrobe.c");
     obj->set_property("enchantment",2);
     obj->set_long("%^RESET%^This elegant robe is made from the finest silk and has been dyed a %^CYAN%^muted %^RESET%^shade of %^CYAN%^blue%^RESET%^."
     "  Having little in the way of decoration or piping, the design is simple.  Long, fluted sleeves would cover the hands of a smaller person, just as the length of the robe would easily reach the floor of a taller one.  While the design itself is quite plain, one cannot help but feel there is something extraordinary about these robes.");
     obj->set_short("%^RESET%^%^CYAN%^Pale blue robe%^RESET%^");
     obj->move(TO);
     command("wear robe");
     set_monster_feats(({
      "parry",
      "powerattack",
	  "shatter",
	  "sunder",
	  "rush"
   }));
   set_funcs(({"rushit","flashit","flashit"}));
   set_func_chance(30);   
}

void rushit(object targ) {
	TO->force_me("say %^GREEN%^Come, join our little performance.");
  	TO->force_me("rush "+targ->query_name());
}

void flashit(object targ) {
  TO->force_me("flash "+targ->query_name());
}

