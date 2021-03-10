inherit "/std/vendor";

string time;
create() {
   ::create();
   set_name("Mrs. Tolo");
   set_id( ({"Mrs. Tolo","mrs. tolo","ms. tolo","tolo","storekeeper","shopkeeper","Tolo"}) );
   set_short("Mrs. Tolo, The Shopkeeper");
   set("aggressive", 0);
   set_level(19);
   set_long("Mrs. Tolo is a chipper middle-aged lady, who is quick to give a smile to all she meets. Her graying dark hair is pulled into a bun, and she wears some wire spectacles on her face. She wears a modest dress.\n");
   set_languages( ({ "common" }) );
  set_gender("female");
   set_alignment(4);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no bump", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_storage_room("/d/koenig/town/gs_storage.c");
}
 
void reset()
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time == "twilight")
    remove();
}
