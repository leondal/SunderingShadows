#include <std.h>
#include <daemons.h>
inherit OBJECT;


void create() {
    ::create();
    set_id( ({"head"}) );
    set_name("head");
    set_short("A half eaten head");
    set_weight(10);
    set_long(
      "%^RED%^This gruesome head appears to have been half eaten away.  It was then almost petrified in a bog of peat until every grotesque feature was eternally preserved.\nThe head bears a look of horror and half the flesh and part of the skull are torn away."
    );
    set_value(5);
}
