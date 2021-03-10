// Pator@ShadowGate
// April 11 1996
// Check for druidship !

#define   DRUIDCLASS     "druid"

int is_druidic(object who);

int is_druidic(object who) {
     string theclass;
     if (!objectp(who)) { who = TP}
     if (interactive(who))
          { theclass = (string)who->query_class(); }
     else
          { theclass = (string)who->query_property("class"); }
     return theclass == DRUIDCLASS; 
 }

