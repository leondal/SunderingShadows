// A report on allowed spells for druids
// Pator@ShadowGate
// July 17 1996

#include <std.h>
#include <ansi.h>
#include <druids.h>
#include <mistletoe.h>

#define CLS ESC+"[H"+ESC+"[2J"
#define MISTLETOE present("mistletoe",this_player())

int allowed_spells();
int cmd_allowed();
mapping count_spl();
int *spells_per_level;
int *max_spells_per_level;
int *number_of_spells;
mapping LEVELMAP;

int cmd_allowed() {
  string *e_spells;
  mixed *values;
  if (! present("mistletoe",this_player()) ) {
     tell_object(TP, "You need a mistletoe first !");
     return 1; }
  e_spells=get_dir("/cmds/priest/_*.c");
  number_of_spells = sizeof(e_spells);
  LEVELMAP=TP->query("known_spells");
  spells_per_level= count_spl();
  max_spells_per_level = TP->query("spells_per_level");
  return allowed_spells();
}

int *count_spl() {
    int inc, *number, *spells, total, x;
    number=({ 0,0,0,0,0,0,0 });
    spells=values(LEVELMAP);
    total=sizeof(spells);	
    for (inc=0;inc<total;inc++) {
	x = --spells[inc];
	number[x]++; }
    return number; }

int allowed_spells(){
    int levl, inc, total_known, total_to_know;
    string pator;
	levl = TP->query_level();
	if(levl > 20) levl = 20;
        pator = CLS;
	pator += ("\n%^GREEN%^ Spells allowed:%^RESET%^\n");
	pator += ("%^BOLD%^%^GREEN%^-=0=-=-=0=-=-=0=-=-=0=-=-==-=0=-=-=0=-=-=0=-=-=0=-%^RESET%^\n");
	for(inc = 0;inc < 7;inc++){
	    pator += ("  %^GREEN%^Total level "+(inc+1)+" spells: "+
                      max_spells_per_level[inc]+
               "      Total you know: "+spells_per_level[inc]+"\n");
	 total_to_know += max_spells_per_level[inc];
	 total_known += spells_per_level[inc];
	}
	pator += ("%^BOLD%^%^GREEN%^-=0=-=-=0=-=-=0=-=-=0=-=-==-=0=-=-=0=-=-=0=-=-=0=-\n");
          pator += "%^GREEN%^Total spells thou may know       : "+total_to_know;
        pator += "\n%^GREEN%^Total number of available spells : "+number_of_spells;
        pator += "\n%^GREEN%^Total spells thou knows          : "+total_known;
        TP->more(explode(pator,"\n"));
	return 1;
}
