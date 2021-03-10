// This lists all the spells that are available
// Just yet it works only for priest spells !
// Pator@ShadowGate
// Mar 13 1996

#include <std.h>
#include <druids.h>
#include <ansi.h>

inherit ABILITIES_DIR+"dlevel.c";

#define CLS ESC+"[H"+ESC+"[2J"
// define functions
int cmd_spell_list(string which);
mapping get_all_spells(string path);
int show_all_spells(mapping spell_map);
int compare_str(string one, string two);

// This gives you a list of all the cleric spells
int cmd_spell_list(string which) {
string path;
   set_author("pator");
       // only Highranked Druids may use this account
   if( RANKING[dlevel(this_player())] < 3)
     { tell_object(this_player(),
		   "Thou are't not allowed to use this privilidged spell !");
                   return 1;
     }
   else
     {
	switch(which)	{
		case "priest"  : which = "priest"; break ;
		case "druid"   : which = "priest"; break;
		case "cleric"  : which = "priest"; break;
		case "paladin" : which = "paladin"; break;
		case "wizard"  : which = "wizard"; break;
		case "mage"    : which = "wizard"; break;
	  	default        : which = "priest"; break;
			}
	path = "/cmds/"+which+"/_";
	return show_all_spells( get_all_spells(path));
     }
}		

// This is almost the same as get_eligable_spells but now the spell
// level is used as a search criterium
mapping get_all_spells(string path) 
{   string *e_spells,*kspell;
    mapping ret;
    string s_sphere,spell_name;
    int *exempt;
    int inc,level,total,mylevel, max_level,temp;
        ret = ([ ]);
        ret = allocate_mapping(300);
        e_spells = get_dir(path+"*.c");
        max_level = 7;
        for(inc = 1;inc <= max_level;inc++) { ret[inc] = ({ }); }
        for(inc = 0;inc < sizeof(e_spells);inc ++)
         {
            spell_name = replace_string(e_spells[inc],"_","",1);
            spell_name = replace_string(spell_name,".c","");
            level = (path+spell_name)->query_spell_level();
	    if (level > max_level ) level = max_level;
	    if (level < 1 ) level = 1;
            ret[level] += ({ spell_name });
	    level = 0;
          }
        return ret;
}
int compare_str(string one, string two){ return strcmp(one,two); }

// Put all acquirable spells onto the screen
// it is derive from the list_spells() in the mistletoe 
// Only this function sorts by spell level.

int show_all_spells(mapping spell_map) 
{
object who;
int max_number, inc, spell_level;
string *spells,*e_spells,temp,spell_ob,pator;
	who = this_player();
	max_number= sizeof(spell_map);
        pator = CLS;
        pator += "-=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=-\n";
        pator += "Your Diety is  : "+capitalize((string)who->query_diety())+
        "\nYour Sphere is : "+capitalize((string)who->query_sphere());
        pator += "\nYour resources : "+ who->query_property("spell_points")+
		" spell_points.";
        pator += "\n%^BOLD%^-=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=-\n";
        spells = ({ });
        for (inc = 1;inc <= max_number;inc++)
          { spells += sort_array(spell_map[inc],"compare_str",TO); }
        if(sizeof(spells) > 0)
      { pator += ("   Spell Name             Spell Level           Sphere\n");
        pator += ("-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=--=0=-=-=0=-=-=0=-=-=0=-=-\n");
        for(inc = 0;inc < sizeof(spells);++inc)
             { temp = replace_string(spells[inc],"_"," ");
                if(!spell_ob = PRIEST_SPELL_DIR+spells[inc])
                        continue;
                spell_level = spell_ob->query_spell_level(spells[inc]);
                pator += (sprintf("%-30s %-15d %s\n",
                       capitalize(temp),spell_level,
                   capitalize(spell_ob->query_spell_sphere())));
              }
        pator += ("-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-");
        pator += ( "\nThou can see there are "+
             sizeof(spells)+" spells at present!\n");
      }
      else 
      { pator += ("Thou are no spells..."); }
    TP ->more(explode(pator,"\n"));
    return 1;
}
