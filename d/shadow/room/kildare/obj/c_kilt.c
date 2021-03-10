#include <std.h>
#include "../kildare.h"
inherit "/std/armour";

void create()
{
        ::create();
        "/d/shadow/room/kildare/obj/b_kilt"->create_kilt(TO);
}
