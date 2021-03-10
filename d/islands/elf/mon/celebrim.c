#include <std.h>
inherit "/std/spell_vend.c";
void create(){
  int i,j;
  object ob;
  mapping spells_sold,spells_to_sell;
  string *spells;
  ::create();
    set_id(({"Celebrimbor Losshelin","teacher","wizard","elf","celebrimbor","celebrimbor losshelin","celebrimbor lossehelin","losshelin"}));
    set_name("Celebrimbor");
    set_short("Celebrimbor Losshelin the wizard teacher");
  set("aggressive", 0);
  set_long(
        "Celebrimbor Losshelin is a rather old looking "+
	"elf.  He has grey hair and deep lines in his "+
	"face from his years of practicing magic.  He "+
	"wears a simple gold and red trimmed robe.  He "+
	"looks to be studying intently but perhaps he "+
	"will sell you a spell or two."
        "\nType <list spells> to see what he has to offer you."
    );
  set_gender("male");
    set_alignment(1);
    set_race("elf");
    set_hd(35,1);
  set_property("strength","spells");
  set_stats("intelligence",19);
  set_stats("wisdom",10);
  set_stats("strength",8);
  set_spells_sold(gen_spells_sold(20));

 set_base_damage_type("bludgeoning");
}
