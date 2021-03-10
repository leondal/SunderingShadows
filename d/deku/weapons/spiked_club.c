inherit "/d/common/obj/weapon/club_lg.c";

create() {
    ::create();
   set_id(({ "large club", "spiked club", "club" }));
   set_name("spiked club");
   set_short("A large spiked club");
   set_long("This is a large wooden club, so large it takes two hands for any "
      "normal size humanoid to wield and swing it.  This one has been crudely "
      "hewn from large tree limbs and also has sharp spikes of metal driven "
      "into the wood.  It is likely to do more damage than a normal club.");
   set_weight(8);
   set("value", 20);
   set_wc(1,10);
   set_large_wc(2,6);
}
