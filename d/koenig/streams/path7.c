//path7.c - Path from Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit PATH;

void create(){
        ::create();
        set_long(::query_long()+"A faint trail can be seen going "+
           "westward, traveling up the mountainside.\n");
        set_exits(([
        "northwest" : VILSTREAM"path6",
        "southeast" : VILSTREAM"path8",
        "west" : "/d/darkwood/tabor/room/auppenser1"
        ]));
}
