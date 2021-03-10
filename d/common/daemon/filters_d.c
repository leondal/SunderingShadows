// /d/common/daemon/filters.c

// daemon to strip colors and characters from catch_say
// borrowed from Garrett's fix to /std/psychic & moved into a daemon by Styx

// questions:
//  does string *strippable need to be nosave in the daemon?
//  does the filter_alphabet() need to init_strippable since it gets passed a string
//     from filter_colors now?
//  does init_strippable need run separately now (it was before ::create in the mobs)

// to use it in /std/npc.c, I think it just needs this added -
//    /d/common/daemon/filters_d.c->filter_colors(str);
//  as the second line (after the strings are defined) in int apprentice()



#include <std.h>
#include <daemons.h>

inherit DAEMON;


nosave string * strippable;
void init_strippable();
string filter_colors(string str);
string filter_alphabet(string str);


void init_strippable() {
 int iter = 0;

  if(pointerp(strippable)) return;
  strippable = ({});
  for (iter=0;iter<256;iter++) {
    if (iter == 32)
      continue;
    if ((iter > 64) && (iter < 91))
      continue;
    if ((iter > 96) && (iter < 123))
      continue;
    strippable += ({ sprintf("%c",iter) });
  }
}

string filter_colors(string str) {
  string tmp;
   init_strippable();
  while (sscanf(str, "%*s%%^%s%%^%*s", tmp) > 2)
    str = replace_string(str, "%^"+tmp+"%^", "");
  filter_alphabet(str);
  return str;
}

string filter_alphabet(string str) {
  int iter=0;

   init_strippable();
  for(iter=0;iter<sizeof(strippable);iter++)
    str=replace_string(str,strippable[iter],"");

  return str;
}
