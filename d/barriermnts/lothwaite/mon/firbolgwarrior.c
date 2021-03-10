#include <std.h>
#include "../lothwaite.h"
inherit MONSTER;

void create()
{
object obj;
	::create();
	set_name("firbolg warrior");	
	set_id(({"ghost","undead","monster","firbolg","giant","firbolg ghost","giant ghost","warrior","firbolg warrior"}));
	set_short("A ghostly firbolg warrior");
	set_gender("male");
	set_size(random(3)+1);
      set_long(
         "This firbolg is clad in the garb of a warrior, "+
         "fitted with a breastplate and leather skirt "+
         "even in this immaterial state.  His entire body "+
         "is translucent, giving him a ghastly appearance, "+
         "and his eyes burn with a fierceness at having "+
         "been awakened.  He stands ready to defend the "+
         "spirits of his people, just as he defended their "+
         "lives at one time."
      );
	set_property("undead",1);
	set_hd(25,6);
	set_max_level(25);
	set_body_type("firbolg");
	set_overall_ac(-8);
	set_alignment(4);
	set_race("ghost");
	set_max_hp(random(50)+200);
	set_hp(query_max_hp());
	set_class("fighter");
	set_mlevel("fighter",20);
      set_stats("strength",20);
      set_stats("dexterity",18);
	set_level(20);
      if((int)TO->query_size() > 1){
         obj = new(OBJ"ghostscythe");
         if(random(4)){
            obj->set_property("monsterweapon",1);
         }
         obj->move(TO);
         command("wield scythe");
      }else{
         obj = new("/d/common/obj/weapon/scythe");
         if(random(4)){
            obj->set_property("monsterweapon",1);
         }
         obj->set_property("enchantment",2);
         obj->move(TO);
         command("wield scythe");
      }
      switch(random(12)){
         case 0..2:  break;
         case 3..5:  if(random(4)){
                        obj = new(OBJ"ghostcloak");
                        if(random(3)){
                           obj->set_property("monsterweapon",1);
                        }
                        obj->move(TO);
                     }else{
                        obj = new(OBJ"health_amulet");
                     }
                        if(random(3)){
                           obj->set_property("monsterweapon",1);
                        }
                        obj->move(TO);
                        command("wear neckthing");
                     break;
         case 6..7:  obj = new(OBJ"ethereal_bplate");
                     if(random(3)){
                        obj->set_property("monsterweapon",1);
                     }
                     obj->move(TO);
                     command("wear breastplate");
                     break;
         case 8..9:  obj = new(OBJ"ghostboots");
                     if(random(3)){
                        obj->set_property("monsterweapon",1);
                     }
                     obj->move(TO);
                     command("wear shoes");
                     break;
         case 10..11:  obj = new(OBJ"ethereal_bracers");
                     if(random(3)){
                        obj->set_property("monsterweapon",1);
                     }
                     obj->move(TO);
                     command("wear bracers");
                     break;
         default:  break;
      }
      set_property("full attacks",1);
	set_funcs(({"touch","drain","scare","rushit","flashit"}));
      set_func_chance(13);
   set_exp(2700+random(1500));
 	add_money("platinum",random(100));
	set_property("swarm",1);
      add_search_path("/cmds/fighter");
	set("aggressive","aggfunc");
	set_property("weapon resistance",2);
	set_mob_magic_resistance("average");
      set_moving(1);
      set_speed(60);
      set_nogo(({"/d/barriermnts/lothwaite/rooms/b1", "/d/barriermnts/lothwaite/rooms/stones2"}));
      force_me("message in drifts in");
      force_me("message out floats $D");
}

/*int touch(object targ)
{
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^%^CYAN%^The ghost reaches "+
                    "out and touches your cheek, draining your strength!");
			tell_room(ETO,"%^BOLD%^%^CYAN%^The ghost"+
			" touches "+targ->query_cap_name()+"'s cheek and seems to drain"+
			" "+targ->query_objective()+" of "+targ->query_possessive()+""+
			" strength.",targ);
			targ->add_stat_bonus("strength",-1);
			return 1;
		}
		else {
			tell_object(targ,"You successfully resist the icy"+
			" touch of the ghost.");
			tell_room(ETO,"The ghost touches "+targ->query_cap_name()+","+
			" but "+targ->query_subjective()+" seems to be alright.",targ);
			return 1;
		}
		return 1;
}*/

int drain(object targ)
{
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^The ghost seems to drain"+
			" your life force from you!");
			tell_room(ETO,"%^BOLD%^The ghost seems"+
			" to drain "+targ->query_cap_name()+"'s life force"+
			" from "+targ->query_objective()+"!",targ);
                     targ->resetLevelForExp(-(random(500)+500));
			return 1;
		}
		else {
			tell_object(targ,"%^BOLD%^The ghost attempts to drain"+
			" away some of your life but fails.");
			tell_room(ETO,"The ghost tries to drain"+
			" away "+targ->query_cap_name()+"'s life force but"+
			" nothing seems to happen.",targ);
			return 1;
		}
		return 1;
}

int scare(object targ)
{
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^%^BLUE%^The ghost "+
                     "stares into your eyes and you feel yourself "+
                     "frozen in fear!");
			tell_room(ETO,"%^BOLD%^%^BLUE%^"+targ->QCN+" looks "+
                     "terrified as "+targ->QS+" gazes at the ghost!",targ);
                  targ->set_tripped(3,"%^BOLD%^You are frozen in fear of the ghost.");
			return 1;
		}
		else {
			tell_object(targ,"%^BOLD%^%^BLUE%^The ghost "+
                     "stares into your eyes, but you resist its power!");
			tell_room(ETO,"%^BOLD%^%^BLUE%^The ghost stares "+
                     "at "+targ->QCN+" but nothing happens.",targ);
			return 1;
		}
		return 1;
}

int rushit(object targ){
   string name = targ->query_name();
   command("say We do not suffer the living to disturb us!");
   command("rush "+name);
   return 1;
}

int flashit(){
   command("flash");
   return 1;
}

int aggfunc(){
   call_out("check_vis",1,TP);
   return 1;
}

int check_vis(){
   if(TP->query_invis()){
      tell_object(TP,"%^RED%^The firbolg's transluscent face turns "+
         "straight toward you!");
      force_me("kill "+TPQN+"");
      return 1;
   }else{
      force_me("kill "+TPQN+"");
      return 1;
   }
}
