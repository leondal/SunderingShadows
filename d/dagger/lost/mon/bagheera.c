#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_mob_magic_resistance("average");
  set_property("swarm",1);
  set_name("Bagheera");
  set_id( ({"fierce frothing bagheera","frothing bagheera","warrior","bagheera","warrior2"}) );
  set_short("a fierce frothing Bagheera");
  set_long(
@PEGASUS
  At the wise ancient's summons this male Bagheera has appeared from
the shadows. His form is similar to the ancients only in the fact he
is in crinos...part man and cat combined...he is stoutly built and
black as midnight. He strongly resembles the panther of power and
cunning. This Bagheera looks rather intellectual and if circumstances
were different he might have been a joy to talk to.
PEGASUS
);
  set_race("bagheera");
  set_gender("male");
  set_body_type("human");
  set_hd(20,140);
  set_max_hp(300);
  set_hp(300);
  set_stats("strength",20);
  set_stats("constitution",18);
  set_stats("dexterity",23);
  set_stats("intelligence",9);
  set_stats("wisdom",10);
  set_stats("charisma",15);
  set_o();
    add_action("inscribe_glyph","inscribe");
}
int inscribe_glyph(string str) {
    object *obs;
    int FLAG,x,GLYPH;
    GLYPH = 0;
    if( !str || str != "glyph" ) {
	notify_fail ("Inscribe what?\n");
        return 0;
    }
    FLAG = 0;
    obs = all_inventory(TP);
    for ( x=0; x<sizeof(obs); x++)
        if ( obs[x]->id("glyph of fire")) {
	FLAG = 1;
        if (FLAG) {
    message ( "my_action",
	"%^BOLD%^%^RED%^You inscribe the glyph to the tower in a burst "
	"of flames!\n%^RESET%^%^RED%^The flames engulf you transporting "
	"your body inside the tower!%^RESET%^"
    ,TP);
    message ( "other_action",
	"%^BOLD%^%^RED%^"+TPQCN+" inscribes a glyph to the tower in a "
	"burst of flames and vanishes!%^RESET%^"
    ,environment (TP), TP);
    obs[x]->remove();
    FLAG = 0;
    GLYPH = 1;
    TP->move_player("/d/dagger/drow/rooms/tower4.c");
    return 1;
    }
    }
    if ( GLYPH != 1) {
    notify_fail ("Inscribe what?\n");
    return 0;
    }
}
