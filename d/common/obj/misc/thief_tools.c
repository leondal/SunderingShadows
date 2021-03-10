//updated with new description by Circe 6/12/04
#include <std.h>
inherit OBJECT;
void create(){
        ::create();
        set_name("locksmith tools");
        set_id(({"tools","thief toolx", "thief tools", "lock picks", "locksmith tools" "picks"}));
set_short("A leather case of tools"); //based on a suggestions by the players - cythera 6/05\\
//set_short("Thief's tools"); //restoring Thief's tools to their former glory - Uriel 1/2020
        set_long(
@CIRCE
This is a small, soft leather case that can be rolled and tied
closed with leather thongs.  The case, when fully opened, reveals
rows of pouches and slots filled with various skeleton keys, long
metal picks and pries, a small handsaw for especially stubborn
locks.  It even has a small hammer with a metal wedge.  These
tools would probably aid any locksmith.
CIRCE
);
        set_value(30);
        set_weight(0);
}
void break_picks(){
	TO->set_id(({"tools","broken tool","lock picks","picks"}));
TO->set_short("A leather case of broken tools");
//TO->set_short("broken Thief's tools");
	TO->set_long(
@CIRCE
This soft leather case has many pouches that were once filled
with tools.  Now, however, many of the tools are missing or
broken, making this set completely worthless for opening a
stubborn lock.
CIRCE
);
	TO->set_value(0);
      TO->set_property("broken",1);

}
