//Coded by Bane - based on wizbert.c//
#include <std.h>
inherit "/std/spell_vend.c";
void create(){
  int i,j;
  object ob;
  mapping spells_sold,spells_to_sell;
  string *spells;
  ::create();
    set_id(({"fargastipius","master","wizard","troll"}));
    set_name("fargastipius");
    set_short("Fargastipius the master wizard");
  set("aggressive", 0);
  set_long(
	"Fargastipius is a rather short troll of an incredible age.  He looks as "+
	"though he is over 1000 years old.  His hair, gray and tangled drops down "+
	"over his gnarled face.  He wears what looks like a potato sack and walks "+
	"with the help of a cane.  He is studying intently but perhaps he will "+
	"be so kind to sell you a spell or two."
	"\nType <list spells> to see what he has to offer you."
    );
  set_gender("male");
    set_alignment(5);
    set_race("troll");
    set_hd(35,1);
  set_property("strength","spells");
  set_stats("intelligence",19);
  set_stats("wisdom",10);
  set_stats("strength",8);
  set_body_type("human");
  set_spells_sold(gen_spells_sold(5));  
  set_size(1);
  set_wielding_limbs( ({ "right hand","left hand" }) );
}
