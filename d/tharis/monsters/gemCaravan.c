//caravan

#include <std.h>

inherit "/std/caravan";

void create(){
    ::create();

    set_name("Gem Caravan");
    set_short("A slow moving caravan");
    set_id(({"caravan","gem caravan","Gem Caravan"}));
    set_long(
@OLI
    This set of wagons is laden with its goods. Its obviously from the mines west
of the trade city of Tharis.
OLI
    );
    setGuards((["/d/tharis/monsters/gguard":10]));
    setPath(({"e","e","e","e","e","e","e","e","e","e","e","e","e","n","n","n","n","ne","ne","ne","e","e","e","e","e","e","n","n","n","n","n","n","n","n","n",}));
    setBandits( (["/d/tharis/monsters/e_archer":2]) );
    setBanditChance(100);
    add_money("gold",1000);
    setContents((["/d/islands/tonerra/obj/gem":10]));

}
