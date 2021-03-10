//  Created by Ignatius, for ShadowGate
//  Coded 05 March, 1995
//  Dwarf NPC King for Charu Mountains

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
    ::create();
  set_name("dwarf king");
 set_id( ({
    "dwarf", "dwarf king", "regal looking dwarf", "short dwarf"
 }) );
 set("race", "dwarf");
 set_gender("male");
 set("short",
    "A regal looking dwarf"
 );
 set("long",
    "This dwarf seems to have not been broken by the horrors of the "
    "Charu range.  He stands tall and proud, and looks as though he "
    "rules over this little area.\n"
 );
 set_level( 10 );
 set_body_type("human");
   set("aggressive", 12);
   set_alignment( 7 );
   set_size( 1 );
    set_stats("intelligence", 6);
    set_stats("wisdom", 4);
    set_stats("strength", 14);
    set_stats("charisma", 9);
    set_stats("dexterity", 11);
    set_stats("constitution", 12);
 set_hd(10, 4);
 set_max_hp(query_hp());
 set_wielding_limbs( ({ "right hand", "left hand" }) );
  new("/d/common/obj/weapon/shortsword")->move(this_object());
       command("wield sword");
 add_money("silver",random(10));
  set_exp(300);
   
}
