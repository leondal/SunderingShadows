inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "scimitar","sword","scimitar sword","freebooter's scimitar","freebooters scimitar"}));
   set_name("scimitar");
   set_short("Freebooter's scimitar");
   set_long(
  "  This scimitar is the favorite weapon of the pirates and bucaneers, as well as the regular merchant seaman that sail the Dagger Sea."
  "  Its wide, heavy curved blade makes it a perfect weapon for maiming other pirates, bucaneers and regular merchant seaman as well as the monsters that lurk under the waters."
  "  The design is a local one you can see as it has a stamp of crossed hammers over a sail."
   );
  set_weight(10);
   set_size(2);
   set("value", 15);
  set_wc(1,10);
  set_large_wc(1,10);
  set_type("slashing");
   set_weapon_speed(5);
}
