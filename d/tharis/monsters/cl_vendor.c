inherit "/std/vendor.c";

// int build; coing away with this
void create() {
    ::create();
   set_name("clothing dealer");
   set_id( ({ "clothing dealer","vendor" }) );
set_short("a clothing vendor");
   set_level(19);
   set("long", "He sells clothes.\n"
	"He is pushing a cart full of various articles of clothing.\n");
   set_gender("male");
   set("race", "human");
   set_body_type("human");
   set_class("mage");
   set_alignment(5);
   set_mp(300);
   set_hd(19,1);
   set_exp(10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_items_allowed("clothing");
   set_storage_room("/d/tharis/Tharis/carts/cl_storage.c");
//    build = 0; not needed even if the hb function uses it because it would init to 0
   }
/*
Get rid of this hearbeat since it didn't call the super and isn't doing enough to be worth the overhead.  Found it trying to get rid of bugs with rooms loading with other vendors. *Styx*
void start_heart(){
        set_heart_beat(1);
}
void heart_beat(){
        if(!build) return;
        build ++;
        if(build == 5){
                command("say Hello there!");
        }
   }
*/
