inherit "/std/vendor.c";
int build;

void create() {
    ::create();
   set_name("ring dealer");
   set_id( ({ "ring dealer","vendor", "jeweler" }) );
   set_short("A jeweler, specializing in rings");
   set_level(19);
   set("long", 
     "She is pushing a cart full of various types and values of rings.\n");
   set_gender("female");
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
    set_nwp("jewelling",10);
   set_storage_room("/d/tharis/Tharis/carts/ring_storage.c");
   build = 0;
   }
/* getting rid of this and making it call ::heartbeat() to try to get rid of bugs when the rooms load with other vendors sometimes *Styx*
void start_heart(){
        set_heart_beat(1);
}
void heart_beat(){
   ::heart_beat() {
        if(!build) return;
        build ++;
        if(build == 5){
                command("say Hello there!");
        }
   }    
*/
