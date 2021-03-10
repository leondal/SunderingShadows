
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
%^CYAN%^You enter into a small room, and pull the curtains closed 
behind you, so as to maintain your privacy. In front of you is a large
sign detailing various forms of government being suggested for the
%^BLUE%^Clan of Scoundrels. %^CYAN%^There is a small wooden
box below the sign in which you may place your vote. Remember to
choose wisely, for you will only have one chance.
SEETH
);


set_exits(([
"out":"/d/shadow/room/city/cguild/thief/tguild.c",
]));


}
