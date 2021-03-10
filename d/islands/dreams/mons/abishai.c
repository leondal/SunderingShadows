//Raised the level and hps and exchanged halberd for a new glaive i made - Cy 3/05
#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create()
{
      object ob;
	::create();
	set_name("black abishai");
	set_id(({"abishai","black abishai","devil"}));
	set_short("A black abishai");
	set_long("%^BOLD%^%^BLACK%^A large, scaly black devil stands "+
		"before you, holding a very large and deadly looking glaive "+
		"comfortably in one hand.  A pair of leathery wings extend from "+
		"the creatures back and they nearly reach the floor.  A long, "+
		"skinny tail ends in a sharb barb, and drags along the floor "+
		"behind the beast.  Each hand has three clawed fingers, while "+
		"its feet has 4 clawed toes.  A pair of horns rise above the "+
		"matted and tangled hair, protruding a few inches above "+
		"its snake like eyes.  All across its body, small horns and "+
		"sharp talons protrude from its hide.");
  	set_race("devil");
  	set_body_type("human");
  	set_gender("male");
  	set_size(3);
  	set_hd(35,2);
  	set("aggressive",1);
  	set_class("fighter");
  	set_mlevel("fighter",30);
  	add_limb("mouth","head",0,0,0);
  	add_limb("tail","torso",0,0,0);
  	set_hp(random(200)+900);
  	set_mob_magic_resistance("average");
  	new(OBJ"glaive")->move(TO);
  	command("wield glaive");
  	set_exp(8000);
  	set_overall_ac(-15);
  	set_alignment(9);
	set_max_level(40);
	set_property("full attacks",1);
	add_search_path("/cmds/fighter");
	set_parrying(1);
	set_funcs(({"rushit","flashit","flashit"}));
	set_func_chance(40);
	command("speech hisse");
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("dream fragment");
      ob->move(TO);
    }
}
void rushit(object targ) {
  	TO->force_me("rush "+targ->query_name());
}

void flashit(object targ) {
  TO->force_me("flash "+targ->query_name());
}
void step5()
{
  force_me("say %^BOLD%^%^RED%^Silence you blabbering fool!  Your tongue shall be "+
	"the next part of your anatomy we...experiment on.  Nothing "+
	"would please me more than to silence you for good.%^RESET%^");
  force_me("emote looks up in your direction, and hisses softly.");
  call_out("step6",10);
}

void step6()
{
  force_me("say %^BOLD%^%^RED%^You there, perhaps we could help each other.  I am "+
	"not permitted to finish them off...but you, on the other hand, "+
	"do not have such restrictions.%^RESET%^");
  force_me("emote holds a large, shimmering glaive before you.");
  call_out("step7",10);
}

void step7()
{
  force_me("say %^BOLD%^%^RED%^I could...look aside for a few moments, long enough "+
	"for you to slit the fool's throat...in return, I would give you "+
	"my weapon.  It is rather mundane to me, but you may find it "+
	"very useful upon your plane.%^RESET%^");
  call_out("step8",10);
}

void step8()
{
  present("prisoner",ETO)->step9();
}

void step12()
{
  force_me("say %^BOLD%^%^RED%^Kill him, or I shall kill you, you obviously do "+
	"not belong here, but I am willing to overlook this if you "+
	"would silence him for good.  But I can not wait all day, "+
	"kill him quickly!%^RESET%^");
}

void die(object ob)
{
	new(OBJ"bcryst")->move(TO);
	tell_room(ETO,"As the abishai collapses, a %^BOLD%^%^BLUE%^"+
	"blue crystal %^RESET%^falls from his hair.");
  ::die(ob);
}
