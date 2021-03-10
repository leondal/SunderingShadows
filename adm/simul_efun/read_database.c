//      /adm/simul_efun/read_database.c
//      from the Nightmare Mudlib
//      reads a database, ignoring blank lines and lines beginning with #
//      created by Descartes of Borg 31 july 1993
//     Sped up using LPC lib functions.  -Val  Aug. 3, 1993

#include <security.h>

string *read_database(string file) {
     string *ret;
    string tmp;

    if(!file_exists(file)) return 0;
    seteuid(geteuid(previous_object()));
    if(!(tmp=read_file(file)) || tmp == "") {
        seteuid(UID_ROOT);
        return ({});
    }
    ret = explode(tmp, "\n");
    seteuid(UID_ROOT);
    ret = filter_array(ret, "database_filter", this_object());
    return ret;
}

int database_filter(string str) {
   if(!str || str == "" || str[0] == '#') return 0;
   return 1;
}
