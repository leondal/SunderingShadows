#include <std.h>
#include "../farm.h"
inherit MONSTER;

void create() {
    	::create();
    	set_name("tin man");
    	set_id(({"tin man","tinman","man","woodsman","tin woodsman"}));
      set_short("a rusty tin woodsman");
      set_long("This hulking man seems to be made entirely of tin!  "+
         "His rounded body glints light, dulled only where the "+
         "effects of aging and rust are evident.  He has been "+
         "intricately crafted of well-articulated parts, and he "+
         "looks to have full, if cumbersome, movement.  A funnel "+
         "has been turned upright atop his head as a hat, giving him "+
         "a somewhat dapper appearance.  In his hands is a mighty "+
         "axe, clearly made to chop wood.");
      set_gender("male");
    	set_hd(12,2);
    	set_class("fighter");
    	set_mlevel("fighter",12);
      set_race("golem");
      set_body_type("human");
    	set_stats("intelligence",8);
    	set_stats("wisdom",6);
    	set_stats("strength",16); 
    	set_stats("charisma",12);
    	set_stats("dexterity",10);  
    	set_stats("constitution",16);
	set("aggressive",12);
    	set_alignment(5);
    	set_overall_ac(-4);
    	set_exp(850);
    	set_max_hp((random(10)+120));
    	set_hp(query_max_hp());
    	set_max_level(14);
      set_property("full attacks",1);
      set_property("swarm",1);
      add_money("gold",random(20)+40);
      new(OBJ"wood_axe")->move(TO);
      command("wield axe");
      set_emotes(3,({
         "The tin woodsman uses a wedge to split wood.",
         "The tin woodsman adds wood to the growing pile.",
         "The tin woodsman swings his axe wide, chopping down a tree."
      }),0);
}