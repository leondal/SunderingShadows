#include <std.h>
#include <daemons.h>
#include "../tharis.h"
inherit "/std/vendor";

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis General Store Remodle - Created in February 2009 by Ari
// Prior Updates by Circe 9/7/04 to interact with evils, also new desc, etc.

void create() {
   ::create();
   set_name("Cath");
   set_id(({"Cath","cath","clerk","shop keeper","shopkeeper","gstorekeeper"}));
   set_short("Cath, the general store clerk");
   set("aggressive", 0);
   set_level(19);
   set_long("%^RESET%^%^CYAN%^Cath is an aging man with a still-sleek "+
        "appearance.  His salt and pepper hair is worn long, pulled "+
        "back in a ponytail at the base of his neck.  He wears a fine silk "+
        "shirt uncommon to most shopkeepers - but then, so is the "+
        "way he moves.  His lithe frame allows him to move quickly "+
        "with a grace more fitting a dancer than a shopkeeper.  "+
        "Something about the hint of amusement in his blue eyes "+
        "and the long scar running down his left cheek hint that he "+
        "probably knows how to handle himself.  However, that life "+
        "seems far behind him now, and he stands ready to help you "+
        "with the wares in his shop.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(6);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_storage_room("/d/tharis/Tharis/storage/gs_storage.c");
   set_exp(0);
   remove_std_db();
}