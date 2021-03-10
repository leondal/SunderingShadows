// _pinfo.c

// Returns certain info on all players online:
// Name
// Race
// Alignment
// Deity
// Class
// Location
// garrett 1-13-2001 took location out to add status indicators like
// bound, gagged, blind, tripped, paralyzed, and so forth.
// Don't quite know why I did paralyzed, other than it was a good idea
// at the time.

#include <std.h>

inherit DAEMON;

void write_line();
void sort();
void swap(int i, int j);
string do_align(int align);
string do_class(string classes);

string *people;

int cmd_pinfo(string str) {
    string *all, info;
    int i;
    object who;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    all = users();
    people = ({});
    for(i=0;i<sizeof(all);i++) {
        if(!living(all[i])) continue;
        if(!wizardp(all[i])) people += ({all[i]->query_name()});
    }
    sort();
    for(i=0;i<sizeof(people);i++) {
        who = find_player(people[i]);
      if (avatarp(who)) {
          info = "%^BOLD%^Av ";
      } else if (high_mortalp(who)) {
          info = "%^BOLD%^%^BLUE%^Hm ";
      } else if (who->query("advanced_player")) {
          info = "%^BOLD%^%^GREEN%^Ap ";
      } else if (newbiep(who)) {
          info = "%^BOLD%^%^CYAN%^Nb ";
      } else {
          info = "%^BOLD%^   ";
      }
        info += "%^RED%^"+arrange_string(who->query_invis()?"("+capitalize(who->query_name())+")":capitalize(who->query_name()),17);
        info += "%^BLUE%^"+arrange_string(who->query_race(),11);
        info += "%^MAGENTA%^"+arrange_string(do_align((int)who->query_alignment()),4);
        info += "%^ORANGE%^"+arrange_string((who->query_diety()?((string)who->query_diety()!="pan"?capitalize(who->query_diety()):"--"):"--"),10);
        info += "%^GREEN%^"+arrange_string(do_class((string)who->query_class_string()),13);
	if (who->query_unconscious())
	  info += "%^MAGENTA%^"+" KO";
	if (who->query_bound())
	  info += "%^RED%^"+" Bind";
	if (who->query_gagged())
	  info += "%^ORANGE%^"+" Gag";
	if (who->query_blind())
	  info += "%^GREEN%^"+" Blind";
	if (who->query_tripped())
	  info += "%^BLUE%^"+" Trip";
	if (who->query_paralyzed())
	  info += "%^CYAN%^"+" Plyze";

        info += "%^RESET%^";
        write(info);
    }
    return 1;
}

void sort() {
    int i,j;

    for(j=0;j<sizeof(people);j++)
        for(i=sizeof(people)-1;i>j;i--)
            if(people[i] < people[i-1])
                swap(i-1,i);
}

private void swap(int i, int j) {
    string tmp;

    tmp = people[i];
    people[i]=people[j];
    people[j]=tmp;
}

string do_align(int align) {
    string str;

    switch(align) {
    case 1:
        str = "LG";
        break;
    case 2:
        str = "LN";
        break;
    case 3:
        str = "LE";
        break;
    case 4:
        str = "NG";
        break;
    case 5:
        str = "TN";
        break;
    case 6:
        str = "NE";
        break;
    case 7:
        str = "CG";
        break;
    case 8:
        str = "CN";
        break;
    case 9:
        str = "CE";
        break;
    default: str = "--";
    }
    return str;
}

string do_class(string classes) {
    string str, cl1, cl2, cl3;

    if(sscanf(classes,"%s/%s/%s",cl1,cl2,cl3) != 3) {
        if(sscanf(classes,"%s/%s",cl1,cl2) != 2) {
            cl1 = classes;
        }
    }
    if(!cl2)
        str = cl1;
    else {
        str = cl1[0..2];
        str += "/"+cl2[0..2];
    }
    if(cl3) str += "/"+cl3[0..2];

    return str;
}
int help(){
    write("Syntax:  pinfo\n\nA listing of people, race, align, gods, class and status.");
    write("Status indicators are KO (Unconsious), Bind, Gag, Blind, Trip, and Plyze (Paralyze).");
    return 1;
}
