
#include <std.h>
inherit VOTING;


void create(){
object ob;
:: create();

set_light(1);
set_indoors(1);
set_property("no teleport",1);
set_short("
%^BOLD%^%^WHITE%^A voting booth
");
set_long(
@SEETH
%^CYAN%^This voting booth has been set up so that the Order might vote privately on who they would like to become their HC. Please just use this voting booth as you used the others for your classes.%^RESET%^
SEETH
);


set_exits(([
  "out":"/d/guilds/order/hall/main.c"
]));


}
