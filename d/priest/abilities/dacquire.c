// This is the inheratable that takes care of giving spells
// to druids !
// Pator@ShadowGate
// Mar 13 1996, revised Jun 28 1996

#include <std.h>
#include <druids.h>
#include <ansi.h>

#define CLS ESC+"[H"+ESC+"[2J"

// define functions
int start_acquiring(int i);
int get_max_spell_level(object who, mapping levels);
mapping get_acquirable_spells(object who,int *spells_per_level, mapping levels,
                            mapping known_spells);
int show_all_acquirables(object who, mapping spell_map, mapping levels,
                         int max_number);
int add_spell_to_player(object who, string str);
int compare_str(string one, string two);

int start_acquiring(int i) {
mixed *values;
object who;
int *spells,max_number;
mapping levels,known,work;

                // Get all important values from the mistletoe
        values = present("mistletoe",TP)->query_spell_values();
                // Init the mappings
        work = ([ ]);
        levels = ([ ]);
        known = ([ ]);
                // Retrieve all values
        who = values[0];
        spells = values[1];
        levels = values[2];
        known = values[3];
        if (!i || i > 7) { max_number= get_max_spell_level(who, levels); }
        else { max_number = i; }

                // Start the acquiring proces
        work = get_acquirable_spells(who, spells, levels, known);
       return show_all_acquirables(who, work, levels, max_number); }

// What is the maximal spell_level this player may cast ??
int get_max_spell_level(object who, mapping levels)
{ int guild_level, spell_level;
  int *per_level;
  per_level = ({ });
  guild_level = (int)who->query_guild_level("druid");
  if (guild_level > 20) guild_level = 20;
  per_level = levels[guild_level];
       // What is the maximum level this druid may cast ??
  spell_level = member_array(0,per_level);
  if ( spell_level == -1) spell_level = 7;
  return spell_level;
}


// This is almost the same as get_eligable_spells but now the spell
// level is used as a search criterium
mapping get_acquirable_spells(object who,int *spells_per_level, mapping levels,
                            mapping known_spells) 
{   string *e_spells,*kspell;
    mapping ret;
    string s_sphere,spell_name;
    int *exempt;
    int inc,level,total,mylevel, max_level,temp;
        ret = ([ ]);
        ret = allocate_mapping(100);
        mylevel = who->query_level();
        if(mylevel > 20) mylevel = 20;
        e_spells = get_dir(PRIEST_SPELL_DIR+"*.c");
        max_level = get_max_spell_level(who, levels);
        for(inc = 1;inc <= max_level;inc++) { ret[inc] = ({ }); }
        for(inc = 0;inc < sizeof(e_spells);inc ++)
         {
            spell_name = replace_string(e_spells[inc],"_","",1);
            spell_name = replace_string(spell_name,".c","");
            level = (PRIEST_SPELL_DIR+spell_name)->query_spell_level();
            if ( level <= max_level ) 
             {
            s_sphere = (PRIEST_SPELL_DIR+spell_name)->query_spell_sphere();
                temp = member_array(spell_name, keys(known_spells));
               if (temp != -1)
               continue;
            if(spells_per_level[level-1] >= levels[mylevel][level-1])
                continue;
            ret[level] += ({ spell_name });
              } 
           }
        return ret;
}
int compare_str(string one, string two){ return strcmp(one,two); }

// Put all acquirable spells onto the screen
// it is derive from the list_spells() in the mistletoe 
// Only this function sorts by spell level.

int show_all_acquirables(object who, mapping spell_map, mapping levels, 
                            int max_number) {
int inc,spell_level;
string *spells,*e_spells,temp,spell_ob,pator;
        pator = CLS;
        pator += "-=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=-\n";
        pator += "Your Diety is  : "+capitalize((string)who->query_diety())+
        "\nYour Sphere is : "+capitalize((string)who->query_sphere());
        pator += "\nYour resources : "+ who->query_property("spell_points")+
		" spell_points.";
        pator += "\n%^BOLD%^-=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=-\n";

        spells = ({ });
        for (inc = 1;inc < max_number;++inc)
          { if (sizeof(spell_map[inc]) > 0)
		spells += sort_array(spell_map[inc],"compare_str",TO); }
 
       if(sizeof(spells) > 0)
      { pator += ("   Spell Name             Spell Level           Sphere\n");
        pator += ("-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=--=0=-=-=0=-=-=0=-=-=0=-=-\n");
        e_spells = present("mistletoe",who)->get_eligable_spells();
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
        pator += ( "\nThou can learn a total of "+
             sizeof(spells)+" spells !\n");
      }
      else 
      { pator += ("Thou may learn no spells..."); }

    TP ->more(explode(pator,"\n"));
    return 1;
}

// The actual adding of the spell
int add_spell_to_player(object who, string str) {
object spell_obj;
string tmp;
int x;
       if(!str) { notify_fail("You can't acquire nothing !!");
                  return 0; }
       spell_obj = present("mistletoe",who);
       if (!((int)spell_obj->query_ok_to_add()))
         { notify_fail("You may not acquire another spell at this moment!!\n");
           return 0; }
       else {
         tmp = replace_string(str," ","_");
         x = (int)spell_obj->add_spell(tmp);
         switch(x) {
         case 0  : tell_object(who,"Internal error. Notify the DruidMaster !");
                   break;
         case -1 : tell_object(who,
                     "You may not acquire another spell at this moment!!");
                   break;
         case -3 : tell_object(who,
                     "You know this spell already !!");
                   break;
         case -4 : tell_object(who,
                     "You may not learn another spell of this level now !");
                   break;
         default : tell_object(who,
                     "You know now the spell : "+capitalize(str)+" !!");
                   break;
         }
         return 1;
       }
}
