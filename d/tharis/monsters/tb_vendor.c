inherit "/std/vendor.c";

// int build;  doing away with the hb stuff to fix bugs *Styx* 7/24/05
void create() {
    ::create();
   set_name("tobacco dealer");
   set_id( ({ "tobacco dealer","vendor" }) );
set_short("a tobacco vendor");
   set_level(19);
   set("long", "He sells tobacco.\n"
	"He is pushing a cart full of various tobacco products.\n");
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_class("mage");
   set_alignment(5);
   set_mp(300);
   set_hd(19,1);
   set_exp(10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_items_allowed("tobacco");
   set_storage_room("/d/tharis/Tharis/carts/tb_storage.c");
//   build = 0;
   }
/* 
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
