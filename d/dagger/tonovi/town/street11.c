//updated by Circe 9/10/04
#include "/d/dagger/tonovi/town/short.h"

inherit RPATH"street12";

void create(){
    ::create();
    set_exits( ([
	"southeast" : RPATH "street4",
	"north" : RPATH "street12",
      ]) );
}