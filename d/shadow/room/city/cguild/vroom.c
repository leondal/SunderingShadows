
#include <std.h>
inherit VOTING;


void create(){
object ob;
:: create();

set_light(1);
set_indoors(1);
set_short("
%^BOLD%^%^WHITE%^A voting booth
");
set_long(
@SEETH
There's a sign to be read.
SEETH
);


set_exits(([

]));


}
