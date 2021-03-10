// A compare command
// This considers if it is wise to kill a monster
// Special for druids.... it is special in the way it looks
// to the spell abilities of the monster
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <druids.h>

inherit ABILITIES_DIR+"is_allowed.c";

int calc_on_stats(string obj);
void balance(int playerstr, int monster_str);
int cmd_compare(string mon);

int str,con,dex,wis,Int,cha,cast_level,level,resistance,hp;
int mon_strength,my_strength;

string name = TP->query_name();
//string theclass = TP->query_class();


int cmd_compare(string mon)
{
    if(!TP->is_class("druid"))
    { 
      notify_fail("This is a druid command!\n"+
                  "You are not allowed to use it !\n");
      return 1;
    }
  else
    {
        if (! present(mon,environment(TP)) && !is_allowed(TPTN) )
        {
          tell_player(TP,
              mon+" is not within you environment !!\n");
          return 1;
;
        }
      else
        { 
	  // Just for testing this thingy
             mon_strength = calc_on_stats(mon);
             my_strength  = calc_on_stats(name);    
      //    printf("My strength  : %d\nHis strength : %d\n",
     //		 my_strength,mon_strength);
          return balance(my_strength,mon_strength);
        }

    }
}

int calc_on_stats(string obj)
{
  object mon;
  string monclass;
  int sum;
  mon = find_living(obj);
  str = mon->query_stats("strength");
  con = mon->query_stats("constitution");
  dex = mon->query_stats("dexterity");
  wis = mon->query_stats("wisdom");
  Int = mon->query_stats("intelligence");
  cha = mon->query_stats("charisma");
  monclass = mon->query_class();
  hp = mon->query_hp();
  level = 11 - (int)mon->query_ac();
  cast_level = mon->query_guild_level(monclass);
  resistance = mon->query_property("magical resistance");
  if (!resistance) { resistance = 5; } 
  sum = (level * (str + con + dex) );
  sum += ( ((resistance*cast_level)/100)*(wis + Int) + 5*cha);
  return sum;
} 


int balance(int player_str,int monster_str)
{
  int value;
  string tmp;
        if (player_str < monster_str)
        {
        value = monster_str - player_str;
        switch(value)
        {
        case 0..20 : tmp = "It is hard to to tell, but he looks tough !\n";break;
        case 21..40 : tmp = "Wouldn't you think this over ??\n";break;
        case 41..60 : tmp = "I hope a hospital is nearby. It could save your
life !\n";break;
        case 61..80 : tmp = "The undertaker is on his way now !\n";break;
        case 81..100 : tmp = "Your tumbstone would read : Here lies a stupid
adventurer !\n";break;
        case 101..125 : tmp = "Uuh. I think you can hold him for 5 secs only !\n";break;
        case 126..200 : tmp = "Death is as sure as your stupidity !\n";break;
        default : tmp = "Read this : R I P  !!\n";break;
        }
        write(tmp);
        }
        else
        {
        value = player_str - monster_str;
        switch(value)
        {
        case 0..20  :  tmp = "It looks as if you are an equal match!\n";break;
        case 21..40 : tmp = "You seem to have the advantage here.\n";break;
        case 41..60 : tmp = "This could be a nice fight !\n";break;
        case 61..80 : tmp = "Don't worry to much on this one !\n";break;
        case 81..100 : tmp = "Your smile goes from ear to ear !\n";break;
        case 101..125 : tmp = "You won't swet much on this one !\n";break;
        case 126..200 : tmp = "You are no match for the unfortunate one\n";break;
        default : tmp = "You order a tumbstone : KILLED BY "+
		         capitalize(TPTN)+" !!\n";break;
        }
        write(tmp);
        }
        return 1;
}

