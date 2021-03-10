// Wadi al-Emir River Landing
// for Verhedin
// Thorn@ShadowGate
// 13 June 2000
// Shamelessly ripped off from Tristan's
// Shadow Dock and altered to make a dock
// with only the basic amentities
// landing.c

#include <std.h>
#include <daemons.h>
#define BOAT "/d/verhedin/virtual/wadi/obj/boat.c"
#define BOAT_DIR "/d/save/boats/wadi_al-emir/"
inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

int clean_up(){return 1;}

void create(){
   object ob;
   ::create();
}
void init(){
   ::init();
   add_action("retrieve","retrieve");
   add_action("__Read_me","read");
}

string query_long(string str){
   string hold;

   hold = room::query_long();
   hold += "\nThere is a sign here listing what can be done, please read it.\n";
   return hold;
}

int __Read_me(string str){
   if(!str || str != "sign") return 0;
   write(
@THORN
This is a boat landing. From here you can do any number of things
concerning water transportation.

        retrieve boat  ---------  Will call boat to dock if you own one

THORN
    );
    return 1;
}

void get_boat(object ob, object player){
   if(!objectp(ob)) return;
   tell_room(TO,"%^BOLD%^A small boat sails into the area for use.",player);
   tell_object(player,"%^BOLD%^Your boat sails into the area!\n");
   ob->move(TO);
   ob->make_me();
}

void get_boat2(object ob, object player){
   if(!objectp(ob)) return;
   tell_room(TO,"%^BOLD%^A small boat sails into the area for use.",player);
   tell_object(player,"%^BOLD%^Your boat sails into the area!\n");
   ob->move(TO);
   ob->make_me();
   ob->set_owner(player->query_name());
}

int retrieve(string str){
   string file, file2;
   object ob;

   if(!str || str[0..3] != "boat")
      return notify_fail("Retrieve what?\n");
   if((int)SAVE_D->is_member("tsarven_boat_owners",TPQN) == -1)
      return notify_fail("We have no record of you owning a boat!\n");
   if(!file_exists(BOAT_DIR+TPQN+"boat.c")){
      write("Error in loading boat object: notify an immortal!");
      write_file(BOAT_DIR+"bad_boats","No "+TPQN+"boat.c on
"+ctime(time())+"\n");
      return 1;
   }
   file = BOAT_DIR+TPQN+"boat.c";
   file2 = read_file(BOAT);
   rm(file);
      write_file(file,file2);

   if(!ob = find_object_or_load(BOAT_DIR+TPQN+"boat")){
      write("Error in loading boat object: notify an immortal!");
      write_file(BOAT_DIR+"bad_boats","No "+TPQN+"boat.c on
"+ctime(time())+"\n");
      return 1;
   }
   if(objectp(environment(ob)) && environment(ob) == TO)
      return notify_fail("Umm, you're standing next to your boat.\n");
   call_out("get_boat2",5,ob,TP);
   write("%^BOLD%^%^CYAN%^You summon your boat from where ever it may be!");
   tell_room(TO,"%^BOLD%^%^CYAN%^"+TPQCN+" summons "+TP->query_possessive()+" boat!",TP);
   return 1;
}

