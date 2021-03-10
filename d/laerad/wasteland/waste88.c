#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste75",
	"east":"/d/laerad/wasteland/waste98",
	"north":"/d/laerad/wasteland/waste87",
	"south":"/d/laerad/wasteland/waste89"
    ]) );
}
