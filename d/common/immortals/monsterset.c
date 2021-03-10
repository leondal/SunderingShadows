//      /std/monsterNew.c
//      from the Nightmare mudlib
//      inheritable code for npc's
//      created by Descartes of Borg september 1992
//  new settings for global balance control added, using a daemon for easier maintenance too

#include <std.h>

inherit "/std/monster.c";

int level_set;
void set_default_stats(int stats_lvl);
void set_mobthief_skills(int thief_lvl);

void create() {
   ::create();
}

query_level_set() { return level_set;  }

// make setting speed automatically set moving on
void set_speed(int i) {
   speed = i;
   set_moving(1);
}

/*
void set_hd(int dice, int bonus) {      // sets the hit dice of a monster
   hit_dice = dice;                 // 2, 0 would be 2d8 + 0
   hit_dice_bonus = bonus;
   set_max_hp(roll_dice(dice,8));
   set_hp(query_max_hp());
   do_exp(dice,bonus);
   if(!query_classes() || query_classes() == ({})) set_class("fighter");
   set_level(dice);
}
*/

/********* replace this function

void do_exp(int dice, int bonus) {
   if(bonus > 0) dice++;
   if(bonus < 0) dice--;
   if(dice < 1) dice = 1;
   if(dice > 13) {
      return;
   }
   switch(dice) {
   case 1:  set_exp(15);  return;
   case 2:  set_exp(35);  return;
   case 3:  set_exp(65);  return;
   case 4:  set_exp(120); return;
   case 5:  set_exp(120); return;
   case 6:  set_exp(175); return;
   case 7:  set_exp(270); return;
   case 8:  set_exp(390); return;
   case 9:  set_exp(500); return;
   case 10: set_exp(850);return;
   case 11: set_exp(960);return;
   case 12: set_exp(1150);return;
}

int query_hd_bonus() {return hit_dice_bonus;}

int query_hd() {return hit_dice;}
*/

/******************************** fix the stats to be set separately & more reasonable

void set_level(int x) {
   level = x;
   set_hp(query_max_hp());
   set_stats("constitution", x*3/2);
   set_stats("strength", x*3/2);
   set_stats("intelligence", x*3/2);
   set_stats("wisdom", x*3/2);
   set_stats("dexterity", x*3/2);
   set_stats("charisma", x*3/2);
   set_max_mp((query_stats("intelligence")/2)*x);
   set_mp(query_max_mp());
//    set_exp( (int)ADVANCE_D->get_exp(x,"fighter"));
   set_mlevel(TO->query_class(),TO->query_level());
}
*/

// *************************

/* started with these breaks then went back to the originals 
    case 0..3:  	base_exp = 50;		set_max_level(8);	break;	
    case 4..5:		base_exp = 200;		set_max_level(10);	break;
    case 6..9:		base_exp = 500;		set_max_level(15);	break;
originally was this....
   case 13: set_exp(1250);return;
      dice -= 13;
      set_exp((2000+(dice*200)));
*/

void add_class(string class) {
   if(!class)  return;
   if(!level_set)
	level_set = 1;
   set_mlevel(class, level_set);

/* check for valid class?
   if(member_array(class, > > > > > check for valid classes here < < < < ) == -1) {
	log_file("settings", base_name(TO)+" needs a valid class for add_class().\n");
	return;
   }
*/
// is this always correct ??
   add_search_path("/cmds/mortal/"+class+"/");
//   set_guild_level(class,level_set);
   switch(class) {
     case "thief" :     set_guild_level("thief", level_set);
			set_mobthief_skills(level_set);		break;
     case "fighter" :

     case "mage" :
     case "bard" :	set_guild_level("mage",level_set);	break;

     case "ranger" :
     case "antipaladin" :
     case "paladin" :
// is cleric or priest correct here?
     case "cleric" :	set_guild_level("cleric",level_set);	break;
     case "cavalier" :	
       default:  break;
   }
} 

void set_mobthief_skills(int thief_lvl) {

/* thief monsters
this func. from monster.c  - have this set by level too or if using mlevel to make them a thief?

void set_thief_skill(string skill, int score) {
   thief_skill[skill] = score;
}
*/
 
}

void set_level_range(int setlvl, int diff, int treas) {
  int base_exp, base_ac;
  if(!setlvl)  {
      log_file("settings", base_name(TO)+" needs arguments for set_level_range().\n");
      return;
  }
  level_set = setlvl;
  set_default_stats(setlvl);
// set exp., overall ac, and max_levels here
  switch(level) {
    case 1:  		base_exp =   15;  	set_max_level(5);	break;
    case 2:  		base_exp =   35;  	set_max_level(5);	break;
    case 3:  		base_exp =   65;  	set_max_level(6);	break;
    case 4:  		base_exp =  100; 	set_max_level(8);	break;
    case 5:  		base_exp =  120; 	set_max_level(9);	break;
    case 6: 		base_exp =  175; 	set_max_level(10);	break;
    case 7:  		base_exp =  270; 	set_max_level(12);	break;
    case 8:  		base_exp =  390; 	set_max_level(13);	break;
    case 9:  		base_exp =  500; 	set_max_level(15);	break;
    case 10..14:	base_exp = 1000;	set_max_level(20);	break;
    case 15..19:	base_exp = 2500;	set_max_level(25);	break;
    case 20..24:	base_exp = 5000;	set_max_level(30);	break;
    case 25..29:	base_exp = 10000;	set_max_level(35);	break;
    case 30..34:	base_exp = 15000;	set_max_level(40);	break;
    case 35..44:	base_exp = 20000;	set_max_level(50);	break;
    case 45..49:	base_exp = 25000;	set_max_level(50);	break;
    case 50..54:	base_exp = 30000;	set_max_level(50);	break;
    case 55..60:	base_exp = 40000;	set_max_level(50);	break;
    default:  		
	base_exp = 100;		set_max_level(25);	
	log_file("settings", base_name(TO)+" needs a valid set_level_range.\n");
	break;
  }
  switch(setlvl) {
    case 1:		base_ac =   10;
    case 2:  		base_ac =   10;  	break;
    case 4:  		base_ac =    9;		break;
    case 5:  		base_ac =    8; 	break;
    case 6: 		base_ac =    7; 	break;
    case 7:  		base_ac =    6; 	break;
    case 8:  		base_ac =    5; 	break;
    case 9:  		base_ac =    4; 	break;
    case 10..14:	base_ac =    2;		break;
    case 15..19:	base_ac =    0;		break;
    case 20..24:	base_ac =   -5;		break;
    case 25..29:	base_ac =  -10;		break;
    case 30..34:	base_ac =  -15;		break;
// these are probably way high and some of the others way low compared to player ACs but I think we need to bring those down at the lower levels for PCs
    case 35..44:	base_ac =  -20;		break;
    case 45..49:	base_ac =  -25;		break;
    case 50..54:	base_ac =  -30;		break;
    case 55..60:	base_ac =  -35;		break;
    default:  		
	base_ac = 10;
  }
  switch(diff) {
     case 1:    set_exp(base_exp *  6/10);	break;
     case 2:    set_exp(base_exp *  8/10);	break;
     case 3:    set_exp(base_exp *  9/10);	break;
     case 4: 	set_exp(base_exp);		break;
     case 5:	set_exp(base_exp * 11/10);	break;
     case 6: 	set_exp(base_exp * 12/10);	break;
     case 7:	set_exp(base_exp * 13/10);	break;
     case 8:    set_exp(base_exp * 14/10);	break;
     case 9:    set_exp(base_exp * 16/10);	break;
     default:	set_exp(base_exp);		break;
  }
  return; 
}

void set_default_stats(int lvl) {
/* was originally
   set_hp(query_max_hp());
   set_stats("constitution", x*3/2);
   set_stats("strength", x*3/2);
   set_stats("intelligence", x*3/2);
   set_stats("wisdom", x*3/2);
   set_stats("dexterity", x*3/2);
   set_stats("charisma", x*3/2);
*/
}

//**********  add to global variables 

void add_to_stat(string stat, int amt) {
   int max;
   if(member_array(stat, TO->query_all_stats()) == -1) {
	log_file("settings", base_name(TO)+" needs a valid stat for add_to_stat().\n");
	return;
   }
   switch(query_level_set()) {
	case 0..4:  	max = 2;	break;
	case 5..9:  	max = 3;	break;
	case 10..19: 	max = 4;	break;
	case 20..29:	max = 5;	break;
	case 30..39:	max = 6;	break;
	case 40..59:	max = 7;	break;
	case 60..1000:	max = 8;	break;
   }
   if(amt > max)   amt = max;
   set_stats(stat, amt);
   return;
}

/*
int query_level() {
    level = query_highest_level();
   if(level == 0) {
      return TO->query_hd();
   }
   return level;
}

*/


// int query_thief_skill(string skill) {return thief_skill[skill];}

/******* here's where to have this ignore invis immortals
void steal_fun() {
   string what;
   object who;
   object *items;
   int coin;
   int inven;

   who = "daemon/find_target_d"->find_player_target(TO);
   if(who == TO) {
      return 1;
   }
   coin = random(2);
   if(coin == 0) what = "money";
   else what = "item";
   if(what == "money")
      TO->force_me("pp "+who->query_name());
   else {
      items = all_inventory(who);
      if(items == ({}))
         return 1;
      inven = random(sizeof(items));
      TO->force_me("steal "+items[inven]->query_name()+" from "+who->query_name());
   }
}
*/