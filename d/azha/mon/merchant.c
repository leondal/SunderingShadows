// A Merchant of Azha
// Thorn@ShadowGate
// 970304
// Town of Azha
// merchant.c

#include <std.h>

inherit "/std/vendor";

create() {
   string type;
   int stor;
   
   ::create();
   stor = random(3);
   type = ({ "special items", "armor", 
             "weapons"  })[stor];
   set_name("merchant");
   set_id( ({ "merchant", "azha merchant", type+" merchant"}) );
   set_short("a merchant of Azha");
   set("aggressive", 0);
   set_level(19);
   set_long(
   "  This man is one of the many merchants who fills the market\n"+
   "square in Azha.  He smiles as he notices you looking at him. \n"+
   "In seconds, he is in front of you and gesturing to his wares. \n"+
   "It appears that this merchant is a seller of "+type+"\n"
   );
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(7);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_storage_room(({ "/d/azha/town/special_storage",
                       "/d/azha/town/armor_storage",
                       "/d/azha/town/weapons_storage",
                       "/d/azha/town/food_storage" })[stor]);
   set_exp(0);
}

