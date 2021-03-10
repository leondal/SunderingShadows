// A list of all the priestspells of a Druid  
// Pator@ShadowGate
// July 17 1996

#include <std.h>
#include <ansi.h>
#include <druids.h>

#define CLS ESC+"[H"+ESC+"[2J"
// Used variables
string diety, sphere_of_influence, save_file;

// Used functions
int compare_str(string one, string two);
int list_spells(mapping spells);
int cmd_spells();

int cmd_spells() {
mixed *values;
mapping known_spells;
     if (!present("mistletoe", TP)) {
        tell_object(TP, "%^RED%^You need a mistletoe first !");
        return 1; }
      diety = TP->query_diety();
      sphere_of_influence = TP->query_sphere();
      known_spells = TP->query("known_spells");
      return list_spells(known_spells);
}
int compare_str(string one, string two){ return strcmp(one,two); }

int list_spells(mapping known_spells)
{   int inc,level;
    object spell_ob;
    string *spells, temp, pator;
        pator = CLS;
	pator += "%^BOLD%^%^GREEN%^-=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=-\n";
	pator += "Your Diety is  : "+capitalize(diety)+
	"\nYour Sphere is : "+capitalize(sphere_of_influence);
        pator += "\nYour resources : "+ TP->query_property("spell_points")+" spell_points.";
	pator += "\nBOLD%^-=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=-\n";
        spells = sort_array(keys(known_spells),"compare_str",TO);
        if(sizeof(spells) > 0)
      { pator += ("   Spell Name             Spell Level           Sphere\n");
	pator += ("%^BOLD%^-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=--=0=-=-=0=-=-=0=-=-=0=-=-\n");
	for(inc = 0;inc < sizeof(spells);++inc)
	     { temp = replace_string(spells[inc],"_"," ");
	       level = known_spells[spells[inc]];
	       spell_ob=find_object(PRIEST_SPELL_DIR+spells[inc]);
	       if(!spell_ob)
 		   { continue; }
                write(temp);
		pator += 
                       (sprintf("%-30s %-15d %s\n",
		        capitalize(temp), level,
                        capitalize(spell_ob->query_spell_sphere())
)
);
	      }
	pator += ("%^BOLD%^-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-");
	pator += ( "%^BOLD%^%^BLUE%^\nThy knows a total of "+
	      sizeof(keys(known_spells))+" spells !\n");
      }
      else 
      { pator += ("%^BLUE%^Thy knows no spells..."); }
    TP ->more(explode(pator,"\n"));
    pator="";
    return 1;
}
