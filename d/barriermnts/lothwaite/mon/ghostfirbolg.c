//changed the experience from 9k to 3k + 1500 as the area is getting cycled way too much
#include <std.h>
#include "../lothwaite.h"
inherit MONSTER;

void create()
{
object obj;
	::create();
	set_name("firbolg ghost");	
	set_id(({"ghost","undead","monster","firbolg","giant","firbolg ghost","giant ghost"}));
	set_short("A looming firbolg ghost");
	set_gender(random(2)?"male":"female");
	set_size(random(3)+1);
      set_long(
        "Once a peaceful villager from the settlement of "+
        "Lothwaite, this hulking firbolg has become a "+
        "malevolent spirit haunting these passageways.  "+
        "It appears to be wearing a long cloak with a deep "+
        "hood, though it - like the ghost itself - is translucent.  "+
        "It is said that even a ghost's touch is enough to freeze "+
        "a mortal, draining him of his lifeblood, but this "+
        "ghost carries a ghastly weapon as well.  Strangely, this "+
        "ghost seems to shift in size."
      );
	set_property("undead",1);
	set_hd(18,6);
	set_max_level(25);
	set_body_type("firbolg");
	set_overall_ac(0);
	set_alignment(4);
	set_race("ghost");
	set_max_hp(random(50)+175);
	set_hp(query_max_hp());
	set_class("cleric");
	set_mlevel("cleric",18);
	set_level(18);
      set_stats("strength",18);
      set_stats("dexterity",14);
      set_moving(1);
      set_speed(60);
      set_nogo(({"/d/barriermnts/lothwaite/rooms/b1", "/d/barriermnts/lothwaite/rooms/stones2"}));
      switch(random(22)){
         case 0..4:  obj = new("/d/common/obj/weapon/scythe");
                     obj->set_property("enchantment",random(3));
                     if(random(3)){
                        obj->set_property("monsterweapon",1);
                     }
                     obj->move(TO);
                     command("wield scythe");
                     break;
         case 5..9:  obj = new("/d/common/obj/weapon/sickle");
                     obj->set_property("enchantment",random(3));
                     if(random(3)){
                        obj->set_property("monsterweapon",1);
                     }
                     obj->move(TO);
                     command("wield sickle");
                     break;
         case 10..13:  obj = new(OBJ"ghostscythe");
                     if(random(4)){
                        obj->set_property("monsterweapon",1);
                     }
                     obj->move(TO);
                     command("wield scythe");
                     break;
         case 14..15:  obj = new(OBJ"firestaff");
                     if(random(4)){
                        obj->set_property("monsterweapon",1);
                     }
                     obj->move(TO);
                     command("wield staff");
                     break;
         case 16..17:  obj = new(OBJ"waterstaff");
                     if(random(4)){
                        obj->set_property("monsterweapon",1);
                     }
                     obj->move(TO);
                     command("wield staff");
                     break;
         case 18..19:  obj = new(OBJ"airstaff");
                     if(random(4)){
                        obj->set_property("monsterweapon",1);
                     }
                     obj->move(TO);
                     command("wield staff");
                     break;
         case 20..21:  obj = new(OBJ"earthstaff");
                     if(random(4)){
                        obj->set_property("monsterweapon",1);
                     }
                     obj->move(TO);
                     command("wield staff");
                     break;
         default:  break;
      }
      switch(random(10)){
         case 0..2:  break;
         case 3..5:  if(random(4)){
                        obj = new(OBJ"ghostcloak");
                        if(random(4)){
                           obj->set_property("monsterweapon",1);
                        }
                        obj->move(TO);
                     }else{
                        obj = new(OBJ"health_amulet");
                     }
                        if(random(4)){
                           obj->set_property("monsterweapon",1);
                        }
                        obj->move(TO);
                        command("wear neckthing");
                     break;
         case 6..7:  obj = new(OBJ"ethereal_bplate");
                     if(random(4)){
                        obj->set_property("monsterweapon",1);
                     }
                     obj->move(TO);
                     command("wear breastplate");
                     break;
         case 8..9:  if((string)TO->query_gender() == "female") {
                        obj = new(OBJ"ghostsandals");
                     }else{
                        obj = new(OBJ"ghostboots");
                     }
                     if(random(4)){
                        obj->set_property("monsterweapon",1);
                     }
                     obj->move(TO);
                     command("wear shoes");
                     break;
         default:  break;
      }
      set_property("full attacks",1);
	set_funcs(({"touch","drain","scare"}));
      set_func_chance(10);
   set_exp(3000+random(1500));
 	add_money("platinum",random(100));
	set_property("swarm",1);
	set("aggressive","aggfunc");
	set_property("weapon resistance",2);
	set_mob_magic_resistance("average");
      force_me("message in drifts in");
      force_me("message out floats $D");
}

int aggfunc(){
   call_out("check_vis",1,TP);
   return 1;
}

int check_vis(){
   if(TP->query_invis()){
      if(!random(3)){
         tell_object(TP,"%^RED%^The firbolg's transluscent face turns "+
            "straight toward you!");
         force_me("kill "+TPQN+"");
      }
      return 1;
   }else{
      force_me("kill "+TPQN+"");
      return 1;
   }
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

void heart_beat()
{
   object targ;
   ::heart_beat();
      if(query_attackers() == ({})) return;
	if(!random(30)) {
         targ = TO->query_current_attacker();
         if(present("fury staff")){
            if(!targ) return;
            force_me("fall "+targ->query_name()+"");
            return;
         }
         if(present("spring staff")){
            force_me("spring");
            return;
         }
         if(present("flame staff")){
            if(!targ) return;
            force_me("summer "+targ->query_name()+"");
            return;
         }
         if(present("ice staff")){
            force_me("winter");
            return;
         }
      return;
	}
   return;
}
