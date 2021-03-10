// These are the texts for the druidic mistletoes' dhelp function
// Pator@ShadowGate
// Jan 22 1996

#include <druids.h>
#include <std.h>
// This is done so the the mistletoes' code isn't clobbered with the
// huge amount of texts

int write_spells();
int write_allowed();
int write_druids();    
int write_mistletoe(string str); 
int write_compare();
int write_meditate(); 
int write_smokescreen(); 
int write_amulet();
int write_levels();
int write_dversion();

int write_spells()
{ string pator;
  pator = "%^BOLD%^%^GREEN%^";
  pator += read_file(DRUID_DOC_DIR+"spells.help");
  TP->more(explode(pator,"\n"));
  return 1; }

int write_allowed()
{ string pator;
  pator = "%^BOLD%^%^GREEN%^";
  pator += read_file(DRUID_DOC_DIR+"allowed.help");
  TP->more(explode(pator,"\n"));
  return 1; }


int write_druids()
{ string pator;
  pator = "%^BOLD%^%^GREEN%^";
  pator += read_file(DRUID_DOC_DIR+"druids.help");
  TP->more(explode(pator,"\n"));
  return 1;
 }

int write_compare()
{ string pator;
  pator = "%^BOLD%^%^GREEN%^";
  pator += read_file(DRUID_DOC_DIR+"compare.help");
  TP->more(explode(pator,"\n"));
  return 1; }

int write_mistletoe(string str)
{ string pator;
  pator = "%^BOLD%^%^GREEN%^";
  pator += read_file(DRUID_DOC_DIR+"mistletoe1.help");
  if (str == "wizard")
     {
       pator += read_file(DRUID_DOC_DIR+"mistletoe2.help");  
     }
	if (str == "allowed_wiz")
	   { pator += read_file(DRUID_DOC_DIR+"mistletoe3.help"); }
  pator += "       -=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-";
  pator += "%^RESET%^\n"; 
  TP->more(explode(pator,"\n"));
	return 1; }

int write_meditate()
{ string pator;
  pator = "%^BOLD%^%^GREEN%^";
  pator += read_file(DRUID_DOC_DIR+"meditate.help");
  TP->more(explode(pator,"\n"));
  return 1;
}

int write_smokescreen()
{ string pator;
  pator = "%^BOLD%^%^GREEN%^";
  pator += read_file(DRUID_DOC_DIR+"smokescreen.help");
  TP->more(explode(pator,"\n"));
  return 1;
}

int write_amulet()
{ string pator;
  pator = "%^BOLD%^%^GREEN%^";
  pator += read_file(DRUID_DOC_DIR+"M_amulet.help");
  TP->more(explode(pator,"\n"));
  return 1;
}

int write_levels()
{ string pator;
  pator = "%^BOLD%^%^GREEN%^";
  pator += read_file(DRUID_DOC_DIR+"M_levels.help");
  TP->more(explode(pator,"\n"));
  return 1;
}

int write_dversion()
{ string pator;
  pator = "%^BOLD%^%^GREEN%^";
  pator += read_file(DRUID_DOC_DIR+"dversion.help");
  TP->more(explode(pator,"\n"));
  return 1;
}
