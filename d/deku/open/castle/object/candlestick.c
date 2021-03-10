// candelstick.c
// Pator@ShadowGate

#include <castle.h>

inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "candlestick" }));
   set_name("candlestick");
   set_short("A heavy candlestick");
   set_long(
@CANDELSTICK
This is a heavy candlestick and it has the emblem of Marleen's castle on it.
CANDELSTICK
   );
   set_weight(6);
   set_size( 1 );
   set("currency","silver");
   set("value", 1);
   set_wc(1,3);
   set_large_wc(1,1);
   set_type("bludgeoning");
}
