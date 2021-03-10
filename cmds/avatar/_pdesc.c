// _pdesc.c

// Returns the adjective description of all players online

#include <std.h>

inherit DAEMON;

void write_line();
void sort();
void swap(int i, int j);
string do_align(int align);
string do_class(string classes);

string *people;

int cmd_pdesc(string str) {
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
          info = "%^BOLD%^Av %^WHITE%^";
      } else if (high_mortalp(who)) {
          info = "%^BOLD%^%^BLUE%^Hm %^WHITE%^";
      } else if (who->query("advanced_player")) {
          info = "%^BOLD%^%^GREEN%^Ap %^WHITE%^";
      } else if (newbiep(who)) {
          info = "%^BOLD%^%^CYAN%^Nb %^WHITE%^";
      } else {
          info = "%^BOLD%^   %^WHITE%^";
      }
        info += "%^BOLD%^"+arrange_string(who->query_invis()?"("+capitalize(who->query_name())+")":capitalize(who->query_name()),17);
        info += "%^RED%^"+who->getWholeDescriptivePhrase();
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
