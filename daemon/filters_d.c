//ACTIVELY USED
//These functions should be efuns instead of a daemon
//Some are already efuns.....

// /daemon/filters.c
// Centralized daemon for filters.
// filter_array, sort_array, and other filters be found here.
// Try to centralize all of them here. That way we cut down on redundant code.
// Garrett.

// daemon to strip colors and characters from catch_say
// borrowed from Garrett's fix to /std/psychic & moved into a daemon by Styx

// questions:
//  does string *strippable need to be static in the daemon?
//  does the filter_alphabet() need to init_strippable since it gets passed a string
//     from filter_colors now?
//  does init_strippable need run separately now (it was before ::create in the mobs)

// to use it in /std/npc.c, I think it just needs this added -
//    /d/common/daemon/filters_d.c->filter_colors(str);
//  as the second line (after the strings are defined) in int apprentice()

#include <std.h>
#include <daemons.h>
#define POSSIBLE_COLORS ({"%^BOLD%^", "%^WHITE%^", "%^RED%^", "%^YELLOW%^", "%^BLUE%^",\
                          "%^GREEN%^", "%^MAGENTA%^", "%^ORANGE%^", "%^RESET%^", "%^BLACK%^", "%^CYAN%^",\
                          "%^B_RED%^","%^B_BLUE%^","%^B_ORANGE%^","%^B_YELLOW%^","%^B_GREEN%^","%^B_MAGENTA%^",\
                          "%^B_BLACK%^","%^B_WHITE%^","%^B_CYAN%^","%^FLASH%^","%^INITTERM%^","%^WINDOW%^","%^ENDTERM%^" })

inherit DAEMON;
#define NUMBERS ({ "0","1","2","3","4","5","6","7","8","9","0" })

nosave string * strippable;   // does this need to be static for the daemon?
void init_strippable();
string filter_colors(string str);
string filter_alphabet(string str);
string filter_alphanumeric(string str);


void init_strippable() {
 int iter = 0;

  if(pointerp(strippable)) return;
  strippable = ({});
  for (iter=1;iter<256;iter++) {
    if (iter == 32)
      continue;
    if ((iter > 64) && (iter < 91))
      continue;
    if ((iter > 96) && (iter < 123))
      continue;
    strippable += ({ sprintf("%c",iter) });
  }
}

string filter_colors(string str)
{
    int count;
    string tmp;
    init_strippable();
    if(!stringp(str)) return str;
    for(count = 0; count < sizeof(POSSIBLE_COLORS);count++)
    {
        if(count > 25)
        {
            //tell_object(find_player("saide"), "count = "+count+ " in filters_d.c");
            count = 0;
            break;
        }
        str = replace_string(str, POSSIBLE_COLORS[count], "");
        continue;
    }
  // filter_alphabet(str);
  // This isn't always desirable.
  // Tristan's point was what if we had merchants move to using says as their
  // method of commerce...
  return str;
}
//If the following functions are not already efuns, they can be added as simul-efun
//in a new alphabet.c file.
string filter_alphanumeric(string str) {
  int iter=0;

  init_strippable();
  for(iter=0;iter<sizeof(strippable);iter++) {
    if (member_array(strippable[iter], NUMBERS) != -1)
     continue;
    str=replace_string(str,strippable[iter],"");
  }

  return str;
}

string filter_alphabet(string str) {
  int iter=0;

   init_strippable();
  for(iter=0;iter<sizeof(strippable);iter++)
    str=replace_string(str,strippable[iter],"");

  return str;
}

int alphabetical_sort(mixed one, mixed two) {
  if (!stringp(one) && !stringp(two))
    return 0;
  if (!stringp(one)) return 1;
  if (!stringp(two)) return -1;

  return strcmp(one,two);
}

int inverse_alphabetical_sort(mixed thistwo, mixed thisone) {
  return alphabetical_sort(thisone, thistwo);
}
int inverse_caseless_alphabetical_sort(mixed thistwo, mixed thisone) {
  return alphabetical_sort(lower_case(thisone), lower_case(thistwo));
}
int caseless_alphabetical_sort(mixed thisone, mixed thistwo) {
  return alphabetical_sort(lower_case(thisone), lower_case(thistwo));
}

int numerical_sort(mixed one, mixed two) {
  if (!intp(one) && !intp(two))
    return 0;
  if (!intp(one)) return 1;
  if (!intp(two)) return -1;
  return (one - two);

}

//EFUN interactivep() already exists
int __interactive(object fnord){
  if (!objectp(fnord))
    return 0;
  if (interactive(fnord))
    return 1;
  return 0;
}

//EFUN playerp()/userp() already exists
int is_player(object fnord)
{
    if (!objectp(fnord)) {
        return 0;
    }
    if (fnord->is_player()) {
        return 1;
    }
    return 0;
}

//EFUN livingp() already exists
int is_player_or_minion(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }

    if (is_player(obj) || objectp(obj->query_property("minion"))) {
        return 1;
    }

    return 0;
}

//EFUN avatarp(), creatorp(), adminp() already exists
int is_non_immortal(object fnord)
{
  if (!objectp(fnord)) return 0;
  if (fnord->query_true_invis()){
     return 0;
  }else if(fnord->query_property("no detect") || !fnord->is_detectable()){ //added to stop scry objects from being hit ~Circe~ 10/23/15
     return 0;
  }else{
     return 1;
  }
  return 0;
}

int is_non_immortal_player(object fnord) {
  if (!objectp(fnord)) return 0;
  if (fnord->query_true_invis()) return 0;
  if (fnord->is_player()) return 1;
  return 0;
}

int is_non_player(object fnord)
{
    if(!objectp(fnord)) return 0;
    if(fnord->is_player()) return 0;
    return 1;
}

//EFUN userp() exists
int _does_user_exist(string luser) {
  if (!stringp(luser)) return 0;
  if (user_exists(luser)) return 1;
  return 0;
}

object * query_retired() {

   string * retired_files;
  int iter;
  object * retireds = ({ });
  object * retireee;

  retired_files= get_dir("/d/retired/*.c");
  for(iter=0; iter<sizeof(retired_files); iter++) {
    retireee = children("/d/retired/"+retired_files[iter]);
    if (retireee != ({ }) ){


      retireds += ({ retireee[0] });

    }
  }
  return retireds;
}

//EFUN livingp() exists
int *is_living(object ob) {
  if (!objectp(ob)) return 0;
  if (living(ob)) return 1;
  return 0;
}

int is_nonliving(object ob)
{
    if(!objectp(ob)) return 0;
    if(!living(ob)) return 1;
    return 0;
}

int classic_swarm(object ob) {
  if (!objectp(ob)) return 0;
  if (living(ob) && (ob->query_property("swarm"))) return 1;
  return 0;
}
int align_hit_order(mixed one, mixed two) {
  int oneval,twoval;
  if (!objectp(one) && !objectp(two))
    return 0;
  if (!objectp(one)) return 1;
  if (!objectp(two)) return -1;

  return strcmp(one,two);
}

int PsiBroken() { return 0; }
