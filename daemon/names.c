//

#include <std.h>

#define NAMES_FILE "/daemon/names.db"

inherit DAEMON;

string *names;


void init_names();

void create(){
    ::create();
    init_names();

}


void init_names(){
    int i;
    string list = read_file(NAMES_FILE);
    string *broken;
    broken = explode(list,"\n");
    names = ({});
    for (i=0;i<sizeof(broken);i++) {
        names += explode(broken[i]," ");
    }
}


string getName(){
    return lower_case(names[random(sizeof(names))]);
}
